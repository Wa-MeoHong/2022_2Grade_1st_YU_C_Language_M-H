#include "draw_shape.h"
#include <windows.h>
#include <conio.h>

int main(void)
{
	int choose; // ������ ����
	int width, length; // ����, ����
	int base; // �غ�(���̵� ���̾�)

	while (1)
	{
		printf("����� ���� ������ �����Ͻÿ�. (1 : rectangle, 2 : right triangle \
3 : reverse triangle, 4 : diamond, 0 : END) : ");	// ������ 
		scanf("%d", &choose);						//choose ������ �� �Է�

		if (choose == 0)							// 0�϶� ����
			break;

		switch (choose)								// ���ÿ� ���� 
		{
			case 1:									// ���簢�� �����
			{	
				printf("Rectangle / width, length : ");
				scanf("%d %d", &width, &length);
				draw_rectangle(width, length);
				break; 
			}

			case 2:									// �����ﰢ�� �����
			{	
				printf("Right_Triangle / base : ");
				scanf("%d", &base);
				draw_right_triangle(base);
				break; 
			}

			case 3:									//�� �����ﰢ�� �����
			{	
				printf("Reverse Right_Triangle / base : ");
				scanf("%d", &base);
				draw_reverse_right_triangle(base);
				break;
			}

			case 4:									//���̾Ƹ�� �����
			{
				printf("Diamond / width : ");
				scanf("%d", &width);
				draw_diamond(width);
				break; 
			}

			default:								//�ٸ��� �Է½� �ٽ��Է��ϵ��� �ϰ���
			{	
				printf("wrong choose! input again!\n");
				_getch(); 
				system("cls");
				continue;
			}
		}
		printf("\n Printing Complete! Press Any Key to back!");
		_getch();
		system("cls");
	}
	return 0;
}