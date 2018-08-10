
class TipoTarea 
{
	public:
		void setNombre (char * nombre);
		char * getNombre ();
		void setId (int id);
		int getId ();
		char * nombre;
	private:
		int id;
};

class Curso 
{
	public:
		void setNombre (char * nombre);
		char * getNombre ();
		void setId (int id);
		int getId ();
		char * nombre;
	private:
		int id;
};

class Alumno 
{
	public:
		void setNombre (char * nombre);
		char * getNombre ();
		void setId (int id);
		int getId ();
		char * nombre;
	private:
		int id;
};

class Clase 
{
	public:
		void setId (int id);
		int getId ();
		void setProfesor (Profesor profesor);
		Profesor getProfesor ();
		void setGrupo (Grupo grupo);
		Grupo getGrupo ();
	private:
		int id;
		TipoCancelacion tipocancelacion;
		Profesor profesor;
		Horario horario;
		TipoTarea tipotarea;
};

class Horario 
{
	public:
		void setId (int id);
		int getId ();
		void setProfesor (Profesor profesor);
		Profesor getProfesor ();
		void setGrupo (Grupo grupo);
		Grupo getGrupo ();
	private:
		int id;
		Profesor profesor;
		Grupo grupo;
};

class Asistencia 
{
	public:
		void setId (int id);
		int getId ();
		void setProfesor (Profesor profesor);
		Profesor getProfesor ();
		void setGrupo (Grupo grupo);
		Grupo getGrupo ();
	private:
		int id;
		Clase clase;
		AlumnoEnGrupo alumnoengrupo;
};

class AlumnoEnGrupo 
{
	public:
		void setMatricula (Matricula matricula);
		Matricula getMatricula ();
		void setId (int id);
		int getId ();
		Matricula matricula;
	private:
		int id;
};

class Matricula 
{
	public:
		void setId (int id);
		int getId ();
		void setProfesor (Profesor profesor);
		Profesor getProfesor ();
		void setGrupo (Grupo grupo);
		Grupo getGrupo ();
	private:
		int id;
		Curso curso;
		Alumno alumno;
};

class Grupo 
{
	public:
		void setGrupo (Grupo grupo);
		Grupo getGrupo ();
		void setProfesor (Profesor profesor);
		Profesor getProfesor ();
		void setCurso (Curso curso);
		Curso getCurso ();
		void setId (int id);
		int getId ();
	private:
		int id;
		Profesor profesor;
		Curso curso;
};
