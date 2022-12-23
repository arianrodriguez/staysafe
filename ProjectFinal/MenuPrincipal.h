#pragma once
#include <iostream>
#include <string>
#include "Instrucciones.h"
#include "MyForm.h"
using namespace std;

namespace ProjectFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			this->opc_senialada = 1;
			this->opc_elegida = false;
			this->it = 0;
			this->nick_jug = gcnew String("");
			this->dificultad = nullptr;
			this->nivelDificultad = 0;
		}

	protected:
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbox_fondo;
	private: System::Windows::Forms::PictureBox^ pbox_flecha;
	private:
		int opc_senialada, it;
		bool opc_elegida;
		int nivelDificultad;
		String^ nick_jug, ^ dificultad;
		Bitmap^ bmp;
		Instrucciones* gif_instrucciones;
		Graphics^ g;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ buffer;

	private: System::Windows::Forms::PictureBox^ pbox_flecha2;
	private: System::Windows::Forms::PictureBox^ pbox_flecha3;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Panel^ panel_instrucciones;
	private: System::Windows::Forms::PictureBox^ pbox_btn_regresarINST;
	private: System::Windows::Forms::Panel^ panel_gif_instrucciones;
	private: System::Windows::Forms::Panel^ panel_creadores;
	private: System::Windows::Forms::PictureBox^ pbox_btn_regresarCRE;
	private: System::Windows::Forms::Panel^ panel_jugar;
	private: System::Windows::Forms::PictureBox^ pbox_btn_iniciar;
	private: System::Windows::Forms::PictureBox^ pbox_btn_regresarJUGAR;
	private: System::Windows::Forms::TextBox^ txt_nombre_jugador;
	private: System::Windows::Forms::PictureBox^ pbox_btn_libre;
	private: System::Windows::Forms::PictureBox^ btn_deslizar;
	private: System::Windows::Forms::PictureBox^ btn_normal;
	private: System::Windows::Forms::PictureBox^ btn_dificil;
	private: System::Windows::Forms::PictureBox^ btn_deslizar_arriba;
	private: System::Windows::Forms::PictureBox^ pbox_caja_dificultad;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->pbox_fondo = (gcnew System::Windows::Forms::PictureBox());
			this->pbox_flecha = (gcnew System::Windows::Forms::PictureBox());
			this->pbox_flecha2 = (gcnew System::Windows::Forms::PictureBox());
			this->pbox_flecha3 = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel_instrucciones = (gcnew System::Windows::Forms::Panel());
			this->panel_creadores = (gcnew System::Windows::Forms::Panel());
			this->panel_jugar = (gcnew System::Windows::Forms::Panel());
			this->btn_normal = (gcnew System::Windows::Forms::PictureBox());
			this->btn_dificil = (gcnew System::Windows::Forms::PictureBox());
			this->btn_deslizar_arriba = (gcnew System::Windows::Forms::PictureBox());
			this->pbox_caja_dificultad = (gcnew System::Windows::Forms::PictureBox());
			this->btn_deslizar = (gcnew System::Windows::Forms::PictureBox());
			this->pbox_btn_libre = (gcnew System::Windows::Forms::PictureBox());
			this->txt_nombre_jugador = (gcnew System::Windows::Forms::TextBox());
			this->pbox_btn_iniciar = (gcnew System::Windows::Forms::PictureBox());
			this->pbox_btn_regresarJUGAR = (gcnew System::Windows::Forms::PictureBox());
			this->pbox_btn_regresarCRE = (gcnew System::Windows::Forms::PictureBox());
			this->panel_gif_instrucciones = (gcnew System::Windows::Forms::Panel());
			this->pbox_btn_regresarINST = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_fondo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_flecha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_flecha2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_flecha3))->BeginInit();
			this->panel_instrucciones->SuspendLayout();
			this->panel_creadores->SuspendLayout();
			this->panel_jugar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_normal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_dificil))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_deslizar_arriba))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_caja_dificultad))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_deslizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_btn_libre))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_btn_iniciar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_btn_regresarJUGAR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_btn_regresarCRE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_btn_regresarINST))->BeginInit();
			this->SuspendLayout();
			// 
			// pbox_fondo
			// 
			this->pbox_fondo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pbox_fondo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbox_fondo.Image")));
			this->pbox_fondo->Location = System::Drawing::Point(0, 0);
			this->pbox_fondo->Name = L"pbox_fondo";
			this->pbox_fondo->Size = System::Drawing::Size(982, 533);
			this->pbox_fondo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_fondo->TabIndex = 0;
			this->pbox_fondo->TabStop = false;
			// 
			// pbox_flecha
			// 
			this->pbox_flecha->BackColor = System::Drawing::Color::Transparent;
			this->pbox_flecha->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbox_flecha.Image")));
			this->pbox_flecha->Location = System::Drawing::Point(350, 254);
			this->pbox_flecha->Name = L"pbox_flecha";
			this->pbox_flecha->Size = System::Drawing::Size(52, 50);
			this->pbox_flecha->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_flecha->TabIndex = 1;
			this->pbox_flecha->TabStop = false;
			// 
			// pbox_flecha2
			// 
			this->pbox_flecha2->BackColor = System::Drawing::Color::Transparent;
			this->pbox_flecha2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbox_flecha2.Image")));
			this->pbox_flecha2->Location = System::Drawing::Point(350, 321);
			this->pbox_flecha2->Name = L"pbox_flecha2";
			this->pbox_flecha2->Size = System::Drawing::Size(52, 50);
			this->pbox_flecha2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_flecha2->TabIndex = 2;
			this->pbox_flecha2->TabStop = false;
			// 
			// pbox_flecha3
			// 
			this->pbox_flecha3->BackColor = System::Drawing::Color::Transparent;
			this->pbox_flecha3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbox_flecha3.Image")));
			this->pbox_flecha3->Location = System::Drawing::Point(350, 386);
			this->pbox_flecha3->Name = L"pbox_flecha3";
			this->pbox_flecha3->Size = System::Drawing::Size(52, 50);
			this->pbox_flecha3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_flecha3->TabIndex = 3;
			this->pbox_flecha3->TabStop = false;
			// 
			// timer
			// 
			this->timer->Interval = 200;
			this->timer->Tick += gcnew System::EventHandler(this, &MenuPrincipal::timer_Tick);
			// 
			// panel_instrucciones
			// 
			this->panel_instrucciones->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_instrucciones.BackgroundImage")));
			this->panel_instrucciones->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel_instrucciones->Controls->Add(this->panel_creadores);
			this->panel_instrucciones->Controls->Add(this->panel_gif_instrucciones);
			this->panel_instrucciones->Controls->Add(this->pbox_btn_regresarINST);
			this->panel_instrucciones->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_instrucciones->Location = System::Drawing::Point(0, 0);
			this->panel_instrucciones->Name = L"panel_instrucciones";
			this->panel_instrucciones->Size = System::Drawing::Size(982, 533);
			this->panel_instrucciones->TabIndex = 4;
			this->panel_instrucciones->Visible = false;
			// 
			// panel_creadores
			// 
			this->panel_creadores->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_creadores.BackgroundImage")));
			this->panel_creadores->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel_creadores->Controls->Add(this->panel_jugar);
			this->panel_creadores->Controls->Add(this->pbox_btn_regresarCRE);
			this->panel_creadores->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_creadores->Location = System::Drawing::Point(0, 0);
			this->panel_creadores->Name = L"panel_creadores";
			this->panel_creadores->Size = System::Drawing::Size(982, 533);
			this->panel_creadores->TabIndex = 3;
			this->panel_creadores->Visible = false;
			// 
			// panel_jugar
			// 
			this->panel_jugar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_jugar.BackgroundImage")));
			this->panel_jugar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel_jugar->Controls->Add(this->btn_normal);
			this->panel_jugar->Controls->Add(this->btn_dificil);
			this->panel_jugar->Controls->Add(this->btn_deslizar_arriba);
			this->panel_jugar->Controls->Add(this->pbox_caja_dificultad);
			this->panel_jugar->Controls->Add(this->btn_deslizar);
			this->panel_jugar->Controls->Add(this->pbox_btn_libre);
			this->panel_jugar->Controls->Add(this->txt_nombre_jugador);
			this->panel_jugar->Controls->Add(this->pbox_btn_iniciar);
			this->panel_jugar->Controls->Add(this->pbox_btn_regresarJUGAR);
			this->panel_jugar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_jugar->Location = System::Drawing::Point(0, 0);
			this->panel_jugar->Name = L"panel_jugar";
			this->panel_jugar->Size = System::Drawing::Size(982, 533);
			this->panel_jugar->TabIndex = 3;
			this->panel_jugar->Visible = false;
			// 
			// btn_normal
			// 
			this->btn_normal->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_normal->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_normal.Image")));
			this->btn_normal->Location = System::Drawing::Point(627, 285);
			this->btn_normal->Name = L"btn_normal";
			this->btn_normal->Size = System::Drawing::Size(184, 50);
			this->btn_normal->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btn_normal->TabIndex = 25;
			this->btn_normal->TabStop = false;
			this->btn_normal->Visible = false;
			this->btn_normal->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_normal_Click);
			this->btn_normal->MouseLeave += gcnew System::EventHandler(this, &MenuPrincipal::btn_normal_MouseLeave);
			this->btn_normal->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MenuPrincipal::btn_normal_MouseMove);
			// 
			// btn_dificil
			// 
			this->btn_dificil->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_dificil->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_dificil.Image")));
			this->btn_dificil->Location = System::Drawing::Point(627, 341);
			this->btn_dificil->Name = L"btn_dificil";
			this->btn_dificil->Size = System::Drawing::Size(184, 50);
			this->btn_dificil->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btn_dificil->TabIndex = 24;
			this->btn_dificil->TabStop = false;
			this->btn_dificil->Visible = false;
			this->btn_dificil->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_dificil_Click);
			this->btn_dificil->MouseLeave += gcnew System::EventHandler(this, &MenuPrincipal::btn_dificil_MouseLeave);
			this->btn_dificil->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MenuPrincipal::btn_dificil_MouseMove);
			// 
			// btn_deslizar_arriba
			// 
			this->btn_deslizar_arriba->BackColor = System::Drawing::Color::Transparent;
			this->btn_deslizar_arriba->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_deslizar_arriba->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_deslizar_arriba.Image")));
			this->btn_deslizar_arriba->Location = System::Drawing::Point(760, 221);
			this->btn_deslizar_arriba->Name = L"btn_deslizar_arriba";
			this->btn_deslizar_arriba->Size = System::Drawing::Size(42, 39);
			this->btn_deslizar_arriba->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btn_deslizar_arriba->TabIndex = 23;
			this->btn_deslizar_arriba->TabStop = false;
			this->btn_deslizar_arriba->Visible = false;
			this->btn_deslizar_arriba->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_deslizar_arriba_Click);
			// 
			// pbox_caja_dificultad
			// 
			this->pbox_caja_dificultad->BackColor = System::Drawing::Color::Transparent;
			this->pbox_caja_dificultad->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbox_caja_dificultad.Image")));
			this->pbox_caja_dificultad->Location = System::Drawing::Point(604, 204);
			this->pbox_caja_dificultad->Name = L"pbox_caja_dificultad";
			this->pbox_caja_dificultad->Size = System::Drawing::Size(221, 209);
			this->pbox_caja_dificultad->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_caja_dificultad->TabIndex = 22;
			this->pbox_caja_dificultad->TabStop = false;
			this->pbox_caja_dificultad->Visible = false;
			// 
			// btn_deslizar
			// 
			this->btn_deslizar->BackColor = System::Drawing::Color::Transparent;
			this->btn_deslizar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_deslizar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_deslizar.Image")));
			this->btn_deslizar->Location = System::Drawing::Point(760, 221);
			this->btn_deslizar->Name = L"btn_deslizar";
			this->btn_deslizar->Size = System::Drawing::Size(42, 39);
			this->btn_deslizar->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btn_deslizar->TabIndex = 21;
			this->btn_deslizar->TabStop = false;
			this->btn_deslizar->Visible = false;
			this->btn_deslizar->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_deslizar_Click);
			// 
			// pbox_btn_libre
			// 
			this->pbox_btn_libre->BackColor = System::Drawing::Color::Transparent;
			this->pbox_btn_libre->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbox_btn_libre.Image")));
			this->pbox_btn_libre->Location = System::Drawing::Point(578, 204);
			this->pbox_btn_libre->Name = L"pbox_btn_libre";
			this->pbox_btn_libre->Size = System::Drawing::Size(261, 72);
			this->pbox_btn_libre->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_btn_libre->TabIndex = 15;
			this->pbox_btn_libre->TabStop = false;
			this->pbox_btn_libre->Visible = false;
			// 
			// txt_nombre_jugador
			// 
			this->txt_nombre_jugador->BackColor = System::Drawing::Color::White;
			this->txt_nombre_jugador->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txt_nombre_jugador->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_nombre_jugador->Location = System::Drawing::Point(177, 221);
			this->txt_nombre_jugador->MaxLength = 10;
			this->txt_nombre_jugador->Name = L"txt_nombre_jugador";
			this->txt_nombre_jugador->Size = System::Drawing::Size(183, 27);
			this->txt_nombre_jugador->TabIndex = 6;
			this->txt_nombre_jugador->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txt_nombre_jugador->Visible = false;
			// 
			// pbox_btn_iniciar
			// 
			this->pbox_btn_iniciar->BackColor = System::Drawing::Color::Transparent;
			this->pbox_btn_iniciar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbox_btn_iniciar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbox_btn_iniciar.Image")));
			this->pbox_btn_iniciar->Location = System::Drawing::Point(514, 476);
			this->pbox_btn_iniciar->Name = L"pbox_btn_iniciar";
			this->pbox_btn_iniciar->Size = System::Drawing::Size(146, 53);
			this->pbox_btn_iniciar->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbox_btn_iniciar->TabIndex = 4;
			this->pbox_btn_iniciar->TabStop = false;
			this->pbox_btn_iniciar->Visible = false;
			this->pbox_btn_iniciar->Click += gcnew System::EventHandler(this, &MenuPrincipal::pbox_btn_iniciar_Click);
			this->pbox_btn_iniciar->MouseLeave += gcnew System::EventHandler(this, &MenuPrincipal::pbox_btn_iniciar_MouseLeave);
			this->pbox_btn_iniciar->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MenuPrincipal::pbox_btn_iniciar_MouseMove);
			// 
			// pbox_btn_regresarJUGAR
			// 
			this->pbox_btn_regresarJUGAR->BackColor = System::Drawing::Color::Transparent;
			this->pbox_btn_regresarJUGAR->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbox_btn_regresarJUGAR->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbox_btn_regresarJUGAR.Image")));
			this->pbox_btn_regresarJUGAR->Location = System::Drawing::Point(329, 480);
			this->pbox_btn_regresarJUGAR->Name = L"pbox_btn_regresarJUGAR";
			this->pbox_btn_regresarJUGAR->Size = System::Drawing::Size(114, 45);
			this->pbox_btn_regresarJUGAR->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_btn_regresarJUGAR->TabIndex = 3;
			this->pbox_btn_regresarJUGAR->TabStop = false;
			this->pbox_btn_regresarJUGAR->Visible = false;
			this->pbox_btn_regresarJUGAR->Click += gcnew System::EventHandler(this, &MenuPrincipal::pbox_btn_regresar_Click_1);
			this->pbox_btn_regresarJUGAR->MouseLeave += gcnew System::EventHandler(this, &MenuPrincipal::pbox_btn_regresar_MouseLeave);
			this->pbox_btn_regresarJUGAR->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MenuPrincipal::pbox_btn_regresar_MouseMove);
			// 
			// pbox_btn_regresarCRE
			// 
			this->pbox_btn_regresarCRE->BackColor = System::Drawing::Color::Transparent;
			this->pbox_btn_regresarCRE->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbox_btn_regresarCRE->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbox_btn_regresarCRE.Image")));
			this->pbox_btn_regresarCRE->Location = System::Drawing::Point(416, 476);
			this->pbox_btn_regresarCRE->Name = L"pbox_btn_regresarCRE";
			this->pbox_btn_regresarCRE->Size = System::Drawing::Size(138, 54);
			this->pbox_btn_regresarCRE->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_btn_regresarCRE->TabIndex = 2;
			this->pbox_btn_regresarCRE->TabStop = false;
			this->pbox_btn_regresarCRE->Visible = false;
			this->pbox_btn_regresarCRE->Click += gcnew System::EventHandler(this, &MenuPrincipal::pbox_btn_regresar_Click_1);
			this->pbox_btn_regresarCRE->MouseLeave += gcnew System::EventHandler(this, &MenuPrincipal::pbox_btn_regresar_MouseLeave);
			this->pbox_btn_regresarCRE->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MenuPrincipal::pbox_btn_regresar_MouseMove);
			// 
			// panel_gif_instrucciones
			// 
			this->panel_gif_instrucciones->BackColor = System::Drawing::Color::White;
			this->panel_gif_instrucciones->Location = System::Drawing::Point(196, 160);
			this->panel_gif_instrucciones->Name = L"panel_gif_instrucciones";
			this->panel_gif_instrucciones->Size = System::Drawing::Size(577, 301);
			this->panel_gif_instrucciones->TabIndex = 1;
			this->panel_gif_instrucciones->Visible = false;
			// 
			// pbox_btn_regresarINST
			// 
			this->pbox_btn_regresarINST->BackColor = System::Drawing::Color::Transparent;
			this->pbox_btn_regresarINST->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbox_btn_regresarINST->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbox_btn_regresarINST.Image")));
			this->pbox_btn_regresarINST->Location = System::Drawing::Point(416, 467);
			this->pbox_btn_regresarINST->Name = L"pbox_btn_regresarINST";
			this->pbox_btn_regresarINST->Size = System::Drawing::Size(138, 54);
			this->pbox_btn_regresarINST->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_btn_regresarINST->TabIndex = 0;
			this->pbox_btn_regresarINST->TabStop = false;
			this->pbox_btn_regresarINST->Visible = false;
			this->pbox_btn_regresarINST->Click += gcnew System::EventHandler(this, &MenuPrincipal::pbox_btn_regresar_Click_1);
			this->pbox_btn_regresarINST->MouseLeave += gcnew System::EventHandler(this, &MenuPrincipal::pbox_btn_regresar_MouseLeave);
			this->pbox_btn_regresarINST->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MenuPrincipal::pbox_btn_regresar_MouseMove);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(982, 533);
			this->Controls->Add(this->panel_instrucciones);
			this->Controls->Add(this->pbox_flecha3);
			this->Controls->Add(this->pbox_flecha2);
			this->Controls->Add(this->pbox_flecha);
			this->Controls->Add(this->pbox_fondo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MenuPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Stay Safe";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MenuPrincipal::MenuPrincipal_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_fondo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_flecha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_flecha2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_flecha3))->EndInit();
			this->panel_instrucciones->ResumeLayout(false);
			this->panel_creadores->ResumeLayout(false);
			this->panel_jugar->ResumeLayout(false);
			this->panel_jugar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_normal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_dificil))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_deslizar_arriba))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_caja_dificultad))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_deslizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_btn_libre))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_btn_iniciar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_btn_regresarJUGAR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_btn_regresarCRE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_btn_regresarINST))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
			this->pbox_flecha->Parent = this->pbox_fondo;
			this->pbox_flecha2->Parent = this->pbox_fondo;
			this->pbox_flecha3->Parent = this->pbox_fondo;
			this->pbox_flecha->BackColor = Color::Transparent;
			this->pbox_flecha2->BackColor = Color::Transparent;
			this->pbox_flecha3->BackColor = Color::Transparent;
			this->pbox_flecha->Visible = true;
			this->pbox_flecha2->Visible = false;
			this->pbox_flecha3->Visible = false;

			
		}
		private: System::Void MenuPrincipal_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			switch (e->KeyCode) {
			case Keys::Up:
				if (this->opc_senialada == 2) this->opc_senialada = 1;
				else if (this->opc_senialada == 3) this->opc_senialada = 2;
				break;
			case Keys::Down:
				if (this->opc_senialada == 1) this->opc_senialada = 2;
				else if (this->opc_senialada == 2) this->opc_senialada = 3;
				break;
			case Keys::Enter:
				this->opc_elegida = true;
				break;
			default: break;
			}
			mostrar_flecha();
		}
		private: void mostrar_flecha(){
			switch (this->opc_senialada) {
			case 1:
				this->pbox_flecha->Visible = true;
				this->pbox_flecha2->Visible = false;
				this->pbox_flecha3->Visible = false;
				break;
			case 2:
				this->pbox_flecha->Visible = false;
				this->pbox_flecha2->Visible = true;
				this->pbox_flecha3->Visible = false;
				break;
			case 3:
				this->pbox_flecha->Visible = false;
				this->pbox_flecha2->Visible = false;
				this->pbox_flecha3->Visible = true;
				break;
			default: break;
			}
			if (this->opc_elegida) {
				switch (this->opc_senialada) {
				case 1:
					this->panel_creadores->Visible = true;
					this->panel_instrucciones->Visible = true;
					this->panel_jugar->Visible = true;
					this->pbox_btn_iniciar->Visible = true;
					this->pbox_btn_regresarJUGAR->Visible = true;
					this->txt_nombre_jugador->Visible = true;
					this->btn_deslizar->Visible = true;
					this->pbox_btn_libre->Visible = true;

					break;

				case 2:
					this->panel_instrucciones->Visible = true;
					this->panel_gif_instrucciones->Visible = true;
					this->timer->Enabled = true;
					this->bmp = gcnew Bitmap("images/menu/instrucciones.png");

					this->pbox_btn_regresarINST->Visible = true;

					this->pbox_btn_regresarINST->Parent = this->panel_instrucciones;
					this->pbox_btn_regresarINST->BackColor = Color::Transparent;
					break;

				case 3:				
					//el panel instrucciones es "padre" del creadores
					this->panel_instrucciones->Visible = true;

					this->panel_creadores->Visible = true;
					this->pbox_btn_regresarCRE->Visible = true;

					this->pbox_btn_regresarCRE->Parent = this->panel_creadores;
					this->pbox_btn_regresarCRE->BackColor = Color::Transparent;

					break;
				default: break;
				}
				this->opc_elegida = false;
			}
		}
		private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
			g = this->panel_gif_instrucciones->CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			buffer = espacio->Allocate(g, ClientRectangle);

			buffer->Graphics->Clear(this->panel_gif_instrucciones->BackColor);

			if (this->it == 0) gif_instrucciones = new Instrucciones(bmp);
			gif_instrucciones->actualizar_indices();
			gif_instrucciones->animacion_gif(buffer->Graphics, bmp, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);

			this->it++;
			buffer->Render(g);
		}
		private: System::Void pbox_btn_regresar_Click_1(System::Object^ sender, System::EventArgs^ e) {
			this->timer->Enabled = false;
			this->panel_instrucciones->Visible = false;
			this->panel_gif_instrucciones->Visible = false;
			this->pbox_btn_regresarINST->Visible = false;

			this->panel_creadores->Visible = false;
			this->pbox_btn_regresarCRE->Visible = false;

			this->panel_jugar->Visible = false;
			this->pbox_btn_iniciar->Visible = false;
			this->pbox_btn_regresarJUGAR->Visible = false;
			this->txt_nombre_jugador->Text = "";
			this->btn_deslizar->Visible = false;
			this->pbox_btn_libre->Image = Image::FromFile("images/menu/btn_libre.png");

		}
		private: System::Void pbox_btn_regresar_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->pbox_btn_regresarINST->Image = Image::FromFile("images/menu/btn_regresar_difuminado.png");
			this->pbox_btn_regresarCRE->Image = Image::FromFile("images/menu/btn_regresar_difuminado.png");
			this->pbox_btn_regresarJUGAR->Image = Image::FromFile("images/menu/btn_regresar_difuminado.png");
		}
		private: System::Void pbox_btn_regresar_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			this->pbox_btn_regresarINST->Image = Image::FromFile("images/menu/btn_regresar.png");
			this->pbox_btn_regresarCRE->Image = Image::FromFile("images/menu/btn_regresar.png");
			this->pbox_btn_regresarJUGAR->Image = Image::FromFile("images/menu/btn_regresar.png");
		}
		private: System::Void pbox_btn_iniciar_MouseLeave(System::Object^ sender, System::EventArgs^ e) { this->pbox_btn_iniciar->Image = Image::FromFile("images/menu/btn_iniciar.png"); }
		private: System::Void pbox_btn_iniciar_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { this->pbox_btn_iniciar->Image = Image::FromFile("images/menu/btn_iniciar_difuminado.png"); }
		private: System::Void btn_deslizar_Click(System::Object^ sender, System::EventArgs^ e) {
			/*el orden de los visible cuenta*/

			this->btn_deslizar->Visible = false;
			this->pbox_btn_libre->Visible = false;
			this->btn_deslizar_arriba->Visible = true;
			this->btn_normal->Visible = true;
			this->btn_dificil->Visible = true;

			this->pbox_caja_dificultad->Visible = true;
		}
		private: System::Void btn_normal_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { this->btn_normal->Image = Image::FromFile("images/menu/dificultad_normal_difuminado.png");	}
		private: System::Void btn_normal_MouseLeave(System::Object^ sender, System::EventArgs^ e) { this->btn_normal->Image = Image::FromFile("images/menu/dificultad_normal.png");	}
		private: System::Void btn_dificil_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { this->btn_dificil->Image = Image::FromFile("images/menu/dificultad_dificil_difuminado.png"); }
		private: System::Void btn_dificil_MouseLeave(System::Object^ sender, System::EventArgs^ e) { this->btn_dificil->Image = Image::FromFile("images/menu/dificultad_dificil.png"); }
		private: System::Void btn_deslizar_arriba_Click(System::Object^ sender, System::EventArgs^ e) {
			this->btn_normal->Visible = false;
			this->btn_dificil->Visible = false;
			this->pbox_caja_dificultad->Visible = false;
			this->btn_deslizar_arriba->Visible = false;
			this->btn_deslizar->Visible = true;

			this->pbox_btn_libre->Visible = true;
		}
		private: System::Void btn_dificil_Click(System::Object^ sender, System::EventArgs^ e) {
			btn_deslizar_arriba_Click(sender, e);
			this->pbox_btn_libre->Image = Image::FromFile("images/menu/dificultad_dificil_escogido.png");
			this->dificultad = gcnew String("DIFICIL");
			this->nivelDificultad = 2;
		}
		private: System::Void btn_normal_Click(System::Object^ sender, System::EventArgs^ e) {
			btn_deslizar_arriba_Click(sender, e);
			this->pbox_btn_libre->Image = Image::FromFile("images/menu/dificultad_normal_escogido.png");
			this->dificultad = gcnew String("NORMAL");
			this->nivelDificultad = 1;
		}
		private: System::Void pbox_btn_iniciar_Click(System::Object^ sender, System::EventArgs^ e) {
			this->nick_jug = gcnew String(this->txt_nombre_jugador->Text);
			if (this->dificultad == nullptr || this->nick_jug == "") MessageBox::Show("Rellena los campos requeridos");
			else {
				/*
					this->nick_jug;
					this->dificultad;
				*/

				// 1: dificultad normal - 2: dificultad dificil 
				
				/* el formulario del juego (myForm) recibe por parametro
				el valor almacenado al elegir la dificultad normal o dificil - Revisar constructor del myForm*/
				MyForm^ juego = gcnew MyForm(nivelDificultad);
				//juego->IngresaNombreUsuario(this->nick_jug);
				juego->ShowDialog();
				this->Close();
				//MessageBox::Show("ia dise");
			}
		}
};
}
