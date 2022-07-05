#include "Draw_Shape.h"
#define Space 1

void draw_rectangle(int width, int length)				//���簢�� �����
{
	for (int i = 0; i < width; i++)						// ���� �𼭸� ǥ��
	{
		printf("* ");									// 1ĭ�� ���� ���� : ���� �𼭸��� ���߱� ����
	}
	printf("\n");
	for (int j = Space; j <= length - Space; j++)		// ���θ𼭸� ǥ��
	{
		printf("* ");									// �糡�ʸ� ��ǥ���ϰ� �������� ĭ����
		for (int k = Space; k < width - Space; k++)		// ���ʳ��� ��ǥ�û���(-2) ���� ��ĭ 
		{
			printf("  ");
		}
		printf("*\n");
	}
	for (int i = 0; i < width; i++)						// �� �Ʒ��� ǥ��
		printf("* ");
	printf("\n");
}

void draw_right_triangle(int base)						// �����ﰢ�� �׸���
{
	printf("\n");
	for (int i = 0; i < base; i++)						// �Ʒ��� ������
	{
		for (int j = 0; j <= i; j++)					//����, ���������� 1ĭ�� �ø��鼭 �׸�
			printf("*");
		printf("\n");
	}
}

void draw_reverse_right_triangle(int base)				// �밢�������� �����ﰢ��
{
	for (int i = 0; i < base; i++)						// �Ʒ��� ������
	{
		for (int j = 0; j < i; j++)						// �Ʒ��� �������鼭 ��ĭ ������ �ø�
		{
			printf(" ");
		}
		for (int k = 0; k < base - i; k++)				//��ĭ ����� �����, ������ �� ��� �������鼭 ��°��� ������
		{
			printf("*"); 
		}
		printf("\n");
	}
}


void draw_diamond(int width)							//�پƾƸ��(������)
{	
	//���κ� �����
	for (int i = 1; i <= (width + Space) / 2; i++)	// ���κ��� ������� ���Խ�Ű�� 
	{	
		for (int j = (width + Space) / 2; j > i; j--)
		{
			printf(" ");
		}
		for (int k = 0; k < (i * 2 - 1); k++)
		{
			printf("*");
		}
		printf("\n");
	}

	//�Ʒ��κ� �����
	for (int i = (width - Space) / 2; i >= 0; i--)  //�Ʒ��κ��� ���κп��� ���� �� ��κ��� �����ϹǷ� -1���� ������ ����
	{
		for (int j = i; j < (width - Space) / 2 + Space; j++)	//�����ΰ����� ��ĭ ���� ������
		{
			printf(" ");
		}
		for (int k = 0; k < (i * 2 - 1); k++)					//������ �� �پ��
		{
			printf("*");
		}
		printf("\n");
	}
}