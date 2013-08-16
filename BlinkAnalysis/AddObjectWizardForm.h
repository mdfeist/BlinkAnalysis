#pragma once
#include "WizardPages.h"
#include "AppData.h"
#include "WorldManager.h"
#include "AddObjectDistanceForm.h"
#include "FormUtils.h"

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace FormUtils;

	enum class ControlType {
		MARKER,
		RIGID_TOOL,
		INPUT,
		RIGID_ATTACH,
		INVALID
	};

	/// <summary>
	/// Wizard for adding objects to a world
	/// </summary>
	public ref class AddObjectWizardForm : public System::Windows::Forms::Form
	{
	public:
		AddObjectWizardForm(void)
		{
			InitializeComponent();
			this->displayWorld = -1;
			this->objType = OBJ_INVALID;
			this->control = ControlType::INVALID;
			this->defaultDataText = L"No data found";
			this->inputDirty = false;

			pos = new osg::Vec3();
			pos0 = new osg::Vec3();
			pos1 = new osg::Vec3();
			pos2 = new osg::Vec3();
			quat = new osg::Quat();

			this->rigidBodyVector = NULL;
			this->rigidID = -1;
		}
		
		void selectWorld(int id) {
			displayWorld = id; 
		}
		int getDisplayWorld() { return displayWorld; }
		
		void setRigidBodyVector(std::vector<RigidBody*>* vector)
		{
			rigidBodyVector = vector;
		}
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
private: System::Windows::Forms::Label^  cylinDimLabel;
private: System::Windows::Forms::Label^  cylinMIDLabel;
private: System::Windows::Forms::TextBox^  cylinMCenText;
private: System::Windows::Forms::TextBox^  cylinCenZText;
private: System::Windows::Forms::TextBox^  cylinCenYText;
private: System::Windows::Forms::TextBox^  cylinCenXText;
private: System::Windows::Forms::Label^  cylinZLabel;
private: System::Windows::Forms::Label^  cylinYLabel;
private: System::Windows::Forms::Label^  cylinXLabel;
private: System::Windows::Forms::TextBox^  cylinHText;
private: System::Windows::Forms::TextBox^  cylinRText;
private: System::Windows::Forms::Label^  cylinHLabel;
private: System::Windows::Forms::Label^  cylinRLabel;

private: System::Windows::Forms::Button^  cylinDataGetButton;
private: System::Windows::Forms::Label^  cylinInfoLabel;
private: System::Windows::Forms::Label^  infoTitleLabel;
private: System::Windows::Forms::Label^  infoLabel;
private: System::Windows::Forms::Label^  paramInfoLabel;
private: System::Windows::Forms::Panel^  inputRigidPanel;


private: System::Windows::Forms::TextBox^  rigidWText;



private: System::Windows::Forms::Label^  rigidWLabel;

private: System::Windows::Forms::Label^  rigidDimLabel;

private: System::Windows::Forms::TextBox^  rigidCenZText;

private: System::Windows::Forms::TextBox^  rigidCenYText;

private: System::Windows::Forms::TextBox^  rigidCenXText;

private: System::Windows::Forms::Label^  rigidZLabel;

private: System::Windows::Forms::Label^  rigidYLabel;

private: System::Windows::Forms::Label^  rigidXLabel;
private: System::Windows::Forms::TextBox^  rigidHText;


private: System::Windows::Forms::TextBox^  rigidLText;
private: System::Windows::Forms::Label^  rigidHLabel;


private: System::Windows::Forms::Label^  rigidLLabel;



private: System::Windows::Forms::Label^  rigidObjInfoLabel;
private: System::Windows::Forms::ListView^  rigidListView;
private: System::Windows::Forms::CheckBox^  rigidAttachCheck;
private: System::Windows::Forms::ComboBox^  rigidCentreCombo;
private: System::Windows::Forms::Label^  rigidCentreLabel;
private: System::Windows::Forms::ComboBox^  cylinCentreCombo;

private: System::Windows::Forms::ComboBox^  boxCentreCombo;
private: System::Windows::Forms::Panel^  inputTemplatePanel;







private: System::Windows::Forms::Label^  tempRoteLabel;


private: System::Windows::Forms::TextBox^  tempCenZText;

private: System::Windows::Forms::TextBox^  tempCenYText;

private: System::Windows::Forms::TextBox^  tempCenXText;
private: System::Windows::Forms::Label^  tempCenZLabel;


private: System::Windows::Forms::Label^  tempCenYLabel;

private: System::Windows::Forms::Label^  tempCenXLabel;
private: System::Windows::Forms::TextBox^  tempQZText;

private: System::Windows::Forms::TextBox^  tempQXText;




private: System::Windows::Forms::Label^  tempInfoLabel;






private: System::Windows::Forms::Label^  tempRoteWLabel;




private: System::Windows::Forms::Label^  tempRoteYLabel;

private: System::Windows::Forms::Label^  tempRoteXLabel;
private: System::Windows::Forms::TextBox^  tempQWText;



private: System::Windows::Forms::Label^  tempFileLabel;
private: System::Windows::Forms::Button^  tempBrowseButton;


private: System::Windows::Forms::TextBox^  tempFilePathText;
private: System::Windows::Forms::TextBox^  tempMIDText;
private: System::Windows::Forms::Button^  tempDataGetButton;
private: System::Windows::Forms::TextBox^  tempQYText;






private: System::Windows::Forms::Label^  tempRoteZLabel;
private: System::Windows::Forms::Button^  rigidBrowseButton;
private: System::Windows::Forms::TextBox^  rigidFilePathText;
private: System::Windows::Forms::Label^  rigidTemplateFileLabel;
private: System::Windows::Forms::OpenFileDialog^  templateOpenFileDialog;
private: System::Windows::Forms::Label^  tempCenLabel;

















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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddObjectWizardForm::typeid));
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->nextButton = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->inputPage = (gcnew System::Windows::Forms::TabPage());
			this->inputTemplatePanel = (gcnew System::Windows::Forms::Panel());
			this->tempCenLabel = (gcnew System::Windows::Forms::Label());
			this->tempMIDText = (gcnew System::Windows::Forms::TextBox());
			this->tempDataGetButton = (gcnew System::Windows::Forms::Button());
			this->tempFileLabel = (gcnew System::Windows::Forms::Label());
			this->tempBrowseButton = (gcnew System::Windows::Forms::Button());
			this->tempFilePathText = (gcnew System::Windows::Forms::TextBox());
			this->tempRoteWLabel = (gcnew System::Windows::Forms::Label());
			this->tempRoteZLabel = (gcnew System::Windows::Forms::Label());
			this->tempRoteYLabel = (gcnew System::Windows::Forms::Label());
			this->tempRoteXLabel = (gcnew System::Windows::Forms::Label());
			this->tempQWText = (gcnew System::Windows::Forms::TextBox());
			this->tempQYText = (gcnew System::Windows::Forms::TextBox());
			this->tempRoteLabel = (gcnew System::Windows::Forms::Label());
			this->tempCenZText = (gcnew System::Windows::Forms::TextBox());
			this->tempCenYText = (gcnew System::Windows::Forms::TextBox());
			this->tempCenXText = (gcnew System::Windows::Forms::TextBox());
			this->tempCenZLabel = (gcnew System::Windows::Forms::Label());
			this->tempCenYLabel = (gcnew System::Windows::Forms::Label());
			this->tempCenXLabel = (gcnew System::Windows::Forms::Label());
			this->tempQZText = (gcnew System::Windows::Forms::TextBox());
			this->tempQXText = (gcnew System::Windows::Forms::TextBox());
			this->tempInfoLabel = (gcnew System::Windows::Forms::Label());
			this->inputRigidPanel = (gcnew System::Windows::Forms::Panel());
			this->rigidCentreCombo = (gcnew System::Windows::Forms::ComboBox());
			this->rigidAttachCheck = (gcnew System::Windows::Forms::CheckBox());
			this->rigidListView = (gcnew System::Windows::Forms::ListView());
			this->rigidWText = (gcnew System::Windows::Forms::TextBox());
			this->rigidWLabel = (gcnew System::Windows::Forms::Label());
			this->rigidDimLabel = (gcnew System::Windows::Forms::Label());
			this->rigidCenZText = (gcnew System::Windows::Forms::TextBox());
			this->rigidCenYText = (gcnew System::Windows::Forms::TextBox());
			this->rigidCenXText = (gcnew System::Windows::Forms::TextBox());
			this->rigidZLabel = (gcnew System::Windows::Forms::Label());
			this->rigidYLabel = (gcnew System::Windows::Forms::Label());
			this->rigidXLabel = (gcnew System::Windows::Forms::Label());
			this->rigidHText = (gcnew System::Windows::Forms::TextBox());
			this->rigidLText = (gcnew System::Windows::Forms::TextBox());
			this->rigidHLabel = (gcnew System::Windows::Forms::Label());
			this->rigidLLabel = (gcnew System::Windows::Forms::Label());
			this->rigidObjInfoLabel = (gcnew System::Windows::Forms::Label());
			this->rigidCentreLabel = (gcnew System::Windows::Forms::Label());
			this->rigidBrowseButton = (gcnew System::Windows::Forms::Button());
			this->rigidFilePathText = (gcnew System::Windows::Forms::TextBox());
			this->rigidTemplateFileLabel = (gcnew System::Windows::Forms::Label());
			this->inputCylinderPanel1 = (gcnew System::Windows::Forms::Panel());
			this->cylinCentreCombo = (gcnew System::Windows::Forms::ComboBox());
			this->cylinDimLabel = (gcnew System::Windows::Forms::Label());
			this->cylinMIDLabel = (gcnew System::Windows::Forms::Label());
			this->cylinMCenText = (gcnew System::Windows::Forms::TextBox());
			this->cylinCenZText = (gcnew System::Windows::Forms::TextBox());
			this->cylinCenYText = (gcnew System::Windows::Forms::TextBox());
			this->cylinCenXText = (gcnew System::Windows::Forms::TextBox());
			this->cylinZLabel = (gcnew System::Windows::Forms::Label());
			this->cylinYLabel = (gcnew System::Windows::Forms::Label());
			this->cylinXLabel = (gcnew System::Windows::Forms::Label());
			this->cylinHText = (gcnew System::Windows::Forms::TextBox());
			this->cylinRText = (gcnew System::Windows::Forms::TextBox());
			this->cylinHLabel = (gcnew System::Windows::Forms::Label());
			this->cylinRLabel = (gcnew System::Windows::Forms::Label());
			this->cylinDataGetButton = (gcnew System::Windows::Forms::Button());
			this->cylinInfoLabel = (gcnew System::Windows::Forms::Label());
			this->inputBoxPanel1 = (gcnew System::Windows::Forms::Panel());
			this->boxCentreCombo = (gcnew System::Windows::Forms::ComboBox());
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
			this->boxDataGetButton = (gcnew System::Windows::Forms::Button());
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
			this->paramPage = (gcnew System::Windows::Forms::TabPage());
			this->paramInfoLabel = (gcnew System::Windows::Forms::Label());
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
			this->infoTitleLabel = (gcnew System::Windows::Forms::Label());
			this->infoLabel = (gcnew System::Windows::Forms::Label());
			this->wizardPagesTemp = (gcnew System::Windows::Forms::TabControl());
			this->templateOpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->inputPage->SuspendLayout();
			this->inputTemplatePanel->SuspendLayout();
			this->inputRigidPanel->SuspendLayout();
			this->inputCylinderPanel1->SuspendLayout();
			this->inputBoxPanel1->SuspendLayout();
			this->inputPlanePanel->SuspendLayout();
			this->paramPage->SuspendLayout();
			this->introPage->SuspendLayout();
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
			this->inputPage->Controls->Add(this->inputTemplatePanel);
			this->inputPage->Controls->Add(this->inputRigidPanel);
			this->inputPage->Controls->Add(this->inputCylinderPanel1);
			this->inputPage->Controls->Add(this->inputBoxPanel1);
			this->inputPage->Controls->Add(this->inputPlanePanel);
			this->inputPage->Location = System::Drawing::Point(4, 22);
			this->inputPage->Name = L"inputPage";
			this->inputPage->Padding = System::Windows::Forms::Padding(3);
			this->inputPage->Size = System::Drawing::Size(511, 219);
			this->inputPage->TabIndex = 4;
			this->inputPage->Text = L"Input";
			this->inputPage->UseVisualStyleBackColor = true;
			// 
			// inputTemplatePanel
			// 
			this->inputTemplatePanel->Controls->Add(this->tempCenLabel);
			this->inputTemplatePanel->Controls->Add(this->tempMIDText);
			this->inputTemplatePanel->Controls->Add(this->tempDataGetButton);
			this->inputTemplatePanel->Controls->Add(this->tempFileLabel);
			this->inputTemplatePanel->Controls->Add(this->tempBrowseButton);
			this->inputTemplatePanel->Controls->Add(this->tempFilePathText);
			this->inputTemplatePanel->Controls->Add(this->tempRoteWLabel);
			this->inputTemplatePanel->Controls->Add(this->tempRoteZLabel);
			this->inputTemplatePanel->Controls->Add(this->tempRoteYLabel);
			this->inputTemplatePanel->Controls->Add(this->tempRoteXLabel);
			this->inputTemplatePanel->Controls->Add(this->tempQWText);
			this->inputTemplatePanel->Controls->Add(this->tempQYText);
			this->inputTemplatePanel->Controls->Add(this->tempRoteLabel);
			this->inputTemplatePanel->Controls->Add(this->tempCenZText);
			this->inputTemplatePanel->Controls->Add(this->tempCenYText);
			this->inputTemplatePanel->Controls->Add(this->tempCenXText);
			this->inputTemplatePanel->Controls->Add(this->tempCenZLabel);
			this->inputTemplatePanel->Controls->Add(this->tempCenYLabel);
			this->inputTemplatePanel->Controls->Add(this->tempCenXLabel);
			this->inputTemplatePanel->Controls->Add(this->tempQZText);
			this->inputTemplatePanel->Controls->Add(this->tempQXText);
			this->inputTemplatePanel->Controls->Add(this->tempInfoLabel);
			this->inputTemplatePanel->Location = System::Drawing::Point(0, 0);
			this->inputTemplatePanel->Name = L"inputTemplatePanel";
			this->inputTemplatePanel->Size = System::Drawing::Size(511, 219);
			this->inputTemplatePanel->TabIndex = 99;
			this->inputTemplatePanel->Visible = false;
			// 
			// tempCenLabel
			// 
			this->tempCenLabel->AutoSize = true;
			this->tempCenLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tempCenLabel->Location = System::Drawing::Point(26, 112);
			this->tempCenLabel->Name = L"tempCenLabel";
			this->tempCenLabel->Size = System::Drawing::Size(43, 15);
			this->tempCenLabel->TabIndex = 110;
			this->tempCenLabel->Text = L"Centre";
			// 
			// tempMIDText
			// 
			this->tempMIDText->Location = System::Drawing::Point(148, 111);
			this->tempMIDText->Name = L"tempMIDText";
			this->tempMIDText->Size = System::Drawing::Size(76, 20);
			this->tempMIDText->TabIndex = 109;
			// 
			// tempDataGetButton
			// 
			this->tempDataGetButton->Location = System::Drawing::Point(148, 87);
			this->tempDataGetButton->Name = L"tempDataGetButton";
			this->tempDataGetButton->Size = System::Drawing::Size(75, 21);
			this->tempDataGetButton->TabIndex = 108;
			this->tempDataGetButton->Text = L"Marker ID";
			this->tempDataGetButton->UseVisualStyleBackColor = true;
			this->tempDataGetButton->Click += gcnew System::EventHandler(this, &AddObjectWizardForm::tempDataGetButton_Click);
			// 
			// tempFileLabel
			// 
			this->tempFileLabel->AutoSize = true;
			this->tempFileLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tempFileLabel->Location = System::Drawing::Point(26, 59);
			this->tempFileLabel->Name = L"tempFileLabel";
			this->tempFileLabel->Size = System::Drawing::Size(82, 15);
			this->tempFileLabel->TabIndex = 107;
			this->tempFileLabel->Text = L"Template File";
			// 
			// tempBrowseButton
			// 
			this->tempBrowseButton->Location = System::Drawing::Point(402, 56);
			this->tempBrowseButton->Name = L"tempBrowseButton";
			this->tempBrowseButton->Size = System::Drawing::Size(75, 23);
			this->tempBrowseButton->TabIndex = 106;
			this->tempBrowseButton->Text = L"Browse";
			this->tempBrowseButton->UseVisualStyleBackColor = true;
			this->tempBrowseButton->Click += gcnew System::EventHandler(this, &AddObjectWizardForm::tempBrowseButton_Click);
			// 
			// tempFilePathText
			// 
			this->tempFilePathText->Enabled = false;
			this->tempFilePathText->Location = System::Drawing::Point(148, 58);
			this->tempFilePathText->Name = L"tempFilePathText";
			this->tempFilePathText->ReadOnly = true;
			this->tempFilePathText->Size = System::Drawing::Size(248, 20);
			this->tempFilePathText->TabIndex = 105;
			// 
			// tempRoteWLabel
			// 
			this->tempRoteWLabel->AutoSize = true;
			this->tempRoteWLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tempRoteWLabel->Location = System::Drawing::Point(448, 141);
			this->tempRoteWLabel->Name = L"tempRoteWLabel";
			this->tempRoteWLabel->Size = System::Drawing::Size(19, 15);
			this->tempRoteWLabel->TabIndex = 104;
			this->tempRoteWLabel->Text = L"W";
			// 
			// tempRoteZLabel
			// 
			this->tempRoteZLabel->AutoSize = true;
			this->tempRoteZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tempRoteZLabel->Location = System::Drawing::Point(361, 141);
			this->tempRoteZLabel->Name = L"tempRoteZLabel";
			this->tempRoteZLabel->Size = System::Drawing::Size(15, 15);
			this->tempRoteZLabel->TabIndex = 103;
			this->tempRoteZLabel->Text = L"Z";
			// 
			// tempRoteYLabel
			// 
			this->tempRoteYLabel->AutoSize = true;
			this->tempRoteYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tempRoteYLabel->Location = System::Drawing::Point(269, 141);
			this->tempRoteYLabel->Name = L"tempRoteYLabel";
			this->tempRoteYLabel->Size = System::Drawing::Size(15, 15);
			this->tempRoteYLabel->TabIndex = 102;
			this->tempRoteYLabel->Text = L"Y";
			// 
			// tempRoteXLabel
			// 
			this->tempRoteXLabel->AutoSize = true;
			this->tempRoteXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tempRoteXLabel->Location = System::Drawing::Point(181, 141);
			this->tempRoteXLabel->Name = L"tempRoteXLabel";
			this->tempRoteXLabel->Size = System::Drawing::Size(16, 15);
			this->tempRoteXLabel->TabIndex = 101;
			this->tempRoteXLabel->Text = L"X";
			// 
			// tempQWText
			// 
			this->tempQWText->Location = System::Drawing::Point(415, 159);
			this->tempQWText->Name = L"tempQWText";
			this->tempQWText->Size = System::Drawing::Size(83, 20);
			this->tempQWText->TabIndex = 91;
			this->tempQWText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// tempQYText
			// 
			this->tempQYText->Location = System::Drawing::Point(237, 159);
			this->tempQYText->Name = L"tempQYText";
			this->tempQYText->Size = System::Drawing::Size(83, 20);
			this->tempQYText->TabIndex = 89;
			this->tempQYText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// tempRoteLabel
			// 
			this->tempRoteLabel->AutoSize = true;
			this->tempRoteLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tempRoteLabel->Location = System::Drawing::Point(26, 160);
			this->tempRoteLabel->Name = L"tempRoteLabel";
			this->tempRoteLabel->Size = System::Drawing::Size(67, 15);
			this->tempRoteLabel->TabIndex = 92;
			this->tempRoteLabel->Text = L"Orientation";
			// 
			// tempCenZText
			// 
			this->tempCenZText->Location = System::Drawing::Point(415, 111);
			this->tempCenZText->Name = L"tempCenZText";
			this->tempCenZText->Size = System::Drawing::Size(83, 20);
			this->tempCenZText->TabIndex = 83;
			this->tempCenZText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// tempCenYText
			// 
			this->tempCenYText->Location = System::Drawing::Point(326, 111);
			this->tempCenYText->Name = L"tempCenYText";
			this->tempCenYText->Size = System::Drawing::Size(83, 20);
			this->tempCenYText->TabIndex = 82;
			this->tempCenYText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// tempCenXText
			// 
			this->tempCenXText->Location = System::Drawing::Point(237, 111);
			this->tempCenXText->Name = L"tempCenXText";
			this->tempCenXText->Size = System::Drawing::Size(83, 20);
			this->tempCenXText->TabIndex = 81;
			this->tempCenXText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// tempCenZLabel
			// 
			this->tempCenZLabel->AutoSize = true;
			this->tempCenZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tempCenZLabel->Location = System::Drawing::Point(450, 93);
			this->tempCenZLabel->Name = L"tempCenZLabel";
			this->tempCenZLabel->Size = System::Drawing::Size(15, 15);
			this->tempCenZLabel->TabIndex = 86;
			this->tempCenZLabel->Text = L"Z";
			// 
			// tempCenYLabel
			// 
			this->tempCenYLabel->AutoSize = true;
			this->tempCenYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tempCenYLabel->Location = System::Drawing::Point(358, 93);
			this->tempCenYLabel->Name = L"tempCenYLabel";
			this->tempCenYLabel->Size = System::Drawing::Size(15, 15);
			this->tempCenYLabel->TabIndex = 85;
			this->tempCenYLabel->Text = L"Y";
			// 
			// tempCenXLabel
			// 
			this->tempCenXLabel->AutoSize = true;
			this->tempCenXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tempCenXLabel->Location = System::Drawing::Point(270, 93);
			this->tempCenXLabel->Name = L"tempCenXLabel";
			this->tempCenXLabel->Size = System::Drawing::Size(16, 15);
			this->tempCenXLabel->TabIndex = 84;
			this->tempCenXLabel->Text = L"X";
			// 
			// tempQZText
			// 
			this->tempQZText->Location = System::Drawing::Point(326, 159);
			this->tempQZText->Name = L"tempQZText";
			this->tempQZText->Size = System::Drawing::Size(83, 20);
			this->tempQZText->TabIndex = 90;
			this->tempQZText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// tempQXText
			// 
			this->tempQXText->Location = System::Drawing::Point(148, 159);
			this->tempQXText->Name = L"tempQXText";
			this->tempQXText->Size = System::Drawing::Size(83, 20);
			this->tempQXText->TabIndex = 88;
			this->tempQXText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// tempInfoLabel
			// 
			this->tempInfoLabel->AutoSize = true;
			this->tempInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tempInfoLabel->Location = System::Drawing::Point(18, 13);
			this->tempInfoLabel->Name = L"tempInfoLabel";
			this->tempInfoLabel->Size = System::Drawing::Size(198, 15);
			this->tempInfoLabel->TabIndex = 55;
			this->tempInfoLabel->Text = L"Add a templated object to the world";
			// 
			// inputRigidPanel
			// 
			this->inputRigidPanel->Controls->Add(this->rigidCentreCombo);
			this->inputRigidPanel->Controls->Add(this->rigidAttachCheck);
			this->inputRigidPanel->Controls->Add(this->rigidListView);
			this->inputRigidPanel->Controls->Add(this->rigidWText);
			this->inputRigidPanel->Controls->Add(this->rigidWLabel);
			this->inputRigidPanel->Controls->Add(this->rigidDimLabel);
			this->inputRigidPanel->Controls->Add(this->rigidCenZText);
			this->inputRigidPanel->Controls->Add(this->rigidCenYText);
			this->inputRigidPanel->Controls->Add(this->rigidCenXText);
			this->inputRigidPanel->Controls->Add(this->rigidZLabel);
			this->inputRigidPanel->Controls->Add(this->rigidYLabel);
			this->inputRigidPanel->Controls->Add(this->rigidXLabel);
			this->inputRigidPanel->Controls->Add(this->rigidHText);
			this->inputRigidPanel->Controls->Add(this->rigidLText);
			this->inputRigidPanel->Controls->Add(this->rigidHLabel);
			this->inputRigidPanel->Controls->Add(this->rigidLLabel);
			this->inputRigidPanel->Controls->Add(this->rigidObjInfoLabel);
			this->inputRigidPanel->Controls->Add(this->rigidCentreLabel);
			this->inputRigidPanel->Controls->Add(this->rigidBrowseButton);
			this->inputRigidPanel->Controls->Add(this->rigidFilePathText);
			this->inputRigidPanel->Controls->Add(this->rigidTemplateFileLabel);
			this->inputRigidPanel->Location = System::Drawing::Point(0, 0);
			this->inputRigidPanel->Name = L"inputRigidPanel";
			this->inputRigidPanel->Size = System::Drawing::Size(511, 219);
			this->inputRigidPanel->TabIndex = 6;
			this->inputRigidPanel->Visible = false;
			// 
			// rigidCentreCombo
			// 
			this->rigidCentreCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->rigidCentreCombo->FormattingEnabled = true;
			this->rigidCentreCombo->Location = System::Drawing::Point(232, 42);
			this->rigidCentreCombo->Name = L"rigidCentreCombo";
			this->rigidCentreCombo->Size = System::Drawing::Size(121, 21);
			this->rigidCentreCombo->TabIndex = 97;
			// 
			// rigidAttachCheck
			// 
			this->rigidAttachCheck->AutoSize = true;
			this->rigidAttachCheck->Location = System::Drawing::Point(32, 193);
			this->rigidAttachCheck->Name = L"rigidAttachCheck";
			this->rigidAttachCheck->Size = System::Drawing::Size(117, 17);
			this->rigidAttachCheck->TabIndex = 96;
			this->rigidAttachCheck->Text = L"Attach to rigid body";
			this->rigidAttachCheck->UseVisualStyleBackColor = true;
			// 
			// rigidListView
			// 
			this->rigidListView->Alignment = System::Windows::Forms::ListViewAlignment::Left;
			this->rigidListView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->rigidListView->FullRowSelect = true;
			this->rigidListView->HideSelection = false;
			this->rigidListView->LabelWrap = false;
			this->rigidListView->Location = System::Drawing::Point(21, 43);
			this->rigidListView->MultiSelect = false;
			this->rigidListView->Name = L"rigidListView";
			this->rigidListView->Size = System::Drawing::Size(203, 144);
			this->rigidListView->TabIndex = 95;
			this->rigidListView->TileSize = System::Drawing::Size(100, 20);
			this->rigidListView->UseCompatibleStateImageBehavior = false;
			this->rigidListView->View = System::Windows::Forms::View::SmallIcon;
			this->rigidListView->SelectedIndexChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::rigidListView_SelectedIndexChanged);
			// 
			// rigidWText
			// 
			this->rigidWText->Location = System::Drawing::Point(321, 178);
			this->rigidWText->Name = L"rigidWText";
			this->rigidWText->Size = System::Drawing::Size(83, 20);
			this->rigidWText->TabIndex = 89;
			this->rigidWText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			this->rigidWText->DoubleClick += gcnew System::EventHandler(this, &AddObjectWizardForm::textInput_Click);
			// 
			// rigidWLabel
			// 
			this->rigidWLabel->AutoSize = true;
			this->rigidWLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidWLabel->Location = System::Drawing::Point(318, 160);
			this->rigidWLabel->Name = L"rigidWLabel";
			this->rigidWLabel->Size = System::Drawing::Size(65, 15);
			this->rigidWLabel->TabIndex = 94;
			this->rigidWLabel->Text = L"Width (Y)";
			// 
			// rigidDimLabel
			// 
			this->rigidDimLabel->AutoSize = true;
			this->rigidDimLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidDimLabel->Location = System::Drawing::Point(229, 131);
			this->rigidDimLabel->Name = L"rigidDimLabel";
			this->rigidDimLabel->Size = System::Drawing::Size(73, 15);
			this->rigidDimLabel->TabIndex = 92;
			this->rigidDimLabel->Text = L"Dimensions";
			// 
			// rigidCenZText
			// 
			this->rigidCenZText->Location = System::Drawing::Point(410, 85);
			this->rigidCenZText->Name = L"rigidCenZText";
			this->rigidCenZText->ReadOnly = true;
			this->rigidCenZText->Size = System::Drawing::Size(83, 20);
			this->rigidCenZText->TabIndex = 83;
			this->rigidCenZText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// rigidCenYText
			// 
			this->rigidCenYText->Location = System::Drawing::Point(321, 85);
			this->rigidCenYText->Name = L"rigidCenYText";
			this->rigidCenYText->ReadOnly = true;
			this->rigidCenYText->Size = System::Drawing::Size(83, 20);
			this->rigidCenYText->TabIndex = 82;
			this->rigidCenYText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// rigidCenXText
			// 
			this->rigidCenXText->Location = System::Drawing::Point(232, 85);
			this->rigidCenXText->Name = L"rigidCenXText";
			this->rigidCenXText->ReadOnly = true;
			this->rigidCenXText->Size = System::Drawing::Size(83, 20);
			this->rigidCenXText->TabIndex = 81;
			this->rigidCenXText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// rigidZLabel
			// 
			this->rigidZLabel->AutoSize = true;
			this->rigidZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidZLabel->Location = System::Drawing::Point(445, 67);
			this->rigidZLabel->Name = L"rigidZLabel";
			this->rigidZLabel->Size = System::Drawing::Size(15, 15);
			this->rigidZLabel->TabIndex = 86;
			this->rigidZLabel->Text = L"Z";
			// 
			// rigidYLabel
			// 
			this->rigidYLabel->AutoSize = true;
			this->rigidYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidYLabel->Location = System::Drawing::Point(353, 67);
			this->rigidYLabel->Name = L"rigidYLabel";
			this->rigidYLabel->Size = System::Drawing::Size(15, 15);
			this->rigidYLabel->TabIndex = 85;
			this->rigidYLabel->Text = L"Y";
			// 
			// rigidXLabel
			// 
			this->rigidXLabel->AutoSize = true;
			this->rigidXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidXLabel->Location = System::Drawing::Point(265, 67);
			this->rigidXLabel->Name = L"rigidXLabel";
			this->rigidXLabel->Size = System::Drawing::Size(16, 15);
			this->rigidXLabel->TabIndex = 84;
			this->rigidXLabel->Text = L"X";
			// 
			// rigidHText
			// 
			this->rigidHText->Location = System::Drawing::Point(410, 178);
			this->rigidHText->Name = L"rigidHText";
			this->rigidHText->Size = System::Drawing::Size(83, 20);
			this->rigidHText->TabIndex = 90;
			this->rigidHText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			this->rigidHText->DoubleClick += gcnew System::EventHandler(this, &AddObjectWizardForm::textInput_Click);
			// 
			// rigidLText
			// 
			this->rigidLText->Location = System::Drawing::Point(232, 178);
			this->rigidLText->Name = L"rigidLText";
			this->rigidLText->Size = System::Drawing::Size(83, 20);
			this->rigidLText->TabIndex = 88;
			this->rigidLText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			this->rigidLText->DoubleClick += gcnew System::EventHandler(this, &AddObjectWizardForm::textInput_Click);
			// 
			// rigidHLabel
			// 
			this->rigidHLabel->AutoSize = true;
			this->rigidHLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidHLabel->Location = System::Drawing::Point(407, 160);
			this->rigidHLabel->Name = L"rigidHLabel";
			this->rigidHLabel->Size = System::Drawing::Size(71, 15);
			this->rigidHLabel->TabIndex = 80;
			this->rigidHLabel->Text = L"Height (Z)";
			// 
			// rigidLLabel
			// 
			this->rigidLLabel->AutoSize = true;
			this->rigidLLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidLLabel->Location = System::Drawing::Point(229, 160);
			this->rigidLLabel->Name = L"rigidLLabel";
			this->rigidLLabel->Size = System::Drawing::Size(74, 15);
			this->rigidLLabel->TabIndex = 78;
			this->rigidLLabel->Text = L"Length (X)";
			// 
			// rigidObjInfoLabel
			// 
			this->rigidObjInfoLabel->AutoSize = true;
			this->rigidObjInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidObjInfoLabel->Location = System::Drawing::Point(18, 19);
			this->rigidObjInfoLabel->Name = L"rigidObjInfoLabel";
			this->rigidObjInfoLabel->Size = System::Drawing::Size(149, 15);
			this->rigidObjInfoLabel->TabIndex = 55;
			this->rigidObjInfoLabel->Text = L"Add a cylinder to the world";
			// 
			// rigidCentreLabel
			// 
			this->rigidCentreLabel->AutoSize = true;
			this->rigidCentreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidCentreLabel->Location = System::Drawing::Point(230, 48);
			this->rigidCentreLabel->Name = L"rigidCentreLabel";
			this->rigidCentreLabel->Size = System::Drawing::Size(43, 15);
			this->rigidCentreLabel->TabIndex = 98;
			this->rigidCentreLabel->Text = L"Centre";
			// 
			// rigidBrowseButton
			// 
			this->rigidBrowseButton->Location = System::Drawing::Point(420, 176);
			this->rigidBrowseButton->Name = L"rigidBrowseButton";
			this->rigidBrowseButton->Size = System::Drawing::Size(75, 23);
			this->rigidBrowseButton->TabIndex = 109;
			this->rigidBrowseButton->Text = L"Browse";
			this->rigidBrowseButton->UseVisualStyleBackColor = true;
			this->rigidBrowseButton->Click += gcnew System::EventHandler(this, &AddObjectWizardForm::rigidBrowseButton_Click);
			// 
			// rigidFilePathText
			// 
			this->rigidFilePathText->Enabled = false;
			this->rigidFilePathText->Location = System::Drawing::Point(232, 178);
			this->rigidFilePathText->Name = L"rigidFilePathText";
			this->rigidFilePathText->ReadOnly = true;
			this->rigidFilePathText->Size = System::Drawing::Size(172, 20);
			this->rigidFilePathText->TabIndex = 108;
			// 
			// rigidTemplateFileLabel
			// 
			this->rigidTemplateFileLabel->AutoSize = true;
			this->rigidTemplateFileLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rigidTemplateFileLabel->Location = System::Drawing::Point(230, 131);
			this->rigidTemplateFileLabel->Name = L"rigidTemplateFileLabel";
			this->rigidTemplateFileLabel->Size = System::Drawing::Size(82, 15);
			this->rigidTemplateFileLabel->TabIndex = 110;
			this->rigidTemplateFileLabel->Text = L"Template File";
			// 
			// inputCylinderPanel1
			// 
			this->inputCylinderPanel1->Controls->Add(this->cylinCentreCombo);
			this->inputCylinderPanel1->Controls->Add(this->cylinDimLabel);
			this->inputCylinderPanel1->Controls->Add(this->cylinMIDLabel);
			this->inputCylinderPanel1->Controls->Add(this->cylinMCenText);
			this->inputCylinderPanel1->Controls->Add(this->cylinCenZText);
			this->inputCylinderPanel1->Controls->Add(this->cylinCenYText);
			this->inputCylinderPanel1->Controls->Add(this->cylinCenXText);
			this->inputCylinderPanel1->Controls->Add(this->cylinZLabel);
			this->inputCylinderPanel1->Controls->Add(this->cylinYLabel);
			this->inputCylinderPanel1->Controls->Add(this->cylinXLabel);
			this->inputCylinderPanel1->Controls->Add(this->cylinHText);
			this->inputCylinderPanel1->Controls->Add(this->cylinRText);
			this->inputCylinderPanel1->Controls->Add(this->cylinHLabel);
			this->inputCylinderPanel1->Controls->Add(this->cylinRLabel);
			this->inputCylinderPanel1->Controls->Add(this->cylinDataGetButton);
			this->inputCylinderPanel1->Controls->Add(this->cylinInfoLabel);
			this->inputCylinderPanel1->Location = System::Drawing::Point(0, 0);
			this->inputCylinderPanel1->Name = L"inputCylinderPanel1";
			this->inputCylinderPanel1->Size = System::Drawing::Size(511, 219);
			this->inputCylinderPanel1->TabIndex = 2;
			this->inputCylinderPanel1->Visible = false;
			// 
			// cylinCentreCombo
			// 
			this->cylinCentreCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cylinCentreCombo->FormattingEnabled = true;
			this->cylinCentreCombo->Location = System::Drawing::Point(28, 51);
			this->cylinCentreCombo->Name = L"cylinCentreCombo";
			this->cylinCentreCombo->Size = System::Drawing::Size(121, 21);
			this->cylinCentreCombo->TabIndex = 98;
			// 
			// cylinDimLabel
			// 
			this->cylinDimLabel->AutoSize = true;
			this->cylinDimLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cylinDimLabel->Location = System::Drawing::Point(25, 160);
			this->cylinDimLabel->Name = L"cylinDimLabel";
			this->cylinDimLabel->Size = System::Drawing::Size(73, 15);
			this->cylinDimLabel->TabIndex = 92;
			this->cylinDimLabel->Text = L"Dimensions";
			// 
			// cylinMIDLabel
			// 
			this->cylinMIDLabel->AutoSize = true;
			this->cylinMIDLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cylinMIDLabel->Location = System::Drawing::Point(39, 108);
			this->cylinMIDLabel->Name = L"cylinMIDLabel";
			this->cylinMIDLabel->Size = System::Drawing::Size(70, 15);
			this->cylinMIDLabel->TabIndex = 91;
			this->cylinMIDLabel->Text = L"Marker ID";
			// 
			// cylinMCenText
			// 
			this->cylinMCenText->Location = System::Drawing::Point(42, 126);
			this->cylinMCenText->Name = L"cylinMCenText";
			this->cylinMCenText->Size = System::Drawing::Size(76, 20);
			this->cylinMCenText->TabIndex = 87;
			// 
			// cylinCenZText
			// 
			this->cylinCenZText->Location = System::Drawing::Point(321, 84);
			this->cylinCenZText->Name = L"cylinCenZText";
			this->cylinCenZText->Size = System::Drawing::Size(83, 20);
			this->cylinCenZText->TabIndex = 83;
			this->cylinCenZText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// cylinCenYText
			// 
			this->cylinCenYText->Location = System::Drawing::Point(232, 84);
			this->cylinCenYText->Name = L"cylinCenYText";
			this->cylinCenYText->Size = System::Drawing::Size(83, 20);
			this->cylinCenYText->TabIndex = 82;
			this->cylinCenYText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// cylinCenXText
			// 
			this->cylinCenXText->Location = System::Drawing::Point(143, 84);
			this->cylinCenXText->Name = L"cylinCenXText";
			this->cylinCenXText->Size = System::Drawing::Size(83, 20);
			this->cylinCenXText->TabIndex = 81;
			this->cylinCenXText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// cylinZLabel
			// 
			this->cylinZLabel->AutoSize = true;
			this->cylinZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cylinZLabel->Location = System::Drawing::Point(356, 66);
			this->cylinZLabel->Name = L"cylinZLabel";
			this->cylinZLabel->Size = System::Drawing::Size(15, 15);
			this->cylinZLabel->TabIndex = 86;
			this->cylinZLabel->Text = L"Z";
			// 
			// cylinYLabel
			// 
			this->cylinYLabel->AutoSize = true;
			this->cylinYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cylinYLabel->Location = System::Drawing::Point(264, 66);
			this->cylinYLabel->Name = L"cylinYLabel";
			this->cylinYLabel->Size = System::Drawing::Size(15, 15);
			this->cylinYLabel->TabIndex = 85;
			this->cylinYLabel->Text = L"Y";
			// 
			// cylinXLabel
			// 
			this->cylinXLabel->AutoSize = true;
			this->cylinXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cylinXLabel->Location = System::Drawing::Point(176, 66);
			this->cylinXLabel->Name = L"cylinXLabel";
			this->cylinXLabel->Size = System::Drawing::Size(16, 15);
			this->cylinXLabel->TabIndex = 84;
			this->cylinXLabel->Text = L"X";
			// 
			// cylinHText
			// 
			this->cylinHText->Location = System::Drawing::Point(321, 178);
			this->cylinHText->Name = L"cylinHText";
			this->cylinHText->Size = System::Drawing::Size(83, 20);
			this->cylinHText->TabIndex = 89;
			this->cylinHText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			this->cylinHText->DoubleClick += gcnew System::EventHandler(this, &AddObjectWizardForm::textInput_Click);
			// 
			// cylinRText
			// 
			this->cylinRText->Location = System::Drawing::Point(143, 178);
			this->cylinRText->Name = L"cylinRText";
			this->cylinRText->Size = System::Drawing::Size(83, 20);
			this->cylinRText->TabIndex = 88;
			this->cylinRText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			this->cylinRText->DoubleClick += gcnew System::EventHandler(this, &AddObjectWizardForm::textInput_Click);
			// 
			// cylinHLabel
			// 
			this->cylinHLabel->AutoSize = true;
			this->cylinHLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cylinHLabel->Location = System::Drawing::Point(318, 160);
			this->cylinHLabel->Name = L"cylinHLabel";
			this->cylinHLabel->Size = System::Drawing::Size(71, 15);
			this->cylinHLabel->TabIndex = 80;
			this->cylinHLabel->Text = L"Height (Z)";
			// 
			// cylinRLabel
			// 
			this->cylinRLabel->AutoSize = true;
			this->cylinRLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cylinRLabel->Location = System::Drawing::Point(140, 160);
			this->cylinRLabel->Name = L"cylinRLabel";
			this->cylinRLabel->Size = System::Drawing::Size(91, 15);
			this->cylinRLabel->TabIndex = 78;
			this->cylinRLabel->Text = L"Radius (X, Y)";
			// 
			// cylinDataGetButton
			// 
			this->cylinDataGetButton->Location = System::Drawing::Point(42, 82);
			this->cylinDataGetButton->Name = L"cylinDataGetButton";
			this->cylinDataGetButton->Size = System::Drawing::Size(75, 23);
			this->cylinDataGetButton->TabIndex = 76;
			this->cylinDataGetButton->Text = L"Get Data";
			this->cylinDataGetButton->UseVisualStyleBackColor = true;
			this->cylinDataGetButton->Click += gcnew System::EventHandler(this, &AddObjectWizardForm::cylinDataGetButton_Click);
			// 
			// cylinInfoLabel
			// 
			this->cylinInfoLabel->AutoSize = true;
			this->cylinInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cylinInfoLabel->Location = System::Drawing::Point(18, 19);
			this->cylinInfoLabel->Name = L"cylinInfoLabel";
			this->cylinInfoLabel->Size = System::Drawing::Size(149, 15);
			this->cylinInfoLabel->TabIndex = 55;
			this->cylinInfoLabel->Text = L"Add a cylinder to the world";
			// 
			// inputBoxPanel1
			// 
			this->inputBoxPanel1->Controls->Add(this->boxCentreCombo);
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
			this->inputBoxPanel1->Controls->Add(this->boxDataGetButton);
			this->inputBoxPanel1->Location = System::Drawing::Point(0, 0);
			this->inputBoxPanel1->Name = L"inputBoxPanel1";
			this->inputBoxPanel1->Size = System::Drawing::Size(511, 219);
			this->inputBoxPanel1->TabIndex = 1;
			// 
			// boxCentreCombo
			// 
			this->boxCentreCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->boxCentreCombo->FormattingEnabled = true;
			this->boxCentreCombo->Location = System::Drawing::Point(28, 51);
			this->boxCentreCombo->Name = L"boxCentreCombo";
			this->boxCentreCombo->Size = System::Drawing::Size(121, 21);
			this->boxCentreCombo->TabIndex = 99;
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
			this->boxCenZText->TabIndex = 65;
			this->boxCenZText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// boxCenYText
			// 
			this->boxCenYText->Location = System::Drawing::Point(232, 84);
			this->boxCenYText->Name = L"boxCenYText";
			this->boxCenYText->Size = System::Drawing::Size(83, 20);
			this->boxCenYText->TabIndex = 64;
			this->boxCenYText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// boxCenXText
			// 
			this->boxCenXText->Location = System::Drawing::Point(143, 84);
			this->boxCenXText->Name = L"boxCenXText";
			this->boxCenXText->Size = System::Drawing::Size(83, 20);
			this->boxCenXText->TabIndex = 63;
			this->boxCenXText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
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
			this->boxHTextBox->TabIndex = 72;
			this->boxHTextBox->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			this->boxHTextBox->DoubleClick += gcnew System::EventHandler(this, &AddObjectWizardForm::textInput_Click);
			// 
			// boxWTextBox
			// 
			this->boxWTextBox->Location = System::Drawing::Point(232, 178);
			this->boxWTextBox->Name = L"boxWTextBox";
			this->boxWTextBox->Size = System::Drawing::Size(83, 20);
			this->boxWTextBox->TabIndex = 71;
			this->boxWTextBox->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			this->boxWTextBox->DoubleClick += gcnew System::EventHandler(this, &AddObjectWizardForm::textInput_Click);
			// 
			// boxLTextBox
			// 
			this->boxLTextBox->Location = System::Drawing::Point(143, 178);
			this->boxLTextBox->Name = L"boxLTextBox";
			this->boxLTextBox->Size = System::Drawing::Size(83, 20);
			this->boxLTextBox->TabIndex = 70;
			this->boxLTextBox->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			this->boxLTextBox->DoubleClick += gcnew System::EventHandler(this, &AddObjectWizardForm::textInput_Click);
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
			// inputPlanePanel
			// 
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
			this->planePt2ZText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// planePt2YText
			// 
			this->planePt2YText->Location = System::Drawing::Point(255, 175);
			this->planePt2YText->Name = L"planePt2YText";
			this->planePt2YText->Size = System::Drawing::Size(76, 20);
			this->planePt2YText->TabIndex = 62;
			this->planePt2YText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// planeCornZText
			// 
			this->planeCornZText->Location = System::Drawing::Point(337, 149);
			this->planeCornZText->Name = L"planeCornZText";
			this->planeCornZText->Size = System::Drawing::Size(76, 20);
			this->planeCornZText->TabIndex = 60;
			this->planeCornZText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// planeCornYText
			// 
			this->planeCornYText->Location = System::Drawing::Point(255, 149);
			this->planeCornYText->Name = L"planeCornYText";
			this->planeCornYText->Size = System::Drawing::Size(76, 20);
			this->planeCornYText->TabIndex = 59;
			this->planeCornYText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// planePt1ZText
			// 
			this->planePt1ZText->Location = System::Drawing::Point(337, 123);
			this->planePt1ZText->Name = L"planePt1ZText";
			this->planePt1ZText->Size = System::Drawing::Size(76, 20);
			this->planePt1ZText->TabIndex = 57;
			this->planePt1ZText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// planePt1YText
			// 
			this->planePt1YText->Location = System::Drawing::Point(255, 123);
			this->planePt1YText->Name = L"planePt1YText";
			this->planePt1YText->Size = System::Drawing::Size(76, 20);
			this->planePt1YText->TabIndex = 56;
			this->planePt1YText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
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
			this->planePt2XText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// planeCornXText
			// 
			this->planeCornXText->Location = System::Drawing::Point(173, 149);
			this->planeCornXText->Name = L"planeCornXText";
			this->planeCornXText->Size = System::Drawing::Size(76, 20);
			this->planeCornXText->TabIndex = 58;
			this->planeCornXText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
			// 
			// planePt1XText
			// 
			this->planePt1XText->Location = System::Drawing::Point(173, 123);
			this->planePt1XText->Name = L"planePt1XText";
			this->planePt1XText->Size = System::Drawing::Size(76, 20);
			this->planePt1XText->TabIndex = 55;
			this->planePt1XText->TextChanged += gcnew System::EventHandler(this, &AddObjectWizardForm::inputText_Validating);
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
			// paramPage
			// 
			this->paramPage->Controls->Add(this->paramInfoLabel);
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
			// paramInfoLabel
			// 
			this->paramInfoLabel->AutoSize = true;
			this->paramInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->paramInfoLabel->Location = System::Drawing::Point(12, 14);
			this->paramInfoLabel->Name = L"paramInfoLabel";
			this->paramInfoLabel->Size = System::Drawing::Size(301, 15);
			this->paramInfoLabel->TabIndex = 31;
			this->paramInfoLabel->Text = L"Complete information for the object you wish to create.";
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
			this->introPage->Controls->Add(this->infoTitleLabel);
			this->introPage->Controls->Add(this->infoLabel);
			this->introPage->Location = System::Drawing::Point(4, 22);
			this->introPage->Name = L"introPage";
			this->introPage->Padding = System::Windows::Forms::Padding(3);
			this->introPage->Size = System::Drawing::Size(511, 219);
			this->introPage->TabIndex = 0;
			this->introPage->Text = L"Info";
			this->introPage->UseVisualStyleBackColor = true;
			// 
			// infoTitleLabel
			// 
			this->infoTitleLabel->AutoSize = true;
			this->infoTitleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->infoTitleLabel->Location = System::Drawing::Point(8, 3);
			this->infoTitleLabel->Name = L"infoTitleLabel";
			this->infoTitleLabel->Size = System::Drawing::Size(199, 30);
			this->infoTitleLabel->TabIndex = 4;
			this->infoTitleLabel->Text = L"Add Object Wizard";
			// 
			// infoLabel
			// 
			this->infoLabel->AutoSize = true;
			this->infoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->infoLabel->Location = System::Drawing::Point(8, 52);
			this->infoLabel->Name = L"infoLabel";
			this->infoLabel->Size = System::Drawing::Size(441, 150);
			this->infoLabel->TabIndex = 3;
			this->infoLabel->Text = resources->GetString(L"infoLabel.Text");
			// 
			// wizardPagesTemp
			// 
			this->wizardPagesTemp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->wizardPagesTemp->Controls->Add(this->introPage);
			this->wizardPagesTemp->Controls->Add(this->paramPage);
			this->wizardPagesTemp->Controls->Add(this->inputPage);
			this->wizardPagesTemp->Location = System::Drawing::Point(0, 0);
			this->wizardPagesTemp->Name = L"wizardPagesTemp";
			this->wizardPagesTemp->SelectedIndex = 0;
			this->wizardPagesTemp->Size = System::Drawing::Size(519, 245);
			this->wizardPagesTemp->TabIndex = 0;
			// 
			// templateOpenFileDialog
			// 
			this->templateOpenFileDialog->Filter = L"XML Files (*.xml) | *.xml";
			// 
			// AddObjectWizardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(520, 286);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->nextButton);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->wizardPagesTemp);
			this->Name = L"AddObjectWizardForm";
			this->Text = L"Add Object Wizard";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AddObjectWizardForm::AddObjectWizardForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AddObjectWizardForm::AddObjectWizardForm_Load);
			this->inputPage->ResumeLayout(false);
			this->inputTemplatePanel->ResumeLayout(false);
			this->inputTemplatePanel->PerformLayout();
			this->inputRigidPanel->ResumeLayout(false);
			this->inputRigidPanel->PerformLayout();
			this->inputCylinderPanel1->ResumeLayout(false);
			this->inputCylinderPanel1->PerformLayout();
			this->inputBoxPanel1->ResumeLayout(false);
			this->inputBoxPanel1->PerformLayout();
			this->inputPlanePanel->ResumeLayout(false);
			this->inputPlanePanel->PerformLayout();
			this->paramPage->ResumeLayout(false);
			this->paramPage->PerformLayout();
			this->introPage->ResumeLayout(false);
			this->introPage->PerformLayout();
			this->wizardPagesTemp->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: WizardPages^ wizardPages;
	private: int displayWorld;
	private: ObjectType objType;
	private: ControlType control;
	private: System::String^ defaultDataText;
	private: bool inputDirty;	// indicates if data fields need to be reset on display
	private: osg::Vec3* pos;
	private: osg::Vec3* pos0;
	private: osg::Vec3* pos1;
	private: osg::Vec3* pos2;
	private: std::vector<RigidBody*>* rigidBodyVector;
	private: int rigidID;
	private: osg::Quat* quat;

	private: System::Void AddObjectWizardForm_Load(System::Object^  sender, System::EventArgs^  e) {
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

			 this->rigidListView->View = View::Details;
			 this->rigidListView->Columns->Add("Id", 50, HorizontalAlignment::Left ); 
			 this->rigidListView->Columns->Add("Name", 150, HorizontalAlignment::Left ); 
			 
			 worldPopulateList();
			 typePopulateList();
			 controlPopulateList();
		}
private: System::Void AddObjectWizardForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 if (pos) delete pos;
			 if (pos0) delete pos0;
			 if (pos1) delete pos1;
			 if (pos2) delete pos2;
			 if (quat) delete quat;
		 }

/////////////////////
// Util Functions
		 // set text to display when there is no position data
private: System::Void setDefaultText(Label^ text) {
				text->Text = this->defaultDataText;
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

				type = gcnew String("Template");
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

		 		control = gcnew String("Add at Rigid Body");
				this->controlComboBox->Items->Add(control);

				control = gcnew String("Base Centre");
				this->rigidCentreCombo->Items->Add(control);

				control = gcnew String("Top Centre");
				this->rigidCentreCombo->Items->Add(control);
				this->rigidCentreCombo->SelectedIndex = CENTRE_BASE;

				control = gcnew String("Base Centre");
				this->boxCentreCombo->Items->Add(control);

				control = gcnew String("Top Centre");
				this->boxCentreCombo->Items->Add(control);
				this->boxCentreCombo->SelectedIndex = CENTRE_BASE;

				control = gcnew String("Base Centre");
				this->cylinCentreCombo->Items->Add(control);

				control = gcnew String("Top Centre");
				this->cylinCentreCombo->Items->Add(control);
				this->cylinCentreCombo->SelectedIndex = CENTRE_BASE;
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
			 {
				 this->nextButton->Enabled = true;
			 }
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
		 // set visible/not visible for coordinate text boxes
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

			 // cylinder
			 case OBJ_CYLINDER :
				 // read only
				 this->cylinCenXText->ReadOnly = readonly;
				 this->cylinCenYText->ReadOnly = readonly;
				 this->cylinCenZText->ReadOnly = readonly;

				 // reset textbox info
				 if (inputDirty)
				 {
					 this->cylinCenXText->Text = "";
					 this->cylinCenYText->Text = "";
					 this->cylinCenZText->Text = "";
				 }
				 break;
				 
			 // template
			 case OBJ_TEMPLATE :
				 // read only
				 this->tempCenXText->ReadOnly = readonly;
				 this->tempCenYText->ReadOnly = readonly;
				 this->tempCenZText->ReadOnly = readonly;

				 // reset textbox info
				 if (inputDirty)
				 {
					 this->tempCenXText->Text = "";
					 this->tempCenYText->Text = "";
					 this->tempCenZText->Text = "";
				 }
				 break;
			 }
		 }
		 // set visible/not visible for get data label
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
		 // set visible/not visible for get data button
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
			 // cylinder
			 case OBJ_CYLINDER :
				 this->cylinDataGetButton->Visible = visible;
				 break;
			 // template
			 case OBJ_TEMPLATE :
				 this->tempDataGetButton->Visible = visible;
				 break;
			 }
		 }
		 // set visible/not visible for text boxes to input marker IDs
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
			 // cylinder
			 case OBJ_CYLINDER :
				 // visibility
				 this->cylinMCenText->Visible = visible;
				 this->cylinMIDLabel->Visible = visible;

				 // reset textbox info
				 if (inputDirty)
				 {
					 this->cylinMCenText->Text = "";
				 }
				 break;
			 // template
			 case OBJ_TEMPLATE :
				 // visibility
				 this->tempMIDText->Visible = visible;

				 // reset textbox info
				 if (inputDirty)
				 {
					 this->tempMIDText->Text = "";
				 }
				 break;
			 }
		 }
		// set visible/not visible for orientation textboxes for template object
private: System::Void orientationTextBox(bool readonly, ObjectType type) {
			 switch (type)
			 {
			 // template
			 case OBJ_TEMPLATE :
				 this->tempQXText->ReadOnly = readonly;
				 this->tempQYText->ReadOnly = readonly;
				 this->tempQZText->ReadOnly = readonly;
				 this->tempQWText->ReadOnly = readonly;
				 break;


			 }
		 }
		 // set visible/not visible plane input panel
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
			 else if (ct == ControlType::RIGID_TOOL)
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
		 // set visible/not visible box input panel
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
			 else if (ct == ControlType::RIGID_TOOL)
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
		 // set visible/not visible cylinder input panel
private: System::Void cylinderPanel(ControlType ct, bool visible) {
			 if (!visible)
			 {
				 this->inputCylinderPanel1->Visible = false;
				 return;
			 }

			 this->inputCylinderPanel1->Visible = true;
			 if (ct == ControlType::MARKER)
			 {
				 XYZTextBox(true, OBJ_CYLINDER);
				 getDataButton(true, OBJ_CYLINDER);
				 markerIDTextBox(true, OBJ_CYLINDER);
			 }
			 else if (ct == ControlType::RIGID_TOOL)
			 {
				 XYZTextBox(true, OBJ_CYLINDER);
				 getDataButton(true, OBJ_CYLINDER);
				 markerIDTextBox(false, OBJ_CYLINDER);
			 }
			 else if (ct == ControlType::INPUT)
			 {
				 XYZTextBox(false, OBJ_CYLINDER);
				 getDataButton(false, OBJ_CYLINDER);
				 markerIDTextBox(false, OBJ_CYLINDER);
			 }
			 if (inputDirty)
			 {
				 this->cylinRText->Text = "";
				 this->cylinHText->Text = "";
			 }

			 inputDirty = false;
		 }
private: System::Void templatePanel(ControlType ct, bool visible) {
			 if (!visible)
			 {
				 this->inputTemplatePanel->Visible = false;
				 return;
			 }

			 this->inputTemplatePanel->Visible = true;
			 if (ct == ControlType::MARKER)
			 {
				 XYZTextBox(true, OBJ_TEMPLATE);
				 getDataButton(true, OBJ_TEMPLATE);
				 markerIDTextBox(true, OBJ_TEMPLATE);
				 orientationTextBox(false, OBJ_TEMPLATE);

				 this->tempDataGetButton->Text = "Marker ID";
			 }
			 else if (ct == ControlType::RIGID_TOOL)
			 {
				 XYZTextBox(true, OBJ_TEMPLATE);
				 getDataButton(true, OBJ_TEMPLATE);
				 markerIDTextBox(false, OBJ_TEMPLATE);
				 orientationTextBox(true, OBJ_TEMPLATE);
				 this->tempDataGetButton->Text = "Get Data";
			 }
			 else if (ct == ControlType::INPUT)
			 {
				 XYZTextBox(false, OBJ_TEMPLATE);
				 getDataButton(false, OBJ_TEMPLATE);
				 markerIDTextBox(false, OBJ_TEMPLATE);
				 orientationTextBox(false, OBJ_TEMPLATE);
			 }
			 if (inputDirty)
			 {
				 this->tempQXText->Text = "";
				 this->tempQYText->Text = "";
				 this->tempQZText->Text = "";
				 this->tempQWText->Text = "";
				 this->tempFilePathText->Text = "";
			 }

			 inputDirty = false;
		 }
private: System::Void rigidPanel(ObjectType ot, bool visible) {
			 if (!visible)
			 {
				 this->inputRigidPanel->Visible = false;
				 return;
			 }

			 this->inputRigidPanel->Visible = true;
			 if (ot == OBJ_PLANE)
			 {
				 this->rigidDimLabel->Visible = false;
				 this->rigidLLabel->Visible = false;
				 this->rigidWLabel->Visible = false;
				 this->rigidHLabel->Visible = false;
				 this->rigidObjInfoLabel->Text = L"Add a plane to the world";

				 this->rigidLText->Visible = false;
				 this->rigidWText->Visible = false;
				 this->rigidHText->Visible = false;
				 this->rigidCentreCombo->Visible = false;

				 this->rigidTemplateFileLabel->Visible = false;
				 this->rigidFilePathText->Visible = false;
				 this->rigidBrowseButton->Visible = false;
			 }
			 else if (ot == OBJ_BOX)
			 {
				 this->rigidDimLabel->Visible = true;
				 this->rigidLLabel->Visible = true;
				 this->rigidWLabel->Visible = true;
				 this->rigidHLabel->Visible = true;
				 this->rigidObjInfoLabel->Text = L"Add a box to the world";
				 this->rigidLLabel->Text = L"Length (X)";

				 this->rigidLText->Visible = true;
				 this->rigidWText->Visible = true;
				 this->rigidHText->Visible = true;
				 this->rigidCentreCombo->Visible = true;

				 this->rigidTemplateFileLabel->Visible = false;
				 this->rigidFilePathText->Visible = false;
				 this->rigidBrowseButton->Visible = false;
			 }
			 else if (ot == OBJ_CYLINDER)
			 {
				 this->rigidDimLabel->Visible = true;
				 this->rigidLLabel->Visible = true;
				 this->rigidWLabel->Visible = false;
				 this->rigidHLabel->Visible = true;
				 this->rigidObjInfoLabel->Text = L"Add a cylinder to the world";
				 this->rigidLLabel->Text = L"Radius (X, Y)";

				 this->rigidLText->Visible = true;
				 this->rigidWText->Visible = false;
				 this->rigidHText->Visible = true;
				 this->rigidCentreCombo->Visible = true;

				 this->rigidTemplateFileLabel->Visible = false;
				 this->rigidFilePathText->Visible = false;
				 this->rigidBrowseButton->Visible = false;
			 }
			 else if (ot == OBJ_TEMPLATE)
			 {
				 this->rigidDimLabel->Visible = false;
				 this->rigidLLabel->Visible = false;
				 this->rigidWLabel->Visible = false;
				 this->rigidHLabel->Visible = false;
				 this->rigidObjInfoLabel->Text = L"Add a templated object to the world";

				 this->rigidLText->Visible = false;
				 this->rigidWText->Visible = false;
				 this->rigidHText->Visible = false;
				 this->rigidCentreCombo->Visible = false;

				 this->rigidTemplateFileLabel->Visible = true;
				 this->rigidFilePathText->Visible = true;
				 this->rigidBrowseButton->Visible = true;
			 }

			 this->rigidCenXText->Text = "";
			 this->rigidCenYText->Text = "";
			 this->rigidCenZText->Text = "";

			 this->rigidLText->Text = "";
			 this->rigidWText->Text = "";
			 this->rigidHText->Text = "";

			 this->rigidFilePathText->Text = "";

			 this->rigidCentreCombo->SelectedIndex = CENTRE_BASE;
			 inputDirty = false;

			 loadRigidBodyList();
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
					 templatePanel(control, false);
					 rigidPanel(objType, false);

					 if (control == ControlType::RIGID_ATTACH)
						 rigidPanel(objType, true);
					 else if (objType == OBJ_PLANE)
						 planePanel(control, true);
					 else if (objType == OBJ_BOX)
						 boxPanel(control, true);
					 else if (objType == OBJ_CYLINDER)
						 cylinderPanel(control, true);
					 else if (objType == OBJ_TEMPLATE)
						 templatePanel(control, true);

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
				 bool result = true;
				 if (control == ControlType::RIGID_ATTACH)
					 result = createAtRigid();
				 else if (objType == OBJ_PLANE)
					 createPlane();
				 else if (objType == OBJ_BOX)
					 createBox();
				 else if (objType == OBJ_CYLINDER)
					 createCylinder();
				 else if (objType == OBJ_TEMPLATE)
					 result = createTemplate();

				 if (result)
					this->Close();
				 else
				 {
					 String^ message = "Object could not be created\nPlease check your input";
					 MessageBox::Show(message, "", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 }
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
			 if (control == ControlType::RIGID_ATTACH)
				 return validateRigid();

			 switch (objType) {
			 case OBJ_PLANE :
				 return validatePlane();

			 case OBJ_BOX :
				 return validateBox();

			 case OBJ_CYLINDER :
				 return validateCylinder();

			 case OBJ_TEMPLATE :
				 return validateTemplate();

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

					  isPositiveFloat(this->boxLTextBox->Text) &&
					  isPositiveFloat(this->boxWTextBox->Text) &&
					  isPositiveFloat(this->boxHTextBox->Text) );
		 }
private: bool validateCylinder() {
			 return ( isFloat(this->cylinCenXText->Text) &&
					  isFloat(this->cylinCenYText->Text) &&
					  isFloat(this->cylinCenZText->Text) &&

					  isPositiveFloat(this->cylinRText->Text) &&
					  isPositiveFloat(this->cylinHText->Text) );
		 }
private: bool validateTemplate() {
			 return ( isFloat(this->tempCenXText->Text) &&
					  isFloat(this->tempCenYText->Text) &&
					  isFloat(this->tempCenZText->Text) &&

					  isFloat(this->tempQXText->Text) &&
					  isFloat(this->tempQYText->Text) &&
					  isFloat(this->tempQZText->Text) &&
					  isFloat(this->tempQWText->Text) &&
					  
					  System::IO::File::Exists(this->tempFilePathText->Text) );
		 }
private: bool validateRigid() {
			 switch (objType)
			 {
			 case OBJ_PLANE :
				 return ( isFloat(this->rigidCenXText->Text) &&
						  isFloat(this->rigidCenYText->Text) &&
						  isFloat(this->rigidCenZText->Text) );

			 case OBJ_BOX : 
				 return ( isFloat(this->rigidCenXText->Text) &&
						  isFloat(this->rigidCenYText->Text) &&
						  isFloat(this->rigidCenZText->Text) &&

						  isPositiveFloat(this->rigidLText->Text) &&
						  isPositiveFloat(this->rigidWText->Text) &&
						  isPositiveFloat(this->rigidHText->Text) );
				 
			 case OBJ_CYLINDER : 
				 return ( isFloat(this->rigidCenXText->Text) &&
						  isFloat(this->rigidCenYText->Text) &&
						  isFloat(this->rigidCenZText->Text) &&

						  isPositiveFloat(this->rigidLText->Text) &&
						  isPositiveFloat(this->rigidHText->Text) );
			 case OBJ_TEMPLATE :
				 return ( isFloat(this->rigidCenXText->Text) &&
						  isFloat(this->rigidCenYText->Text) &&
						  isFloat(this->rigidCenZText->Text) &&
					  
						  System::IO::File::Exists(this->rigidFilePathText->Text) );
			 default :
				 return false;
			 }
		 }
private: System::Void inputText_Validating(System::Object^  sender, System::EventArgs^  e) {
			 validate();
		 }
private: System::Void validate() {
			 if (validateInputPage())
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
			 if (control == ControlType::RIGID_ATTACH)
			 {
				 temp = posVec < 0 ? NULL : pos0;
				 
				 if (temp)
				 {
					 this->rigidCenXText->Text = temp->x().ToString();
					 this->rigidCenYText->Text = temp->y().ToString();
					 this->rigidCenZText->Text = temp->z().ToString();
				 }
				 else // reset to zero
				 {
					 this->rigidCenXText->Text = "";
					 this->rigidCenYText->Text = "";
					 this->rigidCenZText->Text = "";
				 }
				 return;
			 }

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
				 // cylinder
			 case OBJ_CYLINDER :
				 temp = posVec < 0 ? NULL : pos0;
				 
				 if (temp)
				 {
					 this->cylinCenXText->Text = temp->x().ToString();
					 this->cylinCenYText->Text = temp->y().ToString();
					 this->cylinCenZText->Text = temp->z().ToString();
				 }
				 else // reset to zero
				 {
					 this->cylinCenXText->Text = "";
					 this->cylinCenYText->Text = "";
					 this->cylinCenZText->Text = "";
				 }
				 break;
			 case OBJ_TEMPLATE :
				 temp = posVec < 0 ? NULL : pos0;
				 
				 if (temp)
				 {
					 this->tempCenXText->Text = temp->x().ToString();
					 this->tempCenYText->Text = temp->y().ToString();
					 this->tempCenZText->Text = temp->z().ToString();
				 }
				 else // reset to zero
				 {
					 this->tempCenXText->Text = "";
					 this->tempCenYText->Text = "";
					 this->tempCenZText->Text = "";
				 }
				 break;
			 }
		 }
		 // if input control type, extract coordinates from fields
private: bool extractCoordinates() {
			 float x, y, z, w;
			 
			 switch (objType) {
				 // plane
			 case OBJ_PLANE : 
				 if (!Single::TryParse(this->planePt1XText->Text, x) || 
					 !Single::TryParse(this->planePt1YText->Text, y) ||
					 !Single::TryParse(this->planePt1ZText->Text, z))
					 return false;
				 pos1->set(x, y, z);

				 if (!Single::TryParse(this->planeCornXText->Text, x) || 
					 !Single::TryParse(this->planeCornYText->Text, y) ||
					 !Single::TryParse(this->planeCornZText->Text, z))
					 return false;
				 pos0->set(x, y, z);

				 if (!Single::TryParse(this->planePt2XText->Text, x) || 
					 !Single::TryParse(this->planePt2YText->Text, y) ||
					 !Single::TryParse(this->planePt2ZText->Text, z))
					 return false;
				 pos2->set(x, y, z);

				 return true;
				 // box
			 case OBJ_BOX :
				 if (!Single::TryParse(this->boxCenXText->Text, x) || 
					 !Single::TryParse(this->boxCenYText->Text, y) ||
					 !Single::TryParse(this->boxCenZText->Text, z))
					 return false;
				 pos0->set(x, y, z);
				 return true;
				 // cylinder
			 case OBJ_CYLINDER :
				 if (!Single::TryParse(this->cylinCenXText->Text, x) || 
					 !Single::TryParse(this->cylinCenYText->Text, y) ||
					 !Single::TryParse(this->cylinCenZText->Text, z))
					 return false;
				 pos0->set(x, y, z);
				 return true;
				 // template
			 case OBJ_TEMPLATE :
				 if (!Single::TryParse(this->tempCenXText->Text, x) || 
					 !Single::TryParse(this->tempCenYText->Text, y) ||
					 !Single::TryParse(this->tempCenZText->Text, z))
					 return false;
				 pos0->set(x, y, z);

				 if (!Single::TryParse(this->tempQXText->Text, x) || 
					 !Single::TryParse(this->tempQYText->Text, y) ||
					 !Single::TryParse(this->tempQZText->Text, z) ||
					 !Single::TryParse(this->tempQWText->Text, w))
					 return false;
				 quat->set(x, y, z, w);

				 return true;
			 default :
				 return false;
			 }
		 }
private: System::Void loadRigidBodyList() {
			this->rigidListView->Items->Clear();
			
			if (!rigidBodyVector) return;

			for (std::vector<RigidBody*>::iterator itr = rigidBodyVector->begin(); 
				itr != rigidBodyVector->end(); itr++)
			{
				RigidBody* body = *itr;
				String^ rigidBodyID = Convert::ToString(body->getID());
				String^ rigidBodyName = gcnew String(body->getName());
				ListViewItem^ listViewItem = gcnew ListViewItem(rigidBodyID); 
				listViewItem->SubItems->Add(rigidBodyName);
				this->rigidListView->Items->Add(listViewItem);
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
				
				// point 1
				result = Int32::TryParse(this->planeMPt1Text->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
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
			else if (control == ControlType::RIGID_TOOL && client)
			{
				RigidBody* body = client->getRigidBody(client->getRigidBodyTool());
				if (body)
				{
					pos->set(body->getPosition().x(), 
							body->getPosition().y(), 
							body->getPosition().z());
					this->planeDataLabel->Text = setPoint(pos);
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
			}
			else if (sender == this->planeCornSetButton)
			{
				pos0->set(pos->x(), pos->y(), pos->z());
				populateTextFromPosition(0, 0);
			}
			else if (sender == this->planePt2SetButton)
			{
				pos2->set(pos->x(), pos->y(), pos->z());
				populateTextFromPosition(2, 2);
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
			else if (control == ControlType::RIGID_TOOL && client)
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
	 }
private: System::Void cylinDataGetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			ClientHandler* client = AppData::getInstance()->getClient();
			// use markers
			if (control == ControlType::MARKER && client->lock())
			{
				Marker* marker;
				bool result;
				int id;

				// base centre
				result = Int32::TryParse(this->cylinMCenText->Text, id);
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
			else if (control == ControlType::RIGID_TOOL && client)
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
		 }
private: System::Void tempDataGetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			ClientHandler* client = AppData::getInstance()->getClient();
			// use markers
			if (control == ControlType::MARKER && client->lock())
			{
				Marker* marker;
				bool result;
				int id;

				// base centre
				result = Int32::TryParse(this->tempMIDText->Text, id);
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
			else if (control == ControlType::RIGID_TOOL && client)
			{
				RigidBody* body = client->getRigidBody(client->getRigidBodyTool());
				if (body)
				{
					pos0->set(body->getPosition().x(), 
							body->getPosition().y(), 
							body->getPosition().z());
					populateTextFromPosition(0, 0);
					osg::Quat q = body->getRotation();
					quat->set(q.x(), q.y(), q.z(), q.w());
					this->tempQXText->Text = q.x().ToString();
					this->tempQYText->Text = q.y().ToString();
					this->tempQZText->Text = q.z().ToString();
					this->tempQWText->Text = q.w().ToString();
				}
			}
		 }
private: System::Void tempBrowseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->templateOpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 this->tempFilePathText->Text = this->templateOpenFileDialog->FileName;
			 }
			 validate();
		 }
private: System::Void rigidBrowseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->templateOpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 this->rigidFilePathText->Text = this->templateOpenFileDialog->FileName;
			 }
			 validate();
		 }
private: System::Void rigidListView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->rigidListView->SelectedItems->Count <= 0)
				 return;

			 ListViewItem^ item = this->rigidListView->SelectedItems->default[0];
			 if (item && Int32::TryParse(item->Text, rigidID))
			 {
				ClientHandler* client = AppData::getInstance()->getClient();
				if (client)
				{
					RigidBody* body = client->getRigidBody(rigidID);
					if (body)
					{
						pos0->set(body->getPosition().x(), body->getPosition().y(), body->getPosition().z());
						populateTextFromPosition(0, 0);
						return;
					}
				}
			 }
			 populateTextFromPosition(-1, 0);
		 }

/////////////////////
// object creation

private: System::Void createPlane() {
			 if (control == ControlType::INPUT && !extractCoordinates())
				 return;

			 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayWorld);
			 if (world)
			 {
				 const char* name = managedStringToChar(this->nameTextBox->Text);
				 world->addPlane(*pos0, *pos1, *pos2, std::string(name));
			 }
			 this->Close();
		 }
private: System::Void createBox() {
			 if (control == ControlType::INPUT && !extractCoordinates())
				 return;

			 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayWorld);
			 if (world)
			 {
				 const char* name = managedStringToChar(this->nameTextBox->Text);
				 float l, w, h;
				 
				 if (!Single::TryParse(this->boxLTextBox->Text, l) ||
					 !Single::TryParse(this->boxWTextBox->Text, w) ||
					 !Single::TryParse(this->boxHTextBox->Text, h))
					 return;

				 CentreType cenType = (CentreType) this->boxCentreCombo->SelectedIndex;
				 world->addBox(*pos0, osg::Vec3(l, w, h), cenType, std::string(name));
			 }
			 this->Close();
		 }
private: System::Void createCylinder() {
			 if (control == ControlType::INPUT && !extractCoordinates())
				 return;

			 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayWorld);
			 if (world)
			 {
				 const char* name = managedStringToChar(this->nameTextBox->Text);
				 float r, h;
				 
				 if (!Single::TryParse(this->cylinRText->Text, r) ||
					 !Single::TryParse(this->cylinHText->Text, h))
					 return;

				 CentreType cenType = (CentreType) this->cylinCentreCombo->SelectedIndex;
				 world->addCylinder(*pos0, r, h, cenType, std::string(name));
			 }
			 this->Close();
		 }
private: bool createTemplate() {
			 if (control == ControlType::INPUT && !extractCoordinates())
				 return false;

			 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayWorld);
			 if (world)
			 {
				 const char* name = managedStringToChar(this->nameTextBox->Text);
				 const char* file = managedStringToChar(this->tempFilePathText->Text);

				 if (!world->addTemplate(*pos0, *quat, file, std::string(name)))
					 return false;
				 else
					 return true;
			 }
			 return false;
		 }
private: bool createAtRigid() {
			 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayWorld);
			 if (world)
			 {
				 const char* name = managedStringToChar(this->nameTextBox->Text);
				 float l, w, h;
				 CentreType cenType = (CentreType) this->rigidCentreCombo->SelectedIndex;
				 
				 switch (objType)
				 {
				 case OBJ_PLANE :
					 world->addPlaneRigid(rigidID, this->rigidAttachCheck->Checked, std::string(name));
					 return true;

				 case OBJ_BOX : 
					 if (!Single::TryParse(this->rigidLText->Text, l) ||
						 !Single::TryParse(this->rigidWText->Text, w) ||
						 !Single::TryParse(this->rigidHText->Text, h))
					 return false;

					 world->addBoxRigid(rigidID, osg::Vec3(l, w, h), this->rigidAttachCheck->Checked, cenType, std::string(name));
					 return true;

				 case OBJ_CYLINDER :
					 if (!Single::TryParse(this->rigidLText->Text, l) ||
						 !Single::TryParse(this->rigidHText->Text, h))
					 return false;

					 world->addCylinderRigid(rigidID, l, h, this->rigidAttachCheck->Checked, cenType, std::string(name));
					 return true;

				 case OBJ_TEMPLATE :
					 const char* file = managedStringToChar(this->rigidFilePathText->Text);
					 if (!world->addTemplateRigid(rigidID, this->rigidAttachCheck->Checked, file, std::string(name)))
						 return false;
					 else
						 return true;
				 }
			 }
			 return false;
		 }


/////////////////////
// distance calculation

private: System::Void textInput_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (String::IsNullOrWhiteSpace(((TextBox^)sender)->Text))
			 {
				 AddObjectDistanceForm^ form = gcnew AddObjectDistanceForm();
				 if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 ((TextBox^)sender)->Text = form->distance.ToString();
				 }
				 delete form;
			 }
		 }
};
}
