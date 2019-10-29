#include"MethodGaussa.h"
#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(unsigned(time(0)));

	int n = 10;
	long double *arr = new long double[n-1];
	long double *brr = new long double[n];
	long double *crr = new long double[n-1];
	long double *drr = new long double[n];
	long double *err = new long double[n];
	long double *f1 = new long double[n];
	long double *f2 = new long double[n];
	long double *c1 = new long double[n];
	long double *c2 = new long double[n];

	for (int i = 0; i < 10; i++)
	{
		arrayFilling(arr, n-1);
		arrayFilling(brr, n);
		arrayFilling(crr, n-1);
		arrayFilling(drr, n);
		arrayFilling(err, n);
	

		arrayUnif(arr,brr,crr,drr,err,n);
	
		cout << "A";
		showArray(arr, n - 1);
		cout << "B";
		showArray(brr, n);
		cout << "C";
		showArray(crr, n - 1);
		cout << "D";
		showArray(drr, n);
		cout << "E";
		showArray(err, n);

		cout << endl;

	
		arrayFilling(f1, n);
		cout << "f1:" << " ";
		showArray(f1, n);
		cout << endl;
		c1 = copy(f1, n);

		arrayFillingOne(f2, n);
		cout << "f2:" << " ";
		showArray(f2, n);
		cout << endl;
		c2 = copy(f2, n);

		f1 = multiplyMatrixOnVect(arr, brr, crr, drr,err, *f1, n);
		/*showArray(f1,n);
		cout << endl;*/
		f2 = multiplyMatrixOnVect(arr, brr, crr, drr, err, *f2, n);
		/*showArray(f2, n);
		printMatrix(arr, brr, crr, drr, err, f1, f2, n);
		cout << endl;*/


		/*long double ozenkaTochnostiReshenia = 0;*/
		/*long double *tochnosti = new long double[10];*/
			
		methodG(arr, brr, crr, drr, err, f1, f2, c1, c2, n);
		}
		/*printMatrix(arr, brr, crr, drr, err, f1, f2, n);*/





		system("pause");

}