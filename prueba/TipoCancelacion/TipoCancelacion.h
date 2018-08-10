class TipoCancelacion 
{
	public:
		TipoCancelacion(char* nombre, int id);
		void setNombre (char* nombre);
		char* getNombre ();
		void setId (int id);
		int getId ();
		void imprimirTipoCancelacion();
	private:
		char* nombre;
		int id;
};
