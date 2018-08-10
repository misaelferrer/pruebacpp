class Profesor 
{
	public:
		Profesor(char* nombre, int id);
		void setNombre (char* nombre);
		char* getNombre ();
		void setId (int id);
		int getId ();
		void imprimirProfesor();
	private:
		char* nombre;
		int id;
};
