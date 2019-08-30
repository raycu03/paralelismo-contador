#include <iostream>
#include <fstream>
using namespace std;

int main() {
   string cadena=" ";//string para guardar palabras
   int cont=0;
   ifstream fe("libro.txt");

   while(!fe.eof()) {//while para recorrer archivo palabra por palabra
      fe >> cadena;
      cont=cont+1;//se aumenta el valor del contador por cada palabra 
   }
   fe.close();// se cierra el archivo

  cout<<"numero de palabras: "<<cont;//mostramos la cantidad de palabras
   return 0;
}