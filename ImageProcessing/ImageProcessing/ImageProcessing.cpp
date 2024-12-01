#include "pch.h"
#include "stdafx.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    ImageProcessing::Filters main_form;
    Application::Run(% main_form);
    return 0;
}
