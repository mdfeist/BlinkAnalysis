#pragma once

#include "AppData.h"
#include "AppViewer.h"
#include <string>

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum class objectType {PLANE, BOX};

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
			this->tabControl1->SuspendLayout();
			this->planePage->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->infoPage);
			this->tabControl1->Controls->Add(this->planePage);
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
			this->planeRigidRadio->Location = System::Drawing::Point(198, 93);
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
			this->planeSetButton->Text = L"Set Points";
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
			this->ResumeLayout(false);

		}
#pragma endregion

// local variables
private: osg::Vec3* pos1;
private: osg::Vec3* posC;
private: osg::Vec3* pos2;
private: osg::Vec3* pos;

		 // get data from client
		 // markers: based on ID in each text field
		 // rigid body: based on chosen rigid body tool
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
					if (!pos1)
						pos1 = new osg::Vec3(pt.x(), pt.y(), pt.z());
					else
						pos1->set(pt.x(), pt.y(), pt.z());
						setPoint(pos1, this->planeDataPt1Label);
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
					if (!posC)
						posC = new osg::Vec3(pt.x(), pt.y(), pt.z());
					else
						posC->set(pt.x(), pt.y(), pt.z());
						setPoint(posC, this->planeDataCornerLabel);
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
					if (!pos2)
						pos2 = new osg::Vec3(pt.x(), pt.y(), pt.z());
					else
						pos2->set(pt.x(), pt.y(), pt.z());
						setPoint(pos2, this->planeDataPt2Label);
				}
					client->unlock();
			}
			// use rigid tool
			else if (this->planeRigidRadio->Checked && client)
			{
				RigidBody* body = client->getRigidBody(client->getRigidBodyTool());
				if (body)
				{
					if (!pos)
						pos = new osg::Vec3(); 

					pos->set(body->getPosition().x(), 
							body->getPosition().y(), 
							body->getPosition().z());
					setPoint(pos, this->planeRigidDataLabel);
					rigidSetButtons(true, true, objectType::PLANE);
					return;
				}
			}
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
		 // add plane to world based on data from posC, pos1, pos2
private: System::Void planeSetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 CaptureWorld* world = AppData::getInstance()->getWorld(displayWorld);
			 if (world)
			 {
				 std::string* str = new std::string( (const char*) (Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->planeNameTextBox->Text)).ToPointer());
				 CaptureObject* object = world->addPlane(*posC, *pos1, *pos2, *str);
				 if (object)
				 {
					 String^ id = Convert::ToString(object->getID());
					 String^ name = gcnew String(object->getName().c_str());
				 }
			 }
			 this->Close();
		 }
private: System::Void AddObjectForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		 	if (pos1) delete pos1;
			if (posC) delete posC;
			if (pos2) delete pos2;
			if (pos) delete pos;
		 }
		 // set enable/disable, visible/not visible for buttons associated with rigid body tool view
private: System::Void rigidSetButtons(bool enable, bool visible, objectType type) {
			 switch (type)
			 {
			 // plane
			 case objectType::PLANE :
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
private: System::Void markerTextBoxes(bool visible, objectType type) {
			 switch (type)
			 {
			 // plane
			 case objectType::PLANE :
				 this->planePt1TextBox->Visible = visible;
				 this->planeCornerTextBox->Visible = visible;
				 this->planePt2TextBox->Visible = visible;
				 break;


			 }
		 }
		 // change visibility of form objects based on which radio button is checked
private: System::Void planeRigidRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->planeRigidRadio->Checked)
			 {
				 rigidSetButtons(false, true, objectType::PLANE);

				 setDefaultText(this->planeRigidDataLabel);
				 setDefaultText(this->planeDataPt1Label);
				 setDefaultText(this->planeDataCornerLabel);
				 setDefaultText(this->planeDataPt2Label);				 

				 this->planeRigidDataLabel->Visible = true;
				 this->planeSetButton->Enabled = false;
			 }
			 else
			 {
				 rigidSetButtons(false, false, objectType::PLANE);

				 this->planeRigidDataLabel->Visible = false;
			 }
		 }
private: System::Void planeMarkersRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->planeMarkersRadio->Checked)
			 {
				 markerTextBoxes(true, objectType::PLANE);

				 setDefaultText(this->planeDataPt1Label);
				 setDefaultText(this->planeDataCornerLabel);
				 setDefaultText(this->planeDataPt2Label);				 

				 this->planeSetButton->Enabled = false;
			 }
			 else
			 {
				 markerTextBoxes(false, objectType::PLANE);
			 }
		 }
private: System::Void AddObjectForm_Load(System::Object^  sender, System::EventArgs^  e) {
			this->defaultDataText = L"No data found";
			pos1 = NULL;
			posC = NULL;
			pos2 = NULL;
			pos = NULL;
		 }
		 // gets data from rigid body tool and sets it to one of the three points
private: System::Void planeSetDataButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if (sender == this->planePt1SetButton)
			{
				if (!pos1)
					pos1 = new osg::Vec3();

				pos1->set(pos->x(), pos->y(), pos->z());
				setPoint(pos, this->planeDataPt1Label);
					 
				if ( String::Compare(this->planeDataCornerLabel->Text, this->defaultDataText) &&
					String::Compare(this->planeDataPt2Label->Text, this->defaultDataText) )
					this->planeSetButton->Enabled = true;
				else
					this->planeSetButton->Enabled = false;
			}
			else if (sender == this->planeCornerSetButton)
			{
				if (!posC)
					posC = new osg::Vec3();

				posC->set(pos->x(), pos->y(), pos->z());
				setPoint(pos, this->planeDataCornerLabel);

				if ( String::Compare(this->planeDataPt1Label->Text, this->defaultDataText) &&
					String::Compare(this->planeDataPt2Label->Text, this->defaultDataText) )
					this->planeSetButton->Enabled = true;
				else
					this->planeSetButton->Enabled = false;
			}
			else if (sender == this->planePt2SetButton)
			{
				if (!pos2)
					pos2 = new osg::Vec3();

				pos2->set(pos->x(), pos->y(), pos->z());
				setPoint(pos, this->planeDataPt2Label);

				if ( String::Compare(this->planeDataPt1Label->Text, this->defaultDataText) &&
					String::Compare(this->planeDataCornerLabel->Text, this->defaultDataText) )
					this->planeSetButton->Enabled = true;
				else
					this->planeSetButton->Enabled = false;
			}
		}
};

}
