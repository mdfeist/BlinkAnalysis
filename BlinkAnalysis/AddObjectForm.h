#pragma once

#include "AppData.h"
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
			//
			//TODO: Add the constructor code here
			//
		}

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
	private: System::Windows::Forms::Label^  pt2Label;
	private: System::Windows::Forms::Label^  cornerLabel;
	private: System::Windows::Forms::Label^  pt1Label;
	private: System::Windows::Forms::Button^  dataGetButton;
	private: System::Windows::Forms::Button^  planeSetButton;
	private: System::Windows::Forms::Label^  dataPt2Label;
	private: System::Windows::Forms::Label^  dataCornerLabel;
	private: System::Windows::Forms::Label^  dataPt1Label;
	private: System::Windows::Forms::TextBox^  cornerTextBox;
	private: System::Windows::Forms::TextBox^  pt2TextBox;
	private: System::Windows::Forms::TextBox^  pt1TextBox;
	private: System::Windows::Forms::TextBox^  nameTextBox;
	private: System::Windows::Forms::Label^  nameLabel;
			 
	private: System::String^ defaultDataText;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  planeInfoLabel;

	public: event EventHandler^ UpdateObject;

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
			this->planeInfoLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->pt2Label = (gcnew System::Windows::Forms::Label());
			this->cornerLabel = (gcnew System::Windows::Forms::Label());
			this->pt1Label = (gcnew System::Windows::Forms::Label());
			this->dataGetButton = (gcnew System::Windows::Forms::Button());
			this->planeSetButton = (gcnew System::Windows::Forms::Button());
			this->dataPt2Label = (gcnew System::Windows::Forms::Label());
			this->dataCornerLabel = (gcnew System::Windows::Forms::Label());
			this->dataPt1Label = (gcnew System::Windows::Forms::Label());
			this->cornerTextBox = (gcnew System::Windows::Forms::TextBox());
			this->pt2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->pt1TextBox = (gcnew System::Windows::Forms::TextBox());
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
			this->planePage->Controls->Add(this->planeInfoLabel);
			this->planePage->Controls->Add(this->label1);
			this->planePage->Controls->Add(this->nameTextBox);
			this->planePage->Controls->Add(this->nameLabel);
			this->planePage->Controls->Add(this->pt2Label);
			this->planePage->Controls->Add(this->cornerLabel);
			this->planePage->Controls->Add(this->pt1Label);
			this->planePage->Controls->Add(this->dataGetButton);
			this->planePage->Controls->Add(this->planeSetButton);
			this->planePage->Controls->Add(this->dataPt2Label);
			this->planePage->Controls->Add(this->dataCornerLabel);
			this->planePage->Controls->Add(this->dataPt1Label);
			this->planePage->Controls->Add(this->cornerTextBox);
			this->planePage->Controls->Add(this->pt2TextBox);
			this->planePage->Controls->Add(this->pt1TextBox);
			this->planePage->Location = System::Drawing::Point(4, 22);
			this->planePage->Name = L"planePage";
			this->planePage->Padding = System::Windows::Forms::Padding(3);
			this->planePage->Size = System::Drawing::Size(410, 287);
			this->planePage->TabIndex = 1;
			this->planePage->Text = L"Plane";
			this->planePage->UseVisualStyleBackColor = true;
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label1->Location = System::Drawing::Point(255, 94);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 24;
			this->label1->Text = L"optional";
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(70, 91);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(179, 20);
			this->nameTextBox->TabIndex = 23;
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->nameLabel->Location = System::Drawing::Point(18, 92);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(45, 15);
			this->nameLabel->TabIndex = 22;
			this->nameLabel->Text = L"Name";
			// 
			// pt2Label
			// 
			this->pt2Label->AutoSize = true;
			this->pt2Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->pt2Label->Location = System::Drawing::Point(18, 198);
			this->pt2Label->Name = L"pt2Label";
			this->pt2Label->Size = System::Drawing::Size(52, 15);
			this->pt2Label->TabIndex = 21;
			this->pt2Label->Text = L"Point 2";
			// 
			// cornerLabel
			// 
			this->cornerLabel->AutoSize = true;
			this->cornerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cornerLabel->Location = System::Drawing::Point(18, 172);
			this->cornerLabel->Name = L"cornerLabel";
			this->cornerLabel->Size = System::Drawing::Size(50, 15);
			this->cornerLabel->TabIndex = 20;
			this->cornerLabel->Text = L"Corner";
			// 
			// pt1Label
			// 
			this->pt1Label->AutoSize = true;
			this->pt1Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->pt1Label->Location = System::Drawing::Point(18, 146);
			this->pt1Label->Name = L"pt1Label";
			this->pt1Label->Size = System::Drawing::Size(52, 15);
			this->pt1Label->TabIndex = 19;
			this->pt1Label->Text = L"Point 1";
			// 
			// dataGetButton
			// 
			this->dataGetButton->Location = System::Drawing::Point(21, 253);
			this->dataGetButton->Name = L"dataGetButton";
			this->dataGetButton->Size = System::Drawing::Size(75, 23);
			this->dataGetButton->TabIndex = 18;
			this->dataGetButton->Text = L"Get Data";
			this->dataGetButton->UseVisualStyleBackColor = true;
			this->dataGetButton->Click += gcnew System::EventHandler(this, &AddObjectForm::dataGetButton_Click);
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
			// dataPt2Label
			// 
			this->dataPt2Label->AutoSize = true;
			this->dataPt2Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dataPt2Label->Location = System::Drawing::Point(165, 198);
			this->dataPt2Label->Name = L"dataPt2Label";
			this->dataPt2Label->Size = System::Drawing::Size(84, 15);
			this->dataPt2Label->TabIndex = 16;
			this->dataPt2Label->Text = L"No data found";
			// 
			// dataCornerLabel
			// 
			this->dataCornerLabel->AutoSize = true;
			this->dataCornerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dataCornerLabel->Location = System::Drawing::Point(165, 172);
			this->dataCornerLabel->Name = L"dataCornerLabel";
			this->dataCornerLabel->Size = System::Drawing::Size(84, 15);
			this->dataCornerLabel->TabIndex = 15;
			this->dataCornerLabel->Text = L"No data found";
			// 
			// dataPt1Label
			// 
			this->dataPt1Label->AutoSize = true;
			this->dataPt1Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dataPt1Label->Location = System::Drawing::Point(165, 146);
			this->dataPt1Label->Name = L"dataPt1Label";
			this->dataPt1Label->Size = System::Drawing::Size(84, 15);
			this->dataPt1Label->TabIndex = 14;
			this->dataPt1Label->Text = L"No data found";
			// 
			// cornerTextBox
			// 
			this->cornerTextBox->Location = System::Drawing::Point(70, 171);
			this->cornerTextBox->Name = L"cornerTextBox";
			this->cornerTextBox->Size = System::Drawing::Size(82, 20);
			this->cornerTextBox->TabIndex = 13;
			// 
			// pt2TextBox
			// 
			this->pt2TextBox->Location = System::Drawing::Point(70, 197);
			this->pt2TextBox->Name = L"pt2TextBox";
			this->pt2TextBox->Size = System::Drawing::Size(82, 20);
			this->pt2TextBox->TabIndex = 12;
			// 
			// pt1TextBox
			// 
			this->pt1TextBox->Location = System::Drawing::Point(70, 145);
			this->pt1TextBox->Name = L"pt1TextBox";
			this->pt1TextBox->Size = System::Drawing::Size(82, 20);
			this->pt1TextBox->TabIndex = 11;
			// 
			// AddObjectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 311);
			this->Controls->Add(this->tabControl1);
			this->Name = L"AddObjectForm";
			this->Text = L"AddObjectForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AddObjectForm::AddObjectForm_FormClosed);
			this->tabControl1->ResumeLayout(false);
			this->planePage->ResumeLayout(false);
			this->planePage->PerformLayout();
			this->ResumeLayout(false);
			this->defaultDataText = L"No data found";

		}
#pragma endregion

// local variables
private: osg::Vec3* pos1;
private: osg::Vec3* posC;
private: osg::Vec3* pos2;

private: System::Void dataGetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			ClientHandler* client = AppData::getInstance()->getClient();
			if (client->lock())
			{
				Marker* marker;
				bool result;
				int id;
				this->planeSetButton->Enabled = true;
				
				// point 1
				result = Int32::TryParse(pt1TextBox->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					plane_setDefaultText(dataPt1Label);
					this->planeSetButton->Enabled = false;
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					if (!pos1)
						pos1 = new osg::Vec3(pt.x(), pt.y(), pt.z());
					else
						pos1->set(pt.x(), pt.y(), pt.z());
						plane_setPoint(pos1, dataPt1Label);
				}
				
				// corner
				result = Int32::TryParse(cornerTextBox->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					plane_setDefaultText(dataCornerLabel);
					this->planeSetButton->Enabled = false;
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					if (!posC)
						posC = new osg::Vec3(pt.x(), pt.y(), pt.z());
					else
						posC->set(pt.x(), pt.y(), pt.z());
						plane_setPoint(posC, dataCornerLabel);
				}
				
				// point 2
				result = Int32::TryParse(pt2TextBox->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					plane_setDefaultText(dataPt2Label);
					this->planeSetButton->Enabled = false;
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					if (!pos2)
						pos2 = new osg::Vec3(pt.x(), pt.y(), pt.z());
					else
						pos2->set(pt.x(), pt.y(), pt.z());
						plane_setPoint(pos2, dataPt2Label);
				}
					client->unlock();
			}
		}
private: System::Void plane_setDefaultText(Label^ text) {
				text->Text = defaultDataText;
			}
private: System::Void plane_setPoint(osg::Vec3* pos, Label^ text) {
			String^ str = Convert::ToString(pos->x());
			str += ", ";
			str += Convert::ToString(pos->y());
			str += ", ";
			str += Convert::ToString(pos->z());
			text->Text = str;
		 }
private: System::Void planeSetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 CaptureWorld* world = AppData::getInstance()->getWorld();
			 if (world)
			 {
				 std::string* str = new std::string( (const char*) (Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->nameTextBox->Text)).ToPointer());
				 CaptureObject* object = world->addPlane(*posC, *pos1, *pos2, *str);
				 if (object)
				 {
					 String^ id = Convert::ToString(object->getID());
					 String^ name = gcnew String(object->getName().c_str());
					 UpdateObject(this, gcnew EventArgs());
				 }
			 }
			 this->Close();
		 }
private: System::Void AddObjectForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 	if (pos1) delete pos1;
				if (posC) delete posC;
				if (pos2) delete pos2;
		 }
};
}
