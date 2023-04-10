//SEPTIEMBRE 2020

/*

Sea una clase llamada binario que almacena un n�mero binario de longitud arbitraria, 
representado por la secuencia de bits que lo componen (d�gitos 0 y 1). 
La secuencia de bits de un Binario se almacena de menos a m�s significativo en el atributo 
llamado bits, un vector de bajo nivel de unsigned int. Cada elemento del vector bits contiene 
hasta sizeof(unsigned int) bytes de la secuencia. Los bits m�s significativos del �ltimo 
elemento del vector que sobren valdr�n 0 y se ignorar�n. El tama�o del vector (m) depende 
de la longitud en bits (n) del n�mero binario y viene dado por la expresi�n m = (n + bits_elto 
-1) / bits_elto, donde la constante bits_elto corresponde al n�mero de bits de unsigned int. 
Ejemplo: Representaci�n de un Binario de n = 57 bits, suponiendo que sizeof(unsigned 
int) = 2bytes = 16 bits = bits_elto, almacenado en el atributo bits, un vector de bajo nivel 
de m = (n + bits_elto -1) / bits_elto = (57 + 16 -1) /16 = 4 unsigned int en el que sobran los 7 
bits m�s significativos. 

class Binario{
	public:
		//�
	private:
		static const size_t bits_elto = CHAR_BIT * sizeof(unsigned); //CHAR_BIT= bits por byte
		size_t n; //longitud de bits
		size_t m; //longitud del vector de enteros
		unsigned* bits; //vector de enteros
}

*/


/*
Declare e implemente los m�nimos m�todos imprescindibles para que las siguientes 
instrucciones proporcionen los resultados descritos en los comentarios. Si es v�lido el 
comportamiento por defecto de alguno de esos m�todos, explique por qu�.
*/

Binario b1(12); //b1 = 000000000000 (12 d�gitos de valor 0)				constructor de un parametro (n) 
Binario b1; //b2 = 0 (1 d�gito de valor 0)								constructor predeterminado;
b2 = ~b1; //b2 = 111111111111 (12 d�gitos de valor 1)					asignacion con operador ~
b2 = std::move(b1); //b2 = 000000000000(12 d�gitas de valor 0)			asignacion con constructor de movimiento;


class Binario{
	public:
		Binario(size_t n = 1);
		Binario(const Binario& B);
		Binario operator ~(const Binario& B);
		Binario& operator =(const Binario& B);
		Binario& operator =(Binario&& B);
		
		
	private:
		static const size_t bits_elto = CHAR_BIT * sizeof(unsigned); //CHAR_BIT= bits por byte
		size_t n; //longitud de bits
		size_t m; //longitud del vector de enteros
		unsigned* bits; //vector de enteros
}

Binario::Binario(size_t num): n{num},m{(n+bits_elto -1)/bits_elto},bits{new unsigned[m]}
{
	for(size_t i = 0; i < m)
	{
		bits[i] = 0;
	}
}


Binario::Binario(const Binario& B): n{B.n}, m{B.m}, bits{new unsigned[B.m]}
{
	for(size_t i = 0; i < B.m;i++)
	{
		bits[i] = B.bits[i];
	}
}


Binario Binario::operator ~(const Binario& B)
{
	Binario B2(B);
	
	for(size_t i = 0; i < B2.m;i++)
	{
		if(B2.bits[i] == 0)
		{
			B2.bits[i] = 1;
		}
		else
		{
			if(B2.bits[i] == 1)
			{
			B2.bits[i] = 0;
			}
		}	
	}
}

Binario& Binario::operator =(const Binario& B)
{
	if(this != &B)
		n = B.n;
		m = B.m;
	
		for(size_t i = 0; i < B.m;i++)
		{
			bits[i] = B.bits[i];
		}
	}
	return *this;
}

Binario& Binario::operator =(Binario&& B)
{
	if(this != &B)
	{	
		n = B.n;
		m = B.m;
		delete[] bits;
		bits = new unsigned[m];
		std::move(bits,B.bits);
		delete[] B.bits:
		B.bits = nullptr;
		B.n = 0;
		B.m = 0;
	}
	return *this;
}











