#ifndef SECANT_HPP
#define SECANT_HPP


/*
Author Shilo Wilson

Contains definition for secant method.
*/

#include <functional>

class SecantMethod
{
public:
	SecantMethod(std::function<double(double)> &f);
	SecantMethod(std::function<double(double)> &f, double &tol);
	SecantMethod(const SecantMethod &p);
	~SecantMethod();
	SecantMethod &operator = (const SecantMethod &p);
	double operator () (double x1, double x2);

private:
	std::function<double(double)> &m_function;  // Stores the Function to find roots
	double m_tol;   // Stores the Tolerance

};


#endif

