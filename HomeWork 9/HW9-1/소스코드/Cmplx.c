#include "Cmplx.h"

Cmplx InputCmplx()						// ���Ҽ� �Է� �� �ʱⰪ ����
{
	Cmplx input;						

	// ���Ҽ� �Է�
	printf("Input Complex Number (rrr.ddd iii.ddd (�Ǽ�, ���)) : ");
	scanf("%lf %lf", &input.real, &input.imagin);

	// ���Ҽ��� ũ�� = ��(�Ǽ����� + �������)
	input.magnitude = sqrt(pow(input.real, 2) + pow(input.imagin, 2));

	return input;						// �� ��ȯ
}

void printCmplxNum(const Cmplx c)		// ���Ҽ� ��� �Լ� (�⺻��), ������� : "a + jb (magnitude = ũ��)"
{
	// �Ǽ��κ� ���
	printf("%7.3lf", c.real);						

	// ��� ���
	if (c.imagin < 0)								// ���� ����κ��� �����̸� - ���, �ƴϸ� + ���
		printf(" - ");
	else
		printf(" + ");
	printf("j%7.3lf", fabs(c.imagin));				// �̹� -�� �������Ƿ� ���� ���

	// ���Ҽ� ũ�� ���
	printf(" (magnitude = %7.3lf)", c.magnitude);	
}

void printCplxresult(const Cmplx c1, const Cmplx c2, const Cmplx res, Oper num) //���Ҽ� ���� ��� ���
{
	// ���Ҽ� 1 ���
	printCmplxNum(c1);					

	// ���꿡 ���� switch���� ���� �����ȣ ���
	switch (num)
	{
		case ADD:
		{
			printf(" + ");	break;
		}
		case SUB:
		{
			printf(" - ");	break;
		}
		case MUL:
		{
			printf(" * ");	break;
		}
		case DIV:
		{
			printf(" / ");	break;
		}
	}
	
	// ���Ҽ� 2 ���
	printCmplxNum(c2); printf(" = ");
	// ��� ���
	printCmplxNum(res);
	printf("\n");
}

void printCmplxs(const Cmplx* cmplxs, int SIZE)				// ���Ҽ� �迭 ��� �Լ�
{
	for (int i = 0; i < SIZE; i++)							//���Ҽ� ���� ��ŭ �ݺ�
	{
		//�������: "(cmplxs[i] = a + jb (magnitude = ũ��))"
		printf("(cmplxs[%d] = ", i); printCmplxNum(cmplxs[i]);
		printf(")\n");										
	}
	printf("\n");
}

// c1 = a + bj, c2 = c + dj
Cmplx cmplxAdd(const Cmplx c1, const Cmplx c2)				// ���Ҽ� ����
{
	Cmplx result;

	result.real = c1.real + c2.real;						// (a + c), �Ǽ����� ���
	result.imagin = c1.imagin + c2.imagin;					// (b + d)j, ������� ���
	result.magnitude = sqrt(pow(result.real, 2) + pow(result.imagin, 2)); // magnitude ��� (���Ҽ� ũ�� ���)
	

	return result;											// (a + c) + (b + d)j
}

Cmplx cmplxSub(const Cmplx c1, const Cmplx c2)				// ���Ҽ� ����
{
	Cmplx result;

	result.real = c1.real - c2.real;						// (a - c)
	result.imagin = c1.imagin - c2.imagin;					//(b - d)i
	result.magnitude = sqrt(pow(result.real, 2) + pow(result.imagin, 2));
	// magnitude ��� (���Ҽ� ũ�� ���)

	return result;											// (a - c) + (b - d)j
}

Cmplx cmplxMul(const Cmplx c1, const Cmplx c2)				// ���Ҽ� ����
{
	Cmplx result;

	result.real = (c1.real * c2.real) - (c1.imagin * c2.imagin);	// (ac - bd)
	result.imagin = (c1.real * c2.imagin) + (c1.imagin * c2.real);	// (ad + bc)i
	result.magnitude = sqrt(pow(result.real, 2) + pow(result.imagin, 2));
	// magnitude ��� (���Ҽ� ũ�� ���)

	return result;											// (ac - bd) + (ad + bc)i
}

Cmplx cmplxDiv(const Cmplx c1, const Cmplx c2)				// ���Ҽ� ������
{
	Cmplx result;

	result.real = (c1.real * c2.real + c1.imagin * c2.imagin) / (pow(c2.real, 2) + pow(c2.imagin, 2));		// (ac + bd) / (c�� + d��)
	result.imagin = (c1.imagin * c2.real - c1.real * c2.imagin) / (pow(c2.real, 2) + pow(c2.imagin, 2));	// (bc - ad) / (c�� + d��)
	result.magnitude = sqrt(pow(result.real, 2) + pow(result.imagin, 2));
	// magnitude ��� (���Ҽ� ũ�� ���)

	return result;											// ((ac + bd) + (bc - ad)i) / (c�� + d��)
}

double CmpCmplx(const Cmplx c1, const Cmplx c2)				// ���Ҽ� �� �Լ�
{
	// ����ص� magnitude�� ũ��� �� ���Ҽ��� ũ�⸦ ���� ( c1 ���� )
	if (c1.magnitude > c2.magnitude)				
		return 1;
	else if (c1.magnitude < c2.magnitude)
		return -1;
	else
		return 0;
}

// ������ �Լ� 
void quickSortCmplx(Cmplx* cmplxs, int SIZE)					// ������ �����Լ�
{
	quickSort(cmplxs, SIZE, 0, SIZE - 1);
	//ó�� �Ҷ��� left = ��ġ���� 0, right = size-1
}

void quickSort(Cmplx* cmplxs, int SIZE, int left, int right)	// ������ ���Լ�
{
	int P_I, newPI;
	if (left >= right)
		// ���� left�� right���� ũ�ų� ���ٸ� newPI��ȯ ����, ���� left�� 1Ȥ�� 0�϶��̴�..
		return;

	else if (left < right)
	{
		P_I = (left + right) / 2;						// �߰���, ���� Ȧ���ΰ�� ���������� ��������ġ�� ����
	}

	newPI = _partition(cmplxs, SIZE, left, right, P_I); //���ο� P_I(��������ġ��) ���� ��, ����

	// �̷��� ����, ������ ������� �������� �� ū����
	if (left < (newPI - 1))								// ���� newPI�������� ���ʺκ�
	{
		quickSort(cmplxs, SIZE, left, newPI - 1);
		// �ٽ� newPI�� �����ϸ鼭 ũ�������� �����ش�.
	}
	if ((newPI + 1) < right)							// ����, ������ quickSort�� ������, newPI���� ������ �κ�
	{
		quickSort(cmplxs, SIZE, newPI + 1, right);
		// ���������� newPI����� ũ������� �������ش�.
	}
}

int _partition(Cmplx* cmplxs, int SIZE, int left, int right, int P_I) //��Ƽ�� ��ġ�� ��ȯ �Լ�
{
	Cmplx P_V;							//pivot value, �� ��ġ�� �ִ� ��
	Cmplx temp;							// �� �ڸ��ٲٱ� �ϱ� ���� �ӽ����� ����
	int newPI;							// new pivot index, ���ο� ��ġ��

	// 1. ���߾Ӱ� ������ �� ���� ��ġ��ȯ
	P_V = cmplxs[P_I];
	cmplxs[P_I] = cmplxs[right];
	cmplxs[right] = P_V; // �� ó�� P_I�� �ִ� ���� �� ������(Ȥ�� P_I-1��ġ�� �ִ� ��)�� �ٲ۴�

	// 2. newPI(���ο� �߾Ӱ� ����)
	newPI = left;										// ���� ���ο� �ǹ���ġ�� �������ִµ� �ʱⰪ�� �� ����(Ȥ�� P_I + 1��ġ)���� ����
	for (int i = left; i <= right - 1; i++)				// �ǵڷ� ���Ե� P_V�� ���� ������ �迭���� ������ ��´�.
	{
		if (CmpCmplx(cmplxs[i], P_V) == -1)				//���� �ǵڷ� �� P_V���� ���� �۴ٸ�
		{
			temp = cmplxs[i];
			cmplxs[i] = cmplxs[newPI];
			cmplxs[newPI] = temp;						// ����(i)��ġ�� �ִ� ���� newPI�� �ִ� ������ �ٲ��ش�.
			newPI += 1;
		}
	}
	// ��������� ó�� P_V���� �������� ������ P_V���� ���� ������ �迭, �������� P_V���� ū ������ �迭�� �����Ǿ���.

	// 3. 1���� �ߴ���ó�� �Ǹ������� ���߾��� ��ȯ
	P_V = cmplxs[right];
	cmplxs[right] = cmplxs[newPI];
	cmplxs[newPI] = P_V;

	return newPI; //���ο� PI�� ���� ��ȯ���ش�.
}