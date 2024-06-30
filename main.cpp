#include <iostream> 
#include <stdio.h> // permite todo lo relacionado con entrada y salida 
#include <stdlib.h> //libreria standar
 #include <conio.h> //entrada y salida por consola
  #include <string> 
  using namespace std; 
  void agregar();
  void estadisticas();
  void consultar();
  void borrar();
   int opcion=0;
    int contadorEmpleados = 0;
   char agregarEmpleado[50];
   char borrarEmpleado[50];  
   char consultarEmpleado[50];
   char modificarEmpleado[50];
   char salir[20];
     //Variables para usar en switch y para pedir informacion del empleado
     struct Empleado{
	  Empleado empleados[100];
      int cedula;
	  char nombreEmpleado[50]; 
	  char tipoEmpleado;   
	  int cantidadHoras=0;   
	  int precioHora=0; 
	   int salarioOrdinario;   
	  int salarioBruto;   
	  int deduccionCCSS;   
	  int aumento;   
	  int salarioNeto;   
	  
}
	  //leer variables
     
	    
	  
	  //variables proceso  
	  int cantidadtrabajadores[3]={0};   
	  int acumuladosalarios[3]={0};   
	  int cantidadOperarios;   
	  double acumuladoOperarios;   
	  int cantidadTecnicos;   
	  double acumuladoTecnicos;   
	  int cantidadProfesionales;   
	  double acumuladoProfesionales; 

	 
	  


  void menu() {
  	do
	  {
  		cout<< "1- Agregar empleado"<<endl;
  		cout<< "2- Estadisticas"<< endl;
  		cout<< "3- Consultar empleado"<<endl;
  		cout<< "4- Modificar empleado"<<endl;
  		cout<< "5- Salir"<<endl;
  		cout<<" Digite una opcion"<<endl;
  		cin>>opcion;
  		
  		switch (opcion)
		  {
		     case 1: agregar();
                break;
            case 2:estadisticas();
                break;
            case 3: consultar();
                break;
            case 4: borrar();
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;	
	
		}          
        }while (opcion != 5);
  		
  		
  		
  		
  		
  		
  		
	  }
  	
  	
  	void agregar() {
    char nombreEmpleado[50];
    int cedula;
    int cantidadHoras;
    int precioHora;
    char tipoEmpleado;
    char opcion;

    do {
        cout << "Bienvenido señor/a usuario" << endl;
        cout << "Digite su nombre: ";
        cin >> nombreEmpleado;
        cout << "Digite su numero de cedula: ";
        cin >> cedula;
        cout << "Digite la cantidad de horas laboradas: ";
        cin >> cantidadHoras;
        cout << "Digite el valor del precio por hora: ";
        cin >> precioHora;
        cout << "Digite el tipo de empleado (1=Operario, 2=Tecnico, 3=Profesional): ";
        cin >> tipoEmpleado;

        int salarioOrdinario = 0;
        int aumento = 0;
        int salarioBruto = 0;
        int deduccionCCSS = 0;
        int salarioNeto = 0;

        switch (tipoEmpleado) {
            case '1':
                salarioOrdinario = cantidadHoras * precioHora;
                aumento = salarioOrdinario * 0.15;
                cantidadtrabajadores[0]++;
                acumuladosalarios[0] += salarioOrdinario;
                break;
            case '2':
                salarioOrdinario = cantidadHoras * precioHora;
                aumento = salarioOrdinario * 0.10;
                cantidadtrabajadores[1]++;
                acumuladosalarios[1] += salarioOrdinario;
                break;
            case '3':
                salarioOrdinario = cantidadHoras * precioHora;
                aumento = salarioOrdinario * 0.05;
                cantidadtrabajadores[2]++;
                acumuladosalarios[2] += salarioOrdinario;
                break;
            default:
                cout << "Tipo de empleado no valido." << endl;
                continue; 
        }

        salarioBruto = salarioOrdinario + aumento;
        deduccionCCSS = 0.0917 * salarioBruto;
        salarioNeto = salarioBruto - deduccionCCSS;

        cout << "\nInformacion del empleado agregado:\n";
        cout << "Nombre: " << nombreEmpleado << endl;
        cout << "Cedula: " << cedula << endl;
        cout << "Tipo de empleado: " << tipoEmpleado << endl;
        cout << "Precio por hora: " << precioHora << endl;
        cout << "Horas laboradas: " << cantidadHoras << endl;
        cout << "Salario Ordinario: " << salarioOrdinario << endl;
        cout << "Aumento: " << aumento << endl;
        cout << "Salario Bruto: " << salarioBruto << endl;
        cout << "Deduccion CCSS: " << deduccionCCSS << endl;
        cout << "Salario Neto: " << salarioNeto << endl;

        cout << "\nDesea ingresar otro empleado? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
    menu();
    
}
    
  
  void consultar(Empleado empleados[], int contadorEmpleados) {
  
    // Función para consultar un empleado por su nombre o cédula
    char opcionConsulta;
    cout << "Consultar empleado por (n)ombre o (c)edula: ";
    cin >> opcionConsulta;

    if (opcionConsulta == 'n' || opcionConsulta == 'N') {
        char nombreBuscar[50];
        cout << "Ingrese el nombre del empleado a buscar: ";
        cin >> nombreBuscar;

        // Buscar por nombre
        for (int i = 0; i < contadorEmpleados; ++i) {
            if (strcmp(empleados[i].nombreEmpleado, nombreBuscar) == 0) {
                // Mostrar información del empleado encontrado
                cout << "Empleado encontrado:\n";
                cout << "Nombre: " << empleados[i].nombreEmpleado << endl;
                cout << "Cedula: " << empleados[i].cedula << endl;
                cout << "Tipo: " << empleados[i].tipoEmpleado << endl;
                cout << "Salario Neto: " << empleados[i].salarioNeto << endl;
                return; // Termina la función después de encontrar y mostrar el empleado
            }
        }
        // Si no se encontró ningún empleado con el nombre dado
        cout << "No se encontró ningún empleado con el nombre ingresado." << endl;
    } else if (opcionConsulta == 'c' || opcionConsulta == 'C') {
        int cedulaBuscar;
        cout << "Ingrese la cedula del empleado a buscar: ";
        cin >> cedulaBuscar;

        // Buscar por cédula
        for (int i = 0; i < contadorEmpleados; ++i) {
            if (empleados[i].cedula == cedulaBuscar) {
                // Mostrar información del empleado encontrado
                cout << "Empleado encontrado:\n";
                cout << "Nombre: " << empleados[i].nombreEmpleado << endl;
                cout << "Cedula: " << empleados[i].cedula << endl;
                cout << "Tipo: " << empleados[i].tipo << endl;
                cout << "Salario Neto: " << empleados[i].salarioNeto << endl;
                return; // Termina la función después de encontrar y mostrar el empleado
            }
        }
        // Si no se encontró ningún empleado con la cédula dada
        cout << "No se encontró ningún empleado con la cedula ingresada." << endl;
    } else {
        cout << "Opción de consulta no válida." << endl;
    }
}
  	
  	
  		


// Función para borrar datos de un empleado
void borrarDatos(int posicion) {
    // Verificar si la posición está dentro del rango válido del arreglo
    if (posicion < 0 || posicion >= 100) {
        cout << "Posicion invalida. La posicion debe estar entre 0 y 99." << endl;
        return;
    }

    // Reiniciar los datos del empleado en la posición especificada
    strcpy(empleados[posicion].nombreEmpleado, "");
    empleados[posicion].cedula = 0;
    empleados[posicion].tipoEmpleado = ' ';  // Se puede reiniciar con un valor adecuado según tu diseño
    empleados[posicion].cantidadHoras = 0;
    empleados[posicion].precioHora = 0;
    // Otros campos que necesiten ser reiniciados

    cout << "Datos del empleado en la posicion " << posicion << " borrados correctamente." << endl;
}
  		
	  
  	
  
   void estadisticas(){
	
	 cout << "\nEstadisticas :\n"; 
	 cout << "\n Cantidad operarios :\n" << cantidadtrabajadores[0] << endl; 
	 cout << "\n Acumulado salario operarios :\n"<< acumuladosalarios[0] << endl; 
	 cout << "\n Cantidad Tecnicos :\n" <<cantidadtrabajadores[1] << endl ; 
	 cout << "\n Acumulado Salario Tecnicos :\n"<< acumuladosalarios[1] << endl; 
	 cout << "\n Cantidad Profesionales :\n" <<cantidadtrabajadores[2] << endl; 
	 cout << "\n Acumulado Salario Profesional :\n"<< acumuladosalarios[2] << endl; 
	}
  
  int main()
   {  
  menu();
  estadisticas();
  consultar();
  borrar();

return 0;
 }

