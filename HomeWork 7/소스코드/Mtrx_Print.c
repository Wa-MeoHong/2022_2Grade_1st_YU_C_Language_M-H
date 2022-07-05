#include "Mtrx_Print.h"

void fgetMtrxandprint(FILE* fin, double** mA, int* row_SIZE, int* col_SIZE, char a)
// ���� �Է� �� ��� �Լ� (main�� �Է��ϴ°� ���Ƽ� �Լ��� �������)
{
	*mA = fGetMtrx(fin, &(*row_SIZE), &(*col_SIZE));
	//�����Ҵ� �� �� �Է�, ������ �Ű����� mA�� �ƴ� ���� ����(���ο� �ִ�)�� �ּҸ� ��ȯ
	printf("Mtrx_%c ( %d * %d ) : \n", a, *row_SIZE, *col_SIZE); //��� 
	PrintMtrx(*mA, *row_SIZE, *col_SIZE);	printf("\n");
}

void AddMtrxprint(double** mA, double** mB, double** mD, int* row_SIZE, int* col_SIZE, char a)
// ��� ���� ��� ( ���� �Լ��� ���� �ٸ����� �־� ���� �ۼ�, �Ʒ� �Լ��� ����) 
{
	*mD = AddMtrx(*mA, *mB, *row_SIZE, *col_SIZE);					// ��� ����
	printf("Mtrx_%c ( %d * %d ) : \n", a, *row_SIZE, *col_SIZE);	//���
	PrintMtrx(*mD, *row_SIZE, *col_SIZE);	printf("\n");
	DeleteDoubleMatrix(*mD, *row_SIZE);								// �����Ҵ� ����
}

void SubMtrxprint(double** mA, double** mB, double** mE, int* row_SIZE, int* col_SIZE, char a)
// ��� ���� ���
{
	*mE = SubMtrx(*mA, *mB, *row_SIZE, *col_SIZE);					// ��� ����
	printf("Mtrx_%c ( %d * %d ) : \n", a, *row_SIZE, *col_SIZE);	// ���
	PrintMtrx(*mE, *row_SIZE, *col_SIZE);	printf("\n");
	DeleteDoubleMatrix(*mE, *row_SIZE);								// �����Ҵ� ����
}

void MulMtrxprint(double** mA, double** mB, double** mF, int* row_SIZE, int* col_SIZE, int k_SIZE, char a)
// ��� ���� (row_size = ��� F�� �� = ��� A(���ϴ� ���)�� ��, F�� �� = ��� B(�������� ���)�� ��, k_SIZE = �� ���� ����� ���� ���� ��/��)
{
	*mF = MulMtrx(*mA, *mB, *row_SIZE, k_SIZE, *col_SIZE);			// ��� ����
	printf("Mtrx_%c ( %d * %d ) : \n", a, *row_SIZE, *col_SIZE);	// ���
	PrintMtrx(*mF, *row_SIZE, *col_SIZE);	printf("\n");
	DeleteDoubleMatrix(*mF, *row_SIZE);								// �����Ҵ� ����
}