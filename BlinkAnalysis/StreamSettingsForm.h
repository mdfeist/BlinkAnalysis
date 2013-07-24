#pragma once

#include "OutputManager.h"

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StreamSettingsForm
	/// </summary>
	public ref class StreamSettingsForm : public System::Windows::Forms::Form
	{
	public:
		StreamSettingsForm(void)
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
		~StreamSettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  addressLabel;
	private: System::Windows::Forms::Label^  portLabel;
	private: System::Windows::Forms::Label^  FPSLabel;
	private: System::Windows::Forms::TextBox^  addressTextBox;
	private: System::Windows::Forms::TextBox^  portTextBox;
	private: System::Windows::Forms::ComboBox^  FPSComboBox;

	protected: 

	protected: 





	private: System::Windows::Forms::Button^  setButton;
	private: System::Windows::Forms::Label^  infoLabel;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StreamSettingsForm::typeid));
			this->addressLabel = (gcnew System::Windows::Forms::Label());
			this->portLabel = (gcnew System::Windows::Forms::Label());
			this->FPSLabel = (gcnew System::Windows::Forms::Label());
			this->addressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->portTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FPSComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->setButton = (gcnew System::Windows::Forms::Button());
			this->infoLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// addressLabel
			// 
			this->addressLabel->AutoSize = true;
			this->addressLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->addressLabel->Location = System::Drawing::Point(60, 105);
			this->addressLabel->Name = L"addressLabel";
			this->addressLabel->Size = System::Drawing::Size(99, 15);
			this->addressLabel->TabIndex = 0;
			this->addressLabel->Text = L"Network Address";
			// 
			// portLabel
			// 
			this->portLabel->AutoSize = true;
			this->portLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->portLabel->Location = System::Drawing::Point(82, 147);
			this->portLabel->Name = L"portLabel";
			this->portLabel->Size = System::Drawing::Size(77, 15);
			this->portLabel->TabIndex = 1;
			this->portLabel->Text = L"Port Number";
			// 
			// FPSLabel
			// 
			this->FPSLabel->AutoSize = true;
			this->FPSLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FPSLabel->Location = System::Drawing::Point(44, 186);
			this->FPSLabel->Name = L"FPSLabel";
			this->FPSLabel->Size = System::Drawing::Size(115, 15);
			this->FPSLabel->TabIndex = 2;
			this->FPSLabel->Text = L"Frames per Second";
			// 
			// addressTextBox
			// 
			this->addressTextBox->Location = System::Drawing::Point(190, 104);
			this->addressTextBox->Name = L"addressTextBox";
			this->addressTextBox->Size = System::Drawing::Size(181, 20);
			this->addressTextBox->TabIndex = 3;
			this->addressTextBox->TextChanged += gcnew System::EventHandler(this, &StreamSettingsForm::checkEmptyText);
			// 
			// portTextBox
			// 
			this->portTextBox->Location = System::Drawing::Point(190, 146);
			this->portTextBox->Name = L"portTextBox";
			this->portTextBox->Size = System::Drawing::Size(121, 20);
			this->portTextBox->TabIndex = 4;
			this->portTextBox->TextChanged += gcnew System::EventHandler(this, &StreamSettingsForm::checkEmptyText);
			// 
			// FPSComboBox
			// 
			this->FPSComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->FPSComboBox->FormattingEnabled = true;
			this->FPSComboBox->Location = System::Drawing::Point(190, 185);
			this->FPSComboBox->Name = L"FPSComboBox";
			this->FPSComboBox->Size = System::Drawing::Size(121, 21);
			this->FPSComboBox->TabIndex = 5;
			// 
			// setButton
			// 
			this->setButton->Enabled = false;
			this->setButton->Location = System::Drawing::Point(324, 227);
			this->setButton->Name = L"setButton";
			this->setButton->Size = System::Drawing::Size(86, 23);
			this->setButton->TabIndex = 6;
			this->setButton->Text = L"Use Settings";
			this->setButton->UseVisualStyleBackColor = true;
			this->setButton->Click += gcnew System::EventHandler(this, &StreamSettingsForm::setButton_Click);
			// 
			// infoLabel
			// 
			this->infoLabel->AutoSize = true;
			this->infoLabel->Location = System::Drawing::Point(12, 9);
			this->infoLabel->Name = L"infoLabel";
			this->infoLabel->Size = System::Drawing::Size(320, 78);
			this->infoLabel->TabIndex = 7;
			this->infoLabel->Text = resources->GetString(L"infoLabel.Text");
			// 
			// StreamSettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(422, 262);
			this->Controls->Add(this->infoLabel);
			this->Controls->Add(this->setButton);
			this->Controls->Add(this->FPSComboBox);
			this->Controls->Add(this->portTextBox);
			this->Controls->Add(this->addressTextBox);
			this->Controls->Add(this->FPSLabel);
			this->Controls->Add(this->portLabel);
			this->Controls->Add(this->addressLabel);
			this->Name = L"StreamSettingsForm";
			this->Text = L"Network Streaming Settings";
			this->Load += gcnew System::EventHandler(this, &StreamSettingsForm::StreamSettingsForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void StreamSettingsForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 for (int i = 1; i <= 100; i++)
				 {
					 this->FPSComboBox->Items->Add(i.ToString());
				 }
				 this->FPSComboBox->SelectedIndex = OutputManager::getInstance()->getFramesPerSec() - 1;

				 this->addressTextBox->Text = StreamingManager::getInstance()->getIPAddress();
				 this->portTextBox->Text = StreamingManager::getInstance()->getPortNumber().ToString();
			 }
			 // converts a managed String^ to unmanaged std::string*
	private: const char* managedStringToChar(String^ str) {
				 return (const char*) (Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str)).ToPointer();
			 }
	private: bool isNumber(String^ str) {
				 String^ regs = "^\\s*-?\\d+\\s*$";
				 System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(regs);
				 return regex->IsMatch(str);
			 }

	private: System::Void checkEmptyText(System::Object^  sender, System::EventArgs^  e) {
				 if (!String::IsNullOrWhiteSpace(this->addressTextBox->Text) &&
					 isNumber(this->portTextBox->Text) &&
					 this->FPSComboBox->SelectedItem)
					 this->setButton->Enabled = true;
				 else
					 this->setButton->Enabled = false;
			 }
	private: System::Void setButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 int port;
				 bool wasStreaming = StreamingManager::getInstance()->isStreaming();

				 if (wasStreaming) 
					 StreamingManager::getInstance()->stopStreaming();

				 if ( !StreamingManager::getInstance()->setIPAddress(
					 managedStringToChar(this->addressTextBox->Text->Trim()) ) )
				 {
					 String^ message = "Invalid IP address: " + this->addressTextBox->Text;
					 MessageBox::Show(message, "", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 }
				 else if (!Int32::TryParse(this->portTextBox->Text, port))
				 {
					 String^ message = "Invalid port number: " + this->portTextBox->Text;
					 MessageBox::Show(message, "", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 }
				 else
				 {
					 StreamingManager::getInstance()->setPortNumber(port);
					 OutputManager::getInstance()->setFramesPerSec(this->FPSComboBox->SelectedIndex + 1);
					 if (wasStreaming)
						 StreamingManager::getInstance()->startStreaming();
					 this->Close();
				 }

			 }
	};
}
