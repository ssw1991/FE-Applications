/* 
File to test Root finders

*/


#include <functional>
#include <iostream>
#include "Bisection.h"


double ConvergentFunction(double x)
{
	return (x - 1)*(x - 1 )*(x - 1);
}

double DivergentFunction(double x)
{
	return x * x + 1.0;
}


int main()
{
	std::function<double(double)> f1= ConvergentFunction;
	std::function<double(double)> f2 = DivergentFunction;

	BisectionMethod bm1(f1);
	BisectionMethod bm2(f2);

	double rt1 = bm1(-4, 10);
	double rt2 = bm2(-10, 10);

	std::cout << "Root is: " << rt1 << std::endl;

}