/*

Author Shilo Wilson

Implementation of Newtons Method without directly passing derivative

*/
#ifndef NEWTONMOD_HPP
#define NEWTONMOD_HPP

#include <functional>
class NewtonMethodMod
{
public:
	NewtonMethodMod(std::function<double(double)> &f, double tol);
	NewtonMethodMod(const NewtonMethodMod &p);
	virtual ~NewtonMethodMod();

	NewtonMethodMod &operator = (const NewtonMethodMod &p);
	double operator ()(double initval);

private:
	std::function<double(double)> m_function;
	double m_tol;

	double derivative(double val);
};

#endif