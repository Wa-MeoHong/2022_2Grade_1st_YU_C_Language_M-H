/*
  ���ϸ� : "HW3-1_21912193_�Ŵ�ȫ	"
  ���α׷��� ���� �� �⺻ ���:
	- ASCII code�� �Է¹ް�, �� ASCII code�� ��������, ��������, ����, ����, ��ȣ���� �Ǻ��ϴ� ���α׷�

  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 3�� 20��)
  ���� Update : Version 1.1.0, 2022�� 3�� 21��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������		   ������		 ����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
   �Ŵ�ȫ		 2022/03/20		v1.0.0		  �����ۼ�
   �Ŵ�ȫ		 2022/03/21		v1.5.0		  Enter�Է½� �ٽ� �Է��ϵ��� �߰�

===========================================================================================================
*/

#include <stdio.h>
#include <conio.h>										// getch()�� �Է��ϱ� ���� ���̺귯��

#define CR 0x0D											// CR = \r(ù�ٷ� ���ư���)
#define LF 0x0A											// LF = \n(�ٹٲ�)
#define ESC 0x1B										// ESC

void judge(char cht);									// ������ ����, ���� �Ǵ� �Լ�

int main(void)
{
	char cht = 0;
	while (1)
	{
		printf("\nInput a character : ");
		cht = _getch();									// ���� �Է�, ����Ű �ϳ��� �ν���, ���۰� ����

		if (cht == CR || cht == LF)						// CR = \r(ù�ٷ� ���ư���), LF = \n(�ٹٲ�)
			continue;									// �ٽ� �Է�
		else
		{
			if (cht == ESC)								// ESC �Է½� ��
			{
				printf("close...\n");
				break;
			}
			else
			{
				if (cht >= 'A' && cht <= 'Z')			//�빮�� ���ĺ�
				{
					printf("%c\n => alphabet upper-case, ", cht);
					judge(cht);
				}
				else if (cht >= 'a' && cht <= 'z')		//�ҹ��� ���ĺ�
				{
					printf("%c\n => alphabet lower-case, ", cht);
					judge(cht);
				}
				else if (cht >= 0x30 && cht <= 0x39)	// ����
					printf("%c\n => decimal number.\n", cht);
				else									//��ξƴϸ� ��ȣ
					printf("%c\n => symbol (not decimal number, not alphabet)\n", cht); 
			}
		}
	}
	return 0;
}

void judge(char cht)									// ���������� �ƴ��� �Ǵ���
{
	switch (cht)
	{													// �빮��, �ҹ��� a, e, i, o, u (����)
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		printf("vowel\n"); break;						// ���� ���

	default:
		printf("consonanat\n"); break; 					// ���� ���
	}
}