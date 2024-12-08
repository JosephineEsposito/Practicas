// 13112024 | @josephineesposito
// Project8.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

///
/// [X] Implementar la funcionalidad de la práctica 5 definiendo un tipo nuevo "TFile"
///

#include <iostream>
#include <sstream>
#include <fstream>

#include "TFile.h"

int main()
{
  std::fstream* sFile = new std::fstream; // initial file pointer

  unsigned int uSize = 5;
  char* pBuffer = new char[uSize];

  unsigned int uCadenaSize = 4;
  const char* pCadena = "Hola"; //new char[uCadenaSize];

  TFile* cTFile = new TFile();

  void* pFileTexto = cTFile->OpenFile("Hello.txt", "r+");
  if (pFileTexto)
  {
    int iRepeticiones = cTFile->SubStringFind(pCadena, uCadenaSize);
    printf("La cadena %s se repite %d veces.\n", pCadena, iRepeticiones);

    cTFile->CloseFile();
  }

  // Clean up memory
  delete sFile;
  delete[] pBuffer;

  return 0;
}
//EOF