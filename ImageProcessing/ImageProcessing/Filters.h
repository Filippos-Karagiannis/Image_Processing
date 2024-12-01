#pragma once
#include <iostream>
#include <vector>
#include <sstream>

namespace ImageProcessing {

    using namespace std;
    using namespace System::IO;
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for Filters
    /// </summary>

    enum class onLoad
    {
        Blur3, Blur5, Blur7, Details, Sharpened, NONE
    };

    onLoad onload = onLoad::NONE;

    enum class Preset
    {
        Gauss3, Gauss5, Box7, Detailed3, Detailed5, Detailed7, Sharpened3, Sharpened5, Sharpened7, Greyscale, Inverted, Sobel, Laplace, Erosion, Dilation, Median, NONE
    };

    Preset filter = Preset::NONE;

    vector<Preset> filters;

    vector<float>blurConvo0 =
    { 1 / 16.f,2 / 16.f,1 / 16.f,
      2 / 16.f,4 / 16.f,2 / 16.f,
      1 / 16.f,2 / 16.f,1 / 16.f };

    vector<float>blurConvo1 =
    { 1 / 256.f, 4 / 256.f, 6 / 256.f, 4 / 256.f, 1 / 256.f,
      4 / 256.f, 16 / 256.f, 24 / 256.f, 16 / 256.f, 4 / 256.f,
      6 / 256.f, 24 / 256.f, 36 / 256.f, 24 / 256.f, 6 / 256.f,
      4 / 256.f, 16 / 256.f, 24 / 256.f, 16 / 256.f, 4 / 256.f,
      1 / 256.f, 4 / 256.f, 6 / 256.f, 4 / 256.f, 1 / 256.f, };

    vector<float>blurConvo2 =
    { 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f,
      1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f,
      1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f,
      1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f,
      1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f,
      1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f,
      1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f, 1 / 49.f };

    public ref class Filters : public System::Windows::Forms::Form
    {
    public:
        Filters(void)
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
        ~Filters()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::PictureBox^ pictureBox2;
    private: System::Windows::Forms::MenuStrip^ menuStrip1;
    private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ openFileToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ saveFileToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::ProgressBar^ progressBar1;
    private: System::Windows::Forms::RadioButton^ radioButton1;
    private: System::Windows::Forms::RadioButton^ radioButton2;
    private: System::Windows::Forms::RadioButton^ radioButton3;
    private: System::Windows::Forms::RichTextBox^ richTextBox1;
    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;
        String^ pseudo = "";
        String^ copyPseudo = "";
    private: System::Windows::Forms::Button^ LoadPreset;
    private: System::Windows::Forms::Button^ SavePreset;
           bool^ copySelected = false;
           Image^ im;

#pragma region Windows Form Designer generated code
           /// <summary>
           /// Required method for Designer support - do not modify
           /// the contents of this method with the code editor.
           /// </summary>
           void InitializeComponent(void)
           {
               this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
               this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
               this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
               this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->openFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->saveFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
               this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
               this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
               this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
               this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
               this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
               this->LoadPreset = (gcnew System::Windows::Forms::Button());
               this->SavePreset = (gcnew System::Windows::Forms::Button());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
               this->menuStrip1->SuspendLayout();
               this->SuspendLayout();
               // 
               // pictureBox1
               // 
               this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLight;
               this->pictureBox1->Location = System::Drawing::Point(12, 79);
               this->pictureBox1->Name = L"pictureBox1";
               this->pictureBox1->Size = System::Drawing::Size(427, 404);
               this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
               this->pictureBox1->TabIndex = 0;
               this->pictureBox1->TabStop = false;
               this->pictureBox1->Click += gcnew System::EventHandler(this, &Filters::pictureBox1_Click);
               // 
               // pictureBox2
               // 
               this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlLight;
               this->pictureBox2->Location = System::Drawing::Point(628, 79);
               this->pictureBox2->Name = L"pictureBox2";
               this->pictureBox2->Size = System::Drawing::Size(427, 404);
               this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
               this->pictureBox2->TabIndex = 1;
               this->pictureBox2->TabStop = false;
               this->pictureBox2->Click += gcnew System::EventHandler(this, &Filters::pictureBox2_Click);
               // 
               // menuStrip1
               // 
               this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
               this->menuStrip1->Location = System::Drawing::Point(0, 0);
               this->menuStrip1->Name = L"menuStrip1";
               this->menuStrip1->Size = System::Drawing::Size(1067, 24);
               this->menuStrip1->TabIndex = 2;
               this->menuStrip1->Text = L"menuStrip1";
               // 
               // fileToolStripMenuItem
               // 
               this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
                   this->openFileToolStripMenuItem,
                       this->saveFileToolStripMenuItem, this->exitToolStripMenuItem
               });
               this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
               this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
               this->fileToolStripMenuItem->Text = L"File";
               // 
               // openFileToolStripMenuItem
               // 
               this->openFileToolStripMenuItem->Name = L"openFileToolStripMenuItem";
               this->openFileToolStripMenuItem->Size = System::Drawing::Size(124, 22);
               this->openFileToolStripMenuItem->Text = L"Open File";
               this->openFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Filters::openFileToolStripMenuItem_Click);
               // 
               // saveFileToolStripMenuItem
               // 
               this->saveFileToolStripMenuItem->Name = L"saveFileToolStripMenuItem";
               this->saveFileToolStripMenuItem->Size = System::Drawing::Size(124, 22);
               this->saveFileToolStripMenuItem->Text = L"Save File";
               this->saveFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Filters::saveFileToolStripMenuItem_Click);
               // 
               // exitToolStripMenuItem
               // 
               this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
               this->exitToolStripMenuItem->Size = System::Drawing::Size(124, 22);
               this->exitToolStripMenuItem->Text = L"Exit";
               this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Filters::exitToolStripMenuItem_Click);
               // 
               // button1
               // 
               this->button1->Enabled = false;
               this->button1->Location = System::Drawing::Point(12, 498);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(75, 23);
               this->button1->TabIndex = 3;
               this->button1->Text = L"copy";
               this->button1->UseVisualStyleBackColor = true;
               this->button1->Click += gcnew System::EventHandler(this, &Filters::button1_Click);
               // 
               // comboBox1
               // 
               this->comboBox1->Enabled = false;
               this->comboBox1->FormattingEnabled = true;
               this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
                   L"Blur", L"Details", L"Sharpened", L"Grayscale",
                       L"Inverted", L"Sobel", L"Laplace", L"Erosion", L"Dilation", L"Median"
               });
               this->comboBox1->Location = System::Drawing::Point(473, 105);
               this->comboBox1->Name = L"comboBox1";
               this->comboBox1->Size = System::Drawing::Size(121, 21);
               this->comboBox1->TabIndex = 4;
               this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Filters::comboBox1_SelectedIndexChanged);
               // 
               // progressBar1
               // 
               this->progressBar1->Location = System::Drawing::Point(628, 489);
               this->progressBar1->Name = L"progressBar1";
               this->progressBar1->Size = System::Drawing::Size(427, 23);
               this->progressBar1->TabIndex = 5;
               this->progressBar1->Visible = false;
               this->progressBar1->Click += gcnew System::EventHandler(this, &Filters::progressBar1_Click);
               // 
               // radioButton1
               // 
               this->radioButton1->AutoSize = true;
               this->radioButton1->Enabled = false;
               this->radioButton1->Location = System::Drawing::Point(491, 165);
               this->radioButton1->Name = L"radioButton1";
               this->radioButton1->Size = System::Drawing::Size(95, 17);
               this->radioButton1->TabIndex = 6;
               this->radioButton1->TabStop = true;
               this->radioButton1->Text = L"Gaussian 3 x 3";
               this->radioButton1->UseVisualStyleBackColor = true;
               this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Filters::radioButton1_CheckedChanged);
               // 
               // radioButton2
               // 
               this->radioButton2->AutoSize = true;
               this->radioButton2->Enabled = false;
               this->radioButton2->Location = System::Drawing::Point(491, 188);
               this->radioButton2->Name = L"radioButton2";
               this->radioButton2->Size = System::Drawing::Size(95, 17);
               this->radioButton2->TabIndex = 7;
               this->radioButton2->TabStop = true;
               this->radioButton2->Text = L"Gaussian 5 x 5";
               this->radioButton2->UseVisualStyleBackColor = true;
               this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Filters::radioButton2_CheckedChanged);
               // 
               // radioButton3
               // 
               this->radioButton3->AutoSize = true;
               this->radioButton3->Enabled = false;
               this->radioButton3->Location = System::Drawing::Point(491, 211);
               this->radioButton3->Name = L"radioButton3";
               this->radioButton3->Size = System::Drawing::Size(93, 17);
               this->radioButton3->TabIndex = 8;
               this->radioButton3->TabStop = true;
               this->radioButton3->Text = L"Box Blur  7 x 7";
               this->radioButton3->UseVisualStyleBackColor = true;
               this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Filters::radioButton3_CheckedChanged);
               // 
               // richTextBox1
               // 
               this->richTextBox1->BackColor = System::Drawing::SystemColors::MenuText;
               this->richTextBox1->Enabled = false;
               this->richTextBox1->ForeColor = Color::FromArgb(51, 255, 51);
               this->richTextBox1->Location = System::Drawing::Point(445, 244);
               this->richTextBox1->Name = L"richTextBox1";
               this->richTextBox1->ReadOnly = true;
               this->richTextBox1->Size = System::Drawing::Size(177, 239);
               this->richTextBox1->TabIndex = 9;
               this->richTextBox1->Text = L"";
               this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Filters::richTextBox1_TextChanged);
               // 
               // LoadPreset
               // 
               this->LoadPreset->Location = System::Drawing::Point(445, 498);
               this->LoadPreset->Name = L"LoadPreset";
               this->LoadPreset->Size = System::Drawing::Size(75, 23);
               this->LoadPreset->TabIndex = 10;
               this->LoadPreset->Text = L"Load Preset";
               this->LoadPreset->UseVisualStyleBackColor = true;
               this->LoadPreset->Click += gcnew System::EventHandler(this, &Filters::LoadPreset_Click);
               this->LoadPreset->Enabled = false;
               // 
               // SavePreset
               // 
               this->SavePreset->Location = System::Drawing::Point(547, 498);
               this->SavePreset->Name = L"SavePreset";
               this->SavePreset->Size = System::Drawing::Size(75, 23);
               this->SavePreset->TabIndex = 11;
               this->SavePreset->Text = L"Save Preset";
               this->SavePreset->UseVisualStyleBackColor = true;
               this->SavePreset->Click += gcnew System::EventHandler(this, &Filters::SavePreset_Click);
               this->SavePreset->Enabled = false;
               // 
               // Filters
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(1067, 648);
               this->Controls->Add(this->SavePreset);
               this->Controls->Add(this->LoadPreset);
               this->Controls->Add(this->richTextBox1);
               this->Controls->Add(this->radioButton3);
               this->Controls->Add(this->radioButton2);
               this->Controls->Add(this->radioButton1);
               this->Controls->Add(this->progressBar1);
               this->Controls->Add(this->comboBox1);
               this->Controls->Add(this->button1);
               this->Controls->Add(this->pictureBox2);
               this->Controls->Add(this->pictureBox1);
               this->Controls->Add(this->menuStrip1);
               this->MainMenuStrip = this->menuStrip1;
               this->Name = L"Filters";
               this->Text = L"Filters";
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
               this->menuStrip1->ResumeLayout(false);
               this->menuStrip1->PerformLayout();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

           System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
           {
               if (comboBox1->SelectedIndex == 0 || comboBox1->SelectedIndex == 1 || comboBox1->SelectedIndex == 2)
               {
                   radioButton1->Enabled = true;
                   radioButton2->Enabled = true;
                   radioButton3->Enabled = true;
               }

               if (comboBox1->SelectedIndex == 3)
                   grayscale(pictureBox1->Image, 'f');
               if (comboBox1->SelectedIndex == 4)
                   inverted(pictureBox1->Image);
               if (comboBox1->SelectedIndex == 5)
                   grayscale(pictureBox1->Image, 's');
               if (comboBox1->SelectedIndex == 6)
                   grayscale(pictureBox1->Image, 'l');
               if (comboBox1->SelectedIndex == 7)
                   grayscale(pictureBox1->Image, 'e');
               if (comboBox1->SelectedIndex == 8)
                   grayscale(pictureBox1->Image, 'd');
               if (comboBox1->SelectedIndex == 9)
                   median(pictureBox1->Image);
           }

           void blur(Image^ img, vector<float>& blurConvo)
           {
               button1->Enabled = true;

               size_t kernelSize = blurConvo.size();
               double kernelRow = Math::Sqrt(kernelSize);

               Bitmap^ image = gcnew Bitmap(img);
               Bitmap^ blur = gcnew Bitmap(image->Width - (kernelRow / 2) * 2, image->Height - (kernelRow / 2) * 2);

               progressBar1->Visible = true;
               progressBar1->Minimum = 1;
               progressBar1->Step = 1;

               if (comboBox1->SelectedIndex == 1 || onload == onLoad::Details)
                   progressBar1->Maximum = (image->Width * image->Height) * 2;
               else if (comboBox1->SelectedIndex == 2 || onload == onLoad::Sharpened)
                   progressBar1->Maximum = (image->Width * image->Height) * 3;
               else
                   progressBar1->Maximum = image->Width * image->Height;

               float red, green, blue;

               for (int i = kernelRow / 2; i < blur->Width - kernelRow / 2; i++)
               {
                   for (int j = kernelRow / 2; j < blur->Height - kernelRow / 2; j++)
                   {
                       red = green = blue = 0;
                       for (int h = 0; h < kernelRow; h++)
                       {
                           for (int w = 0; w < kernelRow; w++)
                           {
                               red += image->GetPixel(i + w - (kernelRow / 2), j + h - (kernelRow / 2)).R * blurConvo[w + h * kernelRow];
                               green += image->GetPixel(i + w - (kernelRow / 2), j + h - (kernelRow / 2)).G * blurConvo[w + h * kernelRow];
                               blue += image->GetPixel(i + w - (kernelRow / 2), j + h - (kernelRow / 2)).B * blurConvo[w + h * kernelRow];
                           }
                       }

                       blur->SetPixel(i, j, Color::FromArgb(red, green, blue));
                       progressBar1->PerformStep();
                   }
               }


               if (comboBox1->SelectedIndex == 0 || onload == onLoad::Blur3 || onload == onLoad::Blur5 || onload == onLoad::Blur7)
               {
                   if (radioButton1->Checked)
                   {
                       richTextBox1->Text += "Gaussian Blur 3x3\n";
                       filter = Preset::Gauss3;
                   }
                   if (radioButton2->Checked)
                   {
                       richTextBox1->Text += "Gaussian Blur 5x5\n";
                       filter = Preset::Gauss5;
                   }
                   if (radioButton3->Checked)
                   {
                       richTextBox1->Text += "Box Blur 7x7\n";
                       filter = Preset::Box7;
                   }
                   pictureBox2->Image = blur;
                   pseudoCode(1);
               }
               if (comboBox1->SelectedIndex == 1 || onload == onLoad::Details)
                   details(blur, kernelSize, false);
               if (comboBox1->SelectedIndex == 2 || onload == onLoad::Sharpened)
                   details(blur, kernelSize, true);

               refresh();
           } // blur

           void details(Bitmap^ blur, size_t kernelSize, bool sharp)
           {
               button1->Enabled = true;

               double kernelRow = Math::Sqrt(kernelSize);

               Byte red, green, blue;
               Bitmap^ normal = gcnew Bitmap(im);
               Bitmap^ detailed = gcnew Bitmap(blur->Width, blur->Height);

               progressBar1->Visible = true;
               progressBar1->Minimum = 1;
               progressBar1->Step = 1;

               for (int i = kernelRow / 2; i < blur->Width - kernelRow / 2; i++)
               {
                   for (int j = kernelRow / 2; j < blur->Height - kernelRow / 2; j++)
                   {
                       red = Math::Abs(normal->GetPixel(i, j).R - blur->GetPixel(i, j).R);
                       green = Math::Abs(normal->GetPixel(i, j).G - blur->GetPixel(i, j).G);
                       blue = Math::Abs(normal->GetPixel(i, j).B - blur->GetPixel(i, j).B);

                       detailed->SetPixel(i, j, Color::FromArgb(red, green, blue));
                       progressBar1->PerformStep();
                   }
               }

               if (sharp)
                   sharpened(detailed, kernelSize);
               else
               {
                   if (radioButton1->Checked)
                   {
                       richTextBox1->Text += "Details with Gaussian Blur 3x3\n";
                       filter = Preset::Detailed3;
                   }
                   if (radioButton2->Checked)
                   {
                       richTextBox1->Text += "Details with Gaussian Blur 5x5\n";
                       filter = Preset::Detailed5;
                   }
                   if (radioButton3->Checked)
                   {
                       richTextBox1->Text += "Details with Box Blur 7x7\n";
                       filter = Preset::Detailed7;
                   }
                   pictureBox2->Image = detailed;
                   pseudoCode(2);
               }
               refresh();
           }

           void sharpened(Bitmap^ detailed, size_t kernelSize)
           {
               button1->Enabled = true;

               double kernelRow = Math::Sqrt(kernelSize);

               int red, green, blue;
               Bitmap^ normal = gcnew Bitmap(im);
               Bitmap^ sharp = gcnew Bitmap(detailed->Width, detailed->Height);

               progressBar1->Visible = true;
               progressBar1->Minimum = 1;
               progressBar1->Step = 1;

               for (int i = kernelRow / 2; i < detailed->Width - kernelRow / 2; i++)
               {
                   for (int j = kernelRow / 2; j < detailed->Height - kernelRow / 2; j++)
                   {
                       red = (normal->GetPixel(i, j).R + detailed->GetPixel(i, j).R);
                       green = (normal->GetPixel(i, j).G + detailed->GetPixel(i, j).G);
                       blue = (normal->GetPixel(i, j).B + detailed->GetPixel(i, j).B);

                       if (red > 255) red = 255;
                       if (green > 255) green = 255;
                       if (blue > 255) blue = 255;

                       sharp->SetPixel(i, j, Color::FromArgb(red, green, blue));
                       progressBar1->PerformStep();
                   }
               }


               if (radioButton1->Checked)
               {
                   richTextBox1->Text += "Sharpened with Gaussian Blur 3x3\n";
                   filter = Preset::Sharpened3;
               }
               if (radioButton2->Checked)
               {
                   richTextBox1->Text += "Sharpened with Gaussian Blur 5x5\n";
                   filter = Preset::Sharpened5;
               }
               if (radioButton3->Checked)
               {
                   richTextBox1->Text += "Sharpened with Box Blur 7x7\n";
                   filter = Preset::Sharpened7;
               }

               pictureBox2->Image = sharp;
               pseudoCode(3);
               refresh();
           }

           void grayscale(Image^ img, char flag)
           {
               button1->Enabled = true;

               Bitmap^ image = gcnew Bitmap(img);
               Byte average;

               radioButtonsOff();
               progressBar1->Visible = true;
               progressBar1->Minimum = 1;
               progressBar1->Step = 1;

               if (comboBox1->SelectedIndex == 3)
                   progressBar1->Maximum = image->Width * image->Height;
               else
                   progressBar1->Maximum = (image->Width * image->Height) * 2;

               for (int i = 0; i < image->Width; i++)
               {
                   for (int j = 0; j < image->Height; j++)
                   {
                       average = image->GetPixel(i, j).R * 0.2126 + image->GetPixel(i, j).G * 0.7152 + image->GetPixel(i, j).B * 0.0722;
                       image->SetPixel(i, j, Color::FromArgb(average, average, average));
                       progressBar1->PerformStep();
                   }
               }


               if (flag == 's')
                   sobel(image);
               else if (flag == 'l')
                   laplace(image);
               else if (flag == 'e')
                   erosion(image);
               else if (flag == 'd')
                   dilation(image);
               else
               {
                   richTextBox1->Text += "Greyscale\n";
                   filter = Preset::Greyscale;
                   pictureBox2->Image = image;
                   pseudoCode(4);
               }
               refresh();
           }

           void inverted(Image^ img)
           {
               button1->Enabled = true;

               Bitmap^ image = gcnew Bitmap(img);
               Byte red, green, blue;

               radioButtonsOff();
               progressBar1->Visible = true;
               progressBar1->Minimum = 1;
               progressBar1->Step = 1;
               progressBar1->Maximum = image->Width * image->Height;


               for (int i = 0; i < image->Width; i++)
               {
                   for (int j = 0; j < image->Height; j++)
                   {
                       red = 255 - image->GetPixel(i, j).R;
                       green = 255 - image->GetPixel(i, j).G;
                       blue = 255 - image->GetPixel(i, j).B;

                       image->SetPixel(i, j, Color::FromArgb(red, green, blue));
                       progressBar1->PerformStep();
                   }
               }

               richTextBox1->Text += "Inverted\n";
               filter = Preset::Inverted;
               pictureBox2->Image = image;
               pseudoCode(5);
               refresh();
           }

           void sobel(Image^ img)
           {
               button1->Enabled = true;

               Bitmap^ image = gcnew Bitmap(img);
               Bitmap^ sobelImage = gcnew Bitmap(image->Width, image->Height);

               radioButtonsOff();
               progressBar1->Visible = true;

               int colorGx, colorGy;
               float gradient;
               for (int i = 1; i < image->Width - 1; i++)
               {
                   for (int j = 1; j < image->Height - 1; j++)
                   {
                       colorGx = (image->GetPixel(i - 1, j - 1).R + 2 * image->GetPixel(i, j - 1).R + image->GetPixel(i + 1, j - 1).R)
                           - (image->GetPixel(i - 1, j + 1).R + 2 * image->GetPixel(i, j + 1).R + image->GetPixel(i + 1, j + 1).R);

                       colorGy = (image->GetPixel(i - 1, j - 1).R + 2 * image->GetPixel(i - 1, j).R + image->GetPixel(i - 1, j + 1).R)
                           - (image->GetPixel(i + 1, j - 1).R + 2 * image->GetPixel(i + 1, j).R + image->GetPixel(i + 1, j + 1).R);

                       gradient = Math::Sqrt((colorGx * colorGx) + (colorGy * colorGy));


                       if (gradient <= 128) gradient = 0;
                       if (gradient > 128) gradient = 255;

                       sobelImage->SetPixel(i, j, Color::FromArgb(gradient, gradient, gradient));
                       progressBar1->PerformStep();
                   }
               }


               richTextBox1->Text += "Sobel\n";
               filter = Preset::Sobel;
               pictureBox2->Image = sobelImage;
               pseudoCode(6);
               refresh();
           }

           void laplace(Image^ img)
           {
               button1->Enabled = true;

               Bitmap^ image = gcnew Bitmap(img);
               Bitmap^ laplaceImage = gcnew Bitmap(img->Width, img->Height);

               radioButtonsOff();
               progressBar1->Visible = true;

               int color;

               for (int i = 1; i < laplaceImage->Width - 1; i++)
               {
                   for (int j = 1; j < laplaceImage->Height - 1; j++)
                   {
                       color = (image->GetPixel(i, j - 1).R * (-1.0)) + (image->GetPixel(i - 1, j).R * (-1.0))
                           + (image->GetPixel(i, j).R * 4.0) + (image->GetPixel(i + 1, j).R * (-1.0)) + (image->GetPixel(i, j + 1).R * (-1.0));


                       if (color < 0) color = 0;
                       if (color > 255) color = 255;

                       laplaceImage->SetPixel(i, j, Color::FromArgb(color, color, color));
                       progressBar1->PerformStep();
                   }
               }

               richTextBox1->Text += "Laplace\n";
               filter = Preset::Laplace;
               pictureBox2->Image = laplaceImage;
               pseudoCode(7);
               refresh();
           }

           void erosion(Image^ img)
           {
               button1->Enabled = true;

               Bitmap^ image = gcnew Bitmap(img);
               Bitmap^ binaryImg = toBinary(image);

               radioButtonsOff();
               progressBar1->Visible = true;

               Bitmap^ eroded = gcnew Bitmap(image->Width, image->Height);

               int sum = 0;
               for (int i = 1; i < image->Width - 1; i++)
               {
                   for (int j = 1; j < image->Height - 1; j++)
                   {
                       for (int h = 0; h < 3; h++)
                       {
                           for (int w = 0; w < 3; w++)
                           {
                               sum += binaryImg->GetPixel(i + w - 1, j + h - 1).R;
                           }
                       }

                       for (int h = 0; h < 3; h++)
                       {
                           for (int w = 0; w < 3; w++)
                           {
                               if (sum < 2295)
                                   eroded->SetPixel(i + w - 1, j + h - 1, Color::FromArgb(0, 0, 0));
                               else
                                   eroded->SetPixel(i + w - 1, j + h - 1, Color::FromArgb(255, 255, 255));
                           }
                       }
                       progressBar1->PerformStep();
                       sum = 0;
                   }
               }


               richTextBox1->Text += "Erosion\n";
               filter = Preset::Erosion;
               pictureBox2->Image = eroded;
               pseudoCode(8);
               refresh();
           }

           void dilation(Image^ img)
           {
               button1->Enabled = true;

               Bitmap^ image = gcnew Bitmap(img);
               Bitmap^ binaryImg = toBinary(image);
               Bitmap^ dilated = gcnew Bitmap(image->Width, image->Height);

               radioButtonsOff();
               progressBar1->Visible = true;

               int sum = 0;
               for (int i = 1; i < image->Width - 1; i++)
               {
                   for (int j = 1; j < image->Height - 1; j++)
                   {
                       for (int h = 0; h < 3; h++)
                       {
                           for (int w = 0; w < 3; w++)
                           {
                               sum += binaryImg->GetPixel(i + w - 1, j + h - 1).R;
                           }
                       }

                       if (sum == 0)
                           dilated->SetPixel(i, j, Color::FromArgb(0, 0, 0));
                       else
                       {
                           for (int h = 0; h < 3; h++)
                           {
                               for (int w = 0; w < 3; w++)
                               {
                                   dilated->SetPixel(i + w - 1, j + h - 1, Color::FromArgb(255, 255, 255));
                               }
                           }
                       }
                       progressBar1->PerformStep();
                       sum = 0;
                   }
               }


               richTextBox1->Text += "Dilation\n";
               filter = Preset::Dilation;
               pictureBox2->Image = dilated;
               pseudoCode(9);
               refresh();
           }

           Bitmap^ toBinary(Bitmap^ img)
           {
               Bitmap^ image = gcnew Bitmap(img);

               Byte pixel;
               for (int i = 0; i < image->Width; i++)
               {
                   for (int j = 0; j < image->Height; j++)
                   {
                       if (image->GetPixel(i, j).R >= 128)
                           image->SetPixel(i, j, Color::FromArgb(255, 255, 255));
                       else
                           image->SetPixel(i, j, Color::FromArgb(0, 0, 0));
                   }
               }

               return image;
           }

           void median(Image^ img)
           {
               button1->Enabled = true;

               Bitmap^ image = gcnew Bitmap(img);
               Bitmap^ medianImg = gcnew Bitmap(image->Width, image->Height);

               radioButtonsOff();
               progressBar1->Visible = true;
               progressBar1->Minimum = 1;
               progressBar1->Step = 1;
               progressBar1->Maximum = image->Width * image->Height;

               int kernelSize = 3 * 3;
               int kernelRow = Math::Sqrt(kernelSize);

               int red, green, blue;
               for (int i = kernelRow / 2; i < image->Width - kernelRow / 2; i++)
               {
                   for (int j = kernelRow / 2; j < image->Height - kernelRow / 2; j++)
                   {
                       red = green = blue = 0;
                       for (int h = 0; h < kernelRow; h++)
                       {
                           for (int w = 0; w < kernelRow; w++)
                           {
                               if (h == kernelRow / 2 && w == kernelRow / 2) continue;
                               red += image->GetPixel(i + w - (kernelRow / 2), j + h - (kernelRow / 2)).R;
                               green += image->GetPixel(i + w - (kernelRow / 2), j + h - (kernelRow / 2)).G;
                               blue += image->GetPixel(i + w - (kernelRow / 2), j + h - (kernelRow / 2)).B;
                           }
                       }

                       medianImg->SetPixel(i, j, Color::FromArgb(red / (kernelSize - 1), green / (kernelSize - 1), blue / (kernelSize - 1)));
                       progressBar1->PerformStep();
                   }
               }

               richTextBox1->Text += "Median\n";
               filter = Preset::Median;
               pictureBox2->Image = medianImg;
               pseudoCode(10);
               refresh();
           }

           void refresh()
           {
               button1->Enabled = (pictureBox2->Image != nullptr);
               SavePreset->Enabled = (richTextBox1->Text != "");
               progressBar1->Visible = false;
               progressBar1->Value = 1;

               radioButton1->Checked = false;
               radioButton2->Checked = false;
               radioButton3->Checked = false;
           }

           System::Void openFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
           {
               System::IO::Stream^ myStream;
               OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
               openFileDialog1->Filter = "Image files (*.jpg, *.jpeg, *.jpe, *.jfif, *.png) | *.jpg; *.jpeg; *.jpe; *.jfif; *.png";


               if (openFileDialog1->ShowDialog() == ImageProcessing::DialogResult::OK)
               {
                   if (pictureBox2->Image != nullptr)
                       pictureBox2->Image = nullptr;
                   if ((myStream = openFileDialog1->OpenFile()) != nullptr)
                   {

                       pictureBox1->Image = gcnew Bitmap(openFileDialog1->FileName);
                       comboBox1->Enabled = true;
                       richTextBox1->Enabled = true;
                       LoadPreset->Enabled = true;
                       im = pictureBox1->Image;
                   }

                   if (pictureBox2->Image == nullptr) button1->Enabled = false;
                   richTextBox1->Text = "";
               }
           }

           System::Void saveFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
           {
               SaveFileDialog^ sfd = gcnew SaveFileDialog();
               sfd->Filter = "Image files (*.jpg, *.jpeg, *.jpe, *.jfif, *.png) | *.jpg; *.jpeg; *.jpe; *.jfif; *.png";

               if (pictureBox2->Image != nullptr)
               {
                   if (sfd->ShowDialog() == ImageProcessing::DialogResult::OK)
                   {
                       System::IO::Stream^ path = sfd->OpenFile();
                       pictureBox2->Image->Save(path, System::Drawing::Imaging::ImageFormat::Jpeg);

                       StreamWriter^ text = gcnew StreamWriter("pseudocode.txt");

                       if (!copySelected)
                           text->WriteLine(pseudo);
                       else
                           text->WriteLine(copyPseudo + pseudo);
                       text->Close();

                   }
               }
           }

           System::Void SavePreset_Click(System::Object^ sender, System::EventArgs^ e)
           {
               SaveFileDialog^ sfd = gcnew SaveFileDialog();
               sfd->Filter = "Text documents (.txt)|*.txt";

               if (richTextBox1->Text != "")
               {
                   StreamWriter^ presets = gcnew StreamWriter("Preset.txt");
                   String^ temp = "";
                   if (filters.size() > 0 && filters[filters.size() - 1] != filter)
                       filters.push_back(filter);
                   else if (filters.size() == 0 && filter != Preset::NONE)
                       filters.push_back(filter);

                   for (auto& c : filters)
                   {
                       switch (c)
                       {
                       case Preset::Gauss3:		temp += "0\n"; break;
                       case Preset::Gauss5:		temp += "1\n"; break;
                       case Preset::Box7:			temp += "2\n"; break;
                       case Preset::Detailed3:		temp += "3\n"; break;
                       case Preset::Detailed5:		temp += "4\n"; break;
                       case Preset::Detailed7:		temp += "5\n"; break;
                       case Preset::Sharpened3:	temp += "6\n"; break;
                       case Preset::Sharpened5:	temp += "7\n"; break;
                       case Preset::Sharpened7:	temp += "8\n"; break;
                       case Preset::Greyscale:		temp += "9\n"; break;
                       case Preset::Inverted:		temp += "10\n"; break;
                       case Preset::Sobel:			temp += "11\n"; break;
                       case Preset::Laplace:		temp += "12\n"; break;
                       case Preset::Erosion:		temp += "13\n"; break;
                       case Preset::Dilation:		temp += "14\n"; break;
                       case Preset::Median:		temp += "15\n"; break;
                       default:;
                           break;
                       }
                   }

                   presets->WriteLine(temp);
                   presets->Close();
               }
           }

           System::Void LoadPreset_Click(System::Object^ sender, System::EventArgs^ e)
           {
               StreamReader^ myStream = gcnew StreamReader("Preset.txt");
               String^ line;
               line = myStream->ReadLine();

               while (line != "")
               {
                   switch (Convert::ToInt16(line))
                   {
                   case 0:
                   {
                       onload = onLoad::Blur3;
                       blur(im, blurConvo0);
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 1:
                   {
                       onload = onLoad::Blur5;
                       blur(im, blurConvo1);
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 2:
                   {
                       onload = onLoad::Blur7;
                       blur(im, blurConvo2);
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 3:
                   {
                       onload = onLoad::Details;
                       blur(im, blurConvo0);
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 4:
                   {
                       onload = onLoad::Details;
                       blur(im, blurConvo1);
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 5:
                   {
                       onload = onLoad::Details;
                       blur(im, blurConvo2);
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 6:
                   {
                       onload = onLoad::Sharpened;
                       blur(im, blurConvo0);
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 7:
                   {
                       onload = onLoad::Sharpened;
                       blur(im, blurConvo1);
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 8:
                   {
                       onload = onLoad::Sharpened;
                       blur(im, blurConvo2);
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 9:
                   {
                       onload = onLoad::NONE;
                       grayscale(im, 'f');
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 10:
                   {
                       onload = onLoad::NONE;
                       inverted(im);
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 11:
                   {
                       onload = onLoad::NONE;
                       grayscale(im, 's');
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 12:
                   {
                       onload = onLoad::NONE;
                       grayscale(im, 'l');
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 13:
                   {
                       onload = onLoad::NONE;
                       grayscale(im, 'e');
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 14:
                   {
                       onload = onLoad::NONE;
                       grayscale(im, 'd');
                       im = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   case 15:
                   {
                       onload = onLoad::NONE;
                       median(pictureBox1->Image);
                       pictureBox1->Image = pictureBox2->Image;
                       line = myStream->ReadLine();
                       break;
                   }
                   default:;
                       break;
                   }
               }
               richTextBox1->Text = "";
           }

           System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
           {
               Close();
           }

           System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
           {
               pictureBox1->Image = pictureBox2->Image;
               im = pictureBox2->Image;
               copyPseudo += pseudo;
               pseudo = "";
               button1->Enabled = false;
               richTextBox1->Text += "Copy Button\n";
               filters.push_back(filter);
               filter = Preset::NONE;
           }


           System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
           {
               if (radioButton1->Checked)
                   blur(pictureBox1->Image, blurConvo0);
           }

           System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
           {
               if (radioButton2->Checked)
                   blur(pictureBox1->Image, blurConvo1);
           }

           System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
           {
               if (radioButton3->Checked)
                   blur(pictureBox1->Image, blurConvo2);
           }

           void radioButtonsOff()
           {
               radioButton1->Enabled = false;
               radioButton2->Enabled = false;
               radioButton3->Enabled = false;
           }


           //1 = blur, 2 = details, 3 = sharpened, 4 = greyscale, 5 = inverted, 6 = sobel, 7 = laplace, 8 = erosion, 9 = dilation, 10 = median
           void pseudoCode(int flag)
           {
               switch (flag)
               {
               case 1:
               {
                   pseudo = "";
                   pseudo += "Iterate through the image\nfor(i = sqrt(kernelArray.size()) / 2; i < image->Width - sqrt(kernelArray.size()) / 2; i++)\n\n" +
                       "{\n\tfor (j = sqrt(kernelArray.size()) / 2; j < image->Height - sqrt(kernelArray.size()) / 2; j++)\n" +
                       "\t{\n\t\tSum each color for every pixel of the kernel\n\t\tred = green = blue = 0;\n\t\tfor(h = 0; h < sqrt(kernelArray.size()); h++)\n" +
                       "\t\t{\n\t\t\tfor(w = 0; w < sqrt(kernelArray.size()); w++)\n\t\t\t{\n\t\t\t\tred += ...;\n\t\t\t\tgreen += ...;\n\t\t\t\tblue += ...;\n\t\t\t}\n\t\t}\n\tSet color of i,j with red,gree,blue\n\t}\n}\n\n";
                   break;
               }
               case 2:
               {
                   pseudo = "";
                   pseudo += "Iterate through the image\nfor(i = sqrt(kernelArray.size()) / 2; i < image->Width - sqrt(kernelArray.size()) / 2; i++)\n\n" +
                       "{\n\tfor (j = sqrt(kernelArray.size()) / 2; j < image->Height - sqrt(kernelArray.size()) / 2; j++)\n" +
                       "\t{\n\t\tSum each color for every pixel of the kernel\n\t\tred = green = blue = 0;\n\t\tfor(h = 0; h < sqrt(kernelArray.size()); h++)\n" +
                       "\t\t{\n\t\t\tfor(w = 0; w < sqrt(kernelArray.size()); w++)\n\t\t\t{\n\t\t\t\tred += ...;\n\t\t\t\tgreen += ...;\n\t\t\t\tblue += ...;\n\t\t\t}\n\t\t}\n\tSet color of i,j with red,gree,blue\n\t}\n}\n\n";

                   pseudo += "Iterate through image\nfor(...;...;i++)\n{\n\tfor(...;...;j++)\n\t{\n\t\tred = abs(primaryImage_Pixel - blurredImage_Pixel);\n\t\tgreen = ...;\n\t\tblue = ...;\n\t\tSetPixel color for i,j\n\t}\n}\n\n";
                   break;
               }
               case 3:
               {
                   pseudo = "";
                   pseudo += "Iterate through the image\nfor(i = sqrt(kernelArray.size()) / 2; i < image->Width - sqrt(kernelArray.size()) / 2; i++)\n" +
                       "{\n\tfor (j = sqrt(kernelArray.size()) / 2; j < image->Height - sqrt(kernelArray.size()) / 2; j++)\n" +
                       "\t{\n\t\tSum each color for every pixel of the kernel\n\t\tred = green = blue = 0;\n\t\tfor(h = 0; h < sqrt(kernelArray.size()); h++)\n" +
                       "\t\t{\n\t\t\tfor(w = 0; w < sqrt(kernelArray.size()); w++)\n\t\t\t{\n\t\t\t\tred += ...;\n\t\t\t\tgreen += ...;\n\t\t\t\tblue += ...;\n\t\t\t}\n\t\t}\n\tSet color of i,j with red,gree,blue\n\t}\n}\n\n";

                   pseudo += "Iterate through image\nfor(...;...;i++)\n{\n\tfor(...;...;j++)\n\t{\n\t\tred = abs(primaryImage_Pixel - blurredImage_Pixel);\n\t\tgreen = ...;\n\t\tblue = ...;\n\t\tSetPixel color for i,j\n\t}\n}\n\n";

                   pseudo += "Iterate through image\nfor(...;...;i++)\n{\n\tfor(...;...;j++)\n\t{\n\t\tred = primaryImage_Pixel + detailedImage_Pixel;\n\t\tgreen = ...;\n\t\tblue = ...;\n\t\tCheck if colors are more than 255\n\t\tSetPixel color for i,j\n\t}\n}\n\n";
                   break;
               }
               case 4:
               {
                   pseudo = "";
                   pseudo += "Iterate through image\nfor(...;...;i++)\n{\n\tfor(...;...;j++)\n\t{\n\t\tFind the average of all three colors\n\t\tSetPixel color for i,j\n\t}\n}\n\n";
                   break;
               }
               case 5:
               {
                   pseudo = "";
                   pseudo += "Iterate through image\nfor(...;...;i++)\n{\n\tfor(...;...;j++)\n\t{\n\t\tred = 255 - primaryImage_Pixel;\n\t\tgreen = ...;\n\t\tblue = ...;\n\t\tSetPixel color for i,j\n\t}\n}\n\n";
                   break;
               }
               case 6:
               {
                   pseudo = "";
                   pseudo += "Iterate through image\nfor(...;...;i++)\n{\n\tfor(...;...;j++)\n\t{\n\t\tFind the average of all three colors\n\t\tSetPixel color for i,j\n\t}\n}\n\n";
                   pseudo += "Iterate through image\nfor(...;...;i++)\n{\n\tfor(...;...;j++)\n\t{\n\t\tFind the horizontal and vertical value with the respective kernel\n\t\tgradient = magnitude of horizontal and vertical\n\t\tDo thresholding\n\t\tSetPixel for i,j\n\t}\n}\n\n";
                   break;
               }
               case 7:
               {
                   pseudo = "";
                   pseudo += "Iterate through image\nfor(...;...;i++)\n{\n\tfor(...;...;j++)\n\t{\n\t\tFind the average of all three colors\n\t\tSetPixel color for i,j\n\t}\n}\n\n";
                   pseudo += "Iterate through image\nfor(...;...;i++)\n{\n\tfor(...;...;j++)\n\t{\n\t\tFind color value with Laplace's kernel\n\t\tCheck if values are less than 0 or greater than 255\n\t\tSetPixel for i,j\n\t}\n}\n\n";
                   break;
               }
               case 8:
               {
                   pseudo = "";
                   pseudo += "Iterate through image\nfor(...;...;i++)\n{\n\tfor(...;...;j++)\n\t{\n\t\tFind the average of all three colors\n\t\tSetPixel color for i,j\n\t}\n}\n\n";

                   pseudo += "Iterate through the image\nfor(...;...; i++)\n{\n\tfor (...;...; j++)\n\t{\n\t\tfor(h = 0; h < 3; h++)\n\t\t{\n" +
                       "\t\t\tfor(w = 0; w < 3; w++)\n\t\t\t{\n\t\t\t\tsum += binaryImage_Pixel;\n\t\t\t}\n\t\t}" +
                       "\n\n\t\tfor(h = 0; h < 3; h++)\n\t\t{\n\t\t\tfor(w = 0; w < 3; w++)\n\t\t\t{\n" +
                       "\t\t\t\tif sum < 255 * 9 color the pixel black else keep the pixel white\n\t\t\t}\n\t\t}\n\t}\n}\n\n";
                   break;
               }
               case 9:
               {
                   pseudo = "";
                   pseudo += "Iterate through image\nfor(...;...;i++)\n{\n\tfor(...;...;j++)\n\t{\n\t\tFind the average of all three colors\n\t\tSetPixel color for i,j\n\t}\n}\n\n";

                   pseudo += "Make the image binary, if the color is more than 128 make it white otherwise black\nIterate through the image\nfor(...;...; i++)\n" +
                       "{\n\tfor (...;...; j++)\n" +
                       "\t{\n\t\tfor(h = 0; h < 3; h++)\n" +
                       "\t\t{\n\t\t\tfor(w = 0; w < 3; w++)\n\t\t\t{\n\t\t\t\tsum each pixel of the kernel;\n\t\t\t}" +
                       "\n\t\t}\n\t\tif sum equals 0, set the pixel to 0 else iterate through each pixel of the kernel and turn it black\n\t\tsum = 0;\n\t}\n}\n\n";
                   break;
               }
               case 10:
               {
                   pseudo = "";
                   pseudo += "Iterate through the image\nfor(...;...; i++)\n" +
                       "{\n\tfor (...;...; j++)\n" +
                       "\t{\n\t\tred = green = blue = 0;\n\t\tfor(h = 0; h < sqrt(kernelArray.size()); h++)\n" +
                       "\t\t{\n\t\t\tfor(w = 0; w < sqrt(kernelArray.size()); w++)\n\t\t\t{\n\t\t\t\tif (the current pixel is the center of the kernel) continue;\n\t\t\t\tred += ...;\n\t\t\t\tgreen += ...;\n\t\t\t\tblue += ...;\n\t\t\t}\n\t\t}\n\tSet color of i,j with red,gree,blue each divided by the kernelSize - 1\n\t}\n}\n\n";
                   break;
               }
               default:
                   break;
               }
           }

           System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
           {
           }

           System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
           {
           }

           System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e)
           {
           }

           System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e)
           {
           }

    };
}
