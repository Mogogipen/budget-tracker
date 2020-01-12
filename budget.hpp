#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class money {
private:
	int dollars, cents;
public:
	int getDollars() {
		return dollars;
	}
	int getCents() {
		return cents;
	}
	void setDollars(const int& d) {
		dollars = d;
	}
	void setCents(const int& c) {
		dollars += c/100;
		cents = c%100;
		if ((cents < 0) && (dollars > 0)) {
			dollars--;
			cents += 100;
		} else if ((cents > 0) && dollars < 0) {
			dollars++;
			cents -= 100;
		}
	}

	money operator=(const money& m) {
		setDollars(m.dollars);
		setCents(m.cents);
		return *this;
	}
	money operator+(const money& m) const {
		money result;
		result.setDollars(dollars + m.dollars);
		result.setCents(cents + m.cents);
		return result;
	}
	money operator-(const money& m) const {
		money result;
		result.setDollars(dollars - m.dollars);
		result.setCents(cents - m.cents);
		return result;
	}
	money operator+=(const money& m) {
		*this = *this + m;
		return *this;
	}
	money operator-=(const money& m) {
		*this = *this - m;
		return *this;
	}

	string toReadable() {
		stringstream result;
		bool negative = false;
		if (cents < 0 || dollars < 0) {
			result << '-';
			cents *= -1;
			dollars *= -1;
			negative = true;
		}
		result << '$' << dollars << '.';
		if (cents < 10) {
			result << '0' << cents;
		} else if (cents == 0) {
			result << "00";
		} else {
			result << cents;
		}
		if (negative) {
			cents *= -1;
			dollars *= -1;
		}
		return result.str();
	}

	string toFile() {
		string result = toReadable();
		if (result[0] == '-') {
			result.erase(1,1);
			if (result[result.size()-2] == '0')
				result.erase(result.size()-2,1);
			return result;
		}
		result.erase(0,1);
		return result;
	}
	bool buildFromFile(const string& line) {
		stringstream temp;
		int index = -1;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '.') {
				index = i;
			}
		}
		if (index < 0) {
			temp << line;
			temp >> dollars;
			cents = 0;
		}
		else {
			temp << line.substr(0, index + 1);
			temp >> dollars;
			temp.str("");
			temp << line.substr(index + 1, 2);
			temp >> cents;
		}
		if (dollars < 0)
			cents *= -1;
		if (cin.fail()) {
			dollars = 0;
			cents = 0;
		}
		return true;
	}

	bool negative() {
		return ((dollars < 0) || (cents < 0));
	}

	money(int d = 0, int c = 0) {
		setDollars(d);
		setCents(c);
	}
	money(string line) {
		buildFromFile(line);
	}
};

class transaction {
private:
	string name;
	money cost;
public:
	string& getName() {
		return name;
	}
	money& getCost() {
		return cost;
	}
	void setName(const string& c) {
		name = c;
	}
	bool setCost(money m) {
		if (m.negative()) {
			cost = money(0,0);
			return false;
		}
		cost = m;
		return true;
	}

	string toReadable() {
		stringstream result;
		result << name << " | ";
		result << cost.toReadable();
		return result.str();
	}
	string toFile() {
		stringstream result;
		result << name << ';' << cost.toFile();
		return result.str();
	}
	bool buildFromFile(const string& line) {
		for (unsigned int i = 0; i < line.size(); i++) {
			if (line[i] == ';') {
				name = line.substr(0, i);
				cost = money(line.substr(i+1, 8));
				return true;
			}
		}
		return false;
	}

	transaction() {};
	transaction(money m, string c = "unknown") {
		setCost(m);
		name = c;
	}
};

class budgetCategory {
private:
	string category;
	money cost, actual;
	vector<transaction> receipts;

	void setActual(const money& m) {
		actual = m;
	}
	budgetCategory& operator+=(const money& m) {
		setActual(actual + m);
		return *this;
	}
	budgetCategory& operator-=(const money& m) {
		setActual(actual - m);
		return *this;
	}
	void addActual(const money& m) {
		*this += m;
	}
	void minusActual(const money& m) {
		*this -= m;
	}

public:
	string getCategory() {
		return category;
	}
	money& getCost() {
		return cost;
	}
	money& getActual() {
		return actual;
	}
	vector<transaction> getReceipts() {
		return receipts;
	}
	bool setCategory(string s) {
		if (s.size() > 32) {
			category = "unnamed";
			return false;
		}
		category = s;
		return true;
	}
	bool setCost(money m) {
		if (m.negative()) {
			cost = money(0,0);
			return false;
		}
		cost = m;
		return true;
	}

	void addReceipt(transaction& r) {
		*this += r.getCost();
		receipts.push_back(r);
	}
	void removeReceipt(int i) {
		*this -= receipts[i].getCost();
		receipts.erase(receipts.begin()+i);
	}

	string toReadable() {
		stringstream result;
		result << category << ": " << cost.toReadable() << '\n';
		for (unsigned int i = 0; i < receipts.size(); i++) {
			result << "  " << receipts[i].toReadable() << '\n';
		}
		return result.str();
	}
	string toFile() {
		stringstream result;
		result << category << ';' << cost.toFile() << ';' << actual.toFile() << '#';
		for (unsigned int i = 0; i < receipts.size(); i++) {
			result << receipts[i].toFile() << '#';
		}
		return result.str();
	}

	bool buildFromFile(const string& line) {
		int previousLineBreak = 0;
		vector<int> breaks;
		for (unsigned int i = 0; i < line.size(); i++) {
			if (line[i] == ';') {
				breaks.push_back(i);
			}
			if (line[i] == '#') {
				previousLineBreak = i+1;
				break;
			}
		}
		if (breaks.size() > 2 || previousLineBreak == 0)
			return false;
		category = line.substr(0, breaks[0]);
		cost = money(line.substr(breaks[0]+1, breaks[1]));
		actual = money(line.substr(breaks[1]+1, previousLineBreak));

		bool proceed = false;
		for (unsigned int i = 0; i < line.size()-1; i++) {
			if (line[i] == '#') {
				transaction temp;
				proceed = temp.buildFromFile(line.substr(previousLineBreak, i - previousLineBreak));
				if (!proceed)
					return false;
				receipts.push_back(temp);
				previousLineBreak = i+1;
			}
		}
		return true;
	}

	budgetCategory(money m = money(0,0), string s = "") {
		setCategory(s);
		setCost(m);
	}
};

class budget {
private:
	string name;
	money budgetAmount, totalCost, totalActual;
	vector<budgetCategory> budgetList;

public:
	string& getName() {
		return name;
	}
	money& getTotalCost() {
		return totalCost;
	}
	money& getBudgetAmount() {
		return budgetAmount;
	}
	money& getTotalActual() {
		return totalActual;
	}
	budgetCategory& getBudgetCategory(int index) {
		return budgetList[index];
	}
	/*vector<budgetCategory>& getBudgetList() {
		return budgetList;
	}*/
	int getBudgetListSize() {
		return (int)budgetList.size();
	}
	int getbudgetCategoryIndex(string category) {
		for (unsigned int i = 0; i < budgetList.size(); i++) {
			if (category.compare(budgetList[i].getCategory()) == 0) {
				return i;
			}
		}
		return -1;
	}
	bool setBudgetAmount(money m) {
		if (m.negative()) {
			budgetAmount = money(0,0);
			return false;
		}
		budgetAmount = m;
		return true;
	}

	void include(budgetCategory b) {
		budgetList.push_back(b);
		totalCost += b.getCost();
	}
	bool remove(string category) {
		int i = getbudgetCategoryIndex(category);
		if (i < 0) {
			return false;
		}
		totalCost -= (budgetList[i].getCost());
		totalActual -= (budgetList[i].getActual());
		budgetList.erase(budgetList.begin()+i);
		return true;
	}

	string toReadable() {
		stringstream result;
		result << name << '\n';
		result << "Budget: " << budgetAmount.toReadable() << "\n\n";
		int longestCategorySize = 0;
		for (unsigned int i = 0; i < budgetList.size(); i++) {
			if (budgetList[i].getCategory().size() > (unsigned int)longestCategorySize)
				longestCategorySize = budgetList[i].getCategory().size();
		}
		for (unsigned int i = 0; i < budgetList.size(); i++) {
			result << budgetList[i].getCategory();
			for (unsigned int j = 0; j < (unsigned int)longestCategorySize - budgetList[i].getCategory().size() + 1; j++) {
				result << '-';
			}
			result << budgetList[i].getCost().toReadable() << '\n';
		}
		result << "Total";
		for (int i = 0; i < longestCategorySize - 4; i++) {
			result << '-';
		}
		result << totalCost.toReadable() << '\n';
		return result.str();
	}
	string toFile() {
		stringstream result;
		result << name << ';' << budgetAmount.toFile() << ';' << totalCost.toFile() << ';' << totalActual.toFile() << '#';
		for (unsigned int i = 0; i < budgetList.size(); i++) {
			result << budgetList[i].toFile() << "%";
		}
		return result.str();
	}
	bool buildFromFile(const string& line) {
		int previousLineBreak = 0;
		vector<int> breaks;
		for (unsigned int i = 0; i < line.size(); i++) {
			if (line[i] == ';') {
				breaks.push_back(i);
			}
			if (line[i] == '#') {
				previousLineBreak = i+1;
				break;
			}
		}
		if (breaks.size() > 3 || previousLineBreak == 0)
			return false;
		name = line.substr(0, breaks[0]);
		budgetAmount = money(line.substr(breaks[0]+1, breaks[1]));
		totalCost = money(line.substr(breaks[1]+1, breaks[2]));
		totalActual = money(line.substr(breaks[2]+1, previousLineBreak));

		bool proceed = false;
		for (unsigned int i = 0; i < line.size()-1; i++) {
			if (line[i] == '%') {
				budgetCategory temp;
				proceed = temp.buildFromFile(line.substr(previousLineBreak, i - previousLineBreak));
				if (!proceed)
					return false;
				budgetList.push_back(temp);
				previousLineBreak = i+1;
			}
		}
		return true;
	}

	budget(money m = money(0,0), string n = "Untitled") {
		if (m.negative())
			m = money(0,0);
		budgetAmount = m;
		name = n;
	}
};