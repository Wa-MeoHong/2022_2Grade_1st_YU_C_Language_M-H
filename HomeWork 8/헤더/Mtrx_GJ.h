#ifndef MTRX_GH_H
#define MTRX_GH_H
#pragma warning(disable: 4996) // scanf���� �ȶ߰� �ϴ� pragma���� 

#include "Matrix.h"
#include <stdio.h>
#include <math.h>

#define Epsilon 0.000001									// Epsilon = �Ҽ��� ǥ�� �ڸ��� ������ �Ѿ���� Ȯ���ϱ� ����

void pivoting(double** augMtrx, int SIZE_N, int p, int* piv_FOUND);			// �� �ٲ��ִ� �Լ� pivoting
void Diagnolize(FILE* fout, double** augMtrx, int SIZE_N, int* solExist);	// ���콺-���� �ҰŹ� ��� �Լ�
double** InvMtrx(double** mA, int row_SIZE);								// ����� ��� �Լ�

#endif // !MTRX_GH_H