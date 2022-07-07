#include "Event.h"
#include "CirQ_E.h"

#define OUTPUT "output.txt"
#define RANDOMIZE() srand((unsigned int)time(NULL))

void test_FIFO_CirQ_Event(FILE* fout, int max_events_P_round);			// ���� �Լ� 

int main(void)
{
	FILE* fout = NULL;
	int max_events_P_round;

	if ((fout = fopen(OUTPUT, "w")) == NULL)		//��¿� ���� ����, ������ �޼��� ���
	{
		printf("ERROR! output.txt does not OPEN!!\n");
		exit(-1);
	}
	RANDOMIZE();									// ���� ������ ���� �õ� ����
	printf("Input Num_events per round : ");		// �� ����� �ִ� �̺�Ʈ ����
	scanf("%d", &max_events_P_round);

	test_FIFO_CirQ_Event(fout, max_events_P_round);
	fclose(fout);
	return 0;
}

void test_FIFO_CirQ_Event(FILE* fout, int max_events_P_round)
{
	CirQ* pCirQ_Event;
	Event* pEv = NULL;
	Event Processed_Events[N_O_EVENTS];

	int total_P_E = 0;									// processed �� �� events
	int total_G_E = 0;									// generated �� �� events
	int num_events = 0;									// �� ���� �� �̺�Ʈ ��( = max_events_P_round)
	int num_G_R = 0;									// Generated �� Round ��
	int num_P_R = 0;									// processed �� Round �� 

	pCirQ_Event = (CirQ*)calloc(1, sizeof(CirQ));		// ȯ�� ť ����
	fprintf(fout, "Testing Event Handling with FIFO Circular Queue\n");
	printf("Initializing FIFO CirQ of capacity (%d)\n", max_events_P_round);
	fprintf(fout, "Initializing FIFO CirQ of capacity (%d)\n", max_events_P_round);
	pCirQ_Event = initCirQ(pCirQ_Event, max_events_P_round);

	fprintf(fout, "\nEnqueuing Data into Event Circular queue: \n"); //���� �̺�Ʈ �߰����� �Ѵ�.
	for (int round = 0; round < MAX_ROUND; round++)
	{
		fprintf(fout, "Start of (%2d) ****\n", round);	// ���� ���
		if (total_G_E < N_O_EVENTS)
		{
			num_events = max_events_P_round;
			if (total_G_E + num_events > N_O_EVENTS)
				num_events = N_O_EVENTS - total_G_E;	// ���� ������ �̺�Ʈ�� �����Ѵٸ�, �� �̺�Ʈ���� ���� �������� ������
			fprintf(fout, "Generated and enque %2d events\n", num_events);
			num_G_R = 0;								// Generated�� ���� ���� �ʱ�ȭ

			for (int i = 0; i < num_events; i++)
			{
				if (isCirQFull(pCirQ_Event))			// ���� ȯ�� ť�� ��á����
				{
					fprintf(fout, "   !!! CirQ_Event is full --> SKIP Generation and Enqueueing of Event. \n");
					break;								// �� ��� �����Ѵ�.
				}

				// �̺�Ʈ�� ������
				pEv = genEvent(pEv, total_G_E, EVENT_GENERATOR, N_O_EVENTS - total_G_E - 1);
				fprintf(fout, ">>> Enqueue event = ");
				fprintEvent(fout, pEv);

				// Handling �� �̺�Ʈ �߰�(enqueue)
				enCirQ(pCirQ_Event, *pEv);				// ���� �̺�Ʈ�� enqueue(�߰�)��
				fprintCirQ(fout, pCirQ_Event);			// �̺�Ʈ1�� ���
				free(pEv);								// �Ʊ� �̺�Ʈ �����ϱ� ���ؼ� ���� �ּҸ� ��������
				total_G_E++;							// ������ �̺�Ʈ �� ����
				num_G_R++;
			}

			// Handling �� �̺�Ʈ ó���� ����(dequeue)
			fprintf(fout, "\nDequeuing Data from Event Circular queue: \n"); 
			num_events = max_events_P_round;	// ������ 50���� �����߱� ����

			if ((total_P_E + num_events) > N_O_EVENTS)
				num_events = N_O_EVENTS - total_P_E;
			//���� �Ϸ�� �̺�Ʈ�� �����Ѵٸ�, �� �̺�Ʈ���� ���� �������� ������

			// dequeue ����
			fprintf(fout, "Dequeue %2d events\n", num_events);
			num_P_R = 0;							// �۾� �Ϸ�� round ���� �ʰ�ȭ
			for (int i = 0; i < num_events; i++)	
			{
				if (isCirQEmpty(pCirQ_Event))		// ���� Dequeue�� �̺�Ʈ���� ������ �ٷ� for�� Ż��
					break;
				pEv = deCirQ(pCirQ_Event);
				if (pEv != NULL)
				{
					fprintf(fout, "<<< Dequeued event = ");		// dequeue�� �̺�Ʈ ��� 
					fprintEvent(fout, pEv);						// ���
					fprintf(fout, "\n");						//��ĭ ���
					Processed_Events[total_P_E] = *pEv;			// processed�� �̺�Ʈ �ּҸ� ��� �迭�� ����
					total_P_E++;								// Processed�� �̺�Ʈ ���� ����
					num_P_R++;									// ���� UP
				}
				fprintCirQ(fout, pCirQ_Event);
			}
		}
		//Monitoring Simulation Status (�ùķ��̼� ���� ���¸� ��� )

		fprintf(fout, "Round(%2d): Generated_in_this_round(%3d), total_Generated_Events(%3d), ", round, num_G_R, total_G_E);
		fprintf(fout, "processed_in_this_round(% 3d), total_processed_events(% 3d), ", num_P_R, total_P_E);
		fprintf(fout, "events_in_queue(%3d)\n\n", pCirQ_Event->num_elements);

		printf("Round(%2d): Generated_in_this_round(%3d), total_Generated_Events(%3d), ", round, num_G_R, total_G_E);
		printf("processed_in_this_round(%3d), total_processed_events(%3d), ", num_P_R, total_P_E);
		printf("events_in_queue(%3d)\n", pCirQ_Event->num_elements);

		if (total_P_E >= N_O_EVENTS)
			break;
		// ���� Processe�� �����ٸ�( ��� �̺�Ʈ���� Dequeue�ߴٸ�) �ݺ��� ����
	}

	printf("Processed Events : \n");							// Dequeue���� �Ϸ��� �̺�Ʈ���� ���� ����غ���.
	for (int i = 0; i < N_O_EVENTS; i++)
	{
		printf("Ev(id: %3d, pri: %3d), ", Processed_Events[i].event_no, Processed_Events[i].event_pri);
		if ((i + 1) % 5 == 0) 
			printf("\n");
	}
	printf("\n");
	delCirQ(pCirQ_Event);										// ���� ȯ�� ť ����� �������Ƿ� �����Ҵ� ����
}