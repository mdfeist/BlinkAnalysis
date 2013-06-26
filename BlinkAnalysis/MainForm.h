/**
 * MainForm.h
 * Created By: Michael Feist
 *
 * MainForm handles the Windows GUI for the main window.
 * Most of the code is auto generated but the user defined
 * code is located at the bottom.
 */
#pragma once
#include "stdafx.h"

#include "Debug.h"

#include <string>
#include <vector>
#include <exception>
#include <msclr\marshal_cppstd.h>

#include "Dikablis.h"
#include "DikablisHelp.h"
#include "AddObjectWizardFormController.h"
#include "AddWorldForm.h" // TODO need to add controller?
#include "DefineCoordinateFrameFormController.h"
#include "EyeCalibrationWizardFormController.h"
#include "SetObjectRigidBodyFormController.h"
#include "SetRigidBodyObjectForm.h"
#include "AppData.h"
#include "AppViewer.h"
#include "WorldManager.h"
#include "RecordingManager.h"

#include "NatNetClientSetup.h"

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Reflection;
	using namespace msclr::interop;

	// enums used to help define ordering of values
	// in the grid view of world or object properties
	// Make sure to follow this order when adding rows to GridView
	enum class worldProperty 
	{ 
		ID,
		NAME,
		OBJECTS,
		MATRIX, 
		RENDER
	};
	enum class objectProperty 
	{ 
		ID,
		NAME,
		TYPE,
		RIGID, 
		FACES,
		VERTICES, 
		RENDER, 
		POSITION,
		POSITION_X,
		POSITION_Y,
		POSITION_Z,
		ORIENT,
		ORIENT_YAW,
		ORIENT_PITCH,
		ORIENT_ROLL
	};

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  mainTabControl;
	protected: 

	protected: 
	private: System::Windows::Forms::TabPage^  DikablisPage;
	private: System::Windows::Forms::TabPage^  OptiTrackPage;
	private: System::Windows::Forms::SplitContainer^  dikablisMainSplitContainer;





	private: System::Windows::Forms::Label^  dikablisPropertiesLabel;


	private: System::Windows::Forms::Label^  dikablisIPLabel;

	private: System::Windows::Forms::Label^  dikablisRecorderSetting;
	private: System::Windows::Forms::TextBox^  dikablisIPTextBox;
	private: System::Windows::Forms::TextBox^  dikablisPortTextBox;

	private: System::Windows::Forms::Label^  dikablisPortLabel;
	private: System::Windows::Forms::Button^  dikablisConnectBtn;
	private: System::Windows::Forms::Label^  dikablisIndexTitle;
	private: System::Windows::Forms::Label^  dikablisOutputTitle;
	private: System::Windows::Forms::SplitContainer^  dikablisSplitContainer;



	private: System::Windows::Forms::TextBox^  dikablisOutputLogTextBox;
	private: System::Windows::Forms::Label^  dikablisOutputLogLabel;
	private: System::Windows::Forms::Button^  dikablisDisConnectBtn;
	private: System::Windows::Forms::MenuStrip^  menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  projectToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::Label^  dikablisEyeroizoomyLabel;
	private: System::Windows::Forms::Label^  dikablisEyeroizoomxLabel;
	private: System::Windows::Forms::Label^  dikablisEyeroivertLabel;
	private: System::Windows::Forms::Label^  dikablisEyeroihorizLabel;
	private: System::Windows::Forms::Label^  dikablisTimeStampLabel;
	private: System::Windows::Forms::Label^  dikablisFieldYLabel;
	private: System::Windows::Forms::Label^  dikablisFieldXLabel;
	private: System::Windows::Forms::Label^  dikablisEyeYLabel;
	private: System::Windows::Forms::Label^  dikablisEyeXLabel;
	private: System::Windows::Forms::Label^  dikablisEyeValidLabel;
	private: System::Windows::Forms::Label^  dikablisOnlinecalibLabel;
	private: System::Windows::Forms::Button^  dikablisHelpBtn;
	private: System::Windows::Forms::Label^  dikablisTimeStampOutputLabel;
	private: System::Windows::Forms::Label^  dikablisIndexOutputLabel;
	private: System::Windows::Forms::Label^  dikablisEyeRoiHorizOutputLabel;
	private: System::Windows::Forms::Label^  dikablisFieldYOutputLabel;

	private: System::Windows::Forms::Label^  dikablisFieldXOutputLabel;

	private: System::Windows::Forms::Label^  dikablisEyeYOutputLabel;

	private: System::Windows::Forms::Label^  dikablisEyeXOutputLabel;

	private: System::Windows::Forms::Label^  dikablisEyeRoiZoomYOutputLabel;
	private: System::Windows::Forms::Label^  dikablisEyeRoiZoomXOutputLabel;
	private: System::Windows::Forms::Label^  dikablisEyeRoiVertOutputLabel;
	private: System::Windows::Forms::SplitContainer^  optiTrackMainSplitContainer;
	private: System::Windows::Forms::SplitContainer^  optiTrackSplitContainer;
	private: System::Windows::Forms::TextBox^  optiTrackOutputLogTextBox;




	private: System::Windows::Forms::Label^  optiTrackOutputLogLabel;
	private: System::Windows::Forms::Button^  optiTrackHelpBtn;
	private: System::Windows::Forms::Button^  optiTrackDisConnect;



	private: System::Windows::Forms::Button^  optiTrackConnectBtn;

	private: System::Windows::Forms::TextBox^  optiTrackCmdPortTextBox;

	private: System::Windows::Forms::Label^  optiTrackCmdPortLabel;
	private: System::Windows::Forms::TextBox^  optiTrackSeverIpAddressTextBox;


	private: System::Windows::Forms::Label^  optiTrackSeverIpAddressLabel;

	private: System::Windows::Forms::Label^  optiTrackServerTitleLabel;
	private: System::Windows::Forms::Label^  optiTrackPropertiesLabel;
	private: System::Windows::Forms::TextBox^  optiTrackDataPortTextBox;

	private: System::Windows::Forms::Label^  optiTrackDataPortLabel;
	private: System::Windows::Forms::ComboBox^  optiTrackConnectionTypeComboBox;

	private: System::Windows::Forms::Label^  optiTrackConnectionTypeLabel;










private: System::Windows::Forms::TextBox^  optiTrackLocalIpAddressTextBox;
private: System::Windows::Forms::Label^  optiTrackLocalIpAddressLabel;
private: System::Windows::Forms::Label^  optiTrackLocalTitle;
private: System::Windows::Forms::TabPage^  visualTabPage;


private: System::Windows::Forms::SplitContainer^  visualMainSplitContainer;
private: System::Windows::Forms::SplitContainer^  visualSplitContainer;
private: System::Windows::Forms::Label^  visualRecorderLabel;









private: System::Windows::Forms::DataGridView^  optiTrackDataGridView;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  optiTrackRigidBodyIDColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  optiTrackRigidBodyNameColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  optiTrackRigidBodyPositionXColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  optiTrackRigidBodyPositionYColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  optiTrackRigidBodyPositionZColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  optiTrackRigidBodyRotationXColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  optiTrackRigidBodyRotationYColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  optiTrackRigidBodyRotationZColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  optiTrackRigidBodyRotationWColumn;
private: System::Windows::Forms::ListView^  visualRigidBodyListView;
private: System::Windows::Forms::Button^  dikablisCalibrationBtn;
private: System::Windows::Forms::ToolStripMenuItem^  calibrationToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  eyeCalibrationToolStripMenuItem;



private: System::Windows::Forms::ToolStripMenuItem^  objectToolStripMenuItem;



private: System::Windows::Forms::ToolStripMenuItem^  addObjectToolStripMenuItem;




private: System::Windows::Forms::ContextMenuStrip^  rigidBodyToolContextMenu;

private: System::Windows::Forms::ToolStripMenuItem^  setAsRigidBodyToolToolStripMenuItem;
private: System::Windows::Forms::TabControl^  visualPropertiesTabControl;

private: System::Windows::Forms::TabPage^  rigidBodyTabPage;
private: System::Windows::Forms::TabPage^  worldTabPage;
private: System::Windows::Forms::TabPage^  objectTabPage;
private: System::Windows::Forms::ComboBox^  worldComboBox;
private: System::Windows::Forms::Button^  worldAddButton;

private: System::Windows::Forms::DataGridView^  worldGridView;


private: System::Windows::Forms::Label^  worldListLabel;
private: System::Windows::Forms::Label^  objectLabel;

private: System::Windows::Forms::Label^  objectWLabel;
private: System::Windows::Forms::ComboBox^  objectWComboBox;
private: System::Windows::Forms::Button^  objectAddButton;
private: System::Windows::Forms::ComboBox^  objectComboBox;
private: System::Windows::Forms::DataGridView^  objectGridView;




private: System::Windows::Forms::Button^  worldRemoveButton;
private: System::Windows::Forms::Button^  removeObjectButton;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  worldPropertyColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  worldValueColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  objectPropertyColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  objectValueColumn;
private: System::Windows::Forms::ToolStrip^  visualToolStrip;
private: System::Windows::Forms::ToolStripLabel^  visualViewerScaleLabel;
private: System::Windows::Forms::ToolStripTextBox^  visualViewerScaleTextBox;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
private: System::Windows::Forms::Panel^  visualRecorderPanel;
private: System::Windows::Forms::Button^  stopRecordingBtn;
private: System::Windows::Forms::Button^  startRecordingBtn;
private: System::Windows::Forms::ToolStripMenuItem^  attachToExistingObjectToolStripMenuItem;





















	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->mainTabControl = (gcnew System::Windows::Forms::TabControl());
			this->OptiTrackPage = (gcnew System::Windows::Forms::TabPage());
			this->optiTrackMainSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->optiTrackSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->optiTrackDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->optiTrackRigidBodyIDColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->optiTrackRigidBodyNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->optiTrackRigidBodyPositionXColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->optiTrackRigidBodyPositionYColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->optiTrackRigidBodyPositionZColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->optiTrackRigidBodyRotationXColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->optiTrackRigidBodyRotationYColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->optiTrackRigidBodyRotationZColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->optiTrackRigidBodyRotationWColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->optiTrackOutputLogTextBox = (gcnew System::Windows::Forms::TextBox());
			this->optiTrackOutputLogLabel = (gcnew System::Windows::Forms::Label());
			this->optiTrackLocalIpAddressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->optiTrackLocalIpAddressLabel = (gcnew System::Windows::Forms::Label());
			this->optiTrackLocalTitle = (gcnew System::Windows::Forms::Label());
			this->optiTrackConnectionTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->optiTrackConnectionTypeLabel = (gcnew System::Windows::Forms::Label());
			this->optiTrackDataPortTextBox = (gcnew System::Windows::Forms::TextBox());
			this->optiTrackDataPortLabel = (gcnew System::Windows::Forms::Label());
			this->optiTrackHelpBtn = (gcnew System::Windows::Forms::Button());
			this->optiTrackDisConnect = (gcnew System::Windows::Forms::Button());
			this->optiTrackConnectBtn = (gcnew System::Windows::Forms::Button());
			this->optiTrackCmdPortTextBox = (gcnew System::Windows::Forms::TextBox());
			this->optiTrackCmdPortLabel = (gcnew System::Windows::Forms::Label());
			this->optiTrackSeverIpAddressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->optiTrackSeverIpAddressLabel = (gcnew System::Windows::Forms::Label());
			this->optiTrackServerTitleLabel = (gcnew System::Windows::Forms::Label());
			this->optiTrackPropertiesLabel = (gcnew System::Windows::Forms::Label());
			this->DikablisPage = (gcnew System::Windows::Forms::TabPage());
			this->dikablisMainSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->dikablisSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->dikablisOutputLogTextBox = (gcnew System::Windows::Forms::TextBox());
			this->dikablisOutputLogLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisCalibrationBtn = (gcnew System::Windows::Forms::Button());
			this->dikablisFieldYOutputLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisFieldXOutputLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeYOutputLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeXOutputLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeRoiZoomYOutputLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeRoiZoomXOutputLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeRoiVertOutputLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeRoiHorizOutputLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisTimeStampOutputLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisIndexOutputLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisHelpBtn = (gcnew System::Windows::Forms::Button());
			this->dikablisFieldYLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisFieldXLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeYLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeXLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeValidLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisOnlinecalibLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeroizoomyLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeroizoomxLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeroivertLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisEyeroihorizLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisTimeStampLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisDisConnectBtn = (gcnew System::Windows::Forms::Button());
			this->dikablisIndexTitle = (gcnew System::Windows::Forms::Label());
			this->dikablisOutputTitle = (gcnew System::Windows::Forms::Label());
			this->dikablisConnectBtn = (gcnew System::Windows::Forms::Button());
			this->dikablisPortTextBox = (gcnew System::Windows::Forms::TextBox());
			this->dikablisPortLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisIPTextBox = (gcnew System::Windows::Forms::TextBox());
			this->dikablisIPLabel = (gcnew System::Windows::Forms::Label());
			this->dikablisRecorderSetting = (gcnew System::Windows::Forms::Label());
			this->dikablisPropertiesLabel = (gcnew System::Windows::Forms::Label());
			this->visualTabPage = (gcnew System::Windows::Forms::TabPage());
			this->visualMainSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->visualSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->visualToolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->visualViewerScaleLabel = (gcnew System::Windows::Forms::ToolStripLabel());
			this->visualViewerScaleTextBox = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->visualRecorderPanel = (gcnew System::Windows::Forms::Panel());
			this->stopRecordingBtn = (gcnew System::Windows::Forms::Button());
			this->startRecordingBtn = (gcnew System::Windows::Forms::Button());
			this->visualRecorderLabel = (gcnew System::Windows::Forms::Label());
			this->visualPropertiesTabControl = (gcnew System::Windows::Forms::TabControl());
			this->rigidBodyTabPage = (gcnew System::Windows::Forms::TabPage());
			this->visualRigidBodyListView = (gcnew System::Windows::Forms::ListView());
			this->worldTabPage = (gcnew System::Windows::Forms::TabPage());
			this->worldRemoveButton = (gcnew System::Windows::Forms::Button());
			this->worldListLabel = (gcnew System::Windows::Forms::Label());
			this->worldGridView = (gcnew System::Windows::Forms::DataGridView());
			this->worldPropertyColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->worldValueColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->worldAddButton = (gcnew System::Windows::Forms::Button());
			this->worldComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->objectTabPage = (gcnew System::Windows::Forms::TabPage());
			this->removeObjectButton = (gcnew System::Windows::Forms::Button());
			this->objectLabel = (gcnew System::Windows::Forms::Label());
			this->objectWLabel = (gcnew System::Windows::Forms::Label());
			this->objectWComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->objectAddButton = (gcnew System::Windows::Forms::Button());
			this->objectComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->objectGridView = (gcnew System::Windows::Forms::DataGridView());
			this->objectPropertyColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->objectValueColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->projectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->calibrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eyeCalibrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->objectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addObjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rigidBodyToolContextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->setAsRigidBodyToolToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->attachToExistingObjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mainTabControl->SuspendLayout();
			this->OptiTrackPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->optiTrackMainSplitContainer))->BeginInit();
			this->optiTrackMainSplitContainer->Panel1->SuspendLayout();
			this->optiTrackMainSplitContainer->Panel2->SuspendLayout();
			this->optiTrackMainSplitContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->optiTrackSplitContainer))->BeginInit();
			this->optiTrackSplitContainer->Panel1->SuspendLayout();
			this->optiTrackSplitContainer->Panel2->SuspendLayout();
			this->optiTrackSplitContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->optiTrackDataGridView))->BeginInit();
			this->DikablisPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dikablisMainSplitContainer))->BeginInit();
			this->dikablisMainSplitContainer->Panel1->SuspendLayout();
			this->dikablisMainSplitContainer->Panel2->SuspendLayout();
			this->dikablisMainSplitContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dikablisSplitContainer))->BeginInit();
			this->dikablisSplitContainer->Panel2->SuspendLayout();
			this->dikablisSplitContainer->SuspendLayout();
			this->visualTabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->visualMainSplitContainer))->BeginInit();
			this->visualMainSplitContainer->Panel1->SuspendLayout();
			this->visualMainSplitContainer->Panel2->SuspendLayout();
			this->visualMainSplitContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->visualSplitContainer))->BeginInit();
			this->visualSplitContainer->Panel1->SuspendLayout();
			this->visualSplitContainer->Panel2->SuspendLayout();
			this->visualSplitContainer->SuspendLayout();
			this->visualToolStrip->SuspendLayout();
			this->visualRecorderPanel->SuspendLayout();
			this->visualPropertiesTabControl->SuspendLayout();
			this->rigidBodyTabPage->SuspendLayout();
			this->worldTabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->worldGridView))->BeginInit();
			this->objectTabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->objectGridView))->BeginInit();
			this->menuStrip->SuspendLayout();
			this->rigidBodyToolContextMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainTabControl
			// 
			this->mainTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->mainTabControl->Controls->Add(this->OptiTrackPage);
			this->mainTabControl->Controls->Add(this->DikablisPage);
			this->mainTabControl->Controls->Add(this->visualTabPage);
			this->mainTabControl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->mainTabControl->Location = System::Drawing::Point(0, 28);
			this->mainTabControl->Name = L"mainTabControl";
			this->mainTabControl->SelectedIndex = 0;
			this->mainTabControl->Size = System::Drawing::Size(784, 535);
			this->mainTabControl->TabIndex = 0;
			// 
			// OptiTrackPage
			// 
			this->OptiTrackPage->BackColor = System::Drawing::Color::Gainsboro;
			this->OptiTrackPage->Controls->Add(this->optiTrackMainSplitContainer);
			this->OptiTrackPage->Location = System::Drawing::Point(4, 22);
			this->OptiTrackPage->Name = L"OptiTrackPage";
			this->OptiTrackPage->Padding = System::Windows::Forms::Padding(3);
			this->OptiTrackPage->Size = System::Drawing::Size(776, 509);
			this->OptiTrackPage->TabIndex = 1;
			this->OptiTrackPage->Text = L"OptiTrack";
			// 
			// optiTrackMainSplitContainer
			// 
			this->optiTrackMainSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->optiTrackMainSplitContainer->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->optiTrackMainSplitContainer->Location = System::Drawing::Point(3, 3);
			this->optiTrackMainSplitContainer->Name = L"optiTrackMainSplitContainer";
			// 
			// optiTrackMainSplitContainer.Panel1
			// 
			this->optiTrackMainSplitContainer->Panel1->BackColor = System::Drawing::Color::Gainsboro;
			this->optiTrackMainSplitContainer->Panel1->Controls->Add(this->optiTrackSplitContainer);
			// 
			// optiTrackMainSplitContainer.Panel2
			// 
			this->optiTrackMainSplitContainer->Panel2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackLocalIpAddressTextBox);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackLocalIpAddressLabel);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackLocalTitle);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackConnectionTypeComboBox);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackConnectionTypeLabel);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackDataPortTextBox);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackDataPortLabel);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackHelpBtn);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackDisConnect);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackConnectBtn);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackCmdPortTextBox);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackCmdPortLabel);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackSeverIpAddressTextBox);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackSeverIpAddressLabel);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackServerTitleLabel);
			this->optiTrackMainSplitContainer->Panel2->Controls->Add(this->optiTrackPropertiesLabel);
			this->optiTrackMainSplitContainer->Panel2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->optiTrackMainSplitContainer->Panel2MinSize = 273;
			this->optiTrackMainSplitContainer->Size = System::Drawing::Size(770, 503);
			this->optiTrackMainSplitContainer->SplitterDistance = 493;
			this->optiTrackMainSplitContainer->TabIndex = 1;
			// 
			// optiTrackSplitContainer
			// 
			this->optiTrackSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->optiTrackSplitContainer->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->optiTrackSplitContainer->Location = System::Drawing::Point(0, 0);
			this->optiTrackSplitContainer->Name = L"optiTrackSplitContainer";
			this->optiTrackSplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// optiTrackSplitContainer.Panel1
			// 
			this->optiTrackSplitContainer->Panel1->BackColor = System::Drawing::Color::White;
			this->optiTrackSplitContainer->Panel1->Controls->Add(this->optiTrackDataGridView);
			// 
			// optiTrackSplitContainer.Panel2
			// 
			this->optiTrackSplitContainer->Panel2->BackColor = System::Drawing::Color::LightSlateGray;
			this->optiTrackSplitContainer->Panel2->Controls->Add(this->optiTrackOutputLogTextBox);
			this->optiTrackSplitContainer->Panel2->Controls->Add(this->optiTrackOutputLogLabel);
			this->optiTrackSplitContainer->Size = System::Drawing::Size(493, 503);
			this->optiTrackSplitContainer->SplitterDistance = 376;
			this->optiTrackSplitContainer->TabIndex = 0;
			// 
			// optiTrackDataGridView
			// 
			this->optiTrackDataGridView->AllowUserToAddRows = false;
			this->optiTrackDataGridView->AllowUserToDeleteRows = false;
			this->optiTrackDataGridView->AllowUserToResizeColumns = false;
			this->optiTrackDataGridView->AllowUserToResizeRows = false;
			this->optiTrackDataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->optiTrackDataGridView->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->optiTrackDataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->optiTrackDataGridView->CausesValidation = false;
			this->optiTrackDataGridView->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::Disable;
			this->optiTrackDataGridView->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->optiTrackDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->optiTrackDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {this->optiTrackRigidBodyIDColumn, 
				this->optiTrackRigidBodyNameColumn, this->optiTrackRigidBodyPositionXColumn, this->optiTrackRigidBodyPositionYColumn, this->optiTrackRigidBodyPositionZColumn, 
				this->optiTrackRigidBodyRotationXColumn, this->optiTrackRigidBodyRotationYColumn, this->optiTrackRigidBodyRotationZColumn, this->optiTrackRigidBodyRotationWColumn});
			this->optiTrackDataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->optiTrackDataGridView->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->optiTrackDataGridView->EnableHeadersVisualStyles = false;
			this->optiTrackDataGridView->Location = System::Drawing::Point(0, 0);
			this->optiTrackDataGridView->Name = L"optiTrackDataGridView";
			this->optiTrackDataGridView->ReadOnly = true;
			this->optiTrackDataGridView->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->optiTrackDataGridView->RowHeadersWidth = 25;
			this->optiTrackDataGridView->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->optiTrackDataGridView->ShowCellErrors = false;
			this->optiTrackDataGridView->ShowCellToolTips = false;
			this->optiTrackDataGridView->ShowEditingIcon = false;
			this->optiTrackDataGridView->ShowRowErrors = false;
			this->optiTrackDataGridView->Size = System::Drawing::Size(493, 376);
			this->optiTrackDataGridView->TabIndex = 1;
			// 
			// optiTrackRigidBodyIDColumn
			// 
			this->optiTrackRigidBodyIDColumn->HeaderText = L"ID";
			this->optiTrackRigidBodyIDColumn->Name = L"optiTrackRigidBodyIDColumn";
			this->optiTrackRigidBodyIDColumn->ReadOnly = true;
			// 
			// optiTrackRigidBodyNameColumn
			// 
			this->optiTrackRigidBodyNameColumn->HeaderText = L"Name";
			this->optiTrackRigidBodyNameColumn->Name = L"optiTrackRigidBodyNameColumn";
			this->optiTrackRigidBodyNameColumn->ReadOnly = true;
			// 
			// optiTrackRigidBodyPositionXColumn
			// 
			this->optiTrackRigidBodyPositionXColumn->HeaderText = L"Position X";
			this->optiTrackRigidBodyPositionXColumn->Name = L"optiTrackRigidBodyPositionXColumn";
			this->optiTrackRigidBodyPositionXColumn->ReadOnly = true;
			// 
			// optiTrackRigidBodyPositionYColumn
			// 
			this->optiTrackRigidBodyPositionYColumn->HeaderText = L"Position Y";
			this->optiTrackRigidBodyPositionYColumn->Name = L"optiTrackRigidBodyPositionYColumn";
			this->optiTrackRigidBodyPositionYColumn->ReadOnly = true;
			// 
			// optiTrackRigidBodyPositionZColumn
			// 
			this->optiTrackRigidBodyPositionZColumn->HeaderText = L"Position Z";
			this->optiTrackRigidBodyPositionZColumn->Name = L"optiTrackRigidBodyPositionZColumn";
			this->optiTrackRigidBodyPositionZColumn->ReadOnly = true;
			// 
			// optiTrackRigidBodyRotationXColumn
			// 
			this->optiTrackRigidBodyRotationXColumn->HeaderText = L"Rotation X";
			this->optiTrackRigidBodyRotationXColumn->Name = L"optiTrackRigidBodyRotationXColumn";
			this->optiTrackRigidBodyRotationXColumn->ReadOnly = true;
			// 
			// optiTrackRigidBodyRotationYColumn
			// 
			this->optiTrackRigidBodyRotationYColumn->HeaderText = L"Rotation Y";
			this->optiTrackRigidBodyRotationYColumn->Name = L"optiTrackRigidBodyRotationYColumn";
			this->optiTrackRigidBodyRotationYColumn->ReadOnly = true;
			// 
			// optiTrackRigidBodyRotationZColumn
			// 
			this->optiTrackRigidBodyRotationZColumn->HeaderText = L"Rotation Z";
			this->optiTrackRigidBodyRotationZColumn->Name = L"optiTrackRigidBodyRotationZColumn";
			this->optiTrackRigidBodyRotationZColumn->ReadOnly = true;
			// 
			// optiTrackRigidBodyRotationWColumn
			// 
			this->optiTrackRigidBodyRotationWColumn->HeaderText = L"Rotation W";
			this->optiTrackRigidBodyRotationWColumn->Name = L"optiTrackRigidBodyRotationWColumn";
			this->optiTrackRigidBodyRotationWColumn->ReadOnly = true;
			// 
			// optiTrackOutputLogTextBox
			// 
			this->optiTrackOutputLogTextBox->AcceptsReturn = true;
			this->optiTrackOutputLogTextBox->AcceptsTab = true;
			this->optiTrackOutputLogTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->optiTrackOutputLogTextBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->optiTrackOutputLogTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->optiTrackOutputLogTextBox->Location = System::Drawing::Point(3, 16);
			this->optiTrackOutputLogTextBox->Multiline = true;
			this->optiTrackOutputLogTextBox->Name = L"optiTrackOutputLogTextBox";
			this->optiTrackOutputLogTextBox->ReadOnly = true;
			this->optiTrackOutputLogTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->optiTrackOutputLogTextBox->Size = System::Drawing::Size(487, 101);
			this->optiTrackOutputLogTextBox->TabIndex = 1;
			// 
			// optiTrackOutputLogLabel
			// 
			this->optiTrackOutputLogLabel->AutoSize = true;
			this->optiTrackOutputLogLabel->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->optiTrackOutputLogLabel->Location = System::Drawing::Point(5, 0);
			this->optiTrackOutputLogLabel->Name = L"optiTrackOutputLogLabel";
			this->optiTrackOutputLogLabel->Size = System::Drawing::Size(67, 13);
			this->optiTrackOutputLogLabel->TabIndex = 0;
			this->optiTrackOutputLogLabel->Text = L"Output Log";
			// 
			// optiTrackLocalIpAddressTextBox
			// 
			this->optiTrackLocalIpAddressTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->optiTrackLocalIpAddressTextBox->Location = System::Drawing::Point(124, 57);
			this->optiTrackLocalIpAddressTextBox->Name = L"optiTrackLocalIpAddressTextBox";
			this->optiTrackLocalIpAddressTextBox->Size = System::Drawing::Size(144, 22);
			this->optiTrackLocalIpAddressTextBox->TabIndex = 28;
			this->optiTrackLocalIpAddressTextBox->Text = L"127.0.0.1";
			this->optiTrackLocalIpAddressTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::optiTrackLocalIpAddressTextBox_TextChanged);
			// 
			// optiTrackLocalIpAddressLabel
			// 
			this->optiTrackLocalIpAddressLabel->AutoSize = true;
			this->optiTrackLocalIpAddressLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->optiTrackLocalIpAddressLabel->Location = System::Drawing::Point(6, 60);
			this->optiTrackLocalIpAddressLabel->Name = L"optiTrackLocalIpAddressLabel";
			this->optiTrackLocalIpAddressLabel->Size = System::Drawing::Size(63, 13);
			this->optiTrackLocalIpAddressLabel->TabIndex = 27;
			this->optiTrackLocalIpAddressLabel->Text = L"IP Address:";
			// 
			// optiTrackLocalTitle
			// 
			this->optiTrackLocalTitle->AutoSize = true;
			this->optiTrackLocalTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->optiTrackLocalTitle->Location = System::Drawing::Point(6, 37);
			this->optiTrackLocalTitle->Name = L"optiTrackLocalTitle";
			this->optiTrackLocalTitle->Size = System::Drawing::Size(85, 13);
			this->optiTrackLocalTitle->TabIndex = 26;
			this->optiTrackLocalTitle->Text = L"Local Machine:";
			// 
			// optiTrackConnectionTypeComboBox
			// 
			this->optiTrackConnectionTypeComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->optiTrackConnectionTypeComboBox->FormattingEnabled = true;
			this->optiTrackConnectionTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Multicast", L"Unicast"});
			this->optiTrackConnectionTypeComboBox->Location = System::Drawing::Point(124, 203);
			this->optiTrackConnectionTypeComboBox->Name = L"optiTrackConnectionTypeComboBox";
			this->optiTrackConnectionTypeComboBox->Size = System::Drawing::Size(144, 21);
			this->optiTrackConnectionTypeComboBox->TabIndex = 25;
			this->optiTrackConnectionTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::optiTrackConnectionTypeComboBox_SelectedIndexChanged);
			// 
			// optiTrackConnectionTypeLabel
			// 
			this->optiTrackConnectionTypeLabel->AutoSize = true;
			this->optiTrackConnectionTypeLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->optiTrackConnectionTypeLabel->Location = System::Drawing::Point(6, 203);
			this->optiTrackConnectionTypeLabel->Name = L"optiTrackConnectionTypeLabel";
			this->optiTrackConnectionTypeLabel->Size = System::Drawing::Size(96, 13);
			this->optiTrackConnectionTypeLabel->TabIndex = 24;
			this->optiTrackConnectionTypeLabel->Text = L"Connection Type:";
			// 
			// optiTrackDataPortTextBox
			// 
			this->optiTrackDataPortTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->optiTrackDataPortTextBox->Location = System::Drawing::Point(124, 171);
			this->optiTrackDataPortTextBox->Name = L"optiTrackDataPortTextBox";
			this->optiTrackDataPortTextBox->Size = System::Drawing::Size(144, 22);
			this->optiTrackDataPortTextBox->TabIndex = 23;
			this->optiTrackDataPortTextBox->Text = L"1511";
			this->optiTrackDataPortTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::optiTrackDataPortTextBox_TextChanged);
			// 
			// optiTrackDataPortLabel
			// 
			this->optiTrackDataPortLabel->AutoSize = true;
			this->optiTrackDataPortLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->optiTrackDataPortLabel->Location = System::Drawing::Point(6, 174);
			this->optiTrackDataPortLabel->Name = L"optiTrackDataPortLabel";
			this->optiTrackDataPortLabel->Size = System::Drawing::Size(58, 13);
			this->optiTrackDataPortLabel->TabIndex = 22;
			this->optiTrackDataPortLabel->Text = L"Data Port:";
			// 
			// optiTrackHelpBtn
			// 
			this->optiTrackHelpBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->optiTrackHelpBtn->Location = System::Drawing::Point(193, 391);
			this->optiTrackHelpBtn->Name = L"optiTrackHelpBtn";
			this->optiTrackHelpBtn->Size = System::Drawing::Size(75, 23);
			this->optiTrackHelpBtn->TabIndex = 21;
			this->optiTrackHelpBtn->Text = L"Help";
			this->optiTrackHelpBtn->UseVisualStyleBackColor = true;
			// 
			// optiTrackDisConnect
			// 
			this->optiTrackDisConnect->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->optiTrackDisConnect->Location = System::Drawing::Point(195, 474);
			this->optiTrackDisConnect->Name = L"optiTrackDisConnect";
			this->optiTrackDisConnect->Size = System::Drawing::Size(75, 23);
			this->optiTrackDisConnect->TabIndex = 9;
			this->optiTrackDisConnect->Text = L"Disconnect";
			this->optiTrackDisConnect->UseVisualStyleBackColor = true;
			this->optiTrackDisConnect->Click += gcnew System::EventHandler(this, &MainForm::optiTrackDisConnect_Click);
			// 
			// optiTrackConnectBtn
			// 
			this->optiTrackConnectBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->optiTrackConnectBtn->Location = System::Drawing::Point(9, 477);
			this->optiTrackConnectBtn->Name = L"optiTrackConnectBtn";
			this->optiTrackConnectBtn->Size = System::Drawing::Size(75, 23);
			this->optiTrackConnectBtn->TabIndex = 6;
			this->optiTrackConnectBtn->Text = L"Connect";
			this->optiTrackConnectBtn->UseVisualStyleBackColor = true;
			this->optiTrackConnectBtn->Click += gcnew System::EventHandler(this, &MainForm::optiTrackConnectBtn_Click);
			// 
			// optiTrackCmdPortTextBox
			// 
			this->optiTrackCmdPortTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->optiTrackCmdPortTextBox->Location = System::Drawing::Point(124, 143);
			this->optiTrackCmdPortTextBox->Name = L"optiTrackCmdPortTextBox";
			this->optiTrackCmdPortTextBox->Size = System::Drawing::Size(144, 22);
			this->optiTrackCmdPortTextBox->TabIndex = 5;
			this->optiTrackCmdPortTextBox->Text = L"1510";
			this->optiTrackCmdPortTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::optiTrackCmdPortTextBox_TextChanged);
			// 
			// optiTrackCmdPortLabel
			// 
			this->optiTrackCmdPortLabel->AutoSize = true;
			this->optiTrackCmdPortLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->optiTrackCmdPortLabel->Location = System::Drawing::Point(6, 146);
			this->optiTrackCmdPortLabel->Name = L"optiTrackCmdPortLabel";
			this->optiTrackCmdPortLabel->Size = System::Drawing::Size(86, 13);
			this->optiTrackCmdPortLabel->TabIndex = 4;
			this->optiTrackCmdPortLabel->Text = L"Command Port:";
			// 
			// optiTrackSeverIpAddressTextBox
			// 
			this->optiTrackSeverIpAddressTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->optiTrackSeverIpAddressTextBox->Location = System::Drawing::Point(124, 115);
			this->optiTrackSeverIpAddressTextBox->Name = L"optiTrackSeverIpAddressTextBox";
			this->optiTrackSeverIpAddressTextBox->Size = System::Drawing::Size(144, 22);
			this->optiTrackSeverIpAddressTextBox->TabIndex = 3;
			this->optiTrackSeverIpAddressTextBox->Text = L"127.0.0.1";
			this->optiTrackSeverIpAddressTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::optiTrackSeverIpAddressTextBox_TextChanged);
			// 
			// optiTrackSeverIpAddressLabel
			// 
			this->optiTrackSeverIpAddressLabel->AutoSize = true;
			this->optiTrackSeverIpAddressLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->optiTrackSeverIpAddressLabel->Location = System::Drawing::Point(6, 118);
			this->optiTrackSeverIpAddressLabel->Name = L"optiTrackSeverIpAddressLabel";
			this->optiTrackSeverIpAddressLabel->Size = System::Drawing::Size(63, 13);
			this->optiTrackSeverIpAddressLabel->TabIndex = 2;
			this->optiTrackSeverIpAddressLabel->Text = L"IP Address:";
			// 
			// optiTrackServerTitleLabel
			// 
			this->optiTrackServerTitleLabel->AutoSize = true;
			this->optiTrackServerTitleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->optiTrackServerTitleLabel->Location = System::Drawing::Point(6, 95);
			this->optiTrackServerTitleLabel->Name = L"optiTrackServerTitleLabel";
			this->optiTrackServerTitleLabel->Size = System::Drawing::Size(94, 13);
			this->optiTrackServerTitleLabel->TabIndex = 1;
			this->optiTrackServerTitleLabel->Text = L"OptiTrack Server:";
			// 
			// optiTrackPropertiesLabel
			// 
			this->optiTrackPropertiesLabel->AutoSize = true;
			this->optiTrackPropertiesLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->optiTrackPropertiesLabel->Location = System::Drawing::Point(3, 9);
			this->optiTrackPropertiesLabel->Name = L"optiTrackPropertiesLabel";
			this->optiTrackPropertiesLabel->Size = System::Drawing::Size(71, 17);
			this->optiTrackPropertiesLabel->TabIndex = 0;
			this->optiTrackPropertiesLabel->Text = L"Properties";
			// 
			// DikablisPage
			// 
			this->DikablisPage->BackColor = System::Drawing::Color::Gainsboro;
			this->DikablisPage->Controls->Add(this->dikablisMainSplitContainer);
			this->DikablisPage->Location = System::Drawing::Point(4, 22);
			this->DikablisPage->Name = L"DikablisPage";
			this->DikablisPage->Padding = System::Windows::Forms::Padding(3);
			this->DikablisPage->Size = System::Drawing::Size(776, 509);
			this->DikablisPage->TabIndex = 0;
			this->DikablisPage->Text = L"Dikablis";
			// 
			// dikablisMainSplitContainer
			// 
			this->dikablisMainSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dikablisMainSplitContainer->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->dikablisMainSplitContainer->Location = System::Drawing::Point(3, 3);
			this->dikablisMainSplitContainer->Name = L"dikablisMainSplitContainer";
			// 
			// dikablisMainSplitContainer.Panel1
			// 
			this->dikablisMainSplitContainer->Panel1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->dikablisMainSplitContainer->Panel1->Controls->Add(this->dikablisSplitContainer);
			// 
			// dikablisMainSplitContainer.Panel2
			// 
			this->dikablisMainSplitContainer->Panel2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisCalibrationBtn);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisFieldYOutputLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisFieldXOutputLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeYOutputLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeXOutputLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeRoiZoomYOutputLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeRoiZoomXOutputLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeRoiVertOutputLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeRoiHorizOutputLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisTimeStampOutputLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisIndexOutputLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisHelpBtn);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisFieldYLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisFieldXLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeYLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeXLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeValidLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisOnlinecalibLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeroizoomyLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeroizoomxLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeroivertLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisEyeroihorizLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisTimeStampLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisDisConnectBtn);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisIndexTitle);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisOutputTitle);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisConnectBtn);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisPortTextBox);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisPortLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisIPTextBox);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisIPLabel);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisRecorderSetting);
			this->dikablisMainSplitContainer->Panel2->Controls->Add(this->dikablisPropertiesLabel);
			this->dikablisMainSplitContainer->Panel2MinSize = 273;
			this->dikablisMainSplitContainer->Size = System::Drawing::Size(770, 503);
			this->dikablisMainSplitContainer->SplitterDistance = 493;
			this->dikablisMainSplitContainer->TabIndex = 0;
			// 
			// dikablisSplitContainer
			// 
			this->dikablisSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dikablisSplitContainer->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->dikablisSplitContainer->Location = System::Drawing::Point(0, 0);
			this->dikablisSplitContainer->Name = L"dikablisSplitContainer";
			this->dikablisSplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// dikablisSplitContainer.Panel1
			// 
			this->dikablisSplitContainer->Panel1->BackColor = System::Drawing::Color::WhiteSmoke;
			// 
			// dikablisSplitContainer.Panel2
			// 
			this->dikablisSplitContainer->Panel2->BackColor = System::Drawing::Color::LightSlateGray;
			this->dikablisSplitContainer->Panel2->Controls->Add(this->dikablisOutputLogTextBox);
			this->dikablisSplitContainer->Panel2->Controls->Add(this->dikablisOutputLogLabel);
			this->dikablisSplitContainer->Size = System::Drawing::Size(493, 503);
			this->dikablisSplitContainer->SplitterDistance = 376;
			this->dikablisSplitContainer->TabIndex = 0;
			// 
			// dikablisOutputLogTextBox
			// 
			this->dikablisOutputLogTextBox->AcceptsReturn = true;
			this->dikablisOutputLogTextBox->AcceptsTab = true;
			this->dikablisOutputLogTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->dikablisOutputLogTextBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->dikablisOutputLogTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisOutputLogTextBox->Location = System::Drawing::Point(3, 16);
			this->dikablisOutputLogTextBox->Multiline = true;
			this->dikablisOutputLogTextBox->Name = L"dikablisOutputLogTextBox";
			this->dikablisOutputLogTextBox->ReadOnly = true;
			this->dikablisOutputLogTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->dikablisOutputLogTextBox->Size = System::Drawing::Size(487, 101);
			this->dikablisOutputLogTextBox->TabIndex = 1;
			// 
			// dikablisOutputLogLabel
			// 
			this->dikablisOutputLogLabel->AutoSize = true;
			this->dikablisOutputLogLabel->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->dikablisOutputLogLabel->Location = System::Drawing::Point(5, 0);
			this->dikablisOutputLogLabel->Name = L"dikablisOutputLogLabel";
			this->dikablisOutputLogLabel->Size = System::Drawing::Size(67, 13);
			this->dikablisOutputLogLabel->TabIndex = 0;
			this->dikablisOutputLogLabel->Text = L"Output Log";
			// 
			// dikablisCalibrationBtn
			// 
			this->dikablisCalibrationBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->dikablisCalibrationBtn->Location = System::Drawing::Point(193, 408);
			this->dikablisCalibrationBtn->Name = L"dikablisCalibrationBtn";
			this->dikablisCalibrationBtn->Size = System::Drawing::Size(75, 22);
			this->dikablisCalibrationBtn->TabIndex = 32;
			this->dikablisCalibrationBtn->Text = L"Calibration";
			this->dikablisCalibrationBtn->UseVisualStyleBackColor = true;
			this->dikablisCalibrationBtn->Click += gcnew System::EventHandler(this, &MainForm::dikablisCalibrationBtn_Click);
			// 
			// dikablisFieldYOutputLabel
			// 
			this->dikablisFieldYOutputLabel->AutoSize = true;
			this->dikablisFieldYOutputLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisFieldYOutputLabel->Location = System::Drawing::Point(121, 329);
			this->dikablisFieldYOutputLabel->Name = L"dikablisFieldYOutputLabel";
			this->dikablisFieldYOutputLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisFieldYOutputLabel->Size = System::Drawing::Size(19, 19);
			this->dikablisFieldYOutputLabel->TabIndex = 31;
			this->dikablisFieldYOutputLabel->Text = L"0";
			// 
			// dikablisFieldXOutputLabel
			// 
			this->dikablisFieldXOutputLabel->AutoSize = true;
			this->dikablisFieldXOutputLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisFieldXOutputLabel->Location = System::Drawing::Point(121, 307);
			this->dikablisFieldXOutputLabel->Name = L"dikablisFieldXOutputLabel";
			this->dikablisFieldXOutputLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisFieldXOutputLabel->Size = System::Drawing::Size(19, 19);
			this->dikablisFieldXOutputLabel->TabIndex = 30;
			this->dikablisFieldXOutputLabel->Text = L"0";
			// 
			// dikablisEyeYOutputLabel
			// 
			this->dikablisEyeYOutputLabel->AutoSize = true;
			this->dikablisEyeYOutputLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisEyeYOutputLabel->Location = System::Drawing::Point(121, 285);
			this->dikablisEyeYOutputLabel->Name = L"dikablisEyeYOutputLabel";
			this->dikablisEyeYOutputLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeYOutputLabel->Size = System::Drawing::Size(19, 19);
			this->dikablisEyeYOutputLabel->TabIndex = 29;
			this->dikablisEyeYOutputLabel->Text = L"0";
			// 
			// dikablisEyeXOutputLabel
			// 
			this->dikablisEyeXOutputLabel->AutoSize = true;
			this->dikablisEyeXOutputLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisEyeXOutputLabel->Location = System::Drawing::Point(121, 263);
			this->dikablisEyeXOutputLabel->Name = L"dikablisEyeXOutputLabel";
			this->dikablisEyeXOutputLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeXOutputLabel->Size = System::Drawing::Size(19, 19);
			this->dikablisEyeXOutputLabel->TabIndex = 28;
			this->dikablisEyeXOutputLabel->Text = L"0";
			// 
			// dikablisEyeRoiZoomYOutputLabel
			// 
			this->dikablisEyeRoiZoomYOutputLabel->AutoSize = true;
			this->dikablisEyeRoiZoomYOutputLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dikablisEyeRoiZoomYOutputLabel->Location = System::Drawing::Point(121, 241);
			this->dikablisEyeRoiZoomYOutputLabel->Name = L"dikablisEyeRoiZoomYOutputLabel";
			this->dikablisEyeRoiZoomYOutputLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeRoiZoomYOutputLabel->Size = System::Drawing::Size(19, 19);
			this->dikablisEyeRoiZoomYOutputLabel->TabIndex = 27;
			this->dikablisEyeRoiZoomYOutputLabel->Text = L"0";
			// 
			// dikablisEyeRoiZoomXOutputLabel
			// 
			this->dikablisEyeRoiZoomXOutputLabel->AutoSize = true;
			this->dikablisEyeRoiZoomXOutputLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dikablisEyeRoiZoomXOutputLabel->Location = System::Drawing::Point(121, 219);
			this->dikablisEyeRoiZoomXOutputLabel->Name = L"dikablisEyeRoiZoomXOutputLabel";
			this->dikablisEyeRoiZoomXOutputLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeRoiZoomXOutputLabel->Size = System::Drawing::Size(19, 19);
			this->dikablisEyeRoiZoomXOutputLabel->TabIndex = 26;
			this->dikablisEyeRoiZoomXOutputLabel->Text = L"0";
			// 
			// dikablisEyeRoiVertOutputLabel
			// 
			this->dikablisEyeRoiVertOutputLabel->AutoSize = true;
			this->dikablisEyeRoiVertOutputLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dikablisEyeRoiVertOutputLabel->Location = System::Drawing::Point(121, 197);
			this->dikablisEyeRoiVertOutputLabel->Name = L"dikablisEyeRoiVertOutputLabel";
			this->dikablisEyeRoiVertOutputLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeRoiVertOutputLabel->Size = System::Drawing::Size(19, 19);
			this->dikablisEyeRoiVertOutputLabel->TabIndex = 25;
			this->dikablisEyeRoiVertOutputLabel->Text = L"0";
			// 
			// dikablisEyeRoiHorizOutputLabel
			// 
			this->dikablisEyeRoiHorizOutputLabel->AutoSize = true;
			this->dikablisEyeRoiHorizOutputLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dikablisEyeRoiHorizOutputLabel->Location = System::Drawing::Point(121, 175);
			this->dikablisEyeRoiHorizOutputLabel->Name = L"dikablisEyeRoiHorizOutputLabel";
			this->dikablisEyeRoiHorizOutputLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeRoiHorizOutputLabel->Size = System::Drawing::Size(19, 19);
			this->dikablisEyeRoiHorizOutputLabel->TabIndex = 24;
			this->dikablisEyeRoiHorizOutputLabel->Text = L"0";
			// 
			// dikablisTimeStampOutputLabel
			// 
			this->dikablisTimeStampOutputLabel->AutoSize = true;
			this->dikablisTimeStampOutputLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dikablisTimeStampOutputLabel->Location = System::Drawing::Point(121, 153);
			this->dikablisTimeStampOutputLabel->Name = L"dikablisTimeStampOutputLabel";
			this->dikablisTimeStampOutputLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisTimeStampOutputLabel->Size = System::Drawing::Size(19, 19);
			this->dikablisTimeStampOutputLabel->TabIndex = 23;
			this->dikablisTimeStampOutputLabel->Text = L"0";
			// 
			// dikablisIndexOutputLabel
			// 
			this->dikablisIndexOutputLabel->AutoSize = true;
			this->dikablisIndexOutputLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisIndexOutputLabel->Location = System::Drawing::Point(121, 134);
			this->dikablisIndexOutputLabel->Name = L"dikablisIndexOutputLabel";
			this->dikablisIndexOutputLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisIndexOutputLabel->Size = System::Drawing::Size(19, 19);
			this->dikablisIndexOutputLabel->TabIndex = 22;
			this->dikablisIndexOutputLabel->Text = L"0";
			// 
			// dikablisHelpBtn
			// 
			this->dikablisHelpBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->dikablisHelpBtn->Location = System::Drawing::Point(193, 380);
			this->dikablisHelpBtn->Name = L"dikablisHelpBtn";
			this->dikablisHelpBtn->Size = System::Drawing::Size(75, 22);
			this->dikablisHelpBtn->TabIndex = 21;
			this->dikablisHelpBtn->Text = L"Help";
			this->dikablisHelpBtn->UseVisualStyleBackColor = true;
			this->dikablisHelpBtn->Click += gcnew System::EventHandler(this, &MainForm::dikablisHelpBtn_Click);
			// 
			// dikablisFieldYLabel
			// 
			this->dikablisFieldYLabel->AutoSize = true;
			this->dikablisFieldYLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisFieldYLabel->Location = System::Drawing::Point(7, 329);
			this->dikablisFieldYLabel->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->dikablisFieldYLabel->Name = L"dikablisFieldYLabel";
			this->dikablisFieldYLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisFieldYLabel->Size = System::Drawing::Size(49, 19);
			this->dikablisFieldYLabel->TabIndex = 20;
			this->dikablisFieldYLabel->Text = L"field_y:";
			// 
			// dikablisFieldXLabel
			// 
			this->dikablisFieldXLabel->AutoSize = true;
			this->dikablisFieldXLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisFieldXLabel->Location = System::Drawing::Point(7, 307);
			this->dikablisFieldXLabel->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->dikablisFieldXLabel->Name = L"dikablisFieldXLabel";
			this->dikablisFieldXLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisFieldXLabel->Size = System::Drawing::Size(49, 19);
			this->dikablisFieldXLabel->TabIndex = 19;
			this->dikablisFieldXLabel->Text = L"field_x:";
			// 
			// dikablisEyeYLabel
			// 
			this->dikablisEyeYLabel->AutoSize = true;
			this->dikablisEyeYLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisEyeYLabel->Location = System::Drawing::Point(7, 285);
			this->dikablisEyeYLabel->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->dikablisEyeYLabel->Name = L"dikablisEyeYLabel";
			this->dikablisEyeYLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeYLabel->Size = System::Drawing::Size(43, 19);
			this->dikablisEyeYLabel->TabIndex = 18;
			this->dikablisEyeYLabel->Text = L"eye_y:";
			// 
			// dikablisEyeXLabel
			// 
			this->dikablisEyeXLabel->AutoSize = true;
			this->dikablisEyeXLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisEyeXLabel->Location = System::Drawing::Point(6, 263);
			this->dikablisEyeXLabel->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->dikablisEyeXLabel->Name = L"dikablisEyeXLabel";
			this->dikablisEyeXLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeXLabel->Size = System::Drawing::Size(43, 19);
			this->dikablisEyeXLabel->TabIndex = 17;
			this->dikablisEyeXLabel->Text = L"eye_x:";
			// 
			// dikablisEyeValidLabel
			// 
			this->dikablisEyeValidLabel->AutoSize = true;
			this->dikablisEyeValidLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisEyeValidLabel->Location = System::Drawing::Point(6, 396);
			this->dikablisEyeValidLabel->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->dikablisEyeValidLabel->Name = L"dikablisEyeValidLabel";
			this->dikablisEyeValidLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeValidLabel->Size = System::Drawing::Size(131, 19);
			this->dikablisEyeValidLabel->TabIndex = 16;
			this->dikablisEyeValidLabel->Text = L"Pupil was not detected";
			// 
			// dikablisOnlinecalibLabel
			// 
			this->dikablisOnlinecalibLabel->AutoSize = true;
			this->dikablisOnlinecalibLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisOnlinecalibLabel->Location = System::Drawing::Point(6, 374);
			this->dikablisOnlinecalibLabel->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->dikablisOnlinecalibLabel->Name = L"dikablisOnlinecalibLabel";
			this->dikablisOnlinecalibLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisOnlinecalibLabel->Size = System::Drawing::Size(122, 19);
			this->dikablisOnlinecalibLabel->TabIndex = 15;
			this->dikablisOnlinecalibLabel->Text = L"No online calibration";
			// 
			// dikablisEyeroizoomyLabel
			// 
			this->dikablisEyeroizoomyLabel->AutoSize = true;
			this->dikablisEyeroizoomyLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisEyeroizoomyLabel->Location = System::Drawing::Point(6, 241);
			this->dikablisEyeroizoomyLabel->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->dikablisEyeroizoomyLabel->Name = L"dikablisEyeroizoomyLabel";
			this->dikablisEyeroizoomyLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeroizoomyLabel->Size = System::Drawing::Size(80, 19);
			this->dikablisEyeroizoomyLabel->TabIndex = 14;
			this->dikablisEyeroizoomyLabel->Text = L"eyeroizoomy:";
			// 
			// dikablisEyeroizoomxLabel
			// 
			this->dikablisEyeroizoomxLabel->AutoSize = true;
			this->dikablisEyeroizoomxLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisEyeroizoomxLabel->Location = System::Drawing::Point(6, 219);
			this->dikablisEyeroizoomxLabel->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->dikablisEyeroizoomxLabel->Name = L"dikablisEyeroizoomxLabel";
			this->dikablisEyeroizoomxLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeroizoomxLabel->Size = System::Drawing::Size(80, 19);
			this->dikablisEyeroizoomxLabel->TabIndex = 13;
			this->dikablisEyeroizoomxLabel->Text = L"eyeroizoomx:";
			// 
			// dikablisEyeroivertLabel
			// 
			this->dikablisEyeroivertLabel->AutoSize = true;
			this->dikablisEyeroivertLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisEyeroivertLabel->Location = System::Drawing::Point(6, 197);
			this->dikablisEyeroivertLabel->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->dikablisEyeroivertLabel->Name = L"dikablisEyeroivertLabel";
			this->dikablisEyeroivertLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeroivertLabel->Size = System::Drawing::Size(66, 19);
			this->dikablisEyeroivertLabel->TabIndex = 12;
			this->dikablisEyeroivertLabel->Text = L"eyeroivert:";
			// 
			// dikablisEyeroihorizLabel
			// 
			this->dikablisEyeroihorizLabel->AutoSize = true;
			this->dikablisEyeroihorizLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisEyeroihorizLabel->Location = System::Drawing::Point(6, 175);
			this->dikablisEyeroihorizLabel->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->dikablisEyeroihorizLabel->Name = L"dikablisEyeroihorizLabel";
			this->dikablisEyeroihorizLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisEyeroihorizLabel->Size = System::Drawing::Size(73, 19);
			this->dikablisEyeroihorizLabel->TabIndex = 11;
			this->dikablisEyeroihorizLabel->Text = L"eyeroihoriz:";
			// 
			// dikablisTimeStampLabel
			// 
			this->dikablisTimeStampLabel->AutoSize = true;
			this->dikablisTimeStampLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisTimeStampLabel->Location = System::Drawing::Point(6, 153);
			this->dikablisTimeStampLabel->Name = L"dikablisTimeStampLabel";
			this->dikablisTimeStampLabel->Padding = System::Windows::Forms::Padding(3);
			this->dikablisTimeStampLabel->Size = System::Drawing::Size(69, 19);
			this->dikablisTimeStampLabel->TabIndex = 10;
			this->dikablisTimeStampLabel->Text = L"timestamp:";
			// 
			// dikablisDisConnectBtn
			// 
			this->dikablisDisConnectBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->dikablisDisConnectBtn->Location = System::Drawing::Point(195, 474);
			this->dikablisDisConnectBtn->Name = L"dikablisDisConnectBtn";
			this->dikablisDisConnectBtn->Size = System::Drawing::Size(75, 23);
			this->dikablisDisConnectBtn->TabIndex = 9;
			this->dikablisDisConnectBtn->Text = L"Disconnect";
			this->dikablisDisConnectBtn->UseVisualStyleBackColor = true;
			this->dikablisDisConnectBtn->Click += gcnew System::EventHandler(this, &MainForm::dikablisDisConnectBtn_Click);
			// 
			// dikablisIndexTitle
			// 
			this->dikablisIndexTitle->AutoSize = true;
			this->dikablisIndexTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisIndexTitle->Location = System::Drawing::Point(6, 134);
			this->dikablisIndexTitle->Name = L"dikablisIndexTitle";
			this->dikablisIndexTitle->Padding = System::Windows::Forms::Padding(3);
			this->dikablisIndexTitle->Size = System::Drawing::Size(44, 19);
			this->dikablisIndexTitle->TabIndex = 8;
			this->dikablisIndexTitle->Text = L"Index:";
			// 
			// dikablisOutputTitle
			// 
			this->dikablisOutputTitle->AutoSize = true;
			this->dikablisOutputTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisOutputTitle->Location = System::Drawing::Point(6, 111);
			this->dikablisOutputTitle->Name = L"dikablisOutputTitle";
			this->dikablisOutputTitle->Size = System::Drawing::Size(47, 13);
			this->dikablisOutputTitle->TabIndex = 7;
			this->dikablisOutputTitle->Text = L"Output:";
			// 
			// dikablisConnectBtn
			// 
			this->dikablisConnectBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dikablisConnectBtn->Location = System::Drawing::Point(9, 477);
			this->dikablisConnectBtn->Name = L"dikablisConnectBtn";
			this->dikablisConnectBtn->Size = System::Drawing::Size(75, 23);
			this->dikablisConnectBtn->TabIndex = 6;
			this->dikablisConnectBtn->Text = L"Connect";
			this->dikablisConnectBtn->UseVisualStyleBackColor = true;
			this->dikablisConnectBtn->Click += gcnew System::EventHandler(this, &MainForm::dikablisConnectBtn_Click);
			// 
			// dikablisPortTextBox
			// 
			this->dikablisPortTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->dikablisPortTextBox->Location = System::Drawing::Point(124, 80);
			this->dikablisPortTextBox->Name = L"dikablisPortTextBox";
			this->dikablisPortTextBox->Size = System::Drawing::Size(144, 22);
			this->dikablisPortTextBox->TabIndex = 5;
			this->dikablisPortTextBox->Text = L"2002";
			// 
			// dikablisPortLabel
			// 
			this->dikablisPortLabel->AutoSize = true;
			this->dikablisPortLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisPortLabel->Location = System::Drawing::Point(6, 83);
			this->dikablisPortLabel->Name = L"dikablisPortLabel";
			this->dikablisPortLabel->Size = System::Drawing::Size(60, 13);
			this->dikablisPortLabel->TabIndex = 4;
			this->dikablisPortLabel->Text = L"Slave Port:";
			// 
			// dikablisIPTextBox
			// 
			this->dikablisIPTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->dikablisIPTextBox->Location = System::Drawing::Point(124, 52);
			this->dikablisIPTextBox->Name = L"dikablisIPTextBox";
			this->dikablisIPTextBox->Size = System::Drawing::Size(144, 22);
			this->dikablisIPTextBox->TabIndex = 3;
			this->dikablisIPTextBox->Text = L"127.0.0.1";
			// 
			// dikablisIPLabel
			// 
			this->dikablisIPLabel->AutoSize = true;
			this->dikablisIPLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisIPLabel->Location = System::Drawing::Point(6, 55);
			this->dikablisIPLabel->Name = L"dikablisIPLabel";
			this->dikablisIPLabel->Size = System::Drawing::Size(63, 13);
			this->dikablisIPLabel->TabIndex = 2;
			this->dikablisIPLabel->Text = L"IP Address:";
			// 
			// dikablisRecorderSetting
			// 
			this->dikablisRecorderSetting->AutoSize = true;
			this->dikablisRecorderSetting->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisRecorderSetting->Location = System::Drawing::Point(6, 32);
			this->dikablisRecorderSetting->Name = L"dikablisRecorderSetting";
			this->dikablisRecorderSetting->Size = System::Drawing::Size(100, 13);
			this->dikablisRecorderSetting->TabIndex = 1;
			this->dikablisRecorderSetting->Text = L"Dikablis Recorder:";
			// 
			// dikablisPropertiesLabel
			// 
			this->dikablisPropertiesLabel->AutoSize = true;
			this->dikablisPropertiesLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dikablisPropertiesLabel->Location = System::Drawing::Point(3, 9);
			this->dikablisPropertiesLabel->Name = L"dikablisPropertiesLabel";
			this->dikablisPropertiesLabel->Size = System::Drawing::Size(71, 17);
			this->dikablisPropertiesLabel->TabIndex = 0;
			this->dikablisPropertiesLabel->Text = L"Properties";
			// 
			// visualTabPage
			// 
			this->visualTabPage->BackColor = System::Drawing::Color::Gainsboro;
			this->visualTabPage->Controls->Add(this->visualMainSplitContainer);
			this->visualTabPage->Location = System::Drawing::Point(4, 22);
			this->visualTabPage->Name = L"visualTabPage";
			this->visualTabPage->Padding = System::Windows::Forms::Padding(3);
			this->visualTabPage->Size = System::Drawing::Size(776, 509);
			this->visualTabPage->TabIndex = 3;
			this->visualTabPage->Text = L"Visual";
			// 
			// visualMainSplitContainer
			// 
			this->visualMainSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->visualMainSplitContainer->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->visualMainSplitContainer->Location = System::Drawing::Point(3, 3);
			this->visualMainSplitContainer->Name = L"visualMainSplitContainer";
			// 
			// visualMainSplitContainer.Panel1
			// 
			this->visualMainSplitContainer->Panel1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->visualMainSplitContainer->Panel1->Controls->Add(this->visualSplitContainer);
			// 
			// visualMainSplitContainer.Panel2
			// 
			this->visualMainSplitContainer->Panel2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->visualMainSplitContainer->Panel2->Controls->Add(this->visualPropertiesTabControl);
			this->visualMainSplitContainer->Panel2MinSize = 273;
			this->visualMainSplitContainer->Size = System::Drawing::Size(770, 503);
			this->visualMainSplitContainer->SplitterDistance = 493;
			this->visualMainSplitContainer->TabIndex = 0;
			// 
			// visualSplitContainer
			// 
			this->visualSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->visualSplitContainer->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->visualSplitContainer->Location = System::Drawing::Point(0, 0);
			this->visualSplitContainer->Name = L"visualSplitContainer";
			this->visualSplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// visualSplitContainer.Panel1
			// 
			this->visualSplitContainer->Panel1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->visualSplitContainer->Panel1->Controls->Add(this->visualToolStrip);
			this->visualSplitContainer->Panel1MinSize = 200;
			// 
			// visualSplitContainer.Panel2
			// 
			this->visualSplitContainer->Panel2->BackColor = System::Drawing::Color::LightSlateGray;
			this->visualSplitContainer->Panel2->Controls->Add(this->visualRecorderPanel);
			this->visualSplitContainer->Panel2->Controls->Add(this->visualRecorderLabel);
			this->visualSplitContainer->Panel2MinSize = 100;
			this->visualSplitContainer->Size = System::Drawing::Size(493, 503);
			this->visualSplitContainer->SplitterDistance = 376;
			this->visualSplitContainer->TabIndex = 0;
			// 
			// visualToolStrip
			// 
			this->visualToolStrip->BackColor = System::Drawing::SystemColors::Window;
			this->visualToolStrip->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->visualToolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->visualViewerScaleLabel, 
				this->visualViewerScaleTextBox, this->toolStripSeparator1});
			this->visualToolStrip->Location = System::Drawing::Point(0, 0);
			this->visualToolStrip->Name = L"visualToolStrip";
			this->visualToolStrip->Size = System::Drawing::Size(493, 25);
			this->visualToolStrip->TabIndex = 0;
			this->visualToolStrip->Text = L"Tool Bar";
			// 
			// visualViewerScaleLabel
			// 
			this->visualViewerScaleLabel->ForeColor = System::Drawing::SystemColors::WindowText;
			this->visualViewerScaleLabel->Name = L"visualViewerScaleLabel";
			this->visualViewerScaleLabel->Size = System::Drawing::Size(68, 22);
			this->visualViewerScaleLabel->Text = L"Scene Scale";
			// 
			// visualViewerScaleTextBox
			// 
			this->visualViewerScaleTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->visualViewerScaleTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->visualViewerScaleTextBox->ForeColor = System::Drawing::SystemColors::WindowText;
			this->visualViewerScaleTextBox->Name = L"visualViewerScaleTextBox";
			this->visualViewerScaleTextBox->Size = System::Drawing::Size(50, 25);
			this->visualViewerScaleTextBox->Text = L"1.0";
			this->visualViewerScaleTextBox->TextBoxTextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// visualRecorderPanel
			// 
			this->visualRecorderPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->visualRecorderPanel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->visualRecorderPanel->Controls->Add(this->stopRecordingBtn);
			this->visualRecorderPanel->Controls->Add(this->startRecordingBtn);
			this->visualRecorderPanel->Location = System::Drawing::Point(3, 16);
			this->visualRecorderPanel->Name = L"visualRecorderPanel";
			this->visualRecorderPanel->Size = System::Drawing::Size(487, 101);
			this->visualRecorderPanel->TabIndex = 1;
			// 
			// stopRecordingBtn
			// 
			this->stopRecordingBtn->Location = System::Drawing::Point(131, 3);
			this->stopRecordingBtn->Name = L"stopRecordingBtn";
			this->stopRecordingBtn->Size = System::Drawing::Size(122, 23);
			this->stopRecordingBtn->TabIndex = 1;
			this->stopRecordingBtn->Text = L"Stop Recording";
			this->stopRecordingBtn->UseVisualStyleBackColor = true;
			this->stopRecordingBtn->Click += gcnew System::EventHandler(this, &MainForm::stopRecordingBtn_Click);
			// 
			// startRecordingBtn
			// 
			this->startRecordingBtn->Location = System::Drawing::Point(3, 3);
			this->startRecordingBtn->Name = L"startRecordingBtn";
			this->startRecordingBtn->Size = System::Drawing::Size(122, 23);
			this->startRecordingBtn->TabIndex = 0;
			this->startRecordingBtn->Text = L"Start Recording";
			this->startRecordingBtn->UseVisualStyleBackColor = true;
			this->startRecordingBtn->Click += gcnew System::EventHandler(this, &MainForm::startRecordingBtn_Click);
			// 
			// visualRecorderLabel
			// 
			this->visualRecorderLabel->AutoSize = true;
			this->visualRecorderLabel->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->visualRecorderLabel->Location = System::Drawing::Point(5, 0);
			this->visualRecorderLabel->Name = L"visualRecorderLabel";
			this->visualRecorderLabel->Size = System::Drawing::Size(53, 13);
			this->visualRecorderLabel->TabIndex = 0;
			this->visualRecorderLabel->Text = L"Recorder";
			// 
			// visualPropertiesTabControl
			// 
			this->visualPropertiesTabControl->Controls->Add(this->rigidBodyTabPage);
			this->visualPropertiesTabControl->Controls->Add(this->worldTabPage);
			this->visualPropertiesTabControl->Controls->Add(this->objectTabPage);
			this->visualPropertiesTabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->visualPropertiesTabControl->Location = System::Drawing::Point(0, 0);
			this->visualPropertiesTabControl->Name = L"visualPropertiesTabControl";
			this->visualPropertiesTabControl->SelectedIndex = 0;
			this->visualPropertiesTabControl->Size = System::Drawing::Size(273, 503);
			this->visualPropertiesTabControl->TabIndex = 6;
			// 
			// rigidBodyTabPage
			// 
			this->rigidBodyTabPage->Controls->Add(this->visualRigidBodyListView);
			this->rigidBodyTabPage->Location = System::Drawing::Point(4, 22);
			this->rigidBodyTabPage->Name = L"rigidBodyTabPage";
			this->rigidBodyTabPage->Padding = System::Windows::Forms::Padding(3);
			this->rigidBodyTabPage->Size = System::Drawing::Size(265, 477);
			this->rigidBodyTabPage->TabIndex = 0;
			this->rigidBodyTabPage->Text = L"Rigid Body";
			this->rigidBodyTabPage->UseVisualStyleBackColor = true;
			// 
			// visualRigidBodyListView
			// 
			this->visualRigidBodyListView->Alignment = System::Windows::Forms::ListViewAlignment::Left;
			this->visualRigidBodyListView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->visualRigidBodyListView->FullRowSelect = true;
			this->visualRigidBodyListView->LabelWrap = false;
			this->visualRigidBodyListView->Location = System::Drawing::Point(3, 3);
			this->visualRigidBodyListView->MultiSelect = false;
			this->visualRigidBodyListView->Name = L"visualRigidBodyListView";
			this->visualRigidBodyListView->Size = System::Drawing::Size(259, 471);
			this->visualRigidBodyListView->TabIndex = 1;
			this->visualRigidBodyListView->TileSize = System::Drawing::Size(100, 20);
			this->visualRigidBodyListView->UseCompatibleStateImageBehavior = false;
			this->visualRigidBodyListView->View = System::Windows::Forms::View::SmallIcon;
			this->visualRigidBodyListView->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::visualRigidBodyListView_MouseClick);
			// 
			// worldTabPage
			// 
			this->worldTabPage->Controls->Add(this->worldRemoveButton);
			this->worldTabPage->Controls->Add(this->worldListLabel);
			this->worldTabPage->Controls->Add(this->worldGridView);
			this->worldTabPage->Controls->Add(this->worldAddButton);
			this->worldTabPage->Controls->Add(this->worldComboBox);
			this->worldTabPage->Location = System::Drawing::Point(4, 22);
			this->worldTabPage->Name = L"worldTabPage";
			this->worldTabPage->Padding = System::Windows::Forms::Padding(3);
			this->worldTabPage->Size = System::Drawing::Size(265, 477);
			this->worldTabPage->TabIndex = 1;
			this->worldTabPage->Text = L"World";
			this->worldTabPage->UseVisualStyleBackColor = true;
			// 
			// worldRemoveButton
			// 
			this->worldRemoveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->worldRemoveButton->Enabled = false;
			this->worldRemoveButton->Location = System::Drawing::Point(155, 448);
			this->worldRemoveButton->Name = L"worldRemoveButton";
			this->worldRemoveButton->Size = System::Drawing::Size(101, 23);
			this->worldRemoveButton->TabIndex = 2;
			this->worldRemoveButton->Text = L"Remove World";
			this->worldRemoveButton->UseVisualStyleBackColor = true;
			this->worldRemoveButton->Click += gcnew System::EventHandler(this, &MainForm::worldRemoveButton_Click);
			// 
			// worldListLabel
			// 
			this->worldListLabel->AutoSize = true;
			this->worldListLabel->Location = System::Drawing::Point(3, 3);
			this->worldListLabel->Name = L"worldListLabel";
			this->worldListLabel->Size = System::Drawing::Size(39, 13);
			this->worldListLabel->TabIndex = 4;
			this->worldListLabel->Text = L"World";
			// 
			// worldGridView
			// 
			this->worldGridView->AllowUserToAddRows = false;
			this->worldGridView->AllowUserToDeleteRows = false;
			this->worldGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->worldGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->worldGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->worldGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->worldPropertyColumn, 
				this->worldValueColumn});
			this->worldGridView->Location = System::Drawing::Point(6, 46);
			this->worldGridView->Name = L"worldGridView";
			this->worldGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->worldGridView->Size = System::Drawing::Size(250, 396);
			this->worldGridView->TabIndex = 3;
			this->worldGridView->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::worldGridView_CellDoubleClick);
			this->worldGridView->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::worldGridView_CellValueChanged);
			// 
			// worldPropertyColumn
			// 
			this->worldPropertyColumn->HeaderText = L"Property";
			this->worldPropertyColumn->Name = L"worldPropertyColumn";
			this->worldPropertyColumn->ReadOnly = true;
			this->worldPropertyColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// worldValueColumn
			// 
			this->worldValueColumn->HeaderText = L"Value";
			this->worldValueColumn->Name = L"worldValueColumn";
			this->worldValueColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// worldAddButton
			// 
			this->worldAddButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->worldAddButton->Location = System::Drawing::Point(200, 17);
			this->worldAddButton->Name = L"worldAddButton";
			this->worldAddButton->Size = System::Drawing::Size(56, 23);
			this->worldAddButton->TabIndex = 2;
			this->worldAddButton->Text = L"Add";
			this->worldAddButton->UseVisualStyleBackColor = true;
			this->worldAddButton->Click += gcnew System::EventHandler(this, &MainForm::worldAddButton_Click);
			// 
			// worldComboBox
			// 
			this->worldComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->worldComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->worldComboBox->ForeColor = System::Drawing::SystemColors::InfoText;
			this->worldComboBox->FormattingEnabled = true;
			this->worldComboBox->Location = System::Drawing::Point(6, 19);
			this->worldComboBox->Name = L"worldComboBox";
			this->worldComboBox->Size = System::Drawing::Size(188, 21);
			this->worldComboBox->TabIndex = 0;
			this->worldComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::worldComboBox_SelectedIndexChanged);
			// 
			// objectTabPage
			// 
			this->objectTabPage->Controls->Add(this->removeObjectButton);
			this->objectTabPage->Controls->Add(this->objectLabel);
			this->objectTabPage->Controls->Add(this->objectWLabel);
			this->objectTabPage->Controls->Add(this->objectWComboBox);
			this->objectTabPage->Controls->Add(this->objectAddButton);
			this->objectTabPage->Controls->Add(this->objectComboBox);
			this->objectTabPage->Controls->Add(this->objectGridView);
			this->objectTabPage->Location = System::Drawing::Point(4, 22);
			this->objectTabPage->Name = L"objectTabPage";
			this->objectTabPage->Padding = System::Windows::Forms::Padding(3);
			this->objectTabPage->Size = System::Drawing::Size(265, 477);
			this->objectTabPage->TabIndex = 2;
			this->objectTabPage->Text = L"Object";
			this->objectTabPage->UseVisualStyleBackColor = true;
			// 
			// removeObjectButton
			// 
			this->removeObjectButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->removeObjectButton->Enabled = false;
			this->removeObjectButton->Location = System::Drawing::Point(155, 448);
			this->removeObjectButton->Name = L"removeObjectButton";
			this->removeObjectButton->Size = System::Drawing::Size(101, 23);
			this->removeObjectButton->TabIndex = 13;
			this->removeObjectButton->Text = L"Remove Object";
			this->removeObjectButton->UseVisualStyleBackColor = true;
			this->removeObjectButton->Click += gcnew System::EventHandler(this, &MainForm::removeObjectButton_Click);
			// 
			// objectLabel
			// 
			this->objectLabel->AutoSize = true;
			this->objectLabel->Location = System::Drawing::Point(3, 43);
			this->objectLabel->Name = L"objectLabel";
			this->objectLabel->Size = System::Drawing::Size(41, 13);
			this->objectLabel->TabIndex = 12;
			this->objectLabel->Text = L"Object";
			// 
			// objectWLabel
			// 
			this->objectWLabel->AutoSize = true;
			this->objectWLabel->Location = System::Drawing::Point(3, 3);
			this->objectWLabel->Name = L"objectWLabel";
			this->objectWLabel->Size = System::Drawing::Size(39, 13);
			this->objectWLabel->TabIndex = 11;
			this->objectWLabel->Text = L"World";
			// 
			// objectWComboBox
			// 
			this->objectWComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->objectWComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->objectWComboBox->ForeColor = System::Drawing::SystemColors::InfoText;
			this->objectWComboBox->FormattingEnabled = true;
			this->objectWComboBox->Location = System::Drawing::Point(6, 19);
			this->objectWComboBox->Name = L"objectWComboBox";
			this->objectWComboBox->Size = System::Drawing::Size(188, 21);
			this->objectWComboBox->TabIndex = 9;
			this->objectWComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::objectWComboBox_SelectedIndexChanged);
			// 
			// objectAddButton
			// 
			this->objectAddButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->objectAddButton->Enabled = false;
			this->objectAddButton->Location = System::Drawing::Point(200, 57);
			this->objectAddButton->Name = L"objectAddButton";
			this->objectAddButton->Size = System::Drawing::Size(56, 23);
			this->objectAddButton->TabIndex = 8;
			this->objectAddButton->Text = L"Add";
			this->objectAddButton->UseVisualStyleBackColor = true;
			this->objectAddButton->Click += gcnew System::EventHandler(this, &MainForm::objectAddButton_Click);
			// 
			// objectComboBox
			// 
			this->objectComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->objectComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->objectComboBox->ForeColor = System::Drawing::SystemColors::InfoText;
			this->objectComboBox->FormattingEnabled = true;
			this->objectComboBox->Location = System::Drawing::Point(6, 59);
			this->objectComboBox->Name = L"objectComboBox";
			this->objectComboBox->Size = System::Drawing::Size(188, 21);
			this->objectComboBox->TabIndex = 7;
			this->objectComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::objectComboBox_SelectedIndexChanged);
			// 
			// objectGridView
			// 
			this->objectGridView->AllowUserToAddRows = false;
			this->objectGridView->AllowUserToDeleteRows = false;
			this->objectGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->objectGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->objectGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->objectGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->objectPropertyColumn, 
				this->objectValueColumn});
			this->objectGridView->Location = System::Drawing::Point(6, 86);
			this->objectGridView->Name = L"objectGridView";
			this->objectGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->objectGridView->Size = System::Drawing::Size(250, 356);
			this->objectGridView->TabIndex = 6;
			this->objectGridView->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::objectGridView_CellDoubleClick);
			this->objectGridView->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::objectGridView_CellValueChanged);
			// 
			// objectPropertyColumn
			// 
			this->objectPropertyColumn->HeaderText = L"Property";
			this->objectPropertyColumn->Name = L"objectPropertyColumn";
			this->objectPropertyColumn->ReadOnly = true;
			this->objectPropertyColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// objectValueColumn
			// 
			this->objectValueColumn->HeaderText = L"Value";
			this->objectValueColumn->Name = L"objectValueColumn";
			this->objectValueColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->projectToolStripMenuItem, 
				this->calibrationToolStripMenuItem, this->objectToolStripMenuItem});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(784, 24);
			this->menuStrip->TabIndex = 1;
			// 
			// projectToolStripMenuItem
			// 
			this->projectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->newToolStripMenuItem, 
				this->openToolStripMenuItem, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem});
			this->projectToolStripMenuItem->Name = L"projectToolStripMenuItem";
			this->projectToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->projectToolStripMenuItem->Text = L"Project";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->ShortcutKeyDisplayString = L"Ctrl+N";
			this->newToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->newToolStripMenuItem->Text = L"New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::newToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeyDisplayString = L"Ctrl+O";
			this->openToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeyDisplayString = L"Ctrl+S";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->ShortcutKeyDisplayString = L"Ctrl+Shift+S";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveAsToolStripMenuItem_Click);
			// 
			// calibrationToolStripMenuItem
			// 
			this->calibrationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->eyeCalibrationToolStripMenuItem});
			this->calibrationToolStripMenuItem->Name = L"calibrationToolStripMenuItem";
			this->calibrationToolStripMenuItem->Size = System::Drawing::Size(77, 20);
			this->calibrationToolStripMenuItem->Text = L"Calibration";
			// 
			// eyeCalibrationToolStripMenuItem
			// 
			this->eyeCalibrationToolStripMenuItem->Name = L"eyeCalibrationToolStripMenuItem";
			this->eyeCalibrationToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->eyeCalibrationToolStripMenuItem->Text = L"Eye Calibration";
			this->eyeCalibrationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::eyeCalibrationToolStripMenuItem_Click);
			// 
			// objectToolStripMenuItem
			// 
			this->objectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->addObjectToolStripMenuItem});
			this->objectToolStripMenuItem->Name = L"objectToolStripMenuItem";
			this->objectToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->objectToolStripMenuItem->Text = L"Object";
			// 
			// addObjectToolStripMenuItem
			// 
			this->addObjectToolStripMenuItem->Name = L"addObjectToolStripMenuItem";
			this->addObjectToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->addObjectToolStripMenuItem->Text = L"Add Object";
			this->addObjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::addObjectToolStripMenuItem_Click);
			// 
			// rigidBodyToolContextMenu
			// 
			this->rigidBodyToolContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->setAsRigidBodyToolToolStripMenuItem, 
				this->attachToExistingObjectToolStripMenuItem});
			this->rigidBodyToolContextMenu->Name = L"contextMenuStrip1";
			this->rigidBodyToolContextMenu->Size = System::Drawing::Size(205, 70);
			// 
			// setAsRigidBodyToolToolStripMenuItem
			// 
			this->setAsRigidBodyToolToolStripMenuItem->Name = L"setAsRigidBodyToolToolStripMenuItem";
			this->setAsRigidBodyToolToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->setAsRigidBodyToolToolStripMenuItem->Text = L"Set as Rigid Body Tool";
			this->setAsRigidBodyToolToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::setAsRigidBodyToolToolStripMenuItem_Click);
			// 
			// attachToExistingObjectToolStripMenuItem
			// 
			this->attachToExistingObjectToolStripMenuItem->Name = L"attachToExistingObjectToolStripMenuItem";
			this->attachToExistingObjectToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->attachToExistingObjectToolStripMenuItem->Text = L"Attach to Existing Object";
			this->attachToExistingObjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::attachToExistingObjectToolStripMenuItem_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->mainTabControl);
			this->Controls->Add(this->menuStrip);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip;
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"MainForm";
			this->Text = L"Untitled.xml - BlinkAnalysis";
			this->Closed += gcnew System::EventHandler(this, &MainForm::MainForm_Closed);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_Closing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_OnKeyDown);
			this->mainTabControl->ResumeLayout(false);
			this->OptiTrackPage->ResumeLayout(false);
			this->optiTrackMainSplitContainer->Panel1->ResumeLayout(false);
			this->optiTrackMainSplitContainer->Panel2->ResumeLayout(false);
			this->optiTrackMainSplitContainer->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->optiTrackMainSplitContainer))->EndInit();
			this->optiTrackMainSplitContainer->ResumeLayout(false);
			this->optiTrackSplitContainer->Panel1->ResumeLayout(false);
			this->optiTrackSplitContainer->Panel2->ResumeLayout(false);
			this->optiTrackSplitContainer->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->optiTrackSplitContainer))->EndInit();
			this->optiTrackSplitContainer->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->optiTrackDataGridView))->EndInit();
			this->DikablisPage->ResumeLayout(false);
			this->dikablisMainSplitContainer->Panel1->ResumeLayout(false);
			this->dikablisMainSplitContainer->Panel2->ResumeLayout(false);
			this->dikablisMainSplitContainer->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dikablisMainSplitContainer))->EndInit();
			this->dikablisMainSplitContainer->ResumeLayout(false);
			this->dikablisSplitContainer->Panel2->ResumeLayout(false);
			this->dikablisSplitContainer->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dikablisSplitContainer))->EndInit();
			this->dikablisSplitContainer->ResumeLayout(false);
			this->visualTabPage->ResumeLayout(false);
			this->visualMainSplitContainer->Panel1->ResumeLayout(false);
			this->visualMainSplitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->visualMainSplitContainer))->EndInit();
			this->visualMainSplitContainer->ResumeLayout(false);
			this->visualSplitContainer->Panel1->ResumeLayout(false);
			this->visualSplitContainer->Panel1->PerformLayout();
			this->visualSplitContainer->Panel2->ResumeLayout(false);
			this->visualSplitContainer->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->visualSplitContainer))->EndInit();
			this->visualSplitContainer->ResumeLayout(false);
			this->visualToolStrip->ResumeLayout(false);
			this->visualToolStrip->PerformLayout();
			this->visualRecorderPanel->ResumeLayout(false);
			this->visualPropertiesTabControl->ResumeLayout(false);
			this->rigidBodyTabPage->ResumeLayout(false);
			this->worldTabPage->ResumeLayout(false);
			this->worldTabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->worldGridView))->EndInit();
			this->objectTabPage->ResumeLayout(false);
			this->objectTabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->objectGridView))->EndInit();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->rigidBodyToolContextMenu->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/////////////////
	// User Defined
	////////////////

	// Local Variables
	private: std::vector<RigidBody*>* optiTrackRigidBodyVector;
	private: std::vector<Marker*>* optiTrackLabeledMarkerVector;
	private: SplitContainer^ currentMainSplitContainer;
	private: SplitContainer^ currentSplitContainer;
	private: int setRigidBodyTool;		// ID of rigid body to use as pointing tool
	private: int displayWorld;			// ID of world displayed in World tab
	private: int displayObjectWorld;	// ID of world of object displayed in Object tab
	private: int displayObject;			// ID of object displayed in Object tab

	// User Defined Functions
	private: void getOptiTrackInfo() {
				 ClientHandler* client = AppData::getInstance()->getClient();

				 // Local Ip Address
				 String^ localIP = this->optiTrackLocalIpAddressTextBox->Text;
				 client->setLocalIpAddress( marshal_as<std::string>(localIP).c_str() );

				 // Server Ip Address
				 String^ serverIP = this->optiTrackSeverIpAddressTextBox->Text;
				 client->setOptiTrackServerIpAddress( marshal_as<std::string>(serverIP).c_str() );

				 // Command Port
				 String^ commandPort = this->optiTrackCmdPortTextBox->Text;
				 client->setOptiTrackServerCommandPort(System::Int32::Parse(commandPort));

				 // Data Port
				 String^ dataPort = this->optiTrackDataPortTextBox->Text;
				 client->setOptiTrackServerDataPort(System::Int32::Parse(dataPort));

				 // Connection Type
				 String^ connectionType = (String^)this->optiTrackConnectionTypeComboBox->SelectedItem;
				 if (!String::Compare(connectionType, "Multicast"))
					 client->setOptiTrackServerConnectionType(ConnectionType_Multicast);
				 else if (!String::Compare(connectionType, "Unicast"))
					 client->setOptiTrackServerConnectionType(ConnectionType_Unicast);
			 }
	private: void setOptiTrackInfo() {
				 ClientHandler* client = AppData::getInstance()->getClient();

				 if (!client)
					 return;

				 char buf[128];
				 // Local Ip Address
				 client->getLocalIpAddress(buf);
				 this->optiTrackLocalIpAddressTextBox->Text = gcnew String(buf);

				 // Server Ip Address
				 client->getOptiTrackServerIpAddress(buf);
				 this->optiTrackSeverIpAddressTextBox->Text = gcnew String(buf);

				 // Command Port
				 this->optiTrackCmdPortTextBox->Text = Convert::ToString(client->getOptiTrackServerCommandPort());

				 // Data Port
				 this->optiTrackDataPortTextBox->Text = Convert::ToString(client->getOptiTrackServerDataPort());

				 // Connection Type
				 if (client->getOptiTrackServerConnectionType() == ConnectionType_Multicast)
					 this->optiTrackConnectionTypeComboBox->SelectedItem = "Multicast";
				 else if (client->getOptiTrackServerConnectionType() == ConnectionType_Unicast)
				 this->optiTrackConnectionTypeComboBox->SelectedItem = "Unicast";
			 }
	public: void updateTitle() {
				String^ fileName = gcnew String(AppData::getInstance()->getFileName());

				if (AppData::getInstance()->isSaveNeeded())
					this->Text = fileName + "* - BlinkAnalysis";
				else
					this->Text = fileName + " - BlinkAnalysis";
			}
	public: void setFormName(String^ name) { 
				FileInfo^ fileInfo = gcnew FileInfo( name );
				if (  !fileInfo->Exists ) { return; }
				this->Text = fileInfo->Name + " - BlinkAnalysis";
				
				msclr::interop::marshal_context context;
				std::string fileName =  context.marshal_as<std::string>(fileInfo->Name);
				AppData::getInstance()->setFileName((char*)fileName.c_str());
			}
	private: void newProject() {
				 this->Close();
				 if(this->IsDisposed)
					 Application::Restart();
			 }
	private: void openProject() {
				 OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;

				 openFileDialog->InitialDirectory = System::Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
				 openFileDialog->Filter = "XML File (*.xml)|*.xml|All files (*.*)|*.*";
				 openFileDialog->FilterIndex = 2;
				 openFileDialog->RestoreDirectory = true;

				 if ( openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 this->Close();
					 if(this->IsDisposed) {
						 System::Diagnostics::Process::Start( Application::ExecutablePath, openFileDialog->FileName);
						 Environment::Exit(0);
					 }
				 }
			 }
	private: bool saveProject() {
				 String^ filePath = gcnew String(AppData::getInstance()->getFilePath());

				 if (filePath->Length == 0)
					 return saveAsProject();
				 else
					 return AppData::getInstance()->saveFile();
			 }
	private: bool saveAsProject() {
				 SaveFileDialog^ dialog = gcnew SaveFileDialog();
				 dialog->Title = "Save As...";
				 dialog->Filter = "XML File (*.xml)|*.xml";
				 dialog->RestoreDirectory = true;

				 if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 msclr::interop::marshal_context context;
					 std::string filePath =  context.marshal_as<std::string>(dialog->FileName);
					 AppData::getInstance()->setFilePath((char*)filePath.c_str());

					 bool success = AppData::getInstance()->saveFile();

					 FileInfo^ fileInfo = gcnew FileInfo( dialog->FileName );
					 if (  !fileInfo->Exists ) { return false; }
					 
					 std::string fileName =  context.marshal_as<std::string>(fileInfo->Name);
					 AppData::getInstance()->setFileName((char*)fileName.c_str());
					 this->updateTitle();

					 return success;
				 }

				 return false;
			 }
	// Form Events
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 // Setup Main Tab
				 this->currentMainSplitContainer = this->optiTrackMainSplitContainer;
				 this->currentSplitContainer = this->optiTrackSplitContainer;
				 
				 this->optiTrackMainSplitContainer->SplitterMoved += gcnew System::Windows::Forms::SplitterEventHandler(this, &MainForm::splitterMoved);
				 this->optiTrackSplitContainer->SplitterMoved += gcnew System::Windows::Forms::SplitterEventHandler(this, &MainForm::splitterMoved);

				 this->mainTabControl->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::updateCurrentSplitContainer);

				 //this->SetStyle(ControlStyles::OptimizedDoubleBuffer, true);
				 this->SetStyle(ControlStyles::UserPaint, true);
				 this->SetStyle(ControlStyles::AllPaintingInWmPaint, true); 
				 this->SetStyle(ControlStyles::DoubleBuffer, true);
				 this->SetStyle(ControlStyles::ResizeRedraw, true);

				 this->optiTrackDataGridView->CellValueNeeded += gcnew
					 DataGridViewCellValueEventHandler( this, &MainForm::optiTrackDataGridView_CellValueNeeded );

				 for (int i = 0; i < this->optiTrackDataGridView->ColumnCount; i++)
				 {
					 this->optiTrackDataGridView->Columns[i]->SortMode = DataGridViewColumnSortMode::NotSortable;
				 }

				 this->optiTrackDataGridView->VirtualMode = true;

				 // Visual
				 this->visualViewerScaleTextBox->TextChanged += 
					 gcnew System::EventHandler(this, &MainForm::visualViewerScaleTextBox_TextChanged);
				 this->visualViewerScaleTextBox->KeyPress += 
				 gcnew KeyPressEventHandler(this, &MainForm::visualViewerScaleTextBox_KeyPress);
				 AppViewer::initAppViewer((HWND)this->visualSplitContainer->Panel1->Handle.ToPointer());

				 this->visualRigidBodyListView->View = View::Details;
				 this->visualRigidBodyListView->Columns->Add("Id", 50, HorizontalAlignment::Left ); 
				 this->visualRigidBodyListView->Columns->Add("Name", 150, HorizontalAlignment::Left ); 

				 this->rigidBodyToolContextMenu->Close();
			 }
	private: System::Void MainForm_Closing( Object^ /*sender*/, System::Windows::Forms::FormClosingEventArgs^ e) 
			 {
				 if (AppData::getInstance()->isSaveNeeded()) {
					 System::Windows::Forms::DialogResult result;

					 result = MessageBox::Show("Do you want to save any changes to the current Project?", "Closing Project", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
					 if(result == System::Windows::Forms::DialogResult::Yes){
						 if(!saveProject())
							 e->Cancel = true;
					 } else if(result == System::Windows::Forms::DialogResult::Cancel){
						 e->Cancel = true;
					 }
				 }
			 }
	private: System::Void MainForm_Closed( Object^ /*sender*/, System::EventArgs ^ e )
			{
				AppViewer::stopAppViewer();

				ClientHandler* client = AppData::getInstance()->getClient();
				if (client) {
					NatNetClientSetup::deleteClient(&client);

					client->clearLabeledMarkers();
					std::map<int, RigidBody*>* bodyMap = client->getRigidBodyMap();
					
					for (std::map<int, RigidBody*>::iterator it=bodyMap->begin(); it!=bodyMap->end(); ++it)
					{
						delete it->second;
					}

					if (optiTrackRigidBodyVector)
						delete optiTrackRigidBodyVector;

					if (optiTrackLabeledMarkerVector)
						delete optiTrackLabeledMarkerVector;

					delete client;
				}

				WorldManager::getInstance()->clearWorlds();

				Dikablis::stopServer();

#if _DEBUG
_WATCH_MEMORY
#endif
			 }
	private: System::Void MainForm_OnKeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if ((e->Control) && (e->KeyCode == Keys::N)) {
					 this->newProject();
				 } else if ((e->Control) && (e->KeyCode == Keys::O)) {
					 this->openProject();
				 } else if ((e->Control && e->Shift) && (e->KeyCode == Keys::S)) {
					 this->saveAsProject();
				 } else if ((e->Control) && (e->KeyCode == Keys::S)) {
					 this->saveProject();
				 }
			 }
	public: System::Void setInformation() {
				 this->setOptiTrackInfo();
			 }
	public: System::Void getInformation() {
				 this->getOptiTrackInfo();
			 }
	//////////////////////
	// Dikablis
	/////////////////////
	private: delegate void SetDelegate();
			 // Abstract Delegate to change text
	private: delegate void SetTextDelegate(String^ value);
			 // Abstract Delegate to change integer value
	private: delegate void SetIntDelegate(int value);
			 // Abstract Delegate to change unsigned integer value
	private: delegate void SetUIntDelegate(unsigned int value);
			 // Appends new messages to the Dikablis Tab Output Log
	public: System::Void dikablisOutputLog(String^ msg) {
				if (dikablisOutputLogTextBox->InvokeRequired)
				{
					SetTextDelegate^ d = gcnew SetTextDelegate(this, &BlinkAnalysis::MainForm::dikablisOutputLog);
					this->Invoke(d, gcnew array<Object^> { msg });
				} else {
					// Determine if the text being appended to dikablisOutputLogTextBox exceeds the MaxLength property.
					if((unsigned int)(dikablisOutputLogTextBox->TextLength + msg->Length) > (unsigned int)dikablisOutputLogTextBox->MaxLength)
					{
						int over = (dikablisOutputLogTextBox->TextLength + msg->Length) - dikablisOutputLogTextBox->MaxLength;
						dikablisOutputLogTextBox->Text = dikablisOutputLogTextBox->Text->Substring(over);
					}
					// Append the text
					dikablisOutputLogTextBox->AppendText(msg->Replace("\n", Environment::NewLine));
				}
			 }
	public: System::Void dikablisSetIndex(unsigned int value) {
				if (this->dikablisIndexOutputLabel->InvokeRequired)
				{
					SetUIntDelegate^ d = gcnew SetUIntDelegate(this, &BlinkAnalysis::MainForm::dikablisSetIndex);
					this->Invoke(d, value);
				} else {
					// Update Value
					this->dikablisIndexOutputLabel->Text = Convert::ToString(value);
				}
			}
	public: System::Void dikablisSetTimeStamp(unsigned int value) {
				if (this->dikablisTimeStampOutputLabel->InvokeRequired)
				{
					SetUIntDelegate^ d = gcnew SetUIntDelegate(this, &BlinkAnalysis::MainForm::dikablisSetTimeStamp);
					this->Invoke(d, value);
				} else {
					// Update Value
					this->dikablisTimeStampOutputLabel->Text = Convert::ToString(value);
				}
			}
	public: System::Void dikablisSetEyeRoiHoriz(int value) {
				if (this->dikablisEyeRoiHorizOutputLabel->InvokeRequired)
				{
					SetIntDelegate^ d = gcnew SetIntDelegate(this, &BlinkAnalysis::MainForm::dikablisSetEyeRoiHoriz);
					this->Invoke(d, value);
				} else {
					// Update Value
					this->dikablisEyeRoiHorizOutputLabel->Text = Convert::ToString(value);
				}
			}
	public: System::Void dikablisSetEyeRoiVert(int value) {
				if (this->dikablisEyeRoiVertOutputLabel->InvokeRequired)
				{
					SetIntDelegate^ d = gcnew SetIntDelegate(this, &BlinkAnalysis::MainForm::dikablisSetEyeRoiVert);
					this->Invoke(d, value);
				} else {
					// Update Value
					this->dikablisEyeRoiVertOutputLabel->Text = Convert::ToString(value);
				}
			}
	public: System::Void dikablisSetEyeRoiZoomX(int value) {
				if (this->dikablisEyeRoiZoomXOutputLabel->InvokeRequired)
				{
					SetIntDelegate^ d = gcnew SetIntDelegate(this, &BlinkAnalysis::MainForm::dikablisSetEyeRoiZoomX);
					this->Invoke(d, value);
				} else {
					// Update Value
					this->dikablisEyeRoiZoomXOutputLabel->Text = Convert::ToString(value);
				}
			}
	public: System::Void dikablisSetEyeRoiZoomY(int value) {
				if (this->dikablisEyeRoiZoomYOutputLabel->InvokeRequired)
				{
					SetIntDelegate^ d = gcnew SetIntDelegate(this, &BlinkAnalysis::MainForm::dikablisSetEyeRoiZoomY);
					this->Invoke(d, value);
				} else {
					// Update Value
					this->dikablisEyeRoiZoomYOutputLabel->Text = Convert::ToString(value);
				}
			}
	public: System::Void dikablisSetEyeX(int value) {
				if (this->dikablisEyeXOutputLabel->InvokeRequired)
				{
					SetIntDelegate^ d = gcnew SetIntDelegate(this, &BlinkAnalysis::MainForm::dikablisSetEyeX);
					this->Invoke(d, value);
				} else {
					// Update Value
					this->dikablisEyeXOutputLabel->Text = Convert::ToString(value);
				}
			}
	public: System::Void dikablisSetEyeY(int value) {
				if (this->dikablisEyeYOutputLabel->InvokeRequired)
				{
					SetIntDelegate^ d = gcnew SetIntDelegate(this, &BlinkAnalysis::MainForm::dikablisSetEyeY);
					this->Invoke(d, value);
				} else {
					// Update Value
					this->dikablisEyeYOutputLabel->Text = Convert::ToString(value);
				}
			}
	public: System::Void dikablisSetFieldX(int value) {
				if (this->dikablisFieldXOutputLabel->InvokeRequired)
				{
					SetIntDelegate^ d = gcnew SetIntDelegate(this, &BlinkAnalysis::MainForm::dikablisSetFieldX);
					this->Invoke(d, value);
				} else {
					// Update Value
					this->dikablisFieldXOutputLabel->Text = Convert::ToString(value);
				}
			}
	public: System::Void dikablisSetFieldY(int value) {
				if (this->dikablisFieldYOutputLabel->InvokeRequired)
				{
					SetIntDelegate^ d = gcnew SetIntDelegate(this, &BlinkAnalysis::MainForm::dikablisSetFieldY);
					this->Invoke(d, value);
				} else {
					// Update Value
					this->dikablisFieldYOutputLabel->Text = Convert::ToString(value);
				}
			}
	public: System::Void dikablisSetEyeValid(String^ value) {
				if (this->dikablisEyeValidLabel->InvokeRequired)
				{
					SetTextDelegate^ d = gcnew SetTextDelegate(this, &BlinkAnalysis::MainForm::dikablisSetEyeValid);
					this->Invoke(d, gcnew array<Object^> { value });
				} else {
					// Update Value
					this->dikablisEyeValidLabel->Text = Convert::ToString(value);
				}
			}
	public: System::Void dikablisSetOnlineCalibration(String^ value) {
				if (this->dikablisOnlinecalibLabel->InvokeRequired)
				{
					SetTextDelegate^ d = gcnew SetTextDelegate(this, &BlinkAnalysis::MainForm::dikablisSetOnlineCalibration);
					this->Invoke(d, gcnew array<Object^> { value });
				} else {
					// Update Value
					this->dikablisOnlinecalibLabel->Text = Convert::ToString(value);
				}
			}
	//////////////////////
	// OptiTrack
	//////////////////////
			// Appends new messages to the OptiTracks Tab Output Log
	public: System::Void optiTrackOutputLog(String^ msg) {
				if (optiTrackOutputLogTextBox->InvokeRequired)
				{
					SetTextDelegate^ d = gcnew SetTextDelegate(this, &BlinkAnalysis::MainForm::optiTrackOutputLog);
					this->Invoke(d, gcnew array<Object^> { msg });
				} else {
					// Determine if the text being appended to dikablisOutputLogTextBox exceeds the MaxLength property.
					if((unsigned int)(optiTrackOutputLogTextBox->TextLength + msg->Length) > (unsigned int)optiTrackOutputLogTextBox->MaxLength)
					{
						int over = (optiTrackOutputLogTextBox->TextLength + msg->Length) - optiTrackOutputLogTextBox->MaxLength;
						optiTrackOutputLogTextBox->Text = optiTrackOutputLogTextBox->Text->Substring(over);
					}
					// Append the text
					optiTrackOutputLogTextBox->AppendText(msg->Replace("\n", Environment::NewLine));
				}
			 }
	public: System::Void optiTrackInitDataView() {
				this->optiTrackRigidBodyVector = new std::vector<RigidBody*>();
				this->optiTrackLabeledMarkerVector = new std::vector<Marker*>();

				ClientHandler* client = AppData::getInstance()->getClient();
				if (client) {

					std::map<int, RigidBody*>* bodyMap = client->getRigidBodyMap();

					this->optiTrackDataGridView->RowCount = (unsigned int)bodyMap->size();
					
					this->visualRigidBodyListView->Items->Clear();
					
					for (std::map<int, RigidBody*>::iterator it=bodyMap->begin(); it!=bodyMap->end(); ++it)
					{
						this->optiTrackRigidBodyVector->push_back(it->second);

						// Add Rigid Body to list
						String^ rigidBodyID = Convert::ToString(it->second->getID());
						String^ rigidBodyName = gcnew String(it->second->getName());
						ListViewItem^ listViewItem = gcnew ListViewItem(rigidBodyID); 
						listViewItem->SubItems->Add(rigidBodyName);
						this->visualRigidBodyListView->Items->Add(listViewItem);
					}
					
					// labeled markers
					std::map<int, Marker*>* markerMap = client->getLabeledMarkerMap();

					for (std::map<int, Marker*>::iterator it=markerMap->begin(); it!=markerMap->end(); ++it)
					{
						this->optiTrackLabeledMarkerVector->push_back(it->second);
					}
				}
			}
	public: System::Void optiTrackUpdateData() {
				static bool isUpdating = false;
				
				if (isUpdating)
					return;

				isUpdating = true;

				static float fps = (1000.f/10.f);
				static float dwCurrentTime = 0.f;
				static float dwElapsedTime = 0.f;
				static float dwLastUpdateTime = 0.f;

				// Get Current Time
				SYSTEMTIME time;
				GetSystemTime(&time);
				dwCurrentTime = (float)(time.wHour*60.f*60.f*1000.f + time.wMinute*60.f*1000.f + time.wSecond*1000.f + time.wMilliseconds);
				// Calculate time Elapsed time
				dwElapsedTime = dwCurrentTime - dwLastUpdateTime;
				
				// If the elapsed time is less then the fps
				if (dwElapsedTime > fps)
				{
					// Start update
					// Check if the main tab control needs invoke.
					// If not then check to see if the OptiTrack tab
					// is selected.
					if (this->mainTabControl->InvokeRequired) {
						SetDelegate^ d = gcnew SetDelegate(this, &BlinkAnalysis::MainForm::optiTrackUpdateData);
						BeginInvoke(d, nullptr);
					} else if (this->mainTabControl->SelectedIndex == 0) {
						// Check if the OptiTrack DataGridView needs invoke.
						// If not then update the view.
						if (this->optiTrackDataGridView->InvokeRequired) {
							SetDelegate^ d = gcnew SetDelegate(this, &BlinkAnalysis::MainForm::optiTrackUpdateData);
							BeginInvoke(d, nullptr);
						} else {
							// Get client form the AppData
							ClientHandler* client = AppData::getInstance()->getClient();

							// Check if the client is created and not NULL
							if (client)
							{
								// Lock the client
								if (!client->lock())
									return;

								// Try to update the view
								try {
									this->optiTrackDataGridView->SuspendLayout();
									this->optiTrackDataGridView->Invalidate();
									this->optiTrackDataGridView->ResumeLayout();

									// Set LastUpdateTime to CurrentTime
									dwLastUpdateTime = dwCurrentTime;
								}
								catch(Exception^) {
									Debug::WriteLine("Error: Exception when trying to redraw the OptiTrack DataGridView.");
								}

								// Unlock client
								client->unlock();
							}

						}
					} else if (this->mainTabControl->SelectedIndex == 2) { // Visual tab
						// Check if the ListView needs invoke.
						// If not then update the view.
						// Get client form the AppData
						ClientHandler* client = AppData::getInstance()->getClient();

						// Check if the client is created and not NULL
						if (client)
						{
							// Lock the client
							if (!client->lock())
								return;

							// update the vector list
							std::map<int, Marker*>* markerMap = client->getLabeledMarkerMap();
							this->optiTrackLabeledMarkerVector->clear();
							for (std::map<int, Marker*>::iterator it=markerMap->begin(); it!=markerMap->end(); ++it)
							{
								this->optiTrackLabeledMarkerVector->push_back(it->second);
							}

							// update the objects panel (if object attached to rigid body)
							if (this->objectGridView->Rows->Count > 0 &&
								String::Compare((String^) 
								this->objectGridView->Rows[(int) objectProperty::RIGID]->Cells[1]->Value,
								"none"))
								objectGridView_updateObjectRigid();

							// Unlock client
							client->unlock();
						}
					}
				} // End of update

				isUpdating = false;
			}
	public: System::Void optiTrackDataGridView_CellValueNeeded(Object^ /*sender*/,
       System::Windows::Forms::DataGridViewCellValueEventArgs^ e )
			{
				if (optiTrackRigidBodyVector)
				{
					if ((int)e->RowIndex >= (int)optiTrackRigidBodyVector->size())
						return;

					RigidBody* body = optiTrackRigidBodyVector->at(e->RowIndex);

					int id = body->getID();
					String^ name = gcnew String(body->getName());
					osg::Vec3 pos = body->getPosition();
					osg::Quat rot = body->getRotation();

					switch(e->ColumnIndex)
					{
					case 0:
						e->Value = Convert::ToString(id);
						break;
					case 1 :
						e->Value = name;
						break;
					case 2:
						e->Value = Convert::ToString(pos.x());
						break;
					case 3:
						e->Value = Convert::ToString(pos.y());
						break;
					case 4:
						e->Value = Convert::ToString(pos.z());
						break;
					case 5:
						e->Value = Convert::ToString(rot.x());
						break;
					case 6:
						e->Value = Convert::ToString(rot.y());
						break;
					case 7:
						e->Value = Convert::ToString(rot.z());
						break;
					case 8:
						e->Value = Convert::ToString(rot.w());
						break;
					}
				}
			}
	private: System::Void markersListView_RetrieveVitualItem(System::Object^ sender, 
								System::Windows::Forms::RetrieveVirtualItemEventArgs^ e) {
				 if (optiTrackLabeledMarkerVector)
				{
					if ((int)e->ItemIndex >= (int)optiTrackLabeledMarkerVector->size())
						return;

					Marker* marker = optiTrackLabeledMarkerVector->at(e->ItemIndex);

					String^ markerID = Convert::ToString(marker->getID());

					osg::Vec3 pos = marker->getPosition();
					String^ markerX = Convert::ToString(pos.x());
					String^ markerY = Convert::ToString(pos.y());
					String^ markerZ = Convert::ToString(pos.z());

					ListViewItem^ listViewItem = gcnew ListViewItem(markerID); 
					listViewItem->SubItems->Add(markerX);
					listViewItem->SubItems->Add(markerY);
					listViewItem->SubItems->Add(markerZ);

					e->Item = listViewItem;
				}
			 }
	private: System::Void optiTrackLocalIpAddressTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 AppData::getInstance()->needSave();
				 this->updateTitle();
			 }
	private: System::Void optiTrackSeverIpAddressTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 AppData::getInstance()->needSave();
				 this->updateTitle();
			 }
	private: System::Void optiTrackCmdPortTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 AppData::getInstance()->needSave();
				 this->updateTitle();
			 }
	private: System::Void optiTrackDataPortTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 AppData::getInstance()->needSave();
				 this->updateTitle();
			 }
	private: System::Void optiTrackConnectionTypeComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 AppData::getInstance()->needSave();
				 this->updateTitle();
			 }

	//////////////////////
	// OptiTrack Buttons
	/////////////////////
private: System::Void optiTrackConnectBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 ClientHandler* client = AppData::getInstance()->getClient();
			 
			 this->getOptiTrackInfo();
			 NatNetClientSetup::createClient(&client);
		 }
private: System::Void optiTrackDisConnect_Click(System::Object^  sender, System::EventArgs^  e) {
			 ClientHandler* client = AppData::getInstance()->getClient();

			 if (client)
				 NatNetClientSetup::deleteClient(&client);
		 }
	//////////////////////
	// Dikablis Buttons
	/////////////////////
	private: System::Void dikablisConnectBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				msclr::interop::marshal_context context;
				std::string ip_address =  context.marshal_as<std::string>(this->dikablisIPTextBox->Text);
				std::string port =  context.marshal_as<std::string>(this->dikablisPortTextBox->Text);
				
				Dikablis::connectToDikablis(ip_address, port);
			}
	private: System::Void dikablisDisConnectBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				Dikablis::stopServer();
			}
	private: System::Void dikablisHelpBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				DikablisHelp^ helpForm = gcnew DikablisHelp();
				helpForm->Show();
			}
	private: System::Void dikablisCalibrationBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				EyeCalibrationWizardFormController::getInstance()->Show();
		 }
	//////////////////////
	// Split Container Updates
	/////////////////////
	private: System::Void updateCurrentSplitContainer(System::Object^  sender, System::EventArgs^  e) {

			 switch(this->mainTabControl->SelectedIndex) {
			 case 0: 
				 AppViewer::setVisible(false);

				 this->optiTrackMainSplitContainer->SplitterDistance = this->currentMainSplitContainer->SplitterDistance;
				 this->optiTrackSplitContainer->SplitterDistance = this->currentSplitContainer->SplitterDistance;

				 this->optiTrackMainSplitContainer->SuspendLayout();
				 this->optiTrackMainSplitContainer->Refresh();
				 this->optiTrackMainSplitContainer->ResumeLayout();

				 this->currentMainSplitContainer = this->optiTrackMainSplitContainer;
				 this->currentSplitContainer = this->optiTrackSplitContainer;
				 break;
			 case 1:
				 AppViewer::setVisible(false);

				 this->dikablisMainSplitContainer->SplitterDistance = this->currentMainSplitContainer->SplitterDistance;
				 this->dikablisSplitContainer->SplitterDistance = this->currentSplitContainer->SplitterDistance;

				 this->dikablisMainSplitContainer->SuspendLayout();
				 this->dikablisMainSplitContainer->Refresh();
				 this->dikablisMainSplitContainer->ResumeLayout();

				 this->currentMainSplitContainer = this->dikablisMainSplitContainer;
				 this->currentSplitContainer = this->dikablisSplitContainer;
				 break;
			 case 2:
				 AppViewer::setVisible(true);

				 this->visualMainSplitContainer->SplitterDistance = this->currentMainSplitContainer->SplitterDistance;
				 this->visualSplitContainer->SplitterDistance = this->currentSplitContainer->SplitterDistance;

				 this->visualMainSplitContainer->SuspendLayout();
				 this->visualMainSplitContainer->Refresh();
				 this->visualMainSplitContainer->ResumeLayout();

				 this->currentMainSplitContainer = this->visualMainSplitContainer;
				 this->currentSplitContainer = this->visualSplitContainer;
				 break;
			 }
		 }
	private: System::Void splitterMoved(System::Object^ sender, System::Windows::Forms::SplitterEventArgs^  e) {
            this->mainTabControl->Refresh();
	}
	//////////////////////
	// Menu Items
	/////////////////////
private: System::Void eyeCalibrationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 EyeCalibrationWizardFormController::getInstance()->Show();
		 }
private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->newProject();
		 }
private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->openProject();
		 }
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->saveProject();
		 }
private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->saveAsProject();
		 }
private: System::Void addObjectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 AddObjectWizardFormController ^control = AddObjectWizardFormController::getInstance();
			 control->createForm();
			 control->setRigidBodyVector(optiTrackRigidBodyVector);
			 control->Show();
		 }
/*private: System::Void markersListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			int toggled = -1;

			for (std::vector<Marker*>::iterator itr = optiTrackLabeledMarkerVector->begin();
				itr != optiTrackLabeledMarkerVector->end(); itr++)
			{
				(*itr)->deselect();
			}

			IEnumerator^ num = this->visualMarkersListView->SelectedIndices->GetEnumerator();
			while (num->MoveNext())
			{
				optiTrackLabeledMarkerVector->at(safe_cast<int>(num->Current))->select();
			}
}*/
private: System::Void visualRigidBodyListView_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button == System::Windows::Forms::MouseButtons::Right)
			 {
				 ListViewItem^ item = this->visualRigidBodyListView->GetItemAt(e->X, e->Y);
				 if (item)
				 {
					this->rigidBodyToolContextMenu->Show(Cursor->Position);
					setRigidBodyTool = Int32::Parse(item->Text);
				 }
			 }
		 }
private: System::Void setAsRigidBodyToolToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ClientHandler* client = AppData::getInstance()->getClient();
			 if (client)
				 client->setRigidBodyTool(setRigidBodyTool);

			 setRigidBodyTool = -1;
			 this->rigidBodyToolContextMenu->Close();
		 }
private: System::Void attachToExistingObjectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 SetRigidBodyObjectForm^ rbForm = gcnew SetRigidBodyObjectForm();
			 rbForm->setRigidBody(setRigidBodyTool);
			 setRigidBodyTool = -1;
			 this->rigidBodyToolContextMenu->Close();
			 rbForm->Show();
		 }

	//////////////////////
	// Capture World and Objects
	/////////////////////

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
		 // converts a managed String^ to unmanaged std::string*
private: std::string* managedToStdString(String^ str) {
			 return new std::string( 
				 (const char*) (Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str)).ToPointer());
		 }

/////////////////////
// World Functions

		 // update list of worlds in both World and Object tab
public: System::Void worldUpdateList() {
			static bool isUpdatingWorlds = false;
				
			if (isUpdatingWorlds)
				return;

			isUpdatingWorlds = true;

			if (this->worldComboBox->InvokeRequired) 
			{
				SetDelegate^ d = gcnew SetDelegate(this, &BlinkAnalysis::MainForm::worldUpdateList);
				BeginInvoke(d, nullptr);
			} 
			else 
			{
				this->worldComboBox->Items->Clear();
				this->objectWComboBox->Items->Clear();
				this->objectComboBox->Items->Clear();
				resetWorldGridView();
				resetObjectGridView();

				std::map<int, CaptureWorld*> worlds = WorldManager::getInstance()->getWorlds();
				int idx = 0;
				for (worlds_iterator itr = worlds.begin(); itr != worlds.end(); itr++)
				{
					String^ worldName = gcnew String(itr->second->getName().c_str());
					worldName += " (";
					worldName += itr->first.ToString();
					worldName += ")";
					this->worldComboBox->Items->Add(worldName);
					this->objectWComboBox->Items->Add(worldName);
				}
			}

			isUpdatingWorlds = false;
		}
public: System::Void worldUpdateGridView(int id) {
			if (id == displayWorld)
				worldGridView_displayWorld();
		}
		// populates the world GridView based on selected value from world ComboBox
private: System::Void worldGridView_displayWorld() {
			 if (this->worldGridView->InvokeRequired)
			 {
				 SetDelegate^ d = gcnew SetDelegate(this, &BlinkAnalysis::MainForm::worldGridView_displayWorld);
				 BeginInvoke(d, nullptr);
			 }
			 else
			 {
				 this->worldGridView->Rows->Clear();
				 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayWorld);
				 if (!world) return;
				 
				 array<String^>^ row;

				 // populate values
				 // NOTE: this has to match the order in the enum worldProperty
				 row = gcnew array<String^> { "ID", world->getID().ToString() };
				 this->worldGridView->Rows->Add(row);

				 row = gcnew array<String^> { "Name", gcnew String(world->getName().c_str()) };
				 this->worldGridView->Rows->Add(row);

				 row = gcnew array<String^> { "Objects", world->getNumberObjects().ToString() };
				 this->worldGridView->Rows->Add(row);

				 String^ iden = (world->getGlobalToLocalMatrix().isIdentity()) ? "false" : "true";
				 row = gcnew array<String^> { "Transformation", iden };
				 this->worldGridView->Rows->Add(row);

				 String^ ren = world->renderWorld() ? "true" : "false";
				 row = gcnew array<String^> { "Render", ren };
				 this->worldGridView->Rows->Add(row);

				 // set certain rows to read only
				 int numRows = this->worldGridView->Rows->Count;
				 for (int i = 0; i < numRows; i++)
				 {
					 this->worldGridView->Rows[i]->ReadOnly = true;
				 }

				 // if not default world, allow name edit
				 if (world->getID() != 0)
					 this->worldGridView->Rows[(int)worldProperty::NAME]->ReadOnly = false;
			 }
		 }
		 // update world display if drop down list value changes
private: System::Void worldComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (!this->worldComboBox->SelectedItem)
			 {
				 resetWorldGridView();
				 return;
			 }

			 String^ text = this->worldComboBox->SelectedItem->ToString();
			 int id = worldExtractID(text);
			 if (id >= 0)
			 {
				 if (id > 0)	this->worldRemoveButton->Enabled = true;
				 else			this->worldRemoveButton->Enabled = false;
				 displayWorld = id;
				 worldGridView_displayWorld();
			 }
		 }
		 // add a new world (name only)
private: System::Void worldAddButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 AddWorldForm^ addWorldForm = gcnew AddWorldForm();
			 addWorldForm->Show();
		 }
		 
private: System::Void worldGridView_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 if (e->ColumnIndex != 1) // must be value column
				 return;

			 if (e->RowIndex == (int)worldProperty::MATRIX &&	// setting coordinate frame
				 displayWorld != 0)								// but not if default world
			 {
				 DefineCoordinateFrameFormController ^control = DefineCoordinateFrameFormController::getInstance();
				 control->createForm();
				 control->setDisplayWorld(displayWorld);
				 control->Show();
			 }
			 else if (e->RowIndex == (int)worldProperty::RENDER)
			 {
				 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayWorld);
				 if (world)
				 {
					 String^ ren = world->toggleRender() ? "true" : "false";
					 this->worldGridView->Rows[e->RowIndex]->Cells[1]->Value = ren;
				 }
			 }
		 }
		 // user edits property value for world
private: System::Void worldGridView_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 if (e->RowIndex == (int) worldProperty::NAME)
			 {
				CaptureWorld* world = WorldManager::getInstance()->getWorld(displayWorld);
				if (world)
				{
					std::string* str = managedToStdString(
						(String^)this->worldGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);
					world->setName(*str);
					int idx = this->worldComboBox->SelectedIndex;
					worldUpdateList();
					this->worldComboBox->SelectedIndex = idx;
				}
			 }
		 }
private: System::Void resetWorldGridView() {
			if (this->worldGridView->InvokeRequired) 
			{
				SetDelegate^ d = gcnew SetDelegate(this, &BlinkAnalysis::MainForm::resetWorldGridView);
				BeginInvoke(d, nullptr);
			} 
			else 
			{
				this->worldGridView->Rows->Clear();
				displayWorld = -1;
				displayObjectWorld = -1;
				this->objectAddButton->Enabled = false;
				this->worldRemoveButton->Enabled = false;
			}
		 }
private: System::Void worldRemoveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ message = "Are you sure you want to remove " + this->worldComboBox->SelectedItem->ToString() + "?";
			String^ str = (String^) this->worldGridView->Rows[(int)worldProperty::OBJECTS]->Cells[1]->Value;
			int numObjects = Int32::Parse(str);
			if (numObjects > 0)
			{
				message += "\nThis will also remove " + numObjects.ToString() + " associated object";
				if (numObjects > 1)
					message += "s";
			}

			System::Windows::Forms::DialogResult result = MessageBox::Show(
				message, "Remove World", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
			if(result == System::Windows::Forms::DialogResult::OK){
				WorldManager::getInstance()->removeWorld(displayWorld);
				displayWorld = -1;
				worldUpdateList();
			}
		}

/////////////////////
// Object Functions
		 
		 // populate list of objects based on displayObjectWorld
public: System::Void objectUpdateList() {
			if (this->objectComboBox->InvokeRequired) 
			{
				SetDelegate^ d = gcnew SetDelegate(this, &BlinkAnalysis::MainForm::objectUpdateList);
				BeginInvoke(d, nullptr);
			} 
			else 
			{
				 this->objectComboBox->Items->Clear();
				 resetObjectGridView();

				 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayObjectWorld);
				 int idx = 0;
				 if (world)
				 {
					 std::map<int, CaptureObject*> objects = world->getObjects();
					 for (objects_iterator itr = objects.begin(); itr != objects.end(); itr++)
					 {
						String^ objectName = gcnew String(itr->second->getName().c_str());
						objectName += " (";
						objectName += itr->first.ToString();
						objectName += ")";
						this->objectComboBox->Items->Add(objectName);
					 }
				 }
			}
		 }
		 // update list of objects if drop down list value changes
private: System::Void objectWComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (!this->objectWComboBox->SelectedItem)
				 return;
			 
			 String^ text = this->objectWComboBox->SelectedItem->ToString();
			 int id = worldExtractID(text);
			 if (id >= 0)
			 {
				 this->objectAddButton->Enabled = true;
				 displayObjectWorld = id;
				 objectUpdateList();
			 }
		 }
		 // update object display if drop down list value changes
private: System::Void objectComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (!this->objectComboBox->SelectedItem)
			 {
				 resetObjectGridView();
				 return;
			 }

			 String^ text = this->objectComboBox->SelectedItem->ToString();
			 int id = worldExtractID(text);
			 if (id >= 0)
			 {
				 this->removeObjectButton->Enabled = true;
				 displayObject = id;
				 objectGridView_displayObject();
			 }
		 }
public: System::Void objectUpdateGridView(int id) {
			if (id == displayObject)
				objectGridView_displayObject();
		}
		// populates the object GridView based on selected value from world and object ComboBoxes
private: System::Void objectGridView_displayObject() {
			 if (this->objectGridView->InvokeRequired)
			 {
				 SetDelegate^ d = gcnew SetDelegate(this, &BlinkAnalysis::MainForm::objectGridView_displayObject);
				 BeginInvoke(d, nullptr);
			 }
			 else
			 {
				 this->objectGridView->Rows->Clear();
				 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayObjectWorld);
				 if (!world) return;
				 CaptureObject* object = world->getObject(displayObject);
				 if (!object) return;

				 array<String^>^ row;

				 // populate values
				 // NOTE: this has to match the order in the enum objectProperty
				 row = gcnew array<String^> { "ID", object->getID().ToString() };
				 this->objectGridView->Rows->Add(row);

				 row = gcnew array<String^> { "Name", gcnew String(object->getName().c_str()) };
				 this->objectGridView->Rows->Add(row);

				 ObjectType ot = object->getType();
				 String^ otype = (ot == OBJ_PLANE ? "Plane" :
								 ot == OBJ_BOX ? "Box" : 
								 ot == OBJ_CYLINDER ? "Cylinder" :
								 ot == OBJ_CUSTOM ? "Custom" :
								 "Invalid");
				 row = gcnew array<String^> { "Type", otype };
				 this->objectGridView->Rows->Add(row);

				 String^ iden = (object->getRigidBody() < 0) ? "none" : object->getRigidBody().ToString();
				 row = gcnew array<String^> { "Rigid Body ID", iden };
				 this->objectGridView->Rows->Add(row);

				 row = gcnew array<String^> { "Faces", object->getNumFaces().ToString() };
				 this->objectGridView->Rows->Add(row);

				 row = gcnew array<String^> { "Vertices", object->getNumVertices().ToString() };
				 this->objectGridView->Rows->Add(row);

				 String^ ren = object->renderObject() ? "true" : "false";
				 row = gcnew array<String^> { "Render", ren };
				 this->objectGridView->Rows->Add(row);
				 
				 row = gcnew array<String^> { "Position", "" };
				 this->objectGridView->Rows->Add(row);

				 osg::Vec3 pos = object->getPosition();
				 row = gcnew array<String^> { "X", pos.x().ToString() };
				 this->objectGridView->Rows->Add(row);

				 row = gcnew array<String^> { "Y", pos.y().ToString() };
				 this->objectGridView->Rows->Add(row);

				 row = gcnew array<String^> { "Z", pos.z().ToString() };
				 this->objectGridView->Rows->Add(row);

				 row = gcnew array<String^> { "Orientation", "" };
				 this->objectGridView->Rows->Add(row);

				 osg::Vec3 eu = CaptureObjectUtil::quaternionToEuler(object->getRotation());
				 row = gcnew array<String^> { "Yaw", eu.x().ToString() };
				 this->objectGridView->Rows->Add(row);

				 row = gcnew array<String^> { "Pitch", eu.y().ToString() };
				 this->objectGridView->Rows->Add(row);

				 row = gcnew array<String^> { "Roll", eu.z().ToString() };
				 this->objectGridView->Rows->Add(row);

				 // set certain rows to read only
				 int numRows = this->objectGridView->Rows->Count;
				 for (int i = 0; i < numRows; i++)
				 {
					 this->objectGridView->Rows[i]->ReadOnly = true;
				 }

				 // allow name edit
				 this->objectGridView->Rows[(int)objectProperty::NAME]->ReadOnly = false;

				 // set certain rows to bold
				 DataGridViewCellStyle^ style = gcnew DataGridViewCellStyle();
				 style->Font = gcnew Drawing::Font(this->objectGridView->Font, FontStyle::Bold);

				 this->objectGridView->Rows[(int)objectProperty::POSITION]->DefaultCellStyle = style;
				 this->objectGridView->Rows[(int)objectProperty::ORIENT]->DefaultCellStyle = style;
			 }
		 }
		 // updates only the position and orientation data
private: System::Void objectGridView_updateObjectRigid() {
			 if (this->objectGridView->InvokeRequired)
			 {
				 SetDelegate^ d = gcnew SetDelegate(this, &BlinkAnalysis::MainForm::objectGridView_updateObjectRigid);
				 BeginInvoke(d, nullptr);
			 }
			 else
			 {
				 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayObjectWorld);
				 if (!world) return;
				 CaptureObject* object = world->getObject(displayObject);
				 if (!object) return;

				 osg::Vec3 pos = object->getPosition();
				 osg::Vec3 eu = CaptureObjectUtil::quaternionToEuler(object->getRotation());

				 this->objectGridView->Rows[(int)objectProperty::POSITION_X]->Cells[1]->Value = pos.x().ToString();
				 this->objectGridView->Rows[(int)objectProperty::POSITION_Y]->Cells[1]->Value = pos.y().ToString();
				 this->objectGridView->Rows[(int)objectProperty::POSITION_Z]->Cells[1]->Value = pos.z().ToString();
				 this->objectGridView->Rows[(int)objectProperty::ORIENT_YAW]->Cells[1]->Value = eu.x().ToString();
				 this->objectGridView->Rows[(int)objectProperty::ORIENT_PITCH]->Cells[1]->Value = eu.y().ToString();
				 this->objectGridView->Rows[(int)objectProperty::ORIENT_ROLL]->Cells[1]->Value = eu.z().ToString();
			 }
		 }
		 		 // user edits property value for object
private: System::Void objectGridView_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 if (e->RowIndex == (int) objectProperty::NAME)
			 {
				CaptureWorld* world = WorldManager::getInstance()->getWorld(displayObjectWorld);
				if (world)
				{
					CaptureObject* object = world->getObject(displayObject);
					if (object)
					{
						std::string* str = managedToStdString(
							(String^)this->objectGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);
						object->setName(*str);
						int idx = this->objectComboBox->SelectedIndex;
						objectUpdateList();
						this->objectComboBox->SelectedIndex = idx;
					}
				}
			 }
		 }
private: System::Void objectAddButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 AddObjectWizardFormController ^control = AddObjectWizardFormController::getInstance();
			 control->createForm();
			 control->setDisplayWorld(displayObjectWorld);
			 control->setRigidBodyVector(optiTrackRigidBodyVector);
			 control->Show();
		 }
private: System::Void resetObjectGridView() {
			if (this->objectGridView->InvokeRequired) 
			{
				SetDelegate^ d = gcnew SetDelegate(this, &BlinkAnalysis::MainForm::resetObjectGridView);
				BeginInvoke(d, nullptr);
			} 
			else 
			{
				this->objectGridView->Rows->Clear();
				displayObject = -1;
				this->removeObjectButton->Enabled = false;
			}
		 }
private: System::Void objectGridView_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 if (e->ColumnIndex != 1) // nust be Value column
				 return;
			 
			 // set Rigid Body number
			 if (e->RowIndex == (int)objectProperty::RIGID)
			 {
				SetObjectRigidBodyFormController ^control = SetObjectRigidBodyFormController::getInstance();
				control->createForm();
				control->setRigidBodyVector(this->optiTrackRigidBodyVector);
				control->setWorldAndObject(displayObjectWorld, displayObject);
				int rb = String::Compare((String^)this->objectGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value, "none");
				control->setHasRigidBody(rb != 0);
				control->Show();
			 }
			 // set Render on/off
			 else if (e->RowIndex == (int)objectProperty::RENDER)
			 {
				 CaptureWorld* world = WorldManager::getInstance()->getWorld(displayObjectWorld);
				 if (world)
				 {
					 String^ ren = world->toggleRenderObject(displayObject) ? "true" : "false";
					 this->objectGridView->Rows[e->RowIndex]->Cells[1]->Value = ren;
				 }
			 }
		 }
private: System::Void removeObjectButton_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ message = "Are you sure you want to remove " + this->objectComboBox->SelectedItem->ToString() + "?";

			System::Windows::Forms::DialogResult result = MessageBox::Show(
				message, "Remove Object", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
			if(result == System::Windows::Forms::DialogResult::OK){
				CaptureWorld* world = WorldManager::getInstance()->getWorld(displayObjectWorld);
				if (world)
				{
					world->removeObject(displayObject);
					displayObject = -1;
					objectUpdateList();
				}
			}
		 }
private: System::Void visualViewerScaleTextBox_KeyPress(System::Object^  sender, KeyPressEventArgs^  e) {
			 if (!System::Char::IsControl(e->KeyChar) 
				 && !System::Char::IsDigit(e->KeyChar) 
				 && e->KeyChar != '.')
			 {
				 e->Handled = true;
			 }

			 // only allow one decimal point
			 if (e->KeyChar == '.' 
				 && this->visualViewerScaleTextBox->Text->IndexOf('.') > -1)
			 {
				 e->Handled = true;
			 }
		 }

private: System::Void visualViewerScaleTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 float scale = Convert::ToSingle(this->visualViewerScaleTextBox->Text);
			 AppViewer::setScale(scale);
		 }
private: System::Void startRecordingBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 RecordingManager::getInstance()->startRecording();
		}
private: System::Void stopRecordingBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 RecordingManager::getInstance()->stopRecording();
		 }

};
}

