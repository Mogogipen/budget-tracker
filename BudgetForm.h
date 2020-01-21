#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "rows.hpp"

void convertSysToStdString(System::String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

namespace budgettracker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BudgetForm
	/// </summary>
	public ref class BudgetForm : public System::Windows::Forms::Form
	{
	
	private:
		//
		// Budget variables:
		//
		budget* activeBudget;
		System::Collections::Generic::List<budgetRow^> categoryTable;
		bool alter = false;
	public:
		BudgetForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			init();

			this->budgetTitle->Text = gcnew String(this->activeBudget->getName().c_str());
			this->totalBudgetLabel->Text = gcnew String(this->activeBudget->getBudgetAmount().toReadable().c_str());
			this->totalCostLabel->Text = gcnew String(this->activeBudget->getTotalActual().toReadable().c_str());
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BudgetForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ topStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;

	private: System::Windows::Forms::SplitContainer^ splitContainer1;

	private: System::Windows::Forms::Button^ addNewButton;
	private: System::Windows::Forms::TextBox^ alterBudgetTitle;
	private: System::Windows::Forms::Button^ alterTitleButton;
	private: System::Windows::Forms::Label^ budgetTitle;
	private: System::Windows::Forms::Label^ totalBudgetLabel;
	private: System::Windows::Forms::Label^ totalCostLabel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->topStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->totalBudgetLabel = (gcnew System::Windows::Forms::Label());
			this->totalCostLabel = (gcnew System::Windows::Forms::Label());
			this->budgetTitle = (gcnew System::Windows::Forms::Label());
			this->alterTitleButton = (gcnew System::Windows::Forms::Button());
			this->alterBudgetTitle = (gcnew System::Windows::Forms::TextBox());
			this->addNewButton = (gcnew System::Windows::Forms::Button());
			this->topStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// topStrip
			// 
			this->topStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->topStrip->Location = System::Drawing::Point(0, 0);
			this->topStrip->Name = L"topStrip";
			this->topStrip->Size = System::Drawing::Size(889, 24);
			this->topStrip->TabIndex = 0;
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveToolStripMenuItem,
					this->openToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->AutoSize = false;
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &BudgetForm::saveToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->AutoSize = false;
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &BudgetForm::openToolStripMenuItem_Click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->IsSplitterFixed = true;
			this->splitContainer1->Location = System::Drawing::Point(0, 24);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::Color::MediumTurquoise;
			this->splitContainer1->Panel1->Controls->Add(this->totalBudgetLabel);
			this->splitContainer1->Panel1->Controls->Add(this->totalCostLabel);
			this->splitContainer1->Panel1->Controls->Add(this->budgetTitle);
			this->splitContainer1->Panel1->Controls->Add(this->alterTitleButton);
			this->splitContainer1->Panel1->Controls->Add(this->alterBudgetTitle);
			this->splitContainer1->Panel1->Controls->Add(this->addNewButton);
			this->splitContainer1->Panel1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->splitContainer1->Size = System::Drawing::Size(889, 556);
			this->splitContainer1->SplitterDistance = 29;
			this->splitContainer1->SplitterWidth = 1;
			this->splitContainer1->TabIndex = 1;
			// 
			// totalBudgetLabel
			// 
			this->totalBudgetLabel->AutoSize = true;
			this->totalBudgetLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalBudgetLabel->Location = System::Drawing::Point(500, 5);
			this->totalBudgetLabel->Name = L"totalBudgetLabel";
			this->totalBudgetLabel->Size = System::Drawing::Size(110, 20);
			this->totalBudgetLabel->TabIndex = 5;
			this->totalBudgetLabel->Text = L"<totalBudget>";
			// 
			// totalCostLabel
			// 
			this->totalCostLabel->AutoSize = true;
			this->totalCostLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalCostLabel->Location = System::Drawing::Point(700, 5);
			this->totalCostLabel->Name = L"totalCostLabel";
			this->totalCostLabel->Size = System::Drawing::Size(91, 20);
			this->totalCostLabel->TabIndex = 4;
			this->totalCostLabel->Text = L"<totalCost>";
			// 
			// budgetTitle
			// 
			this->budgetTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->budgetTitle->AutoSize = true;
			this->budgetTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->budgetTitle->Location = System::Drawing::Point(60, 2);
			this->budgetTitle->Name = L"budgetTitle";
			this->budgetTitle->Size = System::Drawing::Size(0, 24);
			this->budgetTitle->TabIndex = 0;
			this->budgetTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// alterTitleButton
			// 
			this->alterTitleButton->Location = System::Drawing::Point(820, 3);
			this->alterTitleButton->Name = L"alterTitleButton";
			this->alterTitleButton->Size = System::Drawing::Size(23, 23);
			this->alterTitleButton->TabIndex = 3;
			this->alterTitleButton->Text = L"*";
			this->alterTitleButton->UseVisualStyleBackColor = true;
			this->alterTitleButton->Click += gcnew System::EventHandler(this, &BudgetForm::alterTitleButton_Click);
			// 
			// alterBudgetTitle
			// 
			this->alterBudgetTitle->BackColor = System::Drawing::Color::PowderBlue;
			this->alterBudgetTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->alterBudgetTitle->Location = System::Drawing::Point(59, 0);
			this->alterBudgetTitle->Name = L"alterBudgetTitle";
			this->alterBudgetTitle->Size = System::Drawing::Size(162, 29);
			this->alterBudgetTitle->TabIndex = 2;
			this->alterBudgetTitle->Text = L"Here";
			this->alterBudgetTitle->Visible = false;
			this->alterBudgetTitle->WordWrap = false;
			// 
			// addNewButton
			// 
			this->addNewButton->Location = System::Drawing::Point(848, 3);
			this->addNewButton->Name = L"addNewButton";
			this->addNewButton->Size = System::Drawing::Size(23, 23);
			this->addNewButton->TabIndex = 1;
			this->addNewButton->Text = L"+";
			this->addNewButton->UseVisualStyleBackColor = true;
			this->addNewButton->Click += gcnew System::EventHandler(this, &BudgetForm::addNewButton_click);
			// 
			// BudgetForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 580);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->topStrip);
			this->MainMenuStrip = this->topStrip;
			this->Name = L"BudgetForm";
			this->Text = L"Budget Tracker 0.1";
			this->topStrip->ResumeLayout(false);
			this->topStrip->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		//Place in constructor
		void init() {
			activeBudget = new budget(money(0, 0), "Unknown");
			activeBudget->include(budgetCategory(money(0,0), "uncategorized" ));

			for (int i = 0; i < activeBudget->getBudgetListSize(); i++) {
				addBudgetRow(&(activeBudget->getBudgetCategory(i)));
			}
		}

		//Allow the title name to be changed (switch title label to a textbox)
		void switchTitleToAlter() {
			this->budgetTitle->Visible = false;
			this->alterBudgetTitle->Visible = true;
			this->alterBudgetTitle->Text = gcnew String(this->activeBudget->getName().c_str());
		}
		//Save the altered title name (switch textbox to the title label)
		void switchTitleToViewOnly() {
			std::string temp;
			convertSysToStdString(this->alterBudgetTitle->Text, temp);
			this->activeBudget->getName() = temp;

			this->alterBudgetTitle->Visible = false;
			this->budgetTitle->Visible = true;
			this->budgetTitle->Text = gcnew String(this->activeBudget->getName().c_str());
		}


		//Use to create a budgetRow instead of its constructor
		//------These functions make line deletion possible.
		void addBudgetRow(budgetCategory* b, bool t) {
			//activeBudget->include(*b);

			budgetRow^ temp = gcnew budgetRow(b, t);
			this->categoryTable.Add(temp);

			temp->removeButton->Click += gcnew System::EventHandler(this, &BudgetForm::removeRow);

			this->splitContainer1->Panel2->Controls->Add(temp->tableLayout);
		}
		void addBudgetRow(budgetCategory* b) {
			addBudgetRow(b, false);
		}

		//Use to remove a budgetRow
		void removeBudgetRow(int index) {
			budgetRow^ removeLine;
			removeLine = categoryTable[index];

			if (removeLine != nullptr) {
				this->splitContainer1->Panel2->Controls->Remove(removeLine->tableLayout);
				this->categoryTable.Remove(removeLine);
				//TODO: remove removeLine's budgetCategory from activeBudget
				string temp;
				convertSysToStdString(removeLine->categoryName->Text, temp);
				cout << temp;
				activeBudget->remove(temp);
				delete removeLine;
				for (int i = 0; i < activeBudget->getBudgetListSize(); i++) {
					cout << activeBudget->getBudgetCategory(i).getCategory();
				}
			}

			for (int i = index; i < this->categoryTable.Count; i++) {
				int tempX = this->categoryTable[i]->tableLayout->Location.X;
				int tempY = this->categoryTable[i]->tableLayout->Location.Y;
				tempY -= 32;
				this->categoryTable[i]->tableLayout->Location = Point(tempX, tempY);
			}
		}


	//
	// Events
	//
	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog;
		saveFileDialog = gcnew System::Windows::Forms::SaveFileDialog;
		saveFileDialog->Filter = "budget files (*bud)|*.bud";

		// Show the FolderBrowserDialog.
		System::Windows::Forms::DialogResult result = saveFileDialog->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::OK)
		{
			String^ folderName = saveFileDialog->FileName;
			std::string file;
			convertSysToStdString(folderName, file);
			std::ofstream out(file);
			std::string fileContents = activeBudget->toFile();
			out << fileContents;
			out.close();
			std::cout << activeBudget->toFile();
		}
	}
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog;
		openFileDialog = gcnew System::Windows::Forms::OpenFileDialog;
		openFileDialog->Filter = "budget files (*.bud)|*.bud";

		// Show the FolderBrowserDialog.
		System::Windows::Forms::DialogResult result = openFileDialog->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::OK)
		{
			String^ folderName = openFileDialog->FileName;
			std::string file;
			convertSysToStdString(folderName, file);
			std::ifstream in(file);
			std::string fileContents;
			std::getline(in, fileContents);
			in.close();
			activeBudget = new budget();
			activeBudget->buildFromFile(fileContents);
			std::cout << activeBudget->toFile();

			for (int i = 0; i < activeBudget->getBudgetListSize(); i++) {
				addBudgetRow(& (activeBudget->getBudgetCategory(i)) );
			}
			//String^ temp = categoryTable[0]->categoryName->Text;
			//this->Text = temp;
			//String^ temp2 = gcnew String(activeBudget->getBudgetCategory(0).getCategory().c_str());
			//this->budgetTitle->Text = temp2;
		}
	}
	private: System::Void addNewButton_click(System::Object^ sender, System::EventArgs^ e) {
		//budgetCategory* newCategory = new budgetCategory();
		activeBudget->include(budgetCategory());
		this->addBudgetRow(& (activeBudget->getBudgetCategory(activeBudget->getBudgetListSize()-1) ), true);
	}
	private: System::Void alterTitleButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->alter) {
			switchTitleToViewOnly();
		} else {
			switchTitleToAlter();
		}
		this->alter = !this->alter;
	}
	private: System::Void removeRow(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < this->categoryTable.Count; i++) {
			if (categoryTable[i]->removeButton == sender) {
				removeBudgetRow(i);
			}
		}
	}
};
}
