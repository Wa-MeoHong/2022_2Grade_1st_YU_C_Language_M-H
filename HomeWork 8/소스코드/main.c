#include "Matrix.h"
#include "Mtrx_GJ.h"

#define INPUTDATA "InputData.txt"
#define OUTPUT "Output.txt"

int main(void)
{
	FILE* fin, * fout;
	int row_SIZE, col_SIZE;
	double* Sol;
	double** AugMtrx = NULL;
	int solExist;

	if ((fin = fopen(INPUTDATA, "r")) == NULL)
	{
		printf("Error! it doesn't opening InputData.txt file!!\n");
		exit(-1);
	} // �Է� ���� ����

	if ((fout = fopen(OUTPUT, "w")) == NULL)
	{
		printf("Error! it doesn't opening Output.txt file!!\n");
		exit(-1);
	} // ��� ���� ����

	AugMtrx = fGetMtrx(fin, &row_SIZE, &col_SIZE);						// ���� ������ �迭�� ���Ͽ��� ������
	PrintMtrx("Augmented Matrix", AugMtrx, row_SIZE, col_SIZE);			// ���� ������ �ʱ� ������� ���
	fPrintMtrx(fout, "Augmented Matrix", AugMtrx, row_SIZE, col_SIZE);	// ���� ���
	Sol = (double*)calloc(row_SIZE, sizeof(double));					// ���� ������ ������������ ������ ���Ƽ� SIZE_N���� �迭�� �������

	Diagnolize(fout, AugMtrx, row_SIZE, &solExist);						//���콺-���� �ҰŹ� ���

	if (solExist)														//�ذ� ������
	{
		fprintf(fout, "The Solution of given Linear System : \n");
		for (int i = 0; i < row_SIZE; i++)
		{
			Sol[i] = AugMtrx[i][row_SIZE];								//����� �迭�� ����
			fprintf(fout, "x[%d](I%d) = %4.4lf\n", i, i + 1, Sol[i]);	//��� ���
			printf("x[%d](I%d) = % 4.4lf\n", i, i + 1, Sol[i]);
		}
		printf("\n");
	}
	else																//�ذ� �ȳ��� (Ȥ�� �ذ� ����)
	{
		fprintf(fout, "No Solutions! \n");
		printf("No Solutions! \n");
	}

	DeleteDynMtrx(AugMtrx, row_SIZE);									//�����Ҵ� ����
	free(Sol);
	fclose(fin); fclose(fout);											// ���� ����
	return 0;
}