#pragma once

#include "budget.hpp"

using namespace System;
using namespace System::Windows::Forms;

ref class budgetRow {
private:
	static int rowCount = 0;
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
		convertSysToStdString(this->categoryAlter->Text, temp);
		this->category->setCategory(temp);
		convertSysToStdString(this->budgetAlter->Text, temp);
		this->category->setCost(money(temp));

		//Break down table
		this->tableLayout->Controls->Clear();
		this->tableLayout->ColumnStyles->Clear();

		//Rebuild table
		this->tableLayout->ColumnCount = 6;
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
		this->tableLayout->Controls->Add(this->categoryName, 0, 0);
		this->tableLayout->Controls->Add(this->cost, 1, 0);
		this->tableLayout->Controls->Add(this->actual, 2, 0);
		this->tableLayout->Controls->Add(this->alter, 3, 0);
		this->tableLayout->Controls->Add(this->remove, 4, 0);
		this->tableLayout->Controls->Add(this->toggleTransactions, 5, 0);

		update();
	}



	System::Void switchToAlter() {
		//Break down table
		this->tableLayout->Controls->Clear();
		this->tableLayout->ColumnStyles->Clear();

		//Rubuld table 
		this->tableLayout->ColumnCount = 7;
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
		this->tableLayout->Controls->Add(this->categoryAlter, 0, 0);
		this->tableLayout->Controls->Add(this->dollarSign, 1, 0);
		this->tableLayout->Controls->Add(this->budgetAlter, 2, 0);
		this->tableLayout->Controls->Add(this->actual, 3, 0);
		this->tableLayout->Controls->Add(this->alter, 4, 0);
		this->tableLayout->Controls->Add(this->remove, 5, 0);
		this->tableLayout->Controls->Add(this->toggleTransactions, 6, 0);

		update();
	}





public:
	budgetCategory* category;
	System::Windows::Forms::TableLayoutPanel^ tableLayout;
	System::Windows::Forms::Label^ categoryName;
	System::Windows::Forms::Label^ cost;
	System::Windows::Forms::Label^ actual;
	System::Windows::Forms::Label^ dollarSign;
	System::Windows::Forms::Button^ alter;
	System::Windows::Forms::Button^ remove;
	System::Windows::Forms::Button^ toggleTransactions;
	System::Windows::Forms::TextBox^ categoryAlter;
	System::Windows::Forms::TextBox^ budgetAlter;
	transaction* test;

	budgetRow(budgetCategory* bc) {
		category = bc;
		rowCount++;
		
		//Instantiate Variables
		this->tableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
		this->categoryName = (gcnew System::Windows::Forms::Label());
		this->cost = (gcnew System::Windows::Forms::Label());
		this->actual = (gcnew System::Windows::Forms::Label());
		this->dollarSign = (gcnew System::Windows::Forms::Label());
		this->alter = (gcnew System::Windows::Forms::Button());
		this->remove = (gcnew System::Windows::Forms::Button());
		this->toggleTransactions = (gcnew System::Windows::Forms::Button());
		this->categoryAlter = (gcnew System::Windows::Forms::TextBox());
		this->budgetAlter = (gcnew System::Windows::Forms::TextBox());

		this->tableLayout->SuspendLayout();

		// 
		// tableLayout
		// 
		this->tableLayout->ColumnCount = 6;
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
		this->tableLayout->Controls->Add(this->categoryName, 0, 0);
		this->tableLayout->Controls->Add(this->cost, 1, 0);
		this->tableLayout->Controls->Add(this->actual, 2, 0);
		this->tableLayout->Controls->Add(this->alter, 3, 0);
		this->tableLayout->Controls->Add(this->remove, 4, 0);
		this->tableLayout->Controls->Add(this->toggleTransactions, 5, 0);
		this->tableLayout->Location = System::Drawing::Point(153, 25);
		this->tableLayout->Name = L"tableLayout";
		this->tableLayout->RowCount = 1;
		this->tableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		this->tableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
		this->tableLayout->Size = System::Drawing::Size(628, 32);
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
		// categoryAlter
		//
		this->categoryAlter->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->categoryAlter->Location = System::Drawing::Point(216, 6);
		this->categoryAlter->Name = L"categoryAlter";
		this->categoryAlter->Size = System::Drawing::Size(100, 20);
		this->categoryAlter->TabIndex = 5;
		this->categoryAlter->Text = gcnew String(this->category->getCategory().c_str());
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
		// budgetAlter
		//
		this->budgetAlter->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->budgetAlter->Location = System::Drawing::Point(216, 6);
		this->budgetAlter->Name = L"budgetAlter";
		this->budgetAlter->Size = System::Drawing::Size(100, 20);
		this->budgetAlter->TabIndex = 5;
		this->budgetAlter->Text = gcnew String(this->category->getCost().toFile().c_str());
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
		// alter
		// 
		this->alter->Location = System::Drawing::Point(522, 3);
		this->alter->Name = L"alter";
		this->alter->Size = System::Drawing::Size(28, 23);
		this->alter->TabIndex = 2;
		this->alter->Text = L"*";
		this->alter->UseVisualStyleBackColor = true;
		this->alter->Click += gcnew System::EventHandler(this, &budgetRow::alterClick);
		// 
		// remove
		// 
		this->remove->Location = System::Drawing::Point(556, 3);
		this->remove->Name = L"remove";
		this->remove->Size = System::Drawing::Size(26, 23);
		this->remove->TabIndex = 3;
		this->remove->Text = L"-";
		this->remove->UseVisualStyleBackColor = true;
		// 
		// toggleTransactions
		// 
		this->toggleTransactions->Location = System::Drawing::Point(588, 3);
		this->toggleTransactions->Name = L"toggleTransactions";
		this->toggleTransactions->Size = System::Drawing::Size(28, 23);
		this->toggleTransactions->TabIndex = 4;
		this->toggleTransactions->Text = L">";
		this->toggleTransactions->UseVisualStyleBackColor = true;

		this->tableLayout->ResumeLayout(false);
		this->tableLayout->PerformLayout();
	}
	static int getRowCount() {
		return rowCount;
	}
	
	System::Void update() {
		this->actual->Text = gcnew String(category->getActual().toReadable().c_str());
		this->budgetAlter->Text = gcnew String(category->getCost().toFile().c_str());
		this->cost->Text = gcnew String(category->getCost().toReadable().c_str());
		this->categoryName->Text = gcnew String(category->getCategory().c_str());
		this->categoryAlter->Text = gcnew String(category->getCategory().c_str());
	}
};

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


	transactionRow(transaction* t) {
		trans = t;
		this->tableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
		this->cost = (gcnew System::Windows::Forms::Label());
		this->alter = (gcnew System::Windows::Forms::Button());
		this->remove = (gcnew System::Windows::Forms::Button());
		this->transName = (gcnew System::Windows::Forms::Label());
		this->dollarSign = (gcnew System::Windows::Forms::Label());

		this->tableLayout->SuspendLayout();

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

		this->tableLayout->ResumeLayout(false);
		this->tableLayout->PerformLayout();
	}

	void update() {

	}
};