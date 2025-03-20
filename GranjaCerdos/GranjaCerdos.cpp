/*
	Proyecto que gestiona una granja de cerdos con estructuras de datos Pila y Cola

	Creadores:
	Carlos Maldonado 2290-23-6788
	Johnny Tiu 2290-23-1487
	Andy Tzoc 2290-23-15187
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string>

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
	string genero;
	string cargo;
	string departamento;
	string horario;
	string telefono;
	string direccion;
	int salario;
	string estado;
	string beneficios;
	string fechaContratacion;
	Empleado* sgte;
};

// Estructura para Proveedores
struct Proovedor {
	int id;
	string nombre;
	string telefono;
	string direccion;
	string empresa;
	string productos;
	string fechaRegistro;
	string estadoCuenta;
	Proovedor* sgte;
};

// Estructura para Compradores
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
	Comprador* sgte;
};

struct ColaEmpleado {
	Empleado* delante = nullptr;
	Empleado* atras = nullptr;
};

struct ColaComprador {
	Comprador* delante = nullptr;
	Comprador* atras = nullptr;
};

struct ColaProovedor {
	Proovedor* delante = nullptr;
	Proovedor* atras = nullptr;
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
void buscarCerdo(Cerdo* pila);
void modificarCerdo(Cerdo* pila);
void eliminarCerdosPila(Cerdo*& pila);
void sacarPila(Cerdo*& pila);
int MenuCola(const char* tituloMenuCola, const char* opcionesMenuCola[], int nOpcionesMenuCola);
int SubMenuIngresoPersona(const char* tituloIngresoCola, const char* opcionesIngresoCola[], int nOpcionesIngresoCola);
void TituloIngresaTrabajador();
void TituloIngresaProveedor();
void TituloIngresaComprador();
int SubMenuVerCola(const char* tituloVerCola, const char* opcionesVerCola[], int nOpcionesVerCola);
void TituloVerTrabajadores();
void TituloVerProveedor();
void TituloVerComprador();
int SubMenuBuscarPersona(const char* tituloBuscarEnCola, const char* opcionesBuscarEnCola[], int nOpcionesBuscarEnCola);
void TituloBuscarTrabajador();
void TituloBuscarProveedor();
void TituloBuscarComprador();
int SubMenuModificarPersona(const char* tituloModificarPersona, const char* opcionesModificarPersona[], int nOpcionesModificarPersona);
void TituloModificarTrabajador();
void TituloModificarProveedor();
void TituloModificarComprador();
int SubMenuEliminarPersona(const char* tituloBuscarPersona, const char* opcionesBuscarPersona[], int nOpcionesBuscarPersona);
void TituloEliminaTrabajador();
void TituloEliminaProveedor();
void TituloEliminaComprador();
//Prototipos para el manejo de funciones de los empleados
Empleado* crearEmpleado();
void encolarEmpleado(ColaEmpleado& q, Empleado* nuevo);
void gestionarIngresoEmpleados(ColaEmpleado& q);
void mostrarColaEmpleados(ColaEmpleado q);
Empleado* buscarEmpleado(ColaEmpleado q, int idEmpleadoBuscado);
void modificarEmpleado(ColaEmpleado& q, int idEmpleadoBuscado);
void eliminarEmpleado(ColaEmpleado& q);
//Prototipos para el manejo de funciones de los compradores
Comprador* crearComprador();
void encolarComprador(ColaComprador& q2, Comprador* nuevo);
void gestionarIngresoCompradores(ColaComprador& q2);
void mostrarColaCompradores(ColaComprador q2);
Comprador* buscarComprador(ColaComprador q2, int idCompradorBuscado);
void modificarComprador(ColaComprador& q2, int idCompradorBuscado);
void eliminarComprador(ColaComprador&);
//Prototipos para el manejo de funciones de los proveedores
Proovedor* crearProovedor();
void encolarProovedor(ColaProovedor& q3, Proovedor* nuevo);
void gestionarIngresoProveedores(ColaProovedor& q3);
void mostrarColaProveedores(ColaProovedor q3);
Proovedor* buscarProovedor(ColaProovedor q3, int idProveedorBuscado);
void modificarProovedor(ColaProovedor& q3, int idProveedorBuscado);
void eliminarProovedor(ColaProovedor& q3);
void gotoxy(int, int);

ColaEmpleado q = { nullptr, nullptr }; // Inicializar la cola vacía
ColaComprador q2 = { nullptr, nullptr }; // Inicializar la cola vacía
ColaProovedor q3 = { nullptr, nullptr }; //Inicializar la cola vacia


int main() {
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
	bool repite = true;	//Para no salir del menu o programa hasta que se escoja la opcion de salir

	//Variables para el menu principal
	int opcionMenuPrincipal;
	int nOpcionesMenuPrincipal = 3;

	//Variables para el menu de pila (cerdos)
	int opcionMenuPila;
	int nOpcionesMenuPila = 7;

	//Variables para el menu de cola (personas)
	int opcionMenuCola;
	int nOpcionesMenuCola = 7;

	//Variables para el submenu de ingreso de personas a las colas
	int opcionIngresoPersona;
	int nOpcionesIngresoPersona = 5;

	//Variables para el submenu de ver personas de la cola
	int opcionVerCola;
	int nOpcionesVerCola = 5;

	//Variables para el submenu de buscar personas de la cola
	int opcionBuscarPersona;
	int nOpcionesBuscarPersona = 5;

	//Variables para el submenu de modificar la informacion de una persona de las cola
	int opcionModificarPersona;
	int nOpcionesModificarPersona = 5;

	//Variables para el submenu de eliminar personas de la cola
	int opcionEliminarPersona;
	int nOpcionesEliminarPersona = 5;

	//Titulo y opciones del menu principal
	const char* tituloMenuPrincipal = "Menu Principal de la Granja";
	const char* opcionesMenuPrincipal[] = {
		"Gestionar Informacion de los cerdos (Pila)",
		"Gestionar informacion de pesonas (Cola)",
		"Salir del programa" };

	//Titulo y opciones del menu pila (cerdos)
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

	//Titulo y opciones del menu cola (personas)
	const char* tituloMenuCola = "Gestionar personal de la granja (Cola)";
	const char* opcionesMenuCola[] = {
		"Ingresar una persona",
		"Ver personal",
		"Buscar a una persona",
		"Modificar la informacion de alguna persona",
		"Eliminar a una persona",
		"Regresar al menu principal",
		"Salir del programa"
	};

	//Titulo de submenu de ingreso a las colas (personas)
	const char* tituloIngresoPersona = "Ingreso de datos a las colas (Personas)";
	const char* opcionesIngresoPersona[] = {
		"Ingreso de trabajadores a la cola",
		"Ingreso de proveedores a la cola",
		"Ingreso de compradores a la cola",
		"Regresar al menu de colas",
		"Salir del programa"
	};

	const char* tituloVerCola = "Ver las colas (Personas)";
	const char* opcionesVerCola[] = {
		"Ver cola de trabajadores",
		"Ver cola de proveedores",
		"Ver cola de compradores",
		"Regresar al menu de colas",
		"Salir del programa"
	};

	const char* tituloBuscarPersona = "Buscar persona en cola";
	const char* opcionesBuscarPersona[] = {
		"Buscar en cola de trabajadores",
		"Buscar en cola de proveedores",
		"Buscar en cola d compradores",
		"Regresar al menu de colas",
		"Salir del programa"
	};

	const char* tituloModificarPersona = "Modificar informacion de personas de la cola";
	const char* opcionesModificarPersona[] = {
		"Modificar informacion de trabajadores",
		"Modificar informacion de proveedores",
		"Modificar informacion de compradores",
		"Regresar al meni de colas",
		"Salir del programa"
	};

	const char* tituloEliminarPersona = "Eliminar personas de la cola";
	const char* opcionesEliminarPersona[] = {
		"Eliminar trabajadores",
		"Eliminar proveedores",
		"Eliminar compradores",
		"Regresar al menu de colas",
		"Salir del programa"
	};

	//Variables que sirven para guardar los datos de los cerdos
	Cerdo* pila = NULL;	//Inicializa la pila
	int arete = 0;	//Guarda el numero de arete del cerdo
	int modulo = 0;	//Guarda el numero de modulo en el que se encuentra el cerdo
	string raza;	//Guarda la raza del cerdo
	char sexo;	//Guarda el caracter H o M para saber si el cerdo es Hembra o Macho
	float peso = 0;	//Guarda el peso en Kg del cerdo
	float altura = 0;	//Guarda la altura del cerdo en cm
	string nacimiento;	//Guarda la fecha de nacimiento del cerdo
	int edad = 0;	//Guarda la edad del cerdo en meses
	char salud;	//Guarda el estado de salud del cerdo (E/R/M)
	string ultVac;	//Guarda el nombre de la ultima vacuna aplicada al cerdo
	string feUlVac;	//Guarda la fecha de la ultima vacuna aplicadaal cerdo
	float alimento = 0;	//Guarda la cantidad de alimento que consume el cerdo en Kg
	string procede;	//Guarda el nombre del lugar de procedencia del cerdo
	char venta;	//Guarda el esado de venta del cerdo (Si/No)
	float precio = 0;	//Guarda el precio del cerdo si en dado caso estará a la venta
	string destino;	//Guarda a que esta destinado el cerdo (Consumo Humano/Reproduccion/Vewnta como Lechon/Industrial)
	char rpt;

	//Variables para las colas de empleados y compradores
	ColaEmpleado empleados;
	ColaComprador compradores;
	ColaProovedor proveedores;

	int idEmpleadoBuscado = 0;	//Variable que guarda el id ingresado para buscar en la cola de empleados
	int idCompradorBuscado = 0;	//Variable que guarda el id ingresado para buscar en la cola de compradores
	int idProovedorBuscado = 0; //Variable que guarda el id ingresado para buscar en la cola de proveedores

	do {
		opcionMenuPrincipal = MenuPrincipal(tituloMenuPrincipal, opcionesMenuPrincipal, nOpcionesMenuPrincipal);
		switch (opcionMenuPrincipal) {
			//Si el usuario escoge la opcion de gestionar cerdos entra aca
		case 1:
			do {
				opcionMenuPila = MenuPila(tituloMenuPila, opcionesMenuPila, nOpcionesMenuPila);
				switch (opcionMenuPila) {
				case 1:
					// Para ingresar un nuevo cerdo a la pila
					do {
						system("cls");
						TituloIngresaCerdo();
						gotoxy(5, 6); cout << "--------------------------------------------------------------------------";
						gotoxy(5, 7); cout << "Ingrese el numero de arete del cerdo: ";
						gotoxy(43, 7); cin >> arete;
						gotoxy(5, 8); cout << "Ingrese el modulo al que pertenece el cerdo: ";
						gotoxy(50, 8); cin >> modulo;
						gotoxy(5, 9); cout << "Ingrese la raza del cerdo (Ej: Landrance, Duroc, Hampshire, etc) : ";
						cin.ignore();
						gotoxy(72, 9); getline(cin, raza);
						gotoxy(5, 10); cout << "Ingrese el sexo del cerdo (H = Hembra/ M = Macho) : ";
						gotoxy(57, 10); cin >> sexo;
						gotoxy(5, 11); cout << "Ingrese el peso del cerdo en Kg: ";
						gotoxy(38, 11); cin >> peso;
						gotoxy(5, 12); cout << "Ingrese la altura del cerdo en centimetros: ";
						gotoxy(49, 12); cin >> altura;
						gotoxy(5, 13); cout << "Ingrese la fecha de nacimiento el cerdo (dd/mm/aa): ";
						cin.ignore();
						gotoxy(57, 13); getline(cin, nacimiento);
						gotoxy(5, 14); cout << "Ingrese la edad del cerdo en meses: ";
						gotoxy(41, 14); cin >> edad;
						gotoxy(5, 15); cout << "Ingrese el estado de salud del cerdo (E = Excelente, R = Regular, M = Malo) : ";
						gotoxy(83, 15); cin >> salud;
						gotoxy(5, 16); cout << "Ingrese el nombre de la ultima vacuna aplicada al cerdo: ";
						cin.ignore();
						gotoxy(62, 16); getline(cin, ultVac);
						gotoxy(5, 17); cout << "Ingrese la fecha de la ultima vacuna aplicada al cerdo (dd/mm/aa) : ";
						gotoxy(73, 17); cin >> feUlVac;
						gotoxy(5, 18); cout << "Ingrese la cantidad de alimento que consume el cerdo en Kg: ";
						gotoxy(65, 18); cin >> alimento;
						gotoxy(5, 19); cout << "Ingrese el lugar de procedencia del cerdo (municipio y departamento): ";
						cin.ignore();
						gotoxy(75, 19); getline(cin, procede);
						gotoxy(5, 20); cout << "Ingrese el estado de venta del cerdo (s/n): ";
						gotoxy(50, 20); cin >> venta;
						if (venta == 'S' || venta == 's') {
							gotoxy(5, 21); cout << "Ingrese el precio de venta del cerdo: Q.";
							gotoxy(45, 21); cin >> precio;
						}
						gotoxy(5, 22); cout << "Ingrese a que esta destinado el cerdo (Consumo Humano/Reproduccion/Industrializacion/etc): ";
						cin.ignore();
						gotoxy(96, 22); getline(cin, destino);
						gotoxy(5, 23); cout << "------------------------------------------------------------------------";
						agregarPila(pila, arete, modulo, raza, sexo, peso, altura, nacimiento, edad, salud, ultVac, feUlVac, alimento, procede, venta, precio, destino);

						gotoxy(45, 27); cout << "Desea ingresar otro cerdo a la pila? (s/n): ";
						gotoxy(89, 27); cin >> rpt;
					} while (rpt == 'S' || rpt == 's');
					system("cls");
					TituloIngresaCerdo();
					mostrarPila(pila);
					break;
				case 2:
					//Para ver los cerdos de la pila
					system("cls");
					TituloVerCerdos();
					mostrarPila(pila);
					break;
				case 3:
					//Para buscar a algun cerdo de la pila
					system("cls");
					TituloBuscarCerdo();
					buscarCerdo(pila);
					break;
				case 4:
					//Para modificar a algun cerdo de la pila
					system("cls");
					TituloModificarCerdo();
					modificarCerdo(pila);
					break;
				case 5:
					//Para eliminar al ultimo cerdo ingresado a la pila
					system("cls");
					TituloEliminarCerdo();
					eliminarCerdosPila(pila);
					void mostrarPila(Cerdo*&);
					break;
				case 6:
					//Para regresar al menu principal
					opcionMenuPrincipal = 0;
					break;
				case 7:
					//Para salir del programa
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
					//Para ingresar a alguna persona a la cola (Trabajador, Proveedor o comprador)
					do {
						opcionIngresoPersona = SubMenuIngresoPersona(tituloIngresoPersona, opcionesIngresoPersona, nOpcionesIngresoPersona);
						switch (opcionIngresoPersona) {
						case 1:
							//Para ingresar datos de trabajadores a la cola
							system("cls");
							TituloIngresaTrabajador();
							gestionarIngresoEmpleados(q);
							void mostrarColaEmpleados(ColaEmpleado&);
							break;
						case 2:
							//Para ingresar datos de proveedores a la cola
							system("cls");
							TituloIngresaProveedor();
							gestionarIngresoProveedores(q3);
							void mostrarColaProveedores(ColaProovedor&);
							break;
						case 3:
							//Para ingresar datos de compradores a la cola
							system("cls");
							TituloIngresaComprador();
							gestionarIngresoCompradores(q2);
							void mostrarColaCompradores(ColaComprador&);
							break;
						case 4:
							opcionMenuCola = 0;
							break;
						case 5:
							repite = false;
							break;
						}
					} while (opcionIngresoPersona != 4 && repite);
					break;
				case 2:
					//Para ver la informacion de las personas en alguna cola (Trabajador, proveedor o comprador)
					do {
						opcionVerCola = SubMenuVerCola(tituloVerCola, opcionesVerCola, nOpcionesVerCola);
						switch (opcionVerCola) {
						case 1:
							//Para ver la cola de trabajadores
							system("cls");
							TituloVerTrabajadores();
							mostrarColaEmpleados(q);
							break;
						case 2:
							//Para ver la cola de proveedores
							system("cls");
							TituloVerProveedor();
							mostrarColaProveedores(q3);
							break;
						case 3:
							//Para ver la cola de compradores
							system("cls");
							TituloVerComprador();
							mostrarColaCompradores(q2);
							break;
						case 4:
							//Para regresar al submenu de colas
							opcionMenuCola = 0;
							break;
						case 5:
							repite = false;
							break;
						}
					} while (opcionVerCola != 4 && repite);
					break;
				case 3:
					//Para buscar a alguna persona dentro de alguna cola (trabajador, proveedor o comprador)
					do {
						opcionBuscarPersona = SubMenuBuscarPersona(tituloBuscarPersona, opcionesBuscarPersona, nOpcionesBuscarPersona);
						switch (opcionBuscarPersona) {
						case 1:
							//Para buscar en la cola de trabajadores
							system("cls");
							TituloBuscarTrabajador();
							gotoxy(40, 6); cout << "Ingrese el id del trabajador que desea buscar en la cola: ";
							cin >> idEmpleadoBuscado;
							buscarEmpleado(q, idEmpleadoBuscado);
							break;
						case 2:
							//Para buscar en la cola de proveedores
							system("cls");
							TituloBuscarProveedor();
							gotoxy(40, 6); cout << "Ingrese el id del proveedor que desea buscar en la cola: ";
							cin >> idProovedorBuscado;
							buscarProovedor(q3, idProovedorBuscado);
							break;
						case 3:
							//Para buscar en la cola de compradores
							system("cls");
							TituloBuscarComprador();
							gotoxy(40, 6); cout << "Ingrese el id del comprador que desea buscar en la cola: ";
							cin >> idCompradorBuscado;
							buscarComprador(q2, idCompradorBuscado);
							break;
						case 4:
							opcionMenuCola = 0;
							break;
						case 5:
							repite = false;
							break;
						}
					} while (opcionBuscarPersona != 4 && repite);
					break;
				case 4:
					//Para modificar la informacion de alguna persona dentro de alguna cola (trabajador, proveedor o comprador)
					opcionModificarPersona = SubMenuModificarPersona(tituloModificarPersona, opcionesModificarPersona, nOpcionesModificarPersona);
					switch (opcionModificarPersona) {
					case 1:
						// Para modificar información de trabajadores
						system("cls");
						TituloModificarTrabajador();

						// Verificar si la cola de trabajadores está vacía
						if (q.delante == nullptr) {
							gotoxy(40, 6); cout << "La cola de trabajadores está vacía.";
							gotoxy(40, 8); cout << "Presione una tecla para volver al menú de trabajadores...";
							_getch();
							return;
						}
						gotoxy(40, 6); cout << "Ingrese el id del trabajador que desea modificar: ";
						cin >> idEmpleadoBuscado;
						modificarEmpleado(q, idEmpleadoBuscado);
						break;
					case 2:
						// Para modificar información de proveedores
						system("cls");
						TituloModificarProveedor();

						// Verificar si la cola de proveedores está vacía
						if (q3.delante == nullptr) {
							gotoxy(40, 6); cout << "La cola de proveedores está vacía.";
							gotoxy(40, 8); cout << "Presione una tecla para volver al menú de proveedores...";
							_getch();
							return;
						}
						gotoxy(40, 6); cout << "Ingrese el id del proveedor que desea modificar: ";
						cin >> idProovedorBuscado;
						modificarProovedor(q3, idProovedorBuscado);
						break;
					case 3:
						// Para modificar información de compradores
						system("cls");
						TituloModificarComprador();

						// Verificar si la cola de compradores está vacía
						if (q2.delante == nullptr) {
							gotoxy(40, 6); cout << "La cola de compradores está vacía.";
							gotoxy(40, 8); cout << "Presione una tecla para volver al menú de compradores...";
							_getch();
							return;
						}
						gotoxy(40, 6); cout << "Ingrese el id del comprador que desea modificar: ";
						cin >> idCompradorBuscado;
						modificarComprador(q2, idCompradorBuscado);
						break;
					case 4:
						opcionMenuCola = 0;
						break;
					case 5:
						repite = false;
						break;
					}
					break;
				case 5:
					//Para eliminar a la primera persona de alguna cola (trabajador, proveedor o comprador
					opcionEliminarPersona = SubMenuEliminarPersona(tituloEliminarPersona, opcionesEliminarPersona, nOpcionesEliminarPersona);
					switch (opcionEliminarPersona) {
					case 1:
						//Para eliminar el ultimo trabajador ingresado
						system("cls");
						TituloEliminaTrabajador();
						eliminarEmpleado(q);
						void mostrarColaEmpleados(ColaEmpleado q);
						break;
					case 2:
						//Para eliminar el ultimo proveedor ingresado
						system("cls");
						TituloEliminaProveedor();
						eliminarProovedor(q3);
						void mostrarColaProveedores(ColaProovedor q3);
						break;
					case 3:
						//Para eliminar el ultimo comprador ingresado
						system("cls");
						TituloEliminaComprador();
						eliminarComprador(q2);
						void mostrarColaCompradores(ColaComprador q2);
						break;
					case 4:
						opcionMenuCola = 0;
						break;
					case 5:
						repite = false;
						break;
					}
					break;
				case 6:
					//Para regresar al menu principal
					opcionMenuPrincipal = 0;
					break;
				case 7:
					//Para salir del programa
					repite = false;
					break;
				}
			} while (opcionMenuCola != 6 && repite);
			break;
		case 3:
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

		gotoxy(30, 14); cout << "**********************************************************" << endl;
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

//Funcion para agregar cerdos a la pila
void agregarPila(Cerdo*& pila, int& arete, int& modulo, string& raza, char& sexo, float& peso, float& altura, string& nacimiento, int& edad, char& salud, string& ultVac, string& feUlVac, float& alimento, string& procede, char& venta, float& precio, string& destino) {
	Cerdo* nuevo_cerdo = new Cerdo();

	// Validación para el número de arete
	do {
		gotoxy(5, 7); cout << "Ingrese el numero de arete del cerdo: ";
		gotoxy(43, 7); cin >> arete;
		if (arete <= 0) {
			gotoxy(5, 8); cout << "El numero de arete debe ser un entero positivo.";
		}
	} while (arete <= 0);

	// Validación para el número de módulo
	do {
		gotoxy(5, 9); cout << "Ingrese el modulo al que pertenece el cerdo: ";
		gotoxy(50, 9); cin >> modulo;
		if (modulo <= 0) {
			gotoxy(5, 10); cout << "El modulo debe ser un entero positivo.";
		}
	} while (modulo <= 0);

	// Validación para la raza
	gotoxy(5, 11); cout << "Ingrese la raza del cerdo (Ej: Landrance, Duroc, Hampshire, etc) : ";
	cin.ignore();
	gotoxy(72, 11); getline(cin, raza);

	// Validación para el sexo
	do {
		gotoxy(5, 13); cout << "Ingrese el sexo del cerdo (H = Hembra/ M = Macho) : ";
		gotoxy(57, 13); cin >> sexo;
		if (sexo != 'H' && sexo != 'M') {
			gotoxy(5, 14); cout << "El sexo debe ser 'H' para Hembra o 'M' para Macho.";
		}
	} while (sexo != 'H' && sexo != 'M');

	// Validación para el peso
	do {
		gotoxy(5, 15); cout << "Ingrese el peso del cerdo en Kg: ";
		gotoxy(38, 15); cin >> peso;
		if (peso <= 0) {
			gotoxy(5, 16); cout << "El peso debe ser un número positivo.";
		}
	} while (peso <= 0);

	// Validación para la altura
	do {
		gotoxy(5, 17); cout << "Ingrese la altura del cerdo en centimetros: ";
		gotoxy(49, 17); cin >> altura;
		if (altura <= 0) {
			gotoxy(5, 18); cout << "La altura debe ser un número positivo.";
		}
	} while (altura <= 0);

	// Validación para la fecha de nacimiento
	gotoxy(5, 19); cout << "Ingrese la fecha de nacimiento el cerdo (dd/mm/aa): ";
	cin.ignore();
	gotoxy(57, 19); getline(cin, nacimiento);

	// Validación para la edad
	do {
		gotoxy(5, 21); cout << "Ingrese la edad del cerdo en meses: ";
		gotoxy(41, 21); cin >> edad;
		if (edad < 0) {
			gotoxy(5, 22); cout << "La edad debe ser un número no negativo.";
		}
	} while (edad < 0);

	// Validación para el estado de salud
	do {
		gotoxy(5, 23); cout << "Ingrese el estado de salud del cerdo (E = Excelente, R = Regular, M = Malo) : ";
		gotoxy(83, 23); cin >> salud;
		if (salud != 'E' && salud != 'R' && salud != 'M') {
			gotoxy(5, 24); cout << "El estado de salud debe ser 'E', 'R' o 'M'.";
		}
	} while (salud != 'E' && salud != 'R' && salud != 'M');

	// Validación para la última vacuna
	gotoxy(5, 25); cout << "Ingrese el nombre de la ultima vacuna aplicada al cerdo: ";
	cin.ignore();
	gotoxy(62, 25); getline(cin, ultVac);

	// Validación para la fecha de la última vacuna
	gotoxy(5, 27); cout << "Ingrese la fecha de la ultima vacuna aplicada al cerdo (dd/mm/aa) : ";
	gotoxy(73, 27); cin >> feUlVac;

	// Validación para la cantidad de alimento
	do {
		gotoxy(5, 29); cout << "Ingrese la cantidad de alimento que consume el cerdo en Kg: ";
		gotoxy(65, 29); cin >> alimento;
		if (alimento <= 0) {
			gotoxy(5, 30); cout << "La cantidad de alimento debe ser un número positivo.";
		}
	} while (alimento <= 0);

	// Validación para la procedencia
	gotoxy(5, 31); cout << "Ingrese el lugar de procedencia del cerdo (municipio y departamento): ";
	cin.ignore();
	gotoxy(75, 31); getline(cin, procede);

	// Validación para el estado de venta
	do {
		gotoxy(5, 33); cout << "Ingrese el estado de venta del cerdo (s/n): ";
		gotoxy(50, 33); cin >> venta;
		if (venta != 'S' && venta != 's' && venta != 'N' && venta != 'n') {
			gotoxy(5, 34); cout << "El estado de venta debe ser 's' o 'n'.";
		}
	} while (venta != 'S' && venta != 's' && venta != 'N' && venta != 'n');

	if (venta == 'S' || venta == 's') {
		do {
			gotoxy(5, 35); cout << "Ingrese el precio de venta del cerdo: Q.";
			gotoxy(45, 35); cin >> precio;
			if (precio <= 0) {
				gotoxy(5, 36); cout << "El precio debe ser un número positivo.";
			}
		} while (precio <= 0);
	}

	// Validación para el destino
	gotoxy(5, 37); cout << "Ingrese a que esta destinado el cerdo (Consumo Humano/Reproduccion/Industrializacion/etc): ";
	cin.ignore();
	gotoxy(96, 37); getline(cin, destino);

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

	gotoxy(20, 39); cout << "El cerdo con el arete " << arete << " fue agregado correctamente a la pila de cerdos correctamente";
}


void mostrarPila(Cerdo* pila) {
	if (pila == nullptr) {
		gotoxy(45, 7); cout << "La pila está vacía. No hay cerdos registrados.";
		return;
	}

	Cerdo* aux = pila; // Puntero auxiliar para recorrer la pila

	while (aux != nullptr) {
		cout << endl << endl;
		cout << "\t\t\t\t\t------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\tFicha del cerdo con el arete " << aux->numArete << endl;
		cout << "\t\t\t\t\t------------------------------------------------" << endl;
		cout << "\t\t\t\t\tModulo: " << aux->numModulo << endl;
		cout << "\t\t\t\t\tRaza: " << aux->raza << endl;
		cout << "\t\t\t\t\tSexo (M = macho/H = Hembra): " << aux->sexo << endl;
		cout << "\t\t\t\t\tPeso (Kg): " << aux->peso << endl;
		cout << "\t\t\t\t\tAltura (cm): " << aux->altura << endl;
		cout << "\t\t\t\t\tFecha de nacimiento(dd/mm/aa): " << aux->fechaNac << endl;
		cout << "\t\t\t\t\tEdad (meses): " << aux->edad << endl;
		cout << "\t\t\t\t\tSalud (E = Excelente/R = Regular/M = Mala): " << aux->estadoSalud << endl;
		cout << "\t\t\t\t\tUltima vacuna: " << aux->ultimaVacuna << endl;
		cout << "\t\t\t\t\tFecha de ultima vacunacion: " << aux->fechaUltimaVacuna << endl;
		cout << "\t\t\t\t\tAlimento consumido: " << aux->cantAlimento << endl;
		cout << "\t\t\t\t\tProcedencia: " << aux->procedencia << endl;
		cout << "\t\t\t\t\tVenta: " << aux->venta << endl;
		cout << "\t\t\t\t\tDestino: " << aux->destino << endl;
		cout << "\t\t\t\t\tDireccion de memoria de este nodo: " << aux << endl;
		cout << "\t\t\t\t\t------------------------------------------------" << endl;

		aux = aux->siguiente;  // Avanzamos al siguiente cerdo en la pila
	}

	cout << endl;
	cout << "\t\t\t\tPresione una tecla para volver al menu de pila de cerdos...";
	_getch();
}

void buscarCerdo(Cerdo* pila) {
	int areteBuscado = 0;	//Variable que sirve para buscar la ficha de un cerdo por su nombre de arete

	if (pila == nullptr) {
		gotoxy(40, 6); cout << "La pila está vacía. No hay cerdos registrados para buscar.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menu de pila de cerdos...";
		_getch();
		return;
	}

	gotoxy(20, 6); cout << "Ingrese el numero de arete del cerdo que desea buscar en la pila: ";
	gotoxy(86, 6); cin >> areteBuscado;

	Cerdo* aux = pila; // Puntero auxiliar para recorrer la pila
	bool encontrado = false;

	while (aux != nullptr) {
		if (aux->numArete == areteBuscado) {
			gotoxy(45, 8); cout << "------------------------------------------------";
			gotoxy(50, 9); cout << "Ficha del cerdo con el arete " << aux->numArete;
			gotoxy(45, 10); cout << "------------------------------------------------";
			gotoxy(45, 11); cout << "Modulo: " << aux->numModulo;
			gotoxy(45, 12); cout << "Raza: " << aux->raza;
			gotoxy(45, 13); cout << "Sexo (M = macho/H = Hembra): " << aux->sexo;
			gotoxy(45, 14); cout << "Peso (Kg): " << aux->peso;
			gotoxy(45, 15); cout << "Altura (cm): " << aux->altura;
			gotoxy(45, 16); cout << "Fecha de nacimiento(dd/mm/aa): " << aux->fechaNac;
			gotoxy(45, 17); cout << "Edad (meses): " << aux->edad;
			gotoxy(45, 18); cout << "Salud (E = Excelente/R = Regular/M = Mala): " << aux->estadoSalud;
			gotoxy(45, 19); cout << "Ultima vacuna: " << aux->ultimaVacuna;
			gotoxy(45, 20); cout << "Fecha de ultima vacunacion: " << aux->fechaUltimaVacuna;
			gotoxy(45, 21); cout << "Alimento consumido: " << aux->cantAlimento;
			gotoxy(45, 22); cout << "Procedencia: " << aux->procedencia;
			gotoxy(45, 23); cout << "Venta: " << aux->venta;
			gotoxy(45, 24); cout << "Destino: " << aux->destino;
			gotoxy(45, 25); cout << "Direccion de memoria de este nodo: " << aux;
			gotoxy(45, 26); cout << "------------------------------------------------";
			encontrado = true;
			break;  // Salimos del bucle ya que encontramos el cerdo
		}
		aux = aux->siguiente;
	}

	if (!encontrado) {
		gotoxy(45, 8); cout << "No se encontró ningún cerdo con el arete " << areteBuscado << ".";
		gotoxy(40, 10); cout << "Presione una tecla para volver al menu de pila de cerdos...";
		_getch();
		return;
	}
	gotoxy(40, 28); cout << "Presione una tecla para volver al menu de pila de cerdos...";
	_getch();
}

void modificarCerdo(Cerdo* pila) {
	int areteBuscado = 0;  // Variable para buscar la ficha del cerdo por su número de arete
	Cerdo* aux = pila; // Puntero auxiliar para recorrer la pila
	bool encontrado = false;
	char respuesta;

	if (pila == nullptr) {
		gotoxy(40, 6); cout << "La pila está vacía. No hay cerdos registrados para modificar.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menu de pila de cerdos...";
		_getch();
		return;
	}

	gotoxy(25, 6); cout << "Ingrese el numero de arete del cerdo que desea modificar en la pila: ";
	cin >> areteBuscado;

	while (aux != nullptr) {
		if (aux->numArete == areteBuscado) {
			encontrado = true;
			break;  // Salimos del bucle ya que encontramos el cerdo
		}
		aux = aux->siguiente;
	}

	if (!encontrado) {
		gotoxy(45, 8); cout << "No se encontró ningún cerdo con el arete " << areteBuscado << ".";
		gotoxy(40, 10); cout << "Presione una tecla para volver al menu de pila de cerdos...";
		_getch();
		return;
	}

	// Ahora modificamos los datos, preguntando al usuario si desea cambiar cada uno
	gotoxy(40, 8); cout << "Cerdo encontrado con el arete " << aux->numArete << ".";

	// Modificar módulo
	gotoxy(35, 10); cout << "Modificar modulo (Actual: " << aux->numModulo << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 11); cout << "Nuevo modulo: ";
		cin >> aux->numModulo;
	}

	// Modificar raza
	gotoxy(35, 12); cout << "Modificar raza (Actual: " << aux->raza << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 13); cout << "Nueva raza: ";
		cin >> aux->raza;
	}

	// Modificar sexo
	gotoxy(35, 14); cout << "Modificar sexo (Actual: " << aux->sexo << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 15); cout << "Nuevo sexo (M = macho / H = Hembra): ";
		cin >> aux->sexo;
	}

	// Modificar peso
	gotoxy(35, 16); cout << "Modificar peso (Actual: " << aux->peso << " kg)? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 17); cout << "Nuevo peso (kg): ";
		cin >> aux->peso;
	}

	// Modificar altura
	gotoxy(35, 18); cout << "Modificar altura (Actual: " << aux->altura << " cm)? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 19); cout << "Nueva altura (cm): ";
		cin >> aux->altura;
	}

	// Modificar fecha de nacimiento
	gotoxy(35, 20); cout << "Modificar fecha de nacimiento (Actual: " << aux->fechaNac << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 21); cout << "Nueva fecha de nacimiento (dd/mm/aa): ";
		cin >> aux->fechaNac;
	}

	// Modificar edad
	gotoxy(35, 22); cout << "Modificar edad (Actual: " << aux->edad << " meses)? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 23); cout << "Nueva edad (meses): ";
		cin >> aux->edad;
	}

	// Modificar estado de salud
	gotoxy(35, 24); cout << "Modificar salud (Actual: " << aux->estadoSalud << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 25); cout << "Nuevo estado de salud (E = Excelente / R = Regular / M = Mala): ";
		cin >> aux->estadoSalud;
	}

	// Modificar última vacuna
	gotoxy(35, 26); cout << "Modificar última vacuna (Actual: " << aux->ultimaVacuna << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 27); cout << "Nueva última vacuna: ";
		cin >> aux->ultimaVacuna;
	}

	// Modificar fecha última vacunación
	gotoxy(35, 28); cout << "Modificar fecha de última vacunación (Actual: " << aux->fechaUltimaVacuna << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 29); cout << "Nueva fecha de última vacunación (dd/mm/aa): ";
		cin >> aux->fechaUltimaVacuna;
	}

	// Confirmar cambio y terminar
	gotoxy(40, 31); cout << "Datos del cerdo modificados correctamente.";
	gotoxy(40, 33); cout << "Presione una tecla para volver al menú de pila de cerdos...";
	_getch();
}

void eliminarCerdosPila(Cerdo*& pila) {
	char respuesta;

	if (pila == nullptr) {
		gotoxy(40, 6); cout << "La pila está vacía. No hay cerdos para eliminar.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menú de pila de cerdos...";
		_getch();
		return;
	}

	do {
		system("cls");
		TituloEliminarCerdo();
		// Copia temporal para mostrar los datos antes de eliminar
		Cerdo cerdoEliminado;
		sacarPila(pila);

		gotoxy(40, 27); cout << "¿Desea eliminar otro cerdo? (S/N): ";
		cin >> respuesta;

	} while ((respuesta == 'S' || respuesta == 's') && pila != nullptr);

	gotoxy(40, 27); cout << "Operación finalizada. Presione una tecla para volver al menu de pila...";
	_getch();
}


void sacarPila(Cerdo*& pila) {
	if (pila == nullptr) {
		gotoxy(40, 6); cout << "La pila está vacía. No hay cerdos para eliminar.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menú de pila de cerdos...";
		_getch();
		return;
	}

	// Guardar referencia al cerdo que se eliminará
	Cerdo* aux = pila;

	// Mostrar información del cerdo que será eliminado
	gotoxy(40, 8); cout << "Se eliminó el siguiente cerdo:";
	gotoxy(40, 10); cout << "----------------------------------------------";
	gotoxy(40, 11); cout << "Arete: " << aux->numArete;
	gotoxy(40, 12); cout << "Modulo: " << aux->numModulo;
	gotoxy(40, 13); cout << "Raza: " << aux->raza;
	gotoxy(40, 14); cout << "Sexo: " << aux->sexo;
	gotoxy(40, 15); cout << "Peso: " << aux->peso << " Kg";
	gotoxy(40, 16); cout << "Altura: " << aux->altura << " cm";
	gotoxy(40, 17); cout << "Edad: " << aux->edad << " meses";
	gotoxy(40, 18); cout << "Salud: " << aux->estadoSalud;
	gotoxy(40, 19); cout << "Última vacuna: " << aux->ultimaVacuna;
	gotoxy(40, 20); cout << "Fecha última vacunación: " << aux->fechaUltimaVacuna;
	gotoxy(40, 21); cout << "Alimento consumido: " << aux->cantAlimento << " kg";
	gotoxy(40, 22); cout << "Procedencia: " << aux->procedencia;
	gotoxy(40, 23); cout << "Venta: " << aux->venta;
	gotoxy(40, 24); cout << "Destino: " << aux->destino;
	gotoxy(40, 25); cout << "----------------------------------------------";

	// Mover la cima de la pila al siguiente nodo
	pila = aux->siguiente;

	// Liberar memoria del nodo eliminado
	delete aux;

	gotoxy(40, 29); cout << "Operación finalizada. Presione una tecla para continuar...";
	_getch();
}


int MenuCola(const char* tituloMenuCola, const char* opcionesMenuCola[], int nOpcionesMenuCola) {
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;

	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "*** " << tituloMenuCola << " ***" << endl;
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

int SubMenuIngresoPersona(const char* tituloIngresoPersona, const char* opcionesIngresoPersona[], int nOpcionesIngresoPersona) {
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;

	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "***             " << tituloIngresoPersona << "            ***" << endl;
		gotoxy(30, 10); cout << "**********************************************************" << endl;

		for (int i = 0; i < nOpcionesIngresoPersona; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesIngresoPersona[i];
			}
			else {
				cout << "     " << opcionesIngresoPersona[i];
			}
		}

		gotoxy(30, 16); cout << "**********************************************************" << endl;
		gotoxy(18, 20); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

		tecla = _getch(); // Captura la tecla presionada

		switch (tecla) {
		case 72: // Flecha arriba
			if (opcionSeleccionada > 1) opcionSeleccionada--;
			break;
		case 80: // Flecha abajo
			if (opcionSeleccionada < nOpcionesIngresoPersona) opcionSeleccionada++;
			break;
		case 13: // Enter
			repite = false;
			break;
		}
	} while (repite);

	return opcionSeleccionada;
}

int SubMenuVerCola(const char* tituloVerCola, const char* opcionesVerCola[], int nOpcionesVerCola) {
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;

	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "***                " << tituloVerCola << "            ***" << endl;
		gotoxy(30, 10); cout << "**********************************************************" << endl;

		for (int i = 0; i < nOpcionesVerCola; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesVerCola[i];
			}
			else {
				cout << "     " << opcionesVerCola[i];
			}
		}

		gotoxy(30, 16); cout << "**********************************************************" << endl;
		gotoxy(18, 20); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

		tecla = _getch(); // Captura la tecla presionada

		switch (tecla) {
		case 72: // Flecha arriba
			if (opcionSeleccionada > 1) opcionSeleccionada--;
			break;
		case 80: // Flecha abajo
			if (opcionSeleccionada < nOpcionesVerCola) opcionSeleccionada++;
			break;
		case 13: // Enter
			repite = false;
			break;
		}
	} while (repite);

	return opcionSeleccionada;
}

int SubMenuBuscarPersona(const char* tituloBuscarPersona, const char* opcionesBuscarPersona[], int nOpcionesBuscarPersona) {
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;

	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "***             " << tituloBuscarPersona << "            ***" << endl;
		gotoxy(30, 10); cout << "**********************************************************" << endl;

		for (int i = 0; i < nOpcionesBuscarPersona; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesBuscarPersona[i];
			}
			else {
				cout << "     " << opcionesBuscarPersona[i];
			}
		}

		gotoxy(30, 16); cout << "**********************************************************" << endl;
		gotoxy(18, 20); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

		tecla = _getch(); // Captura la tecla presionada

		switch (tecla) {
		case 72: // Flecha arriba
			if (opcionSeleccionada > 1) opcionSeleccionada--;
			break;
		case 80: // Flecha abajo
			if (opcionSeleccionada < nOpcionesBuscarPersona) opcionSeleccionada++;
			break;
		case 13: // Enter
			repite = false;
			break;
		}
	} while (repite);

	return opcionSeleccionada;
}

int SubMenuModificarPersona(const char* tituloModificarPersona, const char* opcionesModificarPersona[], int nOpcionesModificarPersona) {
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;

	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "***             " << tituloModificarPersona << "            ***" << endl;
		gotoxy(30, 10); cout << "**********************************************************" << endl;

		for (int i = 0; i < nOpcionesModificarPersona; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesModificarPersona[i];
			}
			else {
				cout << "     " << opcionesModificarPersona[i];
			}
		}

		gotoxy(30, 16); cout << "**********************************************************" << endl;
		gotoxy(18, 20); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

		tecla = _getch(); // Captura la tecla presionada

		switch (tecla) {
		case 72: // Flecha arriba
			if (opcionSeleccionada > 1) opcionSeleccionada--;
			break;
		case 80: // Flecha abajo
			if (opcionSeleccionada < nOpcionesModificarPersona) opcionSeleccionada++;
			break;
		case 13: // Enter
			repite = false;
			break;
		}
	} while (repite);

	return opcionSeleccionada;
}

int SubMenuEliminarPersona(const char* tituloEliminarPersona, const char* opcionesEliminarPersona[], int nOpcionesEliminarPersona) {
	int opcionSeleccionada = 1; // Opción inicial
	int tecla = 0;
	bool repite = true;

	do {
		system("cls");
		gotoxy(30, 8); cout << "**********************************************************" << endl;
		gotoxy(30, 9); cout << "***             " << tituloEliminarPersona << "            ***" << endl;
		gotoxy(30, 10); cout << "**********************************************************" << endl;

		for (int i = 0; i < nOpcionesEliminarPersona; i++) {
			gotoxy(33, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << " ==> " << opcionesEliminarPersona[i];
			}
			else {
				cout << "     " << opcionesEliminarPersona[i];
			}
		}

		gotoxy(30, 16); cout << "**********************************************************" << endl;
		gotoxy(18, 20); cout << " Use las teclas de direccion (Arriba, Abajo) para navegar y ENTER para seleccionar." << endl;

		tecla = _getch(); // Captura la tecla presionada

		switch (tecla) {
		case 72: // Flecha arriba
			if (opcionSeleccionada > 1) opcionSeleccionada--;
			break;
		case 80: // Flecha abajo
			if (opcionSeleccionada < nOpcionesEliminarPersona) opcionSeleccionada++;
			break;
		case 13: // Enter
			repite = false;
			break;
		}
	} while (repite);

	return opcionSeleccionada;
}

//Funcion para crear trabajadores a la cola de empleados
Empleado* crearEmpleado() {
	char rpt;
	system("CLS");
	TituloIngresaTrabajador();
	Empleado* nuevo = new Empleado;

	// Validación para el ID
	do {
		gotoxy(45, 7); cout << "Ingrese ID del empleado: ";
		cin >> nuevo->id;
		if (nuevo->id <= 0) {
			gotoxy(45, 8); cout << "El ID debe ser un entero positivo.";
		}
	} while (nuevo->id <= 0);

	cin.ignore();
	gotoxy(45, 9); cout << "Ingrese nombre: "; getline(cin, nuevo->nombre);
	gotoxy(45, 10); cout << "Ingrese fecha de nacimiento (dd/mm/aa): "; getline(cin, nuevo->fechaNacimiento);

	// Validación para el género
	do {
		gotoxy(45, 11); cout << "Ingrese genero (M = Masculino/F = Femenino): ";
		getline(cin, nuevo->genero);
		if (nuevo->genero != "M" && nuevo->genero != "F") {
			gotoxy(45, 12); cout << "El genero debe ser 'M' para Masculino o 'F' para Femenino.";
		}
	} while (nuevo->genero != "M" && nuevo->genero != "F");

	gotoxy(45, 13); cout << "Ingrese puesto: "; getline(cin, nuevo->cargo);
	gotoxy(45, 14); cout << "Ingrese departamento del puesto: "; getline(cin, nuevo->departamento);
	gotoxy(45, 15); cout << "Ingrese horario de trabajo: "; getline(cin, nuevo->horario);
	gotoxy(45, 16); cout << "Ingrese telefono: "; getline(cin, nuevo->telefono);
	gotoxy(45, 17); cout << "Ingrese direccion de residencia: "; getline(cin, nuevo->direccion);

	// Validación para el salario
	do {
		gotoxy(45, 18); cout << "Ingrese salario: Q";
		cin >> nuevo->salario;
		if (nuevo->salario <= 0) {
			gotoxy(45, 19); cout << "El salario debe ser un número positivo.";
		}
	} while (nuevo->salario <= 0);

	cin.ignore();
	gotoxy(45, 20); cout << "Ingrese estado civil (Soltero/Casado/Viudo): "; getline(cin, nuevo->estado);
	gotoxy(45, 21); cout << "Ingrese beneficios: "; getline(cin, nuevo->beneficios);
	gotoxy(45, 22); cout << "Ingrese fecha de contratacion: "; getline(cin, nuevo->fechaContratacion);
	gotoxy(35, 23); cout << "-----------------------------------------------------";
	nuevo->sgte = nullptr;
	return nuevo;
}

//Funcion para agregar nodo (empleado) a la cola de empleados
void encolarEmpleado(ColaEmpleado& q, Empleado* nuevo) {
	if (q.delante == nullptr) q.delante = nuevo;
	else q.atras->sgte = nuevo;
	q.atras = nuevo;
}

//Funcion para gestionar el ingreso de empleados a la cola de empleados (Si se ingresan mas o ya no)
void gestionarIngresoEmpleados(ColaEmpleado& q) {
	char rpt;
	do {
		Empleado* nuevo = crearEmpleado();
		encolarEmpleado(q, nuevo);
		gotoxy(35, 22); cout << "Empleado ingresado correctamente a la cola de clientes.";
		gotoxy(45, 24); cout << "Desea ingresar otro empleado? (s/n): ";
		cin >> rpt;
		cin.ignore(); // Limpiar buffer después de leer un carácter
	} while (rpt == 's' || rpt == 'S');
	gotoxy(45, 26); cout << "Presione una tecla para volver al menu de colas...";
	_getch();
}

// Función para recorrer y mostrar toda la cola de empleados
void mostrarColaEmpleados(ColaEmpleado q) {
	TituloVerTrabajadores();

	// Verificar si la cola está vacía
	if (q.delante == nullptr) {
		gotoxy(45, 6); cout << "La cola de empleados está vacía.";
		gotoxy(40, 8); cout << "Presione alguna tecla para volver al menu de colas...";
		_getch();
		return; // Salir de la función si la cola está vacía
	}

	Empleado* aux = q.delante;
	int contador = 0;
	int fila = 6; // Fila inicial para la primera ficha
	int columna = 1; // Columna inicial para la primera ficha

	while (aux) {
		gotoxy(columna, fila); cout << "-----------------------------------------------";
		gotoxy(columna + 10, fila + 1); cout << "ID: " << aux->id;
		gotoxy(columna, fila + 2); cout << "Nombre: " << aux->nombre;
		gotoxy(columna, fila + 3); cout << "Fecha de Nacimiento: " << aux->fechaNacimiento;
		gotoxy(columna, fila + 4); cout << "Genero: " << aux->genero;
		gotoxy(columna, fila + 5); cout << "Cargo: " << aux->cargo;
		gotoxy(columna, fila + 6); cout << "Departamento: " << aux->departamento;
		gotoxy(columna, fila + 7); cout << "Horario: " << aux->horario;
		gotoxy(columna, fila + 8); cout << "Telefono: " << aux->telefono;
		gotoxy(columna, fila + 9); cout << "Direccion: " << aux->direccion;
		gotoxy(columna, fila + 10); cout << "Salario: " << aux->salario;
		gotoxy(columna, fila + 11); cout << "Estado: " << aux->estado;
		gotoxy(columna, fila + 12); cout << "Beneficios: " << aux->beneficios;
		gotoxy(columna, fila + 13); cout << "Fecha de Contratacion: " << aux->fechaContratacion;
		gotoxy(columna, fila + 14); cout << "Direccion del nodo actual: " << aux;
		gotoxy(columna, fila + 15); cout << "Direccion del nodo siguiente: " << aux->sgte;
		gotoxy(columna, fila + 16); cout << "---------------------------------------------";

		contador++;
		if (contador % 2 == 0) {
			fila += 20; // Mover a la siguiente fila después de 2 fichas
			columna = 1; // Reiniciar la columna
		}
		else {
			columna += 50; // Mover a la siguiente columna para la siguiente ficha
		}

		aux = aux->sgte;
	}

	gotoxy(1, fila + 20); // Mover el cursor a la posición final para el mensaje
	cout << "Presione alguna tecla para volver al menu de colas...";
	_getch();
}

//Funcion para buscar un empleado en la cola de empleados y mostrar sus datos
Empleado* buscarEmpleado(ColaEmpleado q, int idEmpleadoBuscado) {
	Empleado* aux = q.delante;
	while (aux) {
		if (aux->id == idEmpleadoBuscado) {
			// Mostrar los datos del empleado encontrado
			gotoxy(35, 8); cout << "---------------------------------------------------";
			gotoxy(45, 9); cout << "ID: " << aux->id;
			gotoxy(40, 10); cout << "Nombre: " << aux->nombre;
			gotoxy(40, 11); cout << "Fecha de Nacimiento: " << aux->fechaNacimiento;
			gotoxy(40, 12); cout << "Genero: " << aux->genero;
			gotoxy(40, 13); cout << "Cargo: " << aux->cargo;
			gotoxy(40, 14); cout << "Departamento: " << aux->departamento;
			gotoxy(40, 15); cout << "Horario: " << aux->horario;
			gotoxy(40, 16); cout << "Telefono: " << aux->telefono;
			gotoxy(40, 17); cout << "Direccion: " << aux->direccion;
			gotoxy(40, 18); cout << "Salario: " << aux->salario;
			gotoxy(40, 19); cout << "Estado: " << aux->estado;
			gotoxy(40, 20); cout << "Beneficios: " << aux->beneficios;
			gotoxy(40, 21); cout << "Fecha de Contratacion: " << aux->fechaContratacion;
			gotoxy(40, 22); cout << "---------------------------------------------------";
			return aux;
			gotoxy(35, 24); cout << "Presione una tecla para volver al menu de cola...";
			_getch();
		}
		aux = aux->sgte;
	}
	gotoxy(40, 8); cout << "Empleado con ID " << idEmpleadoBuscado << " no encontrado.";
	gotoxy(35, 10); cout << "Presione una tecla para volver al menu de cola...";
	_getch();
	return nullptr;
}

//Funcion para eliminar el primer empleado de la cola de empleados y mostrar su informacion
void eliminarEmpleado(ColaEmpleado& q) {
	if (!q.delante) {
		gotoxy(40, 6); cout << "La cola esta vacia, no hay empleados para eliminar.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menu de cola...";
		_getch();
		return;
	}

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

	// Eliminar el primer empleado de la cola
	q.delante = q.delante->sgte;
	if (!q.delante) {
		q.atras = nullptr; // Si la cola queda vacía, actualizar el puntero 'atras'
	}
	delete temp;

	gotoxy(45, 22); cout << "Presione una tecla para volver al menu de cola...";
	_getch();
}

void modificarEmpleado(ColaEmpleado& q, int id) {
	Empleado* emp = buscarEmpleado(q, id);
	if (emp == nullptr) {
		gotoxy(40, 6); cout << "No se encontró ningún empleado con el ID " << id << ".";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menú de empleados...";
		_getch();
		return;
	}

	char respuesta;

	// Modificar nombre
	gotoxy(35, 10); cout << "Modificar nombre (Actual: " << emp->nombre << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 11); cout << "Nuevo nombre: ";
		cin.ignore(); getline(cin, emp->nombre);
	}

	// Modificar fecha de nacimiento
	gotoxy(35, 12); cout << "Modificar fecha de nacimiento (Actual: " << emp->fechaNacimiento << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 13); cout << "Nueva fecha de nacimiento: ";
		cin.ignore(); getline(cin, emp->fechaNacimiento);
	}

	// Modificar género
	gotoxy(35, 14); cout << "Modificar género (Actual: " << emp->genero << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 15); cout << "Nuevo género: ";
		cin.ignore(); getline(cin, emp->genero);
	}

	// Modificar cargo
	gotoxy(35, 16); cout << "Modificar cargo (Actual: " << emp->cargo << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 17); cout << "Nuevo cargo: ";
		cin.ignore(); getline(cin, emp->cargo);
	}

	// Modificar departamento
	gotoxy(35, 18); cout << "Modificar departamento (Actual: " << emp->departamento << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 19); cout << "Nuevo departamento: ";
		cin.ignore(); getline(cin, emp->departamento);
	}

	// Modificar horario
	gotoxy(35, 20); cout << "Modificar horario (Actual: " << emp->horario << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 21); cout << "Nuevo horario: ";
		cin.ignore(); getline(cin, emp->horario);
	}

	// Modificar teléfono
	gotoxy(35, 22); cout << "Modificar teléfono (Actual: " << emp->telefono << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 23); cout << "Nuevo teléfono: ";
		cin.ignore(); getline(cin, emp->telefono);
	}

	// Modificar dirección
	gotoxy(35, 24); cout << "Modificar dirección (Actual: " << emp->direccion << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 25); cout << "Nueva dirección: ";
		cin.ignore(); getline(cin, emp->direccion);
	}

	// Modificar salario
	gotoxy(35, 26); cout << "Modificar salario (Actual: " << emp->salario << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 27); cout << "Nuevo salario: ";
		cin >> emp->salario;
	}

	// Modificar estado
	gotoxy(35, 28); cout << "Modificar estado (Actual: " << emp->estado << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 29); cout << "Nuevo estado: ";
		cin.ignore(); getline(cin, emp->estado);
	}

	// Modificar beneficios
	gotoxy(35, 30); cout << "Modificar beneficios (Actual: " << emp->beneficios << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 31); cout << "Nuevos beneficios: ";
		cin.ignore(); getline(cin, emp->beneficios);
	}

	// Modificar fecha de contratación
	gotoxy(35, 32); cout << "Modificar fecha de contratación (Actual: " << emp->fechaContratacion << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 33); cout << "Nueva fecha de contratación: ";
		cin.ignore(); getline(cin, emp->fechaContratacion);
	}

	// Confirmar cambio y terminar
	gotoxy(40, 35); cout << "Datos del empleado modificados correctamente.";
	gotoxy(40, 37); cout << "Presione una tecla para volver al menú de empleados...";
	_getch();
}

//Funcion para crear nodos (compradores)
Comprador* crearComprador() {
	system("CLS");
	TituloIngresaComprador();
	Comprador* nuevo = new Comprador;
	gotoxy(45, 6); cout << "--------------------------------------------------------";
	gotoxy(45, 7); cout << "Ingrese ID del comprador: "; cin >> nuevo->id;
	cin.ignore();
	gotoxy(45, 8); cout << "Ingrese nombre: "; getline(cin, nuevo->nombre);
	gotoxy(45, 9); cout << "Ingrese telefono: "; getline(cin, nuevo->telefono);
	gotoxy(45, 10); cout << "Ingrese direccion: "; getline(cin, nuevo->direccion);
	gotoxy(45, 11); cout << "Ingrese metodo de pago: "; getline(cin, nuevo->metodoPago);
	gotoxy(45, 12); cout << "Ingrese frecuencia de compra: "; getline(cin, nuevo->frecuenciaCompra);
	gotoxy(45, 13); cout << "Ingrese preferencias: "; getline(cin, nuevo->preferencias);
	gotoxy(45, 14); cout << "Ingrese fecha de registro: "; getline(cin, nuevo->fechaRegistro);
	gotoxy(45, 15); cout << "Ingrese estado de cuenta: "; getline(cin, nuevo->estadoCuenta);
	gotoxy(45, 16); cout << "-----------------------------------------------";
	nuevo->sgte = nullptr;
	return nuevo;
}

//Funcion para agregar nodo (comprador) a la cola de compradores
void encolarComprador(ColaComprador& q2, Comprador* nuevo) {
	if (q2.delante == nullptr) q2.delante = nuevo;
	else q2.atras->sgte = nuevo;
	q2.atras = nuevo;
}

//Funcion para gestionar el ingreso de compradores a la cola de compradores (Si se ingresan mas o ya no)
void gestionarIngresoCompradores(ColaComprador& q2) {
	char rpt;
	do {
		Comprador* nuevo = crearComprador();
		encolarComprador(q2, nuevo);
		gotoxy(45, 22); cout << "Comprador ingresado correctamente a la cola de compradores.";
		gotoxy(45, 24); cout << "¿Desea ingresar otro comprador? (s/n): ";
		cin >> rpt;
		cin.ignore(); // Limpiar buffer después de leer un carácter
	} while (rpt == 's' || rpt == 'S');
	gotoxy(45, 26); cout << "Presione una tecla para volver al menu de colas...";
	_getch();
}

//Funcion para recorrer y mostrar toda la cola de compradores
void mostrarColaCompradores(ColaComprador q2) {
	TituloVerComprador();
	Comprador* aux = q2.delante;
	int contador = 0;
	int fila = 6; // Fila inicial para la primera ficha
	int columna = 1; // Columna inicial para la primera ficha

	while (aux) {
		gotoxy(columna, fila); cout << "-----------------------------------------------";
		gotoxy(columna + 10, fila + 1); cout << "ID: " << aux->id;
		gotoxy(columna, fila + 2); cout << "Nombre: " << aux->nombre;
		gotoxy(columna, fila + 3); cout << "Telefono: " << aux->telefono;
		gotoxy(columna, fila + 4); cout << "Direccion: " << aux->direccion;
		gotoxy(columna, fila + 5); cout << "Metodo de Pago: " << aux->metodoPago;
		gotoxy(columna, fila + 6); cout << "Frecuencia de Compra: " << aux->frecuenciaCompra;
		gotoxy(columna, fila + 7); cout << "Preferencias: " << aux->preferencias;
		gotoxy(columna, fila + 8); cout << "Fecha de Registro: " << aux->fechaRegistro;
		gotoxy(columna, fila + 9); cout << "Estado de Cuenta: " << aux->estadoCuenta;
		gotoxy(columna, fila + 10); cout << "Direccion del nodo actual: " << aux;
		gotoxy(columna, fila + 11); cout << "Direccion del nodo siguiente: " << aux->sgte;
		gotoxy(columna, fila + 12); cout << "---------------------------------------------";

		contador++;
		if (contador % 3 == 0) {
			fila += 18; // Mover a la siguiente fila después de 3 fichas
			columna = 1; // Reiniciar la columna
		}
		else {
			columna += 40; // Mover a la siguiente columna para la siguiente ficha
		}

		aux = aux->sgte;
	}

	gotoxy(1, fila + 18); // Mover el cursor a la posición final para el mensaje
	cout << "Presione alguna tecla para volver al menu de colas...";
	_getch();
}

//Funcion para buscar un comprador en la cola de compradores y mostrar sus datos
Comprador* buscarComprador(ColaComprador q2, int idCompradorBuscado) {
	Comprador* aux = q2.delante;
	while (aux) {
		if (aux->id == idCompradorBuscado) {
			// Mostrar los datos del comprador encontrado
			gotoxy(40, 8); cout << "---------------------------------------------------";
			gotoxy(50, 9); cout << "ID: " << aux->id;
			gotoxy(40, 10); cout << "Nombre: " << aux->nombre;
			gotoxy(40, 11); cout << "Telefono: " << aux->telefono;
			gotoxy(40, 12); cout << "Direccion: " << aux->direccion;
			gotoxy(40, 13); cout << "Metodo de Pago: " << aux->metodoPago;
			gotoxy(40, 14); cout << "Frecuencia de Compra: " << aux->frecuenciaCompra;
			gotoxy(40, 15); cout << "Preferencias: " << aux->preferencias;
			gotoxy(40, 16); cout << "Fecha de Registro: " << aux->fechaRegistro;
			gotoxy(40, 17); cout << "Estado de Cuenta: " << aux->estadoCuenta;
			gotoxy(40, 18); cout << "---------------------------------------------------";
			return aux;
		}
		aux = aux->sgte;
	}
	gotoxy(40, 8); cout << "Comprador con ID " << idCompradorBuscado << " no encontrado.";
	gotoxy(40, 10); cout << "Presione una tecla para volver al menú de compradores...";
	_getch();
	return nullptr;
}

//Funcion para modificar un comprador en la cola de compradores
void modificarComprador(ColaComprador& q2, int idCompradorBuscado) {
	Comprador* comp = buscarComprador(q2, idCompradorBuscado);
	if (comp == nullptr) {
		gotoxy(40, 6); cout << "No se encontró ningún comprador con el ID " << idCompradorBuscado << ".";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menú de compradores...";
		_getch();
		return;
	}

	char respuesta;

	// Modificar nombre
	gotoxy(35, 10); cout << "Modificar nombre (Actual: " << comp->nombre << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 11); cout << "Nuevo nombre: ";
		cin.ignore(); getline(cin, comp->nombre);
	}

	// Modificar teléfono
	gotoxy(35, 12); cout << "Modificar teléfono (Actual: " << comp->telefono << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 13); cout << "Nuevo teléfono: ";
		cin.ignore(); getline(cin, comp->telefono);
	}

	// Modificar dirección
	gotoxy(35, 14); cout << "Modificar dirección (Actual: " << comp->direccion << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 15); cout << "Nueva dirección: ";
		cin.ignore(); getline(cin, comp->direccion);
	}

	// Modificar método de pago
	gotoxy(35, 16); cout << "Modificar método de pago (Actual: " << comp->metodoPago << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 17); cout << "Nuevo método de pago: ";
		cin.ignore(); getline(cin, comp->metodoPago);
	}

	// Modificar frecuencia de compra
	gotoxy(35, 18); cout << "Modificar frecuencia de compra (Actual: " << comp->frecuenciaCompra << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 19); cout << "Nueva frecuencia de compra: ";
		cin.ignore(); getline(cin, comp->frecuenciaCompra);
	}

	// Modificar preferencias
	gotoxy(35, 20); cout << "Modificar preferencias (Actual: " << comp->preferencias << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 21); cout << "Nuevas preferencias: ";
		cin.ignore(); getline(cin, comp->preferencias);
	}

	// Modificar fecha de registro
	gotoxy(35, 22); cout << "Modificar fecha de registro (Actual: " << comp->fechaRegistro << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 23); cout << "Nueva fecha de registro: ";
		cin.ignore(); getline(cin, comp->fechaRegistro);
	}

	// Modificar estado de cuenta
	gotoxy(35, 24); cout << "Modificar estado de cuenta (Actual: " << comp->estadoCuenta << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 25); cout << "Nuevo estado de cuenta: ";
		cin.ignore(); getline(cin, comp->estadoCuenta);
	}

	// Confirmar cambio y terminar
	gotoxy(40, 27); cout << "Datos del comprador modificados correctamente.";
	gotoxy(40, 29); cout << "Presione una tecla para volver al menú de compradores...";
	_getch();
}

//Funcion para eliminar el primer comprador de la cola de compradores y mostrar su informacion
void eliminarComprador(ColaComprador& q2) {
	if (!q2.delante) {
		gotoxy(40, 6); cout << "La cola esta vacia, no hay compradores para eliminar.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menu de cola...";
		_getch();
		return;
	}

	Comprador* temp = q2.delante;
	// Mostrar la información del comprador que se va a eliminar
	gotoxy(40, 6); cout << "---------------------------------------------------";
	gotoxy(50, 7); cout << "ID: " << temp->id;
	gotoxy(40, 8); cout << "Nombre: " << temp->nombre;
	gotoxy(40, 9); cout << "Telefono: " << temp->telefono;
	gotoxy(40, 10); cout << "Direccion: " << temp->direccion;
	gotoxy(40, 11); cout << "Metodo de Pago: " << temp->metodoPago;
	gotoxy(40, 12); cout << "Frecuencia de Compra: " << temp->frecuenciaCompra;
	gotoxy(40, 13); cout << "Preferencias: " << temp->preferencias;
	gotoxy(40, 14); cout << "Fecha de Registro: " << temp->fechaRegistro;
	gotoxy(40, 15); cout << "Estado de Cuenta: " << temp->estadoCuenta;
	gotoxy(40, 16); cout << "---------------------------------------------------";

	// Eliminar el primer comprador de la cola
	q2.delante = q2.delante->sgte;
	if (!q2.delante) {
		q2.atras = nullptr; // Si la cola queda vacía, actualizar el puntero 'atras'
	}
	delete temp;

	gotoxy(45, 18); cout << "Presione una tecla para volver al menu de cola...";
	_getch();
}

//Funcion para crear nodos (proveedores)
Proovedor* crearProovedor() {
	system("CLS");
	TituloIngresaProveedor();
	Proovedor* nuevo = new Proovedor;
	gotoxy(45, 6); cout << "--------------------------------------------------------";
	gotoxy(45, 7); cout << "Ingrese ID del proovedor: "; cin >> nuevo->id;
	cin.ignore();
	gotoxy(45, 8); cout << "Ingrese nombre: "; getline(cin, nuevo->nombre);
	gotoxy(45, 9); cout << "Ingrese telefono: "; getline(cin, nuevo->telefono);
	gotoxy(45, 10); cout << "Ingrese direccion: "; getline(cin, nuevo->direccion);
	gotoxy(45, 11); cout << "Ingrese empresa: "; getline(cin, nuevo->empresa);
	gotoxy(45, 12); cout << "Ingrese productos: "; getline(cin, nuevo->productos);
	gotoxy(45, 13); cout << "Ingrese fecha de registro: "; getline(cin, nuevo->fechaRegistro);
	gotoxy(45, 14); cout << "Ingrese estado de cuenta: "; getline(cin, nuevo->estadoCuenta);
	gotoxy(45, 15); cout << "--------------------------------------------------------";
	nuevo->sgte = nullptr;
	return nuevo;
}

//Funcion para agregar nodo (proveedor) a la cola de proveedores
void encolarProovedor(ColaProovedor& q3, Proovedor* nuevo) {
	if (q3.delante == nullptr) q3.delante = nuevo;
	else q3.atras->sgte = nuevo;
	q3.atras = nuevo;
}

//Funcion para gestionar el ingreso de proveedores a la cola de proveedores
void gestionarIngresoProveedores(ColaProovedor& q3) {
	char rpt;
	do {
		Proovedor* nuevo = crearProovedor();
		encolarProovedor(q3, nuevo);
		gotoxy(45, 22); cout << "Proveedor ingresado correctamente a la cola de proveedores.";
		gotoxy(45, 24); cout << "¿Desea ingresar otro proveedor? (s/n): ";
		cin >> rpt;
		cin.ignore(); // Limpiar buffer después de leer un carácter
	} while (rpt == 's' || rpt == 'S');
	gotoxy(45, 26); cout << "Presione una tecla para volver al menu de colas...";
	_getch();
}

//Funcion para recorrer y mostrar toda la cola de proveedores
void mostrarColaProveedores(ColaProovedor q3) {
	TituloVerProveedor();
	Proovedor* aux = q3.delante;
	int contador = 0;
	int fila = 6; // Fila inicial para la primera ficha
	int columna = 1; // Columna inicial para la primera ficha

	while (aux) {
		gotoxy(columna, fila); cout << "-----------------------------------------------";
		gotoxy(columna + 10, fila + 1); cout << "ID: " << aux->id;
		gotoxy(columna, fila + 2); cout << "Nombre: " << aux->nombre;
		gotoxy(columna, fila + 3); cout << "Telefono: " << aux->telefono;
		gotoxy(columna, fila + 4); cout << "Direccion: " << aux->direccion;
		gotoxy(columna, fila + 5); cout << "Empresa: " << aux->empresa;
		gotoxy(columna, fila + 6); cout << "Productos: " << aux->productos;
		gotoxy(columna, fila + 7); cout << "Fecha de Registro: " << aux->fechaRegistro;
		gotoxy(columna, fila + 8); cout << "Estado de Cuenta: " << aux->estadoCuenta;
		gotoxy(columna, fila + 9); cout << "Direccion del nodo actual: " << aux;
		gotoxy(columna, fila + 10); cout << "Direccion del nodo siguiente: " << aux->sgte;
		gotoxy(columna, fila + 11); cout << "---------------------------------------------";

		contador++;
		if (contador % 3 == 0) {
			fila += 18; // Mover a la siguiente fila después de 3 fichas
			columna = 1; // Reiniciar la columna
		}
		else {
			columna += 40; // Mover a la siguiente columna para la siguiente ficha
		}

		aux = aux->sgte;
	}

	gotoxy(1, fila + 18); // Mover el cursor a la posición final para el mensaje
	cout << "Presione alguna tecla para volver al menu de colas...";
	_getch();
}

//Funcion para buscar un proveedor en la cola de proveedores y mostrar sus datos
Proovedor* buscarProovedor(ColaProovedor q3, int idProveedorBuscado) {
	Proovedor* aux = q3.delante;
	while (aux) {
		if (aux->id == idProveedorBuscado) {
			// Mostrar los datos del proveedor encontrado
			gotoxy(40, 8); cout << "---------------------------------------------------";
			gotoxy(50, 9); cout << "ID: " << aux->id;
			gotoxy(40, 10); cout << "Nombre: " << aux->nombre;
			gotoxy(40, 11); cout << "Telefono: " << aux->telefono;
			gotoxy(40, 12); cout << "Direccion: " << aux->direccion;
			gotoxy(40, 13); cout << "Empresa: " << aux->empresa;
			gotoxy(40, 14); cout << "Productos: " << aux->productos;
			gotoxy(40, 15); cout << "Fecha de Registro: " << aux->fechaRegistro;
			gotoxy(40, 16); cout << "Estado de Cuenta: " << aux->estadoCuenta;
			gotoxy(40, 17); cout << "---------------------------------------------------";
			return aux;
		}
		aux = aux->sgte;
	}
	gotoxy(40, 8); cout << "Proveedor con ID " << idProveedorBuscado << " no encontrado.";
	return nullptr;
}

//Funcion para modificar un proveedor en la cola de proveedores
void modificarProovedor(ColaProovedor& q3, int idProveedorBuscado) {
	Proovedor* prov = buscarProovedor(q3, idProveedorBuscado);
	if (prov == nullptr) {
		gotoxy(40, 6); cout << "No se encontró ningún proveedor con el ID " << idProveedorBuscado << ".";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menú de proveedores...";
		_getch();
		return;
	}

	char respuesta;

	// Modificar nombre
	gotoxy(35, 10); cout << "Modificar nombre (Actual: " << prov->nombre << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 11); cout << "Nuevo nombre: ";
		cin.ignore(); getline(cin, prov->nombre);
	}

	// Modificar teléfono
	gotoxy(35, 12); cout << "Modificar teléfono (Actual: " << prov->telefono << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 13); cout << "Nuevo teléfono: ";
		cin.ignore(); getline(cin, prov->telefono);
	}

	// Modificar dirección
	gotoxy(35, 14); cout << "Modificar dirección (Actual: " << prov->direccion << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 15); cout << "Nueva dirección: ";
		cin.ignore(); getline(cin, prov->direccion);
	}

	// Modificar empresa
	gotoxy(35, 16); cout << "Modificar empresa (Actual: " << prov->empresa << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 17); cout << "Nueva empresa: ";
		cin.ignore(); getline(cin, prov->empresa);
	}

	// Modificar productos
	gotoxy(35, 18); cout << "Modificar productos (Actual: " << prov->productos << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 19); cout << "Nuevos productos: ";
		cin.ignore(); getline(cin, prov->productos);
	}

	// Modificar fecha de registro
	gotoxy(35, 20); cout << "Modificar fecha de registro (Actual: " << prov->fechaRegistro << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 21); cout << "Nueva fecha de registro: ";
		cin.ignore(); getline(cin, prov->fechaRegistro);
	}

	// Modificar estado de cuenta
	gotoxy(35, 22); cout << "Modificar estado de cuenta (Actual: " << prov->estadoCuenta << ")? (S/N): ";
	cin >> respuesta;
	if (respuesta == 'S' || respuesta == 's') {
		gotoxy(35, 23); cout << "Nuevo estado de cuenta: ";
		cin.ignore(); getline(cin, prov->estadoCuenta);
	}

	// Confirmar cambio y terminar
	gotoxy(40, 25); cout << "Datos del proveedor modificados correctamente.";
	gotoxy(40, 27); cout << "Presione una tecla para volver al menú de proveedores...";
	_getch();
}

//Funcion para eliminar el primer proveedor de la cola de proveedores y mostrar su informacion
void eliminarProovedor(ColaProovedor& q3) {
	if (!q3.delante) {
		gotoxy(40, 6); cout << "La cola esta vacia, no hay proveedores para eliminar.";
		gotoxy(40, 8); cout << "Presione una tecla para volver al menu de cola...";
		_getch();
		return;
	}

	Proovedor* temp = q3.delante;
	// Mostrar la información del proveedor que se va a eliminar
	gotoxy(40, 6); cout << "---------------------------------------------------";
	gotoxy(50, 7); cout << "ID: " << temp->id;
	gotoxy(40, 8); cout << "Nombre: " << temp->nombre;
	gotoxy(40, 9); cout << "Telefono: " << temp->telefono;
	gotoxy(40, 10); cout << "Direccion: " << temp->direccion;
	gotoxy(40, 11); cout << "Empresa: " << temp->empresa;
	gotoxy(40, 12); cout << "Productos: " << temp->productos;
	gotoxy(40, 13); cout << "Fecha de Registro: " << temp->fechaRegistro;
	gotoxy(40, 14); cout << "Estado de Cuenta: " << temp->estadoCuenta;
	gotoxy(40, 15); cout << "---------------------------------------------------";

	// Eliminar el primer proveedor de la cola
	q3.delante = q3.delante->sgte;
	if (!q3.delante) {
		q3.atras = nullptr; // Si la cola queda vacía, actualizar el puntero 'atras'
	}
	delete temp;

	gotoxy(45, 17); cout << "Presione una tecla para volver al menu de cola...";
	_getch();
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
	gotoxy(50, 0); cout << "***************************************";
	gotoxy(50, 1); cout << "**                                   **";
	gotoxy(50, 2); cout << "**     Buscando cerdo de la pila     **";
	gotoxy(59, 3); cout << "**                                   **";
	gotoxy(50, 4); cout << "***************************************";
}

void TituloModificarCerdo() {
	gotoxy(40, 0); cout << "***********************************************";
	gotoxy(40, 1); cout << "**                                           **";
	gotoxy(40, 2); cout << "**     Modificando informacion del cerdo     **";
	gotoxy(40, 3); cout << "**                                           **";
	gotoxy(40, 4); cout << "***********************************************";
}

void TituloEliminarCerdo() {
	gotoxy(50, 0); cout << "*****************************************";
	gotoxy(50, 1); cout << "**                                     **";
	gotoxy(50, 2); cout << "**     Eliminando cerdo de la pila     **";
	gotoxy(50, 3); cout << "**                                     **";
	gotoxy(50, 4); cout << "*****************************************";
}

void TituloIngresaTrabajador() {
	gotoxy(35, 0); cout << "*************************************************************";
	gotoxy(35, 1); cout << "**                                                         **";
	gotoxy(35, 2); cout << "**     Ingresando trabajador a la cola de trabajadores     **";
	gotoxy(35, 3); cout << "**                                                         **";
	gotoxy(35, 4); cout << "*************************************************************";
}

void TituloIngresaProveedor() {
	gotoxy(35, 0); cout << "***********************************************************";
	gotoxy(35, 1); cout << "**                                                       **";
	gotoxy(35, 2); cout << "**     Ingresando proveedor a la cola de proveedores     **";
	gotoxy(35, 3); cout << "**                                                       **";
	gotoxy(35, 4); cout << "***********************************************************";
}

void TituloIngresaComprador() {
	gotoxy(35, 0); cout << "***********************************************************";
	gotoxy(35, 1); cout << "**                                                       **";
	gotoxy(35, 2); cout << "**     Ingresando comprador a la cola de compradores     **";
	gotoxy(35, 3); cout << "**                                                       **";
	gotoxy(35, 4); cout << "***********************************************************";
}

void TituloVerTrabajadores() {
	gotoxy(45, 0); cout << "********************************************";
	gotoxy(45, 1); cout << "**                                        **";
	gotoxy(45, 2); cout << "**     Viendo la cola de trabajadores     **";
	gotoxy(45, 3); cout << "**                                        **";
	gotoxy(45, 4); cout << "********************************************";
}

void TituloVerProveedor() {
	gotoxy(45, 0); cout << "*******************************************";
	gotoxy(45, 1); cout << "**                                       **";
	gotoxy(45, 2); cout << "**     Viendo la cola de proveedores     **";
	gotoxy(45, 3); cout << "**                                       **";
	gotoxy(45, 4); cout << "*******************************************";
}

void TituloVerComprador() {
	gotoxy(45, 0); cout << "*******************************************";
	gotoxy(45, 1); cout << "**                                       **";
	gotoxy(45, 2); cout << "**     Viendo la cola de compradores     **";
	gotoxy(45, 3); cout << "**                                       **";
	gotoxy(45, 4); cout << "*******************************************";
}

void TituloBuscarTrabajador() {
	gotoxy(45, 0); cout << "********************************************";
	gotoxy(45, 1); cout << "**                                        **";
	gotoxy(45, 2); cout << "**     Buscando trabajador en la cola     **";
	gotoxy(45, 3); cout << "**                                        **";
	gotoxy(45, 4); cout << "********************************************";
}

void TituloBuscarProveedor() {
	gotoxy(45, 0); cout << "*******************************************";
	gotoxy(45, 1); cout << "**                                       **";
	gotoxy(45, 2); cout << "**     Buscando proveedor en la cola     **";
	gotoxy(45, 3); cout << "**                                       **";
	gotoxy(45, 4); cout << "*******************************************";
}

void TituloBuscarComprador() {
	gotoxy(45, 0); cout << "*******************************************";
	gotoxy(45, 1); cout << "**                                       **";
	gotoxy(45, 2); cout << "**     Buscando comprador en la cola     **";
	gotoxy(45, 3); cout << "**                                       **";
	gotoxy(45, 4); cout << "*******************************************";
}

void TituloModificarTrabajador() {
	gotoxy(50, 0); cout << "************************************";
	gotoxy(50, 1); cout << "**                                **";
	gotoxy(50, 2); cout << "**     Modificando trabajador     **";
	gotoxy(50, 3); cout << "**                                **";
	gotoxy(50, 4); cout << "************************************";
}

void TituloModificarProveedor() {
	gotoxy(50, 0); cout << "***********************************";
	gotoxy(50, 1); cout << "**                               **";
	gotoxy(50, 2); cout << "**     Modificando proveedor     **";
	gotoxy(50, 3); cout << "**                               **";
	gotoxy(50, 4); cout << "***********************************";
}

void TituloModificarComprador() {
	gotoxy(50, 0); cout << "***********************************";
	gotoxy(50, 1); cout << "**                               **";
	gotoxy(50, 2); cout << "**     Modificando comprador     **";
	gotoxy(50, 3); cout << "**                               **";
	gotoxy(50, 4); cout << "***********************************";
}

void TituloEliminaTrabajador() {
	gotoxy(45, 0); cout << "**********************************************";
	gotoxy(45, 1); cout << "**                                          **";
	gotoxy(45, 2); cout << "**     Eliminando trabajador de la cola     **";
	gotoxy(45, 3); cout << "**                                          **";
	gotoxy(45, 4); cout << "**********************************************";
}

void TituloEliminaProveedor() {
	gotoxy(45, 0); cout << "*********************************************";
	gotoxy(45, 1); cout << "**                                         **";
	gotoxy(45, 2); cout << "**     Eliminando proveedor de la cola     **";
	gotoxy(45, 3); cout << "**                                         **";
	gotoxy(45, 4); cout << "*********************************************";
}

void TituloEliminaComprador() {
	gotoxy(45, 0); cout << "*********************************************";
	gotoxy(45, 1); cout << "**                                         **";
	gotoxy(45, 2); cout << "**     Eliminando comprador de la cola     **";
	gotoxy(45, 3); cout << "**                                         **";
	gotoxy(45, 4); cout << "*********************************************";
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
