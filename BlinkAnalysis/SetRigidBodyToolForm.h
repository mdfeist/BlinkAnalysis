#pragma once
#include "AppData.h"

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SetRigidBodyToolForm
	/// </summary>
	public ref class SetRigidBodyToolForm : public System::Windows::Forms::Form
	{
	public:
		SetRigidBodyToolForm(void)
		{
			InitializeComponent();
			
			rigidBodyVector = NULL;
			rigidID = -1;
			defaultDataText = "No data found";
		}

		void setRigidBodyVector(std::vector<RigidBody*>* vector)
		{
			rigidBodyVector = vector;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SetRigidBodyToolForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  rigidDataLabel;
	protected: 
	private: System::Windows::Forms::Label^  positionLabel;
	private: System::Windows::Forms::ListView^  rigidBodyListView;
	private: System::Windows::Forms::Button^  setButton;

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
			this->rigidDataLabel = (gcnew System::Windows::Forms::Label());
			this->positionLabel = (gcnew System::Windows::Forms::Label());
			this->rigidBodyListView = (gcnew System::Windows::Forms::ListView());
			this->setButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// rigidDataLabel
			// 
			this->rigidDataLabel->AutoSize = true;
			this->rigidDataLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidDataLabel->Location = System::Drawing::Point(42, 274);
			this->rigidDataLabel->Name = L"rigidDataLabel";
			this->rigidDataLabel->Size = System::Drawing::Size(84, 15);
			this->rigidDataLabel->TabIndex = 11;
			this->rigidDataLabel->Text = L"No data found";
			// 
			// positionLabel
			// 
			this->positionLabel->AutoSize = true;
			this->positionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->positionLabel->Location = System::Drawing::Point(12, 247);
			this->positionLabel->Name = L"positionLabel";
			this->positionLabel->Size = System::Drawing::Size(51, 15);
			this->positionLabel->TabIndex = 10;
			this->positionLabel->Text = L"Position";
			// 
			// rigidBodyListView
			// 
			this->rigidBodyListView->Alignment = System::Windows::Forms::ListViewAlignment::Left;
			this->rigidBodyListView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->rigidBodyListView->FullRowSelect = true;
			this->rigidBodyListView->HideSelection = false;
			this->rigidBodyListView->LabelWrap = false;
			this->rigidBodyListView->Location = System::Drawing::Point(12, 12);
			this->rigidBodyListView->MultiSelect = false;
			this->rigidBodyListView->Name = L"rigidBodyListView";
			this->rigidBodyListView->Size = System::Drawing::Size(261, 223);
			this->rigidBodyListView->TabIndex = 9;
			this->rigidBodyListView->TileSize = System::Drawing::Size(100, 20);
			this->rigidBodyListView->UseCompatibleStateImageBehavior = false;
			this->rigidBodyListView->View = System::Windows::Forms::View::SmallIcon;
			this->rigidBodyListView->SelectedIndexChanged += gcnew System::EventHandler(this, &SetRigidBodyToolForm::rigidBodyListView_SelectedIndexChanged);
			// 
			// setButton
			// 
			this->setButton->Enabled = false;
			this->setButton->Location = System::Drawing::Point(197, 307);
			this->setButton->Name = L"setButton";
			this->setButton->Size = System::Drawing::Size(75, 23);
			this->setButton->TabIndex = 12;
			this->setButton->Text = L"Set Tool";
			this->setButton->UseVisualStyleBackColor = true;
			this->setButton->Click += gcnew System::EventHandler(this, &SetRigidBodyToolForm::setButton_Click);
			// 
			// SetRigidBodyToolForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 341);
			this->Controls->Add(this->setButton);
			this->Controls->Add(this->rigidDataLabel);
			this->Controls->Add(this->positionLabel);
			this->Controls->Add(this->rigidBodyListView);
			this->Name = L"SetRigidBodyToolForm";
			this->Text = L"Set Rigid Body Tool";
			this->Load += gcnew System::EventHandler(this, &SetRigidBodyToolForm::SetRigidBodyToolForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::String^ defaultDataText;
	private: std::vector<RigidBody*>* rigidBodyVector;
	private: int rigidID;

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
private: System::Void loadRigidBodyList() {
			if (!rigidBodyVector) return;

			ClientHandler* client = AppData::getInstance()->getClient();
			if (client)
				rigidID = client->getRigidBodyTool();

			this->rigidBodyListView->Items->Clear();
			int idx = 0;
			int select = -1;
			for (std::vector<RigidBody*>::iterator itr = rigidBodyVector->begin(); 
				itr != rigidBodyVector->end(); itr++)
			{
				RigidBody* body = *itr;
				String^ rigidBodyID = Convert::ToString(body->getID());
				String^ rigidBodyName = gcnew String(body->getName());
				ListViewItem^ listViewItem = gcnew ListViewItem(rigidBodyID); 
				listViewItem->SubItems->Add(rigidBodyName);
				this->rigidBodyListView->Items->Add(listViewItem);

				if (body->getID() == rigidID)
					select = idx;
				else
					idx++;
			}
			if (select >= 0)
				rigidBodyListView->SelectedIndices->Add(select);
		 }
private: System::Void SetRigidBodyToolForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 this->defaultDataText = L"No data found";
			 
			 this->rigidBodyListView->View = View::Details;
			 this->rigidBodyListView->Columns->Add("Id", 50, HorizontalAlignment::Left ); 
			 this->rigidBodyListView->Columns->Add("Name", 150, HorizontalAlignment::Left ); 

			 loadRigidBodyList();
		 }
private: System::Void rigidBodyListView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->rigidBodyListView->SelectedItems->Count <= 0)
				 return;

			 ListViewItem^ item = this->rigidBodyListView->SelectedItems->default[0];
			 if (item && Int32::TryParse(item->Text, rigidID))
			 {
				this->setButton->Enabled = true;
				ClientHandler* client = AppData::getInstance()->getClient();
				if (client)
				{
					RigidBody* body = client->getRigidBody(rigidID);
					if (body)
					{
						coordinate_setPoint(&(body->getPosition()), this->rigidDataLabel);
						return;
					}
				}
			 }
			 coordinate_setDefaultText(this->rigidDataLabel);
		 }
private: System::Void setButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ClientHandler* client = AppData::getInstance()->getClient();
			 if (client)
				 client->setRigidBodyTool(rigidID);
			 this->Close();
		 }

};
}
