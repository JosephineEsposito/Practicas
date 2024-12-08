// 22102024 | @josephineesposito
// Project7.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

///
/// [x] Organizar el código de la práctica 5 usando un namespace
/// [x] Organizar el código de la práctica 6 usando un namespace
///

#include <iostream>
#include <sstream>
#include <fstream>

#include "CFile.h"

using namespace FileManager;

int main()
{
  std::fstream* sFile = new std::fstream; // initial file pointer

  unsigned int uSize = 5;
  char* pBuffer = new char[uSize];

  unsigned int uCadenaSize = 4;
  const char* pCadena = "Hola"; //new char[uCadenaSize];


  void* pFileTexto = OpenFile(sFile, "Hello.txt", "r+");
  if (pFileTexto)
  {
    //ReadFile(pBuffer, uSize, pFileTexto);
    //WriteFile(pBuffer, uSize, pFileTexto);

    int iRepeticiones = SubStringFind(pCadena, uCadenaSize, sFile);
    printf("La cadena %s se repite %d veces.\n", pCadena, iRepeticiones);

    CloseFile(pFileTexto);
  }


  void* pFileNumeros = OpenFile(sFile, "Numbers.txt", "r");
  if (pFileNumeros)
  {
    int iSuma = SumaEnFichero(pFileNumeros);
    printf("La suma de los valores en el fichero es de %d\n", iSuma);

    CloseFile(pFileNumeros);
  }


  // Clean up memory
  delete sFile;
  delete[] pBuffer;

  return 0;
}
//EOF