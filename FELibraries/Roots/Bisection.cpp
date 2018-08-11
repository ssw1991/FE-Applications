/*
Author Shilo Wilson

Contains definition for Bisection.


*/

#include <functional>
#include <iostream>
#include "Bisection.h"

const double DEFAULT_ERROR = .001;

BisectionMethod::BisectionMethod(std::function<double(double)> &f): m_function(f), m_tol(DEFAULT_ERROR)
{
// Initialize bisection method with a default tolerance 
};

BisectionMethod::BisectionMethod(std::function<double(double)> &f, double &tol): m_function(f), m_tol(tol)
{
 // User Specified tolerance
};

BisectionMethod::BisectionMethod(const BisectionMethod &p) : m_function(p.m_function), m_tol(p.m_tol)
{
// Copy ctor
};

BisectionMethod::~BisectionMethod()
{};

BisectionMethod &BisectionMethod::operator = (const BisectionMethod &p)
{
	if (this != &p)
	{
		m_function = p.m_function;
		m_tol = p.m_tol;
	}
	return *this;
}

double BisectionMethod::operator() (double x1, double x2)
{ // x1 should be some value where the function evaluate negative
  // x2 should be some value where the function evaluates positive

	double root = 0;
	while (std::abs(x1 - x2) > m_tol)
	{
		double x3 = (x1 + x2) / 2;   // find the midpoint
		root = x3;
		if (m_function(x1) * m_function(x3) < 0)  // if f(x1) XOR f(x3) is negative
		{
			x2 = x3;
		}
		else
		{
			x1 = x3;			
		}
		
		if (m_function(x1) * m_function(x2) >= 0)
		{
			// Better to add exception later
			std::cout << "Function does not converge" << std::endl;
			break;
		}
		
	}
	return (root);
	
};