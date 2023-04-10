//PARCIAL ABRIL 2018

/*
Sea una clase Vector para almacenar secuencias de números de coma flotante y doble 
precisión. La longitud de un vector se establecerá en el momento de la construcción y 
permanecerá fija hasta que el objeto sea destruido

class Vector{
	public:
		//..
	private:
		size_t n;
		double *datos;
}

*/

/*
Complete la clase vector con la declaración de los métodos necesarios para que las 
siguientes instrucciones proporcionen los resultados descritos en los comentarios y 
explique por qué se producen los dos errores.
*/

	- Vector v1(5,1.2);			//v1{1.2,1.2,1.2,1.2,1.2}			constructor con dos parametros
	- Vector v2(5);				//v2{0,0,0,0,0}						constructor de un parametro
	- Vector v3;				//error de compilacion				no hay constructor predeterminado
	- Vector v4 = 3;			//error de compilacion				no hay constructor de conversion y 3 no puede hacer la conversion de int a size_t
	- Vector v5 ={1.2,5.3};		//v5{1.2,5.3}						constructor de lista inicializadora
	
class Vector
{
	public:
		explicit Vector(size_t num, double dato = 0.0);
		Vector(std::initializer_list<double>l);
		
	private:
		size_t n;
		double *datos:
};


Vector::Vector(size_t num, double dato): n{num},datos{new double[num]}
{	
	for(size_t i = 0; i<num;i++)
	{
		datos[i] = dato;
	}
}

Vector::Vector(std::initializer_list<double> l):datos(new double[l.size()]),n(l.size())
{
	std::copy(l.begin(),l.end(),datos);
}


/*
¿Es válido el comportamiento por defecto del constructor? En caso afirmativo explique por 
qué, en caso contrario implemente el método.

Si por que hemos definido que siempre tiene que recibir un size_t,
Para que funcione deberiamos poner por defecto size_t a 0 en el constructor
*/


/*
d) Repita el apartado anterior para el constructor de copia
*/


class Vector
{
	public:
		explicit Vector(size_t num, double dato = 0.0);
		Vector(std::initializer_list<double>l);
		Vector(const Vector& v);
		
	private:
		size_t n;
		double *datos:
};

Vector::Vector(const Vector& v): n{v.n}, datos{new double(v.n)}
{
	for(size_t i = 0; i< v.n; i++)
	{
		datos[i] = v.datos[i];
	}
}

/*
Repita el apartado anterior para el constructor de movimiento
*/

class Vector
{
	public:
		explicit Vector(size_t num, double dato = 0.0);
		Vector(std::initializer_list<double>l);
		Vector(const Vector& v);
		Vector(Vector&& v);
		
	private:
		size_t n;
		double *datos:
};

Vector::Vector(Vector&& v): n{v.n}, datos{new double[v.n]}
{
	for(size_t i = 0; i< v.n; i++)
	{
		datos[i] = v.datos[i];
	}
	
	v.n = 0;
	v.datos = nullptr;
}


