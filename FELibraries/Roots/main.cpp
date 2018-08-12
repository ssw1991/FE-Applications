/* 
File to test Root finders

*/


#include <functional>
#include <iostream>
#include "Bisection.h"
#include "secant.hpp"
#include "NewtonMod.hpp"


double ConvergentFunction(double x)
{
	return (x - 1)*(x - 1 )*(x - 1);
}




int main()
{
	std::function<double(double)> f1= ConvergentFunction;



	NewtonMethodMod nm1(f1, .00001);

	std::cout << "Root is: " << nm1(-4) << std::endl;
	

}