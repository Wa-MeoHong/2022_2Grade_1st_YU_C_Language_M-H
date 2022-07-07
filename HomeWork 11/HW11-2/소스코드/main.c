#include "Event.h"
#include "PriQ_E.h"

#define OUTPUT "output.txt"
#define RANDOMIZE() srand((unsigned int)time(NULL))
#define INIT_PriQ_SIZE 1

void test_PriQ_Event(FILE* fout, int max_events_P_round);	// �����Լ�

int main(void)
{
	FILE* fout = NULL;
	int max_events_P_round;

	if ((fout = fopen(OUTPUT, "w")) == NULL)				//��¿� ���� ����, ������ �޼��� ���
	{
		printf("ERROR! output.txt does not OPEN!!\n");
		exit(-1);
	}
	RANDOMIZE();											// ���� ������ ���� �õ� ����
	printf("Input Num_events per round : ");				// �� ����� �ִ� �̺�Ʈ ����
	scanf("%d", &max_events_P_round);

	test_PriQ_Event(fout, max_events_P_round);
	fclose(fout);
	return 0;
}

void test_PriQ_Event(FILE* fout, int max_events_P_round)
{
	PriQ* pPriQ_Ev = NULL;
	Event* pEv = NULL;
	Event Processed_event[N_O_EVENTS];
	int total_P_E = 0;										// processed �� �� events
	int total_G_E = 0;										// generated �� �� events
	int num_events = 0;										// �� ���� �� �̺�Ʈ ��( = max_events_P_round)
	int num_G_R = 0;										// Generated �� Round ��
	int num_P_R = 0;										// processed �� Round �� 

	fprintf(fout, "Testing Event Handling with Priority Queue\n");
	pPriQ_Ev = (PriQ*)calloc(1, sizeof(PriQ));				// malloc���� calloc�� �����ϱ� ������ �̷��� �����ߴ�.
	if (pPriQ_Ev == NULL)									// �����Ҵ��� ���� ������ ���� �޼��� ����� ����
	{
		printf("Error!! Not allocing for PriorityQueue_Event!\n");
		fclose(fout);
		exit(-1);
	}
	printf("Initializing PriorityQueue_Event of capacity (%d)\n", INIT_PriQ_SIZE);
	initPriQ_Ev(pPriQ_Ev, "PriorityQueue_Event", INIT_PriQ_SIZE);	//�ʱⰪ ����

	// enqueue�۾�
	for (int round = 0; round < MAX_ROUND; round++)			
	{
		fprintf(fout, "\n*** Start of round(%2d)...\n", round);
		num_G_R = 0;
		if (total_G_E < N_O_EVENTS)							// Generated�� �̺�Ʈ�� N_O_EVENTS( = 50)�� �ɶ�����
		{
			num_events = max_events_P_round;
			if ((total_G_E + num_events) >= N_O_EVENTS)		// ���� Generated�� �̺�Ʈ�� �̹� � ������ ���
				num_events = N_O_EVENTS - total_G_E;		// �� ���� �� ����ŭ�� Generate�Ѵ�.
			fprintf(fout, ">>> enque %2d events\n", num_events);
			for (int i = 0; i < num_events; i++)
			{
				pEv = genEvent(pEv, total_G_E, 0, N_O_EVENTS - total_G_E - 1); // �̺�Ʈ ����
				if (pEv == NULL)							//�ȵǸ� ����
				{
					printf("Error in generation of event !! \n");
					fclose(fout);
					exit(-1);
				}
				fprintf(fout, "*** enque event : ");
				fprintEvent(fout, pEv);						// ���Ͽ� ���
				enPriQ(pPriQ_Ev, pEv);						// ����Ʈ�� ť�� �߰� �� �켱���� ������
				total_G_E++;								// ������ �̺�Ʈ �� ����
				num_G_R++;									// �� ����
				fprintPriQ(fout, pPriQ_Ev);					// ���
			}
		}
		fprintf(fout, "\n===========================================================================\n");
		fprintf(fout, "\nRemoving min data from Priority Queue . . . \n");
		
		// Dequeue�۾�
		num_events = max_events_P_round;
		if ((total_P_E + num_events) > N_O_EVENTS)
			num_events = N_O_EVENTS - total_P_E;
		fprintf(fout, "<<< Dequeue %2d events\n", num_events);
		num_P_R = 0;
		for (int i = 0; i < num_events; i++)
		{
			pEv = dePriQ(pPriQ_Ev);					// dequeue�� ��, �̺�Ʈ ��ȯ���� ��
			if (pEv == NULL)						// ������ ���ٸ� ����
			{
				fprintf(fout, "   PriQ is empty\n");
				break;
			}

			fprintf(fout, " *** Dequeued Event : ");
			fprintEvent(fout, pEv);					// ���
			Processed_event[total_P_E] = *pEv;		// Processed�� �̺�Ʈ�� ���� �迭�� ����                                                               
			total_P_E++;							// dequeue�� �̺�Ʈ �� ����
			num_P_R++;								// �� ����
		}

		//Monitoring Simulation Status (�ùķ��̼� ���� ���¸� ��� )
		fprintf(fout, "Round(%2d): Generated_in_this_round(%3d), total_Generated_Events(%3d), ", round, num_G_R, total_G_E);
		fprintf(fout, "processed_in_this_round(% 3d), total_processed_events(% 3d), ", num_P_R, total_P_E);
		fprintf(fout, "events_in_queue(%3d)\n\n", pPriQ_Ev->priQ_size);

		printf("Round(%2d): Generated_in_this_round(%3d), total_Generated_Events(%3d), ", round, num_G_R, total_G_E);
		printf("processed_in_this_round(% 3d), total_processed_events(% 3d), ", num_P_R, total_P_E);
		printf("events_in_queue(%3d)\n", pPriQ_Ev->priQ_size);

		if (total_P_E >= N_O_EVENTS)
			break;
		// ���� Processe�� �����ٸ�( ��� �̺�Ʈ���� Dequeue�ߴٸ�) �ݺ��� ����
	}

	printf("Processed Events : \n");				// Dequeue���� �Ϸ��� �̺�Ʈ���� ���� ����غ���.
	for (int i = 0; i < N_O_EVENTS; i++)
	{
		printf("Ev(id: %3d, pri: %3d), ", Processed_event[i].event_no, Processed_event[i].event_pri);
		if ((i + 1) % 5 == 0)						// 5��°���� �ٹٲ��� ����
			printf("\n");
	}
	printf("\n");
	delPriQ_Ev(pPriQ_Ev);							// ���� �켱���� ť ����� �������Ƿ� �����Ҵ� ����
}