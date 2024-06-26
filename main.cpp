#include <iostream> 
#include <stdio.h> // permite todo lo relacionado con entrada y salida 
#include <stdlib.h> //libreria standar
 #include <conio.h> //entrada y salida por consola
  #include <string> 
  using namespace std; 
  int main()
   {  
  
   //leer variables
      int cedula;
	  char nombreEmpleado[50]; 
	  char tipoEmpleado;   
	  int cantidadHoras=0;   
	  int precioHora=0;   
	  char opcion;   
	  
	  //variables proceso   
	  int salarioOrdinario;   
	  int salarioBruto;   
	  int deduccionCCSS;   
	  int aumento;   
	  int salarioNeto;   
	  int cantidadtrabajadores[3]={0};   
	  int acumuladosalarios[3]={0};   
	  int cantidadOperarios;   
	  double acumuladoOperarios;   
	  int cantidadTecnicos;   
	  double acumuladoTecnicos;   
	  int cantidadProfesionales;   
	  double acumuladoProfesionales;   
	  do
	  {   
	  //pedir informacion <<<<<   
	  cout << "Bienvenido señor/a usuario"<< endl;   
	  cout << "Digite su nombre"<< endl;   
	  cin >> nombreEmpleado;   
	  cout <<"Digite su numero de cedula"<<endl;   
	  cin>> cedula;   
	  cout <<"Digite la cantidad de horas laboradas"<<endl;   
	  cin>> cantidadHoras;   
	  cout<< "Digite el valor del precio por hora"<< endl;   
	  cin>> precioHora;   
	  cout << "Porfavor digite que tipo de empleado es."<< endl;   
	  cout << "1, 2 o 3"<< endl;   
	  cout << "1= Operario, 2= Tecnico y 3= Profesional"<< endl;   
	  cin >> tipoEmpleado;   
	  if (tipoEmpleado==1) 
	  {   
	  salarioOrdinario= cantidadHoras* precioHora;   
	  aumento = salarioOrdinario * 0.15;   
	  cantidadtrabajadores[0]++;   
	  acumuladoOperarios += salarioOrdinario;   
	  salarioBruto= salarioOrdinario + aumento;   
	  deduccionCCSS= 0.0917 * salarioBruto;   
	  salarioNeto= salarioBruto - deduccionCCSS;   
	  acumuladosalarios[0] += salarioNeto; 
	  cout <<"Su nombre es: "<< nombreEmpleado<<endl; 
	  cout << "Su numero de cedula es: "<< cedula<<endl; 
	  cout << "El tipo de empleado al que pertenece es: "<< tipoEmpleado<< endl; 
	  cout << "Su precio por hora es: "<< precioHora<< endl; 
	  cout <<"La cantidad de horas laboradas es: "<< cantidadHoras<< endl; 
	  cout << "Su salario Ordinario es: "<< salarioOrdinario<< endl; 
	  cout << "Su aumento es de: "<< aumento<< endl; 
	  cout << "Su salario bruto es de: "<< salarioBruto<< endl; 
	  cout << "La deduccion de CCSS es de: "<< deduccionCCSS<< endl; 
	  cout <<"Su salario neto es de: "<< salarioNeto<< endl; 
	  cout << "Desea ingresar otro empleado? (s/n): "<< endl; 
	  cin >> opcion;   
	  }   
	  if (tipoEmpleado==2) 
	    {   salarioOrdinario= cantidadHoras* precioHora;   
		aumento= salarioOrdinario * 0.10;   cantidadTecnicos++; 
		 cantidadtrabajadores[1]++;   
	  acumuladoOperarios += salarioOrdinario; 
		salarioBruto= salarioOrdinario + aumento;   
		deduccionCCSS= 0.0917 * salarioBruto;   
		salarioNeto= salarioBruto - deduccionCCSS;  
		 acumuladosalarios[1] += salarioNeto;
		cout <<"Su nombre es: "<< nombreEmpleado<<endl; 
		cout << "Su numero de cedula es: "<< cedula<<endl; 
		cout << "El tipo de empleado al que pertenece es: "<< tipoEmpleado<< endl; 
		cout << "Su precio por hora es: "<< precioHora<< endl; 
		cout <<"La cantidad de horas laboradas es: "<< cantidadHoras<< endl; 
		cout << "Su salario Ordinario es: "<< salarioOrdinario<< endl; 
		cout << "Su aumento es de: "<< aumento<< endl; 
		cout << "Su salario bruto es de: "<< salarioBruto<< endl; 
		cout << "La deduccion de CCSS es de: "<< deduccionCCSS<< endl; 
		cout <<"Su salario neto es de: "<< salarioNeto<< endl; 
		cout << "Desea ingresar otro empleado? (s/n): "<< endl; 
		cin >> opcion;  
    }  
	 if (tipoEmpleado==3)  
	{   
	salarioOrdinario= cantidadHoras* precioHora;   
	aumento = salarioOrdinario + 0.05; 
	cantidadtrabajadores[2]++;   
	acumuladoOperarios += salarioOrdinario;
	cantidadProfesionales++;   
	salarioBruto = salarioOrdinario + aumento;   
	deduccionCCSS = 0.0917 * salarioBruto;  
	salarioNeto = salarioBruto - deduccionCCSS;
	acumuladosalarios[2] += salarioNeto;   
	cout <<"Su nombre es: "<< nombreEmpleado<<endl; 
	cout << "Su numero de cedula es: "<< cedula<<endl; 
	cout << "El tipo de empleado al que pertenece es: "<< tipoEmpleado<< endl; 
	cout << "Su precio por hora es: "<< precioHora<< endl; 
	cout << "La cantidad de horas laboradas es: "<< cantidadHoras<< endl; 
	cout << "Su salario Ordinario es: "<< salarioOrdinario<< endl; 
	cout << "Su aumento es de: "<< aumento<< endl; 
	cout << "Su salario bruto es de: "<< salarioBruto<< endl; 
	cout << "La deduccion de CCSS es de: "<< deduccionCCSS<< endl; 
	cout << "Su salario neto es de: "<< salarioNeto<< endl; 
	cout << "Desea ingresar otro empleado? (s/n): "<< endl; 
	cin >> opcion; 
	}
	 } while (opcion == 's' || opcion == 'S'); 
	 
	 cout << "\nEstadisticas :\n"; 
	 cout << "\n Cantidad operarios :\n" << cantidadtrabajadores[0] << endl; 
	 cout << "\n Acumulado salario operarios :\n"<< acumuladosalarios[0] << endl; 
	 cout << "\n Cantidad Tecnicos :\n" <<cantidadtrabajadores[1] << endl ; 
	 cout << "\n Acumulado Salario Tecnicos :\n"<< acumuladosalarios[1] << endl; 
	 cout << "\n Cantidad Profesionales :\n" <<cantidadtrabajadores[2] << endl; 
	 cout << "\n Acumulado Salario Profesional :\n"<< acumuladosalarios[2] << endl; 
	

return 0;
 }







































