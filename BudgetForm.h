#pragma once
#include <vector>
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
	public:
		BudgetForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	protected:

	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::Label^ budgetTitle;
	private: System::Windows::Forms::Button^ addNewButton;




	//
	// Budget variables:
	//
	private:
		budget* activeBudget = new budget();

		System::Collections::Generic::List<budgetRow^> categoryTable;















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
			this->addNewButton = (gcnew System::Windows::Forms::Button());
			this->budgetTitle = (gcnew System::Windows::Forms::Label());
			this->topStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			runMyFuncs();
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
			this->splitContainer1->Panel1->Controls->Add(this->addNewButton);
			this->splitContainer1->Panel1->Controls->Add(this->budgetTitle);
			this->splitContainer1->Panel1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Size = System::Drawing::Size(889, 556);
			this->splitContainer1->SplitterDistance = 29;
			this->splitContainer1->SplitterWidth = 1;
			this->splitContainer1->TabIndex = 1;
			// 
			// addNewButton
			// 
			this->addNewButton->Location = System::Drawing::Point(848, 3);
			this->addNewButton->Name = L"button7";
			this->addNewButton->Size = System::Drawing::Size(23, 23);
			this->addNewButton->TabIndex = 1;
			this->addNewButton->Text = L"+";
			this->addNewButton->UseVisualStyleBackColor = true;
			this->addNewButton->Click += gcnew System::EventHandler(this, &BudgetForm::button7_Click);
			// 
			// budgetTitle
			// 
			this->budgetTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->budgetTitle->AutoSize = true;
			this->budgetTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->budgetTitle->Location = System::Drawing::Point(359, 0);
			this->budgetTitle->Name = L"budgetTitle";
			this->budgetTitle->Size = System::Drawing::Size(0, 24);
			this->budgetTitle->TabIndex = 0;
			this->budgetTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->Text = L"BudgetForm";
			this->topStrip->ResumeLayout(false);
			this->topStrip->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		//Place in constructor to build objects (after it build them itself)
		void init() {
		activeBudget = new budget();
		activeBudget->include(budgetCategory());
		for (int i = 0; i < activeBudget->getBudgetListSize(); i++) {
			categoryTable.Add(gcnew budgetRow(& (activeBudget->getBudgetCategory(i)) ) );
		}
		this->budgetTitle->Text = gcnew String(activeBudget->getName().c_str());
		for (int i = 0; i < categoryTable.Count; i++) {
			this->splitContainer1->Panel1->Controls->Add(this->categoryTable[i]->tableLayout);
		}
		transaction t(money(234), "walmart");
		transactionRow^ t1 = gcnew transactionRow(&t);
		this->splitContainer1->Panel1->Controls->Add(t1->tableLayout);
		}

		//Place in constructor after other layouts open
		void buildLayout() {

		}

		//Place in constructor before other layouts close
		void closeLayout() {

		}
		
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
			activeBudget->buildFromFile(fileContents);
		}
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
};
}
