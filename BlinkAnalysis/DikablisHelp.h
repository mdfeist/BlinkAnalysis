/**
 * DikablisHelp.h
 * Created By: Michael Feist
 *
 * Manages the GUI for a Dikablis help window.
 */
#pragma once

namespace BlinkAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;
	using namespace System::Reflection;

	/// <summary>
	/// Summary for DikablisHelp
	/// </summary>
	public ref class DikablisHelp : public System::Windows::Forms::Form
	{
	public:
		DikablisHelp(void)
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
		~DikablisHelp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel;
	private: System::Windows::Forms::WebBrowser^  webBrowser;

	protected: 


	protected: 





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
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->webBrowser = (gcnew System::Windows::Forms::WebBrowser());
			this->panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel->Controls->Add(this->webBrowser);
			this->panel->Location = System::Drawing::Point(0, 0);
			this->panel->Name = L"panel";
			this->panel->Padding = System::Windows::Forms::Padding(5);
			this->panel->Size = System::Drawing::Size(584, 562);
			this->panel->TabIndex = 0;
			// 
			// webBrowser
			// 
			this->webBrowser->Dock = System::Windows::Forms::DockStyle::Fill;
			this->webBrowser->Location = System::Drawing::Point(5, 5);
			this->webBrowser->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser->Name = L"webBrowser";
			this->webBrowser->Size = System::Drawing::Size(574, 552);
			this->webBrowser->TabIndex = 0;
			this->webBrowser->Url = (gcnew System::Uri(L"", System::UriKind::Relative));
			// 
			// DikablisHelp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 562);
			this->Controls->Add(this->panel);
			this->MinimumSize = System::Drawing::Size(600, 400);
			this->Name = L"DikablisHelp";
			this->Text = L"Dikablis Help";
			this->Load += gcnew System::EventHandler(this, &DikablisHelp::Form_Load);
			this->panel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void Form_Load(System::Object^  sender, System::EventArgs^  e) {
			String^ path = Path::GetFullPath( "docs/DikablisHelp.htm");
			webBrowser->Navigate("file:///" + path);
		}
};
}
