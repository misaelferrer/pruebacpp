#include <string>
#include <sstream>
#include "Profesores.h"

Profesores::Profesores(Profesor* profesor)
{
	this->profesor = profesor;
	this->ConnectDB();
}
int Profesores::modificarProfesor(Profesor* actual, Profesor* nuevo)
{
	// Para armar consulta SQL
	std::string sSQL;
	sSQL.append("UPDATE profesor SET nombre='");
	sSQL.append(nuevo->getNombre());
	sSQL.append("' WHERE id=");
	sSQL.append(this->itoa(actual->getId()));
	 // Ejecuta Consulta
	PGresult *res = PQexec(this->conn, sSQL.c_str());
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
	  cout << "Modificacion de profesor fallida\n";
	  PQclear(res);
	  CloseConn(this->conn);
	  return 0;
	}

  	cout << "Modificacion de Profesor - OK\n";

  	// Limpia Resultado
  	PQclear(res);

  	return 1;
}
void Profesores::imprimirUnProfesor(Profesor* profesor)
{
	int nFields;

  PGresult *res  = PQexec(this->conn, "BEGIN");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Comando BEGIN Fallo\n";
    PQclear(res);
    CloseConn(this->conn);
  }

  PQclear(res);
  	std::string sSQL;
	sSQL.append("DECLARE emprec CURSOR FOR select * from profesor WHERE id=");
	sSQL.append(this->itoa(profesor->getId()));

  res = PQexec(this->conn, sSQL.c_str());
  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "DECLARE CURSOR fallo\n";
    PQclear(res);
    CloseConn(this->conn);
  }

  PQclear(res);

  res = PQexec(this->conn, "FETCH ALL in emprec");

  if (PQresultStatus(res) != PGRES_TUPLES_OK)
  {
    cout << "FETCH ALL fallo\n";
    PQclear(res);
    CloseConn(this->conn);
  }

  nFields = PQnfields(res);

  // Prepare the header with employee table field name
  cout << "\nTraer Un Profesor Solicitado:";
  cout << "\n********************************************************************\n";
    for (int i = 0; i < nFields; i++)
        printf("%-30s", PQfname(res, i));
    cout << "\n********************************************************************\n";

    for (int i = 0; i < PQntuples(res); i++)
    {
        for (int j = 0; j < nFields; j++)
            printf("%-30s", PQgetvalue(res, i, j));
        printf("\n");
    }
 
    PQclear(res);

    res = PQexec(this->conn, "CLOSE emprec");
    PQclear(res);

    res = PQexec(this->conn, "END");

    PQclear(res);
}

void Profesores::imprimirProfesores()
{
  int nFields;

  PGresult *res  = PQexec(this->conn, "BEGIN");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Comando BEGIN Fallo\n";
    PQclear(res);
    CloseConn(this->conn);
  }

  PQclear(res);

  res = PQexec(this->conn, "DECLARE emprec CURSOR FOR select * from profesor");
  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "DECLARE CURSOR fallo\n";
    PQclear(res);
    CloseConn(this->conn);
  }

  PQclear(res);

  res = PQexec(this->conn, "FETCH ALL in emprec");

  if (PQresultStatus(res) != PGRES_TUPLES_OK)
  {
    cout << "FETCH ALL fallo\n";
    PQclear(res);
    CloseConn(this->conn);
  }

  nFields = PQnfields(res);

  // Prepare the header with employee table field name
  cout << "\nTraer Profesores Guardados:";
  cout << "\n********************************************************************\n";
    for (int i = 0; i < nFields; i++)
        printf("%-30s", PQfname(res, i));
    cout << "\n********************************************************************\n";

    for (int i = 0; i < PQntuples(res); i++)
    {
        for (int j = 0; j < nFields; j++)
            printf("%-30s", PQgetvalue(res, i, j));
        printf("\n");
    }
 
    PQclear(res);

    res = PQexec(this->conn, "CLOSE emprec");
    PQclear(res);

    res = PQexec(this->conn, "END");

    PQclear(res);
}
int Profesores::eliminarProfesor(Profesor* profesor)
{
	std::string sSQL;
	sSQL.append("DELETE FROM profesor WHERE id=");
	sSQL.append(this->itoa(profesor->getId()));

	PGresult *res = PQexec(this->conn, sSQL.c_str());

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Eliminacion de profesor fallida.\n";
    PQclear(res);
    CloseConn(this->conn);
    return 0;
  }

  cout << "\nEliminacion de Profesor " << profesor->getNombre() <<" - OK\n";

  PQclear(res);
  return 1;
}
void Profesores::CloseConn(PGconn *conn)
{
  PQfinish(conn);
  getchar();
}
PGconn * Profesores::ConnectDB()
{
  PGconn *conn = NULL;

  conn = PQconnectdb("user=postgres password=misael dbname=prueba host=127.0.0.1 port=5432");
  
  if (PQstatus(conn) != CONNECTION_OK)
  {
    cout << "Conexion a la BD Fallo.\n";
    CloseConn(conn);
  }
  else
  {
  		this->conn = conn;
  		cout << "Conexion a la BD - OK\n";
  }

  return conn;
}
string Profesores::itoa(int n)
{
    string s;
	char digit[] = "0123456789";
 
	do {
		s = digit[n % 10] + s;
	}while ((n /= 10) > 0);
 
	return s;
}
int Profesores::insertarProfesor(Profesor * profesor)
{
  // Para armar consulta SQL
	std::string sSQL;
	sSQL.append("INSERT INTO profesor(id,nombre) VALUES (");
	sSQL.append(this->itoa(profesor->getId()));
	sSQL.append(", '");
	sSQL.append(profesor->getNombre());
	sSQL.append("')");
	 // Ejecuta Consulta
	PGresult *res = PQexec(this->conn, sSQL.c_str());
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
	  cout << "Insercion de profesor fallida\n";
	  PQclear(res);
	  CloseConn(this->conn);
	  return 0;
	}

  	cout << "Insercion de Profesor - OK\n";

  	// Limpia Resultado
  	PQclear(res);

  	return 1;
}