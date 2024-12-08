// 25102024 | @josephineesposito
// Project17.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

///
/// Practica 17. Utilidades para enumerados
/// [x] Crear una clase que contenga la definición de un enumerado y ofrezca la siguiente funcionalidad :
///		[x] const char* AsString(Enum _eEnum);
///		[x] Enum AsEnum(const char* _sEnum);
/// [ ] Mediante macros generalizar el código anterior para que sea más fácil crear enumerados con esa funcionalidad
///


#include <iostream>


// sezione per le macro
#pragma region MACROS

#define ADD_STATE(_VALUE) _VALUE,

#define ADD_CASE(_VALUE) \
	case _VALUE: \
		return #_VALUE;

#define ADD_IF(_VALUE, _TEXT) \
	if (_VALUE == #_TEXT) \
	{ \
		return _TEXT; \
	}

#define ACTION(_VALUE1, _VALUE2, _VALUE3, _VALUE4, _VALUE5, _VALUE6, _VALUE7, _CALL) \
	_CALL(_VALUE1) \
	_CALL(_VALUE2) \
	_CALL(_VALUE3) \
	_CALL(_VALUE4) \
	_CALL(_VALUE5) \
	_CALL(_VALUE6) \
	_CALL(_VALUE7)

#define CONTROL(_VALUE, _TEXT1, _TEXT2, _TEXT3, _TEXT4, _TEXT5, _TEXT6, _TEXT7, _CALL) \
	_CALL(_VALUE, _TEXT1) \
	_CALL(_VALUE, _TEXT2) \
	_CALL(_VALUE, _TEXT3) \
  _CALL(_VALUE, _TEXT4) \
  _CALL(_VALUE, _TEXT5) \
  _CALL(_VALUE, _TEXT6) \
  _CALL(_VALUE, _TEXT7)

#pragma endregion
//

class CEnum
{
public:

	enum eBooks
	{
		ACTION(SciFi, Horror, Giallo, Poesia, Fantasy, Romantico, Avventura, ADD_STATE)
	};
	eBooks eBook;

	CEnum(CEnum::eBooks _eBook)
	{
		eBook = _eBook;
	}

	const char* AsString(CEnum _eEnum)
	{
		switch (_eEnum.eBook)
		{
			ACTION(SciFi, Horror, Giallo, Poesia, Fantasy, Romantico, Avventura, ADD_CASE);
		}
	}

	eBooks AsEnum(const char* _sEnum)
	{
		CONTROL(_sEnum, SciFi, Horror, Giallo, Poesia, Fantasy, Romantico, Avventura, ADD_IF);
	}
};


int main()
{
	CEnum cEnum = CEnum(CEnum::eBooks::Avventura);

	std::cout << "Initial enum is " << cEnum.eBook << std::endl;

	std::cout << "Status as String is " << cEnum.AsString(cEnum) << std::endl;

	std::cout << "String as Status is " << cEnum.AsEnum("Romantico") << std::endl;
}
