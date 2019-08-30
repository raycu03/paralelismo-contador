#include <iostream>
#include <fstream>
#include	<omp.h>	
#include <vector>
using namespace std;

int main() {
  vector<string> palabras; //vector para guardar el texto linea por linea
  ifstream fe;
  fe.open("libro.txt");//se abre el archivo 
  int cont=0;
  string cont2;
    while(getline(fe,cont2)){//while para recorrer el archivo linea por linea 
    cont=cont+1;//numero de lineas 
    palabras.push_back(cont2);//vector donde se guardan las palabras de cada linea 
  }



  int npalabras=0;
  #pragma omp parallel reduction(+:npalabras)//aqui inicia el paralelismo 
  {
  int reparto=int (cont/omp_get_num_threads());//cuanto lineas para cada hilo 
  int lims=reparto*(omp_get_thread_num()+1);//limite superior 
  if(omp_get_thread_num()==(omp_get_num_threads()-1)){//este if en en caso de que queden lineas, estas se colocan en el ultimo hilo 
    lims=cont;

  }
  bool sp=true;//verificador de espacios
  for(int i=(reparto*omp_get_thread_num()); i<lims; i++){//para reocrrer el vector el vecor
    sp=true;
    for(int j=0; j<palabras[i].size();j++){//para recorrer la linea de texto dentro de la posicion del vector 
      if(palabras[i][j]==' '){//se verifica si hay espacios para contrar las palabras
        sp=true;
        }else{
          if(sp){
            npalabras=npalabras+1;//se suma una palabra
          }
          sp=false;
        }
    }
  }

  }

 cout<<"palabras: "<<npalabras<<endl;//mostramos la cantidad de palabras


  return 0;
}