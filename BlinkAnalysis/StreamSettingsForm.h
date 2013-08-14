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
	/// Form to change output settings for both recording and streaming
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
	private: System::Windows::Forms::TextBox^  marginTextBox;
	private: System::Windows::Forms::Label^  marginLabel;
	private: System::Windows::Forms::TextBox^  depthTextBox;
	private: System::Windows::Forms::Label^  depthLabel;
	private: System::Windows::Forms::CheckBox^  saveDataCheckBox;

	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog;
	private: System::Windows::Forms::TextBox^  filePathText;

	private: System::Windows::Forms::Button^  browseButton;


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
			this->addressLabel = (gcnew System::Windows::Forms::Label());
			this->portLabel = (gcnew System::Windows::Forms::Label());
			this->FPSLabel = (gcnew System::Windows::Forms::Label());
			this->addressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->portTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FPSComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->setButton = (gcnew System::Windows::Forms::Button());
			this->infoLabel = (gcnew System::Windows::Forms::Label());
			this->marginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->marginLabel = (gcnew System::Windows::Forms::Label());
			this->depthTextBox = (gcnew System::Windows::Forms::TextBox());
			this->depthLabel = (gcnew System::Windows::Forms::Label());
			this->saveDataCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->filePathText = (gcnew System::Windows::Forms::TextBox());
			this->browseButton = (gcnew System::Windows::Forms::Button());
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
			this->portLabel->Location = System::Drawing::Point(82, 131);
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
			this->FPSLabel->Location = System::Drawing::Point(44, 157);
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
			this->addressTextBox->TextChanged += gcnew System::EventHandler(this, &StreamSettingsForm::checkValidText);
			// 
			// portTextBox
			// 
			this->portTextBox->Location = System::Drawing::Point(190, 130);
			this->portTextBox->Name = L"portTextBox";
			this->portTextBox->Size = System::Drawing::Size(121, 20);
			this->portTextBox->TabIndex = 4;
			this->portTextBox->TextChanged += gcnew System::EventHandler(this, &StreamSettingsForm::checkValidText);
			// 
			// FPSComboBox
			// 
			this->FPSComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->FPSComboBox->FormattingEnabled = true;
			this->FPSComboBox->Location = System::Drawing::Point(190, 156);
			this->FPSComboBox->Name = L"FPSComboBox";
			this->FPSComboBox->Size = System::Drawing::Size(121, 21);
			this->FPSComboBox->TabIndex = 5;
			// 
			// setButton
			// 
			this->setButton->Enabled = false;
			this->setButton->Location = System::Drawing::Point(324, 364);
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
			this->infoLabel->Size = System::Drawing::Size(320, 65);
			this->infoLabel->TabIndex = 7;
			this->infoLabel->Text = L"Change the output settings for streaming and recording.\r\nData is streamed over TC" 
				L"P using XML format.\r\n\r\nNote: \r\nClicking \"Use Settings\" will restart the server i" 
				L"f it is already running.";
			// 
			// marginTextBox
			// 
			this->marginTextBox->Location = System::Drawing::Point(190, 307);
			this->marginTextBox->Name = L"marginTextBox";
			this->marginTextBox->Size = System::Drawing::Size(121, 20);
			this->marginTextBox->TabIndex = 9;
			this->marginTextBox->TextChanged += gcnew System::EventHandler(this, &StreamSettingsForm::checkValidText);
			// 
			// marginLabel
			// 
			this->marginLabel->AutoSize = true;
			this->marginLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->marginLabel->Location = System::Drawing::Point(47, 308);
			this->marginLabel->Name = L"marginLabel";
			this->marginLabel->Size = System::Drawing::Size(112, 15);
			this->marginLabel->TabIndex = 8;
			this->marginLabel->Text = L"Intersection Margin";
			// 
			// depthTextBox
			// 
			this->depthTextBox->Location = System::Drawing::Point(190, 333);
			this->depthTextBox->Name = L"depthTextBox";
			this->depthTextBox->Size = System::Drawing::Size(121, 20);
			this->depthTextBox->TabIndex = 11;
			this->depthTextBox->TextChanged += gcnew System::EventHandler(this, &StreamSettingsForm::checkValidText);
			// 
			// depthLabel
			// 
			this->depthLabel->AutoSize = true;
			this->depthLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->depthLabel->Location = System::Drawing::Point(53, 334);
			this->depthLabel->Name = L"depthLabel";
			this->depthLabel->Size = System::Drawing::Size(106, 15);
			this->depthLabel->TabIndex = 10;
			this->depthLabel->Text = L"Intersection Depth";
			// 
			// saveDataCheckBox
			// 
			this->saveDataCheckBox->AutoSize = true;
			this->saveDataCheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->saveDataCheckBox->Location = System::Drawing::Point(47, 201);
			this->saveDataCheckBox->Name = L"saveDataCheckBox";
			this->saveDataCheckBox->Size = System::Drawing::Size(153, 19);
			this->saveDataCheckBox->TabIndex = 13;
			this->saveDataCheckBox->Text = L"Save stream data to file";
			this->saveDataCheckBox->UseVisualStyleBackColor = true;
			this->saveDataCheckBox->CheckedChanged += gcnew System::EventHandler(this, &StreamSettingsForm::saveDataCheckBox_CheckedChanged);
			// 
			// filePathText
			// 
			this->filePathText->Enabled = false;
			this->filePathText->Location = System::Drawing::Point(63, 226);
			this->filePathText->Name = L"filePathText";
			this->filePathText->ReadOnly = true;
			this->filePathText->Size = System::Drawing::Size(248, 20);
			this->filePathText->TabIndex = 14;
			this->filePathText->TextChanged += gcnew System::EventHandler(this, &StreamSettingsForm::checkValidText);
			// 
			// browseButton
			// 
			this->browseButton->Enabled = false;
			this->browseButton->Location = System::Drawing::Point(317, 224);
			this->browseButton->Name = L"browseButton";
			this->browseButton->Size = System::Drawing::Size(75, 23);
			this->browseButton->TabIndex = 15;
			this->browseButton->Text = L"Browse";
			this->browseButton->UseVisualStyleBackColor = true;
			this->browseButton->Click += gcnew System::EventHandler(this, &StreamSettingsForm::browseButton_Click);
			// 
			// StreamSettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(422, 416);
			this->Controls->Add(this->browseButton);
			this->Controls->Add(this->filePathText);
			this->Controls->Add(this->saveDataCheckBox);
			this->Controls->Add(this->depthTextBox);
			this->Controls->Add(this->depthLabel);
			this->Controls->Add(this->marginTextBox);
			this->Controls->Add(this->marginLabel);
			this->Controls->Add(this->infoLabel);
			this->Controls->Add(this->setButton);
			this->Controls->Add(this->FPSComboBox);
			this->Controls->Add(this->portTextBox);
			this->Controls->Add(this->addressTextBox);
			this->Controls->Add(this->FPSLabel);
			this->Controls->Add(this->portLabel);
			this->Controls->Add(this->addressLabel);
			this->Name = L"StreamSettingsForm";
			this->Text = L"Output Settings";
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
				 this->marginTextBox->Text = OutputManager::getInstance()->getIntersectionBuffer().ToString();
				 this->depthTextBox->Text = OutputManager::getInstance()->getIntersectionLength().ToString();

				 this->saveDataCheckBox->Checked = StreamingManager::getInstance()->getSaveData();
				 this->filePathText->Text = gcnew String(StreamingManager::getInstance()->getFolderPath().c_str());
			 }
			 // converts a managed String^ to unmanaged std::string*
	private: const char* managedStringToChar(String^ str) {
				 return (const char*) (Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str)).ToPointer();
			 }
	private: bool isPositiveNumber(String^ str) {
				 String^ regs = "^\\s*\\d+\\s*$";
				 System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(regs);
				 return regex->IsMatch(str);
			 }
	private: bool isPositiveFloat(String^ str) {
			 String^ regs = "^\\s*\\d+(.\\d+)?\\s*$";
			 System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(regs);
			 return regex->IsMatch(str);
		 }

	private: System::Void checkValidText(System::Object^  sender, System::EventArgs^  e) {
				 if (!String::IsNullOrWhiteSpace(this->addressTextBox->Text) &&
					 isPositiveNumber(this->portTextBox->Text) &&
					 this->FPSComboBox->SelectedItem &&
					 isPositiveFloat(this->marginTextBox->Text) &&
					 isPositiveFloat(this->depthTextBox->Text) &&
					 (!this->saveDataCheckBox->Checked || System::IO::Directory::Exists(this->filePathText->Text)) )
					 this->setButton->Enabled = true;
				 else
					 this->setButton->Enabled = false;
			 }
	private: System::Void setButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 int port;
				 float margin, depth;
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
				 else if (!Single::TryParse(this->marginTextBox->Text, margin))
				 {
					 String^ message = "Invalid intersection margin: " + this->marginTextBox->Text;
					 MessageBox::Show(message, "", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 }
				 else if (!Single::TryParse(this->depthTextBox->Text, depth))
				 {
					 String^ message = "Invalid intersection depth: " + this->depthTextBox->Text;
					 MessageBox::Show(message, "", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 }
				 else if (this->saveDataCheckBox->Checked && 
					 !System::IO::Directory::Exists(this->filePathText->Text))
				 {
					 String^ message = "Invalid folder path: " + this->filePathText->Text;
					 MessageBox::Show(message, "", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 }
				 else
				 {
					 StreamingManager::getInstance()->setPortNumber(port);
					 OutputManager::getInstance()->setFramesPerSec(this->FPSComboBox->SelectedIndex + 1);
					 OutputManager::getInstance()->setIntersectionBuffer(margin);
					 OutputManager::getInstance()->setIntersectionLength(depth);

					 StreamingManager::getInstance()->setSaveData(this->saveDataCheckBox->Checked);
					 if (this->saveDataCheckBox->Checked)
					 {
						 StreamingManager::getInstance()->setFolderPath(
							 std::string(managedStringToChar(this->filePathText->Text)));
					 }

					 if (wasStreaming)
						 StreamingManager::getInstance()->startStreaming();

					 this->setMainFormSave();
					 this->Close();
				 }

			 }

private: System::Void saveDataCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->browseButton->Enabled = this->saveDataCheckBox->Checked;
			 checkValidText(nullptr, nullptr);
		 }
private: System::Void browseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 this->filePathText->Text = this->folderBrowserDialog->SelectedPath;
			 }
		 }
private: System::Void setMainFormSave();
};
}
