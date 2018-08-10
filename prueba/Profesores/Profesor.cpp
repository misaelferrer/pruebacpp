
#include <iostream>
#include <cstdlib>
#include "Profesor.h"
using namespace std;

Profesor::Profesor(char* nombre, int id)
{
	this->nombre = (char*) malloc (20);
	this->nombre = nombre;
	this->id = id;
}
void Profesor::setNombre (char* nombre)
{
	this->nombre = nombre;
}

char* Profesor::getNombre ()
{
	return this->nombre;
}

void Profesor::setId (int id)
{
	this->id = id;
}

int Profesor::getId ()
{
	return this->id;
}

void Profesor::imprimirProfesor()
{
	cout << "Id: " << this->id << ", Nombre: " << this->nombre << "\n";
}