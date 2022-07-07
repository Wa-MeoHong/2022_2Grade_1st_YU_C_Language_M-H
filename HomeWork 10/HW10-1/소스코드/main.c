#include "word.h"

#define INPUT "words_input.txt"						// �Է� ���� 
#define OUTPUT "words_output.txt"					// ��� ����

int main(void)
{
	FILE* fin = NULL, * fout = NULL;			// ���� ������
	char words[NUM_WORDS][WORD_LENS] = { 0 };	// �迭�� �۾Ƽ� ���� �����Ҵ��� ����
	int word_len[NUM_WORDS];					// �ܾ��� ���̸� ��� ������ �迭
	int count = 0;								// �ܾ��� ������ ��

	if ((fin = fopen(INPUT, "r")) == NULL)
	{
		printf("Error! Not open words_input.txt File!!\n");
		exit(-1);
	} // �б� ���� ����

	if ((fout = fopen(OUTPUT, "w")) == NULL)
	{
		printf("Error! Not open words_output.txt File!!\n");
		exit(-1);
	} // ��� ���� ����

	while (fscanf(fin, "%s", &words[count]) != EOF)		// ������ ������ ����, words�迭�� ����
	{
		word_len[count] = strlen(words[count]);			// ���� �ܾ��� ���̸� ���� 
		count++;										// �ܾ� ���� ����
	}

	FprintWords(fout, words, word_len, count);			// �������
	SelectionSortWords(words, count);					// �ܾ� �������� ����
	for (int i = 0; i < count; i++)						// ������ �ܾ� ���
	{
		if (i == count / 2)
			fprintf(fout, "\n");
		fprintf(fout, "%-10s", words[i]);
	}
	fprintf(fout, "\n");

	printf(" Please check words_output.txt File!\n");	// Ȯ�ο�..
	fcloseall();										// ��� �۾��� ���� ��, �����ִ� ������ ��� �ݴ´�.

	return 0;

}