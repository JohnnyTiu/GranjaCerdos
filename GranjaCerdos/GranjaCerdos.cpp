/*
	Proyecto que gestiona una granja de cerdos con estructuras de datos Pila y Cola

	Creadores:
	Carlos Maldonado 2290-23-6788
	Johnny Tiu 2290-23-1487
	Andy Tzoc 2290-23-15187
*/

#define NOMINMAX // Desactivar la macro max
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <limits> // Incluir la librería <limits>


using namespace std;

struct Cerdo {
	int numArete;
	int numModulo;
	string raza;
	char sexo;
	float peso;
	float altura;
	string fechaNac;
	int edad;
	char estadoSalud;
	string ultimaVacuna;
	string fechaUltimaVacuna;
	float cantAlimento;
	string procedencia;
	char venta;
	float precio;
	string destino;
	struct Cerdo* siguiente;
};

// Estructura para Empleados
struct Empleado {
	int id;
	string nombre;
	string fechaNacimiento;
	char genero;
	string cargo;
	string departamento;
	string horario;
	string telefono;
	string direccion;
	int salario;
	string estado;
	string beneficios;
	string fechaContratacion;
	struct Empleado* sgte;
};

struct ColaEmpleado {
	Empleado* delante = nullptr;
	Empleado* atras = nullptr;
};

struct Comprador
{
	int id;
	string nombre;
	string telefono;
	string direccion;
	string metodoPago;
	string frecuenciaCompra;
	string preferencias;
	string fechaRegistro;
	string estadoCuenta;
	Comprador* sgte;
};

void umg();
void Integrantes();
void PantallaLogo();
void ProgramaPrincipal();
int MenuPrincipal(const char* tituloMenuPrincipal, const char* opcionesMenuPrincipal[], int nOpcionesMenuPrincipal);
int MenuPila(const char* tituloMenuPila, const char* opcionesMenuPila[], int nOpcionesMenuPila);
void TituloIngresaCerdo();
void TituloVerCerdos();
void TituloBuscarCerdo();
void TituloModificarCerdo();
void TituloEliminarCerdo();
void agregarPila(Cerdo*& pila, int& arete, int& modulo, string& raza, char& sexo, float& peso, float& altura, string& nacimiento, int& edad, char& salud, string& ultVac, string& feUlVac, float& alimento, string& procede, char& venta, float& precio, string& destino);
void mostrarPila(Cerdo* pila);
void buscarCerdo(Cerdo* pila, int areteBuscado, Cerdo*& cerdoEncontrado);
void modificarCerdo(Cerdo* pila);
void eliminarCerdosPila(Cerdo*& pila);
void sacarPila(Cerdo*& pila);
int MenuCola(const char* tituloMenuCola, const char* opcionesMenuCola[], int nOpcionesMenuCola);
void TituloIngresaTrabajador();
void TituloVerTrabajadores();
void TituloBuscarTrabajador();
void TituloModificarTrabajador();
void TituloEliminaTrabajador();
int MenuLista(const char* tituloMenuLista, const char* opcionesMenuLista[], int nOpciones);
void TituloIngresaComprador();
void TituloVerCompradores();
void TituloBuscarComprador();
void TituloModificarComprador();
void TituloEliminaComprador();
void TituloVaciarLista();
//Prototipos para el manejo de funciones de los empleados
Empleado* crearEmpleado();
void encolarEmpleado(ColaEmpleado& q, Empleado* nuevo);
void gestionarIngresoEmpleados(ColaEmpleado& q);
void mostrarColaEmpleados(ColaEmpleado q);
Empleado* buscarEmpleado(ColaEmpleado q, int idEmpleadoBuscado);
void gestionarBusquedaEmpleados(ColaEmpleado q);
void modificarEmpleado(ColaEmpleado& q);
void eliminarEmpleado(ColaEmpleado& q);
//prototipos para el manejo de funiones de los compradores
Comprador* CrearComprador();
void insertarComprador(Comprador*& compradores, Comprador* nuevo);
void gestionarIngresoCompradores(Comprador*& compradores);
void mostrarListaCompradores(Comprador*);
Comprador* buscarComprador(Comprador* compradores, int idCompradorBuscado);
void modificarComprador(Comprador*& compradores);
void sacarComprador(Comprador*& compradores, int idCompradorBuscado);
void eliminarCompradores(Comprador*& compradores, int idCompradorBuscado);
//Prototipos para el manejo de funciones de los proveedores
void gotoxy(int, int);
int leerEntero(string mensaje, int x, int y);
double leerDecimal(string mensaje, int x, int y);
char leerCaracter(string mensaje, string opcionesValidas, int x, int y);
string leerCadena(string mensaje, int x, int y);
void borrarLinea(int x, int y);
BOOL WINAPI ConsoleHandler(DWORD event);	// Prototipo de la función de manejo de evententos por si el usuario cierra la consola con la x


ColaEmpleado q = { nullptr, nullptr }; // Inicializar la cola vacía

int main() {
	// Registra la función de manejo de eventos de control
	SetConsoleCtrlHandler(ConsoleHandler, TRUE);

	// Llama a las funciones del programa
	umg();
	Integrantes();
	PantallaLogo();
	ProgramaPrincipal();

	return EXIT_SUCCESS;
}

void umg() {
	system("cls");
	system("color 8F");
	gotoxy(22, 8); cout << "****              ****    ******              ******    ********************";
	gotoxy(22, 9); cout << "****              ****    ********          ********    ********************";
	gotoxy(22, 10); cout << "****              ****    ****  ****      ****  ****    ****";
	gotoxy(22, 11); cout << "****              ****    ****   ****    ****   ****    ****";
	gotoxy(22, 12); cout << "****              ****    ****    ****  ****    ****    ****      **********";
	gotoxy(22, 13); cout << "****              ****    ****     ********     ****    ****      **********";
	gotoxy(22, 14); cout << "****              ****    ****        **        ****    ****            ****";
	gotoxy(22, 15); cout << "****              ****    ****                  ****    ****            ****";
	gotoxy(22, 16); cout << "**********************    ****                  ****    ********************";
	gotoxy(22, 17); cout << "**********************    ****                  ****    ********************";

	gotoxy(32, 24); cout << "Presione una tecla para ver a los creadores del codigo...";
	_getch();
}

void Integrantes() {
	system("cls");
	gotoxy(30, 1); cout << "***** ****  ***** ***** *****  ***** ****  ***** *****  **";
	gotoxy(30, 2); cout << "*     *   * *     *   * *    * *   * *   * *     *      **";
	gotoxy(30, 3); cout << "*     ****  ***   ***** *    * *   * ****  ***   *****  ";
	gotoxy(30, 4); cout << "*     *  *  *     *   * *    * *   * *  *  *         *  **";
	gotoxy(30, 5); cout << "***** *   * ***** *   * *****  ***** *   * ***** *****  **";

	gotoxy(2, 8); cout << "***** ***** ****  *     ***** *****";
	gotoxy(2, 9); cout << "*     *   * *   * *     *   * *";
	gotoxy(2, 10); cout << "*     ***** ****  *     *   * *****";
	gotoxy(2, 11); cout << "*     *   * *  *  *     *   *     *";
	gotoxy(2, 12); cout << "***** *   * *   * ***** ***** *****";

	gotoxy(50, 8); cout << "***** ***** ***** *****   ***** *****   ***** ***** ***** *****";
	gotoxy(50, 9); cout << "    *     * *   * *   *       *     *   *         * *   * *   *";
	gotoxy(50, 10); cout << "***** ***** ***** *   * - *****   *** - *****   *** ***** *****";
	gotoxy(50, 11); cout << "*     *         * *   *   *         *   *   *     * *   * *   *";
	gotoxy(50, 12); cout << "***** ***** ***** *****   ***** *****   *****     * ***** *****";

	gotoxy(2, 14); cout << "***** ***** *   * *   * *   * *    *";
	gotoxy(2, 15); cout << "  *   *   * *   * **  * **  * *   *";
	gotoxy(2, 16); cout << "  *   *   * ***** * * * * * * *****";
	gotoxy(2, 17); cout << "* *   *   * *   * *  ** *  **   *";
	gotoxy(2, 18); cout << "***   ***** *   * *   * *   *   *";

	gotoxy(50, 14); cout << "***** ***** ***** *****   ***** *****     *   *   * ***** *****";
	gotoxy(50, 15); cout << "    *     * *   * *   *       *     *   * *   *   * *   *     *";
	gotoxy(50, 16); cout << "***** ***** ***** *   * - *****   *** -   *   ***** *****   ***";
	gotoxy(50, 17); cout << "*               * *   *   *         *     *       * *   *     *";
	gotoxy(50, 18); cout << "***** ***** ***** *****   ***** *****   *****     * *****     *";

	gotoxy(2, 20); cout << "***** *   * ****  *   *";
	gotoxy(2, 21); cout << "*   * **  * *   * *   *";
	gotoxy(2, 22); cout << "***** * * * *   * *****";
	gotoxy(2, 23); cout << "*   * *  ** *   *   *";
	gotoxy(2, 24); cout << "*   * *   * ****    *";

	gotoxy(45, 20); cout << "***** ***** ***** *****   ***** *****     *   *****   *   ***** *****";
	gotoxy(45, 21); cout << "    *     * *   * *   *       *     *   * *   *     * *   *   *     *";
	gotoxy(45, 22); cout << "***** ***** ***** *   * - *****   *** -   *   *****   *   *****   ***";
	gotoxy(45, 23); cout << "*     *         * *   *   *         *     *       *   *   *   *     *";
	gotoxy(45, 24); cout << "***** ***** ***** *****   ***** *****   ***** ***** ***** *****     *";

	gotoxy(45, 26); cout << "Presione una tecla para ver el logo...";
	_getch();
}

void PantallaLogo() {
	system("cls");
	system("color F0");
	int fila = 0;	//Para llevar el control de las filas impresas de la matriz
	int matrizLogo[25][30] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,2,2,2,2,0,1,1,1,0,2,2,2,2,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,2,2,1,1,1,2,2,2,1,1,1,2,2,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,2,3,1,2,2,2,2,2,1,3,2,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,2,2,1,1,2,2,2,2,2,1,1,2,2,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,2,2,2,2,1,1,1,1,1,2,2,2,2,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,2,2,2,1,2,2,2,2,2,1,2,2,2,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,2,2,2,1,2,1,2,1,2,1,2,2,2,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,2,2,2,1,2,2,2,2,2,1,2,2,2,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,2,2,2,1,1,1,1,1,2,2,2,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,2,2,1,2,2,2,1,2,2,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,2,2,2,1,1,1,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,4,4,1,1,1,1,4,4,4,1,1,1,1,0,4,4,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int x = 32; // Posición fija en X para centrar horizontalmente
	int y = 0;  // Posición fija en Y para centrar verticalmente

	for (int i = 0; i < 25; i++) {
		gotoxy(x, y + i);
		for (int j = 0; j < 30; j++) {
			switch (matrizLogo[i][j]) {
			case 0:
				cout << "  "; // Espacio doble para mantener el ancho
				break;
			case 1:
				SetConsoleTextAttribute(hConsole, 240); // Negro
				cout << char(219) << char(219); // Duplicar el carácter
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, 12); // Rosa
				cout << char(219) << char(219);
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, 7); // Rosa
				cout << char(219) << char(219);
				break;
			case 4:
				cout << "  ";
				break;
			case 5:
				cout << "  ";
				break;
			default:
				cout << "  ";
			}
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 7); // Restablecer color a normal
	// Antes de imprimir el texto
	SetConsoleTextAttribute(hConsole, 240); // Fondo blanco y texto negro
	gotoxy(2, 2); cout << "***** ****  ***** **   * ***** *****";
	gotoxy(2, 3); cout << "*     *   * *   * * *  *   *   *   *";
	gotoxy(2, 4); cout << "*  ** ****  ***** *  * *   *   *****";
	gotoxy(2, 5); cout << "*   * *  *  *   * *   ** * *   *   *";
	gotoxy(2, 6); cout << "***** *   * *   * *    * ***   *   *";
	// Restablecer colores originales

	gotoxy(12, 8); cout << "****  *****";
	gotoxy(12, 9); cout << "*   * *";
	gotoxy(12, 10); cout << "*   * ****";
	gotoxy(12, 11); cout << "*   * *";
	gotoxy(12, 12); cout << "****  *****";

	gotoxy(2, 15); cout << "***** ***** ****  ****  ***** *****";
	gotoxy(2, 16); cout << "*     *     *   * *   * *   * *";
	gotoxy(2, 17); cout << "*     ****  ****  *   * *   * *****";
	gotoxy(2, 18); cout << "*     *     *  *  *   * *   *     *";
	gotoxy(2, 19); cout << "***** ***** *   * ****  ***** *****";

	gotoxy(2, 21); cout << "*       * ***** *     ***** ***** **   * ***** ***** *****";
	gotoxy(2, 22); cout << " *     *  *   * *       *   *     * *  *   *   *     *";
	gotoxy(2, 23); cout << "  *   *   ***** *       *   ****  *  * *   *   ****  *****";
	gotoxy(2, 24); cout << "   * *    *   * *       *   *     *   **   *   *         *";
	gotoxy(2, 25); cout << "    *     *   * ***** ***** ***** *    *   *   ***** *****";

	gotoxy(77, 4); cout << "***** ***** ****  **    * ***** *****";
	gotoxy(77, 5); cout << "*     *   * *   * *  *  * *     *";
	gotoxy(77, 6); cout << "*     ***** ****  *   * * ****  *****";
	gotoxy(77, 7); cout << "*     *   * *  *  *    ** *         *";
	gotoxy(77, 8); cout << "***** *   * *   * *     * ***** *****";

	gotoxy(90, 10); cout << "****  *****";
	gotoxy(90, 11); cout << "*   * *";
	gotoxy(90, 12); cout << "*   * ****";
	gotoxy(90, 13); cout << "*   * *";
	gotoxy(90, 14); cout << "****  *****";

	gotoxy(77, 16); cout << "***** ***** *     ***** ****  ***** ****";
	gotoxy(77, 17); cout << "*     *   * *       *   *   * *   * *   *";
	gotoxy(77, 18); cout << "*     ***** *       *   *   * ***** *   *";
	gotoxy(77, 19); cout << "*     *   * *       *   *   * *   * *   *";
	gotoxy(77, 20); cout << "***** *   * ***** ***** ****  *   * ****";
	// Restablecer colores originales

	gotoxy(40, 27); cout << "Presione una tecla para ir al menu principal...";
	_getch();
	SetConsoleTextAttribute(hConsole, 7); // Fondo negro y texto blanco
}

void ProgramaPrincipal() {
	system("cls");
	bool repite = true;

	int opcionMenuPrincipal;
	int nOpcionesMenuPrincipal = 4;

	int opcionMenuPila;
	int nOpcionesMenuPila = 7;

	int opcionMenuCola;
	int nOpcionesMenuCola = 7;

	int opcionMenuLista;
	int nOpcionesMenuLista = 8;

	const char* tituloMenuPrincipal = "Menu Principal de la Granja";
	const char* opcionesMenuPrincipal[] = {
		"Gestionar Informacion de los cerdos (Pila)",
		"Gestionar Informacion de trabajadores (Cola)",
		"Gestionar Informacion de Compradores (Lista)",
		"Salir del programa"
	};

	const char* tituloMenuPila = "Menu de Gestion de cerdos (Pila)";
	const char* opcionesMenuPila[] = {
		"Ingresar un nuevo cerdo",
		"Ver cerdos",
		"Buscar cerdo",
		"Modificar informacion de algun cerdo",
		"Eliminar cerdo",
		"Regresar al menu principal",
		"Salir del programa"
	};

	const char* tituloMenuCola = "Gestionar personal de trabajadores (Cola)";
	const char* opcionesMenuCola[] = {
		"Ingresar un trabajador",
		"Ver trabajadores",
		"Buscar a un trabajador",
		"Modificar la informacion de algun trabajador",
		"Eliminar a un trabajador",
		"Regresar al menu principal",
		"Salir del programa"
	};

	const char* tituloMenuLista = "Gestionar compradores (Lista)";
	const char* opcionesMenuLista[] = {
		"Ingresar un comprador",
		"Ver compradores",
		"Buscar a un comprador",
		"Modificar la informacion de un comprador",
		"Eliminar a un comprador",
		"Vaciar la lista de compradores",
		"Regresar al menu principal",
		"Salir del programa"
	};

	Cerdo* pila = NULL;
	int arete = 0;
	int modulo = 0;
	string raza;
	char sexo;
	float peso = 0;
	float altura = 0;
	string nacimiento;
	int edad = 0;
	char salud;
	string ultVac;
	string feUlVac;
	float alimento = 0;
	string procede;
	char venta;
	float precio = 0;
	string destino;
	char rpt;

	ColaEmpleado empleados;
	int idEmpleadoBuscado = 0;
	int areteBuscado;
	Comprador* compradores = nullptr;
	int idCompradorBuscado = 0;
	Cerdo* cerdoEncontrado = nullptr;

	do {
		opcionMenuPrincipal = MenuPrincipal(tituloMenuPrincipal, opcionesMenuPrincipal, nOpcionesMenuPrincipal);
		switch (opcionMenuPrincipal) {
		case 1:
			do {
				opcionMenuPila = MenuPila(tituloMenuPila, opcionesMenuPila, nOpcionesMenuPila);
				switch (opcionMenuPila) {
				case 1:
					do {
						system("cls");
						TituloIngresaCerdo();
						gotoxy(35, 6); cout << "-------------------------------------------------------";
						arete = leerEntero("Ingrese el numero de arete del cerdo: ", 35, 7);
						modulo = leerEntero("Ingrese el modulo al que pertenece el cerdo: ", 35, 8);
						raza = leerCadena("Ingrese la raza del cerdo: ", 35, 9);
						sexo = leerCaracter("Ingrese el sexo del cerdo (H/M): ", "HM", 35, 10);
						peso = leerDecimal("Ingrese el peso del cerdo (Kg): ", 35, 11);
						altura = leerDecimal("Ingrese la altura del cerdo (cm): ", 35, 12);
						nacimiento = leerCadena("Ingrese la fecha de nacimiento (dd/mm/aa): ", 35, 13);
						edad = leerEntero("Ingrese la edad (meses): ", 35, 14);
						salud = leerCaracter("Estado de salud (E/R/M): ", "ERM", 35, 15);
						ultVac = leerCadena("Ultima vacuna aplicada: ", 35, 16);
						feUlVac = leerCadena("Fecha de la ultima vacuna (dd/mm/aa): ", 35, 17);
						alimento = leerDecimal("Alimento consumido (Kg): ", 35, 18);
						procede = leerCadena("Lugar de procedencia: ", 35, 19);
						venta = leerCaracter("Estado de venta (S/N): ", "SN", 35, 20);

						if (venta == 'S' || venta == 's') {
							precio = leerDecimal("Precio de venta (Q): ", 35, 21);
							destino = leerCadena("Destino (Consumo/Reproduccion/etc): ", 35, 22);
							gotoxy(35, 23); cout << "-------------------------------------------------------";
						}
						else {
							destino = leerCadena("Destino (Consumo/Reproduccion/etc): ", 35, 21);
							gotoxy(35, 22); cout << "-------------------------------------------------------";
						}
						agregarPila(pila, arete, modulo, raza, sexo, peso, altura, nacimiento, edad, salud, ultVac, feUlVac, alimento, procede, venta, precio, destino);
						rpt = leerCaracter("Desea ingresar otro cerdo? (S/N): ", "SN", 40, 25);

					} while (rpt == 'S');

					system("cls");
					TituloVerCerdos();
					mostrarPila(pila);
					break;
				case 2:
					system("cls");
					TituloVerCerdos();
					mostrarPila(pila);
					break;
				case 3:
					// Para buscar a algún cerdo de la pila
					do {
						system("cls");
						TituloBuscarCerdo();

						if (pila == nullptr) {
							gotoxy(40, 6); cout << "La pila esta vacia. No hay cerdos registrados para buscar.";
							gotoxy(40, 8); cout << "Presione una tecla para volver al menu de pila de cerdos...";
							_getch();
							break;
						}
						else {
							gotoxy(45, 7); cout << "Ingrese el arete del cerdo a buscar: "; cin >> areteBuscado;
							buscarCerdo(pila, areteBuscado, cerdoEncontrado);

							gotoxy(40, 28); cout << "¿Desea buscar otro cerdo? (S/N): ";
							cin >> rpt;
						}
					} while (rpt == 'S' || rpt == 's');
					break;
				case 4:
					system("cls");
					TituloModificarCerdo();
					modificarCerdo(pila);
					break;
				case 5:
					system("cls");
					TituloEliminarCerdo();
					eliminarCerdosPila(pila);
					break;
				case 6:
					break;
				case 7:
					repite = false;
					break;
				}
			} while (opcionMenuPila != 6 && repite);
			break;
		case 2:
			do {
				opcionMenuCola = MenuCola(tituloMenuCola, opcionesMenuCola, nOpcionesMenuCola);
				switch (opcionMenuCola) {
				case 1:
					system("cls");
					TituloIngresaTrabajador();
					gestionarIngresoEmpleados(q);

					system("cls");
					mostrarColaEmpleados(q);
					break;
				case 2:
					system("cls");
					TituloVerTrabajadores();
					mostrarColaEmpleados(q);
					break;
				case 3:
					system("cls");
					TituloBuscarTrabajador();
					gestionarBusquedaEmpleados(q);
					break;
				case 4:
					system("cls");
					TituloModificarTrabajador();
					modificarEmpleado(q);
					break;
				case 5:
					system("cls");
					TituloEliminaTrabajador();
					eliminarEmpleado(q);
					break;
				case 6:
					break;
				case 7:
					repite = false;
					break;
				}
			} while (opcionMenuCola != 6 && repite);
			break;
		case 3:
			do {
				opcionMenuLista = MenuLista(tituloMenuLista, opcionesMenuLista, nOpcionesMenuLista);
				switch (opcionMenuLista)
				{
				case 1:
					system("cls");
					TituloIngresaComprador();
					gestionarIngresoCompradores(compradores);
					_getch();
					break;
				case 2:
					system("cls");
					TituloVerCompradores();
					mostrarListaCompradores(compradores);
					_getch();
					break;
				case 3:
					system("cls");
					TituloBuscarComprador();
					gotoxy(5, 7); cout << "Ingrese el ID del comprador a buscar: "; cin >> idCompradorBuscado;
					buscarComprador(compradores, idCompradorBuscado);
					_getch();
					break;
				case 4:
					system("cls");
					TituloModificarComprador();
					modificarComprador(compradores);
					_getch();
					break;
				case 5:
					system("cls");
					TituloEliminaComprador();
					gotoxy(5, 7); cout << "Ingrese el ID del comprador a eliminar: "; cin >> idCompradorBuscado;
					sacarComprador(compradores, idCompradorBuscado);
					_getch();
					break;
				case 6:
					system("cls");
					TituloVaciarLista();
					eliminarCompradores(compradores, idCompradorBuscado);
					_getch();
					break;

				case 7:

					break;
				case 8:
					repite = false;
					break;
				}
			} while (opcionMenuLista != 8 && repite);
			break;
		case 4:
			repite = false;
			break;
		}
	} while (repite);
}


int MenuPrincipal(const char* tituloMenuPrincipal, const char* opcionesMenuPrincipal[], int nOpcionesMenuPrincipal) {
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;

	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "***             " << tituloMenuPrincipal << "            ***" << endl;
		gotoxy(30, 10); cout << "**********************************************************" << endl;

		for (int i = 0; i < nOpcionesMenuPrincipal; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesMenuPrincipal[i];
			}
			else {
				cout << "     " << opcionesMenuPrincipal[i];
			}
		}

		gotoxy(30, 15); cout << "**********************************************************" << endl;
		gotoxy(18, 26); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

		tecla = _getch(); // Captura la tecla presionada

		switch (tecla) {
		case 72: // Flecha arriba
			if (opcionSeleccionada > 1) opcionSeleccionada--;
			break;
		case 80: // Flecha abajo
			if (opcionSeleccionada < nOpcionesMenuPrincipal) opcionSeleccionada++;
			break;
		case 13: // Enter
			repite = false;
			break;
		}
	} while (repite);

	return opcionSeleccionada;

}

int MenuPila(const char* tituloMenuPila, const char* opcionesMenuPila[], int nOpcionesMenuPila) {
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;

	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "***          " << tituloMenuPila << "          ***" << endl;
		gotoxy(30, 10); cout << "**********************************************************" << endl;

		for (int i = 0; i < nOpcionesMenuPila; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesMenuPila[i];
			}
			else {
				cout << "     " << opcionesMenuPila[i];
			}
		}

		gotoxy(30, 18); cout << "**********************************************************" << endl;
		gotoxy(18, 20); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

		tecla = _getch(); // Captura la tecla presionada

		switch (tecla) {
		case 72: // Flecha arriba
			if (opcionSeleccionada > 1) opcionSeleccionada--;
			break;
		case 80: // Flecha abajo
			if (opcionSeleccionada < nOpcionesMenuPila) opcionSeleccionada++;
			break;
		case 13: // Enter
			repite = false;
			break;
		}
	} while (repite);

	return opcionSeleccionada;
}

int MenuLista(const char* tituloMenuLista, const char* opcionesMenuLista[], int nOpcionesMenuLista)
{
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;
	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "***          " << tituloMenuLista << "          ***" << endl;
		gotoxy(30, 10); cout << "**********************************************************" << endl;
		for (int i = 0; i < nOpcionesMenuLista; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesMenuLista[i];
			}
			else {
				cout << "     " << opcionesMenuLista[i];
			}
		}
		gotoxy(30, 19); cout << "**********************************************************" << endl;
		gotoxy(18, 20); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;
		tecla = _getch(); // Captura la tecla presionada
		switch (tecla) {
		case 72: // Flecha arriba
			if (opcionSeleccionada > 1) opcionSeleccionada--;
			break;
		case 80: // Flecha abajo
			if (opcionSeleccionada < nOpcionesMenuLista) opcionSeleccionada++;
			break;
		case 13: // Enter
			repite = false;
			break;
		}
	} while (repite);
	return opcionSeleccionada;
}


// Funcion para agregar cerdos a la pila
void agregarPila(Cerdo*& pila, int& arete, int& modulo, string& raza, char& sexo, float& peso, float& altura, string& nacimiento, int& edad, char& salud, string& ultVac, string& feUlVac, float& alimento, string& procede, char& venta, float& precio, string& destino) {
	Cerdo* nuevo_cerdo = new Cerdo();

	nuevo_cerdo->numArete = arete;
	nuevo_cerdo->numModulo = modulo;
	nuevo_cerdo->raza = raza;
	nuevo_cerdo->sexo = sexo;
	nuevo_cerdo->peso = peso;
	nuevo_cerdo->altura = altura;
	nuevo_cerdo->fechaNac = nacimiento;
	nuevo_cerdo->edad = edad;
	nuevo_cerdo->estadoSalud = salud;
	nuevo_cerdo->ultimaVacuna = ultVac;
	nuevo_cerdo->fechaUltimaVacuna = feUlVac;
	nuevo_cerdo->cantAlimento = alimento;
	nuevo_cerdo->procedencia = procede;
	nuevo_cerdo->venta = venta;
	nuevo_cerdo->precio = precio;
	nuevo_cerdo->destino = destino;
	nuevo_cerdo->siguiente = pila;
	pila = nuevo_cerdo;
}

void mostrarPila(Cerdo* pila) {
	if (pila == nullptr) {
		gotoxy(38, 7); cout << "La pila esta vacia. No hay cerdos registrados.";
		gotoxy(38, 9); cout << "Presione una tecla para volver a menu de la pila...";
		_getch();
		return;
	}

	Cerdo* aux = pila; // Puntero auxiliar para recorrer la pila

	while (aux != nullptr) {
		cout << endl;
		cout << "\t\t\t\t\t------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\tFicha del cerdo con el arete " << aux->numArete << endl;
		cout << "\t\t\t\t\t------------------------------------------------" << endl;
		cout << "\t\t\t\t\tRaza: " << aux->raza << endl;
		cout << "\t\t\t\t\tSexo (M = macho/H = Hembra): " << aux->sexo << endl;
		cout << "\t\t\t\t\tPeso (Kg): " << aux->peso << endl;
		cout << "\t\t\t\t\tAltura (cm): " << aux->altura << endl;
		cout << "\t\t\t\t\tEdad (meses): " << aux->edad << endl;
		cout << "\t\t\t\t\tSalud (E = Excelente/R = Regular/M = Mala): " << aux->estadoSalud << endl;
		cout << "\t\t\t\t\t------------------------------------------------" << endl;

		aux = aux->siguiente;  // Avanzamos al siguiente cerdo en la pila
	}

	cout << endl;
	cout << "\t\t\t\tPresione una tecla para volver al menu de pila de cerdos...";
	_getch();
}

void buscarCerdo(Cerdo* pila, int areteBuscado, Cerdo*& cerdoEncontrado) {
	cerdoEncontrado = nullptr; // Inicializar el puntero a nullptr

	Cerdo* aux = pila; // Puntero auxiliar para recorrer la pila
	while (aux != nullptr) {
		if (aux->numArete == areteBuscado) {
			cerdoEncontrado = aux;
			gotoxy(35, 8); cout << "------------------------------------------------";
			gotoxy(40, 9); cout << "Ficha del cerdo con el arete " << aux->numArete;
			gotoxy(35, 10); cout << "------------------------------------------------";
			gotoxy(35, 11); cout << "Modulo: " << aux->numModulo;
			gotoxy(35, 12); cout << "Raza: " << aux->raza;
			gotoxy(35, 13); cout << "Sexo (M = macho/H = Hembra): " << aux->sexo;
			gotoxy(35, 14); cout << "Peso (Kg): " << aux->peso;
			gotoxy(35, 15); cout << "Altura (cm): " << aux->altura;
			gotoxy(35, 16); cout << "Fecha de nacimiento(dd/mm/aa): " << aux->fechaNac;
			gotoxy(35, 17); cout << "Edad (meses): " << aux->edad;
			gotoxy(35, 18); cout << "Salud (E = Excelente/R = Regular/M = Mala): " << aux->estadoSalud;
			gotoxy(35, 19); cout << "Ultima vacuna: " << aux->ultimaVacuna;
			gotoxy(35, 20); cout << "Fecha de ultima vacunacion: " << aux->fechaUltimaVacuna;
			gotoxy(35, 21); cout << "Alimento consumido: " << aux->cantAlimento;
			gotoxy(35, 22); cout << "Procedencia: " << aux->procedencia;
			gotoxy(35, 23); cout << "Venta: " << aux->venta;
			gotoxy(35, 24); cout << "Destino: " << aux->destino;
			gotoxy(35, 25); cout << "Direccion de memoria de este nodo: " << aux;
			gotoxy(35, 26); cout << "------------------------------------------------";
			return;
		}
		aux = aux->siguiente;
	}

	gotoxy(45, 9); cout << "No se encontro ningun cerdo con el arete " << areteBuscado << ".";
	gotoxy(35, 11); cout << "Presione una tecla para volver al menu de pila de cerdos...";
	_getch();
}

void modificarCerdo(Cerdo* pila) {
	int areteBuscado = 0;  // Variable para buscar la ficha del cerdo por su número de arete
	Cerdo* cerdoEncontrado = nullptr; // Puntero para almacenar el cerdo encontrado
	char respuesta;

	if (pila == nullptr) {
		gotoxy(30, 6); cout << "La pila esta vacia. No hay cerdos registrados para modificar.";
		gotoxy(33, 8); cout << "Presione una tecla para volver al menu de pila de cerdos...";
		_getch();
		return;
	}

	gotoxy(25, 6); cout << "Ingrese el numero de arete del cerdo que desea modificar en la pila: ";
	cin >> areteBuscado;

	// Buscar el cerdo y mostrar su información
	buscarCerdo(pila, areteBuscado, cerdoEncontrado);

	if (cerdoEncontrado == nullptr) {
		return; // Si no se encontró el cerdo, salir de la función
	}

	// Preguntar si desea modificar el cerdo
	gotoxy(40, 28); cout << "Desea modificar este cerdo? (S/N): ";
	cin >> respuesta;
	if (respuesta != 'S' && respuesta != 's') {
		gotoxy(35, 30); cout << "Operación cancelada. Presione una tecla para volver al menu de pila de cerdos...";
		_getch();
		return;
	}

	system("cls");
	TituloModificarCerdo();
	// Ahora modificamos los datos, preguntando al usuario si desea cambiar cada uno
	gotoxy(40, 6); cout << "Modificando cerdo con el arete " << cerdoEncontrado->numArete << ".";

	// Modificar módulo
	gotoxy(35, 8); cout << "Modificar modulo (Actual: " << cerdoEncontrado->numModulo << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nuevo modulo: ";
		cin >> cerdoEncontrado->numModulo;
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar raza
	gotoxy(35, 8); cout << "Modificar raza (Actual: " << cerdoEncontrado->raza << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nueva raza: ";
		cin >> cerdoEncontrado->raza;
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar sexo
	gotoxy(35, 8); cout << "Modificar sexo (Actual: " << cerdoEncontrado->sexo << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nuevo sexo (M = macho / H = Hembra): ";
		cin >> cerdoEncontrado->sexo;
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar peso
	gotoxy(35, 8); cout << "Modificar peso (Actual: " << cerdoEncontrado->peso << " kg)? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nuevo peso (kg): ";
		cin >> cerdoEncontrado->peso;
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar altura
	gotoxy(35, 8); cout << "Modificar altura (Actual: " << cerdoEncontrado->altura << " cm)? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nueva altura (cm): ";
		cin >> cerdoEncontrado->altura;
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar fecha de nacimiento
	gotoxy(35, 8); cout << "Modificar fecha de nacimiento (Actual: " << cerdoEncontrado->fechaNac << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nueva fecha de nacimiento (dd/mm/aa): ";
		cin >> cerdoEncontrado->fechaNac;
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar edad
	gotoxy(35, 8); cout << "Modificar edad (Actual: " << cerdoEncontrado->edad << " meses)? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nueva edad (meses): ";
		cin >> cerdoEncontrado->edad;
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar estado de salud
	gotoxy(35, 8); cout << "Modificar salud (Actual: " << cerdoEncontrado->estadoSalud << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nuevo estado de salud (E = Excelente / R = Regular / M = Mala): ";
		cin >> cerdoEncontrado->estadoSalud;
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar última vacuna
	gotoxy(35, 8); cout << "Modificar ultima vacuna (Actual: " << cerdoEncontrado->ultimaVacuna << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nueva ultima vacuna: ";
		cin >> cerdoEncontrado->ultimaVacuna;
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar fecha última vacunación
	gotoxy(35, 8); cout << "Modificar fecha de última vacunacion (Actual: " << cerdoEncontrado->fechaUltimaVacuna << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nueva fecha de ultima vacunacion (dd/mm/aa): ";
		cin >> cerdoEncontrado->fechaUltimaVacuna;
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Confirmar cambio y terminar
	gotoxy(40, 11); cout << "Datos del cerdo modificados correctamente.";
	gotoxy(40, 13); cout << "Presione una tecla para volver al menu de pila de cerdos...";
	_getch();
}

void eliminarCerdosPila(Cerdo*& pila) {
	char respuesta;

	if (pila == nullptr) {
		gotoxy(40, 6); cout << "La pila esta vacia. No hay cerdos para eliminar.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menu de pila de cerdos...";
		_getch();
		return;
	}

	do {
		system("cls");
		TituloEliminarCerdo();
		mostrarPila(pila); // Mostrar la pila actualizada antes de eliminar
		sacarPila(pila);

		if (pila == nullptr) {
			gotoxy(40, 27); cout << "No hay más cerdos en la pila.";
			break;
		}

		gotoxy(40, 27); cout << "¿Desea eliminar otro cerdo? (S/N): ";
		cin >> respuesta;

	} while ((respuesta == 'S' || respuesta == 's') && pila != nullptr);

	gotoxy(40, 29); cout << "Operacion finalizada. Presione una tecla para volver al menu de pila...";
	_getch();
}

void sacarPila(Cerdo*& pila) {
	if (pila == nullptr) {
		gotoxy(40, 6); cout << "La pila esta vacia. No hay cerdos para eliminar.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menú de pila de cerdos...";
		_getch();
		return;
	}

	// Guardar referencia al cerdo que se eliminará
	Cerdo* aux = pila;

	// Mostrar información del cerdo que será eliminado
	gotoxy(48, 6); cout << "Se elimino el siguiente cerdo:";
	gotoxy(40, 8); cout << "-----------------------------------------";
	gotoxy(40, 9); cout << "Arete: " << aux->numArete;
	gotoxy(40, 10); cout << "Modulo: " << aux->numModulo;
	gotoxy(40, 11); cout << "Raza: " << aux->raza;
	gotoxy(40, 12); cout << "Sexo: " << aux->sexo;
	gotoxy(40, 13); cout << "Peso: " << aux->peso << " Kg";
	gotoxy(40, 14); cout << "Altura: " << aux->altura << " cm";
	gotoxy(40, 15); cout << "Edad: " << aux->edad << " meses";
	gotoxy(40, 16); cout << "Salud: " << aux->estadoSalud;
	gotoxy(40, 17); cout << "Ultima vacuna: " << aux->ultimaVacuna;
	gotoxy(40, 18); cout << "Fecha ultima vacunacion: " << aux->fechaUltimaVacuna;
	gotoxy(40, 19); cout << "Alimento consumido: " << aux->cantAlimento << " kg";
	gotoxy(40, 20); cout << "Procedencia: " << aux->procedencia;
	gotoxy(40, 21); cout << "Venta: " << aux->venta;
	gotoxy(40, 22); cout << "Destino: " << aux->destino;
	gotoxy(40, 23); cout << "-----------------------------------------";

	// Mover la cima de la pila al siguiente nodo
	pila = aux->siguiente;

	// Liberar memoria del nodo eliminado
	delete aux;

	gotoxy(30, 25); cout << "Operacion finalizada. Presione una tecla para continuar...";
	_getch();
}

int MenuCola(const char* tituloMenuCola, const char* opcionesMenuCola[], int nOpcionesMenuCola) {
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;

	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "***       " << tituloMenuCola << "       ***" << endl;
		gotoxy(30, 10); cout << "**********************************************************" << endl;

		for (int i = 0; i < nOpcionesMenuCola; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesMenuCola[i];
			}
			else {
				cout << "     " << opcionesMenuCola[i];
			}
		}

		gotoxy(30, 18); cout << "**********************************************************" << endl;
		gotoxy(18, 20); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

		tecla = _getch(); // Captura la tecla presionada

		switch (tecla) {
		case 72: // Flecha arriba
			if (opcionSeleccionada > 1) opcionSeleccionada--;
			break;
		case 80: // Flecha abajo
			if (opcionSeleccionada < nOpcionesMenuCola) opcionSeleccionada++;
			break;
		case 13: // Enter
			repite = false;
			break;
		}
	} while (repite);

	return opcionSeleccionada;
}

// Funcion para crear trabajadores a la cola de empleados
Empleado* crearEmpleado() {
	system("CLS");
	TituloIngresaTrabajador();
	Empleado* nuevo = new Empleado;

	gotoxy(35, 6); cout << "---------------------------------------------";
	nuevo->id = leerEntero("Ingrese ID del empleado: ", 35, 7);
	nuevo->nombre = leerCadena("Ingrese nombre: ", 35, 8);
	nuevo->fechaNacimiento = leerCadena("Ingrese fecha de nacimiento (dd/mm/aa): ", 35, 9);
	nuevo->genero = leerCaracter("Ingrese genero (M = Masculino/F = Femenino): ", "MF", 35, 10);
	nuevo->cargo = leerCadena("Ingrese puesto: ", 35, 11);
	nuevo->departamento = leerCadena("Ingrese departamento del puesto: ", 35, 12);
	nuevo->horario = leerCadena("Ingrese horario de trabajo: ", 35, 13);
	nuevo->telefono = leerCadena("Ingrese telefono: ", 35, 14);
	nuevo->direccion = leerCadena("Ingrese direccion de residencia: ", 35, 15);
	nuevo->salario = leerDecimal("Ingrese salario: Q", 35, 16);
	nuevo->estado = leerCadena("Ingrese estado civil (Soltero/Casado/Viudo): ", 35, 17);
	nuevo->beneficios = leerCadena("Ingrese beneficios: ", 35, 18);
	nuevo->fechaContratacion = leerCadena("Ingrese fecha de contratacion: ", 35, 19);
	gotoxy(35, 20); cout << "---------------------------------------------";
	nuevo->sgte = nullptr;
	return nuevo;
}

// Funcion para agregar nodo (empleado) a la cola de empleados
void encolarEmpleado(ColaEmpleado& q, Empleado* nuevo) {
	if (q.delante == nullptr) q.delante = nuevo;
	else q.atras->sgte = nuevo;
	q.atras = nuevo;
}

// Funcion para gestionar el ingreso de empleados a la cola de empleados (Si se ingresan mas o ya no)
void gestionarIngresoEmpleados(ColaEmpleado& q) {
	char rpt;
	do {
		Empleado* nuevo = crearEmpleado();
		encolarEmpleado(q, nuevo);
		gotoxy(35, 22); cout << "Empleado ingresado correctamente a la cola de empleados.";
		gotoxy(45, 24); cout << "Desea ingresar otro empleado? (S/N): ";
		cin >> rpt;
		cin.ignore(); // Limpiar buffer después de leer un carácter
	} while (rpt == 's' || rpt == 'S');
	gotoxy(40, 26); cout << "Presione una tecla para ver la cola actualizada...";
	_getch();
}

void mostrarColaEmpleados(ColaEmpleado q) {
	TituloVerTrabajadores();

	if (q.delante == nullptr) {
		gotoxy(45, 6); cout << "La cola de empleados esta vacia.";
		gotoxy(40, 8); cout << "Presione alguna tecla para volver al menu de colas...";
		_getch();
		return;
	}

	Empleado* aux = q.delante;
	int contador = 0;
	int fila = 6;
	int columna = 1;
	int ultimaFila = fila; // Guardará la última posición de fila usada

	while (aux) {
		gotoxy(columna, fila); cout << "----------------------------------";
		gotoxy(columna + 2, fila + 1); cout << "ID: " << aux->id;
		gotoxy(columna + 2, fila + 2); cout << "Nombre: " << aux->nombre;
		gotoxy(columna + 2, fila + 3); cout << "Genero: " << aux->genero;
		gotoxy(columna + 2, fila + 4); cout << "Cargo: " << aux->cargo;
		gotoxy(columna + 2, fila + 5); cout << "Telefono: " << aux->telefono;
		gotoxy(columna + 2, fila + 6); cout << "Fecha de Contratacion: " << aux->fechaContratacion;
		gotoxy(columna, fila + 7); cout << "----------------------------------";

		ultimaFila = fila + 7; // Guarda la última fila usada por la ficha actual

		contador++;
		if (contador % 3 == 0) {
			fila += 10;
			columna = 1;
		}
		else {
			columna += 39; // Aumentar mucho más la columna para evitar sobreposición
		}

		aux = aux->sgte;
	}

	// Mostrar el mensaje debajo de la última ficha mostrada
	gotoxy(30, ultimaFila + 2);
	cout << "Presione alguna tecla para volver al menu de colas...";
	_getch();
}


// Función para buscar un empleado en la cola de empleados y devolver sus datos
Empleado* buscarEmpleado(ColaEmpleado q, int idEmpleadoBuscado) {
	Empleado* aux = q.delante;
	while (aux) {
		if (aux->id == idEmpleadoBuscado) {
			return aux;
		}
		aux = aux->sgte;
	}
	return nullptr;
}

// Función para gestionar la búsqueda de empleados
void gestionarBusquedaEmpleados(ColaEmpleado q) {
	char rpt;
	int idEmpleadoBuscado;
	Empleado* empleadoEncontrado;
	int filaFinal = 0; // Variable para almacenar la última fila utilizada

	if (q.delante == nullptr) {
		gotoxy(45, 6); cout << "La cola de empleados esta vacia.";
		gotoxy(40, 8); cout << "Presione alguna tecla para volver al menu de colas...";
		_getch();
		return; // Salir de la función si la cola está vacía
	}

	do {
		system("cls");
		TituloBuscarTrabajador();
		gotoxy(45, 7); cout << "Ingrese el ID del trabajador a buscar: ";
		cin >> idEmpleadoBuscado;

		empleadoEncontrado = buscarEmpleado(q, idEmpleadoBuscado);

		if (empleadoEncontrado) {
			// Mostrar los datos del empleado encontrado
			gotoxy(40, 9); cout << "---------------------------------------------------";
			gotoxy(55, 10); cout << "ID: " << empleadoEncontrado->id;
			gotoxy(40, 11); cout << "Nombre: " << empleadoEncontrado->nombre;
			gotoxy(40, 12); cout << "Fecha de Nacimiento: " << empleadoEncontrado->fechaNacimiento;
			gotoxy(40, 13); cout << "Genero: " << empleadoEncontrado->genero;
			gotoxy(40, 14); cout << "Cargo: " << empleadoEncontrado->cargo;
			gotoxy(40, 15); cout << "Departamento: " << empleadoEncontrado->departamento;
			gotoxy(40, 16); cout << "Horario: " << empleadoEncontrado->horario;
			gotoxy(40, 17); cout << "Telefono: " << empleadoEncontrado->telefono;
			gotoxy(40, 18); cout << "Direccion: " << empleadoEncontrado->direccion;
			gotoxy(40, 19); cout << "Salario: " << empleadoEncontrado->salario;
			gotoxy(40, 20); cout << "Estado: " << empleadoEncontrado->estado;
			gotoxy(40, 21); cout << "Beneficios: " << empleadoEncontrado->beneficios;
			gotoxy(40, 22); cout << "Fecha de Contratacion: " << empleadoEncontrado->fechaContratacion;
			gotoxy(40, 23); cout << "---------------------------------------------------";
			filaFinal = 23; // Actualizar la última fila utilizada
		}
		else {
			gotoxy(45, 9); cout << "Empleado con ID " << idEmpleadoBuscado << " no encontrado.";
			filaFinal = 9; // Actualizar la última fila utilizada
		}

		gotoxy(45, filaFinal + 2); cout << "Desea buscar otro empleado? (S/N): ";
		cin >> rpt;
		cin.ignore(); // Limpiar buffer después de leer un carácter

	} while (rpt == 'S' || rpt == 's');

	gotoxy(35, filaFinal + 4); cout << "Presione una tecla para volver al menu de colas...";
	_getch();
}

void eliminarEmpleado(ColaEmpleado& q) {
	char respuesta;

	if (!q.delante) {
		system("cls");
		TituloEliminarCerdo();
		gotoxy(40, 6); cout << "La cola esta vacia, no hay empleados para eliminar.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menu de cola...";
		_getch();
		return;
	}

	do {
		system("cls");
		TituloEliminaTrabajador();
		mostrarColaEmpleados(q); // Mostrar la cola actualizada antes de eliminar

		system("cls");
		TituloEliminaTrabajador();
		Empleado* temp = q.delante;
		// Mostrar la información del empleado que se va a eliminar
		gotoxy(40, 6); cout << "---------------------------------------------------";
		gotoxy(50, 7); cout << "ID: " << temp->id;
		gotoxy(40, 8); cout << "Nombre: " << temp->nombre;
		gotoxy(40, 9); cout << "Fecha de Nacimiento: " << temp->fechaNacimiento;
		gotoxy(40, 10); cout << "Genero: " << temp->genero;
		gotoxy(40, 11); cout << "Cargo: " << temp->cargo;
		gotoxy(40, 12); cout << "Departamento: " << temp->departamento;
		gotoxy(40, 13); cout << "Horario: " << temp->horario;
		gotoxy(40, 14); cout << "Telefono: " << temp->telefono;
		gotoxy(40, 15); cout << "Direccion: " << temp->direccion;
		gotoxy(40, 16); cout << "Salario: " << temp->salario;
		gotoxy(40, 17); cout << "Estado: " << temp->estado;
		gotoxy(40, 18); cout << "Beneficios: " << temp->beneficios;
		gotoxy(40, 19); cout << "Fecha de Contratacion: " << temp->fechaContratacion;
		gotoxy(40, 20); cout << "---------------------------------------------------";

		// Preguntar si desea eliminar el empleado
		gotoxy(40, 22); cout << "Desea eliminar este empleado? (S/N): ";
		cin >> respuesta;
		if (respuesta == 'S' || respuesta == 's') {
			// Eliminar el primer empleado de la cola
			q.delante = q.delante->sgte;
			if (!q.delante) {
				q.atras = nullptr; // Si la cola queda vacía, actualizar el puntero 'atras'
			}
			delete temp;

			gotoxy(45, 24); cout << "Empleado eliminado correctamente.";
		}
		else {
			gotoxy(50, 24); cout << "Operacion cancelada.";
		}

		// Mostrar la cola actualizada después de eliminar
		mostrarColaEmpleados(q);

		if (!q.delante) {
			gotoxy(45, 26); cout << "No hay más empleados en la cola.";
			break;
		}

		gotoxy(45, 26); cout << "¿Desea eliminar otro empleado? (S/N): ";
		cin >> respuesta;

	} while ((respuesta == 'S' || respuesta == 's') && q.delante != nullptr);

	gotoxy(35, 28); cout << "Operacion finalizada. Presione una tecla para volver al menu de cola...";
	_getch();
}

void modificarEmpleado(ColaEmpleado& q) {
	int idEmpleadoBuscado = 0;  // Variable para buscar la ficha del empleado por su ID
	Empleado* emp = nullptr; // Puntero para almacenar el empleado encontrado
	char respuesta;

	if (q.delante == nullptr) {
		gotoxy(40, 6); cout << "La cola de empleados esta vacia.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menu de colas...";
		_getch();
		return;
	}

	do {
		system("cls");
		TituloModificarTrabajador();
		idEmpleadoBuscado = leerEntero("Ingrese el ID del trabajador a modificar: ", 40, 7);

		emp = buscarEmpleado(q, idEmpleadoBuscado);
		if (emp == nullptr) {
			gotoxy(40, 9); cout << "No se encontro ningun empleado con el ID " << idEmpleadoBuscado << ".";
			gotoxy(40, 10); cout << "¿Desea intentar con otro ID? (S/N): ";
			respuesta = leerCaracter("", "SN", 40, 11);
			if (respuesta != 'S' && respuesta != 's') {
				gotoxy(35, 13); cout << "Operación cancelada. Presione una tecla para volver al menu de empleados...";
				_getch();
				return;
			}
			continue; // Volver a preguntar por otro ID
		}

		// Preguntar si desea modificar el empleado
		gotoxy(40, 10); cout << "Desea modificar este empleado? (S/N): ";
		respuesta = leerCaracter("", "SN", 78, 10);
		if (respuesta != 'S' && respuesta != 's') {
			gotoxy(35, 12); cout << "Operación cancelada. Presione una tecla para volver al menu de empleados...";
			_getch();
			return;
		}

		// Modificar nombre
		do {
			system("cls");
			TituloModificarTrabajador();
			gotoxy(35, 7); cout << "Modificar nombre (Actual: " << emp->nombre << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				emp->nombre = leerCadena("Nuevo nombre: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar fecha de nacimiento
		do {
			system("cls");
			TituloModificarTrabajador();
			gotoxy(35, 7); cout << "Modificar fecha de nacimiento (Actual: " << emp->fechaNacimiento << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				emp->fechaNacimiento = leerCadena("Nueva fecha de nacimiento: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar género
		do {
			system("cls");
			TituloModificarTrabajador();
			gotoxy(35, 7); cout << "Modificar genero (Actual: " << emp->genero << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				emp->genero = leerCaracter("Nuevo genero (M/F): ", "MF", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar cargo
		do {
			system("cls");
			TituloModificarTrabajador();
			gotoxy(35, 7); cout << "Modificar cargo (Actual: " << emp->cargo << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				emp->cargo = leerCadena("Nuevo cargo: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar departamento
		do {
			system("cls");
			TituloModificarTrabajador();
			gotoxy(35, 7); cout << "Modificar departamento (Actual: " << emp->departamento << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				emp->departamento = leerCadena("Nuevo departamento: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar horario
		do {
			system("cls");
			TituloModificarTrabajador();
			gotoxy(35, 7); cout << "Modificar horario (Actual: " << emp->horario << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				emp->horario = leerCadena("Nuevo horario: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar teléfono
		do {
			system("cls");
			TituloModificarTrabajador();
			gotoxy(35, 7); cout << "Modificar telefono (Actual: " << emp->telefono << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				emp->telefono = leerCadena("Nuevo telefono: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar dirección
		do {
			system("cls");
			TituloModificarTrabajador();
			gotoxy(35, 7); cout << "Modificar direccion (Actual: " << emp->direccion << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				emp->direccion = leerCadena("Nueva direccion: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar salario
		do {
			system("cls");
			TituloModificarTrabajador();
			gotoxy(35, 7); cout << "Modificar salario (Actual: " << emp->salario << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				emp->salario = leerDecimal("Nuevo salario: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar estado
		do {
			system("cls");
			TituloModificarTrabajador();
			gotoxy(35, 7); cout << "Modificar estado (Actual: " << emp->estado << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				emp->estado = leerCadena("Nuevo estado: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar beneficios
		do {
			system("cls");
			TituloModificarTrabajador();
			gotoxy(35, 7); cout << "Modificar beneficios (Actual: " << emp->beneficios << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				emp->beneficios = leerCadena("Nuevos beneficios: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar fecha de contratación
		do {
			system("cls");
			TituloModificarTrabajador();
			gotoxy(35, 7); cout << "Modificar fecha de contratacion (Actual: " << emp->fechaContratacion << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				emp->fechaContratacion = leerCadena("Nueva fecha de contratacion: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Confirmar cambio y terminar
		gotoxy(40, 6); cout << "Datos del empleado modificados correctamente.";

		// Preguntar si desea modificar otro empleado
		gotoxy(35, 8); cout << "Desea modificar otro empleado? (S/N): ";
		respuesta = leerCaracter("", "SN", 73, 13);

	} while (respuesta == 'S' || respuesta == 's');
	gotoxy(40, 15); cout << "Presione una tecla para volver al menu de empleados...";
	_getch();
}

Comprador* CrearComprador() 
{
	Comprador* nuevo = new Comprador;

	// Validación para el ID
	do {
		gotoxy(45, 7); cout << "Ingrese ID del comprador: ";
		cin >> nuevo->id;
		if (nuevo->id <= 0) {
			gotoxy(45, 8); cout << "El ID debe ser un entero positivo.";
			_getch();
			borrarLinea(45, 8);
		}
	} while (nuevo->id <= 0);

	cin.ignore();
	// Limpiar buffer después de leer un entero
	gotoxy(35, 8); cout << "-----------------------------------------------------";
	gotoxy(45, 9); cout << "Ingrese nombre: "; getline(cin, nuevo->nombre);
	gotoxy(45, 10); cout << "Ingrese telefono: "; getline(cin, nuevo->telefono);
	gotoxy(45, 11); cout << "Ingrese direccion: "; getline(cin, nuevo->direccion);
	gotoxy(45, 12); cout << "Ingrese metodo de pago: "; getline(cin, nuevo->metodoPago);
	gotoxy(45, 13); cout << "Ingrese frecuencia de compra: "; getline(cin, nuevo->frecuenciaCompra);
	gotoxy(45, 14); cout << "Ingrese preferencias: "; getline(cin, nuevo->preferencias);
	gotoxy(45, 15); cout << "Ingrese fecha de registro: "; getline(cin, nuevo->fechaRegistro);
	gotoxy(45, 16); cout << "Ingrese estado de cuenta: "; getline(cin, nuevo->estadoCuenta);
	gotoxy(35, 17); cout << "-----------------------------------------------------";
	nuevo->sgte = nullptr;
	return nuevo;
}

void insertarComprador(Comprador*& compradores, Comprador* nuevo) {
	Comprador* aux1 = compradores, * aux2 = nullptr;

	while (aux1 != nullptr && aux1->id < nuevo->id) {
		aux2 = aux1;
		aux1 = aux1->sgte;
	}

	if (compradores == aux1) {
		nuevo->sgte = compradores; // Enlazar correctamente
		compradores = nuevo;
	}
	else {
		aux2->sgte = nuevo;
		nuevo->sgte = aux1;
	}
}

void gestionarIngresoCompradores(Comprador*& compradores) {
	char rpt;
	do {
		Comprador* nuevo = CrearComprador();
		insertarComprador(compradores, nuevo);
		gotoxy(35, 22); cout << "Comprador ingresado correctamente a la lista de compradores.";
		gotoxy(45, 24); cout << "Desea ingresar otro comprador? (s/n): ";
		cin >> rpt;
		cin.ignore(); // Limpiar buffer después de leer un carácter
	} while (rpt == 's' || rpt == 'S');
	gotoxy(45, 26); cout << "Presione una tecla para volver al menu de listas...";
	_getch();
}

void mostrarListaCompradores(Comprador* compradores)
{
	Comprador* aux = new Comprador();
	aux = compradores;
	while (aux != nullptr)
	{
		cout << "Presione alguna tecla";
		cout << endl;
		cout << "\t\t\t\t\t------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\tDatos de Comprador " << aux->id << endl;
		cout << "\t\t\t\t\t------------------------------------------------" << endl;
		cout << "\t\t\t\t\tNombre: " << aux->nombre << endl;
		cout << "\t\t\t\t\tTelefono : " << aux->telefono << endl;
		cout << "\t\t\t\t\tDireccion : " << aux->direccion << endl;
		cout << "\t\t\t\t\tMetodo de pago: " << aux->metodoPago << endl;
		cout << "\t\t\t\t\tFrecuencia de compra: " << aux->frecuenciaCompra << endl;
		cout << "\t\t\t\t\tEstado de cuenta: " << aux->estadoCuenta << endl;
		cout << "\t\t\t\t\t------------------------------------------------" << endl;

		aux = aux->sgte;
	}
	
}

Comprador* buscarComprador(Comprador* compradores, int idCompradorBuscado) {
	Comprador* aux = compradores;
	while (aux) 
	{
		
		if (aux->id == idCompradorBuscado)
		{
			gotoxy(35, 9); cout << "-----------------------------------------------------";
			gotoxy(45, 10); cout << "Nombre: " << aux->nombre;
			gotoxy(45, 11); cout << "Telefono: " << aux->telefono;
			gotoxy(45, 12); cout << "Direccion: " << aux->direccion;
			gotoxy(45, 13); cout << "Metodo de pago: " << aux->metodoPago;
			gotoxy(45, 14); cout << "Frecuencia de compra: " << aux->frecuenciaCompra;
			gotoxy(45, 15); cout << "Preferencias: " << aux->preferencias;
			gotoxy(45, 16); cout << "Fecha de registro: " << aux->fechaRegistro;
			gotoxy(45, 17); cout << "Estado de cuenta: " << aux->estadoCuenta;
			gotoxy(35, 18); cout << "-----------------------------------------------------";
			gotoxy(45, 19); cout << "Comprador encontrado.";
			gotoxy(45, 20); cout << "Presione una tecla para continuar...";
		}
		aux = aux->sgte;
	}
	gotoxy(45, 8); cout << "Comprador con el id " << idCompradorBuscado << " no encontrado.";
	_getch();
	
	return nullptr;
}

void modificarComprador(Comprador*& compradores) 
{
	int idCompradorBuscado = 0;
	Comprador* compradorEncontrado = nullptr;
	char respuesta;
	if (compradores == nullptr) 
	{
		gotoxy(40, 8); cout << "La lista de compradores esta vaccia";
		gotoxy(40, 9); cout << "Presione una tecla para volver al menu de listas...";
		_getch();
		return;
	}

	do 
	{
		gotoxy(45, 7); cout << "Ingrese el ID del comprador a modificar: ";
		cin >> idCompradorBuscado;
		compradorEncontrado = buscarComprador(compradores, idCompradorBuscado);
		gotoxy(40, 10); cout << "Desea modificar este comprador? (S/N): ";
		respuesta = leerCaracter("", "SN", 78, 10);
		if (respuesta != 'S' && respuesta != 's') 
		{
			gotoxy(35, 12); cout << "Operacion cancelada. Presione una tecla para volver al menu de compradores...";
			_getch();
			return;
		}
		// Modificar nombre
		do 
		{
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar nombre (Actual: " << compradorEncontrado->nombre << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's')
			{
				compradorEncontrado->nombre = leerCadena("Nuevo nombre: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');
		// Modificar telefono
		do
		{
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar telefono (Actual: " << compradorEncontrado->telefono << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') 
			{
				compradorEncontrado->telefono = leerCadena("Nuevo telefono: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');
		// Modificar direccion
		do 
		{
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar direccion (Actual: " << compradorEncontrado->direccion << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') 
			{
				compradorEncontrado->direccion = leerCadena("Nueva direccion: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');
		// Modificar metodo de pago
		do 
		{
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar metodo de pago (Actual: " << compradorEncontrado->metodoPago << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') 
			{
				compradorEncontrado->metodoPago = leerCadena("Nuevo metodo de pago: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');
		// Modificar frecuencia de compra
		do 
		{
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar frecuencia de compra (Actual: " << compradorEncontrado->frecuenciaCompra << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') 
			{
				compradorEncontrado->frecuenciaCompra = leerCadena("Nueva frecuencia de compra: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');
		// Modificar preferencias
		do 
		{
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar preferencias (Actual: " << compradorEncontrado->preferencias << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') 
			{
				compradorEncontrado->preferencias = leerCadena("Nuevas preferencias: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');
		// Modificar fecha de registro
		do
		{
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar fecha de registro (Actual: " << compradorEncontrado->fechaRegistro << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') 
			{
				compradorEncontrado->fechaRegistro = leerCadena("Nueva fecha de registro: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');
		// Modificar estado de cuenta
		do 
		{
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar estado de cuenta (Actual: " << compradorEncontrado->estadoCuenta << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's')
			{
				compradorEncontrado->estadoCuenta = leerCadena("Nuevo estado de cuenta: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');
		gotoxy(40, 6); cout << "Datos del comprador modificados correctamente.";
		gotoxy(45, 8); cout << "Desea modificar otro comprador? (S/N): ";
		respuesta = leerCaracter("", "SN", 78, 10);
	} while (respuesta == 'S' || respuesta == 's');
		gotoxy(40, 12); cout << "Presione una tecla para volver al menu de compradores...";
		_getch();
}
void sacarComprador(Comprador*& compradores, int idCompradorBuscado)
{
	Comprador* aux1 = compradores, * aux2 = nullptr;
	while (aux1 != nullptr && aux1->id != idCompradorBuscado) 
	{
		aux2 = aux1;
		aux1 = aux1->sgte;
	}
	if (aux1 == nullptr) {
		gotoxy(40, 9); cout << "No se encontro ningun comprador con el ID " << idCompradorBuscado << ".";
		gotoxy(40, 10); cout << "Presione una tecla para volver al menu de compradores...";
		_getch();
		return;
	}
	if (compradores == aux1) {
		compradores = compradores->sgte;
		delete aux1;
	}
	else 
	{
		aux2->sgte = aux1->sgte;
		delete aux1;
	}
	gotoxy(40, 6); cout << "Comprador eliminado correctamente.";
	gotoxy(40, 8); cout << "Presione una tecla para volver al menu de compradores...";
	_getch();
}
void eliminarCompradores(Comprador*& compradores, int idCompradorBuscado)
{
	Comprador* aux = compradores;
	if (aux == nullptr) {
		gotoxy(40, 8); cout << "No se encontro ningún comprador con el ID " << idCompradorBuscado << ".";
		gotoxy(40, 9); cout << "Presione una tecla para volver al menú de compradores...";
		_getch();
		return;
	}
	while (aux != nullptr) {
		Comprador* temp = aux;
		aux = aux->sgte;
		delete temp;
	}
	compradores = nullptr;
	gotoxy(40, 6); cout << "Compradores eliminados correctamente.";
	gotoxy(40, 8); cout << "Presione una tecla para volver al menú de compradores...";
	_getch();
}

int leerEntero(string mensaje, int x, int y) {
	int valor;
	while (true) {
		gotoxy(x, y); cout << mensaje;
		if (cin >> valor) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return valor;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			gotoxy(x, y + 1); cout << "Entrada invalida. Por favor, ingrese un numero entero.";
			gotoxy(x, y + 2); cout << "Presione una tecla para volver a intentarlo...";
			_getch();
			borrarLinea(x, y + 1); // Limpiar la línea de error
			borrarLinea(x, y + 2); // Limpiar la línea de error
			borrarLinea(x, y); // Limpiar la línea de entrada
		}
	}
}

double leerDecimal(string mensaje, int x, int y) {
	double valor;
	while (true) {
		gotoxy(x, y); cout << mensaje;
		if (cin >> valor) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return valor;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			gotoxy(x, y + 1); cout << "Entrada invalida. Por favor, ingrese un numero.";
			gotoxy(x, y + 2); cout << "Presione una tecla para volver a intentarlo...";
			_getch();
			borrarLinea(x, y + 1); // Limpiar la línea de error
			borrarLinea(x, y + 2); // Limpiar la línea de error
			borrarLinea(x, y); // Limpiar la línea de entrada
		}
	}
}

char leerCaracter(string mensaje, string opcionesValidas, int x, int y) {
	char c;
	while (true) {
		gotoxy(x, y); cout << mensaje;
		cin >> c;
		c = toupper(c);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (opcionesValidas.find(c) != string::npos)
			return c;
		else {
			gotoxy(x, y + 1); cout << "Entrada invalida. Por favor ingrese uno de estos caracteres: " << opcionesValidas;
			gotoxy(x, y + 2); cout << "Presione una tecla para volver a intentarlo...";
			_getch();
			borrarLinea(x, y + 1); // Limpiar la línea de error
			borrarLinea(x, y + 2); // Limpiar la línea de error
			borrarLinea(x, y); // Limpiar la línea de entrada
		}
	}
}

string leerCadena(string mensaje, int x, int y) {
	string texto;
	gotoxy(x, y); cout << mensaje;
	getline(cin, texto);
	return texto;
}

void borrarLinea(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	WORD wAttributes = csbi.wAttributes;
	int anchoConsola = csbi.dwSize.X;

	gotoxy(x, y);
	cout << string(anchoConsola - x, ' '); // Ajusta el número de espacios según el ancho de la consola
	gotoxy(x, y); // Vuelve a colocar el cursor al inicio de la línea

	SetConsoleTextAttribute(hConsole, wAttributes); // Restaurar los atributos de color originales
}

void TituloIngresaCerdo() {
	gotoxy(35, 0); cout << "***********************************************";
	gotoxy(35, 1); cout << "*                                            **";
	gotoxy(35, 2); cout << "**     Ingresando informacion del cerdo      **";
	gotoxy(35, 3); cout << "**                                           **";
	gotoxy(35, 4); cout << "***********************************************";
}

void TituloVerCerdos() {
	gotoxy(37, 0); cout << "*****************************************************";
	gotoxy(37, 1); cout << "**                                                 **";
	gotoxy(37, 2); cout << "**     Viendo informacion de la pila de cerdos     **";
	gotoxy(37, 3); cout << "**                                                 **";
	gotoxy(37, 4); cout << "*****************************************************";
}

void TituloBuscarCerdo() {
	gotoxy(45, 0); cout << "***************************************";
	gotoxy(45, 1); cout << "**                                   **";
	gotoxy(45, 2); cout << "**     Buscando cerdo de la pila     **";
	gotoxy(45, 3); cout << "**                                   **";
	gotoxy(45, 4); cout << "***************************************";
}

void TituloModificarCerdo() {
	gotoxy(35, 0); cout << "***********************************************";
	gotoxy(35, 1); cout << "**                                           **";
	gotoxy(35, 2); cout << "**     Modificando informacion del cerdo     **";
	gotoxy(35, 3); cout << "**                                           **";
	gotoxy(35, 4); cout << "***********************************************";
}

void TituloEliminarCerdo() {
	gotoxy(45, 0); cout << "*****************************************";
	gotoxy(45, 1); cout << "**                                     **";
	gotoxy(45, 2); cout << "**     Eliminando cerdo de la pila     **";
	gotoxy(45, 3); cout << "**                                     **";
	gotoxy(45, 4); cout << "*****************************************";
}

void TituloIngresaTrabajador() {
	gotoxy(30, 0); cout << "*************************************************************";
	gotoxy(30, 1); cout << "**                                                         **";
	gotoxy(30, 2); cout << "**     Ingresando trabajador a la cola de trabajadores     **";
	gotoxy(30, 3); cout << "**                                                         **";
	gotoxy(30, 4); cout << "*************************************************************";
}

void TituloVerTrabajadores() {
	gotoxy(40, 0); cout << "********************************************";
	gotoxy(40, 1); cout << "**                                        **";
	gotoxy(40, 2); cout << "**     Viendo la cola de trabajadores     **";
	gotoxy(40, 3); cout << "**                                        **";
	gotoxy(40, 4); cout << "********************************************";
}

void TituloBuscarTrabajador() {
	gotoxy(40, 0); cout << "********************************************";
	gotoxy(40, 1); cout << "**                                        **";
	gotoxy(40, 2); cout << "**     Buscando trabajador en la cola     **";
	gotoxy(40, 3); cout << "**                                        **";
	gotoxy(40, 4); cout << "********************************************";
}

void TituloModificarTrabajador() {
	gotoxy(45, 0); cout << "************************************";
	gotoxy(45, 1); cout << "**                                **";
	gotoxy(45, 2); cout << "**     Modificando trabajador     **";
	gotoxy(45, 3); cout << "**                                **";
	gotoxy(45, 4); cout << "************************************";
}

void TituloEliminaTrabajador() {
	gotoxy(40, 0); cout << "********************************************";
	gotoxy(40, 1); cout << "**                                        **";
	gotoxy(40, 2); cout << "**    Eliminando trabajador de la cola    **";
	gotoxy(40, 3); cout << "**                                        **";
	gotoxy(40, 4); cout << "********************************************";
}

void TituloIngresaComprador() {
	gotoxy(35, 0); cout << "*************************************************************";
	gotoxy(35, 1); cout << "**                                                         **";
	gotoxy(35, 2); cout << "**     Ingresando comprador a la lista de compradores      **";
	gotoxy(35, 3); cout << "**                                                         **";
	gotoxy(35, 4); cout << "*************************************************************";
}

void TituloVerCompradores() {
	gotoxy(45, 0); cout << "********************************************";
	gotoxy(45, 1); cout << "**                                        **";
	gotoxy(45, 2); cout << "**     Viendo la lista de compradores     **";
	gotoxy(45, 3); cout << "**                                        **";
	gotoxy(45, 4); cout << "********************************************";
}

void TituloBuscarComprador() {
	gotoxy(45, 0); cout << "********************************************";
	gotoxy(45, 1); cout << "**                                        **";
	gotoxy(45, 2); cout << "**     Buscando comprador en la lista     **";
	gotoxy(45, 3); cout << "**                                        **";
	gotoxy(45, 4); cout << "********************************************";
}

void TituloModificarComprador() {
	gotoxy(50, 0); cout << "************************************";
	gotoxy(50, 1); cout << "**                                **";
	gotoxy(50, 2); cout << "**     Modificando comprador      **";
	gotoxy(50, 3); cout << "**                                **";
	gotoxy(50, 4); cout << "************************************";
}

void TituloEliminaComprador() {
	gotoxy(45, 0); cout << "********************************************";
	gotoxy(45, 1); cout << "**                                        **";
	gotoxy(45, 2); cout << "**    Eliminando comprador de la lista    **";
	gotoxy(45, 3); cout << "**                                        **";
	gotoxy(45, 4); cout << "********************************************";
}

void TituloVaciarLista() {
	gotoxy(45, 0); cout << "********************************************";
	gotoxy(45, 1); cout << "**                                        **";
	gotoxy(45, 2); cout << "**    Vaciando la lista de compradores    **";
	gotoxy(45, 3); cout << "**                                        **";
	gotoxy(45, 4); cout << "********************************************";
}

// Función para mover el cursor a una posición específica en la consola
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

// Implementación de la función de manejo de eventos de control
BOOL WINAPI ConsoleHandler(DWORD event) {
	switch (event) {
	case CTRL_CLOSE_EVENT:
		// Código a ejecutar cuando se cierra la ventana de la consola
		cout << "Cerrando el programa..." << endl;
		// Finaliza el programa
		exit(0);
		return TRUE;
	default:
		return FALSE;
	}
}