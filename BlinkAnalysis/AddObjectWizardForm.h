#pragma once
#include "WizardPages.h"
#include "AppData.h"
#include "WorldManager.h"

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum class ControlType {
		MARKER,
		RIGID,
		INPUT,
		INVALID
	};

	/// <summary>
	/// Summary for AddObjectWizardForm
	/// </summary>
	public ref class AddObjectWizardForm : public System::Windows::Forms::Form
	{
	public:
		AddObjectWizardForm(void)
		{
			InitializeComponent();
			displayWorld = -1;
		}
		
		void selectWorld(int id) {
			displayWorld = id; 
		}
		int getDisplayWorld() { return displayWorld; }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddObjectWizardForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  cancelButton;
	protected: 



	protected: 

	protected: 



	private: System::Windows::Forms::Button^  nextButton;

	private: System::Windows::Forms::Button^  backButton;

	private: System::Windows::Forms::TabPage^  inputPage;
	private: System::Windows::Forms::TabPage^  paramPage;
	private: System::Windows::Forms::ComboBox^  controlComboBox;
	private: System::Windows::Forms::ComboBox^  typeComboBox;
	private: System::Windows::Forms::ComboBox^  worldComboBox;
	private: System::Windows::Forms::TabPage^  introPage;
	private: System::Windows::Forms::TabControl^  wizardPagesTemp;
	private: System::Windows::Forms::Label^  controlLabel;
	private: System::Windows::Forms::Label^  typeLabel;
	private: System::Windows::Forms::Label^  worldLabel;
	private: System::Windows::Forms::Label^  optionalLabel;

	private: System::Windows::Forms::TextBox^  nameTextBox;

	private: System::Windows::Forms::Label^  nameLabel;
	private: System::Windows::Forms::Panel^  inputPlanePanel;
	private: System::Windows::Forms::Panel^  inputBoxPanel1;
	private: System::Windows::Forms::Panel^  inputCylinderPanel1;
	private: System::Windows::Forms::TextBox^  planePt2XText;

	private: System::Windows::Forms::TextBox^  planePt1XText;
	private: System::Windows::Forms::Label^  planeDataLabel;







	private: System::Windows::Forms::Button^  planePt2SetButton;
	private: System::Windows::Forms::Button^  planeCornSetButton;

	private: System::Windows::Forms::Button^  planePt1SetButton;
	private: System::Windows::Forms::Label^  planePt2Label;
	private: System::Windows::Forms::Label^  planeCornerLabel;
	private: System::Windows::Forms::Label^  planePt1Label;
	private: System::Windows::Forms::Button^  planeDataGetButton;






	private: System::Windows::Forms::Label^  planeZLabel;
	private: System::Windows::Forms::Label^  planeYLabel;
	private: System::Windows::Forms::Label^  planeXLabel;
	private: System::Windows::Forms::Label^  planeInfoLabel;
	private: System::Windows::Forms::TextBox^  planePt2ZText;

	private: System::Windows::Forms::TextBox^  planePt2YText;
	private: System::Windows::Forms::TextBox^  planeCornZText;




	private: System::Windows::Forms::TextBox^  planeCornYText;
	private: System::Windows::Forms::TextBox^  planePt1ZText;




	private: System::Windows::Forms::TextBox^  planePt1YText;



	private: System::Windows::Forms::TextBox^  boxHTextBox;
	private: System::Windows::Forms::TextBox^  boxWTextBox;
	private: System::Windows::Forms::TextBox^  boxLTextBox;
	private: System::Windows::Forms::Label^  boxHLabel;

	private: System::Windows::Forms::Label^  boxWLabel;

	private: System::Windows::Forms::Label^  boxLLabel;


	private: System::Windows::Forms::Label^  boxCentreLabel;
private: System::Windows::Forms::Button^  boxDataGetButton;




private: System::Windows::Forms::Label^  boxInfoLabel;
private: System::Windows::Forms::TextBox^  planeCornXText;
private: System::Windows::Forms::TextBox^  boxCenZText;


private: System::Windows::Forms::TextBox^  boxCenYText;

private: System::Windows::Forms::TextBox^  boxCenXText;
private: System::Windows::Forms::Label^  boxZLabel;

private: System::Windows::Forms::Label^  boxYLabel;

private: System::Windows::Forms::Label^  boxXLabel;

private: System::Windows::Forms::Label^  planeMIDLabel;
private: System::Windows::Forms::TextBox^  planeMPt2Text;
private: System::Windows::Forms::TextBox^  planeMCornText;
private: System::Windows::Forms::TextBox^  planeMPt1Text;
private: System::Windows::Forms::Label^  boxDimLabel;

private: System::Windows::Forms::Label^  boxMIDLabel;
private: System::Windows::Forms::TextBox^  boxMCenText;











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
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->nextButton = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->inputPage = (gcnew System::Windows::Forms::TabPage());
			this->inputPlanePanel = (gcnew System::Windows::Forms::Panel());
			this->planeMIDLabel = (gcnew System::Windows::Forms::Label());
			this->planeMPt2Text = (gcnew System::Windows::Forms::TextBox());
			this->planeMCornText = (gcnew System::Windows::Forms::TextBox());
			this->planeMPt1Text = (gcnew System::Windows::Forms::TextBox());
			this->planePt2ZText = (gcnew System::Windows::Forms::TextBox());
			this->planePt2YText = (gcnew System::Windows::Forms::TextBox());
			this->planeCornZText = (gcnew System::Windows::Forms::TextBox());
			this->planeCornYText = (gcnew System::Windows::Forms::TextBox());
			this->planePt1ZText = (gcnew System::Windows::Forms::TextBox());
			this->planePt1YText = (gcnew System::Windows::Forms::TextBox());
			this->planeZLabel = (gcnew System::Windows::Forms::Label());
			this->planeYLabel = (gcnew System::Windows::Forms::Label());
			this->planeXLabel = (gcnew System::Windows::Forms::Label());
			this->planeInfoLabel = (gcnew System::Windows::Forms::Label());
			this->planePt2XText = (gcnew System::Windows::Forms::TextBox());
			this->planeCornXText = (gcnew System::Windows::Forms::TextBox());
			this->planePt1XText = (gcnew System::Windows::Forms::TextBox());
			this->planeDataLabel = (gcnew System::Windows::Forms::Label());
			this->planePt2SetButton = (gcnew System::Windows::Forms::Button());
			this->planeCornSetButton = (gcnew System::Windows::Forms::Button());
			this->planePt1SetButton = (gcnew System::Windows::Forms::Button());
			this->planePt2Label = (gcnew System::Windows::Forms::Label());
			this->planeCornerLabel = (gcnew System::Windows::Forms::Label());
			this->planePt1Label = (gcnew System::Windows::Forms::Label());
			this->planeDataGetButton = (gcnew System::Windows::Forms::Button());
			this->inputBoxPanel1 = (gcnew System::Windows::Forms::Panel());
			this->boxDimLabel = (gcnew System::Windows::Forms::Label());
			this->boxMIDLabel = (gcnew System::Windows::Forms::Label());
			this->boxMCenText = (gcnew System::Windows::Forms::TextBox());
			this->boxCenZText = (gcnew System::Windows::Forms::TextBox());
			this->boxCenYText = (gcnew System::Windows::Forms::TextBox());
			this->boxCenXText = (gcnew System::Windows::Forms::TextBox());
			this->boxZLabel = (gcnew System::Windows::Forms::Label());
			this->boxYLabel = (gcnew System::Windows::Forms::Label());
			this->boxXLabel = (gcnew System::Windows::Forms::Label());
			this->boxInfoLabel = (gcnew System::Windows::Forms::Label());
			this->boxHTextBox = (gcnew System::Windows::Forms::TextBox());
			this->boxWTextBox = (gcnew System::Windows::Forms::TextBox());
			this->boxLTextBox = (gcnew System::Windows::Forms::TextBox());
			this->boxHLabel = (gcnew System::Windows::Forms::Label());
			this->boxWLabel = (gcnew System::Windows::Forms::Label());
			this->boxLLabel = (gcnew System::Windows::Forms::Label());
			this->boxCentreLabel = (gcnew System::Windows::Forms::Label());
			this->boxDataGetButton = (gcnew System::Windows::Forms::Button());
			this->paramPage = (gcnew System::Windows::Forms::TabPage());
			this->controlLabel = (gcnew System::Windows::Forms::Label());
			this->typeLabel = (gcnew System::Windows::Forms::Label());
			this->worldLabel = (gcnew System::Windows::Forms::Label());
			this->optionalLabel = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->controlComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->typeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->worldComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->introPage = (gcnew System::Windows::Forms::TabPage());
			this->wizardPagesTemp = (gcnew System::Windows::Forms::TabControl());
			this->inputCylinderPanel1 = (gcnew System::Windows::Forms::Panel());
			this->inputPage->SuspendLayout();
			this->inputPlanePanel->SuspendLayout();
			this->inputBoxPanel1->SuspendLayout();
			this->paramPage->SuspendLayout();
			this->wizardPagesTemp->SuspendLayout();
			this->SuspendLayout();
			// 
			// cancelButton
			// 
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cancelButton->Location = System::Drawing::Point(426, 250);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(73, 23);
			this->cancelButton->TabIndex = 5;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &AddObjectWizardForm::cancelButton_Click);
			// 
			// nextButton
			// 
			this->nextButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->nextButton->Location = System::Drawing::Point(310, 250);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(73, 23);
			this->nextButton->TabIndex = 4;
			this->nextButton->Text = L"Next";
			this->nextButton->UseVisualStyleBackColor = true;
			this->nextButton->Click += gcnew System::EventHandler(this, &AddObjectWizardForm::nextButton_Click);
			// 
			// backButton
			// 
			this->backButton->Enabled = false;
			this->backButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->backButton->Location = System::Drawing::Point(229, 250);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(73, 23);
			this->backButton->TabIndex = 3;
			this->backButton->Text = L"Back";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &AddObjectWizardForm::backButton_Click);
			// 
			// inputPage
			// 
			this->inputPage->Controls->Add(this->inputPlanePanel);
			this->inputPage->Location = System::Drawing::Point(4, 22);
			this->inputPage->Name = L"inputPage";
			this->inputPage->Padding = System::Windows::Forms::Padding(3);
			this->inputPage->Size = System::Drawing::Size(511, 219);
			this->inputPage->TabIndex = 4;
			this->inputPage->Text = L"Input";
			this->inputPage->UseVisualStyleBackColor = true;
			// 
			// inputPlanePanel
			// 
			this->inputPlanePanel->Controls->Add(this->inputBoxPanel1);
			this->inputPlanePanel->Controls->Add(this->planeMIDLabel);
			this->inputPlanePanel->Controls->Add(this->planeMPt2Text);
			this->inputPlanePanel->Controls->Add(this->planeMCornText);
			this->inputPlanePanel->Controls->Add(this->planeMPt1Text);
			this->inputPlanePanel->Controls->Add(this->planePt2ZText);
			this->inputPlanePanel->Controls->Add(this->planePt2YText);
			this->inputPlanePanel->Controls->Add(this->planeCornZText);
			this->inputPlanePanel->Controls->Add(this->planeCornYText);
			this->inputPlanePanel->Controls->Add(this->planePt1ZText);
			this->inputPlanePanel->Controls->Add(this->planePt1YText);
			this->inputPlanePanel->Controls->Add(this->planeZLabel);
			this->inputPlanePanel->Controls->Add(this->planeYLabel);
			this->inputPlanePanel->Controls->Add(this->planeXLabel);
			this->inputPlanePanel->Controls->Add(this->planeInfoLabel);
			this->inputPlanePanel->Controls->Add(this->planePt2XText);
			this->inputPlanePanel->Controls->Add(this->planeCornXText);
			this->inputPlanePanel->Controls->Add(this->planePt1XText);
			this->inputPlanePanel->Controls->Add(this->planeDataLabel);
			this->inputPlanePanel->Controls->Add(this->planePt2SetButton);
			this->inputPlanePanel->Controls->Add(this->planeCornSetButton);
			this->inputPlanePanel->Controls->Add(this->planePt1SetButton);
			this->inputPlanePanel->Controls->Add(this->planePt2Label);
			this->inputPlanePanel->Controls->Add(this->planeCornerLabel);
			this->inputPlanePanel->Controls->Add(this->planePt1Label);
			this->inputPlanePanel->Controls->Add(this->planeDataGetButton);
			this->inputPlanePanel->Location = System::Drawing::Point(0, 0);
			this->inputPlanePanel->Name = L"inputPlanePanel";
			this->inputPlanePanel->Size = System::Drawing::Size(511, 219);
			this->inputPlanePanel->TabIndex = 0;
			this->inputPlanePanel->Visible = false;
			// 
			// planeMIDLabel
			// 
			this->planeMIDLabel->AutoSize = true;
			this->planeMIDLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planeMIDLabel->Location = System::Drawing::Point(28, 105);
			this->planeMIDLabel->Name = L"planeMIDLabel";
			this->planeMIDLabel->Size = System::Drawing::Size(70, 15);
			this->planeMIDLabel->TabIndex = 67;
			this->planeMIDLabel->Text = L"Marker ID";
			// 
			// planeMPt2Text
			// 
			this->planeMPt2Text->Location = System::Drawing::Point(31, 175);
			this->planeMPt2Text->Name = L"planeMPt2Text";
			this->planeMPt2Text->Size = System::Drawing::Size(76, 20);
			this->planeMPt2Text->TabIndex = 66;
			// 
			// planeMCornText
			// 
			this->planeMCornText->Location = System::Drawing::Point(31, 149);
			this->planeMCornText->Name = L"planeMCornText";
			this->planeMCornText->Size = System::Drawing::Size(76, 20);
			this->planeMCornText->TabIndex = 65;
			// 
			// planeMPt1Text
			// 
			this->planeMPt1Text->Location = System::Drawing::Point(31, 123);
			this->planeMPt1Text->Name = L"planeMPt1Text";
			this->planeMPt1Text->Size = System::Drawing::Size(76, 20);
			this->planeMPt1Text->TabIndex = 64;
			// 
			// planePt2ZText
			// 
			this->planePt2ZText->Location = System::Drawing::Point(337, 175);
			this->planePt2ZText->Name = L"planePt2ZText";
			this->planePt2ZText->Size = System::Drawing::Size(76, 20);
			this->planePt2ZText->TabIndex = 63;
			this->planePt2ZText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::planeText_Validating);
			// 
			// planePt2YText
			// 
			this->planePt2YText->Location = System::Drawing::Point(255, 175);
			this->planePt2YText->Name = L"planePt2YText";
			this->planePt2YText->Size = System::Drawing::Size(76, 20);
			this->planePt2YText->TabIndex = 62;
			this->planePt2YText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::planeText_Validating);
			// 
			// planeCornZText
			// 
			this->planeCornZText->Location = System::Drawing::Point(337, 149);
			this->planeCornZText->Name = L"planeCornZText";
			this->planeCornZText->Size = System::Drawing::Size(76, 20);
			this->planeCornZText->TabIndex = 60;
			this->planeCornZText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::planeText_Validating);
			// 
			// planeCornYText
			// 
			this->planeCornYText->Location = System::Drawing::Point(255, 149);
			this->planeCornYText->Name = L"planeCornYText";
			this->planeCornYText->Size = System::Drawing::Size(76, 20);
			this->planeCornYText->TabIndex = 59;
			this->planeCornYText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::planeText_Validating);
			// 
			// planePt1ZText
			// 
			this->planePt1ZText->Location = System::Drawing::Point(337, 123);
			this->planePt1ZText->Name = L"planePt1ZText";
			this->planePt1ZText->Size = System::Drawing::Size(76, 20);
			this->planePt1ZText->TabIndex = 57;
			this->planePt1ZText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::planeText_Validating);
			// 
			// planePt1YText
			// 
			this->planePt1YText->Location = System::Drawing::Point(255, 123);
			this->planePt1YText->Name = L"planePt1YText";
			this->planePt1YText->Size = System::Drawing::Size(76, 20);
			this->planePt1YText->TabIndex = 56;
			this->planePt1YText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::planeText_Validating);
			// 
			// planeZLabel
			// 
			this->planeZLabel->AutoSize = true;
			this->planeZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planeZLabel->Location = System::Drawing::Point(367, 105);
			this->planeZLabel->Name = L"planeZLabel";
			this->planeZLabel->Size = System::Drawing::Size(15, 15);
			this->planeZLabel->TabIndex = 53;
			this->planeZLabel->Text = L"Z";
			// 
			// planeYLabel
			// 
			this->planeYLabel->AutoSize = true;
			this->planeYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planeYLabel->Location = System::Drawing::Point(287, 105);
			this->planeYLabel->Name = L"planeYLabel";
			this->planeYLabel->Size = System::Drawing::Size(15, 15);
			this->planeYLabel->TabIndex = 52;
			this->planeYLabel->Text = L"Y";
			// 
			// planeXLabel
			// 
			this->planeXLabel->AutoSize = true;
			this->planeXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planeXLabel->Location = System::Drawing::Point(201, 105);
			this->planeXLabel->Name = L"planeXLabel";
			this->planeXLabel->Size = System::Drawing::Size(16, 15);
			this->planeXLabel->TabIndex = 51;
			this->planeXLabel->Text = L"X";
			// 
			// planeInfoLabel
			// 
			this->planeInfoLabel->AutoSize = true;
			this->planeInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planeInfoLabel->Location = System::Drawing::Point(19, 19);
			this->planeInfoLabel->Name = L"planeInfoLabel";
			this->planeInfoLabel->Size = System::Drawing::Size(167, 15);
			this->planeInfoLabel->TabIndex = 54;
			this->planeInfoLabel->Text = L"Add a finite plane to the world";
			// 
			// planePt2XText
			// 
			this->planePt2XText->Location = System::Drawing::Point(173, 175);
			this->planePt2XText->Name = L"planePt2XText";
			this->planePt2XText->Size = System::Drawing::Size(76, 20);
			this->planePt2XText->TabIndex = 61;
			this->planePt2XText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::planeText_Validating);
			// 
			// planeCornXText
			// 
			this->planeCornXText->Location = System::Drawing::Point(173, 149);
			this->planeCornXText->Name = L"planeCornXText";
			this->planeCornXText->Size = System::Drawing::Size(76, 20);
			this->planeCornXText->TabIndex = 58;
			this->planeCornXText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::planeText_Validating);
			// 
			// planePt1XText
			// 
			this->planePt1XText->Location = System::Drawing::Point(173, 123);
			this->planePt1XText->Name = L"planePt1XText";
			this->planePt1XText->Size = System::Drawing::Size(76, 20);
			this->planePt1XText->TabIndex = 55;
			this->planePt1XText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::planeText_Validating);
			// 
			// planeDataLabel
			// 
			this->planeDataLabel->AutoSize = true;
			this->planeDataLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planeDataLabel->Location = System::Drawing::Point(110, 64);
			this->planeDataLabel->Name = L"planeDataLabel";
			this->planeDataLabel->Size = System::Drawing::Size(92, 16);
			this->planeDataLabel->TabIndex = 50;
			this->planeDataLabel->Text = L"No data found";
			// 
			// planePt2SetButton
			// 
			this->planePt2SetButton->Enabled = false;
			this->planePt2SetButton->Location = System::Drawing::Point(113, 173);
			this->planePt2SetButton->Name = L"planePt2SetButton";
			this->planePt2SetButton->Size = System::Drawing::Size(54, 23);
			this->planePt2SetButton->TabIndex = 49;
			this->planePt2SetButton->Text = L"Point 2";
			this->planePt2SetButton->UseVisualStyleBackColor = true;
			this->planePt2SetButton->Click += gcnew System::EventHandler(this, &AddObjectWizardForm::planeDataSetButton_Click);
			// 
			// planeCornSetButton
			// 
			this->planeCornSetButton->Enabled = false;
			this->planeCornSetButton->Location = System::Drawing::Point(113, 147);
			this->planeCornSetButton->Name = L"planeCornSetButton";
			this->planeCornSetButton->Size = System::Drawing::Size(54, 23);
			this->planeCornSetButton->TabIndex = 48;
			this->planeCornSetButton->Text = L"Corner";
			this->planeCornSetButton->UseVisualStyleBackColor = true;
			this->planeCornSetButton->Click += gcnew System::EventHandler(this, &AddObjectWizardForm::planeDataSetButton_Click);
			// 
			// planePt1SetButton
			// 
			this->planePt1SetButton->Enabled = false;
			this->planePt1SetButton->Location = System::Drawing::Point(113, 121);
			this->planePt1SetButton->Name = L"planePt1SetButton";
			this->planePt1SetButton->Size = System::Drawing::Size(54, 23);
			this->planePt1SetButton->TabIndex = 47;
			this->planePt1SetButton->Text = L"Point 1";
			this->planePt1SetButton->UseVisualStyleBackColor = true;
			this->planePt1SetButton->Click += gcnew System::EventHandler(this, &AddObjectWizardForm::planeDataSetButton_Click);
			// 
			// planePt2Label
			// 
			this->planePt2Label->AutoSize = true;
			this->planePt2Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planePt2Label->Location = System::Drawing::Point(115, 176);
			this->planePt2Label->Name = L"planePt2Label";
			this->planePt2Label->Size = System::Drawing::Size(52, 15);
			this->planePt2Label->TabIndex = 46;
			this->planePt2Label->Text = L"Point 2";
			// 
			// planeCornerLabel
			// 
			this->planeCornerLabel->AutoSize = true;
			this->planeCornerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planeCornerLabel->Location = System::Drawing::Point(117, 150);
			this->planeCornerLabel->Name = L"planeCornerLabel";
			this->planeCornerLabel->Size = System::Drawing::Size(50, 15);
			this->planeCornerLabel->TabIndex = 45;
			this->planeCornerLabel->Text = L"Corner";
			// 
			// planePt1Label
			// 
			this->planePt1Label->AutoSize = true;
			this->planePt1Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planePt1Label->Location = System::Drawing::Point(115, 124);
			this->planePt1Label->Name = L"planePt1Label";
			this->planePt1Label->Size = System::Drawing::Size(52, 15);
			this->planePt1Label->TabIndex = 44;
			this->planePt1Label->Text = L"Point 1";
			// 
			// planeDataGetButton
			// 
			this->planeDataGetButton->Location = System::Drawing::Point(29, 61);
			this->planeDataGetButton->Name = L"planeDataGetButton";
			this->planeDataGetButton->Size = System::Drawing::Size(75, 23);
			this->planeDataGetButton->TabIndex = 43;
			this->planeDataGetButton->Text = L"Get Data";
			this->planeDataGetButton->UseVisualStyleBackColor = true;
			this->planeDataGetButton->Click += gcnew System::EventHandler(this, &AddObjectWizardForm::planeDataGetButton_Click);
			// 
			// inputBoxPanel1
			// 
			this->inputBoxPanel1->Controls->Add(this->boxDimLabel);
			this->inputBoxPanel1->Controls->Add(this->boxMIDLabel);
			this->inputBoxPanel1->Controls->Add(this->boxMCenText);
			this->inputBoxPanel1->Controls->Add(this->boxCenZText);
			this->inputBoxPanel1->Controls->Add(this->boxCenYText);
			this->inputBoxPanel1->Controls->Add(this->boxCenXText);
			this->inputBoxPanel1->Controls->Add(this->boxZLabel);
			this->inputBoxPanel1->Controls->Add(this->boxYLabel);
			this->inputBoxPanel1->Controls->Add(this->boxXLabel);
			this->inputBoxPanel1->Controls->Add(this->boxInfoLabel);
			this->inputBoxPanel1->Controls->Add(this->boxHTextBox);
			this->inputBoxPanel1->Controls->Add(this->boxWTextBox);
			this->inputBoxPanel1->Controls->Add(this->boxLTextBox);
			this->inputBoxPanel1->Controls->Add(this->boxHLabel);
			this->inputBoxPanel1->Controls->Add(this->boxWLabel);
			this->inputBoxPanel1->Controls->Add(this->boxLLabel);
			this->inputBoxPanel1->Controls->Add(this->boxCentreLabel);
			this->inputBoxPanel1->Controls->Add(this->boxDataGetButton);
			this->inputBoxPanel1->Location = System::Drawing::Point(0, 0);
			this->inputBoxPanel1->Name = L"inputBoxPanel1";
			this->inputBoxPanel1->Size = System::Drawing::Size(511, 219);
			this->inputBoxPanel1->TabIndex = 1;
			// 
			// boxDimLabel
			// 
			this->boxDimLabel->AutoSize = true;
			this->boxDimLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxDimLabel->Location = System::Drawing::Point(25, 160);
			this->boxDimLabel->Name = L"boxDimLabel";
			this->boxDimLabel->Size = System::Drawing::Size(73, 15);
			this->boxDimLabel->TabIndex = 75;
			this->boxDimLabel->Text = L"Dimensions";
			// 
			// boxMIDLabel
			// 
			this->boxMIDLabel->AutoSize = true;
			this->boxMIDLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxMIDLabel->Location = System::Drawing::Point(39, 108);
			this->boxMIDLabel->Name = L"boxMIDLabel";
			this->boxMIDLabel->Size = System::Drawing::Size(70, 15);
			this->boxMIDLabel->TabIndex = 74;
			this->boxMIDLabel->Text = L"Marker ID";
			// 
			// boxMCenText
			// 
			this->boxMCenText->Location = System::Drawing::Point(42, 126);
			this->boxMCenText->Name = L"boxMCenText";
			this->boxMCenText->Size = System::Drawing::Size(76, 20);
			this->boxMCenText->TabIndex = 73;
			// 
			// boxCenZText
			// 
			this->boxCenZText->Location = System::Drawing::Point(321, 84);
			this->boxCenZText->Name = L"boxCenZText";
			this->boxCenZText->Size = System::Drawing::Size(83, 20);
			this->boxCenZText->TabIndex = 72;
			this->boxCenZText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::boxText_Validating);
			// 
			// boxCenYText
			// 
			this->boxCenYText->Location = System::Drawing::Point(232, 84);
			this->boxCenYText->Name = L"boxCenYText";
			this->boxCenYText->Size = System::Drawing::Size(83, 20);
			this->boxCenYText->TabIndex = 71;
			this->boxCenYText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::boxText_Validating);
			// 
			// boxCenXText
			// 
			this->boxCenXText->Location = System::Drawing::Point(143, 84);
			this->boxCenXText->Name = L"boxCenXText";
			this->boxCenXText->Size = System::Drawing::Size(83, 20);
			this->boxCenXText->TabIndex = 70;
			this->boxCenXText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::boxText_Validating);
			// 
			// boxZLabel
			// 
			this->boxZLabel->AutoSize = true;
			this->boxZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxZLabel->Location = System::Drawing::Point(356, 66);
			this->boxZLabel->Name = L"boxZLabel";
			this->boxZLabel->Size = System::Drawing::Size(15, 15);
			this->boxZLabel->TabIndex = 69;
			this->boxZLabel->Text = L"Z";
			// 
			// boxYLabel
			// 
			this->boxYLabel->AutoSize = true;
			this->boxYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxYLabel->Location = System::Drawing::Point(264, 66);
			this->boxYLabel->Name = L"boxYLabel";
			this->boxYLabel->Size = System::Drawing::Size(15, 15);
			this->boxYLabel->TabIndex = 68;
			this->boxYLabel->Text = L"Y";
			// 
			// boxXLabel
			// 
			this->boxXLabel->AutoSize = true;
			this->boxXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxXLabel->Location = System::Drawing::Point(176, 66);
			this->boxXLabel->Name = L"boxXLabel";
			this->boxXLabel->Size = System::Drawing::Size(16, 15);
			this->boxXLabel->TabIndex = 67;
			this->boxXLabel->Text = L"X";
			// 
			// boxInfoLabel
			// 
			this->boxInfoLabel->AutoSize = true;
			this->boxInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxInfoLabel->Location = System::Drawing::Point(25, 22);
			this->boxInfoLabel->Name = L"boxInfoLabel";
			this->boxInfoLabel->Size = System::Drawing::Size(127, 15);
			this->boxInfoLabel->TabIndex = 66;
			this->boxInfoLabel->Text = L"Add a box to the world";
			// 
			// boxHTextBox
			// 
			this->boxHTextBox->Location = System::Drawing::Point(321, 178);
			this->boxHTextBox->Name = L"boxHTextBox";
			this->boxHTextBox->Size = System::Drawing::Size(83, 20);
			this->boxHTextBox->TabIndex = 65;
			this->boxHTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::boxText_Validating);
			// 
			// boxWTextBox
			// 
			this->boxWTextBox->Location = System::Drawing::Point(232, 178);
			this->boxWTextBox->Name = L"boxWTextBox";
			this->boxWTextBox->Size = System::Drawing::Size(83, 20);
			this->boxWTextBox->TabIndex = 64;
			this->boxWTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::boxText_Validating);
			// 
			// boxLTextBox
			// 
			this->boxLTextBox->Location = System::Drawing::Point(143, 178);
			this->boxLTextBox->Name = L"boxLTextBox";
			this->boxLTextBox->Size = System::Drawing::Size(83, 20);
			this->boxLTextBox->TabIndex = 63;
			this->boxLTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectWizardForm::boxText_Validating);
			// 
			// boxHLabel
			// 
			this->boxHLabel->AutoSize = true;
			this->boxHLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxHLabel->Location = System::Drawing::Point(318, 160);
			this->boxHLabel->Name = L"boxHLabel";
			this->boxHLabel->Size = System::Drawing::Size(71, 15);
			this->boxHLabel->TabIndex = 62;
			this->boxHLabel->Text = L"Height (Z)";
			// 
			// boxWLabel
			// 
			this->boxWLabel->AutoSize = true;
			this->boxWLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxWLabel->Location = System::Drawing::Point(229, 160);
			this->boxWLabel->Name = L"boxWLabel";
			this->boxWLabel->Size = System::Drawing::Size(65, 15);
			this->boxWLabel->TabIndex = 61;
			this->boxWLabel->Text = L"Width (Y)";
			// 
			// boxLLabel
			// 
			this->boxLLabel->AutoSize = true;
			this->boxLLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxLLabel->Location = System::Drawing::Point(140, 160);
			this->boxLLabel->Name = L"boxLLabel";
			this->boxLLabel->Size = System::Drawing::Size(74, 15);
			this->boxLLabel->TabIndex = 60;
			this->boxLLabel->Text = L"Length (X)";
			// 
			// boxCentreLabel
			// 
			this->boxCentreLabel->AutoSize = true;
			this->boxCentreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxCentreLabel->Location = System::Drawing::Point(25, 52);
			this->boxCentreLabel->Name = L"boxCentreLabel";
			this->boxCentreLabel->Size = System::Drawing::Size(74, 15);
			this->boxCentreLabel->TabIndex = 58;
			this->boxCentreLabel->Text = L"Base Centre";
			// 
			// boxDataGetButton
			// 
			this->boxDataGetButton->Location = System::Drawing::Point(42, 82);
			this->boxDataGetButton->Name = L"boxDataGetButton";
			this->boxDataGetButton->Size = System::Drawing::Size(75, 23);
			this->boxDataGetButton->TabIndex = 57;
			this->boxDataGetButton->Text = L"Get Data";
			this->boxDataGetButton->UseVisualStyleBackColor = true;
			this->boxDataGetButton->Click += gcnew System::EventHandler(this, &AddObjectWizardForm::boxDataGetButton_Click);
			// 
			// paramPage
			// 
			this->paramPage->Controls->Add(this->controlLabel);
			this->paramPage->Controls->Add(this->typeLabel);
			this->paramPage->Controls->Add(this->worldLabel);
			this->paramPage->Controls->Add(this->optionalLabel);
			this->paramPage->Controls->Add(this->nameTextBox);
			this->paramPage->Controls->Add(this->nameLabel);
			this->paramPage->Controls->Add(this->controlComboBox);
			this->paramPage->Controls->Add(this->typeComboBox);
			this->paramPage->Controls->Add(this->worldComboBox);
			this->paramPage->Location = System::Drawing::Point(4, 22);
			this->paramPage->Name = L"paramPage";
			this->paramPage->Padding = System::Windows::Forms::Padding(3);
			this->paramPage->Size = System::Drawing::Size(511, 219);
			this->paramPage->TabIndex = 1;
			this->paramPage->Text = L"Parameters";
			this->paramPage->UseVisualStyleBackColor = true;
			// 
			// controlLabel
			// 
			this->controlLabel->AutoSize = true;
			this->controlLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->controlLabel->Location = System::Drawing::Point(41, 178);
			this->controlLabel->Name = L"controlLabel";
			this->controlLabel->Size = System::Drawing::Size(53, 15);
			this->controlLabel->TabIndex = 30;
			this->controlLabel->Text = L"Control";
			// 
			// typeLabel
			// 
			this->typeLabel->AutoSize = true;
			this->typeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->typeLabel->Location = System::Drawing::Point(12, 142);
			this->typeLabel->Name = L"typeLabel";
			this->typeLabel->Size = System::Drawing::Size(82, 15);
			this->typeLabel->TabIndex = 29;
			this->typeLabel->Text = L"Object Type";
			// 
			// worldLabel
			// 
			this->worldLabel->AutoSize = true;
			this->worldLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->worldLabel->Location = System::Drawing::Point(50, 102);
			this->worldLabel->Name = L"worldLabel";
			this->worldLabel->Size = System::Drawing::Size(44, 15);
			this->worldLabel->TabIndex = 28;
			this->worldLabel->Text = L"World";
			// 
			// optionalLabel
			// 
			this->optionalLabel->AutoSize = true;
			this->optionalLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->optionalLabel->Location = System::Drawing::Point(285, 50);
			this->optionalLabel->Name = L"optionalLabel";
			this->optionalLabel->Size = System::Drawing::Size(44, 13);
			this->optionalLabel->TabIndex = 27;
			this->optionalLabel->Text = L"optional";
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(100, 47);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(179, 20);
			this->nameTextBox->TabIndex = 26;
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->nameLabel->Location = System::Drawing::Point(49, 48);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(45, 15);
			this->nameLabel->TabIndex = 25;
			this->nameLabel->Text = L"Name";
			// 
			// controlComboBox
			// 
			this->controlComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->controlComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->controlComboBox->ForeColor = System::Drawing::SystemColors::InfoText;
			this->controlComboBox->FormattingEnabled = true;
			this->controlComboBox->Location = System::Drawing::Point(100, 177);
			this->controlComboBox->Name = L"controlComboBox";
			this->controlComboBox->Size = System::Drawing::Size(183, 21);
			this->controlComboBox->TabIndex = 3;
			this->controlComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::controlComboBox_SelectedIndexChanged);
			// 
			// typeComboBox
			// 
			this->typeComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->typeComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->typeComboBox->ForeColor = System::Drawing::SystemColors::InfoText;
			this->typeComboBox->FormattingEnabled = true;
			this->typeComboBox->Location = System::Drawing::Point(100, 141);
			this->typeComboBox->Name = L"typeComboBox";
			this->typeComboBox->Size = System::Drawing::Size(183, 21);
			this->typeComboBox->TabIndex = 2;
			this->typeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::typeComboBox_SelectedIndexChanged);
			// 
			// worldComboBox
			// 
			this->worldComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->worldComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->worldComboBox->ForeColor = System::Drawing::SystemColors::InfoText;
			this->worldComboBox->FormattingEnabled = true;
			this->worldComboBox->Location = System::Drawing::Point(100, 101);
			this->worldComboBox->Name = L"worldComboBox";
			this->worldComboBox->Size = System::Drawing::Size(183, 21);
			this->worldComboBox->TabIndex = 1;
			this->worldComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::worldComboBox_SelectedIndexChanged);
			// 
			// introPage
			// 
			this->introPage->Location = System::Drawing::Point(4, 22);
			this->introPage->Name = L"introPage";
			this->introPage->Padding = System::Windows::Forms::Padding(3);
			this->introPage->Size = System::Drawing::Size(511, 219);
			this->introPage->TabIndex = 0;
			this->introPage->Text = L"Info";
			this->introPage->UseVisualStyleBackColor = true;
			// 
			// wizardPagesTemp
			// 
			this->wizardPagesTemp->Controls->Add(this->introPage);
			this->wizardPagesTemp->Controls->Add(this->paramPage);
			this->wizardPagesTemp->Controls->Add(this->inputPage);
			this->wizardPagesTemp->Location = System::Drawing::Point(0, 0);
			this->wizardPagesTemp->Name = L"wizardPagesTemp";
			this->wizardPagesTemp->SelectedIndex = 0;
			this->wizardPagesTemp->Size = System::Drawing::Size(519, 245);
			this->wizardPagesTemp->TabIndex = 0;
			// 
			// inputCylinderPanel1
			// 
			this->inputCylinderPanel1->Location = System::Drawing::Point(545, 22);
			this->inputCylinderPanel1->Name = L"inputCylinderPanel1";
			this->inputCylinderPanel1->Size = System::Drawing::Size(510, 219);
			this->inputCylinderPanel1->TabIndex = 2;
			this->inputCylinderPanel1->Visible = false;
			// 
			// AddObjectWizardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1074, 294);
			this->Controls->Add(this->inputCylinderPanel1);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->nextButton);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->wizardPagesTemp);
			this->Name = L"AddObjectWizardForm";
			this->Text = L"Add Object Wizard";
			this->Load += gcnew System::EventHandler(this, &AddObjectWizardForm::AddObjectWizardForm_Load);
			this->inputPage->ResumeLayout(false);
			this->inputPlanePanel->ResumeLayout(false);
			this->inputPlanePanel->PerformLayout();
			this->inputBoxPanel1->ResumeLayout(false);
			this->inputBoxPanel1->PerformLayout();
			this->paramPage->ResumeLayout(false);
			this->paramPage->PerformLayout();
			this->wizardPagesTemp->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: WizardPages^ wizardPages;
	//private: int currentPage;
	private: int displayWorld;
	private: ObjectType objType;
	private: ControlType control;
	private: System::String^ defaultDataText;
	private: bool inputDirty;	// indicates if data fields need to be reset on display
	private: osg::Vec3* pos;
	private: osg::Vec3* pos0;
	private: osg::Vec3* pos1;
	private: osg::Vec3* pos2;

	private: System::Void AddObjectWizardForm_Load(System::Object^  sender, System::EventArgs^  e) {
			this->displayWorld = -1;
			this->objType = OBJ_INVALID;
			this->control = ControlType::INVALID;
			this->defaultDataText = L"No data found";
			this->inputDirty = false;

			pos = new osg::Vec3();
			pos0 = new osg::Vec3();
			pos1 = new osg::Vec3();
			pos2 = new osg::Vec3();
			 
			this->Controls->Remove(this->wizardPagesTemp);
			this->wizardPages = gcnew WizardPages();
			 // TODO: populate this with info from wizardPagesTemp
			this->wizardPages->SuspendLayout();
			
			this->wizardPages->Controls->Add(this->introPage);
			this->wizardPages->Controls->Add(this->paramPage);
			this->wizardPages->Controls->Add(this->inputPage);
			this->wizardPages->Location = System::Drawing::Point(0, 0);
			this->wizardPages->Name = L"wizardPagesTemp";
			this->wizardPages->SelectedIndex = 0;
			this->wizardPages->Size = System::Drawing::Size(519, 245);
			this->wizardPages->TabIndex = 0;
			this->wizardPages->SelectedIndexChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::page_SelectedIndexChanged);
			
			this->Controls->Add(this->wizardPages);
			this->wizardPages->ResumeLayout(false);


			 worldPopulateList();
			 typePopulateList();
			 controlPopulateList();
		}

/////////////////////
// Util Functions

// extracts ID from text format "Name (##)"
private: int worldExtractID(String^ str) {
			 array<String^>^ split = str->Split(gcnew array<wchar_t> {'(', ')'});

			 int result;
			 // id contained in second to last element
			 if (Int32::TryParse(split[split->Length - 2], result))
				 return result;
			 else
				 return -1;
		}
		 // set text to display when there is no position data
private: System::Void setDefaultText(Label^ text) {
				text->Text = this->defaultDataText;
			}
		 // set text to display when there is position data
private: System::Void setPoint(osg::Vec3* pos, Label^ text) {
			String^ str = Convert::ToString(pos->x());
			str += ", ";
			str += Convert::ToString(pos->y());
			str += ", ";
			str += Convert::ToString(pos->z());
			text->Text = str;
		 }
	// converts a managed String^ to unmanaged std::string*
private: std::string* managedToStdString(String^ str) {
			 return new std::string( 
				 (const char*) (Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str)).ToPointer());
		 }
		 // checks if input string is a valid float
private: bool isFloat(String^ str) {
			 String^ regs = "^\\s*-?\\d+(.\\d+)?\\s*$";
			 System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(regs);
			 return regex->IsMatch(str);
		 }
/////////////////////
// Parameter Panel
private: System::Void worldPopulateList() {
			std::map<int, CaptureWorld*> worlds = WorldManager::getInstance()->getWorlds();
			int idx = 0;
			int select = -1;
			for (worlds_iterator itr = worlds.begin(); itr != worlds.end(); itr++)
			{
				String^ worldName = gcnew String(itr->second->getName().c_str());
				worldName += " (";
				worldName += itr->first.ToString();
				worldName += ")";
				this->worldComboBox->Items->Add(worldName);
				if (itr->second->getID() != displayWorld)
					idx++;
				else 
					select = idx;
			}
			if (select >= 0)
				this->worldComboBox->SelectedIndex = select;
		}
private: System::Void typePopulateList() {
				String^ type;
				// make sure it's same order as in CaptureObject::ObjectType enum
				type = gcnew String("Plane");
				this->typeComboBox->Items->Add(type);

				type = gcnew String("Box");
				this->typeComboBox->Items->Add(type);

				type = gcnew String("Cylinder");
				this->typeComboBox->Items->Add(type);

/*				type = gcnew String("Custom");
				this->typeComboBox->Items->Add(type);*/
		}
private: System::Void controlPopulateList() {
				String^ control;
				// make sure it's same order as in ControlType enum
				control = gcnew String("Labeled Markers");
				this->controlComboBox->Items->Add(control);

				control = gcnew String("Rigid Body Tool");
				this->controlComboBox->Items->Add(control);

				control = gcnew String("Input Coordinates");
				this->controlComboBox->Items->Add(control);
		}
private: System::Void worldComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (!this->worldComboBox->SelectedItem)
			 {
				 displayWorld = -1;
				 this->nextButton->Enabled = false;
				 return;
			 }
			 
			 String^ text = this->worldComboBox->SelectedItem->ToString();
			 displayWorld = worldExtractID(text);

			 if (this->typeComboBox->SelectedItem && this->controlComboBox->SelectedItem)
				 this->nextButton->Enabled = true;
		 }
private: System::Void typeComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (!this->typeComboBox->SelectedItem)
			 {
				 this->nextButton->Enabled = false;
				 return;
			 }
			 
			 ObjectType ot = (ObjectType) this->typeComboBox->SelectedIndex;
			 if (objType != ot)
				 inputDirty = true;
			 objType = ot;

			 if (this->worldComboBox->SelectedItem && this->controlComboBox->SelectedItem)
				 this->nextButton->Enabled = true;
		 }
private: System::Void controlComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (!this->controlComboBox->SelectedItem)
			 {
				 this->nextButton->Enabled = false;
				 return;
			 }
			 
			 ControlType ct = (ControlType) this->controlComboBox->SelectedIndex;
			 if (control != ct)
				 inputDirty = true;
			 control = ct;

			 if (this->typeComboBox->SelectedItem && this->worldComboBox->SelectedItem)
				 this->nextButton->Enabled = true;
		 }
/////////////////////
// Input Panel Objects
		 // set visible/not visible for buttons associated with rigid body control
private: System::Void rigidSetButton(bool enable, bool visible, ObjectType type) {
			 switch (type)
			 {
			 // plane
			 case OBJ_PLANE :
				 // visibility
				 this->planePt1SetButton->Visible = visible;
				 this->planeCornSetButton->Visible = visible;
				 this->planePt2SetButton->Visible = visible;

				 // enabled
				 this->planePt1SetButton->Enabled = enable;
				 this->planeCornSetButton->Enabled = enable;
				 this->planePt2SetButton->Enabled = enable;

				 break;


			 }
		 }
		 // set visible/not visible for text boxes in the x column
private: System::Void XYZTextBox(bool readonly, ObjectType type) {
			 switch (type)
			 {
			 // plane
			 case OBJ_PLANE :
				 // read only
				 this->planePt1XText->ReadOnly = readonly;
				 this->planePt1YText->ReadOnly = readonly;
				 this->planePt1ZText->ReadOnly = readonly;

				 this->planeCornXText->ReadOnly = readonly;
				 this->planeCornYText->ReadOnly = readonly;
				 this->planeCornZText->ReadOnly = readonly;

				 this->planePt2XText->ReadOnly = readonly;
				 this->planePt2YText->ReadOnly = readonly;
				 this->planePt2ZText->ReadOnly = readonly;

				 // reset textbox info
				 if (inputDirty)
				 {
					 this->planePt1XText->Text = "";
					 this->planePt1YText->Text = "";
					 this->planePt1ZText->Text = "";

					 this->planeCornXText->Text = "";
					 this->planeCornYText->Text = "";
					 this->planeCornZText->Text = "";

					 this->planePt2XText->Text = "";
					 this->planePt2YText->Text = "";
					 this->planePt2ZText->Text = "";
				 }
				 break;
			 // box
			 case OBJ_BOX :
				 // read only
				 this->boxCenXText->ReadOnly = readonly;
				 this->boxCenYText->ReadOnly = readonly;
				 this->boxCenZText->ReadOnly = readonly;

				 // reset textbox info
				 if (inputDirty)
				 {
					 this->boxCenXText->Text = "";
					 this->boxCenYText->Text = "";
					 this->boxCenZText->Text = "";
				 }
				 break;

			 }
		 }
private: System::Void getDataLabel(bool visible, ObjectType type) {
			 switch (type)
			 {
			 // plane
			 case OBJ_PLANE :
				 // visibility
				 this->planeDataLabel->Visible = visible;

				 // reset label info
				 if (inputDirty)
					 setDefaultText(this->planeDataLabel);
				 
				 break;


			 }
		 }
private: System::Void getDataButton(bool visible, ObjectType type) {
			 switch (type)
			 {
			 // plane
			 case OBJ_PLANE :
				 this->planeDataGetButton->Visible = visible;
				 break;
			 // box
			 case OBJ_BOX :
				 this->boxDataGetButton->Visible = visible;
				 break;

			 }
		 }
private: System::Void markerIDTextBox(bool visible, ObjectType type) {
			 switch (type)
			 {
			 // plane
			 case OBJ_PLANE :
				 // visibility
				 this->planeMPt1Text->Visible = visible;
				 this->planeMCornText->Visible = visible;
				 this->planeMPt2Text->Visible = visible;
				 this->planeMIDLabel->Visible = visible;

				 // reset textbox info
				 if (inputDirty)
				 {
					 this->planeMPt1Text->Text = "";
					 this->planeMCornText->Text = "";
					 this->planeMPt2Text->Text = "";
				 }
				 break;
			 // box
			 case OBJ_BOX :
				 // visibility
				 this->boxMCenText->Visible = visible;
				 this->boxMIDLabel->Visible = visible;

				 // reset textbox info
				 if (inputDirty)
				 {
					 this->boxMCenText->Text = "";
				 }
				 break;

			 }
		 }
private: System::Void planePanel(ControlType ct, bool visible) {
			 if (!visible)
			 {
				 this->inputPlanePanel->Visible = false;
				 return;
			 }

			 this->inputPlanePanel->Visible = true;
			 if (ct == ControlType::MARKER)
			 {
				 rigidSetButton(false, false, OBJ_PLANE);
				 XYZTextBox(true, OBJ_PLANE);
				 getDataLabel(false, OBJ_PLANE);
				 getDataButton(true, OBJ_PLANE);
				 markerIDTextBox(true, OBJ_PLANE);
			 }
			 else if (ct == ControlType::RIGID)
			 {
				 rigidSetButton(!inputDirty, true, OBJ_PLANE);
				 XYZTextBox(true, OBJ_PLANE);
				 getDataLabel(true, OBJ_PLANE);
				 getDataButton(true, OBJ_PLANE);
				 markerIDTextBox(false, OBJ_PLANE);
			 }
			 else if (ct == ControlType::INPUT)
			 {
				 rigidSetButton(false, false, OBJ_PLANE);
				 XYZTextBox(false, OBJ_PLANE);
				 getDataLabel(false, OBJ_PLANE);
				 getDataButton(false, OBJ_PLANE);
				 markerIDTextBox(false, OBJ_PLANE);
			 }

			 inputDirty = false;
		 }
private: System::Void boxPanel(ControlType ct, bool visible) {
			 if (!visible)
			 {
				 this->inputBoxPanel1->Visible = false;
				 return;
			 }

			 this->inputBoxPanel1->Visible = true;
			 if (ct == ControlType::MARKER)
			 {
				 XYZTextBox(true, OBJ_BOX);
				 getDataButton(true, OBJ_BOX);
				 markerIDTextBox(true, OBJ_BOX);
			 }
			 else if (ct == ControlType::RIGID)
			 {
				 XYZTextBox(true, OBJ_BOX);
				 getDataButton(true, OBJ_BOX);
				 markerIDTextBox(false, OBJ_BOX);
			 }
			 else if (ct == ControlType::INPUT)
			 {
				 XYZTextBox(false, OBJ_BOX);
				 getDataButton(false, OBJ_BOX);
				 markerIDTextBox(false, OBJ_BOX);
			 }
			 if (inputDirty)
			 {
				 this->boxLTextBox->Text = "";
				 this->boxWTextBox->Text = "";
				 this->boxHTextBox->Text = "";
			 }

			 inputDirty = false;
		 }
private: System::Void cylinderPanel(ControlType ct, bool visible) {
			 if (!visible)
			 {
				 this->inputCylinderPanel1->Visible = false;
				 return;
			 }
		 }
/////////////////////
// Wizard Navigation
private: System::Void page_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->wizardPages->SelectedIndex == 0)
			 {
				 this->nextButton->Enabled = true;
				 this->backButton->Enabled = false;
			 }
			 else
			 {   
				 this->backButton->Enabled = true;

				 // input page
				 // if page is last, show appropriate panel and change button text
				 if (this->wizardPages->SelectedIndex == this->wizardPages->TabCount -1)
				 {
					 planePanel(control, false);
					 boxPanel(control, false);
					 cylinderPanel(control, false);

					 if (objType == OBJ_PLANE)
						 planePanel(control, true);
					 else if (objType == OBJ_BOX)
						 boxPanel(control, true);
					 else if (objType == OBJ_CYLINDER)
						 cylinderPanel(control, true);

					 this->nextButton->Text = L"Create";
				 }
				 else
					 this->nextButton->Text = L"Next";

				 // check if coming back to valid page data
				 if ( (this->wizardPages->SelectedIndex == 1 && // parameters
					   this->controlComboBox->SelectedItem) ||
					  (this->wizardPages->SelectedIndex == this->wizardPages->TabCount -1 && // input
						  validateInputPage()) )
				 {
					 this->nextButton->Enabled = true;
				 }
				 else
					 this->nextButton->Enabled = false;			 
			 }
		 }
// Advances through the wizard
private: System::Void nextButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 // Check if at last index 
			 // create object and close wizard
			 if (this->wizardPages->SelectedIndex == this->wizardPages->TabCount - 1)
			 {
				 this->Close();
			 }
			 else
				 this->wizardPages->SelectedIndex++;
		 }
		 // Go to the previous page
private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->wizardPages->SelectedIndex > 0)
				 this->wizardPages->SelectedIndex--;
		 }
private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }

/////////////////////
// Validation
private: bool validateInputPage() {
			 switch (objType) {
			 case OBJ_PLANE :
				 return validatePlane();

			 case OBJ_BOX :
				 return validateBox();

			 case OBJ_CYLINDER :
				 return validateCylinder();

			 // case CUSTOM :

			 default:
				 return false;
			 }
		 }
private: bool validatePlane() {
			 return ( isFloat(this->planePt1XText->Text) && 
					  isFloat(this->planePt1YText->Text) && 
					  isFloat(this->planePt1ZText->Text) && 

					  isFloat(this->planeCornXText->Text) && 
					  isFloat(this->planeCornYText->Text) && 
					  isFloat(this->planeCornZText->Text) && 

					  isFloat(this->planePt2XText->Text) && 
					  isFloat(this->planePt2YText->Text) && 
					  isFloat(this->planePt2ZText->Text) );
		 }
private: bool validateBox() {
			 return ( isFloat(this->boxCenXText->Text) &&
					  isFloat(this->boxCenYText->Text) &&
					  isFloat(this->boxCenZText->Text) &&

					  isFloat(this->boxLTextBox->Text) &&
					  isFloat(this->boxWTextBox->Text) &&
					  isFloat(this->boxHTextBox->Text) );
		 }
private: bool validateCylinder() {
			 return true;
		 }

private: System::Void planeText_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 if (validatePlane())
				 this->nextButton->Enabled = true;
			 else
				 this->nextButton->Enabled = false;
		 }
private: System::Void boxText_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 if (validateBox())
				 this->nextButton->Enabled = true;
			 else
				 this->nextButton->Enabled = false;
		 }
/////////////////////
// populate fields
		 // posVec: which vector to get data from (0-2)
		 // posIdx: which set of coordinates to populate 
private: System::Void populateTextFromPosition(int posVec, int posIdx) {
			 osg::Vec3* temp;
			 switch (objType) {
				 // plane
			 case OBJ_PLANE :
				 //(1 = x-axis, 2 = y-axis, 0 other)
				 if (posIdx > 2 || posIdx < 0) return;
				 temp = posVec == 0 ? pos0 : 
								   posVec == 1 ? pos1 : 
								   posVec == 2 ? pos2 : NULL;
				 TextBox^ x;
				 TextBox^ y;
				 TextBox^ z;
				 if (posIdx == 0)
				 { 
					 x = this->planeCornXText;
					 y = this->planeCornYText;
					 z = this->planeCornZText;
				 }
				 else if (posIdx == 1)
				 {
					 x = this->planePt1XText;
					 y = this->planePt1YText;
					 z = this->planePt1ZText;
				 }
				 else 
				 {
					 x = this->planePt2XText;
					 y = this->planePt2YText;
					 z = this->planePt2ZText;
				 }

				 if (temp)
				 {
					 x->Text = temp->x().ToString();
					 y->Text = temp->y().ToString();
					 z->Text = temp->z().ToString();
				 }
				 else // reset to zero
				 {
					 x->Text = "";
					 y->Text = "";
					 z->Text = "";
				 }
				 break;
				 // box
			 case OBJ_BOX :
				 temp = posVec < 0 ? NULL : pos0;
				 
				 if (temp)
				 {
					 this->boxCenXText->Text = temp->x().ToString();
					 this->boxCenYText->Text = temp->y().ToString();
					 this->boxCenZText->Text = temp->z().ToString();
				 }
				 else // reset to zero
				 {
					 this->boxCenXText->Text = "";
					 this->boxCenYText->Text = "";
					 this->boxCenZText->Text = "";
				 }
				 break;
			 }
		 }
/////////////////////
// input data buttons
private: System::Void planeDataGetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			ClientHandler* client = AppData::getInstance()->getClient();
			// use markers
			if (control == ControlType::MARKER && client->lock())
			{
				Marker* marker;
				bool result;
				int id;
				this->nextButton->Enabled = true;
				
				// point 1
				result = Int32::TryParse(this->planeMPt1Text->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					this->nextButton->Enabled = false;
					populateTextFromPosition(-1, 1);
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					pos1->set(pt.x(), pt.y(), pt.z());
					populateTextFromPosition(1, 1);
				}
				
				// corner
				result = Int32::TryParse(this->planeMCornText->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					this->nextButton->Enabled = false;
					populateTextFromPosition(-1, 0);
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					pos0->set(pt.x(), pt.y(), pt.z());
					populateTextFromPosition(0, 0);
				}
				
				// point 2
				result = Int32::TryParse(this->planeMPt2Text->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					this->nextButton->Enabled = false;
					populateTextFromPosition(-1, 2);
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					pos2->set(pt.x(), pt.y(), pt.z());
					populateTextFromPosition(2, 2);
				}
				client->unlock();
			}
			// use rigid tool
			else if (control == ControlType::RIGID && client)
			{
				RigidBody* body = client->getRigidBody(client->getRigidBodyTool());
				if (body)
				{
					pos->set(body->getPosition().x(), 
							body->getPosition().y(), 
							body->getPosition().z());
					setPoint(pos, this->planeDataLabel);
					rigidSetButton(true, true, OBJ_PLANE);
					return;
				}
			}
		 }
private: System::Void planeDataSetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if (sender == this->planePt1SetButton)
			{
				pos1->set(pos->x(), pos->y(), pos->z());
				populateTextFromPosition(1, 1);
					 
				if ( validatePlane() )
					this->nextButton->Enabled = true;
				else
					this->nextButton->Enabled = false;
			}
			else if (sender == this->planeCornSetButton)
			{
				pos0->set(pos->x(), pos->y(), pos->z());
				populateTextFromPosition(0, 0);

				if ( validatePlane() )
					this->nextButton->Enabled = true;
				else
					this->nextButton->Enabled = false;
			}
			else if (sender == this->planePt2SetButton)
			{
				pos2->set(pos->x(), pos->y(), pos->z());
				populateTextFromPosition(2, 2);

				if ( validatePlane() )
					this->nextButton->Enabled = true;
				else
					this->nextButton->Enabled = false;
			}
		 }
private: System::Void boxDataGetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			ClientHandler* client = AppData::getInstance()->getClient();
			// use markers
			if (control == ControlType::MARKER && client->lock())
			{
				Marker* marker;
				bool result;
				int id;

				// base centre
				result = Int32::TryParse(this->boxMCenText->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					populateTextFromPosition(-1, 0);
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					pos0->set(pt.x(), pt.y(), pt.z());
					populateTextFromPosition(0, 0);
				}
				client->unlock();
			}
			// use rigid tool
			else if (control == ControlType::RIGID && client)
			{
				RigidBody* body = client->getRigidBody(client->getRigidBodyTool());
				if (body)
				{
					pos0->set(body->getPosition().x(), 
							body->getPosition().y(), 
							body->getPosition().z());
					populateTextFromPosition(0, 0);
				}
			}

			if (validateBox())
				this->nextButton->Enabled = true;
			else
				this->nextButton->Enabled = false;
	 }
};
}
