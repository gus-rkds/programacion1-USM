/*Programa que simula una maquina tragamonedas de un casino

Elaborado por: Carlos Ferrer

Fecha: 12 de mayo 2023

Catedra Programación

*/

#include<conio.h>

#include<time.h>

/*Para manejar el tiempo del sistema en particular

el reloj del sistema*/

#include<iostream> //Se utilizara para salida de datos a la consola
#include<windows.h>

/* Permite la creación de números aleatorios

los sonidos Beep y las pausas de ejecución Sleep*/

using namespace std;

main()

{

int primer_digito,segundo_digito,tercer_digito,cuarto_digito;

// valores de la tabla ascii de los caracteres a presentar en pantalla

int intentos;

// Contador de intentos del jugador (se dejara ganar en 3)

char s1,s2,s3,s4; //Caracteres para presentar en pantalla

int monto=200;

int apuesta=1;

int tiempo; //tiempo de refrescamiento de pantalla

string codigo;

char cambio,seguir; 

	Beep(150,250);Beep(150,250);

	cout <<"               **** ACIERTE LOS 4 SIMBOLOS IGUALES **** "<<endl<<endl;

    cout <<"La apuesta inicial es de 1$ - Usted puede aumentar la apuesta cuando arranque el juego"<<endl;

    cout <<"Usted gana si logra detener el juego cuando los 4 simbolos son iguales [#][$][%][&]"<<endl;

	cout <<"Cada triunfo le acredita 100$ x dolar apostado"<<endl<<endl;

    system ("pause");

    system ("cls");

while (codigo!="A19B" and codigo!="a19b" and codigo!="a19B" and codigo!="A19b" )

 {

  cout <<"Ingrese el codigo suministrado en caja (a19b)= ";

  cin >>codigo;

  if (codigo!="A19B" and codigo!="a19b" and codigo!="a19B" and codigo!="A19b" )

  	{

	cout <<"El codigo ingresado es invalido!!"<<endl;

	Beep(150,250);Beep(150,250);

	Sleep (500);

	system ("cls");

	}

}

    cout <<"Codigo ingresado valido por "<<monto<<"$"<<endl;

    Sleep(1000);

    Beep(250,250);

    Beep(250,250);

    system ("cls");

         inicio:

    srand(time(NULL));

         tiempo=150;

         intentos=intentos+1;

         while(tiempo>1)

                   {

                   // determinamos el valor ascii de cada carácter

                   primer_digito=rand()%(10);

		    segundo_digito=rand()%(10);

		    tercer_digito=rand()%(10);

		    cuarto_digito=rand()%(10);

                   /* determinamos según el rango cual carácter usaremos

                   (Numeral, dólar, porcentaje,

                   ampersand)*/

                   if (primer_digito>=0 and primer_digito<=2)

                            {

                            primer_digito='#';

                            }

                   if (primer_digito>=3 and primer_digito<=5)

                            {

                            primer_digito='$';

                            }

                   if (primer_digito>=6 and primer_digito<=7)

                            {

                            primer_digito='%';

                            }

                   if (primer_digito>=8 and primer_digito<=9)

                            {

                            primer_digito='&';

                            }

                   if (segundo_digito>=0 and segundo_digito<=2)

                            {

                            segundo_digito='#';

                            }

                   if (segundo_digito>=3 and segundo_digito<=5)

                            {

                            segundo_digito='$';

                            }

                   if (segundo_digito>=6 and segundo_digito<=7)

                            {

                            segundo_digito='%';

                            }

                   if (segundo_digito>=8 and segundo_digito<=9)

                            {

                            segundo_digito='&';

                            }

                     if (tercer_digito>=0 and tercer_digito<=2)

                            {

                            tercer_digito='#';

                            }

                   if (tercer_digito>=3 and tercer_digito<=5)

                            {

                            tercer_digito='$';

                            }

                   if (tercer_digito>=6 and tercer_digito<=7)

                            {

                            tercer_digito='%';

                            }

                   if (tercer_digito>=8 and tercer_digito<=9)

                            {

                            tercer_digito='&';

                            }

                    if (cuarto_digito>=0 and cuarto_digito<=2)

                            {

                            cuarto_digito='#';

                            }

                   if (cuarto_digito>=3 and cuarto_digito<=5)

                            {

                            cuarto_digito='$';

                            }

                   if (cuarto_digito>=6 and cuarto_digito<=7)

                            {

                            cuarto_digito='%';

                            }

                   if (cuarto_digito>=8 and cuarto_digito<=9)

                            {

                            cuarto_digito='&';

                            }

                   //definimos los caracteres a presentar en pantalla

                   s1=primer_digito;

                   s2=segundo_digito;

                   s3=tercer_digito;

                   s4=cuarto_digito;

                   // simulamos el ciclo de rotación del tragamonedas

                   cout <<"["<<s1<<"]["<<s2<<"]["<<s3<<"]["<<s4<<"]        Tiempo=  "<<tiempo;

				   cout <<"        Intentos= "<<intentos<<"         { Apuesta= "<<apuesta<<" $ - ";

				   cout <<" Credito= "<<monto-apuesta<<" $ }"<<endl<<endl;

				   cout <<" Presione (A) o (a) para aumentar la apuesta"<<endl;

				   cout <<" Presione cualquier otra tecla para parar la maquina"<<endl;

                   Beep(300,tiempo);

                   Sleep(tiempo);

                   system("cls");

                   tiempo = tiempo-1;

                   if (kbhit()!=0)

                    {

                    cambio=getch();	

				    if(cambio=='a'or cambio=='A')

				    	{

				    	apuesta=apuesta+1;

						Beep(150,100);	

						}

						else

						{

							tiempo=0;

						}

					}

                   }

           // Si ya jugo 3 veces lo dejamos ganar

         if(intentos>=3)

                   {

                   s1=s4;

                   s2=s4;

                   s3=s4;

                   }

         else

                   {

                   /*Nos aseguramos que nadie gane, en caso de que no alcance

                   los intentos establecidos (3 intentos) */

                   if (s1==s2 and s2==s3 and s3==s4)

                            {

                            if(s1=='$')

                                      {

                                      s1='%';

                                      }

                            if(s1=='%')

                                      {

                                      s1='$';

                                      }

                            if(s1=='&')

                                      {

                                      s1='#';

                                      }

                            if(s1=='#')

                                      {

                                      s1='&';

                                      }

                            }

                   }

         //Presentamos en pantalla el mensaje de éxito

         if (s1==s2 and s2==s3 and s3==s4)

                   {

                   monto=monto+apuesta*100;

                   apuesta=1;

                   system ("cls");

                   cout <<"["<<s1<<"]["<<s2<<"]["<<s3<<"]["<<s4<<"]"<<endl;

                   cout <<endl<<endl<<"Usted acaba de aumentar su credito a = "<<monto<<" $ "<<endl<<endl;

                   Beep (523,382);Beep (587,340);Beep (659,304);Beep (698,286);

          		   Beep (740,270);Beep (880,228);Beep (998,220); Beep (523,382);

          		   Sleep (1000);

                   Beep (998,220);Beep (880,228);Beep (740,270);Beep (698,286);

                   Beep (659,304);Beep (587,340);Beep (523,382);

                   intentos=0;

                   }

    				else

                   // presentamos el mensaje de derrota

		    {

                    Beep(150,50);

                    Beep(150,50);

					monto=monto-apuesta;

    		    system ("cls");

                   cout <<"["<<s1<<"]["<<s2<<"]["<<s3<<"]["<<s4<<"]"<<endl;

                   cout <<endl<<endl<<"Usted perdio "<<apuesta<<" $, su nuevo saldo es = "<<monto<<" $"<<endl<<endl;

				   apuesta=1;

				   }

                   cout <<"presione (S) o (s) para SALIR o cualquier otra tecla para volver a jugar"<<endl;

                  repetir:

				   if (kbhit()!=0)

                   {

                   	seguir=getch();

                   	if (seguir!='s' and seguir!='S')

                   		{

                   			system("cls");

							goto inicio;

						}                 

                   else

				   		{

				   			goto fin;

				   		}

                   }       

                   goto repetir;

fin:

system("cls");

cout <<"Hasta luego...."<<endl;         			

}