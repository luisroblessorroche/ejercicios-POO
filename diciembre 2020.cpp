//DICIEMBRE 2020

/*
Supongamos una clase en C++ para operar con números complejos:

class complejo{
	public:
 		// ...
	private:
 		double r, i; // parte real, parte imaginaria
};
*/


/*
a) Explique el método o métodos requeridos por cada una de las instrucciones 
siguientes. A continuación defina los mínimos miembros imprescindibles para que 
todas ellas se compilen y ejecuten correctamente y explique por qué no se necesitan 
otros. (1,5 p)
	
	complejo(double a = 0.0, double b = 0.0);
	complejo(const complejo& comp) = default;
	
*/

	- complejo v(1.)		//constructor de conversion de double a complejo
	- complejo w			//constructor predeterminado
	- complejo x{2.,-1.2}	//constructor con dos parametros de tipo double
	- complejo y(x)			//constructor de copia
	- complejo z = y		//constructor de copia
	- complejo i = {0,1}	//constructor con dos parametros
	- complejo i2 = -1		//constructor de conversion de entero a complejo
	- x = 3.5 				//conversion de double en asignacion
	
	
class Complejo{
	public:
		
		//constructores
		Complejo(double a = 0.0, double b = 0.0);
		Complejo(const Complejo& comp) = default; //no se si es necesario ponerlo
		
		//operadores de asignacion
		Complejo& operator =(const Complejo& comp) = default;
		
		
 	
	private:
 		double r, i; // parte real, parte imaginaria
};


Complejo::Complejo(double a, double b): r{a},i{b}{}

/*
b) Complete la clase complejo con las declaraciones y definiciones de las mínimas 
funciones necesarias para que el siguiente programa se ejecute sin errores. Dichas 
funciones se definirán en línea (inline) cuando sea factible y como miembros de la 
clase o como funciones externas según convenga. (1,5 p)

int main(){
 complejo i, i2, z, y;
 i.real() = 0; 	//Metodo observador
 i.imag() = 1; //Método observador
 i2 = i * i; //Op *
 if (i2 == complejo(-1.0)) cout << "OK\n";//Op ==
 if (i2 != -1.0) cout << "MAL\n"; //Ctor conv + op !=
 z = y = complejo(2.5, 1); //Op asignacion
 y.imag() = -y.imag(); //Método modificador + op de signo
 if (z + y == 2 * z.real()) cout << "OK\n";//op +
 else cout << "MAL\n";
 if (z + -y != complejo(0, 2 * z.imag())) cout << "MAL\n";
 else cout << "OK\n";
 return 0;
}
El operador de asignación no hace falta implementarlo porque no 
usamos memoria dinámica
*/


class Complejo{
	public:
		
		//constructores
		Complejo(double a = 0.0, double b = 0.0);
		Complejo(const Complejo& comp) = default; //no se si es necesario ponerlo
		
		//operadores de asignacion
		Complejo& operator =(const Complejo& comp) = default;
		
		double real() const noexcept;
		double imag() const noexcept;
		
		Complejo operator * (const Complejo& comp1, const Complejo& comp2);
		Complejo operator -(const Complejo& comp1);
		
		
 	
	private:
 		double r, i; // parte real, parte imaginaria
};

bool operator ==(const Complejo& comp1, const Complejo& comp2);
bool operator !=(const Complejo& comp1, const Complejo& comp2);



inline double Complejo::real(){return r;}
inline double Complejo::imag(){return i;}


Complejo Complejo::operator *(const Complejo& comp1, const Complejo& comp2)
{
	Complejo c{};
	c.r = comp1.real() * comp2.real() + comp1.real() * comp2.imag();
	c.i = comp1.imag() * comp1.real() + comp1.imag() * comp2.imag();
	return c;
}

Complejo Complejo::operator -(const Complejo& comp)
{
	Complejo c(comp);
	c.r = - comp.real();
	c.i = - comp.imag();
	return c;
}

bool operator ==(const Complejo& comp1, const Complejo comp2)
{
	return (comp1.real() == comp2.real() && comp1.imag() == comp2.imag());
}

bool operator !=(const Complejo& comp1, const Complejo comp2)
{
	return !(comp1 == comp2);
}



