// 15102024 - @josephineesposito
// Project1.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>

#pragma region Methods

// Para obtener el numero de balas a partir de la información
unsigned int GetNumBalas(unsigned int _uValue)
{
  /*
  * 10001001 00001101 01110000 00001100
  * >> 16
  * ------------------------------------
  * 00000000 00000000 10001001 00001101
  * AND
  * 00000000 00000000 00000000 11111111
  * ------------------------------------
  * 00000000 00000000 00000000 00001101
  */
  unsigned int uNumBalas_ = _uValue >> 16;
  uNumBalas_ &= 0x000000FF;
  return uNumBalas_;
}

// Para agregar más balas al personaje
unsigned int AddNumBalas(unsigned int _uValue, unsigned int _uMasBalas)
{
  unsigned int uAddedBalas_ = _uValue >> 16; // >> GetNumBalas(_uValue); is also and option
  uAddedBalas_ &= 0x000000FF; // >> *

  uAddedBalas_ += _uMasBalas;
  // >> Adding control
  if (uAddedBalas_ > UCHAR_MAX)
  {
    uAddedBalas_ = UCHAR_MAX;
  }

  uAddedBalas_ = uAddedBalas_ << 16;


  _uValue &= 0xFF00FFFF; //::puliamo lo spazio che ci serve dai valori vecchi

  unsigned int uNewInformacion_ = uAddedBalas_ | _uValue; //::aggiungiamo i nostri nuovi valori

  return uNewInformacion_;
}

// Para saber si la modalidad de balas infinita está activa o menos
bool GetModoBalas(unsigned int _uValue)
{
  /*
  * 10001001 00001101 0111 00000000 1 1 0 0
  * AND
  * 00000000 00000000 0000 00000000 0 0 1 0
  * ---------------------------------------
  * 00000000 00000000 0000 00000000 0 0 0 0
  */
  // removed >> 1 from the return and converted the method to bool
  return (_uValue &= 0x00000002); //..0010 is 2
}

// Para abilitar la modalidad de balas infinitas
unsigned int EnableModoBalas(unsigned int _uValue)
{
  /*
  * 10001001 00001101 0111 00000000 1 1 0 0
  * AND
  * 00000000 00000000 0000 00000000 0 0 1 0
  * ---------------------------------------
  * 00000000 00000000 0000 00000000 0 0 0 0
  */
  return _uValue |= 0x00000002;
}

// To set both values
unsigned int SetBalasInfinitas(unsigned int _uInformacion, bool _bValue)
{
  unsigned int uRet = _uInformacion;

  if (_bValue)
  {
    /*
    * 10001001 00001101 0111 00000000 1 1 0 0
    * OR
    * 00000000 00000000 0000 00000000 0 0 1 0
    * ---------------------------------------
    * 10001001 00001101 0111 00000000 1 1 1 0
    */
    uRet |= 0x00000002;
  }
  else
  {
    /*
    * 10001001 00001101 0111 00000000 1 1 0 0
    * AND
    * 11111111 11111111 1111 11111111 1 1 0 1
    * ---------------------------------------
    * 10001001 00001101 0111 00000000 1 1 0 0
    */
    uRet &= 0xFFFFFFFD;
  }
  return uRet;
}

#pragma endregion

//Main
int main()
{
  /* Detalles de la Información
  // VIDA -> 137 -> x89 
  // NUM. BALAS -> 13 -> x0D
  // COMPAÑEROS -> 7 -> 7
  // vacio 00
  //
  // - berseker -> true
  // - escudo -> true
  // - balas infinitas -> false
  // - invulnerable -> false
  // -> C
  // 10001001 00001101 0111 00000000 1 1 0 0
  */
  unsigned int uMiInformacion = 0x890D700C;

  printf("Current information : %X\n", uMiInformacion); //%X per far un print in esadecimale invece che unsigned int

  // Get Numero de balas:
  unsigned int uNumBalas = GetNumBalas(uMiInformacion);
  printf("Numero de balas : %d\n", uNumBalas);

  // Add Numero de balas:
  unsigned int uBalasToAdd = 10u;
  unsigned int uAddedBalas = AddNumBalas(uMiInformacion, uBalasToAdd);
  printf("New information with added balas : %X\n", uAddedBalas);

  // Modo Balas Infinitas:
  bool uModoBalas = GetModoBalas(uMiInformacion);
  printf("Modo Balas infinitas : %d\n", uModoBalas);

  // Enable Balas Infinitas:
  uModoBalas = EnableModoBalas(uMiInformacion);
  printf("Modo Balas infinitas : %d\n", GetModoBalas(uModoBalas));
}
