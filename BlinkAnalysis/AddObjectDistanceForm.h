#pragma once
#include <osg/Vec3>
#include "AppData.h"

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddObjectDistanceForm
	/// </summary>
	public ref class AddObjectDistanceForm : public System::Windows::Forms::Form
	{
	public:
		AddObjectDistanceForm(void)
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
		~AddObjectDistanceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  startZText;
	private: System::Windows::Forms::TextBox^  startYText;
	private: System::Windows::Forms::TextBox^  startXText;
	private: System::Windows::Forms::Label^  ZLabel;
	private: System::Windows::Forms::Label^  YLabel;
	private: System::Windows::Forms::Label^  XLabel;

	private: System::Windows::Forms::TextBox^  startMIDText;
	private: System::Windows::Forms::TextBox^  endMIDText;
	private: System::Windows::Forms::TextBox^  endZText;
	private: System::Windows::Forms::TextBox^  endYText;
	private: System::Windows::Forms::TextBox^  endXText;
	private: System::Windows::Forms::Label^  distanceLabel;

	private: System::Windows::Forms::Label^  infoLabel;
	private: System::Windows::Forms::ComboBox^  inputComboBox;
	private: System::Windows::Forms::Button^  useButton;

	private: System::Windows::Forms::Button^  startSetDatabutton;
	private: System::Windows::Forms::Button^  endSetDataButton;

	private: System::Windows::Forms::Label^  markerLabel;


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
			this->startZText = (gcnew System::Windows::Forms::TextBox());
			this->startYText = (gcnew System::Windows::Forms::TextBox());
			this->startXText = (gcnew System::Windows::Forms::TextBox());
			this->ZLabel = (gcnew System::Windows::Forms::Label());
			this->YLabel = (gcnew System::Windows::Forms::Label());
			this->XLabel = (gcnew System::Windows::Forms::Label());
			this->startMIDText = (gcnew System::Windows::Forms::TextBox());
			this->endMIDText = (gcnew System::Windows::Forms::TextBox());
			this->endZText = (gcnew System::Windows::Forms::TextBox());
			this->endYText = (gcnew System::Windows::Forms::TextBox());
			this->endXText = (gcnew System::Windows::Forms::TextBox());
			this->distanceLabel = (gcnew System::Windows::Forms::Label());
			this->infoLabel = (gcnew System::Windows::Forms::Label());
			this->inputComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->useButton = (gcnew System::Windows::Forms::Button());
			this->startSetDatabutton = (gcnew System::Windows::Forms::Button());
			this->endSetDataButton = (gcnew System::Windows::Forms::Button());
			this->markerLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// startZText
			// 
			this->startZText->Location = System::Drawing::Point(358, 96);
			this->startZText->Name = L"startZText";
			this->startZText->ReadOnly = true;
			this->startZText->Size = System::Drawing::Size(83, 20);
			this->startZText->TabIndex = 89;
			// 
			// startYText
			// 
			this->startYText->Location = System::Drawing::Point(269, 96);
			this->startYText->Name = L"startYText";
			this->startYText->ReadOnly = true;
			this->startYText->Size = System::Drawing::Size(83, 20);
			this->startYText->TabIndex = 88;
			// 
			// startXText
			// 
			this->startXText->Location = System::Drawing::Point(180, 96);
			this->startXText->Name = L"startXText";
			this->startXText->ReadOnly = true;
			this->startXText->Size = System::Drawing::Size(83, 20);
			this->startXText->TabIndex = 87;
			// 
			// ZLabel
			// 
			this->ZLabel->AutoSize = true;
			this->ZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ZLabel->Location = System::Drawing::Point(393, 78);
			this->ZLabel->Name = L"ZLabel";
			this->ZLabel->Size = System::Drawing::Size(15, 15);
			this->ZLabel->TabIndex = 92;
			this->ZLabel->Text = L"Z";
			// 
			// YLabel
			// 
			this->YLabel->AutoSize = true;
			this->YLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->YLabel->Location = System::Drawing::Point(301, 78);
			this->YLabel->Name = L"YLabel";
			this->YLabel->Size = System::Drawing::Size(15, 15);
			this->YLabel->TabIndex = 91;
			this->YLabel->Text = L"Y";
			// 
			// XLabel
			// 
			this->XLabel->AutoSize = true;
			this->XLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->XLabel->Location = System::Drawing::Point(213, 78);
			this->XLabel->Name = L"XLabel";
			this->XLabel->Size = System::Drawing::Size(16, 15);
			this->XLabel->TabIndex = 90;
			this->XLabel->Text = L"X";
			// 
			// startMIDText
			// 
			this->startMIDText->Location = System::Drawing::Point(21, 96);
			this->startMIDText->Name = L"startMIDText";
			this->startMIDText->Size = System::Drawing::Size(83, 20);
			this->startMIDText->TabIndex = 93;
			// 
			// endMIDText
			// 
			this->endMIDText->Location = System::Drawing::Point(21, 132);
			this->endMIDText->Name = L"endMIDText";
			this->endMIDText->Size = System::Drawing::Size(83, 20);
			this->endMIDText->TabIndex = 94;
			// 
			// endZText
			// 
			this->endZText->Location = System::Drawing::Point(358, 132);
			this->endZText->Name = L"endZText";
			this->endZText->ReadOnly = true;
			this->endZText->Size = System::Drawing::Size(83, 20);
			this->endZText->TabIndex = 97;
			// 
			// endYText
			// 
			this->endYText->Location = System::Drawing::Point(269, 132);
			this->endYText->Name = L"endYText";
			this->endYText->ReadOnly = true;
			this->endYText->Size = System::Drawing::Size(83, 20);
			this->endYText->TabIndex = 96;
			// 
			// endXText
			// 
			this->endXText->Location = System::Drawing::Point(180, 132);
			this->endXText->Name = L"endXText";
			this->endXText->ReadOnly = true;
			this->endXText->Size = System::Drawing::Size(83, 20);
			this->endXText->TabIndex = 95;
			// 
			// distanceLabel
			// 
			this->distanceLabel->AutoSize = true;
			this->distanceLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->distanceLabel->Location = System::Drawing::Point(107, 171);
			this->distanceLabel->Name = L"distanceLabel";
			this->distanceLabel->Size = System::Drawing::Size(90, 16);
			this->distanceLabel->TabIndex = 100;
			this->distanceLabel->Text = L"Distance: N/A";
			// 
			// infoLabel
			// 
			this->infoLabel->AutoSize = true;
			this->infoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->infoLabel->Location = System::Drawing::Point(12, 18);
			this->infoLabel->Name = L"infoLabel";
			this->infoLabel->Size = System::Drawing::Size(215, 15);
			this->infoLabel->TabIndex = 101;
			this->infoLabel->Text = L"Calculate distance between two points";
			// 
			// inputComboBox
			// 
			this->inputComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->inputComboBox->FormattingEnabled = true;
			this->inputComboBox->Location = System::Drawing::Point(39, 45);
			this->inputComboBox->Name = L"inputComboBox";
			this->inputComboBox->Size = System::Drawing::Size(121, 21);
			this->inputComboBox->TabIndex = 102;
			this->inputComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &AddObjectDistanceForm::inputComboBox_SelectedIndexChanged);
			// 
			// useButton
			// 
			this->useButton->Enabled = false;
			this->useButton->Location = System::Drawing::Point(356, 194);
			this->useButton->Name = L"useButton";
			this->useButton->Size = System::Drawing::Size(91, 23);
			this->useButton->TabIndex = 104;
			this->useButton->Text = L"Use Distance";
			this->useButton->UseVisualStyleBackColor = true;
			this->useButton->Click += gcnew System::EventHandler(this, &AddObjectDistanceForm::useButton_Click);
			// 
			// startSetDatabutton
			// 
			this->startSetDatabutton->Location = System::Drawing::Point(110, 94);
			this->startSetDatabutton->Name = L"startSetDatabutton";
			this->startSetDatabutton->Size = System::Drawing::Size(64, 23);
			this->startSetDatabutton->TabIndex = 105;
			this->startSetDatabutton->Text = L"Start Point";
			this->startSetDatabutton->UseVisualStyleBackColor = true;
			this->startSetDatabutton->Click += gcnew System::EventHandler(this, &AddObjectDistanceForm::startSetDatabutton_Click);
			// 
			// endSetDataButton
			// 
			this->endSetDataButton->Location = System::Drawing::Point(110, 130);
			this->endSetDataButton->Name = L"endSetDataButton";
			this->endSetDataButton->Size = System::Drawing::Size(64, 23);
			this->endSetDataButton->TabIndex = 106;
			this->endSetDataButton->Text = L"End Point";
			this->endSetDataButton->UseVisualStyleBackColor = true;
			this->endSetDataButton->Click += gcnew System::EventHandler(this, &AddObjectDistanceForm::endSetDataButton_Click);
			// 
			// markerLabel
			// 
			this->markerLabel->AutoSize = true;
			this->markerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->markerLabel->Location = System::Drawing::Point(18, 78);
			this->markerLabel->Name = L"markerLabel";
			this->markerLabel->Size = System::Drawing::Size(70, 15);
			this->markerLabel->TabIndex = 107;
			this->markerLabel->Text = L"Marker ID";
			// 
			// AddObjectDistanceForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(461, 250);
			this->Controls->Add(this->markerLabel);
			this->Controls->Add(this->endSetDataButton);
			this->Controls->Add(this->startSetDatabutton);
			this->Controls->Add(this->useButton);
			this->Controls->Add(this->inputComboBox);
			this->Controls->Add(this->infoLabel);
			this->Controls->Add(this->distanceLabel);
			this->Controls->Add(this->endMIDText);
			this->Controls->Add(this->endZText);
			this->Controls->Add(this->endYText);
			this->Controls->Add(this->endXText);
			this->Controls->Add(this->startMIDText);
			this->Controls->Add(this->startZText);
			this->Controls->Add(this->startYText);
			this->Controls->Add(this->startXText);
			this->Controls->Add(this->ZLabel);
			this->Controls->Add(this->YLabel);
			this->Controls->Add(this->XLabel);
			this->Name = L"AddObjectDistanceForm";
			this->Text = L"Calculate Distance";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AddObjectDistanceForm::AddObjectDistanceForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AddObjectDistanceForm::AddObjectDistanceForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: String^ defaultDistanceText;
public: double distance;
private: osg::Vec3* posStart;
private: osg::Vec3* posEnd;


private: System::Void AddObjectDistanceForm_Load(System::Object^  sender, System::EventArgs^  e) {
			this->defaultDistanceText = L"Distance: N/A";
			this->posStart = new osg::Vec3();
			this->posEnd = new osg::Vec3();
			this->distance = -1;

			String^ control;
		 	control = gcnew String("Rigid Body Tool");
			this->inputComboBox->Items->Add(control);

			control = gcnew String("Labeled Marker");
			this->inputComboBox->Items->Add(control);
			this->inputComboBox->SelectedIndex = 0;
		}
private: System::Void AddObjectDistanceForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 if (this->posStart) delete this->posStart;
			 if (this->posEnd) delete this->posEnd;
		 }

private: System::Void setDefaultDistanceText() {
			 this->distanceLabel->Text = defaultDistanceText;
		 }
		 // checks if input string is a valid float
private: bool isFloat(String^ str) {
			 String^ regs = "^\\s*-?\\d+(.\\d+)?\\s*$";
			 System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(regs);
			 return regex->IsMatch(str);
		 }

private: System::Void inputComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (!this->inputComboBox->SelectedItem)
			 {
				 this->useButton->Enabled = false;
				 return;
			 }

			 // rigid body tool
			 if (this->inputComboBox->SelectedIndex == 0)
			 {
				 this->markerLabel->Visible = false;
				 this->startMIDText->Visible = false;
				 this->endMIDText->Visible = false;
			 }
			 // labeled marker
			 else if (this->inputComboBox->SelectedIndex == 1)
			 {
				 this->markerLabel->Visible = true;
				 this->startMIDText->Visible = true;
				 this->endMIDText->Visible = true;
			 }
		 }

private: System::Void populateTextFromPosition(int posIdx) {
			 if (posIdx == 0) // start
			 {
				 if (posStart)
				 {
					 this->startXText->Text = posStart->x().ToString();
					 this->startYText->Text = posStart->y().ToString();
					 this->startZText->Text = posStart->z().ToString();
				 }
			 }
			 else if (posIdx == 1) // end
			 {
				 if (posEnd)
				 {
					 this->endXText->Text = posEnd->x().ToString();
					 this->endYText->Text = posEnd->y().ToString();
					 this->endZText->Text = posEnd->z().ToString();
				 }
			 }
		 }
private: System::Void clearPositionText(int posIdx)
		 {
			 if (posIdx == 0) // start
			 {
				this->startXText->Text = "";
				this->startYText->Text = "";
				this->startZText->Text = "";
			 }
			 else if (posIdx == 1) // end
			 {
				this->endXText->Text = "";
				this->endYText->Text = "";
				this->endZText->Text = "";
			 }
		 }
private: System::Void validate()
		 {
			 if ( isFloat(this->startXText->Text) &&
				  isFloat(this->startYText->Text) &&
				  isFloat(this->startZText->Text) &&
				  isFloat(this->endXText->Text) &&
				  isFloat(this->endYText->Text) &&
				  isFloat(this->endZText->Text) )
			 {
				 this->useButton->Enabled = true;
				 this->distance = (*posEnd - *posStart).length();
				 this->distanceLabel->Text = L"Distance: " + this->distance.ToString();
			 }
			 else
			 {
				 this->useButton->Enabled = false;
				 this->distance = -1;
				 setDefaultDistanceText();
			 }
		 }
private: System::Void startSetDatabutton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ClientHandler* client = AppData::getInstance()->getClient();
			 if (!client) return;

			 if (inputComboBox->SelectedIndex == 0) // rigid body tool
			 {
			 	RigidBody* body = client->getRigidBody(client->getRigidBodyTool());
				if (body)
				{
					this->posStart->set(body->getPosition().x(), 
							body->getPosition().y(), 
							body->getPosition().z());
					populateTextFromPosition(0);
				}
				else
					clearPositionText(0);
			 }
			 else if (inputComboBox->SelectedIndex == 1 && client->lock()) // labeled marker
			 {
				Marker* marker;
				bool result;
				int id;
				
				result = Int32::TryParse(this->startMIDText->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					clearPositionText(0);
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					this->posStart->set(pt.x(), pt.y(), pt.z());
					populateTextFromPosition(0);
				}
				client->unlock();
			 }
			 validate();
		 }
private: System::Void endSetDataButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ClientHandler* client = AppData::getInstance()->getClient();
			 if (!client) return;

			 if (inputComboBox->SelectedIndex == 0) // rigid body tool
			 {
			 	RigidBody* body = client->getRigidBody(client->getRigidBodyTool());
				if (body)
				{
					this->posEnd->set(body->getPosition().x(), 
							body->getPosition().y(), 
							body->getPosition().z());
					populateTextFromPosition(1);
				}
				else
					clearPositionText(1);
			 }
			 else if (inputComboBox->SelectedIndex == 1 && client->lock()) // labeled marker
			 {
				Marker* marker;
				bool result;
				int id;
				
				result = Int32::TryParse(this->endMIDText->Text, id);
				marker = client->getLabeledMarker(id);
				if (!result || !marker)
				{
					clearPositionText(1);
				}
				else
				{
					osg::Vec3 pt = marker->getPosition();
					this->posEnd->set(pt.x(), pt.y(), pt.z());
					populateTextFromPosition(1);
				}
				client->unlock();
			 }
			 validate();
		 }
private: System::Void useButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->DialogResult = System::Windows::Forms::DialogResult::OK;
			 this->Close();
		 }
};
}
