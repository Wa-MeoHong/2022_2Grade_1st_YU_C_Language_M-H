/*
  ���ϸ� : "HW9-1_21912193_�Ŵ�ȫ"

  ���α׷��� ���� �� �⺻ ���:
	- ���Ҽ� ����ü �ڷ��� ���� ��, ���Ҽ� 2���� �Է¹ް� ������ ���� ��, �������� �Ͽ� ����ϴ� ���α׷�

  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 5�� 7��)
  ���� Update : Version 1.1.0, 2022�� 5�� 8��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������		   ������		 ����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
   �Ŵ�ȫ		 2022/05/07		v1.0.0		  �����ۼ�
   �Ŵ�ȫ		 2022/05/08		v1.1.0		  �ڵ�ϼ�
===========================================================================================================
*/

#ifndef CMPLX_H
#define CMPLX_H
#pragma warning(disable: 4996) // scanf���� �ȶ߰� �ϴ� pragma���� 

#include <stdio.h>
#include <math.h>
#define CmplxNUM 7															//���Ҽ� ����

typedef struct Complex_Number
{
	double real;					// �Ǽ��κ�
	double imagin;					// ��� �κ�
	double magnitude;				// ���Ҽ� ũ��(���Ҽ� ũ��񱳿�)
} Cmplx;

typedef enum Oper { ADD, SUB, MUL, DIV } Oper; 
// ���Ҽ� ���� ��� ��¿� enum

Cmplx InputCmplx();											// ���Ҽ� �Է� �Լ�

// ���Ҽ� ���
void printCmplxNum(const Cmplx c);													// ���Ҽ� ��� �Լ�
void printCplxresult(const Cmplx c1, const Cmplx c2, const Cmplx res, Oper num);	// ���Ҽ� ���� ��� �Լ�
void printCmplxs(const Cmplx* cmplxs, int SIZE);									// ���Ҽ� �迭 ��� �Լ�

// ���Ҽ� ����, ��
Cmplx cmplxAdd(const Cmplx c1, const Cmplx c2);										// ���Ҽ� ����
Cmplx cmplxSub(const Cmplx c1, const Cmplx c2);										// ���Ҽ� ����
Cmplx cmplxMul(const Cmplx c1, const Cmplx c2);										// ���Ҽ� ����
Cmplx cmplxDiv(const Cmplx c1, const Cmplx c2);										// ���Ҽ� ������
double CmpCmplx(const Cmplx c1, const Cmplx c2);									// ���Ҽ� �� �Լ�

// ����
void quickSortCmplx(Cmplx* cmplxs, int SIZE); // ������ �����Լ�
void quickSort(Cmplx* cmplxs, int SIZE, int left, int right); // ������ ���Լ�
int _partition(Cmplx* cmplxs, int SIZE, int left, int right, int P_I); //��Ƽ�� ��ġ�� ��ȯ

#endif // CMPLX_H