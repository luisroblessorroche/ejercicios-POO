//parcial 2019

/*
Los racionales se guardarán siempre de manera canónica, no está permitido 
denominador 0 y el racional será almacenado como (0,1).

class Racional
{
	public:
		//…n
	private:
		int n,d;
	static int mcd(int,int);
};
*/


/*
Nombre los métodos necesarios para que las siguientes instrucciones muestren las 
salidas correspondientes
*/

	- Racional r(0,1);		//constructor con dos parametros enteros
	- Racional s;			//constructor sin parametros(por defecto)
	- Racional t{4,-8};		//constructor con dos parametros
	- Racional u(3);		//constructor con un solo parametro
	- Racional v = 5;		//constructor con un solo parametro
	- Racional w = v;		//constructor de copia
	- Racional x{w};		//constructor de copia
	- r = t;				//operador de asignacion 
	- s = Racional{9,6};	//operador de asignacion
	- v = -4;				//operador de asignacion de objeto construido con un parametro


/*
)Defina los miembros imprescindibles para que compilen y ejecuten las mismas 
instrucciones del apartado a) y explique por qué no se necesitan otros. Deberá 
comprobar precondiciones y lanzar las excepciones adecuadas
*/

class Racional
{
	public:
		class Invalida
		{
			public:
				Invalida(char* error): msg{error}{}
				char* motivo() const{return msg;}
			private:
				char* msg;
		}
		
		Racional(int num = 0, int den = 1);
		Racional(const Racional& R) = default; //tambien podriamos no ponerlo y hará lo mismo
		Racional& operator =(const Racional& R) = default; //tambien prodiamos no ponerlo y hará lo mismo
		Racional& operator =(int num);
		
	private:
		int n,d;
	static int mcd(int,int);
};


Racional::Racional(int num, int den): n{num}, d{den}
{
	if(den == 0)
	{
		throw Invalida("El denominador no puede ser 0");
	}
	
	n = n / mcd(n,d);
	d = d / mcd(n,d);
}

Racional& Racional::operator = (int num): n{num}
{
	n = n / mcd(n,d);
	d = d / mcd(n,d);
	return *this;
}

/*
c)Declare y defina los siguientes operadores y funciones:
	-Función inv()
	-Operadores aritméticos +,-,* y /
	-Operadores de signo + y -
	-Operadores de comparación ==, !=, <=, <, > y >=
*/

class Racional
{
	public:
		class Invalida
		{
			public:
				Invalida(char* error): msg{error}{}
				char* motivo() const{return msg;}
			private:
				char* msg;
		}
		
		Racional(int num = 0, int den = 1);
		Racional(const Racional& R) = default; //tambien podriamos no ponerlo y hará lo mismo
		Racional& operator =(const Racional& R) = default; //tambien prodiamos no ponerlo y hará lo mismo
		Racional& operator =(int num);
		
		Racional& inv();
		
		Racional operator +(const Racional& R);
		Racional operator -(const Racional& R);
		Racional operator *(const Racional& R);
		Racional operator /(const Racional& R);
		
		Racional operator +();
		Racional operator -();
		
		int num() const{return n;}
		int den() const{return d;}
		
	private:
		int n,d;
	static int mcd(int,int);
};


bool operator ==(const Racional& R1, const Racional& R2);
bool operator !=(const Racional& R1, const Racional& R2);
bool operator <(const Racional& R1, const Racional& R2);
bool operator >(const Racional& R1, const Racional& R2);
bool operator <=(const Racional& R1, const Racional& R2);
bool operator >=(const Racional& R1, const Racional& R2);


Racional& Racional::inv()
{
	int aux = this->n;
	n = this->d;
	d = aux;
	
	if(d == 0)
	{
		throw Invalida("El denominador no puede ser 0");
	}
}

Racional Racional::operator +(const Racional& R)
{
	Racional R1(*this);
	Racional R2(R);
	Racional R3;
	
	R3.d = R1.d * R2.d;
	R3.n = R1.n * R2.d + R2.n * R1.d;
	
	R3.n = R3.n / mcd(R3.n, R3.d);
	R3.d = R3.d / mcd(R3.n, R3.d);
	return R3;
}

Racional Racional::operator -(const Racional& R)
{
	Racional R1(*this);
	Racional R2(R);
	Racional R3;
	
	R3.d = R1.d * R2.d;
	R3.n = R1.n * R2.d - R2.n * R1.d;
	
	R3.n = R3.n / mcd(R3.n, R3.d);
	R3.d = R3.d / mcd(R3.n, R3.d);
	return R3;
}

Racional Racional::operator *(const Racional& R)
{
	Racional R1(*this);
	Racional R2(R);
	Racional R3;
	
	R3.d = R1.d * R2.d;
	R3.n = R1.n * R2.n;
	
	R3.n = R3.n / mcd(R3.n, R3.d);
	R3.d = R3.d / mcd(R3.n, R3.d);
	return R3;
}

Racional Racional::operator /(const Racional& R)
{
	Racional R1(*this);
	Racional R2(R);
	Racional R3;
	
	R3.d = R1.d * R2.n;
	R3.n = R1.n * R2.d;
	
	if(d == 0)
	{
		throw Invalida("El denominador no puede ser 0");
	}
	
	R3.n = R3.n / mcd(R3.n, R3.d);
	R3.d = R3.d / mcd(R3.n, R3.d);
	return R3;
}

Racional Racional::operator +()
{
	return Racional(+this->n,this->d);
}

Racional Racional::operator -()
{
	return Racional(-this->n,this->d);
}

bool operator ==(const Racional& R1, const Racional& R2)
{
	return ((R1.num() == R2.num()) && (R1.den() == R2.den()));
}

bool operator !=(const Racional& R1, const Racional& R2)
{
	return !(R1 == R2);
}

bool operator <(const Racional& R1, const Racional& R2)
{
	double x = R1.num()/R1.den();
	double y = R1.num()/R1.den();
	return x < y;
}

bool operator >(const Racional& R1, const Racional& R2)
{
	return  R2 < R1;
}

bool operator <=(const Racional& R1, const Racional& R2)
{
	return !(R1 > R2); //o (R1 < R2) || (R1 == R2)
}

bool operator >=(const Racional& R1, const Racional& R2)
{
	return !(R1 < R2); //o (R1 > R2) || (R1 == R2)
}


