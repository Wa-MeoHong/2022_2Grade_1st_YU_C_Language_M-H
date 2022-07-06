#include "Mtrx_GJ.h"

void pivoting(double** augMtrx, int SIZE_N, int p, int* piv_FOUND) // �� �ٲ��ִ� �Լ� pivoting
{
	double max = 0;
	double temp = 0;
	int max_row = p;

	//���� ���� ū ���� ã�´�( �� ������)
	max = fabs(augMtrx[p][p]); //���� ��, �� ���� (1��°��,�� ��, 2��°��, ����, 3��°��,�� ��)
	// abs() = int���� ���� ��ȯ, fabs() = double ���� ���� ��ȯ

	for (int i = 0; i < SIZE_N; i++)
	{
		if (max < fabs(augMtrx[i][p]))
		{
			max_row = i;
			max = fabs(augMtrx[i][p]);
		}
	}

	if (max < Epsilon) //���� max == 0�̶�� 
		*piv_FOUND = 0; // �ظ� ���� �� ���� ���¶�� �ϰ�, solExist�� 0���� �������
	else
	{
		*piv_FOUND = 1; //�ƴϸ� solExist�� 1�� ���� ��, 
		if (max_row != p) //���� ������ ���� ū ���ȣ�� �ڱ� �ڽ��� �ƴ� ��쿡 �۵�
		{
			// �� p��, p������ �ϴ°��� �̹� �� ���� ���� ������ ������ ���� ��� ������ �Ϸ�Ǿ��� �����̴�.
			// ��, 2���� ������ �������� 1���� ��� 1, 0, 0, 0, 0,... ���� �����Ǿ� �ٲ� �ʿ䰡 ����.
			for (int k = p; k <= SIZE_N; k++)
			{
				temp = augMtrx[p][k];
				augMtrx[p][k] = augMtrx[max_row][k];
				augMtrx[max_row][k] = temp;
			}
		}
	}
}

void Diagnolize(FILE* fout, double** augMtrx, int SIZE_N, int* solExist) // ���콺-���� �ҰŹ� ��� �Լ�
{
	double pivDivide;
	double anotherDiv;

	for (int p = 0; (p < SIZE_N) && (*solExist); p++)
	{
		pivoting(augMtrx, SIZE_N, p, solExist);

		if (*solExist)
		{
			if (augMtrx[p][p] != 1.00)									// p,p�� ���� 1�� �ƴѰ�� (1�̸� �� ������ ���� �Ȱ�ħ)
			{
				pivDivide = augMtrx[p][p];
				augMtrx[p][p] = 1.00;
				for (int k = p + 1; k <= SIZE_N; k++)
					augMtrx[p][k] /= pivDivide;							// p,p�� ���� 1�� �ǵ��� ���� ��� ���� p,p�� ���� ����
			}
		}
		else
			break;
		// ������� pivoting ��, p��,p���� ���� 1�� ����� �ָ鼭 �� ���� ������ ���� �����ش�.
		// 
//-----------------------------------------------------------------------------------

	// ���⼭���� �� ������ ���� ������ �ٸ� ���� ���ָ鼭 p���� ������ ���� 0���� �������

		for (int j = 0; j < SIZE_N; j++)
		{
			if ((j != p) && (augMtrx[j][p] != 0.0))
			// p���� ������ ������ ��, ����, j���� p���� ���� 0(������ ��������)�� �ƴ� ����� ����
			{
				anotherDiv = augMtrx[j][p];
				augMtrx[j][p] = 0;
				for (int k = p + 1; k <= SIZE_N; k++)
					augMtrx[j][k] = augMtrx[j][k] - (anotherDiv * augMtrx[p][k]);
			}
		}
	}
}

double** InvMtrx(double** mA, int row_SIZE)						//����� ��� �Լ�
{
	// �������� ���� ���콺-���� �ҰŹ��� ����ϰ� �귯����, �����ʿ��� ������� ��������� �Ǵ°��� ���̴�.
	// ��, �迭�� �ΰ� ���ļ� ���콺-���� �ҰŹ�ó�� ����ϸ� �������� ��������� ������� �Ǿ� ���´�.

	double** AugMtrx;
	double** InvMtrx;
	double pivDivide;
	double anotherDiv;

	AugMtrx = (double**)calloc(row_SIZE, sizeof(double*));
	for (int i = 0; i < row_SIZE; i++)
		AugMtrx[i] = (double*)calloc(row_SIZE * 2, sizeof(double));

	InvMtrx = (double**)calloc(row_SIZE, sizeof(double*));
	for (int i = 0; i < row_SIZE; i++)
		InvMtrx[i] = (double*)calloc(row_SIZE, sizeof(double));

	for (int i = 0; i < row_SIZE; i++)
		for (int j = 0; j < row_SIZE; j++)						// AugMtrx�� ���� �κп� ���� ��� ����
			AugMtrx[i][j] = mA[i][j];

	for (int i = 0; i < row_SIZE; i++)
		for (int j = row_SIZE; j < row_SIZE * 2; j++)
			AugMtrx[i][j] = (i == j - row_SIZE) ? 1.0 : 0.0;
	//AugMtrx�� ������ �κ�, ��� ����ȣ�� ���ٸ� 1, �ƴϸ� 0 ����
	
	// ������� �� ���� 
	//--------------------------------------------------------------------------------------------------
	// ���ݺ��ʹ� ����� ��� ����

	for (int p = 0; p < row_SIZE; p++)
	{
		if (AugMtrx[p][p] != 1.00)								// p,p�� ���� 1�� �ƴѰ�� (1�̸� �� ������ ���� �Ȱ�ħ)
		{
			pivDivide = AugMtrx[p][p];
			AugMtrx[p][p] = 1.00;
			for (int k = p + 1; k < row_SIZE * 2; k++)			//����� ������ �迭�� ���������� row_SIZE�� �ι谡 ��...
				AugMtrx[p][k] /= pivDivide;						// p,p�� ���� 1�� �ǵ��� ���� ��� ���� p,p�� ���� ����
		}


		for (int j = 0; j < row_SIZE; j++)
		{
			if ((j != p) && (AugMtrx[j][p] != 0.0))
			// p���� ������ ������ ��, ����, j���� p���� ���� 0(������ ��������)�� �ƴ� ����� ����
			{
				anotherDiv = AugMtrx[j][p];
				AugMtrx[j][p] = 0;
				for (int k = p + 1; k < row_SIZE * 2; k++)
					AugMtrx[j][k] = AugMtrx[j][k] - (anotherDiv * AugMtrx[p][k]);
			}
		}
	}
	// ����� ��� �Ϸ�
	
	//--------------------------------------------------------------------------------------------------
	
	// ���� ���� ������� ������ Inv_mA�� ����

	for (int i = 0; i < row_SIZE; i++)
		for (int j = 0; j < row_SIZE; j++)
			InvMtrx[i][j] = AugMtrx[i][j + row_SIZE];

	for (int i = 0; i < row_SIZE; i++)							//���� �� �ึ�� �ߴ� �����Ҵ��� ����
		free(AugMtrx[i]);
	free(AugMtrx);

	return InvMtrx;
}