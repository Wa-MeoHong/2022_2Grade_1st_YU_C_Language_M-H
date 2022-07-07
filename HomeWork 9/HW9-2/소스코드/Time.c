#include "Time.h"

Time InputTime()								// �ð� �Է� �Լ�
{
	Time input;									// �Է°� ���� ����

	// �Է�
	printf("Input hour, minute, second : ");
	scanf("%d %d %d", &input.hour, &input.min, &input.sec); 
	
	// �Է¹��� �ð��� �ʷ� ȯ��
	input.Allsecs = (input.hour) * 60 * 60 + (input.min) * 60 + input.sec;
	
	return input;								// �� ��ȯ
}

void printTime(Time* t)							// �ð� ��� �Լ� (�⺻��), ��� ���� : "(��:��:��)"
{
	printf("(%02d:%02d:%02d)", t->hour, t->min, t->sec);
}

void printTimes(Time* times, int SIZE)			// �ð� �迭 ��� �Լ�
{
	for (int i = 0; i < SIZE; i++)				// ������ ������ŭ
	{
		//��� ���� : "time[i] = (��:��:��)"
		printf("times[%d] = ", i); printTime(&times[i]); 
		printf("\n");
	}
	printf("\n"); 
}

void incrementTime(Time* t, int incr_sec)				//�ð� �������� �� �ð� ���
{
	t->Allsecs += incr_sec;								// ����ʿ��� ������Ŵ

	t->sec = t->Allsecs % 60;							// ��� �ʿ��� 60�� �������� �� ������ = ��
	t->min = (t->Allsecs / 60) % 60;					// ��� �ʿ��� 60�� ���� ��, �� ������ 60�� �������� �� ������ = ��
	t->hour = (t->Allsecs / 3600);						// ��� �ʿ��� 60 * 60�� �������� �� ���� �� = ��

	// ���� 24�ø� �Ѱ����� �ð��� 24�� ���־� 0�ú��� �����ϰ���
	if (t->hour >= 24) 
	{
		t->hour -= 24;
	}

	// ����ü �ڷ����� �����͸� �����ͷ� �����ͼ� ���� ��ȯ�� ���� ����.
}

int compareTime(const Time* ptr1, const Time* ptr2)			// �ð��� �� �Լ�
{
	return (ptr1->Allsecs - ptr2->Allsecs);					// ���� ��ȯ (�츮�� ���� ���� ���, 0, ������ �ʿ�� �Ѵ�)
}

void SSTime(Time* times, int SIZE)							// �������� �Լ�
{
	Time temp;												// �ִ밪(��ü�� ��)
	int min_index = 0;										// �ּҰ� �ε��� ��ȣ
	int sort_index = 0;										// ������ ���� ���� �ε��� ��ȣ(�� �ε��� ������ ������ �����ʰ͵鿡�� �ִ밪 ã��) 

	for (int i = 0; i < SIZE; i++)
		times[i].Allsecs = (times[i].hour) * 60 * 60 + (times[i].min) * 60 + times[i].sec;
		// �迭�� ��ҵ��� �հ��ʸ� ������ (��ȯ�� �ڷ�� �迭�ȿ� ���⶧���� ����, �ð� ũ��񱳸� ���ؼ�)

	// ��������
	while (1)												
	{
		if (sort_index == SIZE)								// ���� ���� ���� �ε��� ���� �迭�� ������ ����� ����
			break;
		temp = times[sort_index];							// �ּҰ�(��ü��) �ʱⰪ ����
		min_index = sort_index;								// �ּҰ� �ε��� �ʱⰪ ����

		for (int j = sort_index; j < SIZE; j++)
		{
			if (compareTime(&temp, &times[j]) > 0)			// ���� temp�� �� ũ�ٸ�
			{
				temp = times[j];							// �ּҰ�(�ٲܰ�)����
				min_index = j;								// �ε��� ��ȣ ����
			}
		}

		// swap
		times[min_index] = times[sort_index];
		times[sort_index] = temp;
		sort_index++;
	}
}