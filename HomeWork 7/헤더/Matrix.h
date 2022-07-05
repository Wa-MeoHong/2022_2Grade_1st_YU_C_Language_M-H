/*
  ���ϸ� : "HW7-2_21912193_�Ŵ�ȫ"

  ���α׷��� ���� �� �⺻ ���:
	- ������ �迭�� �����Ҵ� �� ��, ����� ���Ͽ��� �о�ͼ� ����ϴ� ���α׷�

  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 4�� 17��)
  ���� Update : Version 1.1.0, 2022�� 7�� 6��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������		   ������		 ����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
   �Ŵ�ȫ		 2022/04/17		v1.0.0		  �����ۼ�
   �Ŵ�ȫ		 2022/07/06		v1.1.0		  ���������� �ڵ� ����ȭ
===========================================================================================================
*/

#ifndef MATRIX_H
#define MATRIX_H

#pragma warning(disable: 4996)						// scanf���� �ȶ߰� �ϴ� pragma���� 

#include <stdio.h>
#include <stdlib.h>

#define MtrxDataFile "Mtrx_Data.txt"				// ����� ��� �ؽ�Ʈ����

double** fGetMtrx(FILE* fin, int* row_SIZE, int* col_SIZE);		// ���Ͽ��� ����� �о�ͼ� ��������
void DeleteDoubleMatrix(double** dM, int row_SIZE);				// ���������� ����� ����
void PrintMtrx(double** mA, int row_SIZE, int col_SIZE);		// ��� ��� �Լ�
double** AddMtrx(double** mA, double** mB, int row_SIZE, int col_SIZE);		// ��� ����
double** SubMtrx(double** mA, double** mB, int row_SIZE, int col_SIZE);		// ��� ����
double** MulMtrx(double** mA, double** mC, int row_SIZE, int col_SIZE, int SIZE_k); // ��� ����

#endif