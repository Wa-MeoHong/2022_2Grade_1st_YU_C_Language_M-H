#include "hexadecimal.h"

int main(void)
{
	char* hexStr;							// ���ڷ� ��ȯ�� ���ڿ� �Է�
	char* hexConvertStr;					// ��ȯ�� ���ڸ� �ٽ� ���ڿ��� ��ȯ�Ͽ� ����� ���ڿ�
	unsigned int value_int;					// ��ȯ�� ���ڸ� ��� ����
	while (1)
	{
		hexStr = (char*)calloc(MAX_HEX_STR_LEN + 1, sizeof(char));			// �����Ҵ�
		hexConvertStr = (char*)calloc(MAX_HEX_STR_LEN + 1, sizeof(char));	// �����Ҵ�

		// ��ȯ�� 16���� ���ڿ� �Է�
		printf("input hexadecimal number : ");								
		scanf("%s", hexStr);
		if (strcmp(hexStr, ".") == 0)									// ���� '.'�� �Է��ϸ� ����
			break;

		value_int = atox(hexStr);										// ���ں�ȯ
		printf("hexadecimal (%s) = %d (decimal)\n", hexStr, value_int); // ��� 1
		xtoa(value_int, hexConvertStr);									// ��ȯ�� ���ڸ� �ٽ� ���ڿ��� ��ȯ
		printf("hexadecimal (%s) = %d (decimal) = %#0X (hexadecimal) = re-converted hexadecimal string(%s)\n", \
			hexStr, value_int, value_int, hexConvertStr);				//��� 2

		// �����Ҵ� ����
		free(hexStr);
		free(hexConvertStr);
	}
	return 0;
}