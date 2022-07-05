/*
	���ϸ� : "Big_Array.c"
	���α׷��� ���� �� �⺻ ���:
		- Big_Array.c �ڵ�����
*/

#include "Big_Array.h"

void genBigRandArray(int* BigRandArray, int SIZE, int offset)
// ���� ����, (offset ~ SIZE ���� ����)
{
	char* flag = NULL;									// �ߺ��Ǵ� ���� ���� Ȯ���ϱ� ���� ������
	int count = 0;										// while �ʱ��
	unsigned int bigRand = 0;							// �ӽ����� ����

	flag = (char*)calloc(SIZE, sizeof(char));			// �߻���ų ������ŭ �����޸� �Ҵ�, ���н� �״�� ����
	if (flag == NULL)
	{
		printf("Error in Dynamic memory allocation for character array of size (%d)\n ", SIZE);
		exit(-1);
	}

	while (count < SIZE)								// �߻���ų ������ŭ
	{
		bigRand = (((unsigned int)rand() << 15) | rand()) % SIZE; //SIZE���� �۾ƾ��ϴ� ���� : �׷��� �ߺ����� ã�� �迭�� ���� ���� ���� �� ����..

		if (flag[bigRand] == 1)							//���� bigRand�� �̹� ���� ������� �ٽ� ����
		{
			continue;
		}
		else
		{
			flag[bigRand] = 1;							// �ƴϸ� üũ���ְ�
			BigRandArray[count++] = bigRand + offset;	//BigRandArray�� ��(�߻��� ���� + base)�� ����������, count�� ++�Ѵ�.
		}
	}
	free(flag);											// �ٳ����� �����޸� ��ȯ���� ( �ߺ� ���� üũ�ϱ� ���� ���� �迭 ) 
	SuffleBigArray(BigRandArray, SIZE);					// ����
}

void SuffleBigArray(int* array, int SIZE)				
// ���� ���� ����(����)
{
	int i1, i2, d, k = 0;								// ������ ������ �ε��� i1, i2, �ӽú��� d, while �ʱ�� k

	while (k < SIZE)									// k = SIZE�� �Ǳ� ����
	{
		i1 = (((unsigned int)rand() << 15) | rand()) % SIZE; // ���������� 1�� ���� 
		i2 = (((unsigned int)rand() << 15) | rand()) % SIZE; // 2�� ����

		// ������ ( ��ġ �ٲٱ� )
		d = array[i1];									// ���� �ӽ������ ���� d�� �ε��� i1���� ��� ���� ����
		array[i1] = array[i2];							// i2���� ��� ���� i1���� ����
		array[i2] = d;									// i1�� ������ �Űܴ��� d�� i2�� �ű�
		k++;											// k����
	}
}

void printBigarraySample(int* mA, int SIZE, int items_per_line, int num_sample_lines)
// �迭 ��� �Լ�(items_per_size = 10, num_sample_lines = 2)
{
	int count = 0;

	if (SIZE < Small_SIZE)										// ���� SIZE�� ���� �����
		num_sample_lines = SIZE / items_per_line + 1;			// ����� ���� num_~������ ��¿� �°� ��ģ��.
	for (int i = 0; i < num_sample_lines; i++)					// ���
	{
		for (int j = 0; j < items_per_line; j++)
		{
			if (count == SIZE)
				break;
			printf("%9d", mA[count]);
			count++;
		}
		printf("\n");
	}
	if (SIZE >= Small_SIZE)									//ū�������� �迭�̶�� �߰������� ���� ������ ó���Ѵ�.
	{
		printf("\n\t . . . . . .\n");
		count = SIZE - (items_per_line * num_sample_lines); // count(�迭�ε��� ��ȣ)�� �ڿ��� 30��° ��ȣ�� �ٲٱ�

		for (int i = 0; i < num_sample_lines; i++)			// ������ 20�� ���
		{
			for (int j = 0; j < items_per_line; j++)
			{
				printf("%9d", mA[count++]);
			}
			printf("\n");
		}
		printf("\n");
	}
}