#pragma once
#include "WizardPages.h"
#include "AppData.h"
#include "EyeCalibration.h"

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
	private: System::Windows::Forms::TabPage^  headSelectPage;


	private: System::Windows::Forms::Label^  introTitleLabel;
	private: System::Windows::Forms::ListView^  headRigidBodyListView;

	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  selectAsHeadBtn;
	private: System::Windows::Forms::Label^  headSelectedLabel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  headSelectLabel;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(EyeCalibrationWizardForm::typeid));
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->nextBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->wizardPages = (gcnew System::Windows::Forms::TabControl());
			this->introPage = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->introTitleLabel = (gcnew System::Windows::Forms::Label());
			this->headSelectPage = (gcnew System::Windows::Forms::TabPage());
			this->headSelectedLabel = (gcnew System::Windows::Forms::Label());
			this->selectAsHeadBtn = (gcnew System::Windows::Forms::Button());
			this->headSelectLabel = (gcnew System::Windows::Forms::Label());
			this->headRigidBodyListView = (gcnew System::Windows::Forms::ListView());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->wizardPages->SuspendLayout();
			this->introPage->SuspendLayout();
			this->headSelectPage->SuspendLayout();
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
			this->wizardPages->Controls->Add(this->headSelectPage);
			this->wizardPages->Controls->Add(this->tabPage1);
			this->wizardPages->Location = System::Drawing::Point(0, 0);
			this->wizardPages->Name = L"wizardPages";
			this->wizardPages->SelectedIndex = 0;
			this->wizardPages->Size = System::Drawing::Size(537, 321);
			this->wizardPages->TabIndex = 3;
			this->wizardPages->SelectedIndexChanged += gcnew System::EventHandler(this, &EyeCalibrationWizardForm::pageChanged);
			// 
			// introPage
			// 
			this->introPage->Controls->Add(this->label1);
			this->introPage->Controls->Add(this->introTitleLabel);
			this->introPage->Location = System::Drawing::Point(4, 22);
			this->introPage->Name = L"introPage";
			this->introPage->Padding = System::Windows::Forms::Padding(3);
			this->introPage->Size = System::Drawing::Size(529, 295);
			this->introPage->TabIndex = 0;
			this->introPage->Text = L"Intro";
			this->introPage->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->label1->Location = System::Drawing::Point(6, 64);
			this->label1->MaximumSize = System::Drawing::Size(500, 250);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(495, 228);
			this->label1->TabIndex = 4;
			this->label1->Text = resources->GetString(L"label1.Text");
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
			// headSelectPage
			// 
			this->headSelectPage->Controls->Add(this->headSelectedLabel);
			this->headSelectPage->Controls->Add(this->selectAsHeadBtn);
			this->headSelectPage->Controls->Add(this->headSelectLabel);
			this->headSelectPage->Controls->Add(this->headRigidBodyListView);
			this->headSelectPage->Location = System::Drawing::Point(4, 22);
			this->headSelectPage->Name = L"headSelectPage";
			this->headSelectPage->Padding = System::Windows::Forms::Padding(3);
			this->headSelectPage->Size = System::Drawing::Size(529, 295);
			this->headSelectPage->TabIndex = 1;
			this->headSelectPage->Text = L"Head";
			this->headSelectPage->UseVisualStyleBackColor = true;
			// 
			// headSelectedLabel
			// 
			this->headSelectedLabel->AutoSize = true;
			this->headSelectedLabel->Location = System::Drawing::Point(269, 248);
			this->headSelectedLabel->Name = L"headSelectedLabel";
			this->headSelectedLabel->Size = System::Drawing::Size(203, 13);
			this->headSelectedLabel->TabIndex = 5;
			this->headSelectedLabel->Text = L"No Rigid Body is selected to be the head.";
			// 
			// selectAsHeadBtn
			// 
			this->selectAsHeadBtn->Location = System::Drawing::Point(335, 157);
			this->selectAsHeadBtn->Name = L"selectAsHeadBtn";
			this->selectAsHeadBtn->Size = System::Drawing::Size(109, 23);
			this->selectAsHeadBtn->TabIndex = 4;
			this->selectAsHeadBtn->Text = L"Select as Head";
			this->selectAsHeadBtn->UseVisualStyleBackColor = true;
			this->selectAsHeadBtn->Click += gcnew System::EventHandler(this, &EyeCalibrationWizardForm::selectAsHeadBtn_Click);
			// 
			// headSelectLabel
			// 
			this->headSelectLabel->AutoSize = true;
			this->headSelectLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->headSelectLabel->Location = System::Drawing::Point(265, 3);
			this->headSelectLabel->Name = L"headSelectLabel";
			this->headSelectLabel->Size = System::Drawing::Size(249, 133);
			this->headSelectLabel->TabIndex = 3;
			this->headSelectLabel->Text = resources->GetString(L"headSelectLabel.Text");
			// 
			// headRigidBodyListView
			// 
			this->headRigidBodyListView->Alignment = System::Windows::Forms::ListViewAlignment::Left;
			this->headRigidBodyListView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->headRigidBodyListView->FullRowSelect = true;
			this->headRigidBodyListView->LabelWrap = false;
			this->headRigidBodyListView->Location = System::Drawing::Point(0, 0);
			this->headRigidBodyListView->MultiSelect = false;
			this->headRigidBodyListView->Name = L"headRigidBodyListView";
			this->headRigidBodyListView->Size = System::Drawing::Size(245, 295);
			this->headRigidBodyListView->TabIndex = 2;
			this->headRigidBodyListView->TileSize = System::Drawing::Size(100, 20);
			this->headRigidBodyListView->UseCompatibleStateImageBehavior = false;
			this->headRigidBodyListView->View = System::Windows::Forms::View::SmallIcon;
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(529, 295);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
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
			this->Closed += gcnew System::EventHandler(this, &EyeCalibrationWizardForm::Form_Closing);
			this->Load += gcnew System::EventHandler(this, &EyeCalibrationWizardForm::Form_Load);
			this->wizardPages->ResumeLayout(false);
			this->introPage->ResumeLayout(false);
			this->introPage->PerformLayout();
			this->headSelectPage->ResumeLayout(false);
			this->headSelectPage->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
//private: WizardPages^ wizardPages;
private: EyeCalibration *eyeCalibration;
		// User Defined Functions
private: System::Void Form_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Create new Eye Calibration
			 this->eyeCalibration = new EyeCalibration();

			 /*
			 this->wizardPages = gcnew WizardPages();

			 this->wizardPages->SuspendLayout();

			 this->wizardPages->Controls->Add(this->introPage);
			 this->wizardPages->Controls->Add(this->headSelectPage);
			 this->wizardPages->Controls->Add(this->tabPage1);
			 this->wizardPages->Location = System::Drawing::Point(0, 0);
			 this->wizardPages->Name = L"wizardPages";
			 this->wizardPages->SelectedIndex = 0;
			 this->wizardPages->Size = System::Drawing::Size(537, 321);
			 this->wizardPages->TabIndex = 3;
			 this->wizardPages->SelectedIndexChanged += gcnew System::EventHandler(this, &EyeCalibrationWizardForm::pageChanged);

			 this->Controls->Add(this->wizardPages);
			 this->wizardPages->ResumeLayout(false);
			 */
			 this->headRigidBodyListView->View = View::Details;
			 this->headRigidBodyListView->Columns->Add("Id", 50, HorizontalAlignment::Left ); 
			 this->headRigidBodyListView->Columns->Add("Name", 150, HorizontalAlignment::Left ); 

			 ClientHandler* client = AppData::getInstance()->getClient();
			 if (client) {

				 std::map<int, RigidBody*>* bodyMap = client->getRigidBodyMap();

				 this->headRigidBodyListView->Items->Clear();

				 for (std::map<int, RigidBody*>::iterator it=bodyMap->begin(); it!=bodyMap->end(); ++it)
				 {
					 // Add Rigid Body to list
					 String^ rigidBodyID = Convert::ToString(it->second->getID());
					 String^ rigidBodyName = gcnew String(it->second->getName());
					 ListViewItem^ listViewItem = gcnew ListViewItem(rigidBodyID); 
					 listViewItem->SubItems->Add(rigidBodyName);
					 this->headRigidBodyListView->Items->Add(listViewItem);
				 }
			 }
		 }
private: System::Void Form_Closing( Object^ sender, System::EventArgs ^ e )
		 {
			 if (this->eyeCalibration)
				delete this->eyeCalibration;
		 }

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
private: System::Void selectAsHeadBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->headRigidBodyListView->SelectedItems->Count > 0) {
				 this->headSelectedLabel->Text = this->headRigidBodyListView->SelectedItems[0]->Text;
			 }
			 else {
				 this->headSelectedLabel->Text = "No Rigid Body is selected to be the head.";
			 } 
		 }
};
}
