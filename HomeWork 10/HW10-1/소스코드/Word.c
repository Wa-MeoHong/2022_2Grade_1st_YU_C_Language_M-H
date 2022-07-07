#include "word.h"

void FprintWords(FILE* fout, char words[][WORD_LENS], int* word_len, int num_words)		// ��������Լ�
{
	fprintf(fout, "Input words list : \n");

	for (int i = 0; i < num_words; i++)													// �ݺ����� ���� ���
	{
		fprintf(fout, "(%2d)th-words : %-10s (word_length: %d)\n", i + 1, words[i], word_len[i]);
		// 1��°���� 10��°���� ���, %-15s : 15�ڸ���ŭ ���������ؼ� ���
	}
	fprintf(fout, "\n"); 
}

void SelectionSortWords(char words[][WORD_LENS], int num_words)				// �ܾ� ���� ���� �Լ�
{
	char temp[WORD_LENS] = { 0 };											// �ܾ �ٲٱ� ���� �ӽ� ���ڿ� �迭
	int sort_IDX = 0, min_IDX = 0;											// ���� ���� �ε���, �ּҰ� �ε���

	while (1)
	{
		if (sort_IDX == num_words)											//���� ���� �ε����� �ܾ��� ������ŭ �ߴٸ� ����
			break;
		strcpy(temp, words[sort_IDX]);										// ���� ���� �ε����� �ִ� �ܾ ����
		min_IDX = sort_IDX;													// �ּҰ� �ε��� �ʱⰪ ����

		for (int i = sort_IDX + 1; i < num_words; i++)						// ���� �����ε��� + 1���� �ܾ�迭 ������
		{
			if (strcmp(temp, words[i]) == 1)								// ���� �ܾ temp���� ũ�ٸ�( �ƽ�Ű�ڵ� ���� )
			{
				strcpy(temp, words[i]);										// �ּҰ� �ܾ� ����
				min_IDX = i;												// �ּҰ� �ε��� ����
			}
		}

		//�� �ٲٱ�
		strcpy(words[min_IDX], words[sort_IDX]);
		strcpy(words[sort_IDX], temp);
		sort_IDX++; // ���� �ε��� ����
	}
}