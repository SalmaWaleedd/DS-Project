#pragma once

namespace DSProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for Suggestion
	/// </summary>
	public ref class Suggestion : public System::Windows::Forms::Form
	{
	private:
		int user;

	public:
		Suggestion(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		property int Input {
			int get() {
				return user;
			}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Suggestion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ submit;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Suggestion::typeid));
			this->submit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// submit
			// 
			this->submit->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->submit->Location = System::Drawing::Point(117, 124);
			this->submit->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->submit->Name = L"submit";
			this->submit->Size = System::Drawing::Size(108, 30);
			this->submit->TabIndex = 0;
			this->submit->Text = L"Submit";
			this->submit->UseVisualStyleBackColor = true;
			this->submit->Click += gcnew System::EventHandler(this, &Suggestion::submit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(25, 43);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Enter user ID";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(29, 63);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(153, 22);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Suggestion::textBox1_TextChanged);
			// 
			// Suggestion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(241, 169);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->submit);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Suggestion";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Suggest friends";
			this->Load += gcnew System::EventHandler(this, &Suggestion::Suggestion_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void submit_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ userId = textBox1->Text;

		// Validate the data (for example, check if it's not empty and contains only integers)
		if (String::IsNullOrEmpty(userId)) {
			MessageBox::Show("Please enter a user ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			int parsedUserId;
			if (int::TryParse(userId, parsedUserId)) {
				// Data is valid, and userId is a valid integer
				// You can proceed with hiding the form or any other action
				user = parsedUserId;
				this->Hide();
				// Do something with the parsedUserId variable if needed
			}
			else {
				// Show an error message if the entered text is not a valid integer
				MessageBox::Show("Please enter a valid numeric user ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		textBox1->Clear();

	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	
private: System::Void Suggestion_Load(System::Object^ sender, System::EventArgs^ e) {
}
};

}
