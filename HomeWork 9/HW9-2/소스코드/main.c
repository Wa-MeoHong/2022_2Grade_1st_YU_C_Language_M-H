#include "Time.h"

int main(void)
{
	Time t1, t2;							// �ð� �Է� ����
	Time times[NUM_Time] = { {23, 59, 59}, {9, 0, 5}, {13, 30, 0}, {3, 59, 59}, {0, 0 ,0} };
	// �ð� �迭 �ʱⰪ 
	int incr_secs, diff_sec;

	// 1. t1, t2�� �Է¹ް�, t2�� ������Ų��, t1�� t2������ �ð����� ����
	t1 = t2 = InputTime();					// �ð��� �Է¹��� ��, t1, t2�� ����
	printf("Input time t1 = "); printTime(&t1); printf("\n");
	printf("Input seconds to increment : ");
	scanf("%d", &incr_secs);				// ��ȭ ��ų �ʸ� �Է�
	incrementTime(&t2, incr_secs);			//t2�� ��ȭ��Ų��.
	printf("After incrementing %d secs, t2 = ", incr_secs); printTime(&t2); printf("\n"); // t2���
	diff_sec = compareTime(&t1, &t2);		// t1, t2�� ���̸� �������
	printf("Difference between t1 and t2 is %d secs\n", abs(diff_sec)); //�ð����� ���

	// 2. �迭�� ���� ���������� �� ���
	printf("\nBefore sorting times : \n");				//�ð� �迭 ���� �� ���
	printTimes(times, NUM_Time);
	SSTime(times, NUM_Time);							//�ð� �迭 ����
	printf("After selection sorting of times : \n");	//�ð� �迭 ���� �� ���
	printTimes(times, NUM_Time);

	return 0;
}