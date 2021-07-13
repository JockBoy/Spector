#pragma once

#include "GlowItemList.h"
#include <windows.h>
#include <msclr/marshal_cppstd.h>
#include <msclr/gcroot.h>
#include "ConfigUtil.h"
#undef GetTempPath

namespace Spector {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Text;
	using namespace System::Reflection;
	using namespace msclr::interop;
	
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

#pragma region Static variables accessed from threads

		static bool IsEnableItemGlow = false;
		static bool IsEnablePlayerGlow = false;
		static bool IsEnableAimBot = false;
		static bool IsEnableTriggerBot = false;

		static Generic::List<int>^ ItemGlowList1 = gcnew Generic::List<int>();
		static Generic::List<int>^ ItemGlowList2 = gcnew Generic::List<int>();
		static Generic::List<int>^ ItemGlowList3 = gcnew Generic::List<int>();
		static Color IGColor1;
		static Color IGColor2;
		static Color IGColor3;

		static Color PGColorVisible;
		static Color PGColorInvisible;
		static Color PGColorDown;

		static int AimbotFov;
		static float AimbotSmooth;
		static int AimbotAimVirticalOffset;
		static String^ AimbotAimKey = "";

		static int TriggerbotFov;
		static String^ TriggerbotKey = "";

		static float MouseSensitivity;

#pragma endregion

	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::CheckBox^ ItemGlowCheckBox;
	private: System::Windows::Forms::CheckBox^ AimbotCheckBox;
	private: System::Windows::Forms::Label^ CloseLabel;
	private: System::Windows::Forms::Label^ AimbotFovLabel;
	private: System::Windows::Forms::Label^ AimbotSmoothLabel;
	private: System::Windows::Forms::Label^ AimbotAimKeyLabel;
	private: System::Windows::Forms::ComboBox^ AimbotAimKeyBox;
	private: System::Windows::Forms::Label^ AimbotOffsetLabel;
	private: System::Windows::Forms::NumericUpDown^ AimbotSmoothVal;
	private: System::Windows::Forms::NumericUpDown^ AimbotFovVal;
	private: System::Windows::Forms::NumericUpDown^ AimbotOffsetVal;
	private: System::Windows::Forms::CheckBox^ PlayerGlowCheckBox;
	private: System::Windows::Forms::Label^ PlayerGlowVisible;
	private: System::Windows::Forms::Label^ PlayerGlowInvisible;
	private: System::Windows::Forms::Label^ PlayerGlowDown;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::NumericUpDown^ MouseSensitivityVal;
	private: System::Windows::Forms::Label^ MouseSensitivityLabel;
	private: System::Windows::Forms::Label^ WindowColorLabel;
	private: System::Windows::Forms::Label^ WindowColor;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::CheckBox^ TriggerbotCheckBox;
	private: System::Windows::Forms::Label^ TriggerFovLabel;
	private: System::Windows::Forms::NumericUpDown^ TriggerbotFovVal;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ TriggerbotKeyBox;
	private: System::Windows::Forms::GroupBox^ SettingsBox;

		   
	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ColorDialog^ colorDialog;
	private: System::Windows::Forms::ListBox^ itemListBox;
	private: System::Windows::Forms::ListBox^ sListBox3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::ListBox^ sListBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::ListBox^ sListBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ TopBar;
	private: System::Windows::Forms::Label^ RightBar;
	private: System::Windows::Forms::Label^ BottomBar;
	private: System::Windows::Forms::Label^ LeftBar;
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->colorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->sListBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->sListBox2 = (gcnew System::Windows::Forms::ListBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->sListBox3 = (gcnew System::Windows::Forms::ListBox());
			this->itemListBox = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->ItemGlowCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->TopBar = (gcnew System::Windows::Forms::Label());
			this->RightBar = (gcnew System::Windows::Forms::Label());
			this->BottomBar = (gcnew System::Windows::Forms::Label());
			this->LeftBar = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->AimbotOffsetVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->AimbotSmoothVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->AimbotFovVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->AimbotOffsetLabel = (gcnew System::Windows::Forms::Label());
			this->AimbotAimKeyBox = (gcnew System::Windows::Forms::ComboBox());
			this->AimbotAimKeyLabel = (gcnew System::Windows::Forms::Label());
			this->AimbotSmoothLabel = (gcnew System::Windows::Forms::Label());
			this->AimbotFovLabel = (gcnew System::Windows::Forms::Label());
			this->AimbotCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CloseLabel = (gcnew System::Windows::Forms::Label());
			this->SettingsBox = (gcnew System::Windows::Forms::GroupBox());
			this->WindowColor = (gcnew System::Windows::Forms::Label());
			this->WindowColorLabel = (gcnew System::Windows::Forms::Label());
			this->MouseSensitivityVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->MouseSensitivityLabel = (gcnew System::Windows::Forms::Label());
			this->PlayerGlowCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->PlayerGlowVisible = (gcnew System::Windows::Forms::Label());
			this->PlayerGlowInvisible = (gcnew System::Windows::Forms::Label());
			this->PlayerGlowDown = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->TriggerbotKeyBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TriggerbotFovVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->TriggerFovLabel = (gcnew System::Windows::Forms::Label());
			this->TriggerbotCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AimbotOffsetVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AimbotSmoothVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AimbotFovVal))->BeginInit();
			this->SettingsBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MouseSensitivityVal))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TriggerbotFovVal))->BeginInit();
			this->SuspendLayout();
			// 
			// sListBox1
			// 
			this->sListBox1->BackColor = System::Drawing::Color::Black;
			this->sListBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->sListBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->sListBox1->FormattingEnabled = true;
			this->sListBox1->ItemHeight = 12;
			this->sListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"[SelectColor]" });
			this->sListBox1->Location = System::Drawing::Point(181, 18);
			this->sListBox1->Name = L"sListBox1";
			this->sListBox1->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->sListBox1->Size = System::Drawing::Size(97, 50);
			this->sListBox1->TabIndex = 7;
			this->sListBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::sListBox1_MouseClick);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Black;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button4->ForeColor = System::Drawing::Color::DimGray;
			this->button4->Location = System::Drawing::Point(143, 104);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(33, 20);
			this->button4->TabIndex = 4;
			this->button4->Text = L"<-";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Black;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button3->ForeColor = System::Drawing::Color::DimGray;
			this->button3->Location = System::Drawing::Point(143, 78);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(33, 20);
			this->button3->TabIndex = 3;
			this->button3->Text = L"->";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// sListBox2
			// 
			this->sListBox2->BackColor = System::Drawing::Color::Black;
			this->sListBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->sListBox2->ForeColor = System::Drawing::Color::Fuchsia;
			this->sListBox2->FormattingEnabled = true;
			this->sListBox2->ItemHeight = 12;
			this->sListBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"[SelectColor]" });
			this->sListBox2->Location = System::Drawing::Point(181, 76);
			this->sListBox2->Name = L"sListBox2";
			this->sListBox2->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->sListBox2->Size = System::Drawing::Size(97, 50);
			this->sListBox2->TabIndex = 8;
			this->sListBox2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::sListBox2_MouseClick);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Black;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button6->ForeColor = System::Drawing::Color::DimGray;
			this->button6->Location = System::Drawing::Point(143, 161);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(33, 20);
			this->button6->TabIndex = 6;
			this->button6->Text = L"<-";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button1->ForeColor = System::Drawing::Color::DimGray;
			this->button1->Location = System::Drawing::Point(142, 20);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(34, 20);
			this->button1->TabIndex = 1;
			this->button1->Text = L"->";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Black;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::DimGray;
			this->button5->Location = System::Drawing::Point(143, 135);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(33, 20);
			this->button5->TabIndex = 5;
			this->button5->Text = L"->";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Black;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button2->ForeColor = System::Drawing::Color::DimGray;
			this->button2->Location = System::Drawing::Point(142, 46);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(34, 20);
			this->button2->TabIndex = 2;
			this->button2->Text = L"<-";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// sListBox3
			// 
			this->sListBox3->BackColor = System::Drawing::Color::Black;
			this->sListBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->sListBox3->ForeColor = System::Drawing::Color::Aqua;
			this->sListBox3->FormattingEnabled = true;
			this->sListBox3->ItemHeight = 12;
			this->sListBox3->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"[SelectColor]" });
			this->sListBox3->Location = System::Drawing::Point(181, 134);
			this->sListBox3->Name = L"sListBox3";
			this->sListBox3->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->sListBox3->Size = System::Drawing::Size(97, 50);
			this->sListBox3->TabIndex = 9;
			this->sListBox3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::sListBox3_MouseClick);
			// 
			// itemListBox
			// 
			this->itemListBox->BackColor = System::Drawing::Color::Black;
			this->itemListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->itemListBox->ForeColor = System::Drawing::Color::White;
			this->itemListBox->FormattingEnabled = true;
			this->itemListBox->ItemHeight = 12;
			this->itemListBox->Location = System::Drawing::Point(6, 16);
			this->itemListBox->Name = L"itemListBox";
			this->itemListBox->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->itemListBox->Size = System::Drawing::Size(132, 170);
			this->itemListBox->TabIndex = 0;
			this->itemListBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::itemListBox_MouseClick);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Black;
			this->groupBox1->Controls->Add(this->ItemGlowCheckBox);
			this->groupBox1->Controls->Add(this->itemListBox);
			this->groupBox1->Controls->Add(this->sListBox2);
			this->groupBox1->Controls->Add(this->sListBox3);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->sListBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(3, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(284, 191);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"  ";
			// 
			// ItemGlowCheckBox
			// 
			this->ItemGlowCheckBox->AutoSize = true;
			this->ItemGlowCheckBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ItemGlowCheckBox->Location = System::Drawing::Point(12, -2);
			this->ItemGlowCheckBox->Name = L"ItemGlowCheckBox";
			this->ItemGlowCheckBox->Size = System::Drawing::Size(68, 16);
			this->ItemGlowCheckBox->TabIndex = 10;
			this->ItemGlowCheckBox->Text = L"ItemGlow";
			this->ItemGlowCheckBox->UseVisualStyleBackColor = true;
			this->ItemGlowCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::ItemGlowCheckBox_CheckedChanged);
			// 
			// TopBar
			// 
			this->TopBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->TopBar->Dock = System::Windows::Forms::DockStyle::Top;
			this->TopBar->Location = System::Drawing::Point(0, 0);
			this->TopBar->Name = L"TopBar";
			this->TopBar->Size = System::Drawing::Size(291, 19);
			this->TopBar->TabIndex = 11;
			this->TopBar->Text = L" AC/JB PREMIUM CHEESE";
			this->TopBar->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->TopBar->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::TopBar_MouseDown);
			// 
			// RightBar
			// 
			this->RightBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->RightBar->Dock = System::Windows::Forms::DockStyle::Right;
			this->RightBar->Location = System::Drawing::Point(290, 19);
			this->RightBar->Name = L"RightBar";
			this->RightBar->Size = System::Drawing::Size(1, 393);
			this->RightBar->TabIndex = 12;
			// 
			// BottomBar
			// 
			this->BottomBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->BottomBar->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->BottomBar->Location = System::Drawing::Point(0, 411);
			this->BottomBar->Name = L"BottomBar";
			this->BottomBar->Size = System::Drawing::Size(290, 1);
			this->BottomBar->TabIndex = 13;
			// 
			// LeftBar
			// 
			this->LeftBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->LeftBar->Dock = System::Windows::Forms::DockStyle::Left;
			this->LeftBar->Location = System::Drawing::Point(0, 19);
			this->LeftBar->Name = L"LeftBar";
			this->LeftBar->Size = System::Drawing::Size(1, 392);
			this->LeftBar->TabIndex = 14;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->AimbotOffsetVal);
			this->groupBox3->Controls->Add(this->AimbotSmoothVal);
			this->groupBox3->Controls->Add(this->AimbotFovVal);
			this->groupBox3->Controls->Add(this->AimbotOffsetLabel);
			this->groupBox3->Controls->Add(this->AimbotAimKeyBox);
			this->groupBox3->Controls->Add(this->AimbotAimKeyLabel);
			this->groupBox3->Controls->Add(this->AimbotSmoothLabel);
			this->groupBox3->Controls->Add(this->AimbotFovLabel);
			this->groupBox3->Controls->Add(this->AimbotCheckBox);
			this->groupBox3->ForeColor = System::Drawing::Color::White;
			this->groupBox3->Location = System::Drawing::Point(3, 258);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(284, 62);
			this->groupBox3->TabIndex = 16;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"  ";
			// 
			// AimbotOffsetVal
			// 
			this->AimbotOffsetVal->BackColor = System::Drawing::Color::Black;
			this->AimbotOffsetVal->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->AimbotOffsetVal->ForeColor = System::Drawing::Color::White;
			this->AimbotOffsetVal->Location = System::Drawing::Point(208, 12);
			this->AimbotOffsetVal->Name = L"AimbotOffsetVal";
			this->AimbotOffsetVal->Size = System::Drawing::Size(55, 19);
			this->AimbotOffsetVal->TabIndex = 12;
			this->AimbotOffsetVal->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->AimbotOffsetVal->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 45, 0, 0, 0 });
			this->AimbotOffsetVal->ValueChanged += gcnew System::EventHandler(this, &MainForm::AimbotOffsetVal_ValueChanged);
			// 
			// AimbotSmoothVal
			// 
			this->AimbotSmoothVal->BackColor = System::Drawing::Color::Black;
			this->AimbotSmoothVal->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->AimbotSmoothVal->DecimalPlaces = 1;
			this->AimbotSmoothVal->ForeColor = System::Drawing::Color::White;
			this->AimbotSmoothVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->AimbotSmoothVal->Location = System::Drawing::Point(73, 37);
			this->AimbotSmoothVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->AimbotSmoothVal->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->AimbotSmoothVal->Name = L"AimbotSmoothVal";
			this->AimbotSmoothVal->Size = System::Drawing::Size(55, 19);
			this->AimbotSmoothVal->TabIndex = 11;
			this->AimbotSmoothVal->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->AimbotSmoothVal->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->AimbotSmoothVal->ValueChanged += gcnew System::EventHandler(this, &MainForm::AimbotSmoothVal_ValueChanged);
			// 
			// AimbotFovVal
			// 
			this->AimbotFovVal->BackColor = System::Drawing::Color::Black;
			this->AimbotFovVal->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->AimbotFovVal->ForeColor = System::Drawing::Color::White;
			this->AimbotFovVal->Location = System::Drawing::Point(73, 13);
			this->AimbotFovVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->AimbotFovVal->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->AimbotFovVal->Name = L"AimbotFovVal";
			this->AimbotFovVal->Size = System::Drawing::Size(55, 19);
			this->AimbotFovVal->TabIndex = 10;
			this->AimbotFovVal->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->AimbotFovVal->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			this->AimbotFovVal->ValueChanged += gcnew System::EventHandler(this, &MainForm::AimbotFovVal_ValueChanged);
			// 
			// AimbotOffsetLabel
			// 
			this->AimbotOffsetLabel->AutoSize = true;
			this->AimbotOffsetLabel->Location = System::Drawing::Point(143, 15);
			this->AimbotOffsetLabel->Name = L"AimbotOffsetLabel";
			this->AimbotOffsetLabel->Size = System::Drawing::Size(63, 12);
			this->AimbotOffsetLabel->TabIndex = 9;
			this->AimbotOffsetLabel->Text = L"AimOffset :";
			// 
			// AimbotAimKeyBox
			// 
			this->AimbotAimKeyBox->BackColor = System::Drawing::Color::Black;
			this->AimbotAimKeyBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AimbotAimKeyBox->ForeColor = System::Drawing::Color::White;
			this->AimbotAimKeyBox->FormattingEnabled = true;
			this->AimbotAimKeyBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Left", L"Right", L"Both" });
			this->AimbotAimKeyBox->Location = System::Drawing::Point(208, 36);
			this->AimbotAimKeyBox->Name = L"AimbotAimKeyBox";
			this->AimbotAimKeyBox->Size = System::Drawing::Size(55, 20);
			this->AimbotAimKeyBox->TabIndex = 8;
			this->AimbotAimKeyBox->Text = L"Both";
			this->AimbotAimKeyBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::AimbotAimKeyBox_SelectedIndexChanged);
			// 
			// AimbotAimKeyLabel
			// 
			this->AimbotAimKeyLabel->AutoSize = true;
			this->AimbotAimKeyLabel->Location = System::Drawing::Point(157, 40);
			this->AimbotAimKeyLabel->Name = L"AimbotAimKeyLabel";
			this->AimbotAimKeyLabel->Size = System::Drawing::Size(49, 12);
			this->AimbotAimKeyLabel->TabIndex = 7;
			this->AimbotAimKeyLabel->Text = L"Aimkey :";
			// 
			// AimbotSmoothLabel
			// 
			this->AimbotSmoothLabel->AutoSize = true;
			this->AimbotSmoothLabel->Location = System::Drawing::Point(21, 39);
			this->AimbotSmoothLabel->Name = L"AimbotSmoothLabel";
			this->AimbotSmoothLabel->Size = System::Drawing::Size(49, 12);
			this->AimbotSmoothLabel->TabIndex = 4;
			this->AimbotSmoothLabel->Text = L"Smooth :";
			// 
			// AimbotFovLabel
			// 
			this->AimbotFovLabel->AutoSize = true;
			this->AimbotFovLabel->Location = System::Drawing::Point(36, 18);
			this->AimbotFovLabel->Name = L"AimbotFovLabel";
			this->AimbotFovLabel->Size = System::Drawing::Size(34, 12);
			this->AimbotFovLabel->TabIndex = 1;
			this->AimbotFovLabel->Text = L"FOV :";
			// 
			// AimbotCheckBox
			// 
			this->AimbotCheckBox->AutoSize = true;
			this->AimbotCheckBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AimbotCheckBox->Location = System::Drawing::Point(12, -2);
			this->AimbotCheckBox->Name = L"AimbotCheckBox";
			this->AimbotCheckBox->Size = System::Drawing::Size(59, 16);
			this->AimbotCheckBox->TabIndex = 0;
			this->AimbotCheckBox->Text = L"AimBot";
			this->AimbotCheckBox->UseVisualStyleBackColor = true;
			this->AimbotCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AimbotCheckBox_CheckedChanged);
			// 
			// CloseLabel
			// 
			this->CloseLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->CloseLabel->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->CloseLabel->ForeColor = System::Drawing::Color::Black;
			this->CloseLabel->Location = System::Drawing::Point(272, 1);
			this->CloseLabel->Name = L"CloseLabel";
			this->CloseLabel->Size = System::Drawing::Size(19, 18);
			this->CloseLabel->TabIndex = 17;
			this->CloseLabel->Text = L"~";
			this->CloseLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->CloseLabel->Click += gcnew System::EventHandler(this, &MainForm::CloseLabel_Click);
			// 
			// SettingsBox
			// 
			this->SettingsBox->BackColor = System::Drawing::Color::Black;
			this->SettingsBox->Controls->Add(this->WindowColor);
			this->SettingsBox->Controls->Add(this->WindowColorLabel);
			this->SettingsBox->Controls->Add(this->MouseSensitivityVal);
			this->SettingsBox->Controls->Add(this->MouseSensitivityLabel);
			this->SettingsBox->ForeColor = System::Drawing::Color::White;
			this->SettingsBox->Location = System::Drawing::Point(3, 371);
			this->SettingsBox->Name = L"SettingsBox";
			this->SettingsBox->Size = System::Drawing::Size(284, 37);
			this->SettingsBox->TabIndex = 18;
			this->SettingsBox->TabStop = false;
			this->SettingsBox->Text = L" Settings ";
			// 
			// WindowColor
			// 
			this->WindowColor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->WindowColor->Location = System::Drawing::Point(91, 15);
			this->WindowColor->Name = L"WindowColor";
			this->WindowColor->Size = System::Drawing::Size(27, 12);
			this->WindowColor->TabIndex = 3;
			this->WindowColor->Click += gcnew System::EventHandler(this, &MainForm::WindowColor_Click);
			// 
			// WindowColorLabel
			// 
			this->WindowColorLabel->AutoSize = true;
			this->WindowColorLabel->Location = System::Drawing::Point(13, 15);
			this->WindowColorLabel->Name = L"WindowColorLabel";
			this->WindowColorLabel->Size = System::Drawing::Size(76, 12);
			this->WindowColorLabel->TabIndex = 2;
			this->WindowColorLabel->Text = L"WindowColor :";
			// 
			// MouseSensitivityVal
			// 
			this->MouseSensitivityVal->BackColor = System::Drawing::Color::Black;
			this->MouseSensitivityVal->DecimalPlaces = 1;
			this->MouseSensitivityVal->ForeColor = System::Drawing::Color::White;
			this->MouseSensitivityVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->MouseSensitivityVal->Location = System::Drawing::Point(231, 12);
			this->MouseSensitivityVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->MouseSensitivityVal->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 65536 });
			this->MouseSensitivityVal->Name = L"MouseSensitivityVal";
			this->MouseSensitivityVal->Size = System::Drawing::Size(40, 19);
			this->MouseSensitivityVal->TabIndex = 1;
			this->MouseSensitivityVal->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->MouseSensitivityVal->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 40, 0, 0, 65536 });
			this->MouseSensitivityVal->ValueChanged += gcnew System::EventHandler(this, &MainForm::MouseSensitivityVal_ValueChanged);
			// 
			// MouseSensitivityLabel
			// 
			this->MouseSensitivityLabel->AutoSize = true;
			this->MouseSensitivityLabel->Location = System::Drawing::Point(128, 15);
			this->MouseSensitivityLabel->Name = L"MouseSensitivityLabel";
			this->MouseSensitivityLabel->Size = System::Drawing::Size(102, 12);
			this->MouseSensitivityLabel->TabIndex = 0;
			this->MouseSensitivityLabel->Text = L"Mouse Sensitivity :";
			// 
			// PlayerGlowCheckBox
			// 
			this->PlayerGlowCheckBox->AutoSize = true;
			this->PlayerGlowCheckBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PlayerGlowCheckBox->Location = System::Drawing::Point(12, -2);
			this->PlayerGlowCheckBox->Name = L"PlayerGlowCheckBox";
			this->PlayerGlowCheckBox->Size = System::Drawing::Size(78, 16);
			this->PlayerGlowCheckBox->TabIndex = 0;
			this->PlayerGlowCheckBox->Text = L"PlayerGlow";
			this->PlayerGlowCheckBox->UseVisualStyleBackColor = true;
			this->PlayerGlowCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::PlayerGlowCheckBox_CheckedChanged);
			// 
			// PlayerGlowVisible
			// 
			this->PlayerGlowVisible->AutoSize = true;
			this->PlayerGlowVisible->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PlayerGlowVisible->ForeColor = System::Drawing::Color::Lime;
			this->PlayerGlowVisible->Location = System::Drawing::Point(16, 16);
			this->PlayerGlowVisible->Name = L"PlayerGlowVisible";
			this->PlayerGlowVisible->Size = System::Drawing::Size(83, 12);
			this->PlayerGlowVisible->TabIndex = 1;
			this->PlayerGlowVisible->Text = L"¡ VisibleColor";
			this->PlayerGlowVisible->Click += gcnew System::EventHandler(this, &MainForm::PlayerGlowVisible_Click);
			// 
			// PlayerGlowInvisible
			// 
			this->PlayerGlowInvisible->AutoSize = true;
			this->PlayerGlowInvisible->ForeColor = System::Drawing::Color::Red;
			this->PlayerGlowInvisible->Location = System::Drawing::Point(102, 16);
			this->PlayerGlowInvisible->Name = L"PlayerGlowInvisible";
			this->PlayerGlowInvisible->Size = System::Drawing::Size(90, 12);
			this->PlayerGlowInvisible->TabIndex = 2;
			this->PlayerGlowInvisible->Text = L"¡ InvisibleColor";
			this->PlayerGlowInvisible->Click += gcnew System::EventHandler(this, &MainForm::PlayerGlowInvisible_Click);
			// 
			// PlayerGlowDown
			// 
			this->PlayerGlowDown->AutoSize = true;
			this->PlayerGlowDown->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->PlayerGlowDown->Location = System::Drawing::Point(195, 16);
			this->PlayerGlowDown->Name = L"PlayerGlowDown";
			this->PlayerGlowDown->Size = System::Drawing::Size(76, 12);
			this->PlayerGlowDown->TabIndex = 3;
			this->PlayerGlowDown->Text = L"¡ DownColor";
			this->PlayerGlowDown->Click += gcnew System::EventHandler(this, &MainForm::PlayerGlowDown_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->PlayerGlowDown);
			this->groupBox2->Controls->Add(this->PlayerGlowInvisible);
			this->groupBox2->Controls->Add(this->PlayerGlowVisible);
			this->groupBox2->Controls->Add(this->PlayerGlowCheckBox);
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(3, 218);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(284, 37);
			this->groupBox2->TabIndex = 15;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"  ";
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::Color::Black;
			this->groupBox4->Controls->Add(this->TriggerbotKeyBox);
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->Controls->Add(this->TriggerbotFovVal);
			this->groupBox4->Controls->Add(this->TriggerFovLabel);
			this->groupBox4->Controls->Add(this->TriggerbotCheckBox);
			this->groupBox4->ForeColor = System::Drawing::Color::White;
			this->groupBox4->Location = System::Drawing::Point(3, 324);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(284, 44);
			this->groupBox4->TabIndex = 19;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L" ";
			// 
			// TriggerbotKeyBox
			// 
			this->TriggerbotKeyBox->BackColor = System::Drawing::Color::Black;
			this->TriggerbotKeyBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->TriggerbotKeyBox->ForeColor = System::Drawing::Color::White;
			this->TriggerbotKeyBox->FormattingEnabled = true;
			this->TriggerbotKeyBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Right", L"Always" });
			this->TriggerbotKeyBox->Location = System::Drawing::Point(208, 16);
			this->TriggerbotKeyBox->Name = L"TriggerbotKeyBox";
			this->TriggerbotKeyBox->Size = System::Drawing::Size(55, 20);
			this->TriggerbotKeyBox->TabIndex = 6;
			this->TriggerbotKeyBox->Text = L"Always";
			this->TriggerbotKeyBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::TriggerbotKeyBox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(143, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 12);
			this->label1->TabIndex = 4;
			this->label1->Text = L"ActiveKey :";
			// 
			// TriggerbotFovVal
			// 
			this->TriggerbotFovVal->BackColor = System::Drawing::Color::Black;
			this->TriggerbotFovVal->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TriggerbotFovVal->ForeColor = System::Drawing::Color::White;
			this->TriggerbotFovVal->Location = System::Drawing::Point(73, 16);
			this->TriggerbotFovVal->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->TriggerbotFovVal->Name = L"TriggerbotFovVal";
			this->TriggerbotFovVal->Size = System::Drawing::Size(55, 19);
			this->TriggerbotFovVal->TabIndex = 2;
			this->TriggerbotFovVal->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TriggerbotFovVal->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->TriggerbotFovVal->ValueChanged += gcnew System::EventHandler(this, &MainForm::TriggerbotFovVal_ValueChanged);
			// 
			// TriggerFovLabel
			// 
			this->TriggerFovLabel->AutoSize = true;
			this->TriggerFovLabel->BackColor = System::Drawing::Color::Black;
			this->TriggerFovLabel->ForeColor = System::Drawing::Color::White;
			this->TriggerFovLabel->Location = System::Drawing::Point(37, 21);
			this->TriggerFovLabel->Name = L"TriggerFovLabel";
			this->TriggerFovLabel->Size = System::Drawing::Size(34, 12);
			this->TriggerFovLabel->TabIndex = 1;
			this->TriggerFovLabel->Text = L"FOV :";
			// 
			// TriggerbotCheckBox
			// 
			this->TriggerbotCheckBox->AutoSize = true;
			this->TriggerbotCheckBox->BackColor = System::Drawing::Color::Black;
			this->TriggerbotCheckBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->TriggerbotCheckBox->ForeColor = System::Drawing::Color::White;
			this->TriggerbotCheckBox->Location = System::Drawing::Point(12, -2);
			this->TriggerbotCheckBox->Name = L"TriggerbotCheckBox";
			this->TriggerbotCheckBox->Size = System::Drawing::Size(75, 16);
			this->TriggerbotCheckBox->TabIndex = 0;
			this->TriggerbotCheckBox->Text = L"TriggerBot";
			this->TriggerbotCheckBox->UseVisualStyleBackColor = false;
			this->TriggerbotCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::TriggerbotCheckBox_CheckedChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(291, 412);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->SettingsBox);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->CloseLabel);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->LeftBar);
			this->Controls->Add(this->BottomBar);
			this->Controls->Add(this->RightBar);
			this->Controls->Add(this->TopBar);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AimbotOffsetVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AimbotSmoothVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AimbotFovVal))->EndInit();
			this->SettingsBox->ResumeLayout(false);
			this->SettingsBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MouseSensitivityVal))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TriggerbotFovVal))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion


#pragma region Utility Functions

	private: System::Void ReleaseSelect(ListBox^ box) {
		if (box->SelectedIndex == -1) return;
		IEnumerator^ iEnum = box->SelectedIndices->GetEnumerator();
		std::vector<int> indexes;
		while (iEnum->MoveNext()) {
			indexes.push_back(safe_cast<int>(iEnum->Current));
		}
		for (const auto& index : indexes) {
			box->SetSelected(index, false);
		}
	}

	private: System::Void SelectColorItemGlow(ListBox^ box) {
		if (box->SelectedIndex != 0) return;
		if (colorDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			box->ForeColor = colorDialog->Color;
		}
		box->SetSelected(0, false);
	}

	private: System::Void SelectColorPlayerGlow(Label^ label) {
		if (colorDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			label->ForeColor = colorDialog->Color;
		}
	}

	private: System::Void SetWindowColor(Color color) {
		TopBar->BackColor = color;
		LeftBar->BackColor = color;
		RightBar->BackColor = color;
		BottomBar->BackColor = color;
		CloseLabel->BackColor = color;
		WindowColor->BackColor = color;
	}
	
	private: System::Void MoveItems(ListBox^ src, ListBox^ dst) {
		if (src->SelectedIndex == -1) return;
		IEnumerator^ iEnum = src->SelectedItems->GetEnumerator();
		std::vector<std::string> items;
		while (iEnum->MoveNext()) {
			items.push_back(marshal_as<std::string>(iEnum->Current->ToString()));
		}
		for (std::string item : items) {
			if (item == "[SelectColor]") continue;
			System::String^ str = marshal_as<System::String^>(item);
			dst->Items->Add(str);
			src->Items->Remove(str);
		}
	}

	private: System::Void UpdateItemGlowList(ListBox^ box, Generic::List<int>^ itemList) {
		itemList->Clear();
		if (box->Items->Count <= 1) return;
		IEnumerator^ iEnum = box->Items->GetEnumerator();
		std::vector<std::string> items;
		while (iEnum->MoveNext()) {
			items.push_back(marshal_as<std::string>(iEnum->Current->ToString()));
		}
		for (std::string item : items) {
			if (item == "[SelectColor]") continue;
			itemList->Add(GetItemIndex(item));
		}
	}

	private: int GetItemIndex(std::string str) {
		for (Item_t item : GlowItems) {
			if (item.itemName == str) {
				return item.itemId;
			}
		}
	}

	private: auto GetResourceFontData(System::String^ name) {
		PrivateFontCollection^ privateFont = gcnew PrivateFontCollection();
		IO::Stream^ fontStream = Assembly::GetExecutingAssembly()->
			GetManifestResourceStream(name);
		cli::array<Byte>^ fontData = gcnew cli::array<Byte>(fontStream->Length);
		fontStream->Read(fontData, 0, (int)fontStream->Length);
		fontStream->Close();
		pin_ptr<Byte> fontAddress = &fontData[0];
		DWORD fnum = 0;
		AddFontMemResourceEx(fontAddress, fontData->Length, NULL, &fnum); // :)
		privateFont->AddMemoryFont((IntPtr)fontAddress, fontData->Length);
		return safe_cast<FontFamily^>(privateFont->Families[0]);
	}

	private: System::Void ListToStringArray(ListBox^ src, Generic::List<String^>^ dst) {
		IEnumerator^ iEnum = src->Items->GetEnumerator();
		while (iEnum->MoveNext()) {
			String^ line = iEnum->Current->ToString();
			if (line == "[SelectColor]") continue;
			dst->Add(line);
		}
	}

	private: System::Void StringArrayToList( Generic::List<String^>^ src, ListBox^ dst) {
		IEnumerator^ iEnum = src->GetEnumerator();
		while (iEnum->MoveNext()) {
			dst->Items->Add(iEnum->Current);
		}
	}

#pragma endregion


#pragma region MainForm Control Events

	private: System::Void TopBar_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		HWND hWnd = reinterpret_cast<HWND>(this->Handle.ToPointer());
		ReleaseCapture();
		SendMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);
	}

	private: System::Void CloseLabel_Click(System::Object^ sender, System::EventArgs^ e) {
		ConfigUtil^ xml = gcnew ConfigUtil("config.xml");
		Config^ conf = gcnew Config();


		ListToStringArray(itemListBox, conf->IGlow_StockList);
		ListToStringArray(sListBox1, conf->IGlow1_List);
		ListToStringArray(sListBox2, conf->IGlow2_List);
		ListToStringArray(sListBox3, conf->IGlow3_List);

		conf->IGlow1_ColorR = sListBox1->ForeColor.R;
		conf->IGlow1_ColorG = sListBox1->ForeColor.G;
		conf->IGlow1_ColorB = sListBox1->ForeColor.B;
		conf->IGlow2_ColorR = sListBox2->ForeColor.R;
		conf->IGlow2_ColorG = sListBox2->ForeColor.G;
		conf->IGlow2_ColorB = sListBox2->ForeColor.B;
		conf->IGlow3_ColorR = sListBox3->ForeColor.R;
		conf->IGlow3_ColorG = sListBox3->ForeColor.G;
		conf->IGlow3_ColorB = sListBox3->ForeColor.B;

		conf->PGlow_Visible_ColorR = PlayerGlowVisible->ForeColor.R;
		conf->PGlow_Visible_ColorG = PlayerGlowVisible->ForeColor.G;
		conf->PGlow_Visible_ColorB = PlayerGlowVisible->ForeColor.B;
		conf->PGlow_Invisible_ColorR = PlayerGlowInvisible->ForeColor.R;
		conf->PGlow_Invisible_ColorG = PlayerGlowInvisible->ForeColor.G;
		conf->PGlow_Invisible_ColorB = PlayerGlowInvisible->ForeColor.B;
		conf->PGlow_Down_ColorR = PlayerGlowDown->ForeColor.R;
		conf->PGlow_Down_ColorG = PlayerGlowDown->ForeColor.G;
		conf->PGlow_Down_ColorB = PlayerGlowDown->ForeColor.B;

		conf->Aimbot_Fov = AimbotFovVal->Value;
		conf->Aimbot_Smooth = AimbotSmoothVal->Value;
		conf->Aimbot_Offset = AimbotOffsetVal->Value;
		conf->Aimbot_AimKey = AimbotAimKeyBox->Text;

		conf->Triggerbot_Fov = TriggerbotFovVal->Value;
		conf->Triggerbot_Key = TriggerbotKeyBox->Text;

		conf->WindowColor_R = WindowColor->BackColor.R;
		conf->WindowColor_G = WindowColor->BackColor.G;
		conf->WindowColor_B = WindowColor->BackColor.B;
		conf->MouseSensitivity = MouseSensitivityVal->Value;

		xml->Save(conf);
		MainForm::Close();
	}
	
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			String^ tmpDir = System::IO::Path::GetTempPath();
			//System::Net::WebClient^ webClient = gcnew System::Net::WebClient();
			//webClient->DownloadFile("http://jbserver.ddo.jp/key.lic", tmpDir + "key.lic");
		}
		catch (System::Exception^ e)
		{
			MainForm::Close();
			return;
		}

		ConfigUtil^ xml = gcnew ConfigUtil("config.xml");
		Config^ conf = xml->Load();

		if (!conf->isLoadError) {
			StringArrayToList(conf->IGlow_StockList, itemListBox);
			StringArrayToList(conf->IGlow1_List, sListBox1);
			StringArrayToList(conf->IGlow2_List, sListBox2);
			StringArrayToList(conf->IGlow3_List, sListBox3);
			sListBox1->ForeColor = Color::FromArgb(conf->IGlow1_ColorR, conf->IGlow1_ColorG, conf->IGlow1_ColorB);
			sListBox2->ForeColor = Color::FromArgb(conf->IGlow2_ColorR, conf->IGlow2_ColorG, conf->IGlow2_ColorB);
			sListBox3->ForeColor = Color::FromArgb(conf->IGlow3_ColorR, conf->IGlow3_ColorG, conf->IGlow3_ColorB);
			PlayerGlowVisible->ForeColor = Color::FromArgb(conf->PGlow_Visible_ColorR, conf->PGlow_Visible_ColorG, conf->PGlow_Visible_ColorB);
			PlayerGlowInvisible->ForeColor = Color::FromArgb(conf->PGlow_Invisible_ColorR, conf->PGlow_Invisible_ColorG, conf->PGlow_Invisible_ColorB);
			PlayerGlowDown->ForeColor = Color::FromArgb(conf->PGlow_Down_ColorR, conf->PGlow_Down_ColorG, conf->PGlow_Down_ColorB);
			AimbotFovVal->Value = conf->Aimbot_Fov;
			AimbotSmoothVal->Value = conf->Aimbot_Smooth;
			AimbotOffsetVal->Value = conf->Aimbot_Offset;
			AimbotAimKeyBox->Text = conf->Aimbot_AimKey;
			TriggerbotFovVal->Value = conf->Triggerbot_Fov;
			TriggerbotKeyBox->Text = conf->Triggerbot_Key;
			SetWindowColor(Color::FromArgb(conf->WindowColor_R, conf->WindowColor_G, conf->WindowColor_B));
			MouseSensitivityVal->Value = conf->MouseSensitivity;
		}
		else {
			for (Item_t item : GlowItems) {
				System::String^ str = marshal_as<System::String^>(item.itemName);
				itemListBox->Items->Add(str);
			}
		}
		
		/* Initialize Variable */
		IsEnableItemGlow = ItemGlowCheckBox->Checked;
		IsEnablePlayerGlow = PlayerGlowCheckBox->Checked;
		IsEnableAimBot = AimbotCheckBox->Checked;
		IsEnableTriggerBot = TriggerbotCheckBox->Checked;

		UpdateItemGlowList(sListBox1, ItemGlowList1);
		UpdateItemGlowList(sListBox2, ItemGlowList2);
		UpdateItemGlowList(sListBox3, ItemGlowList3);

		IGColor1 = sListBox1->ForeColor;
		IGColor2 = sListBox2->ForeColor;
		IGColor3 = sListBox3->ForeColor;

		PGColorVisible = PlayerGlowVisible->ForeColor;
		PGColorInvisible = PlayerGlowInvisible->ForeColor;
		PGColorDown = PlayerGlowDown->ForeColor;

		AimbotFov = (int)AimbotFovVal->Value;
		AimbotSmooth = (float)AimbotSmoothVal->Value;
		AimbotAimVirticalOffset = (int)AimbotOffsetVal->Value;
		AimbotAimKey = AimbotAimKeyBox->Text;
		
		TriggerbotFov = (int)TriggerbotFovVal->Value;
		TriggerbotKey = TriggerbotKeyBox->Text;

		MouseSensitivity = (float)MouseSensitivityVal->Value;
		/* ------------------- */

	}

	private: System::Void MainForm_Shown(System::Object^ sender, System::EventArgs^ e) {
		/* Set Custom Font /
		auto FontData = GetResourceFontData("PixelMplus10-Regular.ttf");
		auto Font_x9 = gcnew Drawing::Font(FontData, 9.0F, FontStyle::Regular);
		auto Font_x10 = gcnew Drawing::Font(FontData, 11.0F, FontStyle::Regular);
		
		TopBar->Font = Font_x10;
		ItemGlowCheckBox->Font = Font_x9;
		PlayerGlowCheckBox->Font = Font_x9;
		AimbotCheckBox->Font = Font_x9;
		itemListBox->Font = Font_x9;
		sListBox1->Font = Font_x9;
		sListBox2->Font = Font_x9;
		sListBox3->Font = Font_x9;
		PlayerGlowVisible->Font = Font_x9;
		PlayerGlowInvisible->Font = Font_x9;
		PlayerGlowDown->Font = Font_x9;
		AimbotCheckBox->Font = Font_x9;
		AimbotFovLabel->Font = Font_x9;
		AimbotFovVal->Font = Font_x9;
		AimbotOffsetLabel->Font = Font_x9;
		AimbotOffsetVal->Font = Font_x9;
		AimbotSmoothLabel->Font = Font_x9;
		AimbotSmoothVal->Font = Font_x9;
		AimbotAimKeyLabel->Font = Font_x9;
		AimbotAimKeyBox->Font = Font_x9;
		/* --------------- */
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MoveItems(itemListBox, sListBox1);
		UpdateItemGlowList(sListBox1, ItemGlowList1);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MoveItems(sListBox1, itemListBox);
		UpdateItemGlowList(sListBox1, ItemGlowList1);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		MoveItems(itemListBox, sListBox2);
		UpdateItemGlowList(sListBox2, ItemGlowList2);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		MoveItems(sListBox2, itemListBox);
		UpdateItemGlowList(sListBox2, ItemGlowList2);
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		MoveItems(itemListBox, sListBox3);
		UpdateItemGlowList(sListBox3, ItemGlowList3);
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		MoveItems(sListBox3, itemListBox);
		UpdateItemGlowList(sListBox3, ItemGlowList3);
	}

	private: System::Void itemListBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		ReleaseSelect(sListBox1);
		ReleaseSelect(sListBox2);
		ReleaseSelect(sListBox3);
	}
	private: System::Void sListBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		ReleaseSelect(itemListBox);
		ReleaseSelect(sListBox2);
		ReleaseSelect(sListBox3);
		SelectColorItemGlow(sListBox1);
		IGColor1 = sListBox1->ForeColor;
	}
	private: System::Void sListBox2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		ReleaseSelect(itemListBox);
		ReleaseSelect(sListBox1);
		ReleaseSelect(sListBox3);
		SelectColorItemGlow(sListBox2);
		IGColor2 = sListBox2->ForeColor;
	}
	private: System::Void sListBox3_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		ReleaseSelect(itemListBox);
		ReleaseSelect(sListBox1);
		ReleaseSelect(sListBox2);
		SelectColorItemGlow(sListBox3);
		IGColor3 = sListBox3->ForeColor;
	}
	
	private: System::Void ItemGlowCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		IsEnableItemGlow = ItemGlowCheckBox->Checked;
	}
	private: System::Void PlayerGlowCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		IsEnablePlayerGlow = PlayerGlowCheckBox->Checked;
	}
	private: System::Void AimbotCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		IsEnableAimBot = AimbotCheckBox->Checked;
	}
	private: System::Void TriggerbotCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		IsEnableTriggerBot = TriggerbotCheckBox->Checked;
	}
	private: System::Void PlayerGlowVisible_Click(System::Object^ sender, System::EventArgs^ e) {
		SelectColorPlayerGlow(PlayerGlowVisible);
		PGColorVisible = PlayerGlowVisible->ForeColor;
	}
	private: System::Void PlayerGlowInvisible_Click(System::Object^ sender, System::EventArgs^ e) {
		SelectColorPlayerGlow(PlayerGlowInvisible);
		PGColorInvisible = PlayerGlowInvisible->ForeColor;
	}
	private: System::Void PlayerGlowDown_Click(System::Object^ sender, System::EventArgs^ e) {
		SelectColorPlayerGlow(PlayerGlowDown);
		PGColorDown = PlayerGlowDown->ForeColor;
	}
	private: System::Void AimbotFovVal_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		AimbotFov = (int)AimbotFovVal->Value;
	}
	private: System::Void AimbotSmoothVal_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		AimbotSmooth = (float)AimbotSmoothVal->Value;
	}
	private: System::Void AimbotOffsetVal_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		AimbotAimVirticalOffset = (int)AimbotOffsetVal->Value;
	}
	private: System::Void AimbotAimKeyBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		AimbotAimKey = AimbotAimKeyBox->Text;
	}
	private: System::Void TriggerbotFovVal_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		TriggerbotFov = (int)TriggerbotFovVal->Value;
	}
	private: System::Void TriggerbotKeyBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		TriggerbotKey = TriggerbotKeyBox->Text;
	}
	private: System::Void WindowColor_Click(System::Object^ sender, System::EventArgs^ e) {
		if (colorDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			WindowColor->BackColor = colorDialog->Color;
		}
		SetWindowColor(WindowColor->BackColor);
	}
	private: System::Void MouseSensitivityVal_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		MouseSensitivity = (float)MouseSensitivityVal->Value;
	}
#pragma endregion
};
}
