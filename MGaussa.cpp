#include "MethodGaussa.h"
#include<iostream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;

void arrayFilling(long double* a, int n)
{
	//srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 11-10;
	}


}

void showArray(long double* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void arrayUnif(long double* a, long double* b, long double* c, long double* d, long double* e, int n)
{
	a[n - 2] = d[n - 1];
	b[n - 2] = d[n - 2];
	b[n - 1] = e[n - 1];
	/*c[n - 2] = d[n - 3];
	c[n-1] = e[n - 2];*/
	c[n - 2] = e[n - 2];
	c[n - 3] = d[n - 3];
}
void arrayFillingOne(long double* a, int n)
{

	for (int i = 0; i < n; i++)
		a[i] = 1;
}

void printMatrix(long double* a, long double* b, long double* c, long double* d, long double* e, long double* f1, long double* f2, int n)
{

	int space = n - 3;
	for (int i = 0; i < n; i++)
	{
		if (i >= 1 && i <= n - 1) cout << a[i-1] << " ";
		cout << b[i] << " ";
		if (i <= n - 2) cout << c[i] << " ";
		
		

		if (i == 0)
		{
			for (int t = 1; t <= space; t++)
				cout << " ";
			cout << d[i] << " " << e[i] << "       " << f1[i] << " " << f2[i];
			space--;
		}

		if (i > 0 && i < n - 3)
		{
			for (int t = 1; t < space; t++)
				cout << " ";
			cout << d[i] << " " << e[i] << "      " << f1[i] << " " << f2[i];
			space--;
		}

		if (i == n - 3)
			cout << e[i] << "      " << f1[i] << " " << f2[i];
		if (i > n - 3 && i<n)
			cout <<  "      " << f1[i] << " " << f2[i];


		cout << endl;

		for (int k = 0; k < i; k++)
			cout << "  ";
			
	}
	cout << endl;


}

void methodG(long double* a, long double* b, long double* c, long double* d, long double* e, long double* f1, long double* f2, long double* c1, long double* c2, int n)
{
	for (int i = 0; i < n-1; i++)   //спуск вниз 
	{
		/*for (int i = 0; i < n; i++)
			cout << b[i] << " ";

		cout << endl;*/
		
		long double R;
		try
		{
			if(b[i] != 0)
			R = 1 / b[i];
			else throw b[i];
		}
		catch (long double &value)
		{
			cout << "Devision by zero" << endl;
			return;
		} 
		
		
			//if ( R < 0.3) R = floor(R + 0.5);
			/*cout << "i" << " " << i << endl;
			cout << "b" << " " << b[i] << endl;
			cout << "R" << " " << R << endl;*/

			b[i] = 1;
			c[i] = R * c[i];
			/*cout << "c[i]" << " " << c[i] << endl;*/
			d[i] = R * d[i];
			e[i] = R * e[i];
			/*cout << "d[i]" << " " << d[i] << endl;*/
			f1[i] = R * f1[i];
			f2[i] = R * f2[i];
			R = a[i];
			/*cout << "R" << " " << R << endl;*/
			a[i] = 0;
			b[i + 1] = b[i + 1] - R * c[i];
			/*cout << "b[i+1]" << " " << b[i + 1] << endl;*/
		
			d[i + 1] = d[i + 1] - R * d[i];
			e[i + 1] = e[i + 1] - R * e[i];
			/*cout << "d[i+1]" << " " << d[i + 1] << endl;
			cout << "c[i+1]" << " " << c[i + 1] << endl;*/
			f1[i + 1] = f1[i + 1] - R * f1[i];
			f2[i + 1] = f2[i + 1] - R * f2[i];
			if (i == n - 4) c[i + 1] = d[i + 1];
			if (i == n - 3)
			{
				b[i + 1] = d[i + 1];
				c[i + 1] = e[i + 1];
			}
			

			cout << endl;
			
		
		
	}
	printMatrix(a, b, c, d, e, f1, f2, n);

	long double *res1 = new long double[n];
	long double *res2 = new long double[n];
	reverseSteps(a, b, c, d, e, f1, f2, *res1, *res2, n);

	double acc1 = accuracyOfTheSolution(c1, res1, n);  //находят максимальную погрешность(оценка точности решения)
	double acc2 = accuracyOfTheSolution(c2, res2, n);
	cout << "Оценка точности решения первого вектора: " << acc1 << endl;
	cout << "Оценка точности решения второго вектора: " << acc2 << endl;
	/*showArray(res1, n);
	cout << endl;
	showArray(res2, n);*/


}

void reverseSteps(long double* a, long double* b, long double* c, long double* d, long double* e, long double* f1, long double* f2, long double &res1, long double&res2, int n)
{
	long double *p = &res1;
	long double *q = &res2;

	
	try
	{
		if (e[n - 1] != 0)
		{
			p[n - 1] = f1[n - 1] / e[n - 1];			
		}
		else throw e[n - 1];
		
	}
	catch (long double &value)
	{
		cout << "Devision by zero" << endl;
		return;
	}
//	p[n - 1] = f1[n - 1] / e[n - 1];
	/*cout << "p[n-1]:" << " " << p[n-1] << endl;*/

	p[n - 2] = f1[n - 2] - e[n - 2] * p[n - 1];
	
	//cout << "p[n-2]:" << " " << p[n - 2] << endl;

	p[n - 3] = f1[n - 3] - p[n - 1] * e[n - 3] - p[n - 2] * d[n - 3];

	/*cout << "p[n-3]:" << " " << p[n - 3] << endl;*/
	/*cout << "p:" << endl;
	showArray(p, n);
	cout << endl;*/

	try
	{
		if (e[n - 1] != 0)
		{
			q[n - 1] = f2[n - 1] / e[n - 1];
		}
		else throw e[n - 1];

	}
	catch (long double &value)
	{
		cout << "Devision by zero" << endl;
		return;
	}
	//q[n - 1] = f2[n - 1] / e[n - 1];
	/*cout << "q[n-1]:" << " " << q[n - 1] << endl;*/
	q[n - 2] = f2[n - 2] - e[n - 2] * q[n - 1];
	/*cout << "q[n-2]:" << " " << q[n - 2] << endl;*/
	q[n - 3] = f2[n - 3] - q[n - 1] * e[n - 3] - q[n - 2] * d[n - 3];
	/*cout << "q[n-3]:" << " " << q[n - 3] << endl;*/
	
	/*cout << "q:" << endl;
	showArray(q, n);
	cout << endl;*/

	cout << "reverse" << endl;
	for (int k = n - 4; k >= 0; k--)
	{
		p[k] = f1[k] - e[k] * p[n - 1] - d[k] * p[n - 2] - c[k ] * p[k+1];
		q[k] = f2[k] - e[k] * q[n - 1] - d[k] * q[n - 2] - c[k ] * q[k + 1];
		/*cout << "p:" << endl;
		showArray(p, n);
		cout << "q:" << endl;
		showArray(q, n);*/

	}

	cout << "p:" << " ";
	showArray(p, n);
	cout << endl;
	cout << "q:" << " ";
	showArray(q, n);
	cout << endl;

}

long double* multiplyMatrixOnVect(long double* a, long double* b, long double* c, long double* d, long double* e, long double& vect, int n) //work
{
	long double*p = &vect;
	
	
	long double* v = new long double[n];

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			v[i] = p[i] * b[i] + p[i + 1] * c[i] + p[n - 2] * d[i] + p[n - 1] * e[i];
			/*cout << "i:" << " " << i;
			cout << "v[i]:" << " " << v[i];
			cout << endl;*/

		}
		if (i > 0 && i < n - 3)
		{
			v[i] = a[i - 1] * p[i - 1] + b[i] * p[i] + c[i] * p[i + 1] + p[n - 2] * d[i] + p[n - 1] * e[i];
			/*cout << "i:" << " " << i;
			cout << "p[i]:" << " " << v[i];
			cout << endl;*/

		}
		if (i == n - 3)
		{
			v[i] = a[i] * p[i - 1] + b[i] * p[i] + d[i] * p[n - 2] + e[i] * p[n - 1];
			/*cout << "i:" << " " << i;
			cout << "p[i]:" << " " << v[i];
			cout << endl;*/

		}
		if (i == n - 2)
		{
			v[i] = a[i-1] * p[i - 1] + b[i] * p[i] + e[i] * p[n - 1];	
			/*cout << "i:" << " " << i;
			cout << "p[i]:" << " " << v[i];
			cout << endl;*/

		}
		if (i == n - 1)
		{
			v[i] = a[i-1] * p[i - 1] + e[i] * p[i];
			/*cout << "i:" << " " << i;
			cout << "p[i]:" << " " << v[i];
			cout << endl;*/
		}


	}
		
	return v;


}
long double accuracyOfTheSolution(long double* f, long double* res, int n)
{
	double r = abs((res[0]-f[0])/f[0]);
	for (int i = 1; i < n; i++)
	{
		double c = abs((res[i] - f[i]) / f[i]);
		if (c >= r) r = c;
	}
	return r;


}
long double* copy(long double* arr, int n)
{
	long double *c = new long double[n];
	for (int i = 0; i < n; i++)
	{
		c[i] = arr[i];
	}
	return c;

}