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
			//
			//TODO: Add the constructor code here
			//
		}

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
			this->CoordinateFramePages = (gcnew System::Windows::Forms::TabControl());
			this->infoPage = (gcnew System::Windows::Forms::TabPage());
			this->markerPage = (gcnew System::Windows::Forms::TabPage());
			this->coordinateGetButton = (gcnew System::Windows::Forms::Button());
			this->coordinateSetButton = (gcnew System::Windows::Forms::Button());
			this->coordinateYLabel = (gcnew System::Windows::Forms::Label());
			this->coordinateXLabel = (gcnew System::Windows::Forms::Label());
			this->coordinateOLabel = (gcnew System::Windows::Forms::Label());
			this->coordinateXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->coordinateYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->coordinateOTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rigidPage = (gcnew System::Windows::Forms::TabPage());
			this->coordinateResetButton = (gcnew System::Windows::Forms::Button());
			this->CoordinateFramePages->SuspendLayout();
			this->infoPage->SuspendLayout();
			this->markerPage->SuspendLayout();
			this->SuspendLayout();
			// 
			// CoordinateFramePages
			// 
			this->CoordinateFramePages->Controls->Add(this->infoPage);
			this->CoordinateFramePages->Controls->Add(this->markerPage);
			this->CoordinateFramePages->Controls->Add(this->rigidPage);
			this->CoordinateFramePages->Location = System::Drawing::Point(0, 0);
			this->CoordinateFramePages->Name = L"CoordinateFramePages";
			this->CoordinateFramePages->SelectedIndex = 0;
			this->CoordinateFramePages->Size = System::Drawing::Size(284, 263);
			this->CoordinateFramePages->TabIndex = 0;
			// 
			// infoPage
			// 
			this->infoPage->Controls->Add(this->coordinateResetButton);
			this->infoPage->Location = System::Drawing::Point(4, 22);
			this->infoPage->Name = L"infoPage";
			this->infoPage->Padding = System::Windows::Forms::Padding(3);
			this->infoPage->Size = System::Drawing::Size(276, 237);
			this->infoPage->TabIndex = 0;
			this->infoPage->Text = L"Info";
			this->infoPage->UseVisualStyleBackColor = true;
			// 
			// markerPage
			// 
			this->markerPage->BackColor = System::Drawing::Color::WhiteSmoke;
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
			this->markerPage->Size = System::Drawing::Size(276, 237);
			this->markerPage->TabIndex = 1;
			this->markerPage->Text = L"Markers";
			// 
			// coordinateGetButton
			// 
			this->coordinateGetButton->Location = System::Drawing::Point(20, 205);
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
			this->coordinateSetButton->Location = System::Drawing::Point(151, 205);
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
			this->coordinateYLabel->Location = System::Drawing::Point(121, 170);
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
			this->coordinateXLabel->Location = System::Drawing::Point(121, 134);
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
			this->coordinateOLabel->Location = System::Drawing::Point(121, 99);
			this->coordinateOLabel->Name = L"coordinateOLabel";
			this->coordinateOLabel->Size = System::Drawing::Size(84, 15);
			this->coordinateOLabel->TabIndex = 3;
			this->coordinateOLabel->Text = L"No data found";
			// 
			// coordinateXTextBox
			// 
			this->coordinateXTextBox->Location = System::Drawing::Point(20, 134);
			this->coordinateXTextBox->Name = L"coordinateXTextBox";
			this->coordinateXTextBox->Size = System::Drawing::Size(82, 20);
			this->coordinateXTextBox->TabIndex = 2;
			// 
			// coordinateYTextBox
			// 
			this->coordinateYTextBox->Location = System::Drawing::Point(20, 170);
			this->coordinateYTextBox->Name = L"coordinateYTextBox";
			this->coordinateYTextBox->Size = System::Drawing::Size(82, 20);
			this->coordinateYTextBox->TabIndex = 1;
			// 
			// coordinateOTextBox
			// 
			this->coordinateOTextBox->Location = System::Drawing::Point(20, 99);
			this->coordinateOTextBox->Name = L"coordinateOTextBox";
			this->coordinateOTextBox->Size = System::Drawing::Size(82, 20);
			this->coordinateOTextBox->TabIndex = 0;
			// 
			// rigidPage
			// 
			this->rigidPage->Location = System::Drawing::Point(4, 22);
			this->rigidPage->Name = L"rigidPage";
			this->rigidPage->Padding = System::Windows::Forms::Padding(3);
			this->rigidPage->Size = System::Drawing::Size(276, 237);
			this->rigidPage->TabIndex = 1;
			this->rigidPage->Text = L"Rigid Body";
			this->rigidPage->UseVisualStyleBackColor = true;
			// 
			// coordinateResetButton
			// 
			this->coordinateResetButton->Location = System::Drawing::Point(143, 205);
			this->coordinateResetButton->Name = L"coordinateResetButton";
			this->coordinateResetButton->Size = System::Drawing::Size(125, 23);
			this->coordinateResetButton->TabIndex = 0;
			this->coordinateResetButton->Text = L"Reset Coordinates";
			this->coordinateResetButton->UseVisualStyleBackColor = true;
			this->coordinateResetButton->Click += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::coordinateResetButton_Click);
			// 
			// DefineCoordinateFrameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->CoordinateFramePages);
			this->Name = L"DefineCoordinateFrameForm";
			this->Text = L"Define Coordinate Frame";
			this->Load += gcnew System::EventHandler(this, &DefineCoordinateFrameForm::DefineCoordinateFrameForm_Load);
			this->CoordinateFramePages->ResumeLayout(false);
			this->infoPage->ResumeLayout(false);
			this->markerPage->ResumeLayout(false);
			this->markerPage->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	// local variables
	private: osg::Vec3* posO;
	private: osg::Vec3* posX;
	private: osg::Vec3* posY;

	private: System::Void DefineCoordinateFrameForm_Load(System::Object^  sender, System::EventArgs^  e) {
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
						 if (!posO)
							 posO = new osg::Vec3(pt.x(), pt.y(), pt.z());
						 else
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
						 if (!posX)
							 posX = new osg::Vec3(pt.x(), pt.y(), pt.z());
						 else
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
						 if (!posY)
							 posY = new osg::Vec3(pt.x(), pt.y(), pt.z());
						 else
							 posY->set(pt.x(), pt.y(), pt.z());

						 coordinate_setPoint(posY, coordinateYLabel);
					 }

					 client->unlock();
				 }
			 }
	private: System::Void coordinate_setDefaultText(Label^ text) {
				 text->Text = L"No data found";
			 }
	private: System::Void coordinate_setPoint(osg::Vec3* pos, Label^ text) {
				String^ str = Convert::ToString(pos->x());
				str += ", ";
				str += Convert::ToString(pos->y());
				str += ", ";
				str += Convert::ToString(pos->z());
				text->Text = str;
			 }

	private: System::Void coordinateSetButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CaptureWorld* world = AppData::getInstance()->getWorld();
				 if (world)
					 world->setCoordinateFrame(CaptureObjectUtil::makeGlobalToLocalMatrix(*posO, *posX, *posY));
				 
				 delete posO;
				 delete posX;
				 delete posY;

				 this->Close();
			 }
	private: System::Void coordinateResetButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CaptureWorld* world = AppData::getInstance()->getWorld();
				 if (world)
				 {
					 osg::Matrix* m = new osg::Matrix();
					 m->makeIdentity();
					 world->setCoordinateFrame(m);
				 }
				 
				 if (posO) delete posO;
				 if (posX) delete posX;
				 if (posY) delete posY;

				 this->Close();
			 }

};
}
