#pragma once

#include<iostream>
using namespace std;

long double* copy(long double* arr, int n);
void arrayFilling(long double* a, int n); //заполнение массива случайными числами
void showArray(long double* a, int n); //вывод массива на экран
void arrayUnif(long double* a, long double* b, long double* c, long double* d, long double* e, int n); //делает одинаковыми элементы массивов, стоящие на пересечении
void arrayFillingOne(long double* a, int n); //для заполнения массива единицами
void printMatrix(long double* a, long double* b, long double* c, long double* d, long double* e, long double* f1, long double* f2, int n); //вывод матрицы на экран
void methodG(long double* a, long double* b, long double* c, long double* d, long double* e, long double* f1, long double* f2, int n); //непосредственно метод Гаусса
void reverseSteps(long double* a, long double* b, long double* c, long double* d, long double* e, long double* f1, long double* f2, long double &res1, long double&res2, int n); // обратный ход
long double* multiplyMatrixOnVect(long double* a, long double* b, long double* c, long double* d, long double* e, long double& vect, int n); //умножение матрицы на вектор
//void multyplyStrOnVect(long double* a, long double* b, long double* c, long double* d, long double* e, long double& vect, int n); //умножение строки матрицы на вектор
long double accuracyOfTheSolution(long double* f, long double* res, int n);