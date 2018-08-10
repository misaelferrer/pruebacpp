#include <iostream>

#include "Profesores/Profesor.cpp"
#include "Profesores/Profesores.cpp"

#include "TipoCancelacion/TipoCancelacion.cpp"
#include "TipoCancelacion/TipoCancelaciones.cpp"

using namespace std;

int main()
{
	
	//CRUD Profesores
	char p_nombre[] = "Minorvys Ferrer";
	Profesor* profe = new Profesor(p_nombre, 1);

	char p_nombre_new[] = "Pedro Mago";
	Profesor* profe_new = new Profesor(p_nombre_new, 2);

	char p_nombre_z[] = "Migdalis Rodriguez";
	Profesor* profe_z = new Profesor(p_nombre_z, 3);



	profe->imprimirProfesor();

	profe_new->imprimirProfesor();

	profe_z->imprimirProfesor();

	Profesores* profesores = new Profesores(profe);
	
	profesores->imprimirProfesores();
	
	profesores->insertarProfesor(profe);

	profesores->imprimirProfesores();

	profesores->insertarProfesor(profe_new);

	profesores->imprimirProfesores();

	profesores->insertarProfesor(profe_z);

	profesores->imprimirProfesores();

	profesores->modificarProfesor(profe, profe_new);

	profesores->imprimirProfesores();
	
	profesores->imprimirUnProfesor(profe_z);
	
	profesores->eliminarProfesor(profe_z);

	profesores->imprimirProfesores();

	//CRUD TipoCancelacion
	char nombre[] = "XXXXXXXXXX";
	TipoCancelacion* tipocance = new TipoCancelacion(nombre, 1);

	char nombre_new[] = "YYYYYYYYYYYY";
	TipoCancelacion* tipocance_new = new TipoCancelacion(nombre_new, 2);

	char nombre_z[] = "ZZZZZZZZZZZZZZZZZz";
	TipoCancelacion* tipocance_z = new TipoCancelacion(nombre_z, 3);

	tipocance->imprimirTipoCancelacion();
	
	tipocance_new->imprimirTipoCancelacion(); 

	tipocance_z->imprimirTipoCancelacion();
	
	TipoCancelaciones* tipocancelaciones = new TipoCancelaciones(tipocance);
	
	tipocancelaciones->imprimirTipoCancelaciones();
	
	tipocancelaciones->insertarTipoCancelacion(tipocance);

	tipocancelaciones->imprimirTipoCancelaciones();

	tipocancelaciones->insertarTipoCancelacion(tipocance_new);

	tipocancelaciones->imprimirTipoCancelaciones();

	tipocancelaciones->insertarTipoCancelacion(tipocance_z);

	tipocancelaciones->imprimirTipoCancelaciones();

	tipocancelaciones->imprimirUnTipoCancelacion(tipocance_new);
	
	tipocancelaciones->modificarTipoCancelacion(tipocance, tipocance_z);

	tipocancelaciones->imprimirTipoCancelaciones();

	tipocancelaciones->eliminarTipoCancelacion(tipocance_new);

	tipocancelaciones->imprimirTipoCancelaciones();
	
	return 0;
}