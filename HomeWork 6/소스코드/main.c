/*
	���ϸ� : "main.c"
	���α׷��� ���� �� �⺻ ���:
		- main.c �ڵ�����
*/

#include "Big_Array.h"
#include "Big_Array_Sort.h"
#include <conio.h>

void Compare_Sorting_Algorithms_SmallIntArray();				// ���� ���� ���� �迭�� ���� �޴�
void Compare_Sorting_Algorithms_BigIntArray();					// ū ���� ���� �迭�� ���� �޴�

int main(void)
{
	int menu;

	while (1)
	{
		printf("\nTest Array Algorithms   \n");
		printf("	1: Performance Comparison of Selection Sort and Quick Sort for \
Small Integer Array\n");
		printf("	2: Performance Comparison of Selection Sort and Quick Sort for \
BIG Integer Array\n");
		printf("Input menu (0 is exit): ");
		scanf("%d", &menu);										// �޴� �Է�

		if (menu == 0)											// 0�Է½� while ����
			break;
		switch (menu)											// �Է¿� ���� ���� �Լ� �޶�����.
		{
		case 1:
			Compare_Sorting_Algorithms_SmallIntArray();
			break;
		case 2:
			Compare_Sorting_Algorithms_BigIntArray();
			break;
		default:
			printf("\n\tWrong input! Please input again!");
			_getch();
			system("cls");
			continue;
		}
		printf("\n\tSorting is Complete! Press Any Key!");
		_getch();
		system("cls");
	}
	printf("\n\t\tClose Progarm..\n");
	return 0;
}

void Compare_Sorting_Algorithms_SmallIntArray() //���� ���� �迭 ���� ���� 
{
	int* array;
	int size, base = 0;
	LARGE_INTEGER freq, t_1, t_2;
	double t_diff;								//�ð� �� ���

	double t_Selection, t_Merge, t_Quick;

	QueryPerformanceFrequency(&freq);
	// CPU�� Ŭ������ ����, Ŭ������ ���� ���ϴ� ���� �ƴϹǷ� �ѹ��� ����

	printf("\nCompare the performance of sorting algorithms for small array\n");
	printf("====================================================================\n");
	printf(" Array size	QuickSort[��s]	MergeSort[��s]	SelectionSort[��s]\n");
	printf("--------------------------------------------------------------------\n");

	for (size = 10; size <= 100; size += 10)
	{
		array = (int*)calloc(size, sizeof(int));
		if (array == NULL)
		{
			printf("Error in creation of array (size = %d)!\n", size);
			exit(1);
		}
		genBigRandArray(array, size, base);
		// ���� ���� ����

		QueryPerformanceCounter(&t_1);						// �ð����(�Լ�������)
		_QUICKSORT(array, size);							// ������
		QueryPerformanceCounter(&t_2);						// �ð����(�Լ���)
		t_diff = t_2.QuadPart - t_1.QuadPart;
		t_Quick = ((double)t_diff / (double)freq.QuadPart) * Micro; //��s���� ��ȯ
		SuffleBigArray(array, size);
		// �ٽ� �����ش�.

		QueryPerformanceCounter(&t_1);						// �ð����(�Լ�������)
		mergeSort(array, size);								// ��������
		QueryPerformanceCounter(&t_2);						// �ð����(�Լ���)
		t_diff = t_2.QuadPart - t_1.QuadPart;
		t_Merge = ((double)t_diff / (double)freq.QuadPart) * Micro; //��s���� ��ȯ
		SuffleBigArray(array, size);
		// �ٽ� �����ش�.

		QueryPerformanceCounter(&t_1);						// �ð����(�Լ�������)
		selectionSort(array, size, 0, size - 1);			// ��������
		QueryPerformanceCounter(&t_2);						// �ð����(�Լ���)
		t_diff = t_2.QuadPart - t_1.QuadPart;
		t_Selection = ((double)t_diff / (double)freq.QuadPart) * Micro; //��s���� ��ȯ
		printf("%10d\t%11.2lf\t%11.2lf\t%14.2lf\n", size, t_Quick, t_Merge, t_Selection);

		free(array);
	}
}

void Compare_Sorting_Algorithms_BigIntArray()				// ���� ���� ���� �ð� ���� �Լ�
{
	int* array;
	int size, base = 0;
	int pow_num = 0;
	LARGE_INTEGER freq, t_1, t_2;
	double t_diff;											// �ð� �� ���

	double t_Selection, t_Merge, t_Quick;

	QueryPerformanceFrequency(&freq);
	// CPU�� Ŭ������ ����, Ŭ������ ���� ���ϴ� ���� �ƴϹǷ� �ѹ��� ����

	printf("\nCompare the performance of sorting algorithms for small array\n");
	printf("====================================================================\n");
	printf(" Array size	QuickSort[ms]	MergeSort[ms]	SelectionSort[ms]\n");
	printf("--------------------------------------------------------------------\n");

	while (1)
	{
		size = BIG_SIZE * (int)pow(2, pow_num);

		if (size >= StopSort)
			break;
		array = (int*)calloc(size, sizeof(int));
		if (array == NULL)
		{
			printf("Error in creation of array (size = %d)!\n", size);
			exit(1);
		}
		genBigRandArray(array, size, base);
		// ���� ���� ����

		QueryPerformanceCounter(&t_1);						// �ð����(�Լ�������)
		_QUICKSORT(array, size);							// ������
		QueryPerformanceCounter(&t_2);						// �ð����(�Լ���)
		t_diff = t_2.QuadPart - t_1.QuadPart;
		t_Quick = ((double)t_diff / (double)freq.QuadPart) * Milli; // ms���� ��ȯ
		SuffleBigArray(array, size);
		// �ٽ� �����ش�.

		QueryPerformanceCounter(&t_1);						// �ð����(�Լ�������)
		mergeSort(array, size);								// ��������
		QueryPerformanceCounter(&t_2);						// �ð����(�Լ���)
		t_diff = t_2.QuadPart - t_1.QuadPart;
		t_Merge = ((double)t_diff / (double)freq.QuadPart) * Milli; // ms���� ��ȯ
		SuffleBigArray(array, size);
		// �ٽ� �����ش�.

		if (size < SELECTION_SORT_THRESHOLD)				// 5���� �̻��϶��� ���������� ���� �ʵ��� if-else ����
		{
			QueryPerformanceCounter(&t_1);					// �ð����(�Լ�������)
			selectionSort(array, size, 0, size - 1);		// ��������
			QueryPerformanceCounter(&t_2);					// �ð����(�Լ���)
			t_diff = t_2.QuadPart - t_1.QuadPart;
			t_Selection = ((double)t_diff / (double)freq.QuadPart) * Milli; // ms���� ��ȯ
			printf("%10d\t%11.2lf\t%11.2lf\t%14.2lf\n", size, t_Quick, t_Merge, t_Selection);
		}
		else
			printf("%10d\t%11.2lf\t%11.2lf\t\t-\n", size, t_Quick, t_Merge);
		pow_num += 1;
		free(array);
	}
	printf("====================================================================\n");
}