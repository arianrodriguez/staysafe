#pragma once
#include "Controlador.h"
#include "Controlador2.h"
#include "GameOver.h"
#include "YouWin.h"

using namespace std;
using namespace System;	

namespace ProjectFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		// recibe parametro del form del Menuprincipal
		MyForm(int _dificultad)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			srand(time(NULL));
			gr = this->CreateGraphics();
			bc = BufferedGraphicsManager::Current;
			bg = bc->Allocate(gr, this->ClientRectangle);

			// se almacena en una variable la dificultad seleccionada en el menu principal
			dificultad = _dificultad;

			timer_aparicion_pildoras->Enabled = true;
			imgAmbulancia = gcnew Bitmap("images/ambulancia.png");
			imgVacuna = gcnew Bitmap("Images//vacuna.png");
			imgPersonaje = gcnew Bitmap("Images//doctor.png");
			imgInfectado1 = gcnew Bitmap("Images//infectado1.png");
			imgInfectado2 = gcnew Bitmap("Images//infectado2.png");
			imgSano1 = gcnew Bitmap("Images//sano1.png");
			imgSano2 = gcnew Bitmap("Images//sano2.png");
			nuevoInfectado1 = gcnew Bitmap("Images//nuevoInfectado1.png");
			nuevoInfectado2 = gcnew Bitmap("Images//nuevoInfectado2.png");
			nuevoSano1 = gcnew Bitmap("Images//nuevoSano1.png");
			nuevoSano2 = gcnew Bitmap("Images//nuevoSano2.png");
			imgBotiquin = gcnew Bitmap("Images//botiquin.png");
			imgPildora = gcnew Bitmap("Images//pildora.png");
			imgVidas = gcnew Bitmap("Images//spriteVidas1.png");
			imgBarraBalas = gcnew Bitmap("Images//municiones_sprite.png");
			fondo = gcnew Bitmap("Images//fondo.png");
			imgPersonajeInmune = gcnew Bitmap("images/doctor_inmune.png");
			txt_soyinmune = gcnew Bitmap("images/txt_inmune.png");
			txt_recargando = gcnew Bitmap("images/txt_recargando.png");
			dosis1 = gcnew Bitmap("images/dosis1.png");
			dosis2 = gcnew Bitmap("images/dosis2.png");
			dosis3 = gcnew Bitmap("images/dosis3.png");
			sindosis = gcnew Bitmap("images/sindosis.png");
			imgVirus = gcnew Bitmap("images//virus.png");
			nuevoFondoDificil = gcnew Bitmap("images/fondo_dificil.png");
			pantalla_gameover = new GameOver(gcnew Bitmap("images/banner_gameover.png"));
			pantalla_youwin = new YouWin(gcnew Bitmap("images/youwin.png"));
			image = gcnew Bitmap(fondo, gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height);
			image2 = gcnew Bitmap(nuevoFondoDificil, gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height);


			paredes = new vector<Rectangle*>();
			generar_paredes();

			control = new Controlador(gr);
			control2 = new Controlador2(gr);

			for (int i = 0; i < control->getNumNPC(); i++)
			{
				control->agregarNPC();
				control->agregarDosisNPC(control->getvectornpc()->at(i)->getX(), control->getvectornpc()->at(i)->getY());
			}

			for (int i = 0; i < control2->getNumNPC(); i++)
			{
				control2->agregarNPC();
				control2->agregarDosisNPC(control2->getvectornpc()->at(i)->getX(), control2->getvectornpc()->at(i)->getY());

			}

			for (int i = 0; i < control2->getNumVirus(); i++)
			{
				control2->agregarVirus();
			}

			if (dificultad == 1) {
				timer1->Enabled = true;
			}
			else {
				timer2->Enabled = true;
			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Graphics^ gr;
		BufferedGraphicsContext^ bc;
		BufferedGraphics^ bg;

		Controlador* control;	// nivel normal
		Controlador2* control2;	// nivel dificil
		Bitmap^ imgAmbulancia;
		Bitmap^ imgVacuna;
		Bitmap^ imgPersonaje;
		Bitmap^ imgInfectado1;
		Bitmap^ imgInfectado2;
		Bitmap^ imgSano1;
		Bitmap^ imgSano2;
		Bitmap^ imgBotiquin;
		Bitmap^ imgPildora;
		Bitmap^ imgVidas;
		Bitmap^ imgBarraBalas;
		Bitmap^ imgPersonajeInmune;
		Bitmap^ txt_soyinmune;
		Bitmap^ txt_recargando;
		Bitmap^ dosis1;
		Bitmap^ dosis2;
		Bitmap^ dosis3;
		Bitmap^ sindosis;
		Bitmap^ fondo;
		Bitmap^ fondo_dificil;
		Bitmap^ image;
		GameOver* pantalla_gameover;
		YouWin* pantalla_youwin;
		int dificultad, mostrar_pantalla;

		// Bitmaps exclusivos del nivel dificil
		Bitmap^ nuevoInfectado1;	// todavia no se esta usando
		Bitmap^ nuevoInfectado2;
		Bitmap^ nuevoSano1;		// todavia no se esta usando
		Bitmap^ nuevoSano2;
		Bitmap^ nuevoFondoDificil;	// para el fondo difuminado o rojizo no se (ia dise)
		Bitmap^ image2;
		Bitmap^ imgVirus;

		vector<Rectangle*>* paredes;
	private: System::Windows::Forms::Timer^ timer_aparicion_pildoras;
	private: System::Windows::Forms::PictureBox^ pbox_contador;
	private: System::Windows::Forms::Label^ lbl_contador_min;
	private: System::Windows::Forms::Label^ lbl_dos_puntos;
	private: System::Windows::Forms::Label^ lbl_contador_seg;
	private: System::Windows::Forms::Timer^ timer_juego_contador;
private: System::Windows::Forms::Timer^ timer2;
private: System::Windows::Forms::Timer^ timer_gameover;


	private: System::Windows::Forms::Timer^ timer_aparicion_botiquines;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timer_aparicion_botiquines = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timer_aparicion_pildoras = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pbox_contador = (gcnew System::Windows::Forms::PictureBox());
			   this->lbl_contador_min = (gcnew System::Windows::Forms::Label());
			   this->lbl_dos_puntos = (gcnew System::Windows::Forms::Label());
			   this->lbl_contador_seg = (gcnew System::Windows::Forms::Label());
			   this->timer_juego_contador = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timer_gameover = (gcnew System::Windows::Forms::Timer(this->components));
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_contador))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			   // 
			   // timer_aparicion_botiquines
			   // 
			   this->timer_aparicion_botiquines->Interval = 15000;
			   this->timer_aparicion_botiquines->Tick += gcnew System::EventHandler(this, &MyForm::timer_aparicion_botiquines_Tick);
			   // 
			   // timer_aparicion_pildoras
			   // 
			   this->timer_aparicion_pildoras->Interval = 20000;
			   this->timer_aparicion_pildoras->Tick += gcnew System::EventHandler(this, &MyForm::timer_aparicion_pildoras_Tick);
			   // 
			   // pbox_contador
			   // 
			   this->pbox_contador->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbox_contador.Image")));
			   this->pbox_contador->Location = System::Drawing::Point(932, 12);
			   this->pbox_contador->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->pbox_contador->Name = L"pbox_contador";
			   this->pbox_contador->Size = System::Drawing::Size(221, 97);
			   this->pbox_contador->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbox_contador->TabIndex = 0;
			   this->pbox_contador->TabStop = false;
			   // 
			   // lbl_contador_min
			   // 
			   this->lbl_contador_min->AutoSize = true;
			   this->lbl_contador_min->BackColor = System::Drawing::Color::White;
			   this->lbl_contador_min->Font = (gcnew System::Drawing::Font(L"Consolas", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lbl_contador_min->Location = System::Drawing::Point(979, 36);
			   this->lbl_contador_min->Name = L"lbl_contador_min";
			   this->lbl_contador_min->Size = System::Drawing::Size(46, 51);
			   this->lbl_contador_min->TabIndex = 1;
			   this->lbl_contador_min->Text = L"0";
			   // 
			   // lbl_dos_puntos
			   // 
			   this->lbl_dos_puntos->AutoSize = true;
			   this->lbl_dos_puntos->BackColor = System::Drawing::Color::White;
			   this->lbl_dos_puntos->Font = (gcnew System::Drawing::Font(L"Consolas", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lbl_dos_puntos->Location = System::Drawing::Point(1011, 36);
			   this->lbl_dos_puntos->Name = L"lbl_dos_puntos";
			   this->lbl_dos_puntos->Size = System::Drawing::Size(46, 51);
			   this->lbl_dos_puntos->TabIndex = 2;
			   this->lbl_dos_puntos->Text = L":";
			   // 
			   // lbl_contador_seg
			   // 
			   this->lbl_contador_seg->AutoSize = true;
			   this->lbl_contador_seg->BackColor = System::Drawing::Color::White;
			   this->lbl_contador_seg->Font = (gcnew System::Drawing::Font(L"Consolas", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lbl_contador_seg->Location = System::Drawing::Point(1043, 36);
			   this->lbl_contador_seg->Name = L"lbl_contador_seg";
			   this->lbl_contador_seg->Size = System::Drawing::Size(70, 51);
			   this->lbl_contador_seg->TabIndex = 3;
			   this->lbl_contador_seg->Text = L"00";
			   // 
			   // timer_juego_contador
			   // 
			   this->timer_juego_contador->Enabled = true;
			   this->timer_juego_contador->Interval = 1000;
			   this->timer_juego_contador->Tick += gcnew System::EventHandler(this, &MyForm::timer_juego_contador_Tick);
			   // 
			   // timer2
			   // 
			   this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			   // 
			   // timer_gameover
			   // 
			   this->timer_gameover->Tick += gcnew System::EventHandler(this, &MyForm::timer_gameover_Tick);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1444, 881);
			   this->Controls->Add(this->lbl_contador_seg);
			   this->Controls->Add(this->lbl_dos_puntos);
			   this->Controls->Add(this->lbl_contador_min);
			   this->Controls->Add(this->pbox_contador);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"MyForm";
			   this->Text = L"Stay Safe";
			   this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_contador))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		bg->Graphics->DrawImageUnscaled(image, 0, 0);

		control->jugar(bg->Graphics, imgPersonaje, imgVacuna, imgInfectado1, imgInfectado2, imgSano1, imgSano2,
			imgBotiquin, imgVidas, imgBarraBalas, imgAmbulancia, imgPildora, imgPersonajeInmune, txt_soyinmune, 
			txt_recargando, dosis1, dosis2, dosis3, sindosis);

		control->colision(paredes);
		if (control->getrefill()) control->refill_balas(gr);
		soltar_botiquin();

		//control->actualizar_seg(); utilizarlo en este timer para comprobar el contador más rápido y no tener q esperar 2 minutos


		if (control->gameOver() || control->time_over())
		{
			this->mostrar_pantalla = 1; //pantalla game over
			timer1->Enabled = false;
			timer_gameover->Enabled = true;
			lbl_contador_min->Visible = false;
			lbl_contador_seg->Visible = false;
			lbl_dos_puntos->Visible = false;
			pbox_contador->Visible = false;

		}

		if (control->gameWin()) {
			this->mostrar_pantalla = 2; //pantalla you win
			timer1->Enabled = false;
			timer_gameover->Enabled = true;
			lbl_contador_min->Visible = false;
			lbl_contador_seg->Visible = false;
			lbl_dos_puntos->Visible = false;
			pbox_contador->Visible = false;
		}

		actualizar_label_contadores();
		


		bg->Render(gr);

		//delete gr, bg, bc;
	}

	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		bg->Graphics->DrawImageUnscaled(image2, 0, 0);

		control2->jugar(bg->Graphics, imgPersonaje, imgVacuna, imgInfectado1, nuevoInfectado2, imgSano1, nuevoSano2,
			imgBotiquin, imgVidas, imgBarraBalas, imgAmbulancia, imgPildora, imgPersonajeInmune, txt_soyinmune,
			txt_recargando, dosis1, dosis2, dosis3, sindosis, imgVirus);

		control2->colision(paredes);
		if (control2->getrefill()) control2->refill_balas(gr);
		soltar_botiquin();

		//control->actualizar_seg(); utilizarlo en este timer para comprobar el contador más rápido y no tener q esperar 2 minutos

		//generar_paredes();
		if (control2->gameOver() || control2->time_over())
		{
			this->mostrar_pantalla = 1; //pantalla game over
			timer2->Enabled = false;
			timer_gameover->Enabled = true;
			lbl_contador_min->Visible = false;
			lbl_contador_seg->Visible = false;
			lbl_dos_puntos->Visible = false;
			pbox_contador->Visible = false;
		}

		if (control2->gameWin()) {
			this->mostrar_pantalla = 2; //pantalla you win
			timer2->Enabled = false;
			timer_gameover->Enabled = true;
			lbl_contador_min->Visible = false;
			lbl_contador_seg->Visible = false;
			lbl_dos_puntos->Visible = false;
			pbox_contador->Visible = false;
		}

		actualizar_label_contadores();

		bg->Render(gr);
	}

	private: void soltar_botiquin() {
		if (dificultad == 1) {
			if (control->getJugador()->getVida() < 5)
				timer_aparicion_botiquines->Enabled = true;
			else
				timer_aparicion_botiquines->Enabled = false;
		}
		
		if (dificultad == 2) {
			if (control2->getJugador()->getVida() < 3)
				timer_aparicion_botiquines->Enabled = true;
			else
				timer_aparicion_botiquines->Enabled = false;
		}
		
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (!control->getrefill()) { //para que se quede quieto cuando esté rellenando balas
			if (!control2->getrefill()) {
				switch (e->KeyCode)
				{
				case Keys::W:
					//control->getJugador()->mov_personaje(gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height, 'W');
					control->getJugador()->setDY(-12);
					control->getJugador()->cambiarDireccion('W');
					control2->getJugador()->setDY(-12);
					control2->getJugador()->cambiarDireccion('W');
					break;
				case Keys::A:
					//control->getJugador()->mov_personaje(gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height, 'A');
					control->getJugador()->setDX(-12);
					control->getJugador()->cambiarDireccion('A');
					control2->getJugador()->setDX(-12);
					control2->getJugador()->cambiarDireccion('A');
					break;
				case Keys::S:
					//control->getJugador()->mov_personaje(gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height, 'S');
					control->getJugador()->setDY(12);
					control->getJugador()->cambiarDireccion('S');
					control2->getJugador()->setDY(12);
					control2->getJugador()->cambiarDireccion('S');
					break;
				case Keys::D:
					//control->getJugador()->mov_personaje(gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height, 'D');
					control->getJugador()->setDX(12);
					control->getJugador()->cambiarDireccion('D');
					control2->getJugador()->setDX(12);
					control2->getJugador()->cambiarDireccion('D');
					break;
				case Keys::X:
					/*control->agregarNPC();
					control2->agregarNPC();*/
					break;
				case Keys::Space:
					control->agregarBala();
					control2->agregarBala();
					break;
				}
			}
		}	
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W:
			control->getJugador()->setDY(0);
			control2->getJugador()->setDY(0);
			break;
		case Keys::A:
			//control->getJugador()->mov_personaje(gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height, 'A');
			control->getJugador()->setDX(0);
			control2->getJugador()->setDX(0);
			break;
		case Keys::S:
			//control->getJugador()->mov_personaje(gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height, 'S');
			control->getJugador()->setDY(0);
			control2->getJugador()->setDY(0);
			break;
		case Keys::D:
			//control->getJugador()->mov_personaje(gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height, 'D');
			control->getJugador()->setDX(0);
			control2->getJugador()->setDX(0);
			break;
		}
	}
	private: void generar_paredes() {
					//visualización de las paredes
	/*for (int i = 0; i < paredes->size(); ++i) {
		bg->Graphics->FillRectangle(Brushes::Red, paredes->at(i)->X, paredes->at(i)->Y,
			paredes->at(i)->Width, paredes->at(i)->Height);
	}
	*/

		paredes->push_back(new Rectangle(0, 0, 850, 350));
		paredes->push_back(new Rectangle(850, 0, 250, 150));
		paredes->push_back(new Rectangle(1050, 0, 280, 350));
		paredes->push_back(new Rectangle(1330, 0, 205, 300));
	}
	private: System::Void timer_aparicion_botiquines_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (!control->getBotiquinSuelto()) {
			control->agregarBotiquin();
			control->setBotiquinSuelto(true);
		}
		if (!control2->getBotiquinSuelto()) {
			control2->agregarBotiquin();
			control2->setBotiquinSuelto(true);
		}
	}
	private: System::Void timer_aparicion_pildoras_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		control->agregarPildora();
		control2->agregarPildora();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		//if(dificultad == "NORMAL") {}  para diferenciar la dificultad y editar el contador
		if (dificultad == 1) {
			this->lbl_contador_min->Text = Convert::ToString(control->getcontmin());
			this->lbl_contador_seg->Text = Convert::ToString(control->getcontseg());
		}
		
		if (dificultad == 2) {
			this->lbl_contador_min->Text = Convert::ToString(control2->getcontmin());
			this->lbl_contador_seg->Text = Convert::ToString(control2->getcontseg());
		}
		
	}
	private: System::Void timer_juego_contador_Tick(System::Object^ sender, System::EventArgs^ e) {
		control->actualizar_seg();
		control2->actualizar_seg();
	}
	private: void actualizar_label_contadores() {
		if (dificultad == 1) {
			if (control->getcontseg() >= 10) {
				this->lbl_contador_min->Text = Convert::ToString(control->getcontmin());
				this->lbl_contador_seg->Text = Convert::ToString(control->getcontseg());
			}
			else {
				this->lbl_contador_seg->Text = "0" + Convert::ToString(control->getcontseg());
			}
		}
		
		if (dificultad == 2) {
			if (control2->getcontseg() >= 10) {
				this->lbl_contador_min->Text = Convert::ToString(control2->getcontmin());
				this->lbl_contador_seg->Text = Convert::ToString(control2->getcontseg());
			}
			else {
				this->lbl_contador_seg->Text = "0" + Convert::ToString(control2->getcontseg());
			}
		}
		
	}

	private: System::Void timer_gameover_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (this->mostrar_pantalla == 1) {
			pantalla_gameover->animacion_gif(bg->Graphics, gcnew Bitmap("images/banner_gameover.png"));
			pantalla_gameover->actualizar_indices();
		}
		else {
			pantalla_youwin->animacion_gif(bg->Graphics, gcnew Bitmap("images/youwin.png"));
			pantalla_youwin->actualizar_indices();
		}
		bg->Render(gr);
	}
};
}
