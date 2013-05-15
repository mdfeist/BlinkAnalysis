#pragma once
#include "WizardPages.h"

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EyeCalibrationWizardForm
	/// </summary>
	public ref class EyeCalibrationWizardForm : public System::Windows::Forms::Form
	{
	public:
		EyeCalibrationWizardForm(void)
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
		~EyeCalibrationWizardForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  backBtn;
	protected: 
	private: System::Windows::Forms::Button^  nextBtn;
	private: System::Windows::Forms::Button^  cancelBtn;
	private: System::Windows::Forms::TabControl^ wizardPages;
	private: System::Windows::Forms::TabPage^  introPage;

	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  introTitleLabel;

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
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->nextBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->wizardPages = (gcnew System::Windows::Forms::TabControl());
			this->introPage = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->introTitleLabel = (gcnew System::Windows::Forms::Label());
			this->wizardPages->SuspendLayout();
			this->introPage->SuspendLayout();
			this->SuspendLayout();
			// 
			// backBtn
			// 
			this->backBtn->Enabled = false;
			this->backBtn->Location = System::Drawing::Point(252, 327);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(73, 23);
			this->backBtn->TabIndex = 0;
			this->backBtn->Text = L"Back";
			this->backBtn->UseVisualStyleBackColor = true;
			this->backBtn->Click += gcnew System::EventHandler(this, &EyeCalibrationWizardForm::backBtn_Click);
			// 
			// nextBtn
			// 
			this->nextBtn->Location = System::Drawing::Point(333, 327);
			this->nextBtn->Name = L"nextBtn";
			this->nextBtn->Size = System::Drawing::Size(73, 23);
			this->nextBtn->TabIndex = 1;
			this->nextBtn->Text = L"Next";
			this->nextBtn->UseVisualStyleBackColor = true;
			this->nextBtn->Click += gcnew System::EventHandler(this, &EyeCalibrationWizardForm::nextBtn_Click);
			// 
			// cancelBtn
			// 
			this->cancelBtn->Location = System::Drawing::Point(449, 327);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(73, 23);
			this->cancelBtn->TabIndex = 2;
			this->cancelBtn->Text = L"Cancel";
			this->cancelBtn->UseVisualStyleBackColor = true;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &EyeCalibrationWizardForm::cancelBtn_Click);
			// 
			// wizardPages
			// 
			this->wizardPages->Controls->Add(this->introPage);
			this->wizardPages->Controls->Add(this->tabPage2);
			this->wizardPages->Location = System::Drawing::Point(0, 0);
			this->wizardPages->Name = L"wizardPages";
			this->wizardPages->SelectedIndex = 0;
			this->wizardPages->Size = System::Drawing::Size(537, 321);
			this->wizardPages->TabIndex = 3;
			this->wizardPages->SelectedIndexChanged += gcnew System::EventHandler(this, &EyeCalibrationWizardForm::pageChanged);
			// 
			// introPage
			// 
			this->introPage->Controls->Add(this->introTitleLabel);
			this->introPage->Location = System::Drawing::Point(4, 22);
			this->introPage->Name = L"introPage";
			this->introPage->Padding = System::Windows::Forms::Padding(3);
			this->introPage->Size = System::Drawing::Size(529, 295);
			this->introPage->TabIndex = 0;
			this->introPage->Text = L"Intro";
			this->introPage->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(525, 295);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// introTitleLabel
			// 
			this->introTitleLabel->AutoSize = true;
			this->introTitleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->introTitleLabel->Location = System::Drawing::Point(8, 16);
			this->introTitleLabel->Name = L"introTitleLabel";
			this->introTitleLabel->Size = System::Drawing::Size(235, 30);
			this->introTitleLabel->TabIndex = 0;
			this->introTitleLabel->Text = L"Eye Calibration Wizard";
			// 
			// EyeCalibrationWizardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 362);
			this->Controls->Add(this->wizardPages);
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->nextBtn);
			this->Controls->Add(this->backBtn);
			this->MaximumSize = System::Drawing::Size(550, 400);
			this->MinimumSize = System::Drawing::Size(550, 400);
			this->Name = L"EyeCalibrationWizardForm";
			this->Text = L"Eye Calibration Wizard";
			this->wizardPages->ResumeLayout(false);
			this->introPage->ResumeLayout(false);
			this->introPage->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void pageChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->wizardPages->SelectedIndex == this->wizardPages->TabCount - 1)
				 this->nextBtn->Text = "Finish";
			 else
				 this->nextBtn->Text = "Next";

			 if (this->wizardPages->SelectedIndex == 0)
				 this->backBtn->Enabled = false;
			 else
				 this->backBtn->Enabled = true;
		 }
private: System::Void cancelBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void nextBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->wizardPages->SelectedIndex < this->wizardPages->TabCount - 1)
				 this->wizardPages->SelectedIndex++;
			 else if (this->wizardPages->SelectedIndex == this->wizardPages->TabCount - 1)
				 this->Close();
		 }
private: System::Void backBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->wizardPages->SelectedIndex > 0)
				 this->wizardPages->SelectedIndex--;
		 }
};
}
