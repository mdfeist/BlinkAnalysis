#pragma once

#include "AppData.h"
#include "WorldManager.h"
#include "FormUtils.h"

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace FormUtils;

	/// <summary>
	/// Simple form for adding a new CaptureWorld \n
	/// Controller not needed since WorldManager will call update on MainForm
	/// </summary>
	public ref class AddWorldForm : public System::Windows::Forms::Form
	{
	public:
		AddWorldForm(void)
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
		~AddWorldForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  nameLabel;
	private: System::Windows::Forms::TextBox^  nameTextBox;
	private: System::Windows::Forms::Button^  nameButton;

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
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nameButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->nameLabel->Location = System::Drawing::Point(12, 13);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(41, 15);
			this->nameLabel->TabIndex = 0;
			this->nameLabel->Text = L"Name";
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(59, 12);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(213, 20);
			this->nameTextBox->TabIndex = 1;
			this->nameTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddWorldForm::nameTextBox_KeyPress);
			// 
			// nameButton
			// 
			this->nameButton->Location = System::Drawing::Point(197, 38);
			this->nameButton->Name = L"nameButton";
			this->nameButton->Size = System::Drawing::Size(75, 23);
			this->nameButton->TabIndex = 2;
			this->nameButton->Text = L"Add World";
			this->nameButton->UseVisualStyleBackColor = true;
			this->nameButton->Click += gcnew System::EventHandler(this, &AddWorldForm::nameButton_Click);
			// 
			// AddWorldForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 73);
			this->Controls->Add(this->nameButton);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->nameLabel);
			this->Name = L"AddWorldForm";
			this->Text = L"Add a New World";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void nameButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CaptureWorld* world = new CaptureWorld(std::string(managedStringToChar(this->nameTextBox->Text)));
				 WorldManager::getInstance()->addWorld(world);
				 Close();
			 }
	private: System::Void nameTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
				 if (e->KeyChar == '\r')
				 {
					 CaptureWorld* world = new CaptureWorld(std::string(managedStringToChar(this->nameTextBox->Text)));
					 WorldManager::getInstance()->addWorld(world);
					 Close();
				 }
			 }
	};
}
