#include "MyForm.h"



using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace std;

[STAThread]

/*
   kan fy paramters bttbasa ly main function wa ana ms7tha
*/


void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DSProject::MyForm form;
	Application::Run(% form);
	
}



