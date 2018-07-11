//----------------------------------------------------------------------------
// File: Poly.h
// 
// Description: Function outlines for the Poly class
// 
// Programmer:	Anthony Waddell
// 
// Environment: Hardware: PC, i7
//              Software: OS: Windows 10 
//              Compiles under Microsoft Visual C++ 2015, g++
//---------------------------------------------------------------------------
#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;


class Poly
{
public:

	// Constructors
	Poly(int coeff, int power);			// Memory is reserved for polynomial A, with a largest power of 7
										// and the coefficient is set to 5: +5x^7.
	Poly(int coeff);					// B has one element, initialized to +2x^0
	Poly();								// Initialized to 0x^0 (zero polynomial)
	Poly(const Poly &other_Poly);		// C is an exact copy (deep copy) of A. 
	~Poly();

	// Mathematical operators
	Poly operator+(const Poly &polynomial_Number) const;
	Poly operator-(const Poly &polynomial_Number) const;
	Poly operator*(const Poly &polynomial_Number) const;
	Poly operator=(const Poly &polynomial_Number);

	// Mathematical assignment operators
	Poly operator+=(const Poly &polynomial_Number)
	{
		return (*this = *this + polynomial_Number);
	}
	Poly operator-=(const Poly &polynomial_Number)
	{
		return (*this = *this - polynomial_Number);
	}
	Poly operator*=(const Poly &polynomial_Number)
	{
		return (*this = *this * polynomial_Number);
	}

	//Boolean operators
	bool operator==(const Poly &polynomial_Number) const;
	bool operator!=(const Poly &polynomial_Number) const
	{
		return (!(*this == polynomial_Number));
	}

	// Accessors
	int getCoeff(int power) const;

	// Mutators
	void setCoeff(int coeff, int power);

	//Print operators
	void print(ostream & sout) const;

private:
	int *poly_Array;
	int size;

};

// overloaded input and output operator prototypes
ostream& operator<<(ostream& sout, const Poly &polynomial_Number);
istream& operator>>(istream& sin, Poly &polynomial_Number);

#endif