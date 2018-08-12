/*

Author Shilo Wilson

Implementation of Newtons Method without directly passing derivative

*/


#include <functional>
#include "NewtonMod.hpp"

NewtonMethodMod::NewtonMethodMod(std::function<double(double)> &f, double tol) : m_function(f), m_tol(tol)
{};

NewtonMethodMod::NewtonMethodMod(const NewtonMethodMod &p): m_function(p.m_function), m_tol(p.m_tol)
{
};

NewtonMethodMod::~NewtonMethodMod()
{};

NewtonMethodMod &NewtonMethodMod::operator = (const NewtonMethodMod &p)
{
	if (this != &p)
	{
		m_function = p.m_function;
		m_tol = p.m_tol;
	}
	return *this;
}

double NewtonMethodMod::operator ()(double initval)
{
	double x1 = initval;
	do
	{
		initval = x1;
		double d = derivative(initval);
		double y = m_function(initval);
		x1 = initval - y / d;

	} while (std::abs(initval - x1) > m_tol);
	return x1;
}


double NewtonMethodMod::derivative(double val)
{
	return (m_function(val + .0001) - m_function(val)) / .0001;
}


