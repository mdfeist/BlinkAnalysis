#pragma once

#include "AppData.h"
#include "AppViewer.h"
#include "WorldManager.h"
#include <string>

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddObjectForm
	/// </summary>
	public ref class AddObjectForm : public System::Windows::Forms::Form
	{
	public:
		AddObjectForm(void)
		{
			InitializeComponent();
			displayWorld = -1;
		}

		void setDisplayWorld(int id) {
			displayWorld = id; 
			this->Text = L"Add Object (World ID " + displayWorld.ToString() + ")";
		}
		int getDisplayWorld() { return displayWorld; }


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddObjectForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 
	private: System::Windows::Forms::TabPage^  infoPage;
	private: System::Windows::Forms::TabPage^  planePage;
	private: System::Windows::Forms::Label^  planePt2Label;

	private: System::Windows::Forms::Label^  planeCornerLabel;

	private: System::Windows::Forms::Label^  planePt1Label;
	private: System::Windows::Forms::Button^  planeDataGetButton;


	private: System::Windows::Forms::Button^  planeSetButton;
	private: System::Windows::Forms::Label^  planeDataPt2Label;

	private: System::Windows::Forms::Label^  planeDataCornerLabel;

	private: System::Windows::Forms::Label^  planeDataPt1Label;
	private: System::Windows::Forms::TextBox^  planeCornerTextBox;
	private: System::Windows::Forms::TextBox^  planePt2TextBox;



	private: System::Windows::Forms::TextBox^  planePt1TextBox;

	private: System::Windows::Forms::TextBox^  planeNameTextBox;

	private: System::Windows::Forms::Label^  planeNameLabel;

			 
	private: System::String^ defaultDataText;
	private: System::Windows::Forms::Label^  planeOptionalLabel;

	private: System::Windows::Forms::Label^  planeInfoLabel;
	private: System::Windows::Forms::Button^  planePt2SetButton;
	private: System::Windows::Forms::Button^  planeCornerSetButton;
	private: System::Windows::Forms::Button^  planePt1SetButton;
	private: System::Windows::Forms::RadioButton^  planeRigidRadio;

	private: System::Windows::Forms::RadioButton^  planeMarkersRadio;
	private: System::Windows::Forms::Label^  planeRigidDataLabel;

	private: int displayWorld;
	private: System::Windows::Forms::RadioButton^  planeCoordRadio;
	private: System::Windows::Forms::TextBox^  planeInPt2TextBox;
	private: System::Windows::Forms::TextBox^  planeInCornerTextBox;
	private: System::Windows::Forms::TextBox^  planeInPt1TextBox;
	private: System::Windows::Forms::TabPage^  boxPage;
	private: System::Windows::Forms::Button^  boxSetButton;
	private: System::Windows::Forms::TextBox^  boxInCenTextBox;
	private: System::Windows::Forms::RadioButton^  boxCoordRadio;


	private: System::Windows::Forms::RadioButton^  boxRigidRadio;
	private: System::Windows::Forms::RadioButton^  boxMarkersRadio;

	private: System::Windows::Forms::Label^  boxInfoLabel;
	private: System::Windows::Forms::Label^  boxOptionalLabel;
	private: System::Windows::Forms::TextBox^  boxNameTextBox;
	private: System::Windows::Forms::Label^  boxNameLabel;
	private: System::Windows::Forms::Label^  boxCentreLabel;
	private: System::Windows::Forms::Button^  boxGetButton;
	private: System::Windows::Forms::Label^  boxCenDataLabel;

	private: System::Windows::Forms::TextBox^  boxCenTextBox;
	private: System::Windows::Forms::TextBox^  boxHTextBox;
	private: System::Windows::Forms::TextBox^  boxWTextBox;
	private: System::Windows::Forms::TextBox^  boxLTextBox;
	private: System::Windows::Forms::Label^  boxHeightLabel;
	private: System::Windows::Forms::Label^  boxWidthLabel;
	private: System::Windows::Forms::Label^  boxLengthLabel;

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->infoPage = (gcnew System::Windows::Forms::TabPage());
			this->planePage = (gcnew System::Windows::Forms::TabPage());
			this->planeInPt2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->planeInCornerTextBox = (gcnew System::Windows::Forms::TextBox());
			this->planeInPt1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->planeCoordRadio = (gcnew System::Windows::Forms::RadioButton());
			this->planeRigidDataLabel = (gcnew System::Windows::Forms::Label());
			this->planePt2SetButton = (gcnew System::Windows::Forms::Button());
			this->planeCornerSetButton = (gcnew System::Windows::Forms::Button());
			this->planePt1SetButton = (gcnew System::Windows::Forms::Button());
			this->planeRigidRadio = (gcnew System::Windows::Forms::RadioButton());
			this->planeMarkersRadio = (gcnew System::Windows::Forms::RadioButton());
			this->planeInfoLabel = (gcnew System::Windows::Forms::Label());
			this->planeOptionalLabel = (gcnew System::Windows::Forms::Label());
			this->planeNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->planeNameLabel = (gcnew System::Windows::Forms::Label());
			this->planePt2Label = (gcnew System::Windows::Forms::Label());
			this->planeCornerLabel = (gcnew System::Windows::Forms::Label());
			this->planePt1Label = (gcnew System::Windows::Forms::Label());
			this->planeDataGetButton = (gcnew System::Windows::Forms::Button());
			this->planeSetButton = (gcnew System::Windows::Forms::Button());
			this->planeDataPt2Label = (gcnew System::Windows::Forms::Label());
			this->planeDataCornerLabel = (gcnew System::Windows::Forms::Label());
			this->planeDataPt1Label = (gcnew System::Windows::Forms::Label());
			this->planeCornerTextBox = (gcnew System::Windows::Forms::TextBox());
			this->planePt2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->planePt1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->boxPage = (gcnew System::Windows::Forms::TabPage());
			this->boxHTextBox = (gcnew System::Windows::Forms::TextBox());
			this->boxWTextBox = (gcnew System::Windows::Forms::TextBox());
			this->boxLTextBox = (gcnew System::Windows::Forms::TextBox());
			this->boxHeightLabel = (gcnew System::Windows::Forms::Label());
			this->boxWidthLabel = (gcnew System::Windows::Forms::Label());
			this->boxLengthLabel = (gcnew System::Windows::Forms::Label());
			this->boxSetButton = (gcnew System::Windows::Forms::Button());
			this->boxInCenTextBox = (gcnew System::Windows::Forms::TextBox());
			this->boxCoordRadio = (gcnew System::Windows::Forms::RadioButton());
			this->boxRigidRadio = (gcnew System::Windows::Forms::RadioButton());
			this->boxMarkersRadio = (gcnew System::Windows::Forms::RadioButton());
			this->boxInfoLabel = (gcnew System::Windows::Forms::Label());
			this->boxOptionalLabel = (gcnew System::Windows::Forms::Label());
			this->boxNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->boxNameLabel = (gcnew System::Windows::Forms::Label());
			this->boxCentreLabel = (gcnew System::Windows::Forms::Label());
			this->boxGetButton = (gcnew System::Windows::Forms::Button());
			this->boxCenDataLabel = (gcnew System::Windows::Forms::Label());
			this->boxCenTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->planePage->SuspendLayout();
			this->boxPage->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->infoPage);
			this->tabControl1->Controls->Add(this->planePage);
			this->tabControl1->Controls->Add(this->boxPage);
			this->tabControl1->Location = System::Drawing::Point(0, -1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(418, 313);
			this->tabControl1->TabIndex = 0;
			// 
			// infoPage
			// 
			this->infoPage->Location = System::Drawing::Point(4, 22);
			this->infoPage->Name = L"infoPage";
			this->infoPage->Padding = System::Windows::Forms::Padding(3);
			this->infoPage->Size = System::Drawing::Size(410, 287);
			this->infoPage->TabIndex = 0;
			this->infoPage->Text = L"Info";
			this->infoPage->UseVisualStyleBackColor = true;
			// 
			// planePage
			// 
			this->planePage->Controls->Add(this->planeInPt2TextBox);
			this->planePage->Controls->Add(this->planeInCornerTextBox);
			this->planePage->Controls->Add(this->planeInPt1TextBox);
			this->planePage->Controls->Add(this->planeCoordRadio);
			this->planePage->Controls->Add(this->planeRigidDataLabel);
			this->planePage->Controls->Add(this->planePt2SetButton);
			this->planePage->Controls->Add(this->planeCornerSetButton);
			this->planePage->Controls->Add(this->planePt1SetButton);
			this->planePage->Controls->Add(this->planeRigidRadio);
			this->planePage->Controls->Add(this->planeMarkersRadio);
			this->planePage->Controls->Add(this->planeInfoLabel);
			this->planePage->Controls->Add(this->planeOptionalLabel);
			this->planePage->Controls->Add(this->planeNameTextBox);
			this->planePage->Controls->Add(this->planeNameLabel);
			this->planePage->Controls->Add(this->planePt2Label);
			this->planePage->Controls->Add(this->planeCornerLabel);
			this->planePage->Controls->Add(this->planePt1Label);
			this->planePage->Controls->Add(this->planeDataGetButton);
			this->planePage->Controls->Add(this->planeSetButton);
			this->planePage->Controls->Add(this->planeDataPt2Label);
			this->planePage->Controls->Add(this->planeDataCornerLabel);
			this->planePage->Controls->Add(this->planeDataPt1Label);
			this->planePage->Controls->Add(this->planeCornerTextBox);
			this->planePage->Controls->Add(this->planePt2TextBox);
			this->planePage->Controls->Add(this->planePt1TextBox);
			this->planePage->Location = System::Drawing::Point(4, 22);
			this->planePage->Name = L"planePage";
			this->planePage->Padding = System::Windows::Forms::Padding(3);
			this->planePage->Size = System::Drawing::Size(410, 287);
			this->planePage->TabIndex = 1;
			this->planePage->Text = L"Plane";
			this->planePage->UseVisualStyleBackColor = true;
			// 
			// planeInPt2TextBox
			// 
			this->planeInPt2TextBox->Location = System::Drawing::Point(75, 223);
			this->planeInPt2TextBox->Name = L"planeInPt2TextBox";
			this->planeInPt2TextBox->Size = System::Drawing::Size(223, 20);
			this->planeInPt2TextBox->TabIndex = 35;
			this->planeInPt2TextBox->Visible = false;
			this->planeInPt2TextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectForm::planeTextBox_Validating);
			// 
			// planeInCornerTextBox
			// 
			this->planeInCornerTextBox->Location = System::Drawing::Point(75, 197);
			this->planeInCornerTextBox->Name = L"planeInCornerTextBox";
			this->planeInCornerTextBox->Size = System::Drawing::Size(223, 20);
			this->planeInCornerTextBox->TabIndex = 34;
			this->planeInCornerTextBox->Visible = false;
			this->planeInCornerTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectForm::planeTextBox_Validating);
			// 
			// planeInPt1TextBox
			// 
			this->planeInPt1TextBox->Location = System::Drawing::Point(75, 171);
			this->planeInPt1TextBox->Name = L"planeInPt1TextBox";
			this->planeInPt1TextBox->Size = System::Drawing::Size(223, 20);
			this->planeInPt1TextBox->TabIndex = 33;
			this->planeInPt1TextBox->Visible = false;
			this->planeInPt1TextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectForm::planeTextBox_Validating);
			// 
			// planeCoordRadio
			// 
			this->planeCoordRadio->AutoSize = true;
			this->planeCoordRadio->Location = System::Drawing::Point(257, 93);
			this->planeCoordRadio->Name = L"planeCoordRadio";
			this->planeCoordRadio->Size = System::Drawing::Size(81, 17);
			this->planeCoordRadio->TabIndex = 32;
			this->planeCoordRadio->TabStop = true;
			this->planeCoordRadio->Text = L"Coordinates";
			this->planeCoordRadio->UseVisualStyleBackColor = true;
			this->planeCoordRadio->CheckedChanged += gcnew System::EventHandler(this, &AddObjectForm::planeCoordRadio_CheckedChanged);
			// 
			// planeRigidDataLabel
			// 
			this->planeRigidDataLabel->AutoSize = true;
			this->planeRigidDataLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->planeRigidDataLabel->Location = System::Drawing::Point(102, 131);
			this->planeRigidDataLabel->Name = L"planeRigidDataLabel";
			this->planeRigidDataLabel->Size = System::Drawing::Size(92, 16);
			this->planeRigidDataLabel->TabIndex = 31;
			this->planeRigidDataLabel->Text = L"No data found";
			this->planeRigidDataLabel->Visible = false;
			// 
			// planePt2SetButton
			// 
			this->planePt2SetButton->Enabled = false;
			this->planePt2SetButton->Location = System::Drawing::Point(75, 221);
			this->planePt2SetButton->Name = L"planePt2SetButton";
			this->planePt2SetButton->Size = System::Drawing::Size(82, 23);
			this->planePt2SetButton->TabIndex = 30;
			this->planePt2SetButton->Text = L"Set";
			this->planePt2SetButton->UseVisualStyleBackColor = true;
			this->planePt2SetButton->Visible = false;
			this->planePt2SetButton->Click += gcnew System::EventHandler(this, &AddObjectForm::planeSetDataButton_Click);
			// 
			// planeCornerSetButton
			// 
			this->planeCornerSetButton->Enabled = false;
			this->planeCornerSetButton->Location = System::Drawing::Point(75, 195);
			this->planeCornerSetButton->Name = L"planeCornerSetButton";
			this->planeCornerSetButton->Size = System::Drawing::Size(82, 23);
			this->planeCornerSetButton->TabIndex = 29;
			this->planeCornerSetButton->Text = L"Set";
			this->planeCornerSetButton->UseVisualStyleBackColor = true;
			this->planeCornerSetButton->Visible = false;
			this->planeCornerSetButton->Click += gcnew System::EventHandler(this, &AddObjectForm::planeSetDataButton_Click);
			// 
			// planePt1SetButton
			// 
			this->planePt1SetButton->Enabled = false;
			this->planePt1SetButton->Location = System::Drawing::Point(75, 169);
			this->planePt1SetButton->Name = L"planePt1SetButton";
			this->planePt1SetButton->Size = System::Drawing::Size(82, 23);
			this->planePt1SetButton->TabIndex = 28;
			this->planePt1SetButton->Text = L"Set";
			this->planePt1SetButton->UseVisualStyleBackColor = true;
			this->planePt1SetButton->Visible = false;
			this->planePt1SetButton->Click += gcnew System::EventHandler(this, &AddObjectForm::planeSetDataButton_Click);
			// 
			// planeRigidRadio
			// 
			this->planeRigidRadio->AutoSize = true;
			this->planeRigidRadio->Location = System::Drawing::Point(148, 93);
			this->planeRigidRadio->Name = L"planeRigidRadio";
			this->planeRigidRadio->Size = System::Drawing::Size(100, 17);
			this->planeRigidRadio->TabIndex = 27;
			this->planeRigidRadio->Text = L"Rigid Body Tool";
			this->planeRigidRadio->UseVisualStyleBackColor = true;
			this->planeRigidRadio->CheckedChanged += gcnew System::EventHandler(this, &AddObjectForm::planeRigidRadio_CheckedChanged);
			// 
			// planeMarkersRadio
			// 
			this->planeMarkersRadio->AutoSize = true;
			this->planeMarkersRadio->Checked = true;
			this->planeMarkersRadio->Location = System::Drawing::Point(67, 93);
			this->planeMarkersRadio->Name = L"planeMarkersRadio";
			this->planeMarkersRadio->Size = System::Drawing::Size(63, 17);
			this->planeMarkersRadio->TabIndex = 26;
			this->planeMarkersRadio->TabStop = true;
			this->planeMarkersRadio->Text = L"Markers";
			this->planeMarkersRadio->UseVisualStyleBackColor = true;
			this->planeMarkersRadio->CheckedChanged += gcnew System::EventHandler(this, &AddObjectForm::planeMarkersRadio_CheckedChanged);
			// 
			// planeInfoLabel
			// 
			this->planeInfoLabel->AutoSize = true;
			this->planeInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planeInfoLabel->Location = System::Drawing::Point(18, 21);
			this->planeInfoLabel->Name = L"planeInfoLabel";
			this->planeInfoLabel->Size = System::Drawing::Size(167, 15);
			this->planeInfoLabel->TabIndex = 25;
			this->planeInfoLabel->Text = L"Add a finite plane to the world";
			// 
			// planeOptionalLabel
			// 
			this->planeOptionalLabel->AutoSize = true;
			this->planeOptionalLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->planeOptionalLabel->Location = System::Drawing::Point(254, 60);
			this->planeOptionalLabel->Name = L"planeOptionalLabel";
			this->planeOptionalLabel->Size = System::Drawing::Size(44, 13);
			this->planeOptionalLabel->TabIndex = 24;
			this->planeOptionalLabel->Text = L"optional";
			// 
			// planeNameTextBox
			// 
			this->planeNameTextBox->Location = System::Drawing::Point(69, 57);
			this->planeNameTextBox->Name = L"planeNameTextBox";
			this->planeNameTextBox->Size = System::Drawing::Size(179, 20);
			this->planeNameTextBox->TabIndex = 23;
			// 
			// planeNameLabel
			// 
			this->planeNameLabel->AutoSize = true;
			this->planeNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planeNameLabel->Location = System::Drawing::Point(18, 58);
			this->planeNameLabel->Name = L"planeNameLabel";
			this->planeNameLabel->Size = System::Drawing::Size(45, 15);
			this->planeNameLabel->TabIndex = 22;
			this->planeNameLabel->Text = L"Name";
			// 
			// planePt2Label
			// 
			this->planePt2Label->AutoSize = true;
			this->planePt2Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planePt2Label->Location = System::Drawing::Point(17, 224);
			this->planePt2Label->Name = L"planePt2Label";
			this->planePt2Label->Size = System::Drawing::Size(52, 15);
			this->planePt2Label->TabIndex = 21;
			this->planePt2Label->Text = L"Point 2";
			// 
			// planeCornerLabel
			// 
			this->planeCornerLabel->AutoSize = true;
			this->planeCornerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planeCornerLabel->Location = System::Drawing::Point(17, 198);
			this->planeCornerLabel->Name = L"planeCornerLabel";
			this->planeCornerLabel->Size = System::Drawing::Size(50, 15);
			this->planeCornerLabel->TabIndex = 20;
			this->planeCornerLabel->Text = L"Corner";
			// 
			// planePt1Label
			// 
			this->planePt1Label->AutoSize = true;
			this->planePt1Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planePt1Label->Location = System::Drawing::Point(17, 172);
			this->planePt1Label->Name = L"planePt1Label";
			this->planePt1Label->Size = System::Drawing::Size(52, 15);
			this->planePt1Label->TabIndex = 19;
			this->planePt1Label->Text = L"Point 1";
			// 
			// planeDataGetButton
			// 
			this->planeDataGetButton->Location = System::Drawing::Point(21, 128);
			this->planeDataGetButton->Name = L"planeDataGetButton";
			this->planeDataGetButton->Size = System::Drawing::Size(75, 23);
			this->planeDataGetButton->TabIndex = 18;
			this->planeDataGetButton->Text = L"Get Data";
			this->planeDataGetButton->UseVisualStyleBackColor = true;
			this->planeDataGetButton->Click += gcnew System::EventHandler(this, &AddObjectForm::planeDataGetButton_Click);
			// 
			// planeSetButton
			// 
			this->planeSetButton->Enabled = false;
			this->planeSetButton->Location = System::Drawing::Point(292, 253);
			this->planeSetButton->Name = L"planeSetButton";
			this->planeSetButton->Size = System::Drawing::Size(103, 23);
			this->planeSetButton->TabIndex = 17;
			this->planeSetButton->Text = L"Make Plane";
			this->planeSetButton->UseVisualStyleBackColor = true;
			this->planeSetButton->Click += gcnew System::EventHandler(this, &AddObjectForm::planeSetButton_Click);
			// 
			// planeDataPt2Label
			// 
			this->planeDataPt2Label->AutoSize = true;
			this->planeDataPt2Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planeDataPt2Label->Location = System::Drawing::Point(164, 224);
			this->planeDataPt2Label->Name = L"planeDataPt2Label";
			this->planeDataPt2Label->Size = System::Drawing::Size(84, 15);
			this->planeDataPt2Label->TabIndex = 16;
			this->planeDataPt2Label->Text = L"No data found";
			// 
			// planeDataCornerLabel
			// 
			this->planeDataCornerLabel->AutoSize = true;
			this->planeDataCornerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->planeDataCornerLabel->Location = System::Drawing::Point(164, 198);
			this->planeDataCornerLabel->Name = L"planeDataCornerLabel";
			this->planeDataCornerLabel->Size = System::Drawing::Size(84, 15);
			this->planeDataCornerLabel->TabIndex = 15;
			this->planeDataCornerLabel->Text = L"No data found";
			// 
			// planeDataPt1Label
			// 
			this->planeDataPt1Label->AutoSize = true;
			this->planeDataPt1Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->planeDataPt1Label->Location = System::Drawing::Point(164, 172);
			this->planeDataPt1Label->Name = L"planeDataPt1Label";
			this->planeDataPt1Label->Size = System::Drawing::Size(84, 15);
			this->planeDataPt1Label->TabIndex = 14;
			this->planeDataPt1Label->Text = L"No data found";
			// 
			// planeCornerTextBox
			// 
			this->planeCornerTextBox->Location = System::Drawing::Point(69, 197);
			this->planeCornerTextBox->Name = L"planeCornerTextBox";
			this->planeCornerTextBox->Size = System::Drawing::Size(82, 20);
			this->planeCornerTextBox->TabIndex = 13;
			// 
			// planePt2TextBox
			// 
			this->planePt2TextBox->Location = System::Drawing::Point(69, 223);
			this->planePt2TextBox->Name = L"planePt2TextBox";
			this->planePt2TextBox->Size = System::Drawing::Size(82, 20);
			this->planePt2TextBox->TabIndex = 12;
			// 
			// planePt1TextBox
			// 
			this->planePt1TextBox->Location = System::Drawing::Point(69, 171);
			this->planePt1TextBox->Name = L"planePt1TextBox";
			this->planePt1TextBox->Size = System::Drawing::Size(82, 20);
			this->planePt1TextBox->TabIndex = 11;
			// 
			// boxPage
			// 
			this->boxPage->Controls->Add(this->boxHTextBox);
			this->boxPage->Controls->Add(this->boxWTextBox);
			this->boxPage->Controls->Add(this->boxLTextBox);
			this->boxPage->Controls->Add(this->boxHeightLabel);
			this->boxPage->Controls->Add(this->boxWidthLabel);
			this->boxPage->Controls->Add(this->boxLengthLabel);
			this->boxPage->Controls->Add(this->boxSetButton);
			this->boxPage->Controls->Add(this->boxInCenTextBox);
			this->boxPage->Controls->Add(this->boxCoordRadio);
			this->boxPage->Controls->Add(this->boxRigidRadio);
			this->boxPage->Controls->Add(this->boxMarkersRadio);
			this->boxPage->Controls->Add(this->boxInfoLabel);
			this->boxPage->Controls->Add(this->boxOptionalLabel);
			this->boxPage->Controls->Add(this->boxNameTextBox);
			this->boxPage->Controls->Add(this->boxNameLabel);
			this->boxPage->Controls->Add(this->boxCentreLabel);
			this->boxPage->Controls->Add(this->boxGetButton);
			this->boxPage->Controls->Add(this->boxCenDataLabel);
			this->boxPage->Controls->Add(this->boxCenTextBox);
			this->boxPage->Location = System::Drawing::Point(4, 22);
			this->boxPage->Name = L"boxPage";
			this->boxPage->Padding = System::Windows::Forms::Padding(3);
			this->boxPage->Size = System::Drawing::Size(410, 287);
			this->boxPage->TabIndex = 2;
			this->boxPage->Text = L"Box";
			this->boxPage->UseVisualStyleBackColor = true;
			// 
			// boxHTextBox
			// 
			this->boxHTextBox->Location = System::Drawing::Point(212, 222);
			this->boxHTextBox->Name = L"boxHTextBox";
			this->boxHTextBox->Size = System::Drawing::Size(83, 20);
			this->boxHTextBox->TabIndex = 54;
			this->boxHTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectForm::boxTextBox_Validating);
			// 
			// boxWTextBox
			// 
			this->boxWTextBox->Location = System::Drawing::Point(123, 222);
			this->boxWTextBox->Name = L"boxWTextBox";
			this->boxWTextBox->Size = System::Drawing::Size(83, 20);
			this->boxWTextBox->TabIndex = 53;
			this->boxWTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectForm::boxTextBox_Validating);
			// 
			// boxLTextBox
			// 
			this->boxLTextBox->Location = System::Drawing::Point(34, 222);
			this->boxLTextBox->Name = L"boxLTextBox";
			this->boxLTextBox->Size = System::Drawing::Size(83, 20);
			this->boxLTextBox->TabIndex = 52;
			this->boxLTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectForm::boxTextBox_Validating);
			// 
			// boxHeightLabel
			// 
			this->boxHeightLabel->AutoSize = true;
			this->boxHeightLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxHeightLabel->Location = System::Drawing::Point(209, 204);
			this->boxHeightLabel->Name = L"boxHeightLabel";
			this->boxHeightLabel->Size = System::Drawing::Size(71, 15);
			this->boxHeightLabel->TabIndex = 51;
			this->boxHeightLabel->Text = L"Height (Z)";
			// 
			// boxWidthLabel
			// 
			this->boxWidthLabel->AutoSize = true;
			this->boxWidthLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxWidthLabel->Location = System::Drawing::Point(120, 204);
			this->boxWidthLabel->Name = L"boxWidthLabel";
			this->boxWidthLabel->Size = System::Drawing::Size(65, 15);
			this->boxWidthLabel->TabIndex = 50;
			this->boxWidthLabel->Text = L"Width (Y)";
			// 
			// boxLengthLabel
			// 
			this->boxLengthLabel->AutoSize = true;
			this->boxLengthLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxLengthLabel->Location = System::Drawing::Point(31, 204);
			this->boxLengthLabel->Name = L"boxLengthLabel";
			this->boxLengthLabel->Size = System::Drawing::Size(74, 15);
			this->boxLengthLabel->TabIndex = 49;
			this->boxLengthLabel->Text = L"Length (X)";
			// 
			// boxSetButton
			// 
			this->boxSetButton->Enabled = false;
			this->boxSetButton->Location = System::Drawing::Point(292, 253);
			this->boxSetButton->Name = L"boxSetButton";
			this->boxSetButton->Size = System::Drawing::Size(103, 23);
			this->boxSetButton->TabIndex = 48;
			this->boxSetButton->Text = L"Make Box";
			this->boxSetButton->UseVisualStyleBackColor = true;
			this->boxSetButton->Click += gcnew System::EventHandler(this, &AddObjectForm::boxSetButton_Click);
			// 
			// boxInCenTextBox
			// 
			this->boxInCenTextBox->Location = System::Drawing::Point(108, 171);
			this->boxInCenTextBox->Name = L"boxInCenTextBox";
			this->boxInCenTextBox->Size = System::Drawing::Size(220, 20);
			this->boxInCenTextBox->TabIndex = 47;
			this->boxInCenTextBox->Visible = false;
			this->boxInCenTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddObjectForm::boxTextBox_Validating);
			// 
			// boxCoordRadio
			// 
			this->boxCoordRadio->AutoSize = true;
			this->boxCoordRadio->Location = System::Drawing::Point(257, 93);
			this->boxCoordRadio->Name = L"boxCoordRadio";
			this->boxCoordRadio->Size = System::Drawing::Size(81, 17);
			this->boxCoordRadio->TabIndex = 46;
			this->boxCoordRadio->TabStop = true;
			this->boxCoordRadio->Text = L"Coordinates";
			this->boxCoordRadio->UseVisualStyleBackColor = true;
			this->boxCoordRadio->CheckedChanged += gcnew System::EventHandler(this, &AddObjectForm::boxCoordRadio_CheckedChanged);
			// 
			// boxRigidRadio
			// 
			this->boxRigidRadio->AutoSize = true;
			this->boxRigidRadio->Location = System::Drawing::Point(148, 93);
			this->boxRigidRadio->Name = L"boxRigidRadio";
			this->boxRigidRadio->Size = System::Drawing::Size(100, 17);
			this->boxRigidRadio->TabIndex = 43;
			this->boxRigidRadio->Text = L"Rigid Body Tool";
			this->boxRigidRadio->UseVisualStyleBackColor = true;
			// 
			// boxMarkersRadio
			// 
			this->boxMarkersRadio->AutoSize = true;
			this->boxMarkersRadio->Checked = true;
			this->boxMarkersRadio->Location = System::Drawing::Point(67, 93);
			this->boxMarkersRadio->Name = L"boxMarkersRadio";
			this->boxMarkersRadio->Size = System::Drawing::Size(63, 17);
			this->boxMarkersRadio->TabIndex = 42;
			this->boxMarkersRadio->TabStop = true;
			this->boxMarkersRadio->Text = L"Markers";
			this->boxMarkersRadio->UseVisualStyleBackColor = true;
			this->boxMarkersRadio->CheckedChanged += gcnew System::EventHandler(this, &AddObjectForm::boxMarkerRadio_CheckedChanged);
			// 
			// boxInfoLabel
			// 
			this->boxInfoLabel->AutoSize = true;
			this->boxInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxInfoLabel->Location = System::Drawing::Point(18, 21);
			this->boxInfoLabel->Name = L"boxInfoLabel";
			this->boxInfoLabel->Size = System::Drawing::Size(127, 15);
			this->boxInfoLabel->TabIndex = 41;
			this->boxInfoLabel->Text = L"Add a box to the world";
			// 
			// boxOptionalLabel
			// 
			this->boxOptionalLabel->AutoSize = true;
			this->boxOptionalLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->boxOptionalLabel->Location = System::Drawing::Point(254, 60);
			this->boxOptionalLabel->Name = L"boxOptionalLabel";
			this->boxOptionalLabel->Size = System::Drawing::Size(44, 13);
			this->boxOptionalLabel->TabIndex = 40;
			this->boxOptionalLabel->Text = L"optional";
			// 
			// boxNameTextBox
			// 
			this->boxNameTextBox->Location = System::Drawing::Point(69, 57);
			this->boxNameTextBox->Name = L"boxNameTextBox";
			this->boxNameTextBox->Size = System::Drawing::Size(179, 20);
			this->boxNameTextBox->TabIndex = 39;
			// 
			// boxNameLabel
			// 
			this->boxNameLabel->AutoSize = true;
			this->boxNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxNameLabel->Location = System::Drawing::Point(18, 58);
			this->boxNameLabel->Name = L"boxNameLabel";
			this->boxNameLabel->Size = System::Drawing::Size(45, 15);
			this->boxNameLabel->TabIndex = 38;
			this->boxNameLabel->Text = L"Name";
			// 
			// boxCentreLabel
			// 
			this->boxCentreLabel->AutoSize = true;
			this->boxCentreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxCentreLabel->Location = System::Drawing::Point(17, 172);
			this->boxCentreLabel->Name = L"boxCentreLabel";
			this->boxCentreLabel->Size = System::Drawing::Size(85, 15);
			this->boxCentreLabel->TabIndex = 37;
			this->boxCentreLabel->Text = L"Base Centre";
			// 
			// boxGetButton
			// 
			this->boxGetButton->Location = System::Drawing::Point(21, 128);
			this->boxGetButton->Name = L"boxGetButton";
			this->boxGetButton->Size = System::Drawing::Size(75, 23);
			this->boxGetButton->TabIndex = 36;
			this->boxGetButton->Text = L"Get Data";
			this->boxGetButton->UseVisualStyleBackColor = true;
			this->boxGetButton->Click += gcnew System::EventHandler(this, &AddObjectForm::boxGetButton_Click);
			// 
			// boxCenDataLabel
			// 
			this->boxCenDataLabel->AutoSize = true;
			this->boxCenDataLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxCenDataLabel->Location = System::Drawing::Point(101, 131);
			this->boxCenDataLabel->Name = L"boxCenDataLabel";
			this->boxCenDataLabel->Size = System::Drawing::Size(84, 15);
			this->boxCenDataLabel->TabIndex = 35;
			this->boxCenDataLabel->Text = L"No data found";
			// 
			// boxCenTextBox
			// 
			this->boxCenTextBox->Location = System::Drawing::Point(108, 171);
			this->boxCenTextBox->Name = L"boxCenTextBox";
			this->boxCenTextBox->Size = System::Drawing::Size(79, 20);
			this->boxCenTextBox->TabIndex = 34;
			// 
			// AddObjectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 311);
			this->Controls->Add(this->tabControl1);
			this->Name = L"AddObjectForm";
			this->Text = L"Add Object ";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AddObjectForm::AddObjectForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &AddObjectForm::AddObjectForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->planePage->ResumeLayout(false);
			this->planePage->PerformLayout();
			this->boxPage->ResumeLayout(false);
			this->boxPage->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

///////////////////////////
// local variables
///////////////////////////
private: osg::Vec3* planePos1;
private: osg::Vec3* planePosC;
private: osg::Vec3* planePos2;
private: osg::Vec3* planePos;
private: osg::Vec3* boxPosCen;

///////////////////////////
// util functions
///////////////////////////
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
			 return new std::string( (const char*) (Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str)).ToPointer());
		 }
		 // checks if input string is a valid coordinate (x, y, z)
private: bool isCoordinate(String^ str) {
			 String^ regs = "^\\s*-?\\d+(.\\d+)?\\s*," + 
							"\\s*-?\\d+(.\\d+)?\\s*," +
							"\\s*-?\\d+(.\\d+)?\\s*$";
			 System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(regs);
			 return regex->IsMatch(str);
		 }
		 // checks if input string is a valid float
private: bool isFloat(String^ str) {
			 String^ regs = "^\\s*-?\\d+(.\\d+)?\\s*$";
			 System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(regs);
			 return regex->IsMatch(str);
		 }
		 // extracts coordinates from input text box
private: bool extractCoordinates(TextBox^ tb, osg::Vec3* pt) {
			 if (!pt || !tb)
				 return false;

			 float x, y, z;
			 array<String^>^ split = tb->Text->Split(gcnew array<wchar_t> {','});
			 if (!Single::TryParse(split[0], x))
				 return false;
			 if (!Single::TryParse(split[1], y))
				 return false;
			 if (!Single::TryParse(split[2], z))
				 return false;

			 pt->set(x, y, z);
			 return true;
		 }
		 // set visible/not visible for buttons associated with rigid body view
private: System::Void rigidSetButtons(bool enable, bool visible, ObjectType type) {
			 switch (type)
			 {
			 // plane
			 case OBJ_PLANE :
				 this->planePt1SetButton->Visible = visible;
				 this->planePt1SetButton->Enabled = enable;
				 
				 this->planeCornerSetButton->Visible = visible;
				 this->planeCornerSetButton->Enabled = enable;
				 
				 this->planePt2SetButton->Visible = visible;
				 this->planePt2SetButton->Enabled = enable;
				 break;


			 }
		 }
		 // set visible/not visible for text boxes associated with markers view
private: System::Void markerTextBoxes(bool visible, ObjectType type) {
			 switch (type)
			 {
			 // plane
			 case OBJ_PLANE :
				 this->planePt1TextBox->Visible = visible;
				 this->planeCornerTextBox->Visible = visible;
				 this->planePt2TextBox->Visible = visible;
				 break;
			 case OBJ_BOX :
				 this->boxCenTextBox->Visible = visible;
				 break;

			 }
		 }
		 	 // set visible/not visible for text boxes associated with coordinates view
private: System::Void coordinateTextBoxes(bool visible, ObjectType type) {
			 switch (type)
			 {
			 // plane
			 case OBJ_PLANE :
				 this->planeInPt1TextBox->Visible = visible;
				 this->planeInCornerTextBox->Visible = visible;
				 this->planeInPt2TextBox->Visible = visible;
				 break;
			 case OBJ_BOX :
				 this->boxInCenTextBox->Visible = visible;

			 }
		 }

///////////////////////////
// form functions
///////////////////////////
private: System::Void AddObjectForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		 	if (planePos1)	delete planePos1;
			if (planePosC)	delete planePosC;
			if (planePos2)	delete planePos2;
			if (planePos)	delete planePos;
			if (boxPosCen)	delete boxPosCen;
		 }
		 // set enable/disable, visible/not visible for buttons associated with rigid body tool view
private: System::Void AddObjectForm_Load(System::Object^  sender, System::EventArgs^  e) {
			this->defaultDataText = L"No data found";
			planePos1	= new osg::Vec3();
			planePosC	= new osg::Vec3();
			planePos2	= new osg::Vec3();
			planePos	= new osg::Vec3();
			boxPosCen	= new osg::Vec3();
		 }

///////////////////////////
// plane functions
///////////////////////////
		 // get data from client
		 // markers: based on ID in each text field
		 // rigid body: based on chosen rigid body tool
		 // coordinate: based on input (validated)
private: System::Void planeDataGetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			ClientHandler* client = AppData::getInstance()->getClient();
			// use markers
			if (this->planeMarkersRadio->Checked && client->lock())
			{
				Marker* marker;
				bool result;
				int id;
				this->planeSetButton->Enabled = true;
				
				// point 1
				result = Int32::TryParse(this->planePt1TextBox->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					setDefaultText(this->planeDataPt1Label);
					this->planeSetButton->Enabled = false;
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					planePos1->set(pt.x(), pt.y(), pt.z());
					setPoint(planePos1, this->planeDataPt1Label);
				}
				
				// corner
				result = Int32::TryParse(this->planeCornerTextBox->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					setDefaultText(this->planeDataCornerLabel);
					this->planeSetButton->Enabled = false;
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					planePosC->set(pt.x(), pt.y(), pt.z());
					setPoint(planePosC, this->planeDataCornerLabel);
				}
				
				// point 2
				result = Int32::TryParse(this->planePt2TextBox->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					setDefaultText(this->planeDataPt2Label);
					this->planeSetButton->Enabled = false;
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					planePos2->set(pt.x(), pt.y(), pt.z());
					setPoint(planePos2, this->planeDataPt2Label);
				}
					client->unlock();
			}
			// use rigid tool
			else if (this->planeRigidRadio->Checked && client)
			{
				RigidBody* body = client->getRigidBody(client->getRigidBodyTool());
				if (body)
				{
					planePos->set(body->getPosition().x(), 
							body->getPosition().y(), 
							body->getPosition().z());
					setPoint(planePos, this->planeRigidDataLabel);
					rigidSetButtons(true, true, OBJ_PLANE);
					return;
				}
			}
		}
		 // add plane to world based on data from posC, pos1, pos2
private: System::Void planeSetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->planeCoordRadio->Checked && !planeExtractCoordinates())
				 return;

			 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayWorld);
			 if (world)
			 {
				 std::string* str = managedToStdString(this->planeNameTextBox->Text);
				 CaptureObject* object = world->addPlane(*planePosC, *planePos1, *planePos2, *str);
				 if (object)
				 {
					 String^ id = Convert::ToString(object->getID());
					 String^ name = gcnew String(object->getName().c_str());
				 }
			 }
			 this->Close();
		 }
private: System::Void planeRigidRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->planeRigidRadio->Checked)
			 {
				 rigidSetButtons(false, true, OBJ_PLANE);

				 setDefaultText(this->planeRigidDataLabel);
				 setDefaultText(this->planeDataPt1Label);
				 setDefaultText(this->planeDataCornerLabel);
				 setDefaultText(this->planeDataPt2Label);				 

				 this->planeRigidDataLabel->Visible = true;
				 this->planeSetButton->Enabled = false;
			 }
			 else
			 {
				 rigidSetButtons(false, false, OBJ_PLANE);

				 this->planeRigidDataLabel->Visible = false;
			 }
		 }
private: System::Void planeMarkersRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->planeMarkersRadio->Checked)
			 {
				 markerTextBoxes(true, OBJ_PLANE);

				 setDefaultText(this->planeDataPt1Label);
				 setDefaultText(this->planeDataCornerLabel);
				 setDefaultText(this->planeDataPt2Label);				 

				 this->planeSetButton->Enabled = false;
			 }
			 else
			 {
				 markerTextBoxes(false, OBJ_PLANE);
			 }
		 }
private: System::Void planeCoordRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->planeCoordRadio->Checked)
			 {
				 coordinateTextBoxes(true, OBJ_PLANE);

				 this->planeDataPt1Label->Text = "";
				 this->planeDataCornerLabel->Text = "";
				 this->planeDataPt2Label->Text = "";

				 this->planeSetButton->Enabled = false;
				 this->planeDataGetButton->Visible = false;
			 }
			 else
			 {
				 coordinateTextBoxes(false, OBJ_PLANE);
				 this->planeDataGetButton->Visible = true;
			 }
		 }
		 // populate vectors based on coordinate input
private: bool planeExtractCoordinates()
		 {
			 if (!extractCoordinates(this->planeInPt1TextBox, planePos1))
				 return false;

			 if (!extractCoordinates(this->planeInCornerTextBox, planePosC))
				 return false;

			 if (!extractCoordinates(this->planeInPt2TextBox, planePos2))
				 return false;

			 return true;
		 }
		 // change visibility of form objects based on which radio button is checked
		 // gets data from rigid body tool and sets it to one of the three points
private: System::Void planeSetDataButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if (sender == this->planePt1SetButton)
			{
				planePos1->set(planePos->x(), planePos->y(), planePos->z());
				setPoint(planePos, this->planeDataPt1Label);
					 
				if ( String::Compare(this->planeDataCornerLabel->Text, this->defaultDataText) &&
					String::Compare(this->planeDataPt2Label->Text, this->defaultDataText) )
					this->planeSetButton->Enabled = true;
				else
					this->planeSetButton->Enabled = false;
			}
			else if (sender == this->planeCornerSetButton)
			{
				planePosC->set(planePos->x(), planePos->y(), planePos->z());
				setPoint(planePos, this->planeDataCornerLabel);

				if ( String::Compare(this->planeDataPt1Label->Text, this->defaultDataText) &&
					String::Compare(this->planeDataPt2Label->Text, this->defaultDataText) )
					this->planeSetButton->Enabled = true;
				else
					this->planeSetButton->Enabled = false;
			}
			else if (sender == this->planePt2SetButton)
			{
				planePos2->set(planePos->x(), planePos->y(), planePos->z());
				setPoint(planePos, this->planeDataPt2Label);

				if ( String::Compare(this->planeDataPt1Label->Text, this->defaultDataText) &&
					String::Compare(this->planeDataCornerLabel->Text, this->defaultDataText) )
					this->planeSetButton->Enabled = true;
				else
					this->planeSetButton->Enabled = false;
			}
		}
private: System::Void planeTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 if (sender == this->planeInPt1TextBox && 
				 isCoordinate(this->planeInPt1TextBox->Text))
			 {
				 if ( isCoordinate(this->planeInCornerTextBox->Text) &&
					  isCoordinate(this->planeInPt2TextBox->Text) )
				 {
					  this->planeSetButton->Enabled = true;
				 }
			 }
			 else if (sender == this->planeInCornerTextBox && 
				 isCoordinate(this->planeInCornerTextBox->Text))
			 {
				 if ( isCoordinate(this->planeInPt1TextBox->Text) &&
					  isCoordinate(this->planeInPt2TextBox->Text) )
				 {
					  this->planeSetButton->Enabled = true;
				 }
			 }
			 else if (sender == this->planeInPt2TextBox && 
				 isCoordinate(this->planeInPt2TextBox->Text))
			 {
				 if ( isCoordinate(this->planeInPt1TextBox->Text) &&
					  isCoordinate(this->planeInCornerTextBox->Text) )
				 {
					  this->planeSetButton->Enabled = true;
				 }
			 }
			 else
			 {
				 this->planeSetButton->Enabled = false;
			 }

		 }

///////////////////////////
// box functions
///////////////////////////

private: System::Void boxGetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			ClientHandler* client = AppData::getInstance()->getClient();
			// use markers
			if (this->boxMarkersRadio->Checked && client->lock())
			{
				Marker* marker;
				bool result;
				int id;
				this->boxSetButton->Enabled = true;
				
				result = Int32::TryParse(this->boxCenTextBox->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					setDefaultText(this->boxCenDataLabel);
					this->boxSetButton->Enabled = false;
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					boxPosCen->set(pt.x(), pt.y(), pt.z());
					setPoint(boxPosCen, this->boxCenDataLabel);

					if (isFloat(this->boxLTextBox->Text) &&
						isFloat(this->boxWTextBox->Text) &&
						isFloat(this->boxHTextBox->Text))
						 this->boxSetButton->Enabled = true;
				}

				client->unlock();
			}
			// use rigid tool
			else if (this->boxRigidRadio->Checked && client)
			{
				RigidBody* body = client->getRigidBody(client->getRigidBodyTool());
				if (body)
				{
					boxPosCen->set(body->getPosition().x(), 
							body->getPosition().y(), 
							body->getPosition().z());
					setPoint(boxPosCen, this->boxCenDataLabel);

					if (isFloat(this->boxLTextBox->Text) &&
						isFloat(this->boxWTextBox->Text) &&
						isFloat(this->boxHTextBox->Text))
						 this->boxSetButton->Enabled = true;

					return;
				}
			}
		 }
private: System::Void boxSetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->boxCoordRadio->Checked && !extractCoordinates(this->boxInCenTextBox, boxPosCen))
				 return;
			 
			 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayWorld);
			 if (world)
			 {
				 std::string* str = managedToStdString(this->boxNameTextBox->Text);
				 float l, w, h;
				 
				 l = Single::Parse(this->boxLTextBox->Text);
				 w = Single::Parse(this->boxWTextBox->Text);
				 h = Single::Parse(this->boxHTextBox->Text);

				 CaptureObject* object = world->addBox(*boxPosCen, osg::Vec3(l, w, h), *str);
				 if (object)
				 {
					 String^ id = Convert::ToString(object->getID());
					 String^ name = gcnew String(object->getName().c_str());
				 }
			 }
			 this->Close();
		 }
private: System::Void boxMarkerRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->boxMarkersRadio->Checked)
			 {
				 markerTextBoxes(true, OBJ_BOX);
				 setDefaultText(this->boxCenDataLabel);

				 this->planeSetButton->Enabled = false;
			 }
			 else
			 {
				 markerTextBoxes(false, OBJ_BOX);
			 }
		 }
private: System::Void boxCoordRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->boxCoordRadio->Checked)
			 {
				 coordinateTextBoxes(true, OBJ_BOX);

				 this->boxCenDataLabel->Text = "";

				 this->boxSetButton->Enabled = false;
				 this->boxGetButton->Visible = false;
			 }
			 else
			 {
				 coordinateTextBoxes(false, OBJ_BOX);
				 this->boxGetButton->Visible = true;
			 }
		 }
private: System::Void boxTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 if ( this->boxCoordRadio->Checked &&
				 isCoordinate(this->boxInCenTextBox->Text) &&
				 isFloat(this->boxLTextBox->Text) &&
				 isFloat(this->boxWTextBox->Text) &&
				 isFloat(this->boxHTextBox->Text) )
				 this->boxSetButton->Enabled = true;
			 else if ( !this->boxCoordRadio->Checked &&
					 String::Compare(this->boxCenDataLabel->Text, this->defaultDataText) &&
					 isFloat(this->boxLTextBox->Text) &&
					 isFloat(this->boxWTextBox->Text) &&
					 isFloat(this->boxHTextBox->Text) )
				 this->boxSetButton->Enabled = true;
			 else
				 this->boxSetButton->Enabled = false;
		 }

};

}
