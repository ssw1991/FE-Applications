

#ifndef BISECTION_H
#define BISECTION_H

/*
Author Shilo Wilson

Contains definition for Bisection.
*/

#include <functional>
#include <iostream>


class BisectionMethod
{
public:
	BisectionMethod(std::function<double(double)> &f);
	BisectionMethod(std::function<double(double)> &f, double &tol);
	BisectionMethod(const BisectionMethod &p);
	~BisectionMethod();
	BisectionMethod &operator = (const BisectionMethod &p);
	double operator () (double x1, double x2);

private:
	std::function<double(double)> &m_function;  // Stores the Function to find roots
	double m_tol;   // Stores the Tolerance

};


#endif

