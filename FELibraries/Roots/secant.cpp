/*
Author Shilo Wilson

Contains definition for Bisection.


*/

#include <functional>
#include <iostream>
#include "secant.hpp"

const double DEFAULT_ERROR = .001;

SecantMethod::SecantMethod(std::function<double(double)> &f) : m_function(f), m_tol(DEFAULT_ERROR)
{
	// Initialize bisection method with a default tolerance 
};

SecantMethod::SecantMethod(std::function<double(double)> &f, double &tol) : m_function(f), m_tol(tol)
{
	// User Specified tolerance
};

SecantMethod::SecantMethod(const SecantMethod &p) : m_function(p.m_function), m_tol(p.m_tol)
{
	// Copy ctor
};

SecantMethod::~SecantMethod()
{};

SecantMethod &SecantMethod::operator = (const SecantMethod &p)
{
	if (this != &p)
	{
		m_function = p.m_function;
		m_tol = p.m_tol;
	}
	return *this;
}

double SecantMethod::operator() (double x1, double x2)
{ // x1 
  // x2 

	double root = 0;    
	double fa = m_function(x1);    
	double fb = m_function(x2);    
	double c = 0, fc = 0;        
	
	do {
		std::cout << x1 << ", " << x2 << ", " << c << ", " << fa << ", " << fb << ", " << fc << std::endl;
		c = x2 - fb * (x2 - x1) / (fb - fa);            
		root = c;        
		fc = m_function(c);
		x1 = x2;        
		fa = fb;        
		x2 = c;        
		fb = fc;
		std::cout << x1 << ", " << x2 << ", " << c << fa << ", " << fb << ", " << fc << std::endl;
	} 
	while (std::abs(x1 - x2) > m_tol);        
	
	return root;
};