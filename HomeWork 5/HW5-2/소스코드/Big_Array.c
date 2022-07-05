#include "Big_Array.h"

void genBigRandArray(int* array, int SIZE)				// ���� ���� �Լ�
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
			array[count++] = bigRand;					// array�� ���� ����������, count�� ++�Ѵ�.
		}
	}
	free(flag);											// �ٳ����� �����޸� ��ȯ���� ( �ߺ� ���� üũ�ϱ� ���� ���� �迭 ) 
	suffleBigArray(array, SIZE);						// ����
}

void suffleBigArray(int* array, int SIZE)				// ���� ���� ����(����)
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


void printBigarraySample(int* array, int SIZE, int line_size, int num_sample_lines) //ū �迭 ��� �Լ�
{
	int count = 0;
	printf("Generate Big array(SIZE of % d) : \n", SIZE);
	for (int i = 0; i < num_sample_lines; i++)				 //ó�� 30�� ���
	{
		for (int j = 0; j < line_size; j++)
		{
			if (count == SIZE)
				break;
			printf("%8d", array[count]);
			count++;
		}
		printf("\n");
	}

	printf("\n . . . . . .\n");
	count = SIZE - (line_size * num_sample_lines);			// count(�迭�ε��� ��ȣ)�� �ڿ��� 30��° ��ȣ�� �ٲٱ�

	for (int i = 0; i < num_sample_lines; i++)				// ������ 30�� ���
	{
		for (int j = 0; j < line_size; j++)
		{
			printf("%8d", array[count]);
			count++;
		}
		printf("\n");
	}
	printf("\n");
}

void fprintBigarraySample(FILE* fout, int* array, int SIZE, int line_size, int num_sample_lines) // ���Ͽ� ū�Լ� ��� �Լ�
{ 
	int count = 0;

	fprintf(fout, "Generate Big array (SIZE of %d) : \n", SIZE);
	for (int i = 0; i < num_sample_lines; i++)				// ���Ͽ��ٰ� �Է� (��ó�� �迭���� 30�� ���)
	{
		for (int j = 0; j < line_size; j++)
		{
			if (count == SIZE)
				break;
			fprintf(fout, "%8d", array[count]);
			count++;
		}
		fprintf(fout, "\n");
	}

	fprintf(fout, "\n . . . . . .\n");
	count = SIZE - (line_size * num_sample_lines);			// count(�迭�ε��� ��ȣ)�� �ڿ��� 30��° ��ȣ�� �ٲٱ�

	for (int i = 0; i < num_sample_lines; i++)				// ���Ͽ��ٰ� �Է� (�ǵ��� �迭���� 30�� ���)
	{
		for (int j = 0; j < line_size; j++)
		{
			fprintf(fout, "%8d", array[count]);
			count++;
		}
		fprintf(fout, "\n");
	}
	fprintf(fout, "\n");

}