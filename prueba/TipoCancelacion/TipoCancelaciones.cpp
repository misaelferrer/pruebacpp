#include <string>
#include <sstream>
#include "TipoCancelaciones.h"

TipoCancelaciones::TipoCancelaciones(TipoCancelacion* tipocancelacion)
{
	this->tipocancelacion = tipocancelacion;
	this->ConnectDB();
}
int TipoCancelaciones::modificarTipoCancelacion(TipoCancelacion* actual, TipoCancelacion* nuevo)
{
	// Para armar consulta SQL
	std::string sSQL;
	sSQL.append("UPDATE tipocancelacion SET nombre='");
	sSQL.append(nuevo->getNombre());
	sSQL.append("' WHERE id=");
	sSQL.append(this->itoa(actual->getId()));
	 // Ejecuta Consulta
	PGresult *res = PQexec(this->conn, sSQL.c_str());
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
	  cout << "Modificacion de TipoCancelacion fallida\n";
	  PQclear(res);
	  CloseConn(this->conn);
	  return 0;
	}

  	cout << "Modificacion de TipoCancelacion - OK\n";

  	// Limpia Resultado
  	PQclear(res);

  	return 1;
}
void TipoCancelaciones::imprimirUnTipoCancelacion(TipoCancelacion* tipocancelacion)
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
	sSQL.append("DECLARE emprec CURSOR FOR select * from tipocancelacion WHERE id=");
	sSQL.append(this->itoa(tipocancelacion->getId()));

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
  cout << "\nTraer Un TipoCancelacion Solicitado:";
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

void TipoCancelaciones::imprimirTipoCancelaciones()
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

  res = PQexec(this->conn, "DECLARE emprec CURSOR FOR select * from tipocancelacion");
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
  cout << "\nTraer TipoCancelaciones Guardados:";
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
int TipoCancelaciones::eliminarTipoCancelacion(TipoCancelacion* tipocancelacion)
{
	std::string sSQL;
	sSQL.append("DELETE FROM tipocancelacion WHERE id=");
	sSQL.append(this->itoa(tipocancelacion->getId()));

	PGresult *res = PQexec(this->conn, sSQL.c_str());

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Eliminacion de TipoCancelacion fallida.\n";
    PQclear(res);
    CloseConn(this->conn);
    return 0;
  }

  cout << "\nEliminacion de TipoCancelacion " << tipocancelacion->getNombre() <<" - OK\n";

  PQclear(res);
  return 1;
}
void TipoCancelaciones::CloseConn(PGconn *conn)
{
  PQfinish(conn);
  getchar();
}
PGconn * TipoCancelaciones::ConnectDB()
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
string TipoCancelaciones::itoa(int n)
{
    string s;
	char digit[] = "0123456789";
 
	do {
		s = digit[n % 10] + s;
	}while ((n /= 10) > 0);
 
	return s;
}
int TipoCancelaciones::insertarTipoCancelacion(TipoCancelacion * tipocancelacion)
{
  // Para armar consulta SQL
	std::string sSQL;
	sSQL.append("INSERT INTO tipocancelacion(id,nombre) VALUES (");
	sSQL.append(this->itoa(tipocancelacion->getId()));
	sSQL.append(", '");
	sSQL.append(tipocancelacion->getNombre());
	sSQL.append("')");
	 // Ejecuta Consulta
	PGresult *res = PQexec(this->conn, sSQL.c_str());
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
	  cout << "Insercion de TipoCancelacion fallida\n";
	  PQclear(res);
	  CloseConn(this->conn);
	  return 0;
	}

  	cout << "Insercion de TipoCancelacion - OK\n";

  	// Limpia Resultado
  	PQclear(res);

  	return 1;
}