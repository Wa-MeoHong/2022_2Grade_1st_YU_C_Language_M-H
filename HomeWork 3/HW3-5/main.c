/*
*���ϸ� : "Print Matrix "
*���α׷��� ���� �� �⺻ ���:
*      - ���A, ���B�� �Է¹޾� (5 * 5¥�� �Ѵ�) ��İ����� ����� ���M�� ���
*
*���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 3�� 14��)
*���� Update : Version 1.5.0, 2022�� 3�� 15��(�Ŵ�ȫ)
*============================================================================
*���α׷� ����/���� �̷�
*============================================================================
*������			������			����			����/���ϳ���
*----------------------------------------------------------------------------
*�Ŵ�ȫ		 2022/03/14			v1.0.0		�����ۼ�
*�Ŵ�ȫ		 2022/03/15			v1.5.0		��İ����Լ� �߰�
*
*============================================================================
*/

#include <stdio.h>
#define MTX_SIZE 5							// ��� ������ = 5 (��, �� ����)

double MtxA[][MTX_SIZE] = {
	{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25} };
/*
	��� A : 
	��  1  2  3  4  5  ��
	��  6  7  8  9  10 ��
	��  11 12 13 14 15 ��
	��  16 17 18 19 20 ��
	��  21 22 23 24 25 ��
*/
double MtxB[][MTX_SIZE] = {
	{1,1,0,0,0}, {0,1,1,0,0},{0,0,1,1,0}, {0,0,0,1,1},{0,0,0,0,1} };
/*
	��� B :
	��  1  1  0  0  0  ��
	��  0  1  1  0  0  ��
	��  0  0  1  1  0  ��
	��  0  0  0  1  1  ��
	��  0  0  0  0  1  ��
*/

double MtxM[][MTX_SIZE] = { {0},{0},{0},{0},{0} };

void printMtx(double mA[][MTX_SIZE], int SIZE);					// ��� ��� �Լ�
void multipleMtx(double mA[][MTX_SIZE], double mB[][MTX_SIZE], double mM[][MTX_SIZE], int SIZE); // ��� �� �Լ�

int main(void)
{
	printf("print MtxA:\n");							// ��� A ���
	printMtx(MtxA, MTX_SIZE);
	printf("print MtxB:\n");							// ��� B ���
	printMtx(MtxB, MTX_SIZE);
	multipleMtx(MtxA, MtxB, MtxM, MTX_SIZE);			// ��� M ��� ( M = A * B )
	printf("print MtxM:\n");							// ��� M ���
	printMtx(MtxM, MTX_SIZE);
	return 0;
}

void multipleMtx(double mA[][MTX_SIZE], double mB[][MTX_SIZE], double mM[][MTX_SIZE], int SIZE)
// ��� �� �Լ�
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < SIZE; k++)
				mM[i][j] += mA[i][k] * mB[k][j];				// ��� �� = ��� A, B�� �����Ǵ� ������ ���� ��
		}
	}
}

void printMtx(double mA[][MTX_SIZE], int SIZE)
{
	const unsigned char a6 = 0xa6, a5 = 0xa5, a4 = 0xa4, a3 = 0xa3, a2 = 0xa2, a1 = 0xa1; 
	//Ȯ���� �����ڵ� : ( �� : a6a1, �� : a6a2, �� : a6a3, �� : a6a4, �� : a6a5, �� : a6a6 )

	for (int i = 0; i < SIZE; i++)
	{
		for (int k = 0; k < SIZE; k++)
		{
			// ���ȣ ��ºκ� ( ���� [ )
			if (i == 0 && k == 0)
				printf("%c%c", a6, a3);							// ��
			else if (i > 0 && i < SIZE - 1 && k == 0)
				printf("%c%c", a6, a2);							// ��
			else if (i == SIZE - 1 && k == 0)
				printf("%c%c", a6, a6);							// ��

			printf(" %3.0lf ", mA[i][k]);						// ���� ��ºκ�
			
			// ���ȣ ��ºκ� ( ���� ] )
			if (i == 0 && k == SIZE - 1)
				printf("%c%c", a6, a4);							// ��
			else if (i > 0 && i < SIZE - 1 && k == SIZE - 1)	
				printf("%c%c", a6, a2);							// ��
			else if (i == SIZE - 1 && k == SIZE - 1)
				printf("%c%c", a6, a5);							// ��
		}
		printf("\n");
	}
	printf("\n");
}