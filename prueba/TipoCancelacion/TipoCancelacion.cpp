
#include <iostream>
#include <cstdlib>
#include "TipoCancelacion.h"
using namespace std;

TipoCancelacion::TipoCancelacion(char* nombre, int id)
{
	this->nombre = (char*) malloc (20);
	this->nombre = nombre;
	this->id = id;
}
void TipoCancelacion::setNombre (char* nombre)
{
	this->nombre = nombre;
}

char* TipoCancelacion::getNombre ()
{
	return this->nombre;
}

void TipoCancelacion::setId (int id)
{
	this->id = id;
}

int TipoCancelacion::getId ()
{
	return this->id;
}

void TipoCancelacion::imprimirTipoCancelacion()
{
	cout << "Id: " << this->id << ", Nombre: " << this->nombre << "\n";
}