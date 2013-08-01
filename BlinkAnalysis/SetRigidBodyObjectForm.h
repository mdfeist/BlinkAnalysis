#pragma once
#include "WorldManager.h"

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form to attach an existing object to the rigid body
	/// </summary>
	public ref class SetRigidBodyObjectForm : public System::Windows::Forms::Form
	{
	public:
		SetRigidBodyObjectForm(void)
		{
			InitializeComponent();
			
			this->rigidID = -1;
			this->objectID = -1;
			this->worldID = -1;
		}

		void setRigidBody(int rid)
		{
			this->rigidID = rid;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SetRigidBodyObjectForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  objectLabel;
	private: System::Windows::Forms::Label^  worldLabel;
	protected: 

	private: System::Windows::Forms::ComboBox^  worldComboBox;


	private: System::Windows::Forms::ComboBox^  objectComboBox;
	private: System::Windows::Forms::DataGridView^  objectGridView;


	private: System::Windows::Forms::CheckBox^  offsetCheckBox;
	private: System::Windows::Forms::Button^  detachButton;
	private: System::Windows::Forms::Button^  attachButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  objectPropertyColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  objectValueColumn;

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
			this->objectLabel = (gcnew System::Windows::Forms::Label());
			this->worldLabel = (gcnew System::Windows::Forms::Label());
			this->worldComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->objectComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->objectGridView = (gcnew System::Windows::Forms::DataGridView());
			this->objectPropertyColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->objectValueColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->offsetCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->detachButton = (gcnew System::Windows::Forms::Button());
			this->attachButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->objectGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// objectLabel
			// 
			this->objectLabel->AutoSize = true;
			this->objectLabel->Location = System::Drawing::Point(14, 47);
			this->objectLabel->Name = L"objectLabel";
			this->objectLabel->Size = System::Drawing::Size(38, 13);
			this->objectLabel->TabIndex = 18;
			this->objectLabel->Text = L"Object";
			// 
			// worldLabel
			// 
			this->worldLabel->AutoSize = true;
			this->worldLabel->Location = System::Drawing::Point(17, 20);
			this->worldLabel->Name = L"worldLabel";
			this->worldLabel->Size = System::Drawing::Size(35, 13);
			this->worldLabel->TabIndex = 17;
			this->worldLabel->Text = L"World";
			// 
			// worldComboBox
			// 
			this->worldComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->worldComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->worldComboBox->ForeColor = System::Drawing::SystemColors::InfoText;
			this->worldComboBox->FormattingEnabled = true;
			this->worldComboBox->Location = System::Drawing::Point(58, 17);
			this->worldComboBox->Name = L"worldComboBox";
			this->worldComboBox->Size = System::Drawing::Size(223, 21);
			this->worldComboBox->TabIndex = 16;
			this->worldComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &SetRigidBodyObjectForm::worldComboBox_SelectedIndexChanged);
			// 
			// objectComboBox
			// 
			this->objectComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->objectComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->objectComboBox->ForeColor = System::Drawing::SystemColors::InfoText;
			this->objectComboBox->FormattingEnabled = true;
			this->objectComboBox->Location = System::Drawing::Point(58, 44);
			this->objectComboBox->Name = L"objectComboBox";
			this->objectComboBox->Size = System::Drawing::Size(223, 21);
			this->objectComboBox->TabIndex = 14;
			this->objectComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &SetRigidBodyObjectForm::objectComboBox_SelectedIndexChanged);
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
			this->objectGridView->Location = System::Drawing::Point(26, 71);
			this->objectGridView->Name = L"objectGridView";
			this->objectGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->objectGridView->Size = System::Drawing::Size(255, 159);
			this->objectGridView->TabIndex = 13;
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
			this->objectValueColumn->ReadOnly = true;
			this->objectValueColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// offsetCheckBox
			// 
			this->offsetCheckBox->AutoSize = true;
			this->offsetCheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->offsetCheckBox->Location = System::Drawing::Point(26, 236);
			this->offsetCheckBox->Name = L"offsetCheckBox";
			this->offsetCheckBox->Size = System::Drawing::Size(234, 19);
			this->offsetCheckBox->TabIndex = 19;
			this->offsetCheckBox->Text = L"move object relative to current position";
			this->offsetCheckBox->UseVisualStyleBackColor = true;
			// 
			// detachButton
			// 
			this->detachButton->Enabled = false;
			this->detachButton->Location = System::Drawing::Point(20, 275);
			this->detachButton->Name = L"detachButton";
			this->detachButton->Size = System::Drawing::Size(88, 23);
			this->detachButton->TabIndex = 21;
			this->detachButton->Text = L"Detach Object";
			this->detachButton->UseVisualStyleBackColor = true;
			this->detachButton->Click += gcnew System::EventHandler(this, &SetRigidBodyObjectForm::detachButton_Click);
			// 
			// attachButton
			// 
			this->attachButton->Enabled = false;
			this->attachButton->Location = System::Drawing::Point(194, 275);
			this->attachButton->Name = L"attachButton";
			this->attachButton->Size = System::Drawing::Size(87, 23);
			this->attachButton->TabIndex = 20;
			this->attachButton->Text = L"Attach Object";
			this->attachButton->UseVisualStyleBackColor = true;
			this->attachButton->Click += gcnew System::EventHandler(this, &SetRigidBodyObjectForm::attachButton_Click);
			// 
			// SetRigidBodyObjectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(301, 313);
			this->Controls->Add(this->detachButton);
			this->Controls->Add(this->attachButton);
			this->Controls->Add(this->offsetCheckBox);
			this->Controls->Add(this->objectLabel);
			this->Controls->Add(this->worldLabel);
			this->Controls->Add(this->worldComboBox);
			this->Controls->Add(this->objectComboBox);
			this->Controls->Add(this->objectGridView);
			this->Name = L"SetRigidBodyObjectForm";
			this->Text = L"Attach Object to Rigid Body";
			this->Load += gcnew System::EventHandler(this, &SetRigidBodyObjectForm::SetRigidBodyObjectForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->objectGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: int rigidID;
	private: int objectID;
	private: int worldID;

	private: int worldExtractID(String^ str) {
				 array<String^>^ split = str->Split(gcnew array<wchar_t> {'(', ')'});

				 int result;
				 // id contained in second to last element
				 if (Int32::TryParse(split[split->Length - 2], result))
					 return result;
				 else
					 return -1;
			}

	private: System::Void SetRigidBodyObjectForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 if (rigidID < 0)
					 this->Close();

				 this->Text = L"Attach Rigid Body (ID " + rigidID.ToString() + L")";

				 worldPopulateList();
			 }
	private: System::Void worldPopulateList() {
				this->worldComboBox->Items->Clear();
				this->objectComboBox->Items->Clear();
				resetObjectGridView();

				std::map<int, CaptureWorld*> worlds = WorldManager::getInstance()->getWorlds();
				for (worlds_iterator itr = worlds.begin(); itr != worlds.end(); itr++)
				{
					String^ worldName = gcnew String(itr->second->getName().c_str());
					worldName += " (";
					worldName += itr->first.ToString();
					worldName += ")";
					this->worldComboBox->Items->Add(worldName);
				}
			 }
			 // populate list of objects based on displayObjectWorld
	private: System::Void objectUpdateList() {
				 this->objectComboBox->Items->Clear();
				 resetObjectGridView();

				 CaptureWorld* world = WorldManager::getInstance()->getWorld(worldID);
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
						if (itr->second->getRigidBody() == rigidID)
							objectName += " [attached]";
						this->objectComboBox->Items->Add(objectName);
					 }
				 }
			 }
	private: System::Void resetObjectGridView() {
				this->objectGridView->Rows->Clear();
				this->objectID = -1;
				this->detachButton->Enabled = false;
				this->attachButton->Enabled = false;
			 }
			 // update world display if drop down list value changes
	private: System::Void worldComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (!this->worldComboBox->SelectedItem)
				 {
					 resetObjectGridView();
					 return;
				 }

				 String^ text = this->worldComboBox->SelectedItem->ToString();
				 int id = worldExtractID(text);
				 if (id >= 0)
				 {
					 this->worldID = id;
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
					 this->attachButton->Enabled = true;
					 this->objectID = id;
					 objectGridView_displayObject();
				 }
			 }
		// populates the object GridView based on selected value from world and object ComboBoxes
	private: System::Void objectGridView_displayObject() {
				this->objectGridView->Rows->Clear();
				CaptureWorld* world = WorldManager::getInstance()->getWorld(worldID);
				if (!world) return;
				CaptureObject* object = world->getObject(objectID);
				if (!object) return;

				array<String^>^ row;

				// populate values
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

				if (object->getRigidBody() == rigidID)
					this->detachButton->Enabled = true;
				else
					this->detachButton->Enabled = false;
		 }
private: System::Void attachButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (rigidID >= 0)
			 {
				 CaptureWorld* world = WorldManager::getInstance()->getWorld(worldID);
				 if (world)
				 {
					 int result = world->setObjectRigidBody(objectID, rigidID, this->offsetCheckBox->Checked);
					 if (!result)
					 {
						 String^ message = "Could not attach object (ID " + objectID.ToString() + ") to rigid body (ID " + 
							 rigidID.ToString() + "). \nIs the rigid body already attached to an object in a different world?";
						 MessageBox::Show(message, "Could not attach rigid body", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					 }
					 else
					 {
						 int selected = this->objectComboBox->SelectedIndex;
						 objectUpdateList();
						 this->objectComboBox->SelectedIndex = selected;
					 }
				 }
			 }
		 }
private: System::Void detachButton_Click(System::Object^  sender, System::EventArgs^  e) {
			CaptureWorld* world = WorldManager::getInstance()->getWorld(worldID);
			if (world)
			{
				 world->setObjectRigidBody(objectID, -1, this->offsetCheckBox->Checked);
				 int selected = this->objectComboBox->SelectedIndex;
				 objectUpdateList();
				 this->objectComboBox->SelectedIndex = selected;
			}
		 }
};
}
