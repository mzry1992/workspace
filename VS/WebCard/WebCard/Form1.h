#pragma once

namespace WebCard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  pwd1;
	protected: 
	private: System::Windows::Forms::Button^  b_getres;
	private: System::Windows::Forms::Button^  b_clear;
	private: System::Windows::Forms::Button^  b_quit;
	private: System::Windows::Forms::TextBox^  pwd2;
	private: System::Windows::Forms::TextBox^  pwd3;
	private: System::Windows::Forms::TextBox^  res1;
	private: System::Windows::Forms::TextBox^  res2;
	private: System::Windows::Forms::TextBox^  res3;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->pwd1 = (gcnew System::Windows::Forms::TextBox());
			this->b_getres = (gcnew System::Windows::Forms::Button());
			this->b_clear = (gcnew System::Windows::Forms::Button());
			this->b_quit = (gcnew System::Windows::Forms::Button());
			this->pwd2 = (gcnew System::Windows::Forms::TextBox());
			this->pwd3 = (gcnew System::Windows::Forms::TextBox());
			this->res1 = (gcnew System::Windows::Forms::TextBox());
			this->res2 = (gcnew System::Windows::Forms::TextBox());
			this->res3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// pwd1
			// 
			this->pwd1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->pwd1->Location = System::Drawing::Point(12, 12);
			this->pwd1->Name = L"pwd1";
			this->pwd1->Size = System::Drawing::Size(60, 54);
			this->pwd1->TabIndex = 0;
			// 
			// b_getres
			// 
			this->b_getres->Location = System::Drawing::Point(12, 72);
			this->b_getres->Name = L"b_getres";
			this->b_getres->Size = System::Drawing::Size(60, 22);
			this->b_getres->TabIndex = 3;
			this->b_getres->Text = L"OK";
			this->b_getres->UseVisualStyleBackColor = true;
			this->b_getres->Click += gcnew System::EventHandler(this, &Form1::b_getres_Click);
			// 
			// b_clear
			// 
			this->b_clear->Location = System::Drawing::Point(78, 72);
			this->b_clear->Name = L"b_clear";
			this->b_clear->Size = System::Drawing::Size(60, 22);
			this->b_clear->TabIndex = 4;
			this->b_clear->Text = L"Clear";
			this->b_clear->UseVisualStyleBackColor = true;
			// 
			// b_quit
			// 
			this->b_quit->Location = System::Drawing::Point(144, 72);
			this->b_quit->Name = L"b_quit";
			this->b_quit->Size = System::Drawing::Size(60, 22);
			this->b_quit->TabIndex = 5;
			this->b_quit->Text = L"Quit";
			this->b_quit->UseVisualStyleBackColor = true;
			// 
			// pwd2
			// 
			this->pwd2->Font = (gcnew System::Drawing::Font(L"微软雅黑", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->pwd2->Location = System::Drawing::Point(78, 12);
			this->pwd2->Name = L"pwd2";
			this->pwd2->Size = System::Drawing::Size(60, 54);
			this->pwd2->TabIndex = 1;
			// 
			// pwd3
			// 
			this->pwd3->Font = (gcnew System::Drawing::Font(L"微软雅黑", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->pwd3->Location = System::Drawing::Point(144, 12);
			this->pwd3->Name = L"pwd3";
			this->pwd3->Size = System::Drawing::Size(60, 54);
			this->pwd3->TabIndex = 2;
			// 
			// res1
			// 
			this->res1->Enabled = false;
			this->res1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->res1->Location = System::Drawing::Point(12, 100);
			this->res1->Name = L"res1";
			this->res1->Size = System::Drawing::Size(60, 54);
			this->res1->TabIndex = 6;
			// 
			// res2
			// 
			this->res2->Enabled = false;
			this->res2->Font = (gcnew System::Drawing::Font(L"微软雅黑", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->res2->Location = System::Drawing::Point(78, 100);
			this->res2->Name = L"res2";
			this->res2->Size = System::Drawing::Size(60, 54);
			this->res2->TabIndex = 7;
			// 
			// res3
			// 
			this->res3->Enabled = false;
			this->res3->Font = (gcnew System::Drawing::Font(L"微软雅黑", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->res3->Location = System::Drawing::Point(144, 100);
			this->res3->Name = L"res3";
			this->res3->Size = System::Drawing::Size(60, 54);
			this->res3->TabIndex = 8;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(216, 169);
			this->Controls->Add(this->res3);
			this->Controls->Add(this->res2);
			this->Controls->Add(this->res1);
			this->Controls->Add(this->pwd3);
			this->Controls->Add(this->pwd2);
			this->Controls->Add(this->b_quit);
			this->Controls->Add(this->b_clear);
			this->Controls->Add(this->b_getres);
			this->Controls->Add(this->pwd1);
			this->Name = L"Form1";
			this->Text = L"WebCard";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		private: array<array<int>^>^ pwdtable;

		void initpwdtable()
		{
			pwdtable[0][0] = 57;
			pwdtable[0][1] = 87;
			pwdtable[0][2] = 98;
			pwdtable[0][3] = 04;
			pwdtable[0][4] = 02;
			pwdtable[0][5] = 65;
			pwdtable[0][6] = 81;
			pwdtable[0][7] = 14;
			pwdtable[1][0] = 35;
			pwdtable[1][1] = 42;
			pwdtable[1][2] = 27;
			pwdtable[1][3] = 26;
			pwdtable[1][4] = 94;
			pwdtable[1][5] = 51;
			pwdtable[1][6] = 17;
			pwdtable[1][7] = 71;
			pwdtable[2][0] = 56;
			pwdtable[2][1] = 51;
			pwdtable[2][2] = 48;
			pwdtable[2][3] = 82;
			pwdtable[2][4] = 65;
			pwdtable[2][5] = 56;
			pwdtable[2][6] = 80;
			pwdtable[2][7] = 80;
			pwdtable[3][0] = 34;
			pwdtable[3][1] = 04;
			pwdtable[3][2] = 60;
			pwdtable[3][3] = 73;
			pwdtable[3][4] = 78;
			pwdtable[3][5] = 44;
			pwdtable[3][6] = 45;
			pwdtable[3][7] = 10;
			pwdtable[4][0] = 43;
			pwdtable[4][1] = 05;
			pwdtable[4][2] = 20;
			pwdtable[4][3] = 47;
			pwdtable[4][4] = 68;
			pwdtable[4][5] = 46;
			pwdtable[4][6] = 42;
			pwdtable[4][7] = 86;
			pwdtable[5][0] = 87;
			pwdtable[5][1] = 72;
			pwdtable[5][2] = 63;
			pwdtable[5][3] = 64;
			pwdtable[5][4] = 71;
			pwdtable[5][5] = 27;
			pwdtable[5][6] = 59;
			pwdtable[5][7] = 21;
			pwdtable[6][0] = 64;
			pwdtable[6][1] = 07;
			pwdtable[6][2] = 95;
			pwdtable[6][3] = 92;
			pwdtable[6][4] = 93;
			pwdtable[6][5] = 68;
			pwdtable[6][6] = 35;
			pwdtable[6][7] = 78;
			pwdtable[7][0] = 23;
			pwdtable[7][1] = 93;
			pwdtable[7][2] = 31;
			pwdtable[7][3] = 53;
			pwdtable[7][4] = 31;
			pwdtable[7][5] = 26;
			pwdtable[7][6] = 44;
			pwdtable[7][7] = 42;
			pwdtable[8][0] = 94;
			pwdtable[8][1] = 71;
			pwdtable[8][2] = 48;
			pwdtable[8][3] = 60;
			pwdtable[8][4] = 81;
			pwdtable[8][5] = 75;
			pwdtable[8][6] = 94;
			pwdtable[8][7] = 07;
			pwdtable[9][0] = 94;
			pwdtable[9][1] = 10;
			pwdtable[9][2] = 33;
			pwdtable[9][3] = 44;
			pwdtable[9][4] = 73;
			pwdtable[9][5] = 58;
			pwdtable[9][6] = 19;
			pwdtable[9][7] = 86;
		}

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 initpwdtable();
				 res1->Text = pwdtable[9][7].to;
			 }
private: System::Void b_getres_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

