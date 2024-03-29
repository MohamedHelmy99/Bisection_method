//#include "pch.h"
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

//the function
double f(double x)
{
	return (pow(x,3)+4*pow(x,2)-10);
}
//the midpoint function
double midpoint(double x, double y)
{
	return ((x + y) / 2);
}

int main()
{
	ofstream myfile;
	myfile.open("file.txt");
	myfile << "Calculating the approximate root value using bisection method " << endl;
	double a, b, m, epsilon;
	int iterations, choice;
	cout << "Enter the value of a and b where f(a)<0 and f(b)>0 :\n";
	cin >> a >> b;
	if (f(a)*f(b) > 0 || f(a)>f(b))
	{
		cout << "Incorrect values for a and b\n";
		return 0;
	}
	else
	{
		cout << "Enter 1 if you want a certain number of iterations:\n";
		cout << "Enter 2 if you want to enter the value of an epsilon:\n";
		cin >> choice;
		if (choice == 1)
		{
			m = midpoint(a, b);
			cout << "enter the number of iterations required\n";
			cin >> iterations;
			cout << "------------------------------------------------------------------------\n";
			myfile << "------------------------------------------------------------------------\n";
			cout << "|\t" << "a\t" << "|\t" << "b\t" << "|\t" << "m\t" << "|\t" << "f(m)\t" << "\t|\n";
			myfile << "|\t" << "a\t" << "|\t" << "b\t" << "|\t" << "m\t" << "|\t" << "f(m)\t" << "\t|\n";
			cout << "|\t" << a << "\t" << "|\t " << b << "\t" << "|\t " << m << "\t" << "|\t" << f(m) << "\t\t|\n";
			myfile << "|\t" << a << "\t" << "|\t " << b << "\t" << "|\t " << m << "\t" << "|\t" << f(m) << "\t\t|\n";
			for (int i = 0; i < iterations; i++)
			{
				if (f(m) <= 0)
				{
					a = m;
				}
				else
				{
					b = m;
				}
				m = midpoint(a, b);
				cout << "|\t" << a << "\t|\t" << b << "\t|\t" << m << "\t|\t" << f(m) << "\t|\n";
				myfile << "|\t" << a << "\t|\t" << b << "\t|\t" << m << "\t|\t" << f(m) << "\t|\n";

			}
			cout << "------------------------------------------------------------------------\n";
			myfile << "------------------------------------------------------------------------\n";
			cout << "The root is approximately = " << m << endl;
			myfile << "The root is approximately = " << m << endl;
		}
		else if (choice == 2)
		{
			cout << "Enter the value of epsilon\n";
			cin >> epsilon;
			m = midpoint(a, b);
			cout << "------------------------------------------------------------------------\n";
			myfile << "------------------------------------------------------------------------\n";
			cout << "|\t" << "a\t" << "|\t" << "b\t" << "|\t" << "m\t" << "|\t" << "f(m)\t" << "\t|\n";
			myfile << "|\t" << "a\t" << "|\t" << "b\t" << "|\t" << "m\t" << "|\t" << "f(m)\t" << "\t|\n";
			while ((b - a) >= epsilon)
			{
				m = midpoint(a, b);
				cout << "|\t" << a << "\t|\t" << b << "\t|\t" << m << "\t|\t" << f(m) << "\t|\n";
				myfile << "|\t" << a << "\t|\t" << b << "\t|\t" << m << "\t|\t" << f(m) << "\t|\n";

				if (f(m) <= 0)
				{
					a = m;
				}
				else
				{
					b = m;
				}

			}
			cout << "The root is approximately = " << m << endl;
			myfile << "The root is approximately = " << m << endl;
		}
		else
		{
			cout << "you have to choose either 1 or 2\n";
			return 0;
		}
		myfile.close();
	}
}


