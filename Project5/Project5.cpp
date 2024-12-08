// 22102024 | @josephineesposito
// Project5.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

/// Practica 5
/// Funciones a implementar
/// [x] openfile, abre un fichero, recibe como parametro el nombre del fichero y el modo de apertura | lectura o escritura, retorna un identificador del fichero abierto
/// [x] closefile, cierra un fichero, recibe como parametro el identificador del fichero a cerrar
/// [x] readfile, lee los n caracteres indicados del fichero de identificador indicado, los deja en el buffer pasado y retorna el numero de caracteres realmente leidos
/// [x] writefile, escribe los n caracteres del buffer pasado en el fichero de identificador pasado y retorna los caracteres escritos
/// 
/// Se tiene que tener en cuenta
/// [x] separar declaraciones de definiciones
/// [x] en la declaracion no puede aparecer ninguna referencia a la libreria que suara para la implementacion
/// [x] se pueden utilizar cualquier API de acceso a ficheros para su implementación
/// [x] se tiene que probar el correct funcionamiento de las funciones realizando llamadar de prueba en un "main"
///

#include <iostream>
#include <sstream>
#include <fstream>

#include "FileUtil.h"

int main()
{
  std::fstream* sFile = new std::fstream; // file pointer
  unsigned int uSize = 5;
  char* pBuffer = new char[uSize];

  void* pFile = OpenFile(sFile, "Hello.txt", "r");

  if (pFile)
  {
    ReadFile(pBuffer, uSize, pFile);
    WriteFile(pBuffer, uSize, pFile);
    CloseFile(pFile);
  }

  // Clean up memory
  delete sFile;
  delete[] pBuffer;
}
//EOF