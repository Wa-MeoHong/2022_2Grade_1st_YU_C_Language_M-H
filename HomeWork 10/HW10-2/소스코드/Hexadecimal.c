#include "hexadecimal.h"

unsigned int TransperHex(char hex)				// 16������ ���ڿ��� ������ ��ȯ�ϴ� �Լ�
{
	unsigned int a = 0;

	if (hex >= '0' && hex <= '9')				// 16���� 0~9������ ���ڿ��϶�
		a = hex - '0';							// �ƽ�Ű�ڵ尪�� ����.
	else if (hex >= 'A' && hex <= 'F')			// 16���� A~F������ ���ڿ��϶�
		a = hex - 'A' + 10;						// �ƽ�Ű�ڵ尪�� ���� 10�� ����.

	return a;
}

unsigned int atox(char* hexStr)					// ���ڿ��� 16���� ������ ��ȯ�ϴ� �Լ�
{
	unsigned int a = 0;							// ��ȯ������ ���� a
	int bits = 4;								// ��Ʈ �������� ���� ���� bits (4��Ʈ�� �Ű���)

	bits = bits * (strlen(hexStr) - 1);
	// hexStr �ǿ����� ���ڿ��� �ֻ��� �Ϻ�(4bit)�̹Ƿ�, ó���� �ű� bits�� �ʱ�ȭ
	// ���� 4�ڸ��� 16������ ���Դٸ� bit shift�� 12�� ��������� hexStr[0]�� �˸°� �ڸ��� ��

	for (int i = 0; i < strlen(hexStr); i++, bits -= 4) // ���ڿ� ������ŭ ����, �������� ��Ʈ���� 4�� ����
	{
		unsigned int bitshift = 0;				// ���� ���ڿ��� ���ڸ� ��ȯ���� ����� �ӽ� ���� ����
		bitshift = TransperHex(hexStr[i]);		// ���� �Ѱ��� ���ڷ� ��ȯ
		bitshift = bitshift << bits;			// �ڸ��� �°� ��Ʈ ����Ʈ
		a |= bitshift;							// a�� bitshigt�� OR����
	}

	return a;									// ��� ���� ��, a�� ��ȯ
}

void xtoa(unsigned int hxd, char* strBuf)		// ���ڸ� 16���� ���ڿ��� ��ȯ
{
	int bits = 4;								// ��Ʈ �������� ���� ���� bits (4��Ʈ�� �Ű���)
	int bit_len = 0;							// ������ ��Ʈ ���̸� ���ϴ� ����
	unsigned int Trans;							// ���� ���ڸ� ��Ʈ����ŷ�ؼ� ����� ���� Trans
	char a = 0;									// ��ȯ�� ���ڸ� ����� ������ ����

	// ������ ��Ʈ���� ���ϱ�
	bit_len = (int)(log2((double)hxd)) + 1;		// ���� ���ڿ� log2�� ���Ѵ�, ��Ʈ���� 1���� ����ϹǷ� 1�� ���Ѵ�.

	bits = ((int)(bit_len / 4) * bits);			// ��Ʈ����ŷ �ʱⰪ�� �����Ѵ�. ��Ʈ���� 4�� ���� ��, �������� 4�� ���Ѵ�.
	if ((bit_len % 4) == 0 && bit_len != 0)		// ���� 4�� ����� �ɷȴٸ� (4, 8, 12, 16 ��)
		bits -= 4;								// ��Ʈ����ŷ�� Ƚ���� 4�� ����. (��Ʈ����ŷ �Ҷ��� ���� �ϸ� �ȵǱ⶧��)

	for (int i = 0; i < bit_len; i += 4, bits -= 4) // ������ ��Ʈ����ŭ ����, �׷��� �������� 4��( ������ 4��Ʈ�� ��ȯ�ϱ⶧��)
	{
		Trans = hxd >> bits;					// ��Ʈ����ŷ
		Trans &= 0xF;							// &�� ��ȯ�� ��Ʈ�� �� ����ش�. 0xF = 0000 0000 0000 1111
		a = TransperStr(Trans);					//���� ��ȯ
		strBuf[(int)(i / 4)] = a;
	}

	if (hxd == 0)								// 0000�� �Է��ϸ� 0�� �����µ�, 0�̸� ��ĭ�� ����ϱ⿡ ���� ó���� ���ش�.
		strBuf[0] = '0';
}

char TransperStr(unsigned int hxd)				// 16���� ���ڸ� ���ڷ� ��ȯ��Ű�� �Լ�
{
	char a = 0;

	if (hxd >= 0 && hxd <= 9)					// ���� 0~ 9���� �� ��
		a = hxd + '0';							// ����(�ƽ�Ű�ڵ�)�� ��ȯ
	else if (hxd >= 10 && hxd <= 15)			// ���� 10 ~ 15���� �� ��
		a = hxd + 'A' - 10;						// ���ڿ� 

	return a;
}
