#pragma once

// Include all functions headers
#include <msclr\marshal_cppstd.h>
#include "parsing.h"
#include "prettifying.h"
#include "minifying.h"
#include "deminifying.h"
#include "huffman.h"
#include "Compress.h"
#include "decompress.h"
#include<stack>
#include "xml_to_json.h"
#include "error.h"
#include"Form2.h"
namespace DSProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{


	public:

		MyForm(void)
		{
			undoStack = gcnew System::Collections::Generic::Stack<System::String^>();
			redoStack = gcnew System::Collections::Generic::Stack<System::String^>();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private:
		System::Windows::Forms::SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		System::Windows::Forms::Button^ Browse_button;
		System::Windows::Forms::OpenFileDialog^ openFileDialog1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::RichTextBox^ code_rtxt;
		System::Windows::Forms::Button^ error_btn;
		System::Windows::Forms::Button^ prettifying_btn;
		System::Windows::Forms::Button^ json_btn;
		System::Windows::Forms::Button^ minifying_btn;
		System::Windows::Forms::Button^ compressing_btn;
		System::Windows::Forms::Button^ decompressing_btn;
		System::Windows::Forms::ToolTip^ toolTip1;
		System::ComponentModel::IContainer^ components;
		System::Windows::Forms::Button^ deminifying_btn;
		System::Windows::Forms::Button^ undo_btn;
		System::Windows::Forms::Button^ redo_btn;
		System::Collections::Generic::Stack<String^>^ undoStack;
		System::Windows::Forms::Button^ Save;
	private: System::Windows::Forms::Button^ network;
	private: System::Windows::Forms::Label^ Undo;
	private: System::Windows::Forms::Label^ Redo;
	private: System::Windows::Forms::Label^ Networkanalysis;
	private: System::Windows::Forms::Label^ Find_errors;
	private: System::Windows::Forms::Label^ prettyfing;
	private: System::Windows::Forms::Label^ xmltojson;
	private: System::Windows::Forms::Label^ mini;
	private: System::Windows::Forms::Label^ Deminifying;
	private: System::Windows::Forms::Label^ Compress;
	private: System::Windows::Forms::Label^ Decompress;
	private: System::Windows::Forms::Label^ label2;



		   System::Collections::Generic::Stack<String^>^ redoStack;




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Browse_button = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->code_rtxt = (gcnew System::Windows::Forms::RichTextBox());
			this->error_btn = (gcnew System::Windows::Forms::Button());
			this->prettifying_btn = (gcnew System::Windows::Forms::Button());
			this->json_btn = (gcnew System::Windows::Forms::Button());
			this->minifying_btn = (gcnew System::Windows::Forms::Button());
			this->compressing_btn = (gcnew System::Windows::Forms::Button());
			this->decompressing_btn = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->deminifying_btn = (gcnew System::Windows::Forms::Button());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->undo_btn = (gcnew System::Windows::Forms::Button());
			this->redo_btn = (gcnew System::Windows::Forms::Button());
			this->network = (gcnew System::Windows::Forms::Button());
			this->Undo = (gcnew System::Windows::Forms::Label());
			this->Redo = (gcnew System::Windows::Forms::Label());
			this->Networkanalysis = (gcnew System::Windows::Forms::Label());
			this->Find_errors = (gcnew System::Windows::Forms::Label());
			this->prettyfing = (gcnew System::Windows::Forms::Label());
			this->xmltojson = (gcnew System::Windows::Forms::Label());
			this->mini = (gcnew System::Windows::Forms::Label());
			this->Deminifying = (gcnew System::Windows::Forms::Label());
			this->Compress = (gcnew System::Windows::Forms::Label());
			this->Decompress = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Browse_button
			// 
			this->Browse_button->Location = System::Drawing::Point(12, 96);
			this->Browse_button->Margin = System::Windows::Forms::Padding(2);
			this->Browse_button->Name = L"Browse_button";
			this->Browse_button->Size = System::Drawing::Size(91, 32);
			this->Browse_button->TabIndex = 0;
			this->Browse_button->Text = L"Browse";
			this->Browse_button->UseVisualStyleBackColor = true;
			this->Browse_button->Click += gcnew System::EventHandler(this, &MyForm::browse_btn);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(9, 18);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Select a file";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(107, 96);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 32);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Write the file ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::write_btn);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Enabled = false;
			this->textBox1->ImeMode = System::Windows::Forms::ImeMode::Katakana;
			this->textBox1->Location = System::Drawing::Point(11, 56);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(260, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"Please Choose a path...";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// code_rtxt
			// 
			this->code_rtxt->BackColor = System::Drawing::Color::White;
			this->code_rtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->code_rtxt->Location = System::Drawing::Point(11, 132);
			this->code_rtxt->Margin = System::Windows::Forms::Padding(2);
			this->code_rtxt->Name = L"code_rtxt";
			this->code_rtxt->Size = System::Drawing::Size(636, 608);
			this->code_rtxt->TabIndex = 6;
			this->code_rtxt->Text = L"";
			this->code_rtxt->Visible = false;
			this->code_rtxt->TextChanged += gcnew System::EventHandler(this, &MyForm::code_rtxt_TextChanged);
			// 
			// error_btn
			// 
			this->error_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"error_btn.BackgroundImage")));
			this->error_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->error_btn->Location = System::Drawing::Point(683, 211);
			this->error_btn->Margin = System::Windows::Forms::Padding(2);
			this->error_btn->Name = L"error_btn";
			this->error_btn->Size = System::Drawing::Size(86, 51);
			this->error_btn->TabIndex = 11;
			this->toolTip1->SetToolTip(this->error_btn, L"Find Bug");
			this->error_btn->UseVisualStyleBackColor = true;
			this->error_btn->Click += gcnew System::EventHandler(this, &MyForm::error_btn_Click);
			// 
			// prettifying_btn
			// 
			this->prettifying_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prettifying_btn.BackgroundImage")));
			this->prettifying_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->prettifying_btn->Location = System::Drawing::Point(683, 290);
			this->prettifying_btn->Margin = System::Windows::Forms::Padding(2);
			this->prettifying_btn->Name = L"prettifying_btn";
			this->prettifying_btn->Size = System::Drawing::Size(86, 51);
			this->prettifying_btn->TabIndex = 12;
			this->toolTip1->SetToolTip(this->prettifying_btn, L"Formatting (Prettifying)");
			this->prettifying_btn->UseVisualStyleBackColor = true;
			this->prettifying_btn->Click += gcnew System::EventHandler(this, &MyForm::prettifying_btn_Click);
			// 
			// json_btn
			// 
			this->json_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"json_btn.BackgroundImage")));
			this->json_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->json_btn->Location = System::Drawing::Point(683, 367);
			this->json_btn->Margin = System::Windows::Forms::Padding(2);
			this->json_btn->Name = L"json_btn";
			this->json_btn->Size = System::Drawing::Size(86, 51);
			this->json_btn->TabIndex = 10;
			this->toolTip1->SetToolTip(this->json_btn, L"Converting XML to JSON");
			this->json_btn->UseVisualStyleBackColor = true;
			this->json_btn->Click += gcnew System::EventHandler(this, &MyForm::json_btn_Click);
			// 
			// minifying_btn
			// 
			this->minifying_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"minifying_btn.BackgroundImage")));
			this->minifying_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->minifying_btn->Location = System::Drawing::Point(683, 444);
			this->minifying_btn->Margin = System::Windows::Forms::Padding(2);
			this->minifying_btn->Name = L"minifying_btn";
			this->minifying_btn->Size = System::Drawing::Size(86, 51);
			this->minifying_btn->TabIndex = 11;
			this->toolTip1->SetToolTip(this->minifying_btn, L"Minifying the XML file");
			this->minifying_btn->UseVisualStyleBackColor = true;
			this->minifying_btn->Click += gcnew System::EventHandler(this, &MyForm::minifying_btn_Click);
			// 
			// compressing_btn
			// 
			this->compressing_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"compressing_btn.BackgroundImage")));
			this->compressing_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->compressing_btn->Location = System::Drawing::Point(683, 601);
			this->compressing_btn->Margin = System::Windows::Forms::Padding(2);
			this->compressing_btn->Name = L"compressing_btn";
			this->compressing_btn->Size = System::Drawing::Size(86, 51);
			this->compressing_btn->TabIndex = 12;
			this->toolTip1->SetToolTip(this->compressing_btn, L"Compressing the data in the XML/JSON file");
			this->compressing_btn->UseVisualStyleBackColor = true;
			this->compressing_btn->Click += gcnew System::EventHandler(this, &MyForm::compressing_btn_Click);
			// 
			// decompressing_btn
			// 
			this->decompressing_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"decompressing_btn.BackgroundImage")));
			this->decompressing_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->decompressing_btn->Location = System::Drawing::Point(683, 673);
			this->decompressing_btn->Margin = System::Windows::Forms::Padding(2);
			this->decompressing_btn->Name = L"decompressing_btn";
			this->decompressing_btn->Size = System::Drawing::Size(86, 51);
			this->decompressing_btn->TabIndex = 13;
			this->toolTip1->SetToolTip(this->decompressing_btn, L"Decompressing the compressed file");
			this->decompressing_btn->UseVisualStyleBackColor = true;
			this->decompressing_btn->Click += gcnew System::EventHandler(this, &MyForm::decompressing_btn_Click);
			// 
			// deminifying_btn
			// 
			this->deminifying_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deminifying_btn.BackgroundImage")));
			this->deminifying_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->deminifying_btn->Location = System::Drawing::Point(683, 523);
			this->deminifying_btn->Margin = System::Windows::Forms::Padding(2);
			this->deminifying_btn->Name = L"deminifying_btn";
			this->deminifying_btn->Size = System::Drawing::Size(86, 51);
			this->deminifying_btn->TabIndex = 14;
			this->toolTip1->SetToolTip(this->deminifying_btn, L"Deminifying the XML file");
			this->deminifying_btn->UseVisualStyleBackColor = true;
			this->deminifying_btn->Click += gcnew System::EventHandler(this, &MyForm::deminifying_btn_Click);
			// 
			// Save
			// 
			this->Save->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Save.BackgroundImage")));
			this->Save->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Save->Enabled = false;
			this->Save->Location = System::Drawing::Point(466, 18);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(59, 44);
			this->Save->TabIndex = 16;
			this->toolTip1->SetToolTip(this->Save, L"Save the file");
			this->Save->UseVisualStyleBackColor = true;
			this->Save->Click += gcnew System::EventHandler(this, &MyForm::save_Click);
			// 
			// undo_btn
			// 
			this->undo_btn->BackColor = System::Drawing::Color::AliceBlue;
			this->undo_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"undo_btn.BackgroundImage")));
			this->undo_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->undo_btn->Location = System::Drawing::Point(564, 18);
			this->undo_btn->Name = L"undo_btn";
			this->undo_btn->Size = System::Drawing::Size(59, 44);
			this->undo_btn->TabIndex = 15;
			this->undo_btn->UseVisualStyleBackColor = false;
			this->undo_btn->Click += gcnew System::EventHandler(this, &MyForm::undo_Click);
			// 
			// redo_btn
			// 
			this->redo_btn->BackColor = System::Drawing::Color::AliceBlue;
			this->redo_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"redo_btn.BackgroundImage")));
			this->redo_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->redo_btn->Location = System::Drawing::Point(647, 18);
			this->redo_btn->MaximumSize = System::Drawing::Size(512, 512);
			this->redo_btn->Name = L"redo_btn";
			this->redo_btn->Size = System::Drawing::Size(59, 44);
			this->redo_btn->TabIndex = 9;
			this->redo_btn->UseVisualStyleBackColor = false;
			this->redo_btn->Click += gcnew System::EventHandler(this, &MyForm::redo_Click);
			// 
			// network
			// 
			this->network->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"network.BackgroundImage")));
			this->network->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->network->Location = System::Drawing::Point(683, 128);
			this->network->Name = L"network";
			this->network->Size = System::Drawing::Size(86, 51);
			this->network->TabIndex = 17;
			this->network->UseVisualStyleBackColor = true;
			this->network->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// Undo
			// 
			this->Undo->AutoSize = true;
			this->Undo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Undo->Location = System::Drawing::Point(577, 65);
			this->Undo->Name = L"Undo";
			this->Undo->Size = System::Drawing::Size(41, 16);
			this->Undo->TabIndex = 18;
			this->Undo->Text = L"Undo";
			// 
			// Redo
			// 
			this->Redo->AutoSize = true;
			this->Redo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Redo->Location = System::Drawing::Point(653, 65);
			this->Redo->Name = L"Redo";
			this->Redo->Size = System::Drawing::Size(42, 16);
			this->Redo->TabIndex = 19;
			this->Redo->Text = L"Redo";
			// 
			// Networkanalysis
			// 
			this->Networkanalysis->AutoSize = true;
			this->Networkanalysis->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Networkanalysis->Location = System::Drawing::Point(675, 182);
			this->Networkanalysis->Name = L"Networkanalysis";
			this->Networkanalysis->Size = System::Drawing::Size(110, 16);
			this->Networkanalysis->TabIndex = 20;
			this->Networkanalysis->Text = L"Network analysis";
			// 
			// Find_errors
			// 
			this->Find_errors->AutoSize = true;
			this->Find_errors->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Find_errors->Location = System::Drawing::Point(690, 264);
			this->Find_errors->Name = L"Find_errors";
			this->Find_errors->Size = System::Drawing::Size(72, 16);
			this->Find_errors->TabIndex = 21;
			this->Find_errors->Text = L"Find errors";
			// 
			// prettyfing
			// 
			this->prettyfing->AutoSize = true;
			this->prettyfing->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->prettyfing->Location = System::Drawing::Point(696, 343);
			this->prettyfing->Name = L"prettyfing";
			this->prettyfing->Size = System::Drawing::Size(66, 16);
			this->prettyfing->TabIndex = 22;
			this->prettyfing->Text = L"Prettifying";
			// 
			// xmltojson
			// 
			this->xmltojson->AutoSize = true;
			this->xmltojson->Location = System::Drawing::Point(690, 420);
			this->xmltojson->Name = L"xmltojson";
			this->xmltojson->Size = System::Drawing::Size(72, 13);
			this->xmltojson->TabIndex = 23;
			this->xmltojson->Text = L"XML to JSON";
			// 
			// mini
			// 
			this->mini->AutoSize = true;
			this->mini->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mini->Location = System::Drawing::Point(696, 497);
			this->mini->Name = L"mini";
			this->mini->Size = System::Drawing::Size(60, 16);
			this->mini->TabIndex = 24;
			this->mini->Text = L"Minifying";
			// 
			// Deminifying
			// 
			this->Deminifying->AutoSize = true;
			this->Deminifying->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Deminifying->Location = System::Drawing::Point(690, 576);
			this->Deminifying->Name = L"Deminifying";
			this->Deminifying->Size = System::Drawing::Size(78, 16);
			this->Deminifying->TabIndex = 25;
			this->Deminifying->Text = L"Deminifying";
			// 
			// Compress
			// 
			this->Compress->AutoSize = true;
			this->Compress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Compress->Location = System::Drawing::Point(692, 654);
			this->Compress->Name = L"Compress";
			this->Compress->Size = System::Drawing::Size(70, 16);
			this->Compress->TabIndex = 26;
			this->Compress->Text = L"Compress";
			// 
			// Decompress
			// 
			this->Decompress->AutoSize = true;
			this->Decompress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Decompress->Location = System::Drawing::Point(683, 726);
			this->Decompress->Name = L"Decompress";
			this->Decompress->Size = System::Drawing::Size(86, 16);
			this->Decompress->TabIndex = 27;
			this->Decompress->Text = L"Decompress";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(474, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 16);
			this->label2->TabIndex = 28;
			this->label2->Text = L"Save";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::GhostWhite;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(797, 756);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Decompress);
			this->Controls->Add(this->Compress);
			this->Controls->Add(this->Deminifying);
			this->Controls->Add(this->mini);
			this->Controls->Add(this->xmltojson);
			this->Controls->Add(this->prettyfing);
			this->Controls->Add(this->Find_errors);
			this->Controls->Add(this->Networkanalysis);
			this->Controls->Add(this->Redo);
			this->Controls->Add(this->Undo);
			this->Controls->Add(this->network);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->redo_btn);
			this->Controls->Add(this->undo_btn);
			this->Controls->Add(this->deminifying_btn);
			this->Controls->Add(this->decompressing_btn);
			this->Controls->Add(this->compressing_btn);
			this->Controls->Add(this->minifying_btn);
			this->Controls->Add(this->json_btn);
			this->Controls->Add(this->prettifying_btn);
			this->Controls->Add(this->error_btn);
			this->Controls->Add(this->code_rtxt);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Browse_button);
			this->ForeColor = System::Drawing::SystemColors::Highlight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L" XML EDITOR ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/********************************************************************************
		*                                 Form Window                                   *
		*********************************************************************************/
		/*
		 * Type: Form
		 * Name: MyForm
		 * Desciption: change title of form to 'Choose File'
		 */
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = " XML EDITOR ";
		this->Size = System::Drawing::Size(813, 795);

	}

		   /********************************************************************************
		   *                                    Buttons                                    *
		   *********************************************************************************/




		   // Function to save the current state to the undo stack
	private: void SaveToUndoStack() {
		undoStack->Push(code_rtxt->Text);

	}

		   /*
			* Type: Button
			* Name: browse_btn (Browse Button)
			* Event: Click
			* Description: We can choose the XML file from our PC
			*/
	private: System::Void browse_btn(System::Object^ sender, System::EventArgs^ e) {

		openFileDialog1->Filter = "XML Files (*.xml)|*.xml";
		openFileDialog1->Title = "Choose a File";
		openFileDialog1->ShowDialog();
		String^ selectedFile = openFileDialog1->FileName;
		String^ fileName = System::IO::Path::GetFileName(selectedFile);
		String^ directory = System::IO::Path::GetDirectoryName(selectedFile);
		String^ lastFolderName = System::IO::Path::GetFileName(directory);
		String^ filePath = lastFolderName + "/" + fileName;
		textBox1->Text = filePath;

		directory = directory + "/" + fileName;
		directory = directory->Replace('\\', '/');     // replace \ with / in file path
		string dir = marshal_as<string>(directory);  // convert String^ type to string type
		dir = ReadXml(dir);                          // Parse XML file
		String^ final = marshal_as<System::String^>(dir);    // Convert string type to String^ type
		code_rtxt->Text = final;
	}

		   /*
			* Type: Button
			* Name: write_btn (Write File Button)
			* Event: Click
			* Description: It shows a textbox 'code_rtxt ' so we can write the XML file
			*/
	private: System::Void write_btn(System::Object^ sender, System::EventArgs^ e) {
		this->Size = System::Drawing::Size(813, 795);
		code_rtxt->Visible = true;
		code_rtxt->Size = System::Drawing::Size(636, 608);

	}

		   /*
			* Type: Button
			* Name: error_btn (Error Button)
			* Event: Click
			* Description: Shows error in the file
			*/

	private: System::Void error_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		code_rtxt->WordWrap = FALSE;

		String^ xmlFile = code_rtxt->Text;
		string file = marshal_as<string>(xmlFile);  // convert String^ type to string type
		SaveToUndoStack();
		TagForError* ptr = createDynamicArray(1000);
		code_rtxt->SelectionStart = 0;
		code_rtxt->SelectionLength = code_rtxt->Text->Length;
		code_rtxt->SelectionColor = code_rtxt->ForeColor;

		int  Size = Error(file, ptr);
		for (int i = 0; i < Size; i++)
		{
			// Set the line number you want to color
			int lineTocolor = ptr[i].LineNumber;
			string type = ptr[i].name;
			if (type == "openning Tag")
			{
				int startIndex = code_rtxt->GetFirstCharIndexFromLine(lineTocolor - 1);
				int nextLineIndex = code_rtxt->GetFirstCharIndexFromLine(lineTocolor);
				int lineLength = (nextLineIndex == -1 ? code_rtxt->Text->Length : nextLineIndex) - startIndex;

				code_rtxt->SelectionStart = startIndex;
				code_rtxt->SelectionLength = lineLength;
				code_rtxt->SelectionColor = System::Drawing::Color::Red;
			}
			else
			{
				int startIndex = code_rtxt->GetFirstCharIndexFromLine(lineTocolor - 1);
				int nextLineIndex = code_rtxt->GetFirstCharIndexFromLine(lineTocolor);
				int lineLength = (nextLineIndex == -1 ? code_rtxt->Text->Length : nextLineIndex) - startIndex;

				code_rtxt->SelectionStart = startIndex;
				code_rtxt->SelectionLength = lineLength;
				code_rtxt->SelectionColor = System::Drawing::Color::ForestGreen;
			}

		}
		if (Size == 0) {
			// Display a message box indicating no errors
			MessageBox::Show("No errors found.", "No Errors", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			// Display a message box with an indication of colors
			String^ message = "Red color indicates missing opening tags.\n\nGreen color indicates missing closing tags.";
			MessageBox::Show(message, "Tag Color Legend", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		delete[] ptr;

		code_rtxt->WordWrap = TRUE;



	}

		   /*
			* Type: Button
			* Name: pretifying_btn (Prettifying Button)
			* Event: Click
			* Description: Prettifying the  XML file
			*/

	private: System::Void prettifying_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ xmlFile = code_rtxt->Text;
		SaveToUndoStack();
		string pre = marshal_as<string>(xmlFile);  // convert String^ type to string type
		pre = prettifying(pre);                   // Prettifying XML file
		String^ PRE = marshal_as<System::String^>(pre);
		code_rtxt->Text = PRE;

	}

		   /*
			* Type: Button
			* Name: json_btn (JSON Button)
			* Event: Click
			* Description: Convert the  XML file into JSON file
			*/
	private: System::Void json_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ xmlFile = code_rtxt->Text;
		SaveToUndoStack();
		string xtj = marshal_as<string>(xmlFile);  // convert String^ type to string type
		xtj = XML_TO_JSON(xtj);                  // Converting XML file to JSON
		String^ XTJ = marshal_as<System::String^>(xtj);
		code_rtxt->Text = XTJ;

	}
		   /*
			* Type: Button
			* Name: minifying_btn (Minifying Button)
			* Event: Click
			* Description: Minifying the  XML file
			*/
	private: System::Void minifying_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ xmlFile = code_rtxt->Text;
		SaveToUndoStack();
		string mini = marshal_as<string>(xmlFile);  // convert String^ type to string type
		mini = minifying(mini);                // Minifying XML file
		String^ MINI = marshal_as<System::String^>(mini);

		code_rtxt->Text = MINI;

	}

		   /*
			* Type: Button
			* Name: compressing_btn (Compressing Button)
			* Event: Click
			* Description: Compress the file
			*/
	private: System::Void compressing_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get the XML content from the text box
		String^ xmlFile = code_rtxt->Text;

		// Save the current state to the undo stack
		SaveToUndoStack();

		// Convert String^ type to string type
		string to_be_compressed = marshal_as<string>(xmlFile);

		// Create a SaveFileDialog to choose the destination path and filename
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "Binary files (*.bin)|*.bin|All files (*.*)|*.*";
		saveFileDialog1->Title = "Save Compressed File";

		// Show the dialog and check if the user clicked OK
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// Get the chosen path and filename
			String^ compressedPath = System::IO::Path::GetDirectoryName(saveFileDialog1->FileName);
			String^ compressedFilename = System::IO::Path::GetFileNameWithoutExtension(saveFileDialog1->FileName);

			// Compress the XML content and specify the destination path and filename
			string compressed = compress(to_be_compressed);
			compressAndWriteToFile(to_be_compressed, marshal_as<string>(compressedPath), marshal_as<string>(compressedFilename));
			// Update the text box with the compressed content
			String^ COMPRESSED = marshal_as<System::String^>(compressed);
			code_rtxt->Text = COMPRESSED;
			string comp = marshal_as<string>(COMPRESSED);
			double compressionRatio = calculateCompressionRatio(to_be_compressed, comp);

			MessageBox::Show("The compression ratio is: " + compressionRatio.ToString("F3"), "Compression Ratio", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
	}


		   /*
		 * Type: Button
		 * Name: deminifying (deminifying Button)
		 * Event: Click
		 * Description: the  XML file
		 */
	private: System::Void deminifying_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ xmlFile = code_rtxt->Text;
		SaveToUndoStack();

		string demini = marshal_as<string>(xmlFile);  // convert String^ type to string type
		demini = deminifying(demini);                // Minifying XML file
		String^ DEMINI = marshal_as<System::String^>(demini);

		code_rtxt->Text = DEMINI;

	}

		   /*
			* Type: Button
			* Name: decompressing_btn (Decompressing Button)
			* Event: Click
			* Description: Decompressing the file
			*/
	private: System::Void decompressing_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		code_rtxt->Size = System::Drawing::Size(636, 608);
		String^ xmlFile = code_rtxt->Text;
		SaveToUndoStack();

		// Create an OpenFileDialog to choose the compressed file
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "Binary files (*.bin)|*.bin|All files (*.*)|*.*";
		openFileDialog1->Title = "Open Compressed File";

		// Show the dialog and check if the user clicked OK
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// Get the chosen path and filename
			String^ compressedPath = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
			String^ compressedFilename = System::IO::Path::GetFileName(openFileDialog1->FileName);

			// Decompress the file and get the decompressed content
			string decompressed = readAndDecompressFromFile(marshal_as<string>(compressedPath + "\\" + compressedFilename));

			// Display the decompressed content in the text box
			String^ DECOMPRESSED = marshal_as<System::String^>(decompressed);
			code_rtxt->Text = DECOMPRESSED;
			code_rtxt->Visible = true;

		}
	}
		   /*
			* Type: Button
			* Name: undo
			* Event: Click
			* Description: undo the latest opreation
			*/

	private: System::Void undo_Click(System::Object^ sender, System::EventArgs^ e) {
		if (undoStack != nullptr && undoStack->Count > 0) {
			// Your code here

		  // Push the current state to the redo stack
			redoStack->Push(code_rtxt->Text);

			// Pop the previous state from the undo stack
			code_rtxt->Text = undoStack->Peek();
			undoStack->Pop();
		}
	}

		   /*
			* Type: Button
			* Name: redo
			* Event: Click
			* Description: redo the latest opreation
			*/

	private: System::Void redo_Click(System::Object^ sender, System::EventArgs^ e) {

		if (redoStack != nullptr && redoStack->Count > 0) {
			// Save the current state to undo stack
			undoStack->Push(code_rtxt->Text);

			// Pop the last state from redo stack
			code_rtxt->Text = redoStack->Pop();
		}



	}

		   /*
			* Type: Button
			* Name: save
			* Event: Click
			* Description: save the xml file
			*/
	private: System::Void save_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ xmlFile = code_rtxt->Text;

		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "XML files (*.xml)|*.xml|All files (*.*)|*.*";
		saveFileDialog1->Title = "Save XML File";

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// Get the selected file name and create a StreamWriter
			String^ fileName = saveFileDialog1->FileName;

			// Write the XML string to the selected file
			System::IO::File::WriteAllText(fileName, xmlFile);

			// Optionally, you can show a message to indicate success
			MessageBox::Show("XML file is saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
		   /*
		   * Type: Button
		   * Name: button2
		   * Event: Click
		   * Description: open network analysis form
		   */
		   private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			   String^ xml = code_rtxt->Text;
			   Form2^ graphs = gcnew Form2();
			   graphs->xml_transfer = xml;  // Setting the xml_transfer property

			   graphs->Show();


			   this->WindowState = FormWindowState::Minimized;
		   }


		   /********************************************************************************
		   *                                  TextBoxs                                     *
		   *********************************************************************************/

		   /*
			* Type: Textbox
			* Name: textBox1_TextChanged (textbox where we write XML file path)
			* Event: Text Changed
			* Description: if there is text in the textbox, make code_rtxt visible
			*/
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!(textBox1->Text == "/openFileDialog1"))
		{
			this->Size = System::Drawing::Size(813, 795);
			code_rtxt->Visible = true;
		}
	}

		   /*
			* Type: Rich Textbox
			* Name: code_rtxt_TextChanged (textbox where we write XML file)
			* Event: Text Changed
			* Description: if there is text in the textbox, enable open button
			*/
	private: System::Void code_rtxt_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		Save->Enabled = !code_rtxt->Text->IsNullOrWhiteSpace(code_rtxt->Text);
		this->Size = System::Drawing::Size(813, 795);
		code_rtxt->Size = System::Drawing::Size(636, 608);

	}

	
};
}

