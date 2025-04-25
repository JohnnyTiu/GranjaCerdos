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
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <limits> // Incluir la librería <limits>
#pragma comment(lib, "winmm.lib")

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

struct Comprador {
	int id;
	string nombre;
	string telefono;
	string direccion;
	string metodoPago;
	string frecuenciaCompra;
	string preferencias;
	string fechaRegistro;
	string estadoCuenta;
	struct Comprador* sgte;
};

struct Proveedor {
	int id;
	string nombre;
	string direccion;
	string telefono;
	string correo;
	string productos;
	string fechaRegistro;
	string estado;
	struct Proveedor* siguiente;
};

// Estructura para Alimentos (Lista Doblemente Enlazada)
struct Alimento {
	int codigo;
	string marca;
	string fechaCaducacion;
	int cantidad;
	string categoria;
	string proveedor;
	float precio;
	string paisOrigen;
	struct Alimento* anterior;
	struct Alimento* siguiente;
};


typedef Proveedor* Lista;
typedef Proveedor* pNodo;

// Estructuras para la vacunación de cerdos (ABB)
struct FichaVacunacion {
	int id;
	string fechaVacAct;
	string nombreVacAct;
	string fechaVacSig;
	string nombreVacSig;
};

struct Vacuna {
	FichaVacunacion ficha; // Usar la nueva estructura
	Vacuna* izq;
	Vacuna* der;
};

void umg();
void Integrantes();
void PantallaLogo();
void ProgramaPrincipal();
int MenuPrincipal(const char* tituloMenuPrincipal, const char* opcionesMenuPrincipal[], int nOpcionesMenuPrincipal);
// Prototipos para el manejo de funciones de la pila de cerdos
int MenuPila(const char* tituloMenuPila, const char* opcionesMenuPila[], int nOpcionesMenuPila);
void TituloIngresaCerdo();
void TituloVerCerdos();
void TituloBuscarCerdo();
void TituloModificarCerdo();
void TituloEliminarCerdo();
void TituloVaciarPila();
void agregarPila(Cerdo*& pila, int& arete, int& modulo, string& raza, char& sexo, float& peso, float& altura, string& nacimiento, int& edad, char& salud, string& ultVac, string& feUlVac, float& alimento, string& procede, char& venta, float& precio, string& destino);
void mostrarPila(Cerdo* pila);
void buscarCerdo(Cerdo* pila, int areteBuscado, Cerdo*& cerdoEncontrado);
void modificarCerdo(Cerdo* pila);
void eliminarCerdosPila(Cerdo*& pila);
void sacarPila(Cerdo*& pila);
void vaciarPila(Cerdo*& pila);
// Prototipos para el manejo de funciones de la cola de empleados
int MenuCola(const char* tituloMenuCola, const char* opcionesMenuCola[], int nOpcionesMenuCola);
void TituloIngresaTrabajador();
void TituloVerTrabajadores();
void TituloBuscarTrabajador();
void TituloModificarTrabajador();
void TituloEliminaTrabajador();
void TituloVaciarCola();
Empleado* crearEmpleado();
void encolarEmpleado(ColaEmpleado& q, Empleado* nuevo);
void gestionarIngresoEmpleados(ColaEmpleado& q);
void mostrarColaEmpleados(ColaEmpleado q);
Empleado* buscarEmpleado(ColaEmpleado q, int idEmpleadoBuscado);
void gestionarBusquedaEmpleados(ColaEmpleado q);
void modificarEmpleado(ColaEmpleado& q);
void eliminarEmpleado(ColaEmpleado& q);
void vaciarCola(ColaEmpleado& q);
//prototipos para el manejo de funiones de los compradores
int MenuLista(const char* tituloMenuLista, const char* opcionesMenuLista[], int nOpciones);
void TituloIngresaComprador();
void TituloVerCompradores();
void TituloBuscarComprador();
void TituloModificarComprador();
void TituloEliminaComprador();
void TituloVaciarLista();
Comprador* CrearComprador();
void insertarComprador(Comprador*& compradores, Comprador* nuevo);
void gestionarIngresoCompradores(Comprador*& compradores);
void mostrarListaCompradores(Comprador*);
Comprador* buscarComprador(Comprador* compradores, int idCompradorBuscado);
void modificarComprador(Comprador*& compradores);
void sacarComprador(Comprador*& compradores, int idCompradorBuscado);
void eliminarCompradores(Comprador*& compradores, int idCompradorBuscado);
//Prototipos para el menejo de funciones de productos (Lista doble)
int MenuListaDoble(const char* tituloMenuListaDoble, const char* opcionesMenuListaDoble[], int nOpcionesMenuListaDoble);
void TituloIngresaAlimento();
void TituloVerAlimento();
void TituloBuscarAlimento();
void TituloModificarAlimento();
void TituloEliminarAlimento();
void TituloVaciarListaAlimento();
void agregarAlimento(Alimento*& cabeza, Alimento*& cola, int codigo, string marca, string fechaCaducacion, int cantidad, string categoria, string proveedor, float precio, string paisOrigen);
int contarElementos(Alimento* cabeza0);
void mostrarListaAlimentos(Alimento* cabeza);
Alimento* buscarAlimento(Alimento* cabeza, int codigoBuscado);
void modificarAlimento(Alimento* cabeza);
void eliminarAlimento(Alimento*& cabeza, Alimento*& cola, int codigoBuscado);
void vaciarListaAlimentos(Alimento*& cabeza, Alimento*& cola);
//Prototipos para el manejo de funciones de proveedores (Lista circular)
int MenuListaCircular(const char* tituloMenuListaCircular, const char* opcionesMenuListaCircular[], int nOpcionesListaCircular);
void TituloInsertaProveedor();
void TituloVerProveedores();
void TituloModificarProveedor();
void TituloBuscarProveedor();
void TituloEliminarProveedor();
void TituloVaciarListaProveedores();
void InsertarProveedor(Lista* lista, int id, string nombre, string direccion, string telefono, string correo, string productos, string fechaRegistro, string estado);
void BorrarProveedor(Lista* lista, int id);
void MostrarProveedores(Lista lista);
void BuscarProveedor(Lista lista, int id);
void modificarProveedor(Lista* lista);
void VaciarListaProveedores(Lista* lista);
//Prototipos para el manejo de funciones de la vacunacion de cerdos (ABB)
int MenuABB(const char* tituloMenuABB, const char* opcionesMenuABB[], int nOpcionesMenuABB);
void TituloIngresaFicha();
void TituloVerABB();
void TituloBuscarFicha();
void TituloRecorrerABB();
void TituloEliminarFicha();
void TituloVaciarABB();
Vacuna* crearNodo(const FichaVacunacion& ficha);
Vacuna* insertarNodo(Vacuna* raiz, const FichaVacunacion& ficha);
Vacuna* buscarNodo(Vacuna* raiz, int id);
Vacuna* eliminarNodo(Vacuna* raiz, int id);
void mostrarNodo(Vacuna* nodo, int x, int y);
void mostrarArbol(Vacuna* raiz);
void recorrerPreorden(Vacuna* raiz, int x_base, int y_base, int& offset);
void recorrerInorden(Vacuna* raiz, int x_base, int y_base, int& offset);
void recorrerPostorden(Vacuna* raiz, int x_base, int y_base, int& offset);
Vacuna* nodoMinimo(Vacuna* nodo);
Vacuna* nodoMaximo(Vacuna* nodo);
Vacuna* eliminarNodo(Vacuna* raiz, int id, bool usarMinimoDerecha = true);
void eliminarFicha(Vacuna*& arbol);
void vaciarArbol(Vacuna*& raiz);
// Funciones extras para el programa
void gotoxy(int, int);
int leerEntero(string mensaje, int x, int y);
double leerDecimal(string mensaje, int x, int y);
char leerCaracter(string mensaje, string opcionesValidas, int x, int y);
string leerCadena(string mensaje, int x, int y);
void borrarLinea(int x, int y);
void cambiarColorConsola(WORD texto, WORD fondo);
BOOL WINAPI ConsoleHandler(DWORD event);	// Prototipo de la función de manejo de evententos por si el usuario cierra la consola con la x


ColaEmpleado q = { nullptr, nullptr }; // Inicializar la cola vacía

int main() {
	// Registra la función de manejo de eventos de control
	SetConsoleCtrlHandler(ConsoleHandler, TRUE);

	PlaySound(TEXT("C:\\Users\\Johnn\\OneDrive\\Documentos\\5semestre\\Progra3\\GranjaCerdos\\granja.mp3"), NULL, SND_ASYNC);
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
	int nOpcionesMenuPrincipal = 7;

	int opcionMenuPila;
	int nOpcionesMenuPila = 8;

	int opcionMenuCola;
	int nOpcionesMenuCola = 8;

	int opcionMenuLista;
	int nOpcionesMenuLista = 8;

	int opcionMenuListaDoble;
	int nOpcionesMenuListaDoble = 8;

	int opcionMenuListaCircular;
	int nOpcionesMenuListaCircular = 8;

	int opcionMenuABB;
	int nOpcionesMenuABB = 8;

	const char* tituloMenuPrincipal = "Menu Principal de la Granja";
	const char* opcionesMenuPrincipal[] = {
		"Gestionar Informacion de los cerdos (Pila)",
		"Gestionar Informacion de trabajadores (Cola)",
		"Gestionar Informacion de los Compradores (Lista simple)",
		"Gestionar Informacion de los Productos (Lista doble)",
		"Gestionar Informacion de los proveedores (Lista circular)",
		"Gestionar Informacion de la vacunacion de cerdos (ABB)",
		"Salir del programa"
	};

	const char* tituloMenuPila = "Menu de Gestion de cerdos (Pila)";
	const char* opcionesMenuPila[] = {
		"Ingresar un nuevo cerdo",
		"Ver cerdos",
		"Buscar cerdo",
		"Modificar informacion de algun cerdo",
		"Eliminar cerdo",
		"Vaciar pila de cerdos",
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
		"Vaciar cola de trabajadores",
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

	const char* tituloMenuListaDoble = "Gestion de Alimentos (Lista Doblemente Enlazada)";
	const char* opcionesMenuListaDoble[] = {
		"Ingresar un nuevo alimento",
		"Ver alimentos registrados",
		"Buscar un alimento",
		"Modificar informacion de un alimento",
		"Eliminar un alimento",
		"Vaciar la lista de alimentos",
		"Regresar al menu principal",
		"Salir del programa"
	};

	const char* tituloMenuListaCircular = "Gestionar Proveedores (Lista Circular)";
	const char* opcionesMenuListaCircular[] = {
		"Ingresar proveedores",
		"Buscar proveedores",
		"Modificar proveedores",
		"Eliminar proveedores",
		"Ver lista proveedores",
		"Vaciar lista de proveedores",
		"Regresar al menu principal",
		"Salir del programa"
	};

	const char* tituloMenuABB = "Gestionar vacunacion de cerdos (ABB)";
	const char* opcionesMenuABB[] = {
		"Insertar ficha de vacunacion",
		"Buscar ficha de vacunacion",
		"Ver estructura de vacunacion",
		"Recorrer la estructura de vacunacion (Pre, In, Post)",
		"Eliminar ficha de la estructura",
		"Vaciar la estructura",
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
	Cerdo* cerdoEncontrado = nullptr;

	Comprador* compradores = nullptr;
	int idCompradorBuscado = 0;


	int id = 0;
	string nombre;
	string direccion;
	string telefono;
	string correo;
	string productos;
	string fechaRegistro;
	string estado;


	Lista* lista = new Proveedor*; // Inicializar la lista correctamente
	*lista = nullptr; // Inicializar la lista a un estado vacío

	Alimento* cabeza = nullptr;
	Alimento* cola = nullptr;
	int codigoBuscado = 0;

	//Variables para el manejo de la vacunacion de cerdos (ABB)
	FichaVacunacion fichaActual;
	Vacuna* arbol = nullptr;
	int idFichaBuscar = 0;
	int idFichaEliminar = 0;
	int x = 35;
	int y = 31; 
	int offset = 0;

	do {
		system("color 1F");  // Fondo azul, letra blanca brillante
		opcionMenuPrincipal = MenuPrincipal(tituloMenuPrincipal, opcionesMenuPrincipal, nOpcionesMenuPrincipal);
		switch (opcionMenuPrincipal) {
		case 1:
			do {
				system("color 2E");  // Fondo verde, letra amarilla clara
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
							gotoxy(45, 6); cout << "Ingrese el arete del cerdo a buscar: "; cin >> areteBuscado;
							buscarCerdo(pila, areteBuscado, cerdoEncontrado);

							gotoxy(45, 28); cout << "Desea buscar otro cerdo? (S/N): ";
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

					system("cls");
					TituloEliminarCerdo();
					gotoxy(50, 6); cout << "Pila actualizada...";
					mostrarPila(pila);
					break;
				case 6:
					system("cls");
					TituloVaciarPila();
					vaciarPila(pila);
					break;
				case 7:
					break;
				case 8:
					repite = false;
					break;
				}
			} while (opcionMenuPila != 7 && repite);
			break;
		case 2:
			do {
				system("color 4F");  // Fondo rojo, letra blanca brillante
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
					system("cls");
					TituloVaciarCola();
					vaciarCola(q);
					break;
				case 7:
					break;
				case 8:
					repite = false;
					break;
				}
			} while (opcionMenuCola != 7 && repite);
			break;
		case 3:
			do {
				system("color 0A");
				opcionMenuLista = MenuLista(tituloMenuLista, opcionesMenuLista, nOpcionesMenuLista);
				switch (opcionMenuLista)
				{
				case 1:
						system("cls");
						TituloIngresaComprador();
						gestionarIngresoCompradores(compradores);
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
					idCompradorBuscado = leerEntero("Ingrese el ID del comprador a buscar: ", 5, 7);
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
					idCompradorBuscado = leerEntero("Ingrese el ID del comprador a eliminar: ", 5, 7);
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
			} while (opcionMenuLista != 7 && repite);
			break;
		case 4:
			do {
				system("color 8F");
				opcionMenuListaDoble = MenuListaDoble(tituloMenuListaDoble, opcionesMenuListaDoble, nOpcionesMenuListaDoble);
				switch (opcionMenuListaDoble)
				{
				case 1:
					do
					{
						system("cls");
						TituloIngresaAlimento();
						gotoxy(35, 6); cout << "-------------------------------------------------------";
						int codigo = leerEntero("Ingrese el codigo del alimento: ", 35, 7);
						string marca = leerCadena("Ingrese la marca del alimento: ", 35, 8);
						string fechaCad = leerCadena("Ingrese la fecha de caducidad (dd/mm/aa): ", 35, 9);
						int cantidad = leerEntero("Ingrese la cantidad disponible: ", 35, 10);
						string categoria = leerCadena("Ingrese la categoria del alimento: ", 35, 11);
						string proveedor = leerCadena("Ingrese el proveedor: ", 35, 12);
						float precio = leerDecimal("Ingrese el precio: ", 35, 13);
						string paisOrigen = leerCadena("Ingrese el pais de origen: ", 35, 14);
						gotoxy(35, 15); cout << "-------------------------------------------------------";

						agregarAlimento(cabeza, cola, codigo, marca, fechaCad, cantidad, categoria, proveedor, precio, paisOrigen);
						rpt = leerCaracter("Desea ingresar otro alimento? (S/N): ", "SN", 40, 17);

					} while (rpt == 'S' || rpt == 's');
					system("cls");
					TituloVerAlimento();
					mostrarListaAlimentos(cabeza);
					_getch();
					break;
				case 2:
					system("cls");
					TituloVerAlimento();
					mostrarListaAlimentos(cabeza);
					_getch();
					break;
				case 3:
					do {
						system("cls");
						TituloBuscarAlimento();

						if (cabeza == nullptr) {
							gotoxy(40, 6); cout << "La lista esta vacia. No hay alimentos registrados para buscar.";
							gotoxy(40, 8); cout << "Presione una tecla para volver al menu de alimentos...";
							_getch();
							break;
						}
						else {
							gotoxy(45, 7); cout << "Ingrese el codigo del alimento a buscar: ";
							cin >> codigoBuscado;
							Alimento* alimentoEncontrado = buscarAlimento(cabeza, codigoBuscado);

							if (alimentoEncontrado != nullptr) {
								gotoxy(35, 9); cout << "------------------------------------------------";
								gotoxy(40, 10); cout << "Informacion del alimento con codigo " << alimentoEncontrado->codigo;
								gotoxy(35, 11); cout << "------------------------------------------------";
								gotoxy(35, 12); cout << "Marca: " << alimentoEncontrado->marca;
								gotoxy(35, 13); cout << "Fecha de caducidad: " << alimentoEncontrado->fechaCaducacion;
								gotoxy(35, 14); cout << "Cantidad: " << alimentoEncontrado->cantidad;
								gotoxy(35, 15); cout << "Categoria: " << alimentoEncontrado->categoria;
								gotoxy(35, 16); cout << "Proveedor: " << alimentoEncontrado->proveedor;
								gotoxy(35, 17); cout << "Precio: " << alimentoEncontrado->precio;
								gotoxy(35, 18); cout << "Pais de origen: " << alimentoEncontrado->paisOrigen;
								gotoxy(35, 19); cout << "------------------------------------------------";
							}
							else {
								gotoxy(45, 9); cout << "No se encontro ningun alimento con el codigo " << codigoBuscado << ".";
							}

							gotoxy(40, 24); cout << "¿Desea buscar otro alimento? (S/N): ";
							cin >> rpt;
						}
					} while (rpt == 'S' || rpt == 's');
					break;
				case 4:
					system("cls");
					TituloModificarAlimento();
					modificarAlimento(cabeza);
					break;
				case 5:
					system("cls");
					TituloEliminarAlimento();
					if (cabeza == nullptr) {
						gotoxy(40, 6); cout << "La lista esta vacia. No hay alimentos para eliminar.";
						gotoxy(40, 8); cout << "Presione una tecla para volver al menu de alimentos...";
						_getch();
						break;
					}
					gotoxy(45, 7); cout << "Ingrese el codigo del alimento a eliminar: ";
					cin >> codigoBuscado;
					eliminarAlimento(cabeza, cola, codigoBuscado);
					_getch();
					break;
				case 6:
					system("cls");
					TituloVaciarListaAlimento();
					vaciarListaAlimentos(cabeza, cola);
					_getch();
					break;
				case 7:
					break;
				case 8:
					repite = false;
					break;
				}
			} while (opcionMenuListaDoble != 7 && repite);
			break;
		case 5:
			do {
				system("color 6F");  // Fondo amarillo, letra rojo claro
				opcionMenuListaCircular = MenuListaCircular(tituloMenuListaCircular, opcionesMenuListaCircular, nOpcionesMenuListaCircular);
				switch (opcionMenuListaCircular) {
				case 1:
					do {
						system("cls");
						TituloInsertaProveedor();
						gotoxy(35, 6); cout << "------------------------------------------------";
						id = leerEntero("Ingrese el ID del proveedor: ", 35, 7);
						nombre = leerCadena("Ingrese el nombre del proveedor: ", 35, 8);
						direccion = leerCadena("Ingrese la direccion del proveedor: ", 35, 9);
						telefono = leerCadena("Ingrese el telefono del proveedor: ", 35, 10);
						correo = leerCadena("Ingrese el correo del proveedor: ", 35, 11);
						productos = leerCadena("Ingrese los productos que ofrece el proveedor: ", 35, 12);
						fechaRegistro = leerCadena("Ingrese la fecha de registro del proveedor (dd/mm/aa): ", 35, 13);
						estado = leerCadena("Ingrese el estado del proveedor (Activo/Inactivo): ", 35, 14);
						gotoxy(35, 15); cout << "------------------------------------------------";
						InsertarProveedor(lista, id, nombre, direccion, telefono, correo, productos, fechaRegistro, estado);

						// Preguntar si desea agregar otro proveedor
						char respuesta = leerCaracter("Desea agregar otro proveedor? (S/N): ", "SN", 35, 19);
						if (respuesta != 'S' && respuesta != 's') {
							break;
						}
					} while (true);
					// Mostrar la lista completa de proveedores
					system("cls");
					TituloVerProveedores();
					MostrarProveedores(*lista);
					break;
				case 2:
					do {
						system("cls");
						TituloBuscarProveedor();

						if (*lista == nullptr) {
							gotoxy(35, 6); cout << "La lista de proveedores esta vacia. No se puede realizar la busqueda." << endl;
							break;
						}

						id = leerEntero("Ingrese el ID del proveedor a buscar: ", 35, 6);
						BuscarProveedor(*lista, id);

						// Preguntar si desea buscar otro proveedor
						char respuesta = leerCaracter("Desea buscar otro proveedor? (S/N): ", "SN", 35, 22);
						if (respuesta != 'S' && respuesta != 's') {
							break;
						}
					} while (true);
					gotoxy(35, 24); cout << "Presione una tecla para volver al menu de lista circular..." << endl;
					_getch();
					break;
				case 3:
					system("cls");
					TituloModificarProveedor();
					modificarProveedor(lista);
					break;
				case 4:
					do {
						system("cls");
						TituloEliminarProveedor();

						if (*lista == nullptr) {
							gotoxy(30, 6); cout << "La lista de proveedores esta vacia. No se puede realizar la eliminacion." << endl;
							break;
						}

						id = leerEntero("Ingrese el ID del proveedor a eliminar: ", 35, 6);
						BorrarProveedor(lista, id);

						// Preguntar si desea eliminar otro proveedor
						system("cls");
						TituloEliminarProveedor();
						char respuesta = leerCaracter("Desea eliminar otro proveedor? (S/N): ", "SN", 35, 6);
						if (respuesta != 'S' && respuesta != 's') {
							break;
						}
					} while (true);
					gotoxy(35, 21); cout << "Presione una tecla para volver al menu de lista circular..." << endl;
					_getch();
					break;
				case 5:
					system("cls");
					TituloVerProveedores();
					MostrarProveedores(*lista);
					break;
				case 6:
					system("cls");
					TituloVaciarListaProveedores();
					VaciarListaProveedores(lista);
					break;
				case 7:
					break;
				case 8:
					repite = false;
					break;
				}
			} while (opcionMenuListaCircular != 7 && repite);
			break;
			case 6:
				do {
					system("color 4F");  // Fondo rojo, letra blanca brillante
					opcionMenuABB = MenuABB(tituloMenuABB, opcionesMenuABB, nOpcionesMenuABB);
					switch (opcionMenuABB) {
					case 1: // Insertar ficha de vacunación
						do {
							system("cls"); 
							TituloIngresaFicha(); 
							gotoxy(35, 6); cout << "-------------------------------------------------------";

							fichaActual.id = leerEntero("Ingrese el ID de la ficha: ", 35, 7);
							fichaActual.fechaVacAct = leerCadena("Ingrese la fecha de la vacuna actual (dd/mm/aa): ", 35, 8);
							fichaActual.nombreVacAct = leerCadena("Ingrese el nombre de la vacuna actual: ", 35, 9);
							fichaActual.fechaVacSig = leerCadena("Ingrese la fecha de la proxima vacuna (dd/mm/aa): ", 35, 10);
							fichaActual.nombreVacSig = leerCadena("Ingrese el nombre de la proxima vacuna: ", 35, 11);


							gotoxy(35, 12); cout << "-------------------------------------------------------";

							// Inserta la ficha de vacunación en el árbol binario de búsqueda (ABB).
							arbol = insertarNodo(arbol, fichaActual);

							gotoxy(40, 14); cout << "Ficha de vacunacion insertada correctamente.";

							// Pregunta al usuario si desea ingresar otra ficha de vacunación.
							rpt = leerCaracter("Desea ingresar otra ficha de vacunacion? (S/N): ", "SN", 40, 16);

						} while (rpt == 'S' || rpt == 's'); // Repite el proceso si el usuario responde 'S' o 's'.

						system("cls"); 
						TituloVerABB(); 
						mostrarArbol(arbol); 
						_getch(); 
						break;
					case 2: // Buscar ficha de vacunación
						do {
							system("cls"); // Limpia la pantalla para iniciar la búsqueda
							TituloBuscarFicha(); // Muestra el título de la sección de búsqueda

							// Verifica que el árbol no esté vacío
							if (arbol == nullptr) {
								gotoxy(35, 6); cout << "El arbol esta vacio. No hay fichas registradas para buscar.";
								gotoxy(40, 8); cout << "Presione una tecla para volver al menu de ABB...";
								_getch();
								break;
							}

							// Se solicita al usuario el ID de la ficha a buscar
							idFichaBuscar = leerEntero("Ingrese el ID de la ficha que desea buscar: ", 45, 6);

							// Se busca el nodo en el árbol utilizando el ID
							Vacuna* fichaEncontrada = buscarNodo(arbol, idFichaBuscar);
							if (fichaEncontrada) {
								// Si se encuentra la ficha, se muestran sus datos
								gotoxy(45, 8); cout << "Ficha encontrada:";
								gotoxy(40, 10); cout << "-----------------------------------------";
								gotoxy(40, 11); cout << "ID: " << fichaEncontrada->ficha.id;
								gotoxy(40, 12); cout << "Fecha Vacuna Actual: " << fichaEncontrada->ficha.fechaVacAct;
								gotoxy(40, 13); cout << "Nombre Vacuna Actual: " << fichaEncontrada->ficha.nombreVacAct;
								gotoxy(40, 14); cout << "Fecha Proxima Vacuna: " << fichaEncontrada->ficha.fechaVacSig;
								gotoxy(40, 15); cout << "Nombre Proxima Vacuna: " << fichaEncontrada->ficha.nombreVacSig;
								gotoxy(40, 16); cout << "-----------------------------------------";
							}
							else {
								// Si no se encuentra, se informa al usuario
								gotoxy(40, 8); cout << "No se encontro ninguna ficha con el ID " << idFichaBuscar << ".";
							}

							// Se pregunta si se desea realizar otra búsqueda
							rpt = leerCaracter("Desea buscar otra ficha de vacunacion? (S/N): ", "SN", 40, 18);
						} while (rpt == 'S' || rpt == 's');
						break;

					case 3: // Ver estructura del ABB
						system("cls");
						TituloVerABB();
						mostrarArbol(arbol);

						// Cambiar el color a texto negro y fondo blanco
						cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
						gotoxy(45, 28); cout << "Presione una tecla para volver al menu de ABB";

						// Restaurar colores originales
						cambiarColorConsola(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, 0);
						_getch();
						break;

					case 4: // Recorrer la estructura del ABB
						system("cls");
						TituloRecorrerABB();
						if (arbol == nullptr) {
							gotoxy(40, 6); cout << "El arbol esta vacio. No hay arbol para recorrer.";

							cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
							gotoxy(40, 8); cout << "Presione una tecla para volver al menu de ABB...";
							cambiarColorConsola(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, 0);
							_getch();
							break;
						}

						mostrarArbol(arbol);
						cout << endl;
						cout << endl;
						cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
						gotoxy(25, 30); cout << "Recorrido Preorden: ";
						// Recorrido Inorden
						offset = 0;
						recorrerPreorden(arbol, 35, 31, offset);

						cout << endl;
						x = 35, y = 32;
						cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
						gotoxy(25, 31); cout << "Recorrido Inorden: ";
						// Recorrido Inorden
						offset = 0;
						recorrerInorden(arbol, 35, 32, offset);

						cout << endl;
						x = 35, y = 33;
						cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
						gotoxy(25, 32); cout << "Recorrido Postorden: ";
						// Recorrido Postorden
						offset = 0;
						recorrerPostorden(arbol, 35, 33, offset);

						cout << endl;
						cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
						gotoxy(45, 34); cout << "\t\t\t\t\tPresione una tecla para volver al menu de ABB";
						cambiarColorConsola(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, 0);
						_getch();
						break;
					case 5: // Eliminar ficha de la estructura
							eliminarFicha(arbol);
						break;
					case 6: // Vaciar la estructura
						system("cls");
						TituloVaciarABB();

						if (arbol == nullptr) {
							gotoxy(30, 6); cout << "El arbol no tiene elementos ingresados, por lo tanto ya estaba vacio.";
							gotoxy(40, 8); cout << "Presione una tecla para volver al menu de ABB...";
							_getch();
							break;
						}

						rpt = leerCaracter("Est seguro de que desea vaciar el arbol? (S/N): ", "SN", 35, 6);

						if (rpt == 'S' || rpt == 's') {
							vaciarArbol(arbol);
							gotoxy(35, 8); cout << "El ABB ha sido vaciado correctamente.";
						}
						else {
							gotoxy(35, 8); cout << "Operacion cancelada. El arbol no fue vaciado.";
						}

						gotoxy(40, 10); cout << "Presione una tecla para volver al menu de ABB...";
						_getch();
						break;
					case 7: // Regresar al menú principal
						break;

					case 8: // Salir del programa
						repite = false;
						break;
					}
				} while (opcionMenuABB != 7 && repite);
				break;
		case 7:
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
		gotoxy(30, 8); cout << "*************************************************************************" << endl;
		gotoxy(30, 9); cout << "***                     " << tituloMenuPrincipal << "                   ***" << endl;
		gotoxy(30, 10); cout << "*************************************************************************" << endl;

		for (int i = 0; i < nOpcionesMenuPrincipal; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesMenuPrincipal[i];
			}
			else {
				cout << "     " << opcionesMenuPrincipal[i];
			}
		}

		gotoxy(30, 18); cout << "*************************************************************************" << endl;
		gotoxy(18, 20); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

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

		gotoxy(30, 19); cout << "**********************************************************" << endl;
		gotoxy(18, 21); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

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

		gotoxy(30, 19); cout << "**********************************************************" << endl;
		gotoxy(18, 21); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

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

int MenuLista(const char* tituloMenuLista, const char* opcionesMenuLista[], int nOpcionesMenuLista) {
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;
	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "***             " << tituloMenuLista << "          ***" << endl;
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
		gotoxy(18, 21); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;
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

int MenuListaDoble(const char* tituloMenuListaDoble, const char* opcionesMenuListaDoble[], int nOpcionesMenuListaDoble)
{
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;
	do {
		system("cls");
		gotoxy(23, 8); cout << "**************************************************************************" << endl;
		gotoxy(23, 9); cout << "***          " << tituloMenuListaDoble << "          ***" << endl;
		gotoxy(23, 10); cout << "**************************************************************************" << endl;
		for (int i = 0; i < nOpcionesMenuListaDoble; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesMenuListaDoble[i];
			}
			else {
				cout << "     " << opcionesMenuListaDoble[i];
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
			if (opcionSeleccionada < nOpcionesMenuListaDoble) opcionSeleccionada++;
			break;
		case 13: // Enter
			repite = false;
			break;
		}
	} while (repite);
	return opcionSeleccionada;
}

int MenuListaCircular(const char* tituloMenuListaCircular, const char* opcionesMenuListaCircular[], int nOpcionesMenuListaCircular) {
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;
	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "***        " << tituloMenuListaCircular << "      ***" << endl;
		gotoxy(30, 10); cout << "**********************************************************" << endl;
		for (int i = 0; i < nOpcionesMenuListaCircular; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesMenuListaCircular[i];
			}
			else {
				cout << "     " << opcionesMenuListaCircular[i];
			}
		}
		gotoxy(30, 19); cout << "**********************************************************" << endl;
		gotoxy(18, 21); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;
		tecla = _getch(); // Captura la tecla presionada
		switch (tecla) {
		case 72: // Flecha arriba
			if (opcionSeleccionada > 1) opcionSeleccionada--;
			break;
		case 80: // Flecha abajo
			if (opcionSeleccionada < nOpcionesMenuListaCircular) opcionSeleccionada++;
			break;
		case 13: // Enter
			repite = false;
			break;
		}
	} while (repite);
	return opcionSeleccionada;
}

int MenuABB(const char* tituloMenuABB, const char* opcionesMenuABB[], int nOpcionesMenuABB) {
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;
	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "***        " << tituloMenuABB << "        ***" << endl;
		gotoxy(30, 10); cout << "**********************************************************" << endl;
		for (int i = 0; i < nOpcionesMenuABB; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesMenuABB[i];
			}
			else {
				cout << "     " << opcionesMenuABB[i];
			}
		}
		gotoxy(30, 19); cout << "**********************************************************" << endl;
		gotoxy(18, 21); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;
		tecla = _getch(); // Captura la tecla presionada
		switch (tecla) {
		case 72: // Flecha arriba
			if (opcionSeleccionada > 1) opcionSeleccionada--;
			break;
		case 80: // Flecha abajo
			if (opcionSeleccionada < nOpcionesMenuABB) opcionSeleccionada++;
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

	// Contar el número total de nodos en la pila
	int totalNodos = 0;
	Cerdo* aux = pila;
	while (aux != nullptr) {
		totalNodos++;
		aux = aux->siguiente;
	}

	// Mostrar los nodos con la posición correcta
	aux = pila;
	int posicion = totalNodos;  // Comenzar desde el total de nodos

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
		// Mostrar la posición del nodo, la dirección actual y la dirección del siguiente nodo al final de la ficha
		if (posicion == totalNodos) {
			cout << "\t\t\t\t\tPosicion del nodo: Ultimo" << endl;
		}
		else if (posicion == 1) {
			cout << "\t\t\t\t\tPosicion del nodo: Primero" << endl;
		}
		else {
			cout << "\t\t\t\t\tPosicion del nodo: " << posicion << endl;
		}
		cout << "\t\t\t\t\tDireccion actual: " << aux << endl;
		cout << "\t\t\t\t\tDireccion siguiente: " << aux->siguiente << endl;
		cout << "\t\t\t\t\t------------------------------------------------" << endl;

		aux = aux->siguiente;  // Avanzamos al siguiente cerdo en la pila
		posicion--;  // Decrementamos la posición del nodo
	}

	cout << endl;
	cout << "\t\t\t\tPresione una tecla para volver al menu de pila de cerdos...";
	_getch();
}

void buscarCerdo(Cerdo* pila, int areteBuscado, Cerdo*& cerdoEncontrado) {
	cerdoEncontrado = nullptr; // Inicializar el puntero a nullptr

	Cerdo* aux = pila; // Puntero auxiliar para recorrer la pila
	int posicion = 1;  // Variable para llevar la cuenta de la posición del nodo

	while (aux != nullptr) {
		if (aux->numArete == areteBuscado) {
			cerdoEncontrado = aux;
			gotoxy(35, 7); cout << "------------------------------------------------";
			gotoxy(40, 8); cout << "Ficha del cerdo con el arete " << aux->numArete;
			gotoxy(35, 9); cout << "------------------------------------------------";
			gotoxy(35, 10); cout << "Modulo: " << aux->numModulo;
			gotoxy(35, 11); cout << "Raza: " << aux->raza;
			gotoxy(35, 12); cout << "Sexo (M = macho/H = Hembra): " << aux->sexo;
			gotoxy(35, 13); cout << "Peso (Kg): " << aux->peso;
			gotoxy(35, 14); cout << "Altura (cm): " << aux->altura;
			gotoxy(35, 15); cout << "Fecha de nacimiento(dd/mm/aa): " << aux->fechaNac;
			gotoxy(35, 16); cout << "Edad (meses): " << aux->edad;
			gotoxy(35, 17); cout << "Salud (E = Excelente/R = Regular/M = Mala): " << aux->estadoSalud;
			gotoxy(35, 18); cout << "Ultima vacuna: " << aux->ultimaVacuna;
			gotoxy(35, 19); cout << "Fecha de ultima vacunacion: " << aux->fechaUltimaVacuna;
			gotoxy(35, 20); cout << "Alimento consumido: " << aux->cantAlimento;
			gotoxy(35, 21); cout << "Procedencia: " << aux->procedencia;
			gotoxy(35, 22); cout << "Venta: " << aux->venta;
			gotoxy(35, 23); cout << "Destino: " << aux->destino;

			// Mostrar la posición del nodo, la dirección actual y la dirección del siguiente nodo al final de la ficha
			if (aux == pila) {
				gotoxy(35, 24); cout << "Posicion del nodo: Primero" << endl;
			}
			else if (aux->siguiente == nullptr) {
				gotoxy(35, 24); cout << "Posicion del nodo: Ultimo" << endl;
			}
			else {
				gotoxy(35, 24); cout << "Posicion del nodo: " << posicion << endl;
			}
			gotoxy(35, 25); cout << "Direccion actual: " << aux << endl;
			gotoxy(35, 26); cout << "Direccion siguiente: " << aux->siguiente << endl;
			gotoxy(35, 27); cout << "------------------------------------------------";
			return;
		}
		aux = aux->siguiente;
		posicion++;  // Incrementamos la posición del nodo
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
	respuesta = leerCaracter("Desea modificar este cerdo? (S/N): ", "SN", 40, 28);
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
	respuesta = leerCaracter("", "SN", 73, 8);
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nuevo modulo: ";
		cerdoEncontrado->numModulo = leerEntero("", 49, 9);
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar raza
	gotoxy(35, 8); cout << "Modificar raza (Actual: " << cerdoEncontrado->raza << ")? (S/N): ";
	respuesta = leerCaracter("", "SN", 82, 8);
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nueva raza: ";
		cerdoEncontrado->raza = leerCadena("", 47, 9);
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar sexo
	gotoxy(35, 8); cout << "Modificar sexo (Actual: " << cerdoEncontrado->sexo << ")? (S/N): ";
	respuesta = leerCaracter("", "SN", 73, 8);
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nuevo sexo (M = macho / H = Hembra): ";
		cerdoEncontrado->sexo = leerCaracter("", "MH", 73, 9);
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar peso
	gotoxy(35, 8); cout << "Modificar peso (Actual: " << cerdoEncontrado->peso << " kg)? (S/N): ";
	respuesta = leerCaracter("", "SN", 76, 8);
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nuevo peso (kg): ";
		cerdoEncontrado->peso = leerDecimal("", 52, 9);
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar altura
	gotoxy(35, 8); cout << "Modificar altura (Actual: " << cerdoEncontrado->altura << " cm)? (S/N): ";
	respuesta = leerCaracter("", "SN", 77, 8);
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nueva altura (cm): ";
		cerdoEncontrado->altura = leerDecimal("", 54, 9);
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar fecha de nacimiento
	gotoxy(35, 8); cout << "Modificar fecha de nacimiento (Actual: " << cerdoEncontrado->fechaNac << ")? (S/N): ";
	respuesta = leerCaracter("", "SN", 92, 8);
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nueva fecha de nacimiento (dd/mm/aa): ";
		cerdoEncontrado->fechaNac = leerCadena("", 73, 9);
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar edad
	gotoxy(35, 8); cout << "Modificar edad (Actual: " << cerdoEncontrado->edad << " meses)? (S/N): ";
	respuesta = leerCaracter("", "SN", 78, 8);
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nueva edad (meses): ";
		cerdoEncontrado->edad = leerEntero("", 56, 9);
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar estado de salud
	gotoxy(35, 8); cout << "Modificar salud (Actual: " << cerdoEncontrado->estadoSalud << ")? (S/N): ";
	respuesta = leerCaracter("", "SN", 73, 8);
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nuevo estado de salud (E = Excelente / R = Regular / M = Mala): ";
		cerdoEncontrado->estadoSalud = leerCaracter("", "E/R/M", 101, 9);
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar última vacuna
	gotoxy(35, 8); cout << "Modificar ultima vacuna (Actual: " << cerdoEncontrado->ultimaVacuna << ")? (S/N): ";
	respuesta = leerCaracter("", "SN", 88, 8);
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nueva ultima vacuna: ";
		cerdoEncontrado->ultimaVacuna = leerCadena("", 57, 9);
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Modificar fecha última vacunación
	gotoxy(35, 8); cout << "Modificar fecha de ultima vacunacion (Actual: " << cerdoEncontrado->fechaUltimaVacuna << ")? (S/N): ";
	respuesta = leerCaracter("", "SN", 102, 8);
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 9); cout << "Nueva fecha de ultima vacunacion (dd/mm/aa): ";
		cerdoEncontrado->fechaUltimaVacuna = leerCadena("", 81, 9);
	}
	borrarLinea(35, 8); borrarLinea(35, 9);

	// Confirmar cambio y terminar
	gotoxy(40, 12); cout << "Datos del cerdo modificados correctamente.";
	gotoxy(40, 14); cout << "Presione una tecla para volver al menu de pila de cerdos...";
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

		// Mostrar el cerdo que se va a eliminar
		Cerdo* cerdoAEliminar = pila;
		gotoxy(40, 6); cout << "Cerdo a eliminar:";
		gotoxy(40, 8); cout << "Arete: " << cerdoAEliminar->numArete;
		gotoxy(40, 9); cout << "Modulo: " << cerdoAEliminar->numModulo;
		gotoxy(40, 10); cout << "Raza: " << cerdoAEliminar->raza;
		gotoxy(40, 11); cout << "Sexo: " << cerdoAEliminar->sexo;
		gotoxy(40, 12); cout << "Peso: " << cerdoAEliminar->peso << " Kg";
		gotoxy(40, 13); cout << "Altura: " << cerdoAEliminar->altura << " cm";
		gotoxy(40, 14); cout << "Edad: " << cerdoAEliminar->edad << " meses";
		gotoxy(40, 15); cout << "Salud: " << cerdoAEliminar->estadoSalud;
		gotoxy(40, 16); cout << "Ultima vacuna: " << cerdoAEliminar->ultimaVacuna;
		gotoxy(40, 17); cout << "Fecha ultima vacunacion: " << cerdoAEliminar->fechaUltimaVacuna;
		gotoxy(40, 18); cout << "Alimento consumido: " << cerdoAEliminar->cantAlimento << " kg";
		gotoxy(40, 19); cout << "Procedencia: " << cerdoAEliminar->procedencia;
		gotoxy(40, 20); cout << "Venta: " << cerdoAEliminar->venta;
		gotoxy(40, 21); cout << "Destino: " << cerdoAEliminar->destino;

		// Preguntar si desea eliminar el cerdo
		respuesta = leerCaracter("Desea eliminar este cerdo? (S/N):", "SN", 40, 23);

		if (respuesta == 'S' || respuesta == 's') {
			sacarPila(pila); // Eliminar el cerdo de la pila
			gotoxy(40, 25); cout << "Cerdo eliminado con exito.";
		}
		else {
			gotoxy(40, 25); cout << "Operacion cancelada. Presione una tecla para volver al menu de pila de cerdos...";
			_getch();
			return;
		}

		if (pila == nullptr) {
			gotoxy(40, 27); cout << "No hay más cerdos en la pila.";
			break;
		}

		respuesta = leerCaracter("Desea eliminar otro cerdo? (S/N): ", "SN", 40, 27);

	} while ((respuesta == 'S' || respuesta == 's') && pila != nullptr);

	gotoxy(40, 29); cout << "Operacion finalizada. Presione una tecla para volver al menu de pila...";
	_getch();
}

void sacarPila(Cerdo*& pila) {
	if (pila == nullptr) {
		return;
	}

	// Guardar referencia al cerdo que se eliminará
	Cerdo* aux = pila;

	// Mover la cima de la pila al siguiente nodo
	pila = aux->siguiente;

	// Liberar memoria del nodo eliminado
	delete aux;
}

void vaciarPila(Cerdo*& pila) {
	if (pila == nullptr) {
		gotoxy(50, 6); cout << "La pila ya esta vacia.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menu de pila de cerdos...";
		_getch();
		return;
	}

	// Mostrar la pila completa
	system("cls");
	TituloVerCerdos();
	mostrarPila(pila);

	// Preguntar si desea vaciar la pila
	char respuesta;
	gotoxy(40, 6); cout << "¿Desea vaciar la pila de cerdos? (S/N): ";
	respuesta = leerCaracter("", "SN", 40, 7);

	if (respuesta != 'S' && respuesta != 's') {
		gotoxy(40, 9); cout << "Operación cancelada. Presione una tecla para volver al menú de pila de cerdos...";
		_getch();
		return;
	}

	// Vaciar la pila
	while (pila != nullptr) {
		Cerdo* aux = pila; // Guardar referencia al nodo actual
		pila = pila->siguiente; // Mover la cima de la pila al siguiente nodo
		delete aux; // Liberar memoria del nodo eliminado
	}

	gotoxy(40, 9); cout << "La pila de cerdos ha sido vaciada correctamente.";
	gotoxy(40, 11); cout << "Presione una tecla para volver al menú de pila de cerdos...";
	_getch();
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

void gestionarIngresoEmpleados(ColaEmpleado& q) {
	char rpt;
	do {
		Empleado* nuevo = crearEmpleado();
		encolarEmpleado(q, nuevo);
		gotoxy(35, 22); cout << "Empleado ingresado correctamente a la cola de empleados.";
		gotoxy(45, 24); cout << "Desea ingresar otro empleado? (S/N): ";
		rpt = leerCaracter("", "SN", 82, 24);
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
		gotoxy(columna + 2, fila + 7); cout << "Direccion de memoria: " << aux;
		gotoxy(columna, fila + 8); cout << "----------------------------------";

		ultimaFila = fila + 8; // Guarda la última fila usada por la ficha actual

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
		idEmpleadoBuscado = leerEntero("Ingrese el ID del trabajador a buscar: ", 45, 7);

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
		rpt = leerCaracter("", "SN", 45, filaFinal + 20);

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
		respuesta = leerCaracter("", "SN", 40, 59);

		if (respuesta == 'S' || respuesta == 's') {
			// Eliminar el primer empleado de la cola
			q.delante = q.delante->sgte;
			if (!q.delante) {
				q.atras = nullptr; // Si la cola queda vacía, actualizar el puntero 'atras'
			}
			delete temp;
			system("cls");
			TituloEliminaTrabajador();
			gotoxy(45, 24); cout << "Empleado eliminado correctamente.";
		}
		else {
			system("cls");
			TituloEliminaTrabajador();
			gotoxy(50, 24); cout << "Operacion cancelada.";
		}
		 
		// Mostrar la cola actualizada después de eliminar
		mostrarColaEmpleados(q);

		if (!q.delante) {
			system("cls");
			TituloEliminaTrabajador();
			gotoxy(45, 26); cout << "No hay mas empleados en la cola.";
			break;
		}

		gotoxy(45, 26); cout << "¿Desea eliminar otro empleado? (S/N): ";
		respuesta = leerCaracter("", "SN", 45, 26);

	} while ((respuesta == 'S' || respuesta == 's') && q.delante != nullptr);
	TituloEliminaTrabajador();

	gotoxy(35, 15); cout << "Operacion finalizada. Presione una tecla para volver al menu de cola...";
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

void vaciarCola(ColaEmpleado& q) {
	if (q.delante == nullptr) {
		gotoxy(40, 6); cout << "La cola ya está vacía.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menú de cola de empleados...";
		_getch();
		return;
	}

	// Mostrar la cola completa
	system("cls");
	TituloVerTrabajadores();
	mostrarColaEmpleados(q);

	// Preguntar si desea vaciar la cola
	char respuesta;
	gotoxy(40, 6); cout << "¿Desea vaciar la cola de empleados? (S/N): ";
	respuesta = leerCaracter("", "SN", 40, 11);

	if (respuesta != 'S' && respuesta != 's') {
		gotoxy(40, 11); cout << "Operación cancelada. Presione una tecla para volver al menú de cola de empleados...";
		_getch();
		return;
	}

	// Vaciar la cola
	while (q.delante != nullptr) {
		Empleado* aux = q.delante; // Guardar referencia al nodo actual
		q.delante = q.delante->sgte; // Mover el frente de la cola al siguiente nodo
		delete aux; // Liberar memoria del nodo eliminado
	}

	q.atras = nullptr; // Asegurarse de que el puntero 'atras' también esté en nullptr

	gotoxy(40, 13); cout << "La cola de empleados ha sido vaciada correctamente.";
	gotoxy(40, 14); cout << "Presione una tecla para volver al menú de cola de empleados...";
	_getch();
}

Comprador* CrearComprador() {
	Comprador* nuevo = new Comprador;

	nuevo->id = leerEntero("Ingrese ID del comprador: ", 45, 7);

	gotoxy(35, 8); cout << "-----------------------------------------------------";
	nuevo->nombre = leerCadena("Ingrese nombre: ", 45, 9);
	nuevo->telefono = leerCadena("Ingrese telefono: ", 45, 10);
	nuevo->direccion = leerCadena("Ingrese direccion: ", 45, 11);
	nuevo->metodoPago = leerCadena("Ingrese metodo de pago: ", 45, 12);
	nuevo->frecuenciaCompra = leerCadena("Ingrese frecuencia de compra: ", 45, 13);
	nuevo->preferencias = leerCadena("Ingrese preferencias: ", 45, 14);
	nuevo->fechaRegistro = leerCadena("Ingrese fecha de registro: ", 45, 15);
	nuevo->estadoCuenta = leerCadena("Ingrese estado de cuenta: ", 45, 16);
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
		rpt = leerCaracter("Desea ingresar otro comprador? (S/N): ", "SN", 45, 24);
	} while (rpt == 's' || rpt == 'S');
	gotoxy(40, 26); cout << "Presione una tecla para ver la lista actualizada...";
	_getch();
}

void mostrarListaCompradores(Comprador* compradores)
{
	Comprador* aux = new Comprador();
	aux = compradores;
	while (aux != nullptr)
	{
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

	// Si la lista está vacía
	if (aux == nullptr) {
		gotoxy(45, 8); cout << "La lista de compradores está vacía.";
		_getch();
		return nullptr;
	}

	// Buscar el comprador por ID
	while (aux) {
		if (aux->id == idCompradorBuscado) {
			// Mostrar la información del comprador encontrado
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
			_getch();
			return aux; // Devolver el comprador encontrado
		}
		aux = aux->sgte;
	}

	// Si llegó aquí, no se encontró el comprador
	gotoxy(45, 8); cout << "Comprador con el id " << idCompradorBuscado << " no encontrado.";
	_getch();
	return nullptr;
}

void modificarComprador(Comprador*& compradores) {
	int idCompradorBuscado = 0;
	Comprador* compradorEncontrado = nullptr;
	char respuesta;
	if (compradores == nullptr) {
		gotoxy(40, 8); cout << "La lista de compradores esta vacia";
		gotoxy(40, 9); cout << "Presione una tecla para volver al menu de listas...";
		_getch();
		return;
	}

	do {
		idCompradorBuscado = leerEntero("Ingrese el ID del comprador a modificar: ", 45, 7);
		compradorEncontrado = buscarComprador(compradores, idCompradorBuscado);
		if (compradorEncontrado == nullptr) {
			gotoxy(40, 10); cout << "Comprador no encontrado. ¿Desea intentar con otro ID? (S/N): ";
			respuesta = leerCaracter("", "SN", 78, 10);
			if (respuesta != 'S' && respuesta != 's') {
				gotoxy(35, 12); cout << "Operacion cancelada. Presione una tecla para volver al menu de compradores...";
				_getch();
				return;
			}
			continue;
		}

		gotoxy(40, 10); cout << "Desea modificar este comprador? (S/N): ";
		respuesta = leerCaracter("", "SN", 78, 10);
		if (respuesta != 'S' && respuesta != 's') {
			gotoxy(35, 12); cout << "Operacion cancelada. Presione una tecla para volver al menu de compradores...";
			_getch();
			return;
		}

		// Modificar nombre
		do {
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar nombre (Actual: " << compradorEncontrado->nombre << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				compradorEncontrado->nombre = leerCadena("Nuevo nombre: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar telefono
		do {
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar telefono (Actual: " << compradorEncontrado->telefono << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				compradorEncontrado->telefono = leerCadena("Nuevo telefono: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar direccion
		do {
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar direccion (Actual: " << compradorEncontrado->direccion << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				compradorEncontrado->direccion = leerCadena("Nueva direccion: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar metodo de pago
		do {
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar metodo de pago (Actual: " << compradorEncontrado->metodoPago << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				compradorEncontrado->metodoPago = leerCadena("Nuevo metodo de pago: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar frecuencia de compra
		do {
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar frecuencia de compra (Actual: " << compradorEncontrado->frecuenciaCompra << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				compradorEncontrado->frecuenciaCompra = leerCadena("Nueva frecuencia de compra: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar preferencias
		do {
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar preferencias (Actual: " << compradorEncontrado->preferencias << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				compradorEncontrado->preferencias = leerCadena("Nuevas preferencias: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar fecha de registro
		do {
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar fecha de registro (Actual: " << compradorEncontrado->fechaRegistro << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
				compradorEncontrado->fechaRegistro = leerCadena("Nueva fecha de registro: ", 35, 9);
			}
			borrarLinea(35, 7); borrarLinea(35, 8); borrarLinea(35, 9);
		} while (respuesta == 'S' || respuesta == 's');

		// Modificar estado de cuenta
		do {
			system("cls");
			TituloModificarComprador();
			gotoxy(35, 7); cout << "Modificar estado de cuenta (Actual: " << compradorEncontrado->estadoCuenta << ")? (S/N): ";
			respuesta = leerCaracter("", "SN", 35, 8);
			if (respuesta == 'S' || respuesta == 's') {
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

void agregarAlimento(Alimento*& cabeza, Alimento*& cola, int codigo, string marca, string fechaCaducacion,
	int cantidad, string categoria, string proveedor, float precio, string paisOrigen) {
	Alimento* nuevo = new Alimento();
	nuevo->codigo = codigo;
	nuevo->marca = marca;
	nuevo->fechaCaducacion = fechaCaducacion;
	nuevo->cantidad = cantidad;
	nuevo->categoria = categoria;
	nuevo->proveedor = proveedor;
	nuevo->precio = precio;
	nuevo->paisOrigen = paisOrigen;
	nuevo->anterior = nullptr;
	nuevo->siguiente = nullptr;

	// Caso 1: Lista vacía
	if (cabeza == nullptr) {
		cabeza = cola = nuevo;
		gotoxy(40, 19); cout << "Alimento agregado correctamente (PRIMER elemento).";
		gotoxy(40, 20); cout << "Direccion: " << nuevo;
		gotoxy(40, 21); cout << "Anterior: NULL";
		gotoxy(40, 22); cout << "Siguiente: NULL";
		return;
	}

	// Caso 2: Insertar al inicio
	if (codigo < cabeza->codigo) {
		nuevo->siguiente = cabeza;
		cabeza->anterior = nuevo;
		cabeza = nuevo;

		// Determinar posición
		int posicion = 1;
		gotoxy(40, 19); cout << "Alimento agregado correctamente (PRIMER elemento).";
		gotoxy(40, 20); cout << "Direccion: " << nuevo;
		gotoxy(40, 21); cout << "Anterior: NULL";
		gotoxy(40, 22); cout << "Siguiente: " << nuevo->siguiente;
		gotoxy(40, 23); cout << "Ahora hay " << contarElementos(cabeza) << " elementos en la lista.";
		return;
	}

	// Caso 3: Insertar al final
	if (codigo > cola->codigo) {
		cola->siguiente = nuevo;
		nuevo->anterior = cola;
		cola = nuevo;

		// Determinar posición
		int total = contarElementos(cabeza);
		gotoxy(40, 19); cout << "Alimento agregado correctamente (ULTIMO elemento, posicion " << total << ").";
		gotoxy(40, 20); cout << "Direccion: " << nuevo;
		gotoxy(40, 21); cout << "Anterior: " << nuevo->anterior;
		gotoxy(40, 22); cout << "Siguiente: NULL";
		gotoxy(40, 23); cout << "Ahora hay " << total << " elementos en la lista.";
		return;
	}

	// Caso 4: Insertar en medio
	Alimento* actual = cabeza;
	int posicion = 1;
	while (actual != nullptr && actual->codigo < codigo) {
		actual = actual->siguiente;
		posicion++;
	}

	// Verificar si el código ya existe
	if (actual != nullptr && actual->codigo == codigo) {
		gotoxy(40, 19); cout << "Error: Ya existe un alimento con ese codigo.";
		delete nuevo;
		return;
	}

	// Insertar antes del nodo actual
	nuevo->siguiente = actual;
	nuevo->anterior = actual->anterior;
	actual->anterior->siguiente = nuevo;
	actual->anterior = nuevo;

	// Mostrar información de posición
	gotoxy(40, 19); cout << "Alimento agregado correctamente (Posicion " << posicion << ").";
	gotoxy(40, 20); cout << "Direccion: " << nuevo;
	gotoxy(40, 21); cout << "Anterior: " << nuevo->anterior;
	gotoxy(40, 22); cout << "Siguiente: " << nuevo->siguiente;
	gotoxy(40, 23); cout << "Ahora hay " << contarElementos(cabeza) << " elementos en la lista.";
}

// Función auxiliar para contar elementos en la lista (añadir esta función)
int contarElementos(Alimento* cabeza) {
	int contador = 0;
	Alimento* actual = cabeza;
	while (actual != nullptr) {
		contador++;
		actual = actual->siguiente;
	}
	return contador;
}
//Funciones para el uso de lista doble
// Función para mostrar todos los alimentos en la lista
void mostrarListaAlimentos(Alimento* cabeza) {
	if (cabeza == nullptr) {
		gotoxy(38, 7); cout << "La lista esta vacia. No hay alimentos registrados.";
		gotoxy(38, 9); cout << "Presione una tecla para volver al menu de alimentos...";
		_getch();
		return;
	}

	system("cls"); // Limpiar pantalla antes de mostrar
	TituloVerAlimento();

	Alimento* actual = cabeza;
	int fila = 8; // Empezar más abajo para dejar espacio al título

	// Mostrar información de los nodos extremos
	gotoxy(5, fila++); cout << "=== INFORMACION DE LA LISTA ===";
	gotoxy(5, fila++); cout << "Primer nodo: " << cabeza->codigo << " (" << cabeza << ")";

	// Encontrar el último nodo
	Alimento* ultimo = cabeza;
	while (ultimo->siguiente != nullptr) {
		ultimo = ultimo->siguiente;
	}
	gotoxy(5, fila++); cout << "Ultimo nodo: " << ultimo->codigo << " (" << ultimo << ")";
	fila++; // Espacio

	// Encabezados de columnas
	gotoxy(5, fila++); cout << "Pos." << "\tCodigo" << "\tMarca" << "\tCaducidad" << "\tCant." << "\tPrecio" << "\tDireccion";
	gotoxy(5, fila++); cout << "------------------------------------------------------------------------------------------------";

	int posicion = 1;
	while (actual != nullptr) {
		// Limitar la longitud de los strings para que no desborden
		string marcaCorta = actual->marca.substr(0, 10);
		if (actual->marca.length() > 10) marcaCorta += "...";

		string fechaCorta = actual->fechaCaducacion.substr(0, 10);

		// Mostrar datos en formato compacto
		gotoxy(5, fila++);
		cout << posicion++ << "\t        "
			<< actual->codigo << "\t"
			<< marcaCorta << "\t "
			<< fechaCorta << "\t        "
			<< actual->cantidad << "\t "
			<< actual->precio << "\t"
			<< actual;

		// Mostrar relaciones de nodos en líneas separadas
		gotoxy(5, fila++); cout << "  Anterior: " << actual->anterior;
		gotoxy(5, fila++); cout << "  Siguiente: " << actual->siguiente;
		fila++; // Espacio entre alimentos

		actual = actual->siguiente;

		// Pausa cada 5 elementos si hay muchos
		if (posicion % 5 == 0 && actual != nullptr) {
			gotoxy(5, fila++); cout << "Presione una tecla para continuar...";
			_getch();
			fila = 8; // Resetear posición
			system("cls");
			TituloVerAlimento();
			// Volver a mostrar encabezados
			gotoxy(5, fila++); cout << "Pos." << "\tCodigo" << "\tMarca" << "\tCaducidad" << "\tCant." << "\tPrecio" << "\tDireccion";
			gotoxy(5, fila++); cout << "------------------------------------------------------------------------------------------------";
		}
	}

	gotoxy(5, fila); cout << "Presione una tecla para volver al menu...";
	_getch();
}

// Función para buscar un alimento por su código
Alimento* buscarAlimento(Alimento* cabeza, int codigoBuscado) {
	Alimento* actual = cabeza;
	while (actual != nullptr) {
		if (actual->codigo == codigoBuscado) {
			// Mostrar información de direcciones cuando se encuentra
			gotoxy(35, 21); cout << "Direccion del nodo: " << actual;
			gotoxy(35, 22); cout << "Nodo anterior: " << actual->anterior;
			gotoxy(35, 23); cout << "Nodo siguiente: " << actual->siguiente;
			return actual;
		}
		actual = actual->siguiente;
	}
	return nullptr;
}

// Función para modificar un alimento
void modificarAlimento(Alimento* cabeza) {
	int codigoBuscado = 0;
	Alimento* alimentoEncontrado = nullptr;
	char respuesta;

	if (cabeza == nullptr) {
		gotoxy(40, 6); cout << "La lista esta vacia. No hay alimentos para modificar.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menu de alimentos...";
		_getch();
		return;
	}

	gotoxy(40, 7); cout << "Ingrese el codigo del alimento a modificar: ";
	cin >> codigoBuscado;

	alimentoEncontrado = buscarAlimento(cabeza, codigoBuscado);

	if (alimentoEncontrado == nullptr) {
		gotoxy(45, 9); cout << "No se encontro ningun alimento con el codigo " << codigoBuscado << ".";
		gotoxy(40, 11); cout << "Presione una tecla para volver al menu de alimentos...";
		_getch();
		return;
	}

	// Mostrar información actual
	gotoxy(35, 9); cout << "------------------------------------------------";
	gotoxy(40, 10); cout << "Informacion actual del alimento " << alimentoEncontrado->codigo;
	gotoxy(35, 11); cout << "Direccion de nodo: " << alimentoEncontrado;
	gotoxy(35, 12); cout << "Anterior: " << alimentoEncontrado->anterior;
	gotoxy(35, 13); cout << "Siguiente: " << alimentoEncontrado->siguiente;
	gotoxy(35, 14); cout << "Marca: " << alimentoEncontrado->marca;
	gotoxy(35, 15); cout << "Fecha Caducidad: " << alimentoEncontrado->fechaCaducacion;
	gotoxy(35, 16); cout << "Cantidad: " << alimentoEncontrado->cantidad;
	gotoxy(35, 17); cout << "Categoria: " << alimentoEncontrado->categoria;
	gotoxy(35, 18); cout << "Proveedor: " << alimentoEncontrado->proveedor;
	gotoxy(35, 19); cout << "Precio: " << alimentoEncontrado->precio;
	gotoxy(35, 20); cout << "Pais Origen: " << alimentoEncontrado->paisOrigen;
	gotoxy(35, 21); cout << "------------------------------------------------";

	// Preguntar si desea modificar
	gotoxy(35, 23); cout << "                               ";
	cin.ignore();
	gotoxy(40, 22); cout << "Desea modificar este alimento? (S/N): ";
	cin >> respuesta;

	if (respuesta != 'S' && respuesta != 's') {
		gotoxy(35, 23); cout << "Operacion cancelada. Presione una tecla para volver...";
		_getch();
		return;
	}

	// Modificar campos
	gotoxy(35, 23); cout << "Deje en blanco los campos que no desea modificar.";
	cin.ignore();

	string nuevaMarca = leerCadena("Nueva marca (" + alimentoEncontrado->marca + "): ", 35, 24);
	if (!nuevaMarca.empty()) alimentoEncontrado->marca = nuevaMarca;

	string nuevaFecha = leerCadena("Nueva fecha caducidad (" + alimentoEncontrado->fechaCaducacion + "): ", 35, 25);
	if (!nuevaFecha.empty()) alimentoEncontrado->fechaCaducacion = nuevaFecha;

	string nuevaCantidad = leerCadena("Nueva cantidad (" + to_string(alimentoEncontrado->cantidad) + "): ", 35, 26);
	if (!nuevaCantidad.empty()) alimentoEncontrado->cantidad = stoi(nuevaCantidad);

	string nuevaCategoria = leerCadena("Nueva categoria (" + alimentoEncontrado->categoria + "): ", 35, 27);
	if (!nuevaCategoria.empty()) alimentoEncontrado->categoria = nuevaCategoria;

	string nuevoProveedor = leerCadena("Nuevo proveedor (" + alimentoEncontrado->proveedor + "): ", 35, 28);
	if (!nuevoProveedor.empty()) alimentoEncontrado->proveedor = nuevoProveedor;

	string nuevoPrecio = leerCadena("Nuevo precio (" + to_string(alimentoEncontrado->precio) + "): ", 35, 29);
	if (!nuevoPrecio.empty()) alimentoEncontrado->precio = stof(nuevoPrecio);

	string nuevoPais = leerCadena("Nuevo pais origen (" + alimentoEncontrado->paisOrigen + "): ", 35, 30);
	if (!nuevoPais.empty()) alimentoEncontrado->paisOrigen = nuevoPais;

	gotoxy(40, 32); cout << "Alimento modificado correctamente.";
	gotoxy(40, 34); cout << "Presione una tecla para volver al menu...";
	_getch();
}

// Función para eliminar un alimento de la lista
void eliminarAlimento(Alimento*& cabeza, Alimento*& cola, int codigoBuscado) {
	Alimento* alimentoEliminar = buscarAlimento(cabeza, codigoBuscado);

	if (alimentoEliminar == nullptr) {
		gotoxy(45, 9); cout << "No se encontro ningun alimento con el codigo " << codigoBuscado << ".";
		return;
	}

	// Mostrar información del alimento a eliminar
	gotoxy(35, 9); cout << "------------------------------------------------";
	gotoxy(40, 10); cout << "Informacion del alimento a eliminar:";
	gotoxy(35, 11); cout << "Codigo: " << alimentoEliminar->codigo;
	gotoxy(35, 12); cout << "Marca: " << alimentoEliminar->marca;
	gotoxy(35, 13); cout << "Proveedor: " << alimentoEliminar->proveedor;
	gotoxy(35, 14); cout << "Direccion: " << alimentoEliminar;
	gotoxy(35, 15); cout << "Anterior: " << alimentoEliminar->anterior;
	gotoxy(35, 16); cout << "Siguiente: " << alimentoEliminar->siguiente;
	gotoxy(35, 17); cout << "------------------------------------------------";

	char confirmar;
	gotoxy(40, 18); cout << "¿Esta seguro que desea eliminar este alimento? (S/N): ";
	cin >> confirmar;

	if (confirmar != 'S' && confirmar != 's') {
		gotoxy(40, 19); cout << "Operacion cancelada.";
		return;
	}

	// Reorganizar los punteros
	if (alimentoEliminar->anterior != nullptr) {
		alimentoEliminar->anterior->siguiente = alimentoEliminar->siguiente;
	}
	else {
		cabeza = alimentoEliminar->siguiente;
	}

	if (alimentoEliminar->siguiente != nullptr) {
		alimentoEliminar->siguiente->anterior = alimentoEliminar->anterior;
	}
	else {
		cola = alimentoEliminar->anterior;
	}

	delete alimentoEliminar;
	gotoxy(40, 19); cout << "Alimento eliminado correctamente.";
}

// Función para vaciar toda la lista de alimentos
void vaciarListaAlimentos(Alimento*& cabeza, Alimento*& cola) {
	if (cabeza == nullptr) {
		gotoxy(40, 6); cout << "La lista ya esta vacia.";
		return;
	}

	char confirmar;
	gotoxy(40, 6); cout << "¿Esta seguro que desea vaciar toda la lista? (S/N): ";
	cin >> confirmar;

	if (confirmar != 'S' && confirmar != 's') {
		gotoxy(40, 8); cout << "Operacion cancelada.";
		return;
	}

	Alimento* actual = cabeza;
	while (actual != nullptr) {
		Alimento* temp = actual;
		actual = actual->siguiente;
		delete temp;
	}

	cabeza = cola = nullptr;
	gotoxy(40, 8); cout << "Lista de alimentos vaciada correctamente.";
}

//
void InsertarProveedor(Lista* lista, int id, string nombre, string direccion, string telefono, string correo, string productos, string fechaRegistro, string estado) {
	// Crear un nuevo nodo de tipo Proveedor
	pNodo nuevo = new Proveedor();

	// Asignar los valores pasados como parámetros al nuevo nodo
	nuevo->id = id;
	nuevo->nombre = nombre;
	nuevo->direccion = direccion;
	nuevo->telefono = telefono;
	nuevo->correo = correo;
	nuevo->productos = productos;
	nuevo->fechaRegistro = fechaRegistro;
	nuevo->estado = estado;

	// Caso 1: Si la lista está vacía, el nuevo nodo se convierte en la lista
	if (!*lista) {
		*lista = nuevo;
		nuevo->siguiente = nuevo; // Se apunta a sí mismo, formando una lista circular
	}
	// Caso 2: Insertar al inicio si el ID del nuevo proveedor es menor al ID del primer nodo
	else if (id < (*lista)->id) {
		pNodo actual = *lista;	// Nodo actual para recorrer la lista

		// Recorrer la lista para encontrar el último nodo (que apunta al primero)
		while (actual->siguiente != *lista) {
			actual = actual->siguiente;
		}

		// Ajustar punteros para insertar el nuevo nodo al inicio
		actual->siguiente = nuevo;
		nuevo->siguiente = *lista;
		*lista = nuevo; // Actualizar la lista para que apunte al nuevo nodo
	}
	// Caso 3: Insertar en medio o al final según el orden del ID
	else {
		pNodo actual = *lista;

		// Recorrer la lista hasta encontrar la posición correcta para insertar
		while (actual->siguiente != *lista && actual->siguiente->id < id) {
			actual = actual->siguiente;
		}

		// Ajustar punteros para insertar el nuevo nodo en la posición correcta
		nuevo->siguiente = actual->siguiente;
		actual->siguiente = nuevo;
	}

	// Mostrar mensaje de confirmación en la pantalla con gotoxy
	gotoxy(35, 17);
	cout << "Proveedor con el ID " << id << " agregado exitosamente." << endl;
}

void BorrarProveedor(Lista* lista, int id) {
	pNodo actual = *lista;
	pNodo anterior = nullptr;
	bool encontrado = false;
	int contador = 1; // Contador para la posición de cada proveedor

	// Buscar el proveedor en la lista
	do {
		if (actual->id == id) {	// Proveedor encontrado
			encontrado = true;
			break;
		}
		anterior = actual;	// Guardar el nodo actual como anterior
		actual = actual->siguiente;	// Avanzar al siguiente nodo
		contador++;	// Incrementar el contador de posición
	} while (actual != *lista);	// Repetir hasta regresar al inicio

	if (!encontrado) {	// Proveedor no encontrado
		gotoxy(40, 8); cout << "Proveedor con ID " << id << " no encontrado." << endl;
		gotoxy(45, 10); cout << "Presione una tecla para continuar...";
		_getch();
		return;
	}

	// Mostrar los datos del proveedor encontrado
	gotoxy(45, 8); cout << "-----------------------------------------" << endl;
	gotoxy(45, 9); cout << "ID: " << actual->id << endl;
	gotoxy(45, 10); cout << "Nombre: " << actual->nombre << endl;
	gotoxy(45, 11); cout << "Direccion: " << actual->direccion << endl;
	gotoxy(45, 12); cout << "Telefono: " << actual->telefono << endl;
	gotoxy(45, 13); cout << "Correo: " << actual->correo << endl;
	gotoxy(45, 14); cout << "Productos: " << actual->productos << endl;
	gotoxy(45, 15); cout << "Fecha de Registro: " << actual->fechaRegistro << endl;
	gotoxy(45, 16); cout << "Estado: " << actual->estado << endl;

	// Determinar la posición en la lista
	if (actual == *lista) {	// Nodo actual es el primero
		gotoxy(45, 17); cout << "Posicion en la lista: Primero" << endl;
	}
	else if (actual->siguiente == *lista) {	// Nodo actual es el último
		gotoxy(45, 17); cout << "Posicion en la lista: Ultimo" << endl;
	}
	else {
		gotoxy(45, 17); cout << "Posicion en la lista: " << contador << endl;
	}

	gotoxy(45, 18); cout << "Direccion nodo actual: " << actual << endl;
	gotoxy(45, 19); cout << "Direccion siguiente nodo: " << actual->siguiente << endl;
	gotoxy(45, 20); cout << "-----------------------------------------" << endl;

	// Preguntar si desea eliminar el proveedor
	char respuesta = leerCaracter("Desea eliminar este proveedor? (S/N): ", "SN", 40, 22);
	if (respuesta != 'S' && respuesta != 's') {
		gotoxy(45, 24); cout << "Operación cancelada." << endl;
		return;
	}

	// Caso especial: si el nodo a eliminar es el primero de la lista
	if (actual == *lista) {	// Nodo a eliminar es el primero
		if (actual->siguiente == *lista) {
			// Solo hay un nodo en la lista
			delete actual;	// Eliminar el nodo
			*lista = nullptr;	// Actualizar la lista
		}
		else {
			// Hay más de un nodo en la lista
			anterior = *lista;	// Nodo anterior al primero
			while (anterior->siguiente != *lista) {	// Encontrar el último nodo
				anterior = anterior->siguiente;	// Avanzar al siguiente nodo
			}
			anterior->siguiente = (*lista)->siguiente;	// Actualizar el enlace
			*lista = (*lista)->siguiente;	// Actualizar la lista
			delete actual;	// Eliminar el nodo
		}
	}
	else {
		// Nodo encontrado, eliminarlo
		anterior->siguiente = actual->siguiente;	// Actualizar el enlace
		delete actual;	// Eliminar el nodo
	}

	gotoxy(40, 24); cout << "Proveedor con ID " << id << " eliminado." << endl;
}

void MostrarProveedores(Lista lista) {
	if (lista == nullptr) {
		// La lista está vacía
		gotoxy(45, 6); cout << "La lista de proveedores esta vacia." << endl;
		gotoxy(35, 8); cout << "Presione una tecla para regresar al menu de lista circular...";
		_getch();
		return;
	}

	pNodo actual = lista; // Nodo actual para recorrer la lista
	int contador = 1; // Contador para la posición de cada proveedor
	cout << endl;
	do {
		// Mostrar el resumen del proveedor actual
		cout << endl;
		cout << "\t\t\t\t\t------------------------------------------" << endl;
		cout << "\t\t\t\t\tID: " << actual->id << endl;
		cout << "\t\t\t\t\tNombre: " << actual->nombre << endl;
		cout << "\t\t\t\t\tTelefono: " << actual->telefono << endl;
		cout << "\t\t\t\t\tProductos: " << actual->productos << endl;
		cout << "\t\t\t\t\tEstado: " << actual->estado << endl;

		// Determinar la posición en la lista
		if (actual == lista) {	// Nodo actual es el primero
			cout << "\t\t\t\t\tPosicion en la lista: Primero" << endl;
		}
		else if (actual->siguiente == lista) {	// Nodo actual es el último
			cout << "\t\t\t\t\tPosicion en la lista: Ultimo" << endl;
		}
		else {
			cout << "\t\t\t\t\tPosicion en la lista: " << contador << endl;
		}

		cout << "\t\t\t\t\tDireccion nodo actual: " << actual << endl;
		cout << "\t\t\t\t\tDireccion siguiente nodo: " << actual->siguiente << endl;
		cout << "\t\t\t\t\t------------------------------------------" << endl;

		// Avanzar al siguiente proveedor
		actual = actual->siguiente;	// Avanzar al siguiente nodo
		contador++;
	} while (actual != lista);	// Repetir hasta regresar al inicio

	cout << endl;
	cout << "\t\t\t\t\tPresione una tecla para volver al menu..." << endl;
	_getch();
}

void BuscarProveedor(Lista lista, int id) {
	pNodo actual = lista;	// Nodo actual para recorrer la lista
	bool encontrado = false;
	int contador = 1; // Contador para la posición de cada proveedor

	do {
		if (actual->id == id) {
			// Proveedor encontrado, mostrar todos los datos
			gotoxy(40, 8); cout << "-----------------------------------------" << endl;
			gotoxy(40, 9); cout << "ID: " << actual->id << endl;
			gotoxy(40, 10); cout << "Nombre: " << actual->nombre << endl;
			gotoxy(40, 11); cout << "Direccion: " << actual->direccion << endl;
			gotoxy(40, 12); cout << "Telefono: " << actual->telefono << endl;
			gotoxy(40, 13); cout << "Correo: " << actual->correo << endl;
			gotoxy(40, 14); cout << "Productos: " << actual->productos << endl;
			gotoxy(40, 15); cout << "Fecha de Registro: " << actual->fechaRegistro << endl;
			gotoxy(40, 16); cout << "Estado: " << actual->estado << endl;

			// Determinar la posición en la lista
			if (actual == lista) {	// Nodo actual es el primero
				gotoxy(40, 17); cout << "Posicion en la lista: Primero" << endl;
			}
			else if (actual->siguiente == lista) {	// Nodo actual es el último
				gotoxy(40, 17); cout << "Posicion en la lista: Ultimo" << endl;
			}
			else {
				gotoxy(40, 17); cout << "Posicion en la lista: " << contador << endl;
			}

			gotoxy(40, 18); cout << "Direccion nodo actual: " << actual << endl;
			gotoxy(40, 19); cout << "Direccion siguiente nodo: " << actual->siguiente << endl;
			gotoxy(40, 20); cout << "-----------------------------------------" << endl;
			encontrado = true;
			break;
		}
		actual = actual->siguiente;	// Avanzar al siguiente nodo
		contador++;
	} while (actual != lista);	// Repetir hasta regresar al inicio

	if (!encontrado) {
		gotoxy(40, 8); cout << "Proveedor con ID " << id << " no encontrado." << endl;
	}
}

void modificarProveedor(Lista* lista) {
	if (*lista == nullptr) {
		gotoxy(40, 6); cout << "La lista de proveedores esta vacia. No hay datos para modificar.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menu...";
		_getch();
		return;
	}

	int idBuscado;
	char respuesta;

	do {
		system("cls");
		TituloModificarProveedor();

		// Mostrar lista de proveedores para referencia
		gotoxy(35, 6); cout << "Lista actual de proveedores:";
		pNodo aux = *lista;	// Nodo auxiliar para recorrer la lista
		int contador = 1;
		do {
			gotoxy(35, 6 + contador);
			cout << contador << ". ID: " << aux->id << " - " << aux->nombre;
			aux = aux->siguiente;
			contador++;
		} while (aux != *lista);	// Repetir hasta regresar al inicio

		// Solicitar ID del proveedor a modificar
		idBuscado = leerEntero("\nIngrese el ID del proveedor a modificar: ", 35, 6 + contador + 1);

		// Buscar el proveedor
		pNodo actual = *lista;	// Nodo actual para recorrer la lista
		bool encontrado = false;

		do {
			if (actual->id == idBuscado) {	// Proveedor encontrado
				encontrado = true;
				break;
			}
			actual = actual->siguiente;
		} while (actual != *lista);	// Repetir hasta regresar al inicio

		if (!encontrado) {
			gotoxy(35, 6 + contador + 3);
			cout << "No se encontro un proveedor con el ID " << idBuscado << ".";
			respuesta = leerCaracter("Desea intentar con otro ID? (S/N): ", "SN", 35, 6 + contador + 5);
			if (respuesta != 'S' && respuesta != 's') {
				return;
			}
			continue;
		}

		// Mostrar información actual del proveedor
		gotoxy(35, 6 + contador + 3); cout << "---------------------------------------------------";
		gotoxy(35, 6 + contador + 4); cout << "Informacion actual del proveedor ID " << actual->id;
		gotoxy(35, 6 + contador + 5); cout << "Nombre: " << actual->nombre;
		gotoxy(35, 6 + contador + 6); cout << "Direccion: " << actual->direccion;
		gotoxy(35, 6 + contador + 7); cout << "Telefono: " << actual->telefono;
		gotoxy(35, 6 + contador + 8); cout << "Correo: " << actual->correo;
		gotoxy(35, 6 + contador + 9); cout << "Productos: " << actual->productos;
		gotoxy(35, 6 + contador + 10); cout << "Fecha Registro: " << actual->fechaRegistro;
		gotoxy(35, 6 + contador + 11); cout << "Estado: " << actual->estado;
		gotoxy(35, 6 + contador + 12); cout << "---------------------------------------------------";

		// Confirmar modificación
		respuesta = leerCaracter("Desea modificar este proveedor? (S/N): ", "SN", 35, 6 + contador + 14);
		if (respuesta != 'S' && respuesta != 's') {
			gotoxy(35, 6 + contador + 16); cout << "Modificacion cancelada.";
			_getch();
			return;
		}

		// Menú de campos a modificar
		int opcion;
		do {
			system("cls");
			TituloModificarProveedor();
			gotoxy(35, 6); cout << "Seleccione el campo a modificar:";
			gotoxy(35, 8); cout << "1. Nombre";
			gotoxy(35, 9); cout << "2. Direccion";
			gotoxy(35, 10); cout << "3. Telefono";
			gotoxy(35, 11); cout << "4. Correo";
			gotoxy(35, 12); cout << "5. Productos";
			gotoxy(35, 13); cout << "6. Fecha de Registro";
			gotoxy(35, 14); cout << "7. Estado";
			gotoxy(35, 15); cout << "8. Terminar modificacion";
			gotoxy(35, 17); cout << "Seleccione una opcion: ";

			opcion = leerEntero("", 56, 17);

			switch (opcion) {
			case 1:
				actual->nombre = leerCadena("Nuevo nombre: ", 35, 19);
				break;
			case 2:
				actual->direccion = leerCadena("Nueva direccion: ", 35, 19);
				break;
			case 3:
				actual->telefono = leerCadena("Nuevo telefono: ", 35, 19);
				break;
			case 4:
				actual->correo = leerCadena("Nuevo correo: ", 35, 19);
				break;
			case 5:
				actual->productos = leerCadena("Nuevos productos: ", 35, 19);
				break;
			case 6:
				actual->fechaRegistro = leerCadena("Nueva fecha de registro: ", 35, 19);
				break;
			case 7:
				actual->estado = leerCadena("Nuevo estado: ", 35, 19);
				break;
			case 8:
				break;
			default:
				gotoxy(35, 21); cout << "Opcion no valida. Intente nuevamente.";
				_getch();
			}

			if (opcion >= 1 && opcion <= 7) {
				gotoxy(35, 21); cout << "Campo modificado correctamente.";
				_getch();
			}

		} while (opcion != 8);

		gotoxy(35, 23); cout << "Modificacion completada para el proveedor ID " << actual->id;

	} while ((respuesta = leerCaracter("Desea modificar otro proveedor? (S/N): ", "SN", 35, 25)) == 'S' || respuesta == 's');
}

void VaciarListaProveedores(Lista* lista) {
	char respuesta;
	TituloVaciarListaProveedores();
	if (*lista == nullptr) {
		// La lista está vacía
		gotoxy(40, 6); cout << "La lista de proveedores ya esta vacia." << endl;
		gotoxy(35, 8); cout << "Presione una tecla para regresar al menu de lista circular...";
		_getch();
		return;
	}

	// Mostrar la lista de proveedores
	MostrarProveedores(*lista);	// Mostrar la lista actual

	system("cls");
	TituloVaciarListaProveedores();
	// Preguntar si desea eliminar la lista
	respuesta = leerCaracter("Desea eliminar todos los proveedores? (S/N): ", "SN", 40, 6);

	if (respuesta != 'S' && respuesta != 's') {
		gotoxy(20, 8); cout << "Operacion cancelada. Presione una tecla para volver al menu de lista circular..." << endl;
		_getch();
		return;
	}

	pNodo actual = *lista;	// Nodo actual para recorrer la lista
	pNodo siguiente;	// Nodo siguiente para recorrer la lista

	// Recorrer la lista y eliminar cada nodo
	do {
		siguiente = actual->siguiente;	// Guardar el siguiente nodo
		delete actual;	// Eliminar el nodo actual
		actual = siguiente;	// Avanzar al siguiente nodo
	} while (actual != *lista);	// Repetir hasta regresar al inicio

	// Establecer la lista como vacía
	*lista = nullptr;

	gotoxy(45, 8); cout << "La lista de proveedores ha sido vaciada." << endl;
	gotoxy(35, 10); cout << "Presione una tecla para volver al menu de lista circular..." << endl;
	_getch();
}

// Crear un nodo de tipo Vacuna en un árbol binario
Vacuna* crearNodo(const FichaVacunacion& ficha) {
	Vacuna* nuevo = new Vacuna();

	// Se asigna la ficha de vacunación proporcionada al nodo recién creado
	nuevo->ficha = ficha;

	// Se inicializan los punteros izquierdo y derecho como nulos, indicando que 
	// este nodo aún no tiene hijos
	nuevo->izq = nullptr;
	nuevo->der = nullptr;

	// Se retorna el puntero al nodo creado para su posterior uso en el árbol
	return nuevo;
}


// Función para insertar un nuevo nodo en un Árbol Binario de Búsqueda (ABB)
Vacuna* insertarNodo(Vacuna* raiz, const FichaVacunacion& ficha) {
	// Si la raíz es nula, significa que el árbol está vacío o hemos llegado a un 
	// punto donde debe insertarse un nuevo nodo, entonces se crea.
	if (raiz == nullptr) {
		return crearNodo(ficha);
	}

	// Si el ID de la nueva ficha es menor que el ID de la ficha en el nodo actual,
	// insertamos recursivamente en el subárbol izquierdo.
	if (ficha.id < raiz->ficha.id) {
		raiz->izq = insertarNodo(raiz->izq, ficha);
	}
	// Si el ID de la nueva ficha es mayor que el ID de la ficha en el nodo actual,
	// insertamos recursivamente en el subárbol derecho.
	else if (ficha.id > raiz->ficha.id) {
		raiz->der = insertarNodo(raiz->der, ficha);
	}

	// Finalmente, retornamos la raíz actual, manteniendo la estructura del árbol.
	return raiz;
}

// Función para buscar un nodo en un Árbol Binario de Búsqueda (ABB)
Vacuna* buscarNodo(Vacuna* raiz, int id) {
	// Caso base: si el nodo actual es nulo o su ID coincide con el ID buscado, 
	// se retorna el nodo (puede ser nulo si el nodo no existe en el árbol).
	if (raiz == nullptr || raiz->ficha.id == id) {
		return raiz;
	}

	// Si el ID buscado es menor que el ID en el nodo actual, 
	// continuamos la búsqueda en el subárbol izquierdo.
	if (id < raiz->ficha.id) {
		return buscarNodo(raiz->izq, id);
	}

	// Si el ID buscado es mayor que el ID en el nodo actual, 
	// continuamos la búsqueda en el subárbol derecho.
	return buscarNodo(raiz->der, id);
}

// Función para mostrar la información de un nodo de tipo Vacuna en coordenadas específicas
void mostrarNodo(Vacuna* nodo, int x, int y) {
	// Si el nodo es nulo, simplemente se retorna sin mostrar nada
	if (nodo == nullptr) return;

	gotoxy(x, y); cout << "---------------------------";

	// Se imprime los datos de la ficha de vacunación contenida en el nodo
	gotoxy(x, y + 1); cout << "ID: " << nodo->ficha.id;
	gotoxy(x, y + 2); cout << nodo->ficha.nombreVacSig;
	gotoxy(x, y + 3); cout << nodo->ficha.fechaVacSig;
	gotoxy(x, y + 4); cout << "Direccion: " << nodo;
	gotoxy(x, y + 5); cout << "---------------------------";
}

// Función para mostrar el árbol binario de búsqueda en una representación jerárquica en consola.
void mostrarArbol(Vacuna* raiz) {

	// Cambia los colores de la consola: fondo blanco, letras negras.
	cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

	system("cls");
	TituloVerABB();

	if (!raiz) {
		gotoxy(55, 6); cout << "Arbol vacio.";
		cambiarColorConsola(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, 0);
		return;
	}

	// Nivel 1: Mostrar la raíz del árbol en la posición central.
	mostrarNodo(raiz, 45, 5);

	// Nivel 2: Mostrar los hijos directos de la raíz (izquierdo y derecho).
	if (raiz->izq) {
		// Conexión visual al hijo izquierdo con una barra inclinada "/"
		cambiarColorConsola(FOREGROUND_RED | FOREGROUND_GREEN, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		gotoxy(45, 11); cout << "/";
		cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		mostrarNodo(raiz->izq, 20, 13);
	}
	if (raiz->der) {
		// Conexión visual al hijo derecho con una barra invertida "\"
		cambiarColorConsola(FOREGROUND_RED | FOREGROUND_GREEN, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		gotoxy(69, 11); cout << "\\";
		cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		mostrarNodo(raiz->der, 70, 13);
	}

	// Nivel 3: Mostrar los nietos (hijos de los hijos).
	if (raiz->izq && raiz->izq->izq) {
		cambiarColorConsola(FOREGROUND_RED | FOREGROUND_GREEN, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		gotoxy(24, 19); cout << "/";
		cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		mostrarNodo(raiz->izq->izq, 2, 21);
	}
	if (raiz->izq && raiz->izq->der) {
		cambiarColorConsola(FOREGROUND_RED | FOREGROUND_GREEN, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		gotoxy(42, 19); cout << "\\";
		cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		mostrarNodo(raiz->izq->der, 32, 21);
	}
	if (raiz->der && raiz->der->izq) {
		cambiarColorConsola(FOREGROUND_RED | FOREGROUND_GREEN, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		gotoxy(75, 19); cout << "/";
		cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		mostrarNodo(raiz->der->izq, 62, 21);
	}
	if (raiz->der && raiz->der->der) {
		cambiarColorConsola(FOREGROUND_RED | FOREGROUND_GREEN, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		gotoxy(92, 19); cout << "\\";
		cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		mostrarNodo(raiz->der->der, 90, 21);
	}

	// Restaurar colores originales al finalizar la visualización.
	cambiarColorConsola(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, 0);
}

// Función para eliminar un nodo de un Árbol Binario de Búsqueda (ABB)
Vacuna* eliminarNodo(Vacuna* raiz, int id, bool usarMinimoDerecha) {
	// Si la raíz es nula, significa que el nodo no se encuentra en el árbol.
	if (raiz == nullptr) return raiz;

	// Si el ID buscado es menor que el ID en el nodo actual, 
	// se busca recursivamente en el subárbol izquierdo.
	if (id < raiz->ficha.id) {
		raiz->izq = eliminarNodo(raiz->izq, id, usarMinimoDerecha);
	}
	// Si el ID buscado es mayor que el ID en el nodo actual, 
	// se busca recursivamente en el subárbol derecho.
	else if (id > raiz->ficha.id) {
		raiz->der = eliminarNodo(raiz->der, id, usarMinimoDerecha);
	}
	else {
		// CASO 1: El nodo a eliminar es una hoja (sin hijos).
		if (raiz->izq == nullptr && raiz->der == nullptr) {
			delete raiz; // Se libera la memoria del nodo eliminado.
			return nullptr; // Se retorna nulo para eliminar la referencia en el árbol.
		}

		// CASO 2: El nodo tiene solo un hijo.
		if (raiz->izq == nullptr) { // Solo tiene hijo derecho.
			Vacuna* temp = raiz->der;
			delete raiz; // Se elimina el nodo actual.
			return temp; // Se retorna el hijo derecho para mantener la conexión.
		}
		else if (raiz->der == nullptr) { // Solo tiene hijo izquierdo.
			Vacuna* temp = raiz->izq;
			delete raiz; // Se elimina el nodo actual.
			return temp; // Se retorna el hijo izquierdo para mantener la conexión.
		}

		// CASO 3: El nodo tiene dos hijos.
		Vacuna* temp;
		if (usarMinimoDerecha) {
			// Se obtiene el nodo con el menor valor en el subárbol derecho.
			temp = nodoMinimo(raiz->der);
			raiz->ficha = temp->ficha; // Se reemplaza la información del nodo actual.
			raiz->der = eliminarNodo(raiz->der, temp->ficha.id, usarMinimoDerecha);
		}
		else {
			// Se obtiene el nodo con el mayor valor en el subárbol izquierdo.
			temp = nodoMaximo(raiz->izq);
			raiz->ficha = temp->ficha; // Se reemplaza la información del nodo actual.
			raiz->izq = eliminarNodo(raiz->izq, temp->ficha.id, usarMinimoDerecha);
		}
	}
	return raiz; // Se retorna la raíz actualizada.
}

// Función para encontrar el nodo con el menor valor en un Árbol Binario de Búsqueda
Vacuna* nodoMinimo(Vacuna* nodo) {
	// Se recorre el árbol hacia la izquierda hasta encontrar el nodo más bajo.
	while (nodo->izq != nullptr)
		nodo = nodo->izq;

	// Se retorna el nodo con el menor valor encontrado.
	return nodo;
}

// Función para encontrar el nodo con el mayor valor en un Árbol Binario de Búsqueda
Vacuna* nodoMaximo(Vacuna* nodo) {
	// Se recorre el árbol hacia la derecha hasta encontrar el nodo más alto.
	while (nodo->der != nullptr)
		nodo = nodo->der;

	// Se retorna el nodo con el mayor valor encontrado.
	return nodo;
}

// Función para eliminar una ficha del árbol binario de búsqueda
void eliminarFicha(Vacuna*& arbol) {
	int idFichaEliminar;
	char respuesta;

	// Ciclo para permitir múltiples eliminaciones si el usuario lo desea.
	do {
		system("cls"); 
		TituloEliminarFicha(); 

		// Si el árbol está vacío, se muestra un mensaje y se retorna.
		if (arbol == nullptr) {
			gotoxy(35, 6); cout << "El arbol esta vacio. No hay fichas para eliminar.";
			gotoxy(35, 8); cout << "Presione una tecla para volver al menu de ABB...";
			_getch();
			return;
		}

		// Se solicita el ID de la ficha a eliminar y se busca en el árbol.
		idFichaEliminar = leerEntero("Ingrese el ID de la ficha que desea eliminar: ", 35, 6);
		Vacuna* nodoEliminar = buscarNodo(arbol, idFichaEliminar);

		// Si el nodo no existe, se informa al usuario.
		if (nodoEliminar == nullptr) {
			gotoxy(35, 8); cout << "No se encontró ninguna ficha con ese ID.";
		}
		else {
			// Se muestra la ficha encontrada con sus detalles.
			gotoxy(35, 8);  cout << "Ficha encontrada:";
			gotoxy(35, 9);  cout << "ID: " << nodoEliminar->ficha.id;
			gotoxy(35, 10); cout << "Fecha Vacunacion Actual: " << nodoEliminar->ficha.fechaVacAct;
			gotoxy(35, 11); cout << "Nombre Vacuna Actual: " << nodoEliminar->ficha.nombreVacAct;
			gotoxy(35, 12); cout << "Fecha Vacunacion Siguiente: " << nodoEliminar->ficha.fechaVacSig;
			gotoxy(35, 13); cout << "Nombre Vacuna Siguiente: " << nodoEliminar->ficha.nombreVacSig;

			// Se confirma si el usuario realmente quiere eliminar la ficha.
			char confirmar = leerCaracter("Desea eliminar esta ficha? (S/N): ", "SN", 35, 15);
			if (confirmar == 'S' || confirmar == 's') {
				if (nodoEliminar->izq != nullptr && nodoEliminar->der != nullptr) {
					// Si el nodo tiene dos hijos, el usuario elige el método de reemplazo.
					char opcion;
					bool opcionValida = false;
					do {
						gotoxy(35, 17); cout << "El nodo tiene dos hijos.";
						gotoxy(35, 18); cout << "Deseas reemplazar con el minimo derecho (D) o maximo izquierdo (I)? ";
						cin >> opcion;
						opcion = toupper(opcion);

						if (opcion == 'D' || opcion == 'I') {
							opcionValida = true;
						}
						else {
							gotoxy(35, 19); cout << "Opción inválida. Por favor ingresa D o I.";
						}
					} while (!opcionValida);

					bool usarMinimoDerecha = (opcion == 'D');
					arbol = eliminarNodo(arbol, idFichaEliminar, usarMinimoDerecha);
				}
				else {
					// Si el nodo no tiene dos hijos, se elimina usando el mínimo derecho por defecto.
					arbol = eliminarNodo(arbol, idFichaEliminar, true);
				}

				// Confirmación y actualización del árbol en consola.
				gotoxy(35, 21); cout << "Ficha eliminada correctamente.";
				gotoxy(35, 22); cout << "Estructura del ABB actualizada:";
				mostrarArbol(arbol);
			}
			else {
				gotoxy(35, 17); cout << "Operación cancelada. No se eliminó la ficha.";
			}
		}

		// Si el árbol quedó vacío tras la eliminación, se informa al usuario y se finaliza el ciclo.
		if (arbol == nullptr) {
			gotoxy(35, 24); cout << "El árbol ahora está vacío. No hay más fichas para eliminar.";
			gotoxy(35, 26); cout << "Presione una tecla para volver al menú de ABB...";
			_getch();
			break;
		}

		// Se pregunta si el usuario quiere eliminar otra ficha.
		cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		respuesta = leerCaracter("Desea eliminar otra ficha? (S/N): ", "SN", 40, 28);
		cambiarColorConsola(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, 0);

	} while (respuesta == 'S' || respuesta == 's');
}

// Función para recorrer el árbol en preorden y mostrar los IDs de los nodos
void recorrerPreorden(Vacuna* raiz, int x_base, int y_base, int& offset) {
	// Si el nodo es nulo, no hay nada que procesar, así que se retorna.
	if (raiz == nullptr) return;

	cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

	// Posiciona el cursor en las coordenadas definidas (x_base + offset, y_base) para mostrar el ID.
	gotoxy(x_base + offset, y_base);
	cout << "ID: " << raiz->ficha.id << ", ";

	// Se incrementa `offset` para desplazar la siguiente impresión.
	offset += 10;

	// Restaurar colores a los originales después de imprimir el ID.
	cambiarColorConsola(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, 0);

	// Llamadas recursivas para recorrer primero el subárbol izquierdo y luego el derecho.
	recorrerPreorden(raiz->izq, x_base, y_base, offset);
	recorrerPreorden(raiz->der, x_base, y_base, offset);
}

// Función para recorrer el árbol en inorden y mostrar los IDs de los nodos
void recorrerInorden(Vacuna* raiz, int x_base, int y_base, int& offset) {
	// Si el nodo es nulo, no hay nada que procesar, así que se retorna.
	if (raiz == nullptr) return;

	// Llamada recursiva al subárbol izquierdo, explorando primero los nodos menores.
	recorrerInorden(raiz->izq, x_base, y_base, offset);

	cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

	// Posiciona el cursor en la coordenada definida para mostrar el ID del nodo actual.
	gotoxy(x_base + offset, y_base);
	cout << "ID: " << raiz->ficha.id << ", ";

	// Se incrementa `offset` para desplazar la siguiente impresión en consola.
	offset += 10;

	cambiarColorConsola(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, 0);

	// Llamada recursiva al subárbol derecho, explorando luego los nodos mayores.
	recorrerInorden(raiz->der, x_base, y_base, offset);
}

// Función para recorrer el árbol en postorden y mostrar los IDs de los nodos
void recorrerPostorden(Vacuna* raiz, int x_base, int y_base, int& offset) {
	// Si el nodo es nulo, no hay nada que procesar, así que se retorna.
	if (raiz == nullptr) return;

	// Llamada recursiva al subárbol izquierdo, explorando primero los nodos menores.
	recorrerPostorden(raiz->izq, x_base, y_base, offset);

	// Llamada recursiva al subárbol derecho, explorando luego los nodos mayores.
	recorrerPostorden(raiz->der, x_base, y_base, offset);


	cambiarColorConsola(FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

	// Posiciona el cursor en la coordenada definida para mostrar el ID del nodo actual.
	gotoxy(x_base + offset, y_base); cout << "ID: " << raiz->ficha.id << ", ";

	// Se incrementa `offset` para desplazar la siguiente impresión en consola.
	offset += 10;

	// Restaurar colores a los originales después de imprimir el ID.
	cambiarColorConsola(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, 0);
}

// Función para eliminar todos los nodos del árbol y vaciarlo completamente
void vaciarArbol(Vacuna*& raiz) {
	// Si el árbol está vacío, no hay nada que eliminar.
	if (raiz == nullptr) return;

	// Se aplica recursión para eliminar primero los nodos del subárbol izquierdo.
	vaciarArbol(raiz->izq);

	// Se aplica recursión para eliminar luego los nodos del subárbol derecho.
	vaciarArbol(raiz->der);

	// Se elimina el nodo actual y se libera la memoria.
	delete raiz;

	// Se asigna `nullptr` para indicar que el árbol ahora está vacío.
	raiz = nullptr;
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
	gotoxy(35, 0); cout << "********************************************************";
	gotoxy(35, 1); cout << "*                                                     **";
	gotoxy(35, 2); cout << "**     Ingresando informacion del cerdo a la pila     **";
	gotoxy(35, 3); cout << "**                                                    **";
	gotoxy(35, 4); cout << "********************************************************";
}

void TituloVerCerdos() {
	gotoxy(45, 0); cout << "********************************************";
	gotoxy(45, 1); cout << "**                                        **";
	gotoxy(45, 2); cout << "**     Viendo la pila de cerdos           **";
	gotoxy(45, 3); cout << "**                                        **";
	gotoxy(45, 4); cout << "********************************************";
}

void TituloBuscarCerdo() {
	gotoxy(45, 0); cout << "***************************************";
	gotoxy(45, 1); cout << "**                                   **";
	gotoxy(45, 2); cout << "**     Buscando cerdo de la pila     **";
	gotoxy(45, 3); cout << "**                                   **";
	gotoxy(45, 4); cout << "***************************************";
}

void TituloModificarCerdo() {
	gotoxy(35, 0); cout << "**********************************************************";
	gotoxy(35, 1); cout << "**                                                      **";
	gotoxy(35, 2); cout << "**     Modificando informacion del cerdo en la pila     **";
	gotoxy(35, 3); cout << "**                                                      **";
	gotoxy(35, 4); cout << "**********************************************************";
}

void TituloEliminarCerdo() {
	gotoxy(45, 0); cout << "*****************************************";
	gotoxy(45, 1); cout << "**                                     **";
	gotoxy(45, 2); cout << "**     Eliminando cerdo de la pila     **";
	gotoxy(45, 3); cout << "**                                     **";
	gotoxy(45, 4); cout << "*****************************************";
}

void TituloVaciarPila() {
	gotoxy(45, 0); cout << "***********************************";
	gotoxy(45, 1); cout << "**                               **";
	gotoxy(45, 2); cout << "**    Vaciando pila de cerdos    **";
	gotoxy(45, 3); cout << "**                               **";
	gotoxy(45, 4); cout << "***********************************";
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
	gotoxy(45, 0); cout << "***********************************************";
	gotoxy(45, 1); cout << "**                                           **";
	gotoxy(45, 2); cout << "**     Modificando trabajador de la cola     **";
	gotoxy(45, 3); cout << "**                                           **";
	gotoxy(45, 4); cout << "***********************************************";
}

void TituloEliminaTrabajador() {
	gotoxy(40, 0); cout << "********************************************";
	gotoxy(40, 1); cout << "**                                        **";
	gotoxy(40, 2); cout << "**    Eliminando trabajador de la cola    **";
	gotoxy(40, 3); cout << "**                                        **";
	gotoxy(40, 4); cout << "********************************************";
}

void TituloVaciarCola() {
	gotoxy(45, 0); cout << "********************************************";
	gotoxy(45, 1); cout << "**                                        **";
	gotoxy(45, 2); cout << "**    Vaciando la cola de trabajadores    **";
	gotoxy(45, 3); cout << "**                                        **";
	gotoxy(45, 4); cout << "********************************************";
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

// Implementación de las funciones de título para alimentos
void TituloIngresaAlimento() {
	gotoxy(35, 0); cout << "*************************************************";
	gotoxy(35, 1); cout << "**                                             **";
	gotoxy(35, 2); cout << "**     Ingresando informacion del alimento     **";
	gotoxy(35, 3); cout << "**           (Lista Doble Enlazada)            **";
	gotoxy(35, 4); cout << "**                                             **";
	gotoxy(35, 5); cout << "*************************************************";
}

void TituloVerAlimento() {
	gotoxy(35, 0); cout << "*************************************************";
	gotoxy(35, 1); cout << "**                                             **";
	gotoxy(35, 2); cout << "**     Visualizando informacion del alimento   **";
	gotoxy(35, 3); cout << "**           (Lista Doble Enlazada)            **";
	gotoxy(35, 4); cout << "**                                             **";
	gotoxy(35, 5); cout << "*************************************************";
}

void TituloBuscarAlimento() {
	gotoxy(35, 0); cout << "*************************************************";
	gotoxy(35, 1); cout << "**                                             **";
	gotoxy(35, 2); cout << "**     Buscando informacion del alimento       **";
	gotoxy(35, 3); cout << "**           (Lista Doble Enlazada)            **";
	gotoxy(35, 4); cout << "**                                             **";
	gotoxy(35, 5); cout << "*************************************************";
}

void TituloModificarAlimento() {
	gotoxy(35, 0); cout << "*************************************************";
	gotoxy(35, 1); cout << "**                                             **";
	gotoxy(35, 2); cout << "**     Modificando informacion del alimento    **";
	gotoxy(35, 3); cout << "**           (Lista Doble Enlazada)            **";
	gotoxy(35, 4); cout << "**                                             **";
	gotoxy(35, 5); cout << "*************************************************";
}

void TituloEliminarAlimento() {
	gotoxy(35, 0); cout << "*************************************************";
	gotoxy(35, 1); cout << "**                                             **";
	gotoxy(35, 2); cout << "**     Eliminando informacion del alimento     **";
	gotoxy(35, 3); cout << "**           (Lista Doble Enlazada)            **";
	gotoxy(35, 4); cout << "**                                             **";
	gotoxy(35, 5); cout << "*************************************************";
}

void TituloVaciarListaAlimento() {
	gotoxy(35, 0); cout << "*************************************************";
	gotoxy(35, 1); cout << "**                                             **";
	gotoxy(35, 2); cout << "**     Vaciando informacion del alimento       **";
	gotoxy(35, 3); cout << "**           (Lista Doble Enlazada)            **";
	gotoxy(35, 4); cout << "**                                             **";
	gotoxy(35, 5); cout << "*************************************************";
}

void TituloInsertaProveedor() {
	gotoxy(35, 0); cout << "*************************************************";
	gotoxy(35, 1); cout << "**                                             **";
	gotoxy(35, 2); cout << "**    Ingresando proveedor a lista circular    **";
	gotoxy(35, 3); cout << "**                                             **";
	gotoxy(35, 4); cout << "*************************************************";
}

void TituloVerProveedores() {
	gotoxy(35, 0); cout << "***************************************************";
	gotoxy(35, 1); cout << "**                                               **";
	gotoxy(35, 2); cout << "**    Viendo la lista circular de proveedores    **";
	gotoxy(35, 3); cout << "**                                               **";
	gotoxy(35, 4); cout << "***************************************************";
}

void TituloModificarProveedor() {
	gotoxy(35, 0); cout << "*************************************************";
	gotoxy(35, 1); cout << "**                                             **";
	gotoxy(35, 2); cout << "**    Modificando proveedor en lista circular  **";
	gotoxy(35, 3); cout << "**                                             **";
	gotoxy(35, 4); cout << "*************************************************";
}

void TituloBuscarProveedor() {
	gotoxy(35, 0); cout << "*************************************************";
	gotoxy(35, 1); cout << "**                                             **";
	gotoxy(35, 2); cout << "**    Buscando proveedor en lista circular     **";
	gotoxy(35, 3); cout << "**                                             **";
	gotoxy(35, 4); cout << "*************************************************";
}

void TituloEliminarProveedor() {
	gotoxy(35, 0); cout << "***************************************************";
	gotoxy(35, 1); cout << "**                                               **";
	gotoxy(35, 2); cout << "**    Eliminando proveedor de lista circular     **";
	gotoxy(35, 3); cout << "**                                               **";
	gotoxy(35, 4); cout << "***************************************************";
}

void TituloVaciarListaProveedores() {
	gotoxy(35, 0); cout << "***************************************************";
	gotoxy(35, 1); cout << "**                                               **";
	gotoxy(35, 2); cout << "**    Vaciando lista circular de proveedores     **";
	gotoxy(35, 3); cout << "**                                               **";
	gotoxy(35, 4); cout << "***************************************************";
}

void TituloIngresaFicha() {
	gotoxy(45, 0); cout << "************************************";
	gotoxy(45, 1); cout << "**                                **";
	gotoxy(45, 2); cout << "**    Ingresando ficha al ABB     **";
	gotoxy(45, 3); cout << "**                                **";
	gotoxy(45, 4); cout << "************************************";
}

void TituloVerABB() {
	gotoxy(45, 0); cout << "******************************";
	gotoxy(45, 1); cout << "**                          **";
	gotoxy(45, 2); cout << "**    Visualizando el ABB   **";
	gotoxy(45, 3); cout << "**                          **";
	gotoxy(45, 4); cout << "******************************";
}

void TituloBuscarFicha() {
	gotoxy(45, 0); cout << "************************************";
	gotoxy(45, 1); cout << "**                                **";
	gotoxy(45, 2); cout << "**    Buscando ficha en el ABB    **";
	gotoxy(45, 3); cout << "**                                **";
	gotoxy(45, 4); cout << "************************************";
}

void TituloRecorrerABB() {
	gotoxy(45, 0); cout << "******************************";
	gotoxy(45, 1); cout << "**                          **";
	gotoxy(45, 2); cout << "**    Recorriendo el ABB    **";
	gotoxy(45, 3); cout << "**                          **";
	gotoxy(45, 4); cout << "******************************";
}

void TituloEliminarFicha() {
	gotoxy(45, 0); cout << "************************************";
	gotoxy(45, 1); cout << "**                                **";
	gotoxy(45, 2); cout << "**    Eliminando ficha del ABB    **";
	gotoxy(45, 3); cout << "**                                **";
	gotoxy(45, 4); cout << "************************************";
}

void TituloVaciarABB() {
	gotoxy(45, 0); cout << "***************************";
	gotoxy(45, 1); cout << "**                       **";
	gotoxy(45, 2); cout << "**    Vaciando el ABB    **";
	gotoxy(45, 3); cout << "**                       **";
	gotoxy(45, 4); cout << "***************************";
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

void cambiarColorConsola(WORD texto, WORD fondo) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, texto | fondo);
}