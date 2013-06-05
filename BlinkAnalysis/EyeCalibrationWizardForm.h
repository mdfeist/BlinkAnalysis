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
	private: System::Windows::Forms::TabPage^  objectSelectPage;



	private: System::Windows::Forms::Button^  selectAsHeadBtn;
	private: System::Windows::Forms::Label^  headSelectedLabel;
	private: System::Windows::Forms::Label^  eyeCalibrationInstructionsLabel;

	private: System::Windows::Forms::Label^  headSelectLabel;
	private: System::Windows::Forms::Label^  selectedObjectLabel;
	private: System::Windows::Forms::Button^  selectAsObjectBtn;
	private: System::Windows::Forms::Label^  objectSelectionInstructionsLabel;

	private: System::Windows::Forms::ListView^  objectRigidBodyListView;
	private: System::Windows::Forms::TabPage^  calibrationPage;
	private: System::Windows::Forms::Button^  addCalibrationPointBtn;

	private: System::Windows::Forms::Label^  calibrationPointInstructionsLabel;
	private: System::Windows::Forms::Label^  calibrationExampleLabel;
	private: Microsoft::VisualBasic::PowerPacks::ShapeContainer^  shapeContainer1;
	private: Microsoft::VisualBasic::PowerPacks::OvalShape^  demoCalibrationPoint7;
	private: Microsoft::VisualBasic::PowerPacks::OvalShape^  demoCalibrationPoint8;
	private: Microsoft::VisualBasic::PowerPacks::OvalShape^  demoCalibrationPoint9;
	private: Microsoft::VisualBasic::PowerPacks::OvalShape^  demoCalibrationPoint6;
	private: Microsoft::VisualBasic::PowerPacks::OvalShape^  demoCalibrationPoint5;
	private: Microsoft::VisualBasic::PowerPacks::OvalShape^  demoCalibrationPoint4;
	private: Microsoft::VisualBasic::PowerPacks::OvalShape^  demoCalibrationPoint2;
	private: Microsoft::VisualBasic::PowerPacks::OvalShape^  demoCalibrationPoint3;
	private: Microsoft::VisualBasic::PowerPacks::OvalShape^  demoCalibrationPoint1;
	private: Microsoft::VisualBasic::PowerPacks::RectangleShape^  screenShape;
	private: System::Windows::Forms::TabPage^  calculatingPage;
	private: System::Windows::Forms::TextBox^  calibrationOutputLogLabel;




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
			this->eyeCalibrationInstructionsLabel = (gcnew System::Windows::Forms::Label());
			this->introTitleLabel = (gcnew System::Windows::Forms::Label());
			this->headSelectPage = (gcnew System::Windows::Forms::TabPage());
			this->headSelectedLabel = (gcnew System::Windows::Forms::Label());
			this->selectAsHeadBtn = (gcnew System::Windows::Forms::Button());
			this->headSelectLabel = (gcnew System::Windows::Forms::Label());
			this->headRigidBodyListView = (gcnew System::Windows::Forms::ListView());
			this->objectSelectPage = (gcnew System::Windows::Forms::TabPage());
			this->selectedObjectLabel = (gcnew System::Windows::Forms::Label());
			this->selectAsObjectBtn = (gcnew System::Windows::Forms::Button());
			this->objectSelectionInstructionsLabel = (gcnew System::Windows::Forms::Label());
			this->objectRigidBodyListView = (gcnew System::Windows::Forms::ListView());
			this->calibrationPage = (gcnew System::Windows::Forms::TabPage());
			this->calibrationExampleLabel = (gcnew System::Windows::Forms::Label());
			this->addCalibrationPointBtn = (gcnew System::Windows::Forms::Button());
			this->calibrationPointInstructionsLabel = (gcnew System::Windows::Forms::Label());
			this->shapeContainer1 = (gcnew Microsoft::VisualBasic::PowerPacks::ShapeContainer());
			this->demoCalibrationPoint7 = (gcnew Microsoft::VisualBasic::PowerPacks::OvalShape());
			this->demoCalibrationPoint8 = (gcnew Microsoft::VisualBasic::PowerPacks::OvalShape());
			this->demoCalibrationPoint9 = (gcnew Microsoft::VisualBasic::PowerPacks::OvalShape());
			this->demoCalibrationPoint6 = (gcnew Microsoft::VisualBasic::PowerPacks::OvalShape());
			this->demoCalibrationPoint5 = (gcnew Microsoft::VisualBasic::PowerPacks::OvalShape());
			this->demoCalibrationPoint4 = (gcnew Microsoft::VisualBasic::PowerPacks::OvalShape());
			this->demoCalibrationPoint2 = (gcnew Microsoft::VisualBasic::PowerPacks::OvalShape());
			this->demoCalibrationPoint3 = (gcnew Microsoft::VisualBasic::PowerPacks::OvalShape());
			this->demoCalibrationPoint1 = (gcnew Microsoft::VisualBasic::PowerPacks::OvalShape());
			this->screenShape = (gcnew Microsoft::VisualBasic::PowerPacks::RectangleShape());
			this->calculatingPage = (gcnew System::Windows::Forms::TabPage());
			this->calibrationOutputLogLabel = (gcnew System::Windows::Forms::TextBox());
			this->wizardPages->SuspendLayout();
			this->introPage->SuspendLayout();
			this->headSelectPage->SuspendLayout();
			this->objectSelectPage->SuspendLayout();
			this->calibrationPage->SuspendLayout();
			this->calculatingPage->SuspendLayout();
			this->SuspendLayout();
			// 
			// backBtn
			// 
			this->backBtn->Enabled = false;
			this->backBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
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
			this->nextBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
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
			this->cancelBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
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
			this->wizardPages->Controls->Add(this->objectSelectPage);
			this->wizardPages->Controls->Add(this->calibrationPage);
			this->wizardPages->Controls->Add(this->calculatingPage);
			this->wizardPages->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->wizardPages->Location = System::Drawing::Point(0, 0);
			this->wizardPages->Name = L"wizardPages";
			this->wizardPages->SelectedIndex = 0;
			this->wizardPages->Size = System::Drawing::Size(537, 321);
			this->wizardPages->TabIndex = 3;
			this->wizardPages->SelectedIndexChanged += gcnew System::EventHandler(this, &EyeCalibrationWizardForm::pageChanged);
			// 
			// introPage
			// 
			this->introPage->Controls->Add(this->eyeCalibrationInstructionsLabel);
			this->introPage->Controls->Add(this->introTitleLabel);
			this->introPage->Location = System::Drawing::Point(4, 22);
			this->introPage->Name = L"introPage";
			this->introPage->Padding = System::Windows::Forms::Padding(3);
			this->introPage->Size = System::Drawing::Size(529, 295);
			this->introPage->TabIndex = 0;
			this->introPage->Text = L"Intro";
			this->introPage->UseVisualStyleBackColor = true;
			// 
			// eyeCalibrationInstructionsLabel
			// 
			this->eyeCalibrationInstructionsLabel->AutoSize = true;
			this->eyeCalibrationInstructionsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->eyeCalibrationInstructionsLabel->Location = System::Drawing::Point(6, 64);
			this->eyeCalibrationInstructionsLabel->MaximumSize = System::Drawing::Size(500, 250);
			this->eyeCalibrationInstructionsLabel->Name = L"eyeCalibrationInstructionsLabel";
			this->eyeCalibrationInstructionsLabel->Size = System::Drawing::Size(495, 228);
			this->eyeCalibrationInstructionsLabel->TabIndex = 4;
			this->eyeCalibrationInstructionsLabel->Text = resources->GetString(L"eyeCalibrationInstructionsLabel.Text");
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
			this->headSelectedLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->headSelectedLabel->Location = System::Drawing::Point(266, 248);
			this->headSelectedLabel->MaximumSize = System::Drawing::Size(250, 60);
			this->headSelectedLabel->Name = L"headSelectedLabel";
			this->headSelectedLabel->Size = System::Drawing::Size(219, 34);
			this->headSelectedLabel->TabIndex = 5;
			this->headSelectedLabel->Text = L"No Rigid Body is selected to be the head.";
			// 
			// selectAsHeadBtn
			// 
			this->selectAsHeadBtn->Location = System::Drawing::Point(335, 200);
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
			// objectSelectPage
			// 
			this->objectSelectPage->Controls->Add(this->selectedObjectLabel);
			this->objectSelectPage->Controls->Add(this->selectAsObjectBtn);
			this->objectSelectPage->Controls->Add(this->objectSelectionInstructionsLabel);
			this->objectSelectPage->Controls->Add(this->objectRigidBodyListView);
			this->objectSelectPage->Location = System::Drawing::Point(4, 22);
			this->objectSelectPage->Name = L"objectSelectPage";
			this->objectSelectPage->Padding = System::Windows::Forms::Padding(3);
			this->objectSelectPage->Size = System::Drawing::Size(529, 295);
			this->objectSelectPage->TabIndex = 2;
			this->objectSelectPage->Text = L"Object";
			this->objectSelectPage->UseVisualStyleBackColor = true;
			// 
			// selectedObjectLabel
			// 
			this->selectedObjectLabel->AutoSize = true;
			this->selectedObjectLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->selectedObjectLabel->Location = System::Drawing::Point(266, 248);
			this->selectedObjectLabel->MaximumSize = System::Drawing::Size(250, 60);
			this->selectedObjectLabel->Name = L"selectedObjectLabel";
			this->selectedObjectLabel->Size = System::Drawing::Size(219, 34);
			this->selectedObjectLabel->TabIndex = 9;
			this->selectedObjectLabel->Text = L"No Rigid Body is selected to be the viewing object.";
			// 
			// selectAsObjectBtn
			// 
			this->selectAsObjectBtn->Location = System::Drawing::Point(335, 200);
			this->selectAsObjectBtn->Name = L"selectAsObjectBtn";
			this->selectAsObjectBtn->Size = System::Drawing::Size(109, 23);
			this->selectAsObjectBtn->TabIndex = 8;
			this->selectAsObjectBtn->Text = L"Select as Object";
			this->selectAsObjectBtn->UseVisualStyleBackColor = true;
			this->selectAsObjectBtn->Click += gcnew System::EventHandler(this, &EyeCalibrationWizardForm::selectAsObjectBtn_Click);
			// 
			// objectSelectionInstructionsLabel
			// 
			this->objectSelectionInstructionsLabel->AutoSize = true;
			this->objectSelectionInstructionsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->objectSelectionInstructionsLabel->Location = System::Drawing::Point(265, 3);
			this->objectSelectionInstructionsLabel->MaximumSize = System::Drawing::Size(250, 300);
			this->objectSelectionInstructionsLabel->Name = L"objectSelectionInstructionsLabel";
			this->objectSelectionInstructionsLabel->Size = System::Drawing::Size(249, 171);
			this->objectSelectionInstructionsLabel->TabIndex = 7;
			this->objectSelectionInstructionsLabel->Text = resources->GetString(L"objectSelectionInstructionsLabel.Text");
			// 
			// objectRigidBodyListView
			// 
			this->objectRigidBodyListView->Alignment = System::Windows::Forms::ListViewAlignment::Left;
			this->objectRigidBodyListView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->objectRigidBodyListView->FullRowSelect = true;
			this->objectRigidBodyListView->LabelWrap = false;
			this->objectRigidBodyListView->Location = System::Drawing::Point(0, 0);
			this->objectRigidBodyListView->MultiSelect = false;
			this->objectRigidBodyListView->Name = L"objectRigidBodyListView";
			this->objectRigidBodyListView->Size = System::Drawing::Size(245, 295);
			this->objectRigidBodyListView->TabIndex = 6;
			this->objectRigidBodyListView->TileSize = System::Drawing::Size(100, 20);
			this->objectRigidBodyListView->UseCompatibleStateImageBehavior = false;
			this->objectRigidBodyListView->View = System::Windows::Forms::View::SmallIcon;
			// 
			// calibrationPage
			// 
			this->calibrationPage->Controls->Add(this->calibrationExampleLabel);
			this->calibrationPage->Controls->Add(this->addCalibrationPointBtn);
			this->calibrationPage->Controls->Add(this->calibrationPointInstructionsLabel);
			this->calibrationPage->Controls->Add(this->shapeContainer1);
			this->calibrationPage->Location = System::Drawing::Point(4, 22);
			this->calibrationPage->Name = L"calibrationPage";
			this->calibrationPage->Padding = System::Windows::Forms::Padding(3);
			this->calibrationPage->Size = System::Drawing::Size(529, 295);
			this->calibrationPage->TabIndex = 3;
			this->calibrationPage->Text = L"Calibration";
			this->calibrationPage->UseVisualStyleBackColor = true;
			// 
			// calibrationExampleLabel
			// 
			this->calibrationExampleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->calibrationExampleLabel->Location = System::Drawing::Point(14, 190);
			this->calibrationExampleLabel->Name = L"calibrationExampleLabel";
			this->calibrationExampleLabel->Size = System::Drawing::Size(143, 102);
			this->calibrationExampleLabel->TabIndex = 12;
			this->calibrationExampleLabel->Text = L"For best calibration results try to follow the pattern to the left.";
			// 
			// addCalibrationPointBtn
			// 
			this->addCalibrationPointBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->addCalibrationPointBtn->Location = System::Drawing::Point(379, 231);
			this->addCalibrationPointBtn->Name = L"addCalibrationPointBtn";
			this->addCalibrationPointBtn->Size = System::Drawing::Size(109, 23);
			this->addCalibrationPointBtn->TabIndex = 10;
			this->addCalibrationPointBtn->Text = L"Add Point";
			this->addCalibrationPointBtn->UseVisualStyleBackColor = true;
			this->addCalibrationPointBtn->Click += gcnew System::EventHandler(this, &EyeCalibrationWizardForm::addCalibrationPointBtn_Click);
			// 
			// calibrationPointInstructionsLabel
			// 
			this->calibrationPointInstructionsLabel->AutoSize = true;
			this->calibrationPointInstructionsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->calibrationPointInstructionsLabel->Location = System::Drawing::Point(13, 7);
			this->calibrationPointInstructionsLabel->MaximumSize = System::Drawing::Size(500, 300);
			this->calibrationPointInstructionsLabel->Name = L"calibrationPointInstructionsLabel";
			this->calibrationPointInstructionsLabel->Size = System::Drawing::Size(491, 171);
			this->calibrationPointInstructionsLabel->TabIndex = 9;
			this->calibrationPointInstructionsLabel->Text = resources->GetString(L"calibrationPointInstructionsLabel.Text");
			// 
			// shapeContainer1
			// 
			this->shapeContainer1->Location = System::Drawing::Point(3, 3);
			this->shapeContainer1->Margin = System::Windows::Forms::Padding(0);
			this->shapeContainer1->Name = L"shapeContainer1";
			this->shapeContainer1->Shapes->AddRange(gcnew cli::array< Microsoft::VisualBasic::PowerPacks::Shape^  >(10) {this->demoCalibrationPoint7, 
				this->demoCalibrationPoint8, this->demoCalibrationPoint9, this->demoCalibrationPoint6, this->demoCalibrationPoint5, this->demoCalibrationPoint4, 
				this->demoCalibrationPoint2, this->demoCalibrationPoint3, this->demoCalibrationPoint1, this->screenShape});
			this->shapeContainer1->Size = System::Drawing::Size(523, 289);
			this->shapeContainer1->TabIndex = 11;
			this->shapeContainer1->TabStop = false;
			// 
			// demoCalibrationPoint7
			// 
			this->demoCalibrationPoint7->Location = System::Drawing::Point(167, 262);
			this->demoCalibrationPoint7->Name = L"demoCalibrationPoint7";
			this->demoCalibrationPoint7->Size = System::Drawing::Size(20, 20);
			// 
			// demoCalibrationPoint8
			// 
			this->demoCalibrationPoint8->Location = System::Drawing::Point(238, 262);
			this->demoCalibrationPoint8->Name = L"demoCalibrationPoint8";
			this->demoCalibrationPoint8->Size = System::Drawing::Size(20, 20);
			// 
			// demoCalibrationPoint9
			// 
			this->demoCalibrationPoint9->Location = System::Drawing::Point(310, 262);
			this->demoCalibrationPoint9->Name = L"demoCalibrationPoint9";
			this->demoCalibrationPoint9->Size = System::Drawing::Size(20, 20);
			// 
			// demoCalibrationPoint6
			// 
			this->demoCalibrationPoint6->Location = System::Drawing::Point(310, 228);
			this->demoCalibrationPoint6->Name = L"demoCalibrationPoint6";
			this->demoCalibrationPoint6->Size = System::Drawing::Size(20, 20);
			// 
			// demoCalibrationPoint5
			// 
			this->demoCalibrationPoint5->Location = System::Drawing::Point(238, 228);
			this->demoCalibrationPoint5->Name = L"demoCalibrationPoint5";
			this->demoCalibrationPoint5->Size = System::Drawing::Size(20, 20);
			// 
			// demoCalibrationPoint4
			// 
			this->demoCalibrationPoint4->Location = System::Drawing::Point(167, 228);
			this->demoCalibrationPoint4->Name = L"demoCalibrationPoint4";
			this->demoCalibrationPoint4->Size = System::Drawing::Size(20, 20);
			// 
			// demoCalibrationPoint2
			// 
			this->demoCalibrationPoint2->Location = System::Drawing::Point(238, 191);
			this->demoCalibrationPoint2->Name = L"demoCalibrationPoint2";
			this->demoCalibrationPoint2->Size = System::Drawing::Size(20, 20);
			// 
			// demoCalibrationPoint3
			// 
			this->demoCalibrationPoint3->Location = System::Drawing::Point(310, 191);
			this->demoCalibrationPoint3->Name = L"demoCalibrationPoint3";
			this->demoCalibrationPoint3->Size = System::Drawing::Size(20, 20);
			// 
			// demoCalibrationPoint1
			// 
			this->demoCalibrationPoint1->Location = System::Drawing::Point(167, 191);
			this->demoCalibrationPoint1->Name = L"demoCalibrationPoint1";
			this->demoCalibrationPoint1->Size = System::Drawing::Size(20, 20);
			// 
			// screenShape
			// 
			this->screenShape->Location = System::Drawing::Point(156, 187);
			this->screenShape->Name = L"screenShape";
			this->screenShape->Size = System::Drawing::Size(183, 100);
			// 
			// calculatingPage
			// 
			this->calculatingPage->Controls->Add(this->calibrationOutputLogLabel);
			this->calculatingPage->Location = System::Drawing::Point(4, 22);
			this->calculatingPage->Name = L"calculatingPage";
			this->calculatingPage->Padding = System::Windows::Forms::Padding(3);
			this->calculatingPage->Size = System::Drawing::Size(529, 295);
			this->calculatingPage->TabIndex = 4;
			this->calculatingPage->Text = L"Calculating";
			this->calculatingPage->UseVisualStyleBackColor = true;
			// 
			// calibrationOutputLogLabel
			// 
			this->calibrationOutputLogLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->calibrationOutputLogLabel->Location = System::Drawing::Point(3, 3);
			this->calibrationOutputLogLabel->Multiline = true;
			this->calibrationOutputLogLabel->Name = L"calibrationOutputLogLabel";
			this->calibrationOutputLogLabel->ReadOnly = true;
			this->calibrationOutputLogLabel->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->calibrationOutputLogLabel->Size = System::Drawing::Size(523, 289);
			this->calibrationOutputLogLabel->TabIndex = 0;
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
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
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
			this->objectSelectPage->ResumeLayout(false);
			this->objectSelectPage->PerformLayout();
			this->calibrationPage->ResumeLayout(false);
			this->calibrationPage->PerformLayout();
			this->calculatingPage->ResumeLayout(false);
			this->calculatingPage->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
//private: WizardPages^ wizardPages;
private: EyeCalibration *eyeCalibration;
private: int currentPage;
		 // Abstract Delegate to change text
	private: delegate void SetTextDelegate(String^ value);
		// User Defined Functions
private: System::Void Form_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Create new Eye Calibration
			 this->eyeCalibration = new EyeCalibration();

			 // Set current page
			 this->currentPage = 0;

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

			 // Create list of Rigid Body's
			 this->headRigidBodyListView->View = View::Details;
			 this->headRigidBodyListView->Columns->Add("Id", 50, HorizontalAlignment::Left ); 
			 this->headRigidBodyListView->Columns->Add("Name", 150, HorizontalAlignment::Left ); 

			 this->objectRigidBodyListView->View = View::Details;
			 this->objectRigidBodyListView->Columns->Add("Id", 50, HorizontalAlignment::Left ); 
			 this->objectRigidBodyListView->Columns->Add("Name", 150, HorizontalAlignment::Left ); 

			 // Get ClientHandler
			 ClientHandler* client = AppData::getInstance()->getClient();

			 // Check if the client exists
			 if (client) {

				 // Get all the Rigid Body's
				 std::map<int, RigidBody*>* bodyMap = client->getRigidBodyMap();

				 // Clear any previous entries in the list view
				 this->headRigidBodyListView->Items->Clear();
				 this->objectRigidBodyListView->Items->Clear();

				 // Loop through all Rigid Body's
				 for (std::map<int, RigidBody*>::iterator it=bodyMap->begin(); it!=bodyMap->end(); ++it)
				 {
					 // Add Rigid Body to list
					 { // Add Rigid Body's for head
						 String^ rigidBodyID = Convert::ToString(it->second->getID());
						 String^ rigidBodyName = gcnew String(it->second->getName());
						 ListViewItem^ listViewItem = gcnew ListViewItem(rigidBodyID); 
						 listViewItem->SubItems->Add(rigidBodyName);
						 this->headRigidBodyListView->Items->Add(listViewItem);
					 }

					 { // Add Rigid Body's for viewing object
						 String^ rigidBodyID = Convert::ToString(it->second->getID());
						 String^ rigidBodyName = gcnew String(it->second->getName());
						 ListViewItem^ listViewItem = gcnew ListViewItem(rigidBodyID); 
						 listViewItem->SubItems->Add(rigidBodyName);
						 this->objectRigidBodyListView->Items->Add(listViewItem);
					 }
				 }
			 }
		 }
private: System::Void Form_Closing( Object^ sender, System::EventArgs ^ e )
		 {
			 if (this->eyeCalibration)
				delete this->eyeCalibration;
		 }

private: System::Void pageChanged(System::Object^  sender, System::EventArgs^  e) {
			 // Check if tab is enabled
			 if (this->currentPage < this->wizardPages->SelectedIndex) {
				 // Set the tab index to the current page
				 this->wizardPages->SelectedIndex = this->currentPage;
				 // Give message alerting user's that they are missing information
				  MessageBox::Show(String::Concat("You have insufficient information. ",
            "Please make sure all previous tabs have the proper information."));
			 }

			 // Check Valid information for each page
			 if (this->wizardPages->SelectedTab == this->headSelectPage &&
				 this->eyeCalibration->getHeadId() < 0) {
				  this->nextBtn->Enabled = false;
			 } else if (this->wizardPages->SelectedTab == this->objectSelectPage &&
				 this->eyeCalibration->getViewingObjectId() < 0) {
				  this->nextBtn->Enabled = false;
			 } else {
				  this->nextBtn->Enabled = true;
			 }

			 // Calculate Calibration Points
			 if (this->wizardPages->SelectedTab == this->calculatingPage)
				 this->eyeCalibration->calibrate();

			 // Done and change text in the next button to finished
			 if (this->wizardPages->SelectedIndex == this->wizardPages->TabCount - 1)
				 this->nextBtn->Text = "Finish";
			 else
				 this->nextBtn->Text = "Next";

			 // First page so set enabled to false for the back button
			 if (this->wizardPages->SelectedIndex == 0)
				 this->backBtn->Enabled = false;
			 else
				 this->backBtn->Enabled = true;
		 }
// Cancels the Eye Calibration and closes the wizard
private: System::Void cancelBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
// Advances through the wizard
private: System::Void nextBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Update current page
			 if (this->currentPage == this->wizardPages->SelectedIndex)
				 this->currentPage++;

			 // Check if at last index and if so close Wizard
			 if (this->wizardPages->SelectedIndex < this->wizardPages->TabCount - 1)
				 this->wizardPages->SelectedIndex++;
			 else if (this->wizardPages->SelectedIndex == this->wizardPages->TabCount - 1)
				 this->Close();
		 }
// Go to the previous page
private: System::Void backBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->wizardPages->SelectedIndex > 0)
				 this->wizardPages->SelectedIndex--;
		 }
// When user selects the Rigid Body that represents the head of the subject
private: System::Void selectAsHeadBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->headRigidBodyListView->SelectedItems->Count > 0) {
				 int headId = System::Int32::Parse(this->headRigidBodyListView->SelectedItems[0]->Text);
				 this->eyeCalibration->setHeadId(headId);

				 String^ message = gcnew String(this->eyeCalibration->getHeadName());
				 message = message + " is the Rigid Body selected as the head.";

				 this->headSelectedLabel->Text = message;
				 this->nextBtn->Enabled = true;
			 }
			 else {
				 this->headSelectedLabel->Text = "No Rigid Body is selected to be the head.";
			 }
		 }
private: System::Void selectAsObjectBtn_Click(System::Object^  sender, System::EventArgs^  e) { 
			 if (this->objectRigidBodyListView->SelectedItems->Count > 0) {
				 int viewingObjectId = System::Int32::Parse(this->objectRigidBodyListView->SelectedItems[0]->Text);
				 this->eyeCalibration->setViewingObjectId(viewingObjectId);

				 String^ message = gcnew String(this->eyeCalibration->getViewingObjectName());
				 message = message + " is the Rigid Body selected as the viewing object.";

				 this->selectedObjectLabel->Text = message;
				 this->nextBtn->Enabled = true;
			 }
			 else {
				 this->selectedObjectLabel->Text = "No Rigid Body is selected to be the viewing object.";
			 }
		 }
private: System::Void addCalibrationPointBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
public: System::Void calibrationOutputLog(String^ value) {
			if (this->calibrationOutputLogLabel->InvokeRequired)
			{
				SetTextDelegate^ d = gcnew SetTextDelegate(this, &BlinkAnalysis::EyeCalibrationWizardForm::calibrationOutputLog);
				this->Invoke(d, gcnew array<Object^> { value });
			} else {
				// Update Value
				// Determine if the text being appended to calibrationOutputLogLabel exceeds the MaxLength property.
				if((unsigned int)(calibrationOutputLogLabel->TextLength + value->Length) > (unsigned int)calibrationOutputLogLabel->MaxLength)
				{
					int over = (calibrationOutputLogLabel->TextLength + value->Length) - calibrationOutputLogLabel->MaxLength;
					calibrationOutputLogLabel->Text = calibrationOutputLogLabel->Text->Substring(over);
				}
				// Append the text
				this->calibrationOutputLogLabel->AppendText(value->Replace("\n", Environment::NewLine));
			}
		}
};
}
