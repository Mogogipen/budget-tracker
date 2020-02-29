#pragma once

#include "budget.hpp"

using namespace System;
using namespace System::Windows::Forms;

//
// A row that displays a transaction
//

ref class transactionRow {
private:
	transaction* trans;
	bool alterValues = false;

	void convertSysToStdString(System::String^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	//
	// Event handlers
	//
	System::Void alterClick(System::Object^ sender, System::EventArgs^ e) {
		if (alterValues) {
			switchToViewOnly();
		}
		else {
			switchToAlter();
		}
		alterValues = !alterValues;
	}


	System::Void switchToViewOnly() {
		//Load new values
		std::string temp;
		convertSysToStdString(this->nameAlter->Text, temp);
		this->trans->setName(temp);
		temp = "";
		convertSysToStdString(this->costAlter->Text, temp);
		this->trans->setCost(money(temp));

		//Break down table
		this->tableLayout->Controls->Clear();
		this->tableLayout->ColumnStyles->Clear();

		//Rebuild table
		this->tableLayout->ColumnCount = 4;
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			51.42857F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			48.57143F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			34)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			20)));
		this->tableLayout->Controls->Add(this->transName, 0, 0);
		this->tableLayout->Controls->Add(this->cost, 1, 0);
		this->tableLayout->Controls->Add(this->alter, 2, 0);
		this->tableLayout->Controls->Add(this->remove, 3, 0);

		update();
	}



	System::Void switchToAlter() {
		//Break down table
		this->tableLayout->Controls->Clear();
		this->tableLayout->ColumnStyles->Clear();

		//Rubuld table 
		this->tableLayout->ColumnCount = 5;
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			50.85714F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			11.71429F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			37.42857F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));

		this->tableLayout->Controls->Add(this->nameAlter, 0, 0);
		this->tableLayout->Controls->Add(this->dollarSign, 1, 0);
		this->tableLayout->Controls->Add(this->costAlter, 2, 0);
		this->tableLayout->Controls->Add(this->alter, 3, 0);
		this->tableLayout->Controls->Add(this->remove, 4, 0);

		update();
	}

public:
	System::Windows::Forms::TableLayoutPanel^ tableLayout;
	System::Windows::Forms::Button^ alter;
	System::Windows::Forms::Button^ remove;
	System::Windows::Forms::Label^ transName;
	System::Windows::Forms::Label^ cost;
	System::Windows::Forms::Label^ dollarSign;
	System::Windows::Forms::TextBox^ nameAlter;
	System::Windows::Forms::TextBox^ costAlter;


	transactionRow(transaction* t, int initHeight) {
		trans = t;
		this->tableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
		this->cost = (gcnew System::Windows::Forms::Label());
		this->alter = (gcnew System::Windows::Forms::Button());
		this->remove = (gcnew System::Windows::Forms::Button());
		this->transName = (gcnew System::Windows::Forms::Label());
		this->dollarSign = (gcnew System::Windows::Forms::Label());
		this->nameAlter = (gcnew System::Windows::Forms::TextBox());
		this->costAlter = (gcnew System::Windows::Forms::TextBox());

	}

	void update() {

	}

	void build() {
		// 
		// tableLayout
		// 
		this->tableLayout->ColumnCount = 4;
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			51.42857F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			48.57143F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			34)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			20)));
		this->tableLayout->Controls->Add(this->transName, 0, 0);
		this->tableLayout->Controls->Add(this->cost, 1, 0);
		this->tableLayout->Controls->Add(this->alter, 2, 0);
		this->tableLayout->Controls->Add(this->remove, 3, 0);
		this->tableLayout->Location = System::Drawing::Point(326, 58);
		this->tableLayout->Name = L"tableLayoutPanel2";
		this->tableLayout->RowCount = 1;
		this->tableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		this->tableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
		this->tableLayout->Size = System::Drawing::Size(415, 32);
		this->tableLayout->TabIndex = 0;
		// 
		// cost
		// 
		this->cost->Anchor = System::Windows::Forms::AnchorStyles::None;
		this->cost->AutoSize = true;
		this->cost->Location = System::Drawing::Point(246, 9);
		this->cost->Name = L"label4";
		this->cost->Size = System::Drawing::Size(35, 13);
		this->cost->TabIndex = 3;
		this->cost->Text = L"label4";
		// 
		// dollarSign
		// 
		this->dollarSign->Anchor = System::Windows::Forms::AnchorStyles::Right;
		this->dollarSign->AutoSize = true;
		this->dollarSign->Location = System::Drawing::Point(197, 9);
		this->dollarSign->Name = L"dollarSign";
		this->dollarSign->Size = System::Drawing::Size(13, 13);
		this->dollarSign->TabIndex = 6;
		this->dollarSign->Text = L"$";
		// 
		// alter
		// 
		this->alter->Location = System::Drawing::Point(351, 3);
		this->alter->Name = L"button4";
		this->alter->Size = System::Drawing::Size(26, 23);
		this->alter->TabIndex = 0;
		this->alter->Text = L"*";
		this->alter->UseVisualStyleBackColor = true;
		this->alter->Click += gcnew System::EventHandler(this, &transactionRow::alterClick);
		// 
		// remove
		// 
		this->remove->Location = System::Drawing::Point(383, 3);
		this->remove->Name = L"button5";
		this->remove->Size = System::Drawing::Size(27, 23);
		this->remove->TabIndex = 1;
		this->remove->Text = L"-";
		this->remove->UseVisualStyleBackColor = true;
		// 
		// transName
		// 
		this->transName->Anchor = System::Windows::Forms::AnchorStyles::None;
		this->transName->AutoSize = true;
		this->transName->Location = System::Drawing::Point(72, 9);
		this->transName->Name = L"label3";
		this->transName->Size = System::Drawing::Size(35, 13);
		this->transName->TabIndex = 2;
		this->transName->Text = L"label3";

		update();
	}
};

//
// A row that displays a budget category
//

ref class budgetRow {
private:
	static int rowCount = 0;
	bool alterValues = false;

	budgetCategory* category;

	void convertSysToStdString(System::String^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}


	//A toString() function that returns a System::String
	String^ toString() {
		return gcnew String(category->getCategory().c_str());
	}


	//
	// Event handlers
	//
	System::Void alterClick(System::Object^ sender, System::EventArgs^ e) {
		if (alterValues) {
			switchToViewOnly();
		}
		else {
			switchToAlter();
		}
		alterValues = !alterValues;

	}
	//System::Void removeClick(System::Object^ sender, System::EventArgs^ e) {
	//	if (this->window->removeRow(this))
	//		delete this;
	//}

	System::Void viewTransClick(System::Object^ sender, System::EventArgs^ e) {
		cout << this->category << endl;
	}



	System::Void switchToViewOnly() {
		//Load new values
		std::string temp;
		convertSysToStdString(this->alterCategory->Text, temp);
		this->category->setCategory(temp);
		convertSysToStdString(this->alterBudget->Text, temp);
		this->category->setCost(money(temp));

		//Break down table
		this->tableLayout->Controls->Clear();
		this->tableLayout->ColumnStyles->Clear();

		//Rebuild table
		this->tableLayout->ColumnCount = 7;
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			33.33332F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			33.33334F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			33.33334F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->Controls->Add(this->categoryName, 0, 0);
		this->tableLayout->Controls->Add(this->cost, 1, 0);
		this->tableLayout->Controls->Add(this->actual, 2, 0);
		this->tableLayout->Controls->Add(this->alterButton, 3, 0);
		this->tableLayout->Controls->Add(this->addTransButton, 4, 0);
		this->tableLayout->Controls->Add(this->viewTransactionsButton, 5, 0);
		this->tableLayout->Controls->Add(this->removeButton, 6, 0);

		update();
	}


	System::Void switchToAlter() {
		//Break down table
		this->tableLayout->Controls->Clear();
		this->tableLayout->ColumnStyles->Clear();

		//Rubuld table 
		this->tableLayout->ColumnCount = 8;
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			33.26886F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			7.156309F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			27.11864F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			32.39171F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->Controls->Add(this->alterCategory, 0, 0);
		this->tableLayout->Controls->Add(this->dollarSign, 1, 0);
		this->tableLayout->Controls->Add(this->alterBudget, 2, 0);
		this->tableLayout->Controls->Add(this->actual, 3, 0);
		this->tableLayout->Controls->Add(this->alterButton, 4, 0);
		this->tableLayout->Controls->Add(this->addTransButton, 5, 0);
		this->tableLayout->Controls->Add(this->viewTransactionsButton, 6, 0);
		this->tableLayout->Controls->Add(this->removeButton, 7, 0);

		update();
	}





public:
	System::Windows::Forms::TableLayoutPanel^ tableLayout;
	System::Windows::Forms::Label^ categoryName;
	System::Windows::Forms::Label^ cost;
	System::Windows::Forms::Label^ actual;
	System::Windows::Forms::Label^ dollarSign;
	System::Windows::Forms::Button^ alterButton;
	System::Windows::Forms::Button^ removeButton;
	System::Windows::Forms::Button^ viewTransactionsButton;
	System::Windows::Forms::Button^ addTransButton;
	System::Windows::Forms::TextBox^ alterCategory;
	System::Windows::Forms::TextBox^ alterBudget;

	System::Collections::Generic::List<transactionRow^> rows;

	budgetRow(budgetCategory* bc, bool alter) {
		category = bc;
		rowCount++;

		//Instantiate Variables
		this->tableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
		this->categoryName = (gcnew System::Windows::Forms::Label());
		this->cost = (gcnew System::Windows::Forms::Label());
		this->actual = (gcnew System::Windows::Forms::Label());
		this->dollarSign = (gcnew System::Windows::Forms::Label());
		this->alterButton = (gcnew System::Windows::Forms::Button());
		this->removeButton = (gcnew System::Windows::Forms::Button());
		this->viewTransactionsButton = (gcnew System::Windows::Forms::Button());
		this->addTransButton = (gcnew System::Windows::Forms::Button());
		this->alterCategory = (gcnew System::Windows::Forms::TextBox());
		this->alterBudget = (gcnew System::Windows::Forms::TextBox());
		for (int i = 0; i < (int)bc->getReceipts().size(); i++) {
			this->rows.Add(gcnew transactionRow(&(category->getReceipts()[i]), 1) );
		}

		alterValues = !alter;
		build();
	}

	~budgetRow() {
		rowCount--;
	}

	static int getRowCount() {
		return rowCount;
	}

	System::Void update() {
		this->actual->Text = gcnew String(category->getActual().toReadable().c_str());
		this->alterBudget->Text = gcnew String(category->getCost().toFile().c_str());
		this->cost->Text = gcnew String(category->getCost().toReadable().c_str());
		this->categoryName->Text = gcnew String(category->getCategory().c_str()); //Error occurs here
		this->alterCategory->Text = gcnew String(category->getCategory().c_str());
	}

	private:
	void build() {
		// 
		// tableLayout
		// 
		this->tableLayout->ColumnCount = 7;
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			33.33332F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			33.33334F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			33.33334F)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			32)));
		this->tableLayout->Controls->Add(this->categoryName, 0, 0);
		this->tableLayout->Controls->Add(this->cost, 1, 0);
		this->tableLayout->Controls->Add(this->actual, 2, 0);
		this->tableLayout->Controls->Add(this->alterButton, 3, 0);
		this->tableLayout->Controls->Add(this->addTransButton, 4, 0);
		this->tableLayout->Controls->Add(this->viewTransactionsButton, 5, 0);
		this->tableLayout->Controls->Add(this->removeButton, 6, 0);
		this->tableLayout->Location = System::Drawing::Point(100, 32*(rowCount));
		this->tableLayout->Name = L"tableLayout";
		this->tableLayout->RowCount = 1;
		this->tableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		this->tableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
		this->tableLayout->Size = System::Drawing::Size(688, 32);
		this->tableLayout->TabIndex = 0;
		// 
		// categoryName
		// 
		this->categoryName->Anchor = System::Windows::Forms::AnchorStyles::None;
		this->categoryName->AutoSize = true;
		this->categoryName->Location = System::Drawing::Point(43, 9);
		this->categoryName->Name = L"categoryName";
		this->categoryName->Size = System::Drawing::Size(86, 13);
		this->categoryName->TabIndex = 0;
		this->categoryName->Text = gcnew String(category->getCategory().c_str());
		//
		// alterCategory
		//
		this->alterCategory->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->alterCategory->Location = System::Drawing::Point(216, 6);
		this->alterCategory->Name = L"categoryAlter";
		this->alterCategory->Size = System::Drawing::Size(100, 20);
		this->alterCategory->TabIndex = 5;
		this->alterCategory->Text = gcnew String(this->category->getCategory().c_str());
		// 
		// cost
		// 
		this->cost->Anchor = System::Windows::Forms::AnchorStyles::None;
		this->cost->AutoSize = true;
		this->cost->Location = System::Drawing::Point(227, 9);
		this->cost->Name = L"cost";
		this->cost->Size = System::Drawing::Size(65, 13);
		this->cost->TabIndex = 1;
		this->cost->Text = gcnew String(category->getCost().toReadable().c_str());
		// 
		// dollarSign
		// 
		this->dollarSign->Anchor = System::Windows::Forms::AnchorStyles::Right;
		this->dollarSign->AutoSize = true;
		this->dollarSign->Location = System::Drawing::Point(197, 9);
		this->dollarSign->Name = L"dollarSign";
		this->dollarSign->Size = System::Drawing::Size(13, 13);
		this->dollarSign->TabIndex = 6;
		this->dollarSign->Text = L"$";
		//
		// alterBudget
		//
		this->alterBudget->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->alterBudget->Location = System::Drawing::Point(216, 6);
		this->alterBudget->Name = L"budgetAlter";
		this->alterBudget->Size = System::Drawing::Size(100, 20);
		this->alterBudget->TabIndex = 5;
		this->alterBudget->Text = gcnew String(this->category->getCost().toFile().c_str());
		// 
		// actual
		// 
		this->actual->Anchor = System::Windows::Forms::AnchorStyles::None;
		this->actual->AutoSize = true;
		this->actual->Location = System::Drawing::Point(402, 9);
		this->actual->Name = L"actual";
		this->actual->Size = System::Drawing::Size(61, 13);
		this->actual->TabIndex = 5;
		this->actual->Text = gcnew String(category->getActual().toReadable().c_str());
		// 
		// alterButton
		// 
		this->alterButton->Location = System::Drawing::Point(522, 3);
		this->alterButton->Name = L"alter";
		this->alterButton->Size = System::Drawing::Size(26, 23);
		this->alterButton->TabIndex = 2;
		this->alterButton->Text = L"*";
		this->alterButton->UseVisualStyleBackColor = true;
		this->alterButton->Click += gcnew System::EventHandler(this, &budgetRow::alterClick);
		// 
		// addTransButton
		// 
		this->addTransButton->Location = System::Drawing::Point(556, 3);
		this->addTransButton->Name = L"addTrans";
		this->addTransButton->Size = System::Drawing::Size(26, 23);
		this->addTransButton->TabIndex = 3;
		this->addTransButton->Text = L"+";
		this->addTransButton->UseVisualStyleBackColor = true;
		// 
		// viewTransactionsButton
		// 
		this->viewTransactionsButton->Location = System::Drawing::Point(588, 3);
		this->viewTransactionsButton->Name = L"toggleTransactions";
		this->viewTransactionsButton->Size = System::Drawing::Size(26, 23);
		this->viewTransactionsButton->TabIndex = 4;
		this->viewTransactionsButton->Text = L">";
		this->viewTransactionsButton->UseVisualStyleBackColor = true;
		this->viewTransactionsButton->Click += gcnew System::EventHandler(this, &budgetRow::viewTransClick);
		// 
		// removeButton
		// 
		this->removeButton->Location = System::Drawing::Point(612, 3);
		this->removeButton->Name = L"remove";
		this->removeButton->Size = System::Drawing::Size(26, 23);
		this->removeButton->TabIndex = 5;
		this->removeButton->Text = L"-";
		this->removeButton->UseVisualStyleBackColor = true;

		if (alterValues) {
			switchToViewOnly();
		}
		else {
			switchToAlter();
		}
		alterValues = !alterValues;
	}
};