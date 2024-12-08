// practica4.cpp
//
#include <stdio.h>
#include <Windows.h>
#include "consola.h"

#include <ctime>

struct TEntity;
typedef void (*funcEntity)(TEntity*);

#define MAX_X 20
#define MAX_Y 20
#define RUNTIME 60000 // 1 minuto

// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	funcEntity* m_funcs;

	TEntity(funcEntity* funcs, int x, int y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
	}
};

bool bGameState = true;

// ***************************************************************************************
// METHODS
// ***************************************************************************************
void DrawA(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("A");
}
void DrawB(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("B");
}
void DrawC(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("C");
}
void DrawD(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("D");
}


void MoveDown(TEntity* _pEntity)
{
	_pEntity->m_iy++;
	if (_pEntity->m_iy > MAX_Y)
	{
		_pEntity->m_iy = 0;
	}
}
void MoveRight(TEntity* _pEntity)
{
	_pEntity->m_ix++;
	if (_pEntity->m_ix > MAX_X)
	{
		_pEntity->m_ix = 0;
	}
}
void MoveDiagonalRight(TEntity* _pEntity)
{
	_pEntity->m_ix++;
	_pEntity->m_iy++;
	if (_pEntity->m_ix > MAX_X)
	{
		_pEntity->m_ix = 0;
	}
	if (_pEntity->m_iy > MAX_Y)
	{
		_pEntity->m_iy = 0;
	}
}
void MoveDiagonalLeft(TEntity* _pEntity)
{
	_pEntity->m_ix--;
	_pEntity->m_iy--;
	if (_pEntity->m_ix < 0)
	{
		_pEntity->m_ix = MAX_X;
	}
	if (_pEntity->m_iy < 0)
	{
		_pEntity->m_iy = MAX_Y;
	}
}

// ***************************************************************************************
// MAIN
// ***************************************************************************************
unsigned int uKey;
int main(int argc, char* argv[])
{
	TEntity* pEntities[4];
	const unsigned int uEntitiesSize = sizeof(pEntities) / (sizeof(int) + sizeof(int));

	const int iMethodsNumber = 2;
	funcEntity tMisFuncionesA[iMethodsNumber];
	funcEntity tMisFuncionesB[iMethodsNumber];
	funcEntity tMisFuncionesC[iMethodsNumber];
	funcEntity tMisFuncionesD[iMethodsNumber];

	tMisFuncionesA[0] = &MoveDown;
	tMisFuncionesA[1] = &DrawA;
	pEntities[0] = new TEntity(tMisFuncionesA, 10, 4);


	tMisFuncionesB[0] = &MoveRight;
	tMisFuncionesB[1] = &DrawB;
	pEntities[1] = new TEntity(tMisFuncionesB, 4, 6);


	tMisFuncionesC[0] = &MoveDiagonalRight;
	tMisFuncionesC[1] = &DrawC;
	pEntities[2] = new TEntity(tMisFuncionesC, 8, 8);


	tMisFuncionesD[0] = &MoveDiagonalLeft;
	tMisFuncionesD[1] = &DrawD;
	pEntities[3] = new TEntity(tMisFuncionesD, 6, 2);

	
	time_t timestamp = time(&timestamp);
	while (timestamp < timestamp + RUNTIME)
	{
		clear();

		for (unsigned int uIndex = 0; uIndex < 4; uIndex++)
		{
			(*(pEntities[uIndex])->m_funcs[0])((pEntities[uIndex]));
			(*(pEntities[uIndex])->m_funcs[1])((pEntities[uIndex]));
		}
		
		hidecursor();
		
		Sleep(200);
	}

	delete pEntities;
}

