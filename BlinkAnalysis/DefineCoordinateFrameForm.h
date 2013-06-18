#pragma once

#include "AppData.h"
#include "CaptureObjectUtil.h"

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DefineCoordinateFrameForm
	/// </summary>
	public ref class DefineCoordinateFrameForm : public System::Windows::Forms::Form
	{
	public:
		DefineCoordinateFrameForm(void)
		{
			InitializeComponent();
			displayWorld = -1;
		}

		void setDisplayWorld(int id) { displayWorld = id; }
		int getDisplayWorld() { return displayWorld; }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DefineCoordinateFrameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  CoordinateFramePages;
	protected: 

	protected: 
	private: System::Windows::Forms::TabPage^  infoPage;
	private: System::Windows::Forms::TabPage^  markerPage;
	private: System::Windows::Forms::TabPage^  rigidPage;
	private: System::Windows::Forms::TextBox^  coordinateOTextBox;
	private: System::Windows::Forms::TextBox^  coordinateXTextBox;
	private: System::Windows::Forms::TextBox^  coordinateYTextBox;
	private: System::Windows::Forms::Label^  coordinateOLabel;
	private: System::Windows::Forms::Button^  coordinateSetButton;
	private: System::Windows::Forms::Label^  coordinateYLabel;


	private: System::Windows::Forms::Label^  coordinateXLabel;

	private: System::Windows::Forms::Button^  coordinateGetButton;
	private: System::Windows::Forms::Button^  coordinateResetButton;
	private: System::Windows::Forms::Label^  originLabel;
	private: System::Windows::Forms::Label^  yLabel;

	private: System::Windows::Forms::Label^  xLabel;
	private: System::Windows::Forms::Label^  infoLabel;
	private: System::Windows::Forms::Label^  markerLabel;






	private: System::Windows::Forms::Label^  infoTitleLabel;
	private: System::Windows::Forms::Label^  rigidBodyLabel;
	private: System::Windows::Forms::Label^  rigidToolPositionLabel;
	private: System::Windows::Forms::Button^  rigidGetDataButton;
	private: System::Windows::Forms::Button^  coordinateSetButton2;
	private: System::Windows::Forms::Button^  rigidYButton;
	private: System::Windows::Forms::Button^  rigidXButton;
	private: System::Windows::Forms::Button^  rigidOButton;
	private: System::Windows::Forms::Label^  rigidYLabel;
	private: System::Windows::Forms::Label^  rigidXLabel;
	private: System::Windows::Forms::Label^  rigidOLabel;
	
	// added variables
	private: System::String^ defaultDataText;
	private: int displayWorld;
	private: System::Windows::Forms::Label^  rigidInfoLabel;
	private: System::Windows::Forms::Label^  inputInfoLabel;
	private: System::Windows::Forms::Label^  inputYLabel;


	private: System::Windows::Forms::Label^  inputXLabel;
	private: System::Windows::Forms::Label^  inputOLabel;
	private: System::Windows::Forms::Button^  inputSetButton;
	private: System::Windows::Forms::TextBox^  inputXTextBox;
	private: System::Windows::Forms::TextBox^  inputYTextBox;










	private: System::Windows::Forms::TextBox^  inputOTextBox;



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
			System::Windows::Forms::TabPage^  inputPage;
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(DefineCoordinateFrameForm::typeid));
			this->inputInfoLabel = (gcnew System::Windows::Forms::Label());
			this->inputYLabel = (gcnew System::Windows::Forms::Label());
			this->inputXLabel = (gcnew System::Windows::Forms::Label());
			this->inputOLabel = (gcnew System::Windows::Forms::Label());
			this->inputSetButton = (gcnew System::Windows::Forms::Button());
			this->inputXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->inputYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->inputOTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CoordinateFramePages = (gcnew System::Windows::Forms::TabControl());
			this->infoPage = (gcnew System::Windows::Forms::TabPage());
			this->infoTitleLabel = (gcnew System::Windows::Forms::Label());
			this->infoLabel = (gcnew System::Windows::Forms::Label());
			this->coordinateResetButton = (gcnew System::Windows::Forms::Button());
			this->markerPage = (gcnew System::Windows::Forms::TabPage());
			this->markerLabel = (gcnew System::Windows::Forms::Label());
			this->yLabel = (gcnew System::Windows::Forms::Label());
			this->xLabel = (gcnew System::Windows::Forms::Label());
			this->originLabel = (gcnew System::Windows::Forms::Label());
			this->coordinateGetButton = (gcnew System::Windows::Forms::Button());
			this->coordinateSetButton = (gcnew System::Windows::Forms::Button());
			this->coordinateYLabel = (gcnew System::Windows::Forms::Label());
			this->coordinateXLabel = (gcnew System::Windows::Forms::Label());
			this->coordinateOLabel = (gcnew System::Windows::Forms::Label());
			this->coordinateXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->coordinateYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->coordinateOTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rigidPage = (gcnew System::Windows::Forms::TabPage());
			this->rigidInfoLabel = (gcnew System::Windows::Forms::Label());
			this->rigidYButton = (gcnew System::Windows::Forms::Button());
			this->rigidXButton = (gcnew System::Windows::Forms::Button());
			this->rigidOButton = (gcnew System::Windows::Forms::Button());
			this->rigidYLabel = (gcnew System::Windows::Forms::Label());
			this->rigidXLabel = (gcnew System::Windows::Forms::Label());
			this->rigidOLabel = (gcnew System::Windows::Forms::Label());
			this->coordinateSetButton2 = (gcnew System::Windows::Forms::Button());
			this->rigidGetDataButton = (gcnew System::Windows::Forms::Button());
			this->rigidToolPositionLabel = (gcnew System::Windows::Forms::Label());
			this->rigidBodyLabel = (gcnew System::Windows::Forms::Label());
			inputPage = (gcnew System::Windows::Forms::TabPage());
			inputPage->SuspendLayout();
			this->CoordinateFramePages->SuspendLayout();
			this->infoPage->SuspendLayout();
			this->markerPage->SuspendLayout();
			this->rigidPage->SuspendLayout();
			this->SuspendLayout();
			// 
			// inputPage
			// 
			inputPage->Controls->Add(this->inputInfoLabel);
			inputPage->Controls->Add(this->inputYLabel);
			inputPage->Controls->Add(this->inputXLabel);
			inputPage->Controls->Add(this->inputOLabel);
			inputPage->Controls->Add(this->inputSetButton);
			inputPage->Controls->Add(this->inputXTextBox);
			inputPage->Controls->Add(this->inputYTextBox);
			inputPage->Controls->Add(this->inputOTextBox);
			inputPage->Location = System::Drawing::Point(4, 22);
			inputPage->Name = L"inputPage";
			inputPage->Padding = System::Windows::Forms::Padding(3);
			inputPage->Size = System::Drawing::Size(416, 285);
			inputPage->TabIndex = 2;
			inputPage->Text = L"Input";
			inputPage->UseVisualStyleBackColor = true;
			// 
			// inputInfoLabel
			// 
			this->inputInfoLabel->AutoSize = true;
			this->inputInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->inputInfoLabel->Location = System::Drawing::Point(17, 15);
			this->inputInfoLabel->Name = L"inputInfoLabel";
			this->inputInfoLabel->Size = System::Drawing::Size(313, 30);
			this->inputInfoLabel->TabIndex = 23;
			this->inputInfoLabel->Text = L"Enter the positions of where you wish to specify the axes.\r\n\r\n";
			// 
			// inputYLabel
			// 
			this->inputYLabel->AutoSize = true;
			this->inputYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->inputYLabel->Location = System::Drawing::Point(17, 186);
			this->inputYLabel->Name = L"inputYLabel";
			this->inputYLabel->Size = System::Drawing::Size(46, 15);
			this->inputYLabel->TabIndex = 22;
			this->inputYLabel->Text = L"Y-Axis";
			// 
			// inputXLabel
			// 
			this->inputXLabel->AutoSize = true;
			this->inputXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->inputXLabel->Location = System::Drawing::Point(17, 145);
			this->inputXLabel->Name = L"inputXLabel";
			this->inputXLabel->Size = System::Drawing::Size(47, 15);
			this->inputXLabel->TabIndex = 21;
			this->inputXLabel->Text = L"X-Axis";
			// 
			// inputOLabel
			// 
			this->inputOLabel->AutoSize = true;
			this->inputOLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->inputOLabel->Location = System::Drawing::Point(17, 99);
			this->inputOLabel->Name = L"inputOLabel";
			this->inputOLabel->Size = System::Drawing::Size(46, 15);
			this->inputOLabel->TabIndex = 20;
			this->inputOLabel->Text = L"Origin";
			// 
			// inputSetButton
			// 
			this->inputSetButton->Enabled = false;
			this->inputSetButton->Location = System::Drawing::Point(291, 241);
			this->inputSetButton->Name = L"inputSetButton";
			this->inputSetButton->Size = System::Drawing::Size(103, 23);
			this->inputSetButton->TabIndex = 18;
			this->inputSetButton->Text = L"Set Coordinates";
			this->inputSetButton->UseVisualStyleBackColor = true;
			this->inputSetButton->Click += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::coordinateSetButton_Click);
			// 
			// inputXTextBox
			// 
			this->inputXTextBox->Location = System::Drawing::Point(69, 144);
			this->inputXTextBox->Name = L"inputXTextBox";
			this->inputXTextBox->Size = System::Drawing::Size(230, 20);
			this->inputXTextBox->TabIndex = 14;
			this->inputXTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &DefineCoordinateFrameForm::inputTextBox_Validating);
			// 
			// inputYTextBox
			// 
			this->inputYTextBox->Location = System::Drawing::Point(69, 185);
			this->inputYTextBox->Name = L"inputYTextBox";
			this->inputYTextBox->Size = System::Drawing::Size(230, 20);
			this->inputYTextBox->TabIndex = 13;
			this->inputYTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &DefineCoordinateFrameForm::inputTextBox_Validating);
			// 
			// inputOTextBox
			// 
			this->inputOTextBox->Location = System::Drawing::Point(69, 99);
			this->inputOTextBox->Name = L"inputOTextBox";
			this->inputOTextBox->Size = System::Drawing::Size(230, 20);
			this->inputOTextBox->TabIndex = 12;
			this->inputOTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &DefineCoordinateFrameForm::inputTextBox_Validating);
			// 
			// CoordinateFramePages
			// 
			this->CoordinateFramePages->Controls->Add(this->infoPage);
			this->CoordinateFramePages->Controls->Add(this->markerPage);
			this->CoordinateFramePages->Controls->Add(this->rigidPage);
			this->CoordinateFramePages->Controls->Add(inputPage);
			this->CoordinateFramePages->Location = System::Drawing::Point(0, 0);
			this->CoordinateFramePages->Name = L"CoordinateFramePages";
			this->CoordinateFramePages->SelectedIndex = 0;
			this->CoordinateFramePages->Size = System::Drawing::Size(424, 311);
			this->CoordinateFramePages->TabIndex = 0;
			// 
			// infoPage
			// 
			this->infoPage->BackColor = System::Drawing::Color::White;
			this->infoPage->Controls->Add(this->infoTitleLabel);
			this->infoPage->Controls->Add(this->infoLabel);
			this->infoPage->Controls->Add(this->coordinateResetButton);
			this->infoPage->Location = System::Drawing::Point(4, 22);
			this->infoPage->Name = L"infoPage";
			this->infoPage->Padding = System::Windows::Forms::Padding(3);
			this->infoPage->Size = System::Drawing::Size(416, 285);
			this->infoPage->TabIndex = 0;
			this->infoPage->Text = L"Info";
			// 
			// infoTitleLabel
			// 
			this->infoTitleLabel->AutoSize = true;
			this->infoTitleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->infoTitleLabel->Location = System::Drawing::Point(8, 12);
			this->infoTitleLabel->Name = L"infoTitleLabel";
			this->infoTitleLabel->Size = System::Drawing::Size(258, 30);
			this->infoTitleLabel->TabIndex = 2;
			this->infoTitleLabel->Text = L"Define Coordinate Frame";
			// 
			// infoLabel
			// 
			this->infoLabel->AutoSize = true;
			this->infoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->infoLabel->Location = System::Drawing::Point(8, 61);
			this->infoLabel->Name = L"infoLabel";
			this->infoLabel->Size = System::Drawing::Size(387, 165);
			this->infoLabel->TabIndex = 1;
			this->infoLabel->Text = resources->GetString(L"infoLabel.Text");
			// 
			// coordinateResetButton
			// 
			this->coordinateResetButton->Location = System::Drawing::Point(270, 239);
			this->coordinateResetButton->Name = L"coordinateResetButton";
			this->coordinateResetButton->Size = System::Drawing::Size(125, 23);
			this->coordinateResetButton->TabIndex = 0;
			this->coordinateResetButton->Text = L"Reset Coordinates";
			this->coordinateResetButton->UseVisualStyleBackColor = true;
			this->coordinateResetButton->Click += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::coordinateResetButton_Click);
			// 
			// markerPage
			// 
			this->markerPage->BackColor = System::Drawing::SystemColors::ControlLight;
			this->markerPage->Controls->Add(this->markerLabel);
			this->markerPage->Controls->Add(this->yLabel);
			this->markerPage->Controls->Add(this->xLabel);
			this->markerPage->Controls->Add(this->originLabel);
			this->markerPage->Controls->Add(this->coordinateGetButton);
			this->markerPage->Controls->Add(this->coordinateSetButton);
			this->markerPage->Controls->Add(this->coordinateYLabel);
			this->markerPage->Controls->Add(this->coordinateXLabel);
			this->markerPage->Controls->Add(this->coordinateOLabel);
			this->markerPage->Controls->Add(this->coordinateXTextBox);
			this->markerPage->Controls->Add(this->coordinateYTextBox);
			this->markerPage->Controls->Add(this->coordinateOTextBox);
			this->markerPage->Location = System::Drawing::Point(4, 22);
			this->markerPage->Name = L"markerPage";
			this->markerPage->Padding = System::Windows::Forms::Padding(3);
			this->markerPage->Size = System::Drawing::Size(416, 285);
			this->markerPage->TabIndex = 1;
			this->markerPage->Text = L"Markers";
			// 
			// markerLabel
			// 
			this->markerLabel->AutoSize = true;
			this->markerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->markerLabel->Location = System::Drawing::Point(17, 15);
			this->markerLabel->Name = L"markerLabel";
			this->markerLabel->Size = System::Drawing::Size(370, 45);
			this->markerLabel->TabIndex = 11;
			this->markerLabel->Text = L"Enter the IDs of the markers you wish to use for specifying the axes.\r\n\r\nClick \"G" 
				L"et Data\" to retrieve the marker positions.";
			// 
			// yLabel
			// 
			this->yLabel->AutoSize = true;
			this->yLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->yLabel->Location = System::Drawing::Point(17, 186);
			this->yLabel->Name = L"yLabel";
			this->yLabel->Size = System::Drawing::Size(46, 15);
			this->yLabel->TabIndex = 10;
			this->yLabel->Text = L"Y-Axis";
			// 
			// xLabel
			// 
			this->xLabel->AutoSize = true;
			this->xLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->xLabel->Location = System::Drawing::Point(17, 145);
			this->xLabel->Name = L"xLabel";
			this->xLabel->Size = System::Drawing::Size(47, 15);
			this->xLabel->TabIndex = 9;
			this->xLabel->Text = L"X-Axis";
			// 
			// originLabel
			// 
			this->originLabel->AutoSize = true;
			this->originLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->originLabel->Location = System::Drawing::Point(17, 99);
			this->originLabel->Name = L"originLabel";
			this->originLabel->Size = System::Drawing::Size(46, 15);
			this->originLabel->TabIndex = 8;
			this->originLabel->Text = L"Origin";
			// 
			// coordinateGetButton
			// 
			this->coordinateGetButton->Location = System::Drawing::Point(20, 241);
			this->coordinateGetButton->Name = L"coordinateGetButton";
			this->coordinateGetButton->Size = System::Drawing::Size(75, 23);
			this->coordinateGetButton->TabIndex = 7;
			this->coordinateGetButton->Text = L"Get Data";
			this->coordinateGetButton->UseVisualStyleBackColor = true;
			this->coordinateGetButton->Click += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::coordinateGetButton_Click);
			// 
			// coordinateSetButton
			// 
			this->coordinateSetButton->Enabled = false;
			this->coordinateSetButton->Location = System::Drawing::Point(291, 241);
			this->coordinateSetButton->Name = L"coordinateSetButton";
			this->coordinateSetButton->Size = System::Drawing::Size(103, 23);
			this->coordinateSetButton->TabIndex = 6;
			this->coordinateSetButton->Text = L"Set Coordinates";
			this->coordinateSetButton->UseVisualStyleBackColor = true;
			this->coordinateSetButton->Click += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::coordinateSetButton_Click);
			// 
			// coordinateYLabel
			// 
			this->coordinateYLabel->AutoSize = true;
			this->coordinateYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->coordinateYLabel->Location = System::Drawing::Point(164, 186);
			this->coordinateYLabel->Name = L"coordinateYLabel";
			this->coordinateYLabel->Size = System::Drawing::Size(84, 15);
			this->coordinateYLabel->TabIndex = 5;
			this->coordinateYLabel->Text = L"No data found";
			// 
			// coordinateXLabel
			// 
			this->coordinateXLabel->AutoSize = true;
			this->coordinateXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->coordinateXLabel->Location = System::Drawing::Point(164, 145);
			this->coordinateXLabel->Name = L"coordinateXLabel";
			this->coordinateXLabel->Size = System::Drawing::Size(84, 15);
			this->coordinateXLabel->TabIndex = 4;
			this->coordinateXLabel->Text = L"No data found";
			// 
			// coordinateOLabel
			// 
			this->coordinateOLabel->AutoSize = true;
			this->coordinateOLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->coordinateOLabel->Location = System::Drawing::Point(164, 99);
			this->coordinateOLabel->Name = L"coordinateOLabel";
			this->coordinateOLabel->Size = System::Drawing::Size(84, 15);
			this->coordinateOLabel->TabIndex = 3;
			this->coordinateOLabel->Text = L"No data found";
			// 
			// coordinateXTextBox
			// 
			this->coordinateXTextBox->Location = System::Drawing::Point(69, 144);
			this->coordinateXTextBox->Name = L"coordinateXTextBox";
			this->coordinateXTextBox->Size = System::Drawing::Size(82, 20);
			this->coordinateXTextBox->TabIndex = 2;
			// 
			// coordinateYTextBox
			// 
			this->coordinateYTextBox->Location = System::Drawing::Point(69, 185);
			this->coordinateYTextBox->Name = L"coordinateYTextBox";
			this->coordinateYTextBox->Size = System::Drawing::Size(82, 20);
			this->coordinateYTextBox->TabIndex = 1;
			// 
			// coordinateOTextBox
			// 
			this->coordinateOTextBox->Location = System::Drawing::Point(69, 99);
			this->coordinateOTextBox->Name = L"coordinateOTextBox";
			this->coordinateOTextBox->Size = System::Drawing::Size(82, 20);
			this->coordinateOTextBox->TabIndex = 0;
			// 
			// rigidPage
			// 
			this->rigidPage->BackColor = System::Drawing::SystemColors::ControlLight;
			this->rigidPage->Controls->Add(this->rigidInfoLabel);
			this->rigidPage->Controls->Add(this->rigidYButton);
			this->rigidPage->Controls->Add(this->rigidXButton);
			this->rigidPage->Controls->Add(this->rigidOButton);
			this->rigidPage->Controls->Add(this->rigidYLabel);
			this->rigidPage->Controls->Add(this->rigidXLabel);
			this->rigidPage->Controls->Add(this->rigidOLabel);
			this->rigidPage->Controls->Add(this->coordinateSetButton2);
			this->rigidPage->Controls->Add(this->rigidGetDataButton);
			this->rigidPage->Controls->Add(this->rigidToolPositionLabel);
			this->rigidPage->Controls->Add(this->rigidBodyLabel);
			this->rigidPage->Location = System::Drawing::Point(4, 22);
			this->rigidPage->Name = L"rigidPage";
			this->rigidPage->Padding = System::Windows::Forms::Padding(3);
			this->rigidPage->Size = System::Drawing::Size(416, 285);
			this->rigidPage->TabIndex = 1;
			this->rigidPage->Text = L"Rigid Body";
			// 
			// rigidInfoLabel
			// 
			this->rigidInfoLabel->AutoSize = true;
			this->rigidInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidInfoLabel->Location = System::Drawing::Point(21, 15);
			this->rigidInfoLabel->Name = L"rigidInfoLabel";
			this->rigidInfoLabel->Size = System::Drawing::Size(380, 30);
			this->rigidInfoLabel->TabIndex = 14;
			this->rigidInfoLabel->Text = L"Click \"Get Data\" to retrieve the current Rigid Body Tool position, \r\nthen choose " 
				L"one of the buttons to set that position as part of the axes.";
			// 
			// rigidYButton
			// 
			this->rigidYButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->rigidYButton->Enabled = false;
			this->rigidYButton->Location = System::Drawing::Point(85, 194);
			this->rigidYButton->Name = L"rigidYButton";
			this->rigidYButton->Size = System::Drawing::Size(75, 23);
			this->rigidYButton->TabIndex = 13;
			this->rigidYButton->Text = L"Y-Axis";
			this->rigidYButton->UseVisualStyleBackColor = true;
			this->rigidYButton->Click += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::rigidSetDataButton_Click);
			// 
			// rigidXButton
			// 
			this->rigidXButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->rigidXButton->Enabled = false;
			this->rigidXButton->Location = System::Drawing::Point(85, 163);
			this->rigidXButton->Name = L"rigidXButton";
			this->rigidXButton->Size = System::Drawing::Size(75, 23);
			this->rigidXButton->TabIndex = 12;
			this->rigidXButton->Text = L"X-Axis";
			this->rigidXButton->UseVisualStyleBackColor = true;
			this->rigidXButton->Click += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::rigidSetDataButton_Click);
			// 
			// rigidOButton
			// 
			this->rigidOButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->rigidOButton->Enabled = false;
			this->rigidOButton->Location = System::Drawing::Point(85, 132);
			this->rigidOButton->Name = L"rigidOButton";
			this->rigidOButton->Size = System::Drawing::Size(75, 23);
			this->rigidOButton->TabIndex = 11;
			this->rigidOButton->Text = L"Origin";
			this->rigidOButton->UseVisualStyleBackColor = true;
			this->rigidOButton->Click += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::rigidSetDataButton_Click);
			// 
			// rigidYLabel
			// 
			this->rigidYLabel->AutoSize = true;
			this->rigidYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidYLabel->Location = System::Drawing::Point(166, 197);
			this->rigidYLabel->Name = L"rigidYLabel";
			this->rigidYLabel->Size = System::Drawing::Size(84, 15);
			this->rigidYLabel->TabIndex = 10;
			this->rigidYLabel->Text = L"No data found";
			// 
			// rigidXLabel
			// 
			this->rigidXLabel->AutoSize = true;
			this->rigidXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidXLabel->Location = System::Drawing::Point(166, 166);
			this->rigidXLabel->Name = L"rigidXLabel";
			this->rigidXLabel->Size = System::Drawing::Size(84, 15);
			this->rigidXLabel->TabIndex = 9;
			this->rigidXLabel->Text = L"No data found";
			// 
			// rigidOLabel
			// 
			this->rigidOLabel->AutoSize = true;
			this->rigidOLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidOLabel->Location = System::Drawing::Point(166, 135);
			this->rigidOLabel->Name = L"rigidOLabel";
			this->rigidOLabel->Size = System::Drawing::Size(84, 15);
			this->rigidOLabel->TabIndex = 8;
			this->rigidOLabel->Text = L"No data found";
			// 
			// coordinateSetButton2
			// 
			this->coordinateSetButton2->Enabled = false;
			this->coordinateSetButton2->Location = System::Drawing::Point(291, 241);
			this->coordinateSetButton2->Name = L"coordinateSetButton2";
			this->coordinateSetButton2->Size = System::Drawing::Size(103, 23);
			this->coordinateSetButton2->TabIndex = 7;
			this->coordinateSetButton2->Text = L"Set Coordinates";
			this->coordinateSetButton2->UseVisualStyleBackColor = true;
			this->coordinateSetButton2->Click += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::coordinateSetButton_Click);
			// 
			// rigidGetDataButton
			// 
			this->rigidGetDataButton->Location = System::Drawing::Point(36, 101);
			this->rigidGetDataButton->Name = L"rigidGetDataButton";
			this->rigidGetDataButton->Size = System::Drawing::Size(75, 23);
			this->rigidGetDataButton->TabIndex = 2;
			this->rigidGetDataButton->Text = L"Get Data";
			this->rigidGetDataButton->UseVisualStyleBackColor = true;
			this->rigidGetDataButton->Click += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::rigidGetDataButton_Click);
			// 
			// rigidToolPositionLabel
			// 
			this->rigidToolPositionLabel->AutoSize = true;
			this->rigidToolPositionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rigidToolPositionLabel->Location = System::Drawing::Point(117, 104);
			this->rigidToolPositionLabel->Name = L"rigidToolPositionLabel";
			this->rigidToolPositionLabel->Size = System::Drawing::Size(92, 16);
			this->rigidToolPositionLabel->TabIndex = 1;
			this->rigidToolPositionLabel->Text = L"No data found";
			// 
			// rigidBodyLabel
			// 
			this->rigidBodyLabel->AutoSize = true;
			this->rigidBodyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidBodyLabel->Location = System::Drawing::Point(21, 79);
			this->rigidBodyLabel->Name = L"rigidBodyLabel";
			this->rigidBodyLabel->Size = System::Drawing::Size(160, 16);
			this->rigidBodyLabel->TabIndex = 0;
			this->rigidBodyLabel->Text = L"Rigid Body Tool Position:";
			// 
			// DefineCoordinateFrameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 310);
			this->Controls->Add(this->CoordinateFramePages);
			this->Name = L"DefineCoordinateFrameForm";
			this->Text = L"Define Coordinate Frame";
			this->Closed += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::DefineCoordinateFrameForm_Closed);
			this->Load += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::DefineCoordinateFrameForm_Load);
			inputPage->ResumeLayout(false);
			inputPage->PerformLayout();
			this->CoordinateFramePages->ResumeLayout(false);
			this->infoPage->ResumeLayout(false);
			this->infoPage->PerformLayout();
			this->markerPage->ResumeLayout(false);
			this->markerPage->PerformLayout();
			this->rigidPage->ResumeLayout(false);
			this->rigidPage->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	// local variables
	private: osg::Vec3* posO;
	private: osg::Vec3* posX;
	private: osg::Vec3* posY;
	private: osg::Vec3* pos;


		 // checks if input string is a valid coordinate (x, y, z)
private: bool isCoordinate(String^ str) {
			 String^ regs = "^\\s*-?\\d+(.\\d+)?\\s*," + 
							"\\s*-?\\d+(.\\d+)?\\s*," +
							"\\s*-?\\d+(.\\d+)?\\s*$";
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

	private: System::Void DefineCoordinateFrameForm_Load(System::Object^  sender, System::EventArgs^  e) {
				this->defaultDataText = L"No data found";
				posO = new osg::Vec3();
				posX = new osg::Vec3();
				posY = new osg::Vec3();
				pos = new osg::Vec3();
			 }
 	private: System::Void DefineCoordinateFrameForm_Closed( Object^ /*sender*/, System::EventArgs ^ e )
			{
				if (posO) delete posO;
				if (posX) delete posX;
				if (posY) delete posY;
				if (pos) delete pos;
			 }

	private: System::Void coordinateGetButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 ClientHandler* client = AppData::getInstance()->getClient();
				 if (client->lock())
				 {
					 Marker* marker;
					 bool result;
					 int id;
					 this->coordinateSetButton->Enabled = true;

					 // origin
					 result = Int32::TryParse(coordinateOTextBox->Text, id);
					 marker = client->getLabeledMarker(id);
					 if (!result || !marker)
					 {
						 coordinate_setDefaultText(coordinateOLabel);
						 this->coordinateSetButton->Enabled = false;
					 }
					 else
					 {
						 osg::Vec3 pt = marker->getPosition();
						 posO->set(pt.x(), pt.y(), pt.z());

						 coordinate_setPoint(posO, coordinateOLabel);
					 }

					 // x
					 result = Int32::TryParse(coordinateXTextBox->Text, id);
					 marker = client->getLabeledMarker(id);
					 if (!result || !marker)
					 {
						 coordinate_setDefaultText(coordinateXLabel);
						 this->coordinateSetButton->Enabled = false;
					 }
					 else
					 {
						 osg::Vec3 pt = marker->getPosition();
						 posX->set(pt.x(), pt.y(), pt.z());

						 coordinate_setPoint(posX, coordinateXLabel);
					 }

					 // y
					 result = Int32::TryParse(coordinateYTextBox->Text, id);
					 marker = client->getLabeledMarker(id);
					 if (!result || !marker)
					 {
						 coordinate_setDefaultText(coordinateYLabel);
						 this->coordinateSetButton->Enabled = false;
					 }
					 else
					 {
						 osg::Vec3 pt = marker->getPosition();
						 posY->set(pt.x(), pt.y(), pt.z());

						 coordinate_setPoint(posY, coordinateYLabel);
					 }

					 client->unlock();
				 }
			 }
	private: System::Void coordinate_setDefaultText(Label^ text) {
				 text->Text = defaultDataText;
			 }
	private: System::Void coordinate_setPoint(osg::Vec3* pos, Label^ text) {
				String^ str = Convert::ToString(pos->x());
				str += ", ";
				str += Convert::ToString(pos->y());
				str += ", ";
				str += Convert::ToString(pos->z());
				text->Text = str;
			 }

	private: System::Void coordinateSetButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void coordinateResetButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void rigidSetButtons(bool enable) {
				 this->rigidOButton->Enabled = enable;
				 this->rigidXButton->Enabled = enable;
				 this->rigidYButton->Enabled = enable;
			 }
	private: System::Void rigidGetDataButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 ClientHandler* client = AppData::getInstance()->getClient();
				 if (client)
				 {
					 RigidBody* body = client->getRigidBody(client->getRigidBodyTool());
					 if (body)
					 {
						 pos->set(body->getPosition().x(), 
									body->getPosition().y(), 
									body->getPosition().z());
						 coordinate_setPoint(pos, rigidToolPositionLabel);
						 rigidSetButtons(true);
						 return;
					 }
				 }
				 coordinate_setDefaultText(rigidToolPositionLabel);
				 rigidSetButtons(false);
			 }

	private: System::Void rigidSetDataButton_Click(System::Object^ sender, System::EventArgs^ e) {
				 if (sender == this->rigidOButton)
				 {
					 posO->set(pos->x(), pos->y(), pos->z());
					 coordinate_setPoint(pos, rigidOLabel);
					 
					 if ( String::Compare(rigidXLabel->Text, defaultDataText) &&
						  String::Compare(rigidYLabel->Text, defaultDataText) )
						  coordinateSetButton2->Enabled = true;
					 else
						  coordinateSetButton2->Enabled = false;
				 }
				 else if (sender == this->rigidXButton)
				 {
					 posX->set(pos->x(), pos->y(), pos->z());
					 coordinate_setPoint(pos, rigidXLabel);

					 if ( String::Compare(rigidOLabel->Text, defaultDataText) &&
						  String::Compare(rigidYLabel->Text, defaultDataText) )
						  coordinateSetButton2->Enabled = true;
					 else
						  coordinateSetButton2->Enabled = false;
				 }
				 else if (sender == this->rigidYButton)
				 {
					 posY->set(pos->x(), pos->y(), pos->z());
					 coordinate_setPoint(pos, rigidYLabel);

					 if ( String::Compare(rigidOLabel->Text, defaultDataText) &&
						  String::Compare(rigidXLabel->Text, defaultDataText) )
						  coordinateSetButton2->Enabled = true;
					 else
						  coordinateSetButton2->Enabled = false;
				 }
			 }
private: System::Void inputTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 if (isCoordinate(this->inputOTextBox->Text) &&
				 isCoordinate(this->inputXTextBox->Text) &&
				 isCoordinate(this->inputYTextBox->Text) )
				 this->inputSetButton->Enabled = true;
			 else
				 this->inputSetButton->Enabled = false;
		 }
		 // populate vectors based on coordinate input
private: bool extractCoordinates()
		 {
			 if (!extractCoordinates(this->inputOTextBox, posO))
				 return false;

			 if (!extractCoordinates(this->inputXTextBox, posX))
				 return false;

			 if (!extractCoordinates(this->inputYTextBox, posY))
				 return false;

			 return true;
		 }
};
}
