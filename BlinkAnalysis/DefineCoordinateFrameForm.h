#pragma once

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
	private: System::Windows::Forms::TabPage^  dataPage;

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
			this->dataPage = (gcnew System::Windows::Forms::TabPage());
			this->CoordinateFramePages->SuspendLayout();
			this->SuspendLayout();
			// 
			// CoordinateFramePages
			// 
			this->CoordinateFramePages->Controls->Add(this->infoPage);
			this->CoordinateFramePages->Controls->Add(this->dataPage);
			this->CoordinateFramePages->Location = System::Drawing::Point(0, 0);
			this->CoordinateFramePages->Name = L"CoordinateFramePages";
			this->CoordinateFramePages->SelectedIndex = 0;
			this->CoordinateFramePages->Size = System::Drawing::Size(284, 263);
			this->CoordinateFramePages->TabIndex = 0;
			// 
			// infoPage
			// 
			this->infoPage->Location = System::Drawing::Point(4, 22);
			this->infoPage->Name = L"infoPage";
			this->infoPage->Padding = System::Windows::Forms::Padding(3);
			this->infoPage->Size = System::Drawing::Size(276, 237);
			this->infoPage->TabIndex = 0;
			this->infoPage->Text = L"Info";
			this->infoPage->UseVisualStyleBackColor = true;
			// 
			// dataPage
			// 
			this->dataPage->Location = System::Drawing::Point(4, 22);
			this->dataPage->Name = L"dataPage";
			this->dataPage->Padding = System::Windows::Forms::Padding(3);
			this->dataPage->Size = System::Drawing::Size(192, 74);
			this->dataPage->TabIndex = 1;
			this->dataPage->Text = L"Data";
			this->dataPage->UseVisualStyleBackColor = true;
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
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void DefineCoordinateFrameForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}
