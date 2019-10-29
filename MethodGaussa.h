#pragma once

#include<iostream>
using namespace std;

long double* copy(long double* arr, int n);
void arrayFilling(long double* a, int n); //���������� ������� ���������� �������
void showArray(long double* a, int n); //����� ������� �� �����
void arrayUnif(long double* a, long double* b, long double* c, long double* d, long double* e, int n); //������ ����������� �������� ��������, ������� �� �����������
void arrayFillingOne(long double* a, int n); //��� ���������� ������� ���������
void printMatrix(long double* a, long double* b, long double* c, long double* d, long double* e, long double* f1, long double* f2, int n); //����� ������� �� �����
void methodG(long double* a, long double* b, long double* c, long double* d, long double* e, long double* f1, long double* f2, int n); //��������������� ����� ������
void reverseSteps(long double* a, long double* b, long double* c, long double* d, long double* e, long double* f1, long double* f2, long double &res1, long double&res2, int n); // �������� ���
long double* multiplyMatrixOnVect(long double* a, long double* b, long double* c, long double* d, long double* e, long double& vect, int n); //��������� ������� �� ������
//void multyplyStrOnVect(long double* a, long double* b, long double* c, long double* d, long double* e, long double& vect, int n); //��������� ������ ������� �� ������
long double accuracyOfTheSolution(long double* f, long double* res, int n);