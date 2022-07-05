/*
  ���ϸ� : "HW4-1_21912193_�Ŵ�ȫ"

  ���α׷��� ���� �� �⺻ ���:
	- ���� Rand()�Լ����� �� �� �ִ� ���������� �� ���� ������ �������� �߻���Ų��
	�װ� �����޸��Ҵ��� ���� �迭�� �޾� ���� ��½�Ű�� ���α׷�

  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 3�� 24��)
  ���� Update : Version 1.1.0, 2022�� 3�� 25��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������		   ������		 ����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
   �Ŵ�ȫ		 2022/03/24		v1.0.0		  �����ۼ�
   �Ŵ�ȫ		 2022/03/25		v1.1.0		  �����迭 flag��ȯ ��� �߰�
===========================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>										// rand()�Լ��� ����ϱ� ���� �������
#include <time.h>										// time()�� ����ϱ� ���� �������

#define RANDOMIZE() srand((unsigned int)time(NULL))		// �ð��� ���� �õ带 define���� ��ũ�θ� ����
#define LINE_SIZE 10									// �⺻ ǥ�� �� ��.

void BigRandArray(int* array, int SIZE);				// ������ Rand() (0~32767)�� �Ѿ�� ������ ����� �Լ�
void PrintArray(int* array, int SIZE, int line_size);	// ���� ����Լ�

int main(void)
{
	int* array = NULL;								// ������(�迭)�� ���� ���� �� �ʱ�ȭ

	RANDOMIZE();									// �õ� ����
	for (int size = 200000; size <= 1000000; size += 200000) // 20������ ���� �����ؼ� +20������ �÷���
	{
		array = (int*)calloc(size, sizeof(int));	// ���� �޸� �Ҵ����(���� �迭�ּҿ� ���� ����), ���н� �ٷ� ����
		if (array == NULL)
		{
			printf("Error in Dynamic memory allocation for integer array of size (%d)\n\n ", size);
			exit(-1);								// ����
		}

		BigRandArray(array, size);					// �����߻��� array�迭�� ����
		PrintArray(array, size, LINE_SIZE);			// ���� ����Լ�
	}
	free(array);									//���� �޸� ��ȯ (array�� �������� �Ҵ�޾����Ƿ� �� ������ �ؾߵ�)
	return 0;
}

void BigRandArray(int* array, int SIZE)
// �ߺ����� ���� �������� �����ϴ� �Լ�
{
	char* flag = NULL;							// �ߺ��Ǵ� ���� ���� Ȯ���ϱ� ���� ������
	int count = 0;								// while �ʱ�� ����
	unsigned int bigRand = 0;					// �ӽ����� ���� 

	flag = (char*)calloc(SIZE, sizeof(char));	// �߻���ų ������ŭ �����޸� �Ҵ� (���н� �ٷ� ����)
	if (flag == NULL)
	{	
		printf("Error in Dynamic memory allocation for character array of size (%d)\n ", SIZE);
		exit(-1);
	} 

	while (count < SIZE)						//�߻���ų ������ŭ
	{
		bigRand = (((long)rand() << 15) | (long)rand()) % SIZE;
		//SIZE���� �۾ƾ��ϴ� ���� : �׷��� �ߺ����� ã�� �迭�� ���� ���� ���� �� ����..

		if (flag[bigRand] == 1)				//���� bigRand�� �̹� ���� ������� 
		{
			continue;						// �ٽý��� ( ���� �ٽ� ���� )
		} 
		else
		{
			flag[bigRand] = 1;				// �ƴϸ� üũ���ְ�
			array[count++] = bigRand;		// array�� ���� ����������, count�� ++�Ѵ�.
		}
	}
	free(flag);								//�ٳ����� �����޸� ��ȯ���� ( �ߺ� ���� üũ�ϱ� ���� �ӽ� �迭)
}

void PrintArray(int* array, int SIZE, int line_size)
// ���
{
	printf("Testing Generation of dynamic array of random numbers (size : %d)\n", SIZE);
	for (int i = 0; i < 3; i++)							//ó�� 30�� ����
	{
		for (int j = 0; j < line_size; j++, array++)	// 10�� ���
		{
			printf("%8d", *(array));
		}
		printf("\n");
	}
	printf(" . . . . . .\n");

	for (int i = 0; i < 3; i++)							//������ 30�� ���� ���
	{
		for (int j = 0; j < line_size; j++, array++)
		{
			printf("%8d", *(array + SIZE - 61));		//���� 30�� ���� +�߱⶧���� SIZE�� ������ ������ 30���� ����ϱ� ����
			//61���� ���ش�.
		}
		printf("\n");
	}
	printf("\n");
}

// ��� �׳� �����Ҵ縸 �س���, ���ڸ� 1���� SIZE���� ������ �迭�� �����ϰ� �����ִ� �Լ� ���� ��.
// suffle�ϴ� ����� �迭 swap�ϴ� �Լ��� �����ϴ� ��.