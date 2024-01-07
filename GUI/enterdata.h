#pragma once

namespace DSProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for enterdata
	/// </summary>
	public ref class enterdata : public System::Windows::Forms::Form
	{
	private:
		int input_1;
		int input_2;

	public:
		enterdata(void)
		{
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
		}
		property int Input_1 {
			int get() {
				return input_1;
			}
		}

		property int Input_2 {
			int get() {
				return input_2;
			}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~enterdata()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(enterdata::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 116);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(236, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &enterdata::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(156, 176);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &enterdata::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 52);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(236, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &enterdata::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AllowDrop = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label1->Location = System::Drawing::Point(12, 97);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Enter second User ID";
			// 
			// label2
			// 
			this->label2->AllowDrop = true;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label2->Location = System::Drawing::Point(12, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Enter first User ID";
			// 
			// enterdata
			// 
			this->AcceptButton = this->button1;
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(260, 211);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"enterdata";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Enter users ID";
			this->Load += gcnew System::EventHandler(this, &enterdata::enterdata_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}






#pragma endregion
	private: System::Void enterdata_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	

	String^ userId1 = textBox2->Text;
	String^ userId2 = textBox1->Text;

	if (String::IsNullOrEmpty(userId1) || String::IsNullOrEmpty(userId2)) {
		MessageBox::Show("Please enter both user IDs.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		int parsedUserId1, parsedUserId2;
		if (int::TryParse(userId1, parsedUserId1) && int::TryParse(userId2, parsedUserId2)) {
			input_1 = parsedUserId1;
			input_2 = parsedUserId2;

			this->Hide();
		}
		else {
			// Show an error message if any entered text is not a valid integer
			MessageBox::Show("Please enter valid numeric user IDs.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	// Remove the remaining text from the textboxes
	textBox1->Clear();
	textBox2->Clear();
}
};
}
