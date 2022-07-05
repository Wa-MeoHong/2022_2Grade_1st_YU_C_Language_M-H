/*
  ���ϸ� : "HW4-2_21912193_�Ŵ�ȫ"

  ���α׷��� ���� �� �⺻ ���:
	- �ŵ������� �ϴ� �Լ��� 2��(for�ݺ��� ���, ����Լ� ���)���� ��,
	������ �Լ����� ó���ϴ� �ð��� ����ϰ� �Ͽ� ���غ��� ���α׷�

  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 3�� 25��)
  ���� Update : Version 2.0.0, 2022�� 7�� 6��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������		   ������		 ����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
   �Ŵ�ȫ		 2022/03/25		v1.0.0		  �����ۼ�
   �Ŵ�ȫ		 2022/03/27		v1.1.0		  ����Լ� ����(4000���� ��)
   �Ŵ�ȫ		 2022/07/06		v2.0.0		  ����Լ��� �����Ҵ�迭�� �̿��ؼ� �籸��
===========================================================================================================
*/

#include <stdio.h>
#include <windows.h>								// �ð���꿡 �ʿ��� ������� 1 ( windows.h �̿� )
#include <time.h>									// �ð���꿡 �ʿ��� ������� 2 ( time.h �̿� )

#define Milli 1000									// �ð� ȯ��� ���

double PowerFor(double base, int exponent);									// �ݺ��� ��� �ŵ�����
double PowerRecursive(double base, int exponent, double* array);			// ����Լ� �ŵ�����

int main(void)
{
	double resultF, resultR;						// ���� for���� ���, ����Լ� ��� ���� ������
	double base = 1.015;							// 1.015�� ������ ����
	double* Rarray;									// �����÷η� ���� ������ �����ϱ� ���� �����Ҵ��� �Ѵ�. (����ȭ�� ����)

	// �ð� ��꿡 �ʿ��� ���� 1 (windows.h ��������� �̿�)
	LARGE_INTEGER freq, t_1, t_2;							// CPU�� Ŭ���� ��� ���� freq, ���� t_1, �� t_2
	LONGLONG t_diff_pc;										// t_2 - t_1 = t_diff_pc (�ð��� ���) (LONGLONG = windows.h�� �ִ� 64��Ʈ�� ����)
	double t_elapse_ms;										// t_diff_pc�� ms������ ȯ���� *( * 1000 )
	
	// �ð� ��꿡 �ʿ��� ���� 2 (time.h ��������� �̿�) 
	time_t t_before, t_after;
	double t_diff;											// t_after - t_before 
	
	Rarray = (double*)calloc(50000, sizeof(double));		// ���� Rarray�� �����Ҵ� ���ش� (�� �迭�� �ݺ��� ���߿� ����ϱ� ������ ���⼭ �Ҵ�)
	QueryPerformanceFrequency(&freq);					// CPU Ŭ���� ���� 1�ʴ� ����Ǵ� ƽ��, (���� �������̶� 1���� �ϸ� ��)
	for (int exponent = 1000; exponent <= 5000; exponent += 1000)
	{
		time(&t_before);								//�ð����(�Լ�������) 1 (time.h)
		QueryPerformanceCounter(&t_1);					//�ð����(�Լ�������) 2 (windows.h)
		resultF = PowerFor(base, exponent);				//����������� �������� (�ݺ���)'
		time(&t_after);									//�ð����(�Լ���) 1
		QueryPerformanceCounter(&t_2);					//�ð����(�Լ���) 2

		// �ð��� ���
		t_diff = difftime(t_before, t_after);			// time.h
		t_diff_pc = t_2.QuadPart - t_1.QuadPart;		// windows.h (LARGE_INTEGER �ڷ����� ���� .QuadPart�� �ٿ�����)
		t_elapse_ms = ((double)t_diff_pc / (double)freq.QuadPart) * Milli; //�ð��� ���(���ļ��� ����) 2

		// ���
		printf("Pow(%.3lf, %d) by iterative = %40.5lf / took time : (%3d)sec, (%5.2lf)ms\n",
			base, exponent, resultF, (int)t_diff, t_elapse_ms); 


		//���� �Լ��� ����Լ��� ���̻���� ����
		time(&t_before); QueryPerformanceCounter(&t_1);
		resultR = PowerRecursive(base, exponent, Rarray);
		time(&t_after);	QueryPerformanceCounter(&t_2);

		// �ð��� ���
		t_diff = difftime(t_before, t_after);
		t_diff_pc = t_2.QuadPart - t_1.QuadPart;
		t_elapse_ms = ((double)t_diff_pc / (double)freq.QuadPart) * Milli;
		
		// ���
		printf("Pow(%.3lf, %d) by Recursive = %40.5lf / took time : (%3d)sec, (%5.2lf)ms\n",
			base, exponent, resultR, (int)t_diff, t_elapse_ms);
	}
	free(Rarray);										// ����� �����Ҵ�� �迭�� �������� �Ҵ������� �Ѵ�.
	return 0;
}

double PowerFor(double base, int exponent) // �ݺ����� �̿��� �ŵ����� �Լ�
{
	double result = 1; //�ŵ����� ��� �ʱⰪ���� 1�� ����.
	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	} //��� base�� �����ָ鼭 �ݺ��Ѵ�.
	return result;  //��ȯ
}

double PowerRecursive(double base, int exponent, double* array) // ����Լ��� �̿��� �ŵ����� �Լ�
{
	if (exponent == 0)								// ����Լ� ��������
		return 1;

	if (array[exponent] >= 1)						// �迭�� ���� �Էµ�������
		return array[exponent];						// ���� ����� �ʿ���� ���� ��ȯ�Ѵ�.

	else
	{
		array[exponent] = base * PowerRecursive(base, exponent - 1, array);
		return array[exponent];						// ����� ��ŭ ������ ���� ��ȯ
	}
}