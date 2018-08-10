#include "libpq-fe.h"
class TipoCancelaciones 
{
	public:
		TipoCancelaciones(TipoCancelacion* tipocancelacion);
		int insertarTipoCancelacion(TipoCancelacion* tipocancelacion);
		int modificarTipoCancelacion(TipoCancelacion* actual, TipoCancelacion* nuevo);
		void imprimirUnTipoCancelacion(TipoCancelacion* tipocancelacion);
		void imprimirTipoCancelaciones();
		int eliminarTipoCancelacion(TipoCancelacion* tipocancelacion);
		void CloseConn(PGconn *conn);
		PGconn * ConnectDB();
		string itoa(int n);
	private:
		TipoCancelacion* tipocancelacion;
		PGconn *conn;
};