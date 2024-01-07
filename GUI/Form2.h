#pragma once
#include"enterdata.h"
#include "Suggestion.h"
#include"search.h"
#include "Graph.h"
#include "Parsing_graph.h"
#include <msclr\marshal_cppstd.h>
#include "Parsing_graph.h"
#include "visualization.h"


namespace DSProject {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{


	public:
		Form2(void)
		{
			// Initialize enter

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ output_rtx;
	private: System::Windows::Forms::Button^ Search;



	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ mutual;

	private: System::Windows::Forms::Button^ suggest;
	private: System::Windows::Forms::Button^ most_active;
	private: System::Windows::Forms::Button^ most_influ;



	private:
		System::String^ xml_file;
		SocialNetwork* graph_network;

	private: System::Windows::Forms::PictureBox^ graph;

	public:
		property System::String^ xml_transfer {
			void set(System::String^ value) {
				xml_file = value;
			}
		}
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->output_rtx = (gcnew System::Windows::Forms::RichTextBox());
			this->Search = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->mutual = (gcnew System::Windows::Forms::Button());
			this->suggest = (gcnew System::Windows::Forms::Button());
			this->most_active = (gcnew System::Windows::Forms::Button());
			this->most_influ = (gcnew System::Windows::Forms::Button());
			this->graph = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graph))->BeginInit();
			this->SuspendLayout();
			// 
			// output_rtx
			// 
			this->output_rtx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output_rtx->Location = System::Drawing::Point(12, 346);
			this->output_rtx->Name = L"output_rtx";
			this->output_rtx->Size = System::Drawing::Size(516, 259);
			this->output_rtx->TabIndex = 1;
			this->output_rtx->Text = L"";
			// 
			// Search
			// 
			this->Search->Font = (gcnew System::Drawing::Font(L"Californian FB", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Search->Location = System::Drawing::Point(669, 410);
			this->Search->Name = L"Search";
			this->Search->Size = System::Drawing::Size(120, 84);
			this->Search->TabIndex = 2;
			this->Search->Text = L"Search";
			this->Search->UseVisualStyleBackColor = true;
			this->Search->Click += gcnew System::EventHandler(this, &Form2::Search_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Californian FB", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(669, 511);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 84);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Generate graph";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// mutual
			// 
			this->mutual->Font = (gcnew System::Drawing::Font(L"Californian FB", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mutual->Location = System::Drawing::Point(669, 114);
			this->mutual->Name = L"mutual";
			this->mutual->Size = System::Drawing::Size(120, 84);
			this->mutual->TabIndex = 4;
			this->mutual->Text = L"Mutual friend";
			this->mutual->UseVisualStyleBackColor = true;
			this->mutual->Click += gcnew System::EventHandler(this, &Form2::mutual_Click);
			// 
			// suggest
			// 
			this->suggest->Font = (gcnew System::Drawing::Font(L"Californian FB", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suggest->Location = System::Drawing::Point(669, 12);
			this->suggest->Name = L"suggest";
			this->suggest->Size = System::Drawing::Size(120, 84);
			this->suggest->TabIndex = 5;
			this->suggest->Text = L"Suggest friends";
			this->suggest->UseVisualStyleBackColor = true;
			this->suggest->Click += gcnew System::EventHandler(this, &Form2::sugget_Click);
			// 
			// most_active
			// 
			this->most_active->Font = (gcnew System::Drawing::Font(L"Californian FB", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->most_active->Location = System::Drawing::Point(669, 213);
			this->most_active->Name = L"most_active";
			this->most_active->Size = System::Drawing::Size(120, 84);
			this->most_active->TabIndex = 6;
			this->most_active->Text = L"Most active user";
			this->most_active->UseVisualStyleBackColor = true;
			this->most_active->Click += gcnew System::EventHandler(this, &Form2::most_active_Click);
			// 
			// most_influ
			// 
			this->most_influ->Font = (gcnew System::Drawing::Font(L"Californian FB", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->most_influ->Location = System::Drawing::Point(669, 320);
			this->most_influ->Name = L"most_influ";
			this->most_influ->Size = System::Drawing::Size(120, 84);
			this->most_influ->TabIndex = 7;
			this->most_influ->Text = L"Most influencer user";
			this->most_influ->UseVisualStyleBackColor = true;
			this->most_influ->Click += gcnew System::EventHandler(this, &Form2::most_influ_Click);
			// 
			// graph
			// 
			this->graph->Location = System::Drawing::Point(23, 30);
			this->graph->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->graph->Name = L"graph";
			this->graph->Size = System::Drawing::Size(609, 301);
			this->graph->TabIndex = 9;
			this->graph->TabStop = false;
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(801, 617);
			this->Controls->Add(this->graph);
			this->Controls->Add(this->most_influ);
			this->Controls->Add(this->most_active);
			this->Controls->Add(this->suggest);
			this->Controls->Add(this->mutual);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->Search);
			this->Controls->Add(this->output_rtx);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form2";
			this->Text = L"Network analysis";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graph))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		/********************************************************************************
		*                                 Form Window                                   *
		*********************************************************************************/

		private: System::Void Form2_Load(System::Object^ sender, System::EventArgs^ e) {
			output_rtx->Text = "";
			String^ network_string = xml_file;
			string NETWORK = marshal_as<string>(network_string);


			static SocialNetwork network;
			graph_network = &network;
			ParsingXml(NETWORK, graph_network);
			string network_str = graph_network->getAllUsersDataAsString();
			String^ NET = marshal_as < String^ >(network_str);

			output_rtx->Text = NET;

		}

		/********************************************************************************
		*                                    Buttons                                    *
		*********************************************************************************/
		   /*
			* Type: Button
			* Name: mutual 
			* Event: Click
			* Description:Get mutual friends
			*/
	private: System::Void mutual_Click(System::Object^ sender, System::EventArgs^ e) {

		enterdata^ enter1 = gcnew enterdata();
		enter1->ShowDialog();

		int user_1 = enter1->Input_1;

		int user_2 = enter1->Input_2;

		if (user_1 > 0 && user_2 > 0)
		{


			string mutual = graph_network->getMutualFollowers(graph_network->users[user_1 - ID_Converter], graph_network->users[user_2 - ID_Converter]);

			String^ MUTUAL = marshal_as < String^ >(mutual);

			output_rtx->Text = MUTUAL;
		}
	}

		   /*
		    * Type: Button
			* Name: suggest
			* Event: Click
			* Description: suggest friends
			*/

	private: System::Void sugget_Click(System::Object^ sender, System::EventArgs^ e) {

		Suggestion^ suggest1 = gcnew Suggestion();
		suggest1->ShowDialog();
		int user_id = suggest1->Input;
		if (user_id > 0)
		{


			string suggested = graph_network->users[user_id - ID_Converter]->getUserSuggestion();

			String^ SUGGESTED = marshal_as < String^ >(suggested);

			output_rtx->Text = SUGGESTED;
		}
	}
		   /*
			* Type: Button
			* Name: most_active
			* Event: Click
			* Description: shows most active user
			*/

	private: System::Void most_active_Click(System::Object^ sender, System::EventArgs^ e) {

		string most_active = graph_network->getUserWithMostFollowings()->getUserDataAsString();

		String^ MOST_ACTIVE = marshal_as < String^ >(most_active);
		output_rtx->Text = MOST_ACTIVE;

	}
		   /*
		    * Type: Button
		    * Name: search
		    * Event: Click
		    * Description: search for posts by word
		    */
	private: System::Void Search_Click(System::Object^ sender, System::EventArgs^ e) {

		search^ search1 = gcnew search();
		search1->ShowDialog();
		String^ serach_word = search1->serach_wordt;

		if (!String::IsNullOrEmpty(serach_word))
		{
			string SEARCH = marshal_as<string>(serach_word);
			string post = graph_network->searchByKeyword(SEARCH);

			String^ POST = marshal_as < String^ >(post);
			output_rtx->Text = POST;
		}
		else
		{
			MessageBox::Show("Please enter a word.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
		/*
	     * Type: Button
	     * Name: button2
	     * Event: Click
	     * Description: generate graph for network
	     */
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		vector<User*> users = graph_network->getUsersAsVector();
		generateDOTFile(users);
		String^ imagePath = "Graph.png";

		// Check if the file exists
		if (System::IO::File::Exists(imagePath))
		{
			// Load the image
			Image^ image = Image::FromFile(imagePath);
			graph->Image = image;
		}
		else
		{
			// Display an error message if the file is not found
			MessageBox::Show("Image file is not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	   /*
		* Type: Button
		* Name: most_influ
		* Event: Click
		* Description: get most influencer user
		*/
	private: System::Void most_influ_Click(System::Object^ sender, System::EventArgs^ e) {

		string most_influ = graph_network->getUserWithMostFollowers()->getUserDataAsString();

		String^ MOST_INFLU = marshal_as < String^ >(most_influ);
		output_rtx->Text = MOST_INFLU;

	}
	
};
}
