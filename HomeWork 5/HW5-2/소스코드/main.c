#include "Big_Array.h"

int main(void)
{
	FILE* fout = NULL;							// ���������� fout
	int* array = NULL;							// Bigarray������ �迭 
	int SIZE = 0;								// �迭ũ�� SIZE

	if ((fout = fopen(OUT_DATA, "w")) == NULL)	// ������� ���� ����, ���� ���ϸ� �״�� ����
	{
		printf("Error in creation of %s !! \n", OUT_DATA);
		exit(-1);
	}

	printf("Input size of big array : ");				// ������ �Է� 
	scanf("%d", &SIZE);
	array = (int*)calloc(SIZE, sizeof(int));			// �����Ҵ�

	genBigRandArray(array, SIZE);						// ���� �߻� �� �迭�� ����
	printBigarraySample(array, SIZE, LINE_SIZE, NUM_OF_LINES);			// ��� �Լ�
	fprintBigarraySample(fout, array, SIZE, LINE_SIZE, NUM_OF_LINES);	// ���Ͽ� ����ϴ� �Լ�
	free(array);								// �����Ҵ��� array ����
}