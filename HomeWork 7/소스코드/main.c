#include "Matrix.h"
#include "Mtrx_Print.h"

int main(void)
{
	FILE* fin;
	char a = 65; //'A'
	double** mA, ** mB, ** mC, ** mD, ** mE, ** mF;
	int a_row_SIZE = 0, a_col_SIZE = 0;
	int b_row_SIZE = 0, b_col_SIZE = 0;
	int c_row_SIZE = 0, c_col_SIZE = 0;

	if ((fin = fopen(MtrxDataFile, "r")) == NULL)				// ������ �б���� ����. ���н� ����
	{
		printf("\tError in opening input.txt FILE !!\n\n");
		exit(-1);
	}

	//����� �����Ҵ� ���� ��, ��� ���ִ� �Լ� fgetMtrxandprint
	fgetMtrxandprint(fin, &mA, &a_row_SIZE, &a_col_SIZE, a++);
	fgetMtrxandprint(fin, &mB, &b_row_SIZE, &b_col_SIZE, a++);
	fgetMtrxandprint(fin, &mC, &c_row_SIZE, &c_col_SIZE, a++);

	if ((a_row_SIZE != b_row_SIZE) || (a_col_SIZE != b_col_SIZE))
	{ //���� �� �� �ϳ��� ���� �ʴٸ� ( ��� ����, ������ �ΰ��� ��,���� ���ƾ� ����)
		printf("\tError! row_SIZE and/or col_SIZE aren't equal!!\n ");
		fclose(fin);
		return; //�ϴ����� : ���ᰡ �Ǵ��� �ٽ� �ݺ����� �ؾ��ϱ� ����
	}

	//mD = mA + mB;
	AddMtrxprint(&mA, &mB, &mD, &a_row_SIZE, &a_col_SIZE, a++);
	//mE = mA - mB;
	SubMtrxprint(&mA, &mB, &mE, &a_row_SIZE, &a_col_SIZE, a++);
	//mF = mA * mC;
	MulMtrxprint(&mA, &mC, &mF, &a_row_SIZE, &c_col_SIZE, c_row_SIZE, a);

	DeleteDoubleMatrix(mA, a_row_SIZE); //�����Ҵ� ����
	DeleteDoubleMatrix(mB, b_row_SIZE);
	DeleteDoubleMatrix(mC, c_row_SIZE);

	fclose(fin);
	return 0;
}