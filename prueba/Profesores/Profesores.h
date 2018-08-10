#include "libpq-fe.h"
class Profesores 
{
	public:
		Profesores(Profesor* profesor);
		int insertarProfesor(Profesor* profesor);
		int modificarProfesor(Profesor* actual, Profesor* nuevo);
		void imprimirUnProfesor(Profesor* profesor);
		void imprimirProfesores();
		int eliminarProfesor(Profesor* profesor);
		void CloseConn(PGconn *conn);
		PGconn * ConnectDB();
		string itoa(int n);
	private:
		Profesor* profesor;
		PGconn *conn;
};