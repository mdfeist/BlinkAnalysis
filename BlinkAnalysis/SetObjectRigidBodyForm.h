#pragma once

#include <vector>
#include "AppData.h"

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SetObjectRigidBodyForm
	/// </summary>
	public ref class SetObjectRigidBodyForm : public System::Windows::Forms::Form
	{
	public:
		SetObjectRigidBodyForm(void)
		{
			InitializeComponent();
			
			rigidBodyVector = NULL;
			rigidID = -1;
			hasRB = false;
		}

		void setRigidBodyVector(std::vector<RigidBody*>* vector)
		{
			rigidBodyVector = vector;
		}

		void setWorldAndObject(int world, int object)
		{
			this->worldID = world;
			this->objectID = object;
		}

		void setHasRigidBody(bool rb)
		{
			hasRB = rb;
		}



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SetObjectRigidBodyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::String^ defaultDataText;
	private: std::vector<RigidBody*>* rigidBodyVector;
	private: int rigidID;
	private: int worldID;
	private: int objectID;
	private: bool hasRB;

	private: System::Windows::Forms::ListView^  rigidBodyListView;

	private: System::Windows::Forms::Label^  positionLabel;
	private: System::Windows::Forms::Label^  rigidDataLabel;
	private: System::Windows::Forms::Button^  attachButton;
	private: System::Windows::Forms::Button^  detachButton;
	private: System::Windows::Forms::CheckBox^  offsetCheckBox;


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
			this->rigidBodyListView = (gcnew System::Windows::Forms::ListView());
			this->positionLabel = (gcnew System::Windows::Forms::Label());
			this->rigidDataLabel = (gcnew System::Windows::Forms::Label());
			this->attachButton = (gcnew System::Windows::Forms::Button());
			this->detachButton = (gcnew System::Windows::Forms::Button());
			this->offsetCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// rigidBodyListView
			// 
			this->rigidBodyListView->Alignment = System::Windows::Forms::ListViewAlignment::Left;
			this->rigidBodyListView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->rigidBodyListView->FullRowSelect = true;
			this->rigidBodyListView->LabelWrap = false;
			this->rigidBodyListView->Location = System::Drawing::Point(12, 12);
			this->rigidBodyListView->MultiSelect = false;
			this->rigidBodyListView->Name = L"rigidBodyListView";
			this->rigidBodyListView->Size = System::Drawing::Size(261, 223);
			this->rigidBodyListView->TabIndex = 2;
			this->rigidBodyListView->TileSize = System::Drawing::Size(100, 20);
			this->rigidBodyListView->UseCompatibleStateImageBehavior = false;
			this->rigidBodyListView->View = System::Windows::Forms::View::SmallIcon;
			this->rigidBodyListView->SelectedIndexChanged += gcnew System::EventHandler(this, &SetObjectRigidBodyForm::rigidBodyListView_SelectedIndexChanged);
			// 
			// positionLabel
			// 
			this->positionLabel->AutoSize = true;
			this->positionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->positionLabel->Location = System::Drawing::Point(14, 273);
			this->positionLabel->Name = L"positionLabel";
			this->positionLabel->Size = System::Drawing::Size(51, 15);
			this->positionLabel->TabIndex = 3;
			this->positionLabel->Text = L"Position";
			// 
			// rigidDataLabel
			// 
			this->rigidDataLabel->AutoSize = true;
			this->rigidDataLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rigidDataLabel->Location = System::Drawing::Point(44, 300);
			this->rigidDataLabel->Name = L"rigidDataLabel";
			this->rigidDataLabel->Size = System::Drawing::Size(84, 15);
			this->rigidDataLabel->TabIndex = 4;
			this->rigidDataLabel->Text = L"No data found";
			// 
			// attachButton
			// 
			this->attachButton->Enabled = false;
			this->attachButton->Location = System::Drawing::Point(186, 344);
			this->attachButton->Name = L"attachButton";
			this->attachButton->Size = System::Drawing::Size(87, 23);
			this->attachButton->TabIndex = 5;
			this->attachButton->Text = L"Attach Object";
			this->attachButton->UseVisualStyleBackColor = true;
			this->attachButton->Click += gcnew System::EventHandler(this, &SetObjectRigidBodyForm::attachButton_Click);
			// 
			// detachButton
			// 
			this->detachButton->Location = System::Drawing::Point(12, 344);
			this->detachButton->Name = L"detachButton";
			this->detachButton->Size = System::Drawing::Size(88, 23);
			this->detachButton->TabIndex = 6;
			this->detachButton->Text = L"Detach Object";
			this->detachButton->UseVisualStyleBackColor = true;
			this->detachButton->Visible = false;
			this->detachButton->Click += gcnew System::EventHandler(this, &SetObjectRigidBodyForm::detachButton_Click);
			// 
			// offsetCheckBox
			// 
			this->offsetCheckBox->AutoSize = true;
			this->offsetCheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->offsetCheckBox->Location = System::Drawing::Point(20, 241);
			this->offsetCheckBox->Name = L"offsetCheckBox";
			this->offsetCheckBox->Size = System::Drawing::Size(234, 19);
			this->offsetCheckBox->TabIndex = 8;
			this->offsetCheckBox->Text = L"move object relative to current position";
			this->offsetCheckBox->UseVisualStyleBackColor = true;
			// 
			// SetObjectRigidBodyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(285, 379);
			this->Controls->Add(this->offsetCheckBox);
			this->Controls->Add(this->detachButton);
			this->Controls->Add(this->attachButton);
			this->Controls->Add(this->rigidDataLabel);
			this->Controls->Add(this->positionLabel);
			this->Controls->Add(this->rigidBodyListView);
			this->Name = L"SetObjectRigidBodyForm";
			this->Text = L"Attach Object to Rigid Body";
			this->Load += gcnew System::EventHandler(this, &SetObjectRigidBodyForm::SetObjectRigidBodyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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

			this->rigidBodyListView->Items->Clear();
					
			for (std::vector<RigidBody*>::iterator itr = rigidBodyVector->begin(); 
				itr != rigidBodyVector->end(); itr++)
			{
				RigidBody* body = *itr;
				String^ rigidBodyID = Convert::ToString(body->getID());
				String^ rigidBodyName = gcnew String(body->getName());
				ListViewItem^ listViewItem = gcnew ListViewItem(rigidBodyID); 
				listViewItem->SubItems->Add(rigidBodyName);
				this->rigidBodyListView->Items->Add(listViewItem);
			}
		 }
private: System::Void SetObjectRigidBodyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 this->defaultDataText = L"No data found";
			 
			 this->rigidBodyListView->View = View::Details;
			 this->rigidBodyListView->Columns->Add("Id", 50, HorizontalAlignment::Left ); 
			 this->rigidBodyListView->Columns->Add("Name", 150, HorizontalAlignment::Left ); 

			 loadRigidBodyList();

			 if (hasRB)
				 this->detachButton->Visible = true;
		 }
private: System::Void rigidBodyListView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->rigidBodyListView->SelectedItems->Count <= 0)
				 return;

			 ListViewItem^ item = this->rigidBodyListView->SelectedItems->default[0];
			 if (item && Int32::TryParse(item->Text, rigidID))
			 {
				this->attachButton->Enabled = true;
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
private: System::Void attachButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void detachButton_Click(System::Object^  sender, System::EventArgs^  e);
};
}
