// Project15.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

///
/// [X] Dise�ar e implementar (simuladamente) el esqueleto de un sistema jer�rquico con funciones virtuales que gestione la apertura, cierre, lectura y escritura de streams
/// Los streams que deber� contemplar son :
///  - Ficheros
///  - Puerto serie
///  - Conexi�n TC
/// Habr� una clase base CStream y las clases derivadas
///  - CFile
///  - CCom
///  - CTcp
///

#include <iostream>

#include "CStream.h"
#include "CFile.h"
#include "CCom.h"
#include "CTcp.h"

int main()
{
    std::cout << "Hello World!\n";

    // Creating the objects
    CStream cStream = CStream();
    CFile cFile = CFile();
    CCom cCom = CCom();
    CTcp cTcp = CTcp();

    cStream.Open();
    cFile.Open();
    cCom.Open();
    cTcp.Open();
}
//EOF
