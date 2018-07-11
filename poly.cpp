//-----------------------------------------------------------------------------
// File:		poly.cpp
// Programmer:	Anthony Waddell
// Resources:
//
//	For addition:
//		https://www.geeksforgeeks.org/program-add-two-polynomials/
//	For multiplication: 
//		https://www.geeksforgeeks.org/multiply-two-polynomials-2/
//-----------------------------------------------------------------------------
#include "poly.h"
using namespace std;

//-----------------------------------------------------------------------------
// Function:	Poly::Poly(int coeff, int power)
// Title:		Poly constructor with two parameters
// Description: Constructs a Poly object with given power and coefficient
//
// Programmer:	Anthony Waddell
//
// Parameters:	int coeff; the coefficient of the highest power
//				int power; the highest power
// Returns:		N/A
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
Poly::Poly(int coeff, int power)
{
	// Only take positive exponents
	if (power < 0)
	{
		power = -(power);
	}
	// Set properties and fill zeros
	this->size = power + 1;
	poly_Array = new int[this->size];
	for (int i = 0; i < size; i++)
	{
		poly_Array[i] = 0;
	}
	// Set coefficient
	poly_Array[power] = coeff;
}

//-----------------------------------------------------------------------------
// Function:	Poly::Poly(int coeff)
// Title:		Poly constructor with one parameters
// Description: Constructs a Poly object with given coefficient to the 0 power
//
// Programmer:	Anthony Waddell
//
// Parameters:	int coeff; the coefficient of the highest power
// Returns:		N/A
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
Poly::Poly(int coeff)
{
	// Set properties and instantiate 0 index to coeff
	this->size = 1;
	this->poly_Array = new int[1];
	poly_Array[0] = coeff;
}

//-----------------------------------------------------------------------------
// Function:	Poly::Poly()
// Title:		Poly constructor with no parameters
// Description: Constructs a Poly object of size 1 with element equal to 0
//
// Programmer:	Anthony Waddell
//
// Parameters:	N/A
// Returns:		N/A
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
Poly::Poly()
{
	// Set properties and instantiate 0 index to 0
	this->size = 1;
	this->poly_Array = new int[1];
	poly_Array[0] = 0;
}

//-----------------------------------------------------------------------------
// Function:	Poly::Poly(const Poly & other_Poly)
// Title:		Copy Constructor
// Description: Deep copy Poly constructor
//
// Programmer:	Anthony Waddell
//
// Parameters:	const Poly & other_Poly; the Poly opbject to copy
// Returns:		N/A
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
Poly::Poly(const Poly & other_Poly)
{
	// Clear properties and copy other Poly properties
	int size = other_Poly.size;
	this->size = size;
	this->poly_Array = new int[size];
	// Copy elements from other Poly array
	for (int i = 0; i < size; i++)
	{
		this->poly_Array[i] = other_Poly.poly_Array[i];
	}
}

//-----------------------------------------------------------------------------
// Function:	Poly::~Poly()
// Title:		Destructor
// Description: Destructor for Poly class object
//
// Programmer:	Anthony Waddell
//
// Parameters:	N/A 
// Returns:		N/A
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
Poly::~Poly()
{
	// Delete array and set to nullptr
	delete[] poly_Array;
	poly_Array = NULL;
}

//-----------------------------------------------------------------------------
// Function:	Poly Poly::operator+(const Poly & polynomial_Number) const
// Title:		Addition operator
// Description: Overloaded addition for Poly class
//
// Programmer:	Anthony Waddell
//
// Parameters:	const Poly & polynomial_Number; the addend
// Returns:		Poly sum; the sum of two Poly objects
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
Poly Poly::operator+(const Poly & polynomial_Number) const
{
	// Get size of largest Poly object and create new Poly object
	int sum_size = this->size > polynomial_Number.size 
		? this->size : polynomial_Number.size;
	Poly sum(0, sum_size - 1);

	// Copy elements of *this into new Poly object
	for (int i = 0; i < this->size; i++)
	{
		sum.poly_Array[i] = this->poly_Array[i];
	}
	// Add elements of other Poly object into new Poly object
	for (int j = 0; j < polynomial_Number.size; j++)
	{
		sum.poly_Array[j] += polynomial_Number.poly_Array[j];
	}
	return sum;
}

//-----------------------------------------------------------------------------
// Function:	Poly Poly::operator-(const Poly & polynomial_Number) const
// Title:		Addition operator
// Description: Overloaded subtraction for Poly class
//
// Programmer:	Anthony Waddell
//
// Parameters:	const Poly & polynomial_Number; the subtrahend
// Returns:		Poly diff; the differnce between two Poly objects
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
Poly Poly::operator-(const Poly & polynomial_Number) const
{
	// Get size of largest Poly object and create new Poly object
	int diff_size = this->size > polynomial_Number.size 
		? this->size : polynomial_Number.size;
	Poly diff(0, diff_size - 1);

	// Copy elements of *this into new Poly object
	for (int i = 0; i < this->size; i++)
	{
		diff.poly_Array[i] = this->poly_Array[i];
	}
	// Subtract elements of other Poly object into new Poly object
	for (int j = 0; j < polynomial_Number.size; j++)
	{
		diff.poly_Array[j] -= polynomial_Number.poly_Array[j];
	}
	return diff;
}

//-----------------------------------------------------------------------------
// Function:	Poly Poly::operator*(const Poly & polynomial_Number) const
// Title:		Addition operator
// Description: Overloaded multiplication for Poly class
//
// Programmer:	Anthony Waddell
//
// Parameters:	const Poly & polynomial_Number; the multiplicand
// Returns:		Poly product; the product of two Poly objects
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
Poly Poly::operator*(const Poly & polynomial_Number) const
{
	// Get size of product and create new Poly object
	int product_size = ((size + polynomial_Number.size) - 2);
	Poly product(0, product_size);

	// Start from least significant digit of *this
	for (int i = 0; i < size; i++)
	{
		// No zero multiplication
		if (this->poly_Array[i] != 0)
		{
			for (int j = 0; j < polynomial_Number.size; j++)
			{
				// Multiply each term of *this by multiplcahend Poly object
				product.poly_Array[i + j] += 
					(this->poly_Array[i] * polynomial_Number.poly_Array[j]);
			}
		}
	}
	return product;
}

//-----------------------------------------------------------------------------
// Function:	Poly Poly::operator=(const Poly & polynomial_Number) const
// Title:		Addition operator
// Description: Overloaded assignment for Poly class
//
// Programmer:	Anthony Waddell
//
// Parameters:	const Poly & polynomial_Number; the Poly object to set equal to
// Returns:		*this
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
Poly Poly::operator=(const Poly & polynomial_Number)
{
	// If they are equal, return
	if (this == &polynomial_Number)
	{
		return *this;
	}
	// Otherwise create new Poly object, swap properties with *this, return
	Poly temp(polynomial_Number);
	swap(size, temp.size);
	swap(poly_Array, temp.poly_Array);
	return *this;
}

//-----------------------------------------------------------------------------
// Function:	ostream & operator<<(ostream & sout, const Poly 
//					& polynomial_Number)
// Title:		Output operator
// Description: Overloaded output operator for the Poly class
//
// Programmer:	Anthony Waddell
//
// Parameters:	ostream & sout; reference to output stream
//				const Poly & polynomial_Number; Poly object to output
// Returns:		sout; reference to output stream
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
ostream & operator<<(ostream & sout, const Poly & polynomial_Number)
{
	// Call print function on Poly object
	polynomial_Number.print(sout);
	return sout;
}

//-----------------------------------------------------------------------------
// Function:	istream & operator >> (istream & sin, Poly & polynomial_Number)
// Title:		Input operator
// Description: Overloaded input operator for the Poly class
//
// Programmer:	Anthony Waddell
//
// Parameters:	istream & sin; reference to input stream
//				const Poly & polynomial_Number; Poly object to output
// Returns:		sout; reference to input stream
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
istream & operator >> (istream & sin, Poly & polynomial_Number)
{
	int coeff;
	int power;
	int stop = -1;

	// While buffer isn't clear
	while (sin >> coeff >> power)
	{
		// If stop values received, break
		if (coeff == stop && power == stop)
		{
			break;
		}
		// Fill Poly object with values from buffer
		polynomial_Number.setCoeff(coeff, power);
	}
	return sin;
}

//-----------------------------------------------------------------------------
// Function:	bool Poly::operator==(const Poly & polynomial_Number) const
// Title:		Comparison operator
// Description: Overloaded boolean comparison operator for Poly class
//
// Programmer:	Anthony Waddell
//
// Parameters:	const Poly & polynomial_Number; the Poly object to be compared
//					to
// Returns:		true if objects are equal; false if not
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
bool Poly::operator==(const Poly & polynomial_Number) const
{
	// If *this has smaller array
	if (size < polynomial_Number.size)
	{
		for (int i = 0; i < size; i++)
		{
			// Check that all values of smaller array are equal to larger array
			if (this->poly_Array[i] != polynomial_Number.poly_Array[i])
				return false;
		}
		for (int j = size; j < polynomial_Number.size; j++)
		{
			// Check that remaining elements of larger array are zero
			if (polynomial_Number.poly_Array[j] != 0)
				return false;
		}
		return true;
	}
	// If comparator has smaller array
	else if (size > polynomial_Number.size)
	{
		for (int i = 0; i < polynomial_Number.size; i++)
		{
			// Check that all values of smaller array are equal to larger array
			if (this->poly_Array[i] != polynomial_Number.poly_Array[i])
				return false;
		}
		for (int j = polynomial_Number.size; j < size; j++)
		{
			// Check that remaining elements of larger array are zero
			if (this->poly_Array[j] != 0)
				return false;
		}
		return true;
	}
	// If arrays are of	same size
	else
	{
		for (int i = 0; i < size; i++)
		{
			// Check that every element in both arrays are equal
			if (this->poly_Array[i] != polynomial_Number.poly_Array[i])
				return false;
		}
		return true;
	}
}

//-----------------------------------------------------------------------------
// Function:	int Poly::getCoeff(int power) const
// Title:		Accessor
// Description: Accessor for coeff property of Poly class
//
// Programmer:	Anthony Waddell
//
// Parameters:	int power; the power to to return the coefficient of
// Returns:		int; the coeff property of the designated power
//				0 (error) if power is out of bounds
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
int Poly::getCoeff(int power) const
{
	// Make sure power is in bounds
	if (power >= 0 && power <= (size - 1))
	{
		return this->poly_Array[power];
	}
	else
	{
		// Return 0 (error) for false bound
		return 0;
	}
}
//-----------------------------------------------------------------------------
// Function:	void Poly::setCoeff(int coeff, int power)
// Title:		Mutator
// Description: Mutator for coeff property of Poly class
//
// Programmer:	Anthony Waddell
//
// Parameters:	int coeff; the coefficient to be set
//				int power; the power of the desired coeff
// Returns:		void
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
void Poly::setCoeff(int coeff, int power)
{
	// Only take positive exponents
	if (power < 0)
	{
		power = -(power);
	}
	// If new memory has to be allocated
	if (power >= size)
	{
		// Create new Poly object, copy array values from *this
		Poly temp(0, power);
		for (int i = 0; i < size; i++)
		{
			temp.poly_Array[i] = this->poly_Array[i];
		}
		// Set coeff property of given power, clean up memory
		temp.poly_Array[power] = coeff;
		delete poly_Array;
		poly_Array = NULL;
		*this = temp;
	}
	// If no new memory is needed
	else if (power < size && power >= 0)
	{
		poly_Array[power] = coeff;
	}
}

//-----------------------------------------------------------------------------
// Function:	void Poly::print(ostream & sout) const
// Title:		Print
// Description: Print function for Poly class object
//
// Programmer:	Anthony Waddell
//
// Parameters:	ostream & sout; reference to output stream
// Returns:		coid
// History Log: 01/08/18 AW Completed Function
//-----------------------------------------------------------------------------
void Poly::print(ostream & sout) const
{
	bool all_Zeros = true;
	int zero = 0;
	int to_The_First = 1;

	// Check to see if Poly object should print as single zero
	for (int i = 0; i < size; i++)
	{
		if (poly_Array[i] != zero)
		{
			all_Zeros = false;
			break;
		}
	}
	// If Poly object is equal to zero
	if (all_Zeros)
	{
		cout << "0";
		return;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		// For last element (constant)
		if (i == zero)
		{
			// If negative value
			if (poly_Array[i] < zero)
			{
				cout <<  " "  << poly_Array[i];
			}
			else
			{
				// If positive value
				if (poly_Array[i] != zero)
				{
					cout << " +" << poly_Array[i];
				}
			}
		}
		// For all exponential values grater than x^0
		else
		{
			// For negative values
			if (poly_Array[i] < zero)
			{
				// Don't display zero values
				if (poly_Array[i] != zero)
				{
					if (i != to_The_First)
					{
						cout << " " << poly_Array[i] << "x^" << i;
					}
					// For x^1
					else
					{
						cout << " " << poly_Array[i] << "x";
					}
				}
			}
			else
			{
				// Don't diaply zero values
				if (poly_Array[i] != zero)
				{
					if (i != to_The_First)
					{
						cout << " +" << poly_Array[i] << "x^" << i;
					}
					// For x^1
					else
					{
						cout << " +" << poly_Array[i] << "x";
					}
				}
			}
		}
	}
}