#include "Thread.h"

using namespace std;

void Thread_EventGenerator(T_P_Ev* pParam)
{
	Event* pEv;

	// �ʱⰪ ����
	int event_no = 0;
	int event_pri = 0;
	int event_gen_count = 0;
	int myRole = pParam->myAddr;
	int myGenAddr = pParam->myAddr;
	int target_E_G = pParam->targetEventGen;
	DLL_EvQ* pEvQ;
	DLL_EvQ* priH_EvQ = pParam->EvQ_PriH;
	DLL_EvQ* priL_EvQ = pParam->EvQ_PriL;
	T_Stat* pThrdMon = pParam->pThrdMon;
	int maxround = pParam->maxRound;

	pParam->pCS_main->lock(); // �� �ɾ����
	printf("Thread_EventGenerator(%d) : targetEventGen(%d)\n", myGenAddr, target_E_G);
	pParam->pCS_main->unlock(); // �� ����

	for (int round = 0; round < maxround; round++)
	{
		if (event_gen_count < target_E_G)
		{
			// �̺�Ʈ ���� �� enqueue�� ���ش�.
			pEv = (Event*)calloc(1, sizeof(Event));
			pEv->ev_gen_addr = myGenAddr;
			pEv->seq_no = event_no = event_gen_count + (NUM_EV_PER_GEN * myGenAddr);
			pEv->ev_pri = event_pri = rand() % NUM_PRIORITY;
			pEv->ev_han_addr = -1; // �� �̺�Ʈ�� ���� �ڵ鸵 ���� ����
			QueryPerformanceCounter(&pEv->t_gen); // ������ �ð� ����
			pEvQ = (event_pri < PRIORITY_THRESHOLD) ? priH_EvQ : priL_EvQ;
			while (enEventQ(pEvQ, pEv) == NULL) // enqueue �۾�
			{
				Sleep(100);
			}

			pParam->pCS_thrd_mon->lock(); // ������ ��
			// ������ �̺�Ʈ�� ��Ͽ� �迭�� �������
			pThrdMon->eventGen[myGenAddr]++;
			pThrdMon->ev_Generated[pThrdMon->total_G_E] = *pEv;
			pThrdMon->total_G_E++;
			pParam->pCS_thrd_mon->unlock(); // ������ ���
			event_gen_count++;
		}

		else
		{
			if (*(pThrdMon->pFlagThreadTerminated) == TERMINATE)
				break; //�����尡 ��������̸� for���� Ż���Ѵ�.
		}
		Sleep(100 + rand() % 100); // ������ �ش�.
	}
}

void Thread_EventHandler(T_P_Ev* pParam)
{
	// �ʱⰪ ����
	int myRole = pParam->myAddr;
	int myProcAddr = pParam->myAddr;
	Event* pEv;
	DLL_EvQ* priH_EvQ = pParam->EvQ_PriH;
	DLL_EvQ* priL_EvQ = pParam->EvQ_PriL;
	T_Stat* pThrdMon = pParam->pThrdMon;
	int maxround = pParam->maxRound;
	Event* evProc = pParam->pThrdMon->ev_Processed;
	int target_E_G = pParam->targetEventGen;
	LARGE_INTEGER freq = pParam->freq; // �Ʊ� �� Ŭ���� ������

	pParam->pCS_main->lock(); // �� �ɾ����
	printf("Thread_EventHandler(%d) : targetEventGen(%d)\n", myProcAddr, target_E_G);
	pParam->pCS_main->unlock(); // �� ����

	for (int round = 0; round < maxround; round++)
	{
		if (*(pThrdMon->pFlagThreadTerminated) == TERMINATE)
			break; //�����尡 ��������̸� for���� Ż���Ѵ�.

		while ((pEv = deEventQ(priH_EvQ)) != NULL) // �켱������ ���� ť���� ����
		{
			pParam->pCS_thrd_mon->lock();
			pEv->ev_han_addr = myProcAddr;
			QueryPerformanceCounter(&pEv->t_proc);
			calc_elapsed_time(pEv, freq);
			pThrdMon->ev_Processed[pThrdMon->total_P_E] = *pEv;
			pThrdMon->eventProc[myProcAddr]++;
			pThrdMon->total_P_E++;
			pThrdMon->num_P_E_H++;
			free(pEv); // ó���� �̺�Ʈ�� �����ȴ�. (���� �迭�� ����Ǿ������Ƿ� ������)
			pParam->pCS_thrd_mon->unlock();
			Sleep(100 + rand() % 200); // ���� ��(������ �ð� ���߱�)
		}
		if ((pEv = deEventQ(priL_EvQ)) != NULL) // �켱������ ���� ť���� ����
		{
			pParam->pCS_thrd_mon->lock();
			pEv->ev_han_addr = myProcAddr;
			QueryPerformanceCounter(&pEv->t_proc);
			calc_elapsed_time(pEv, freq);
			pThrdMon->ev_Processed[pThrdMon->total_P_E] = *pEv;
			pThrdMon->eventProc[myProcAddr]++;
			pThrdMon->total_P_E++;
			pThrdMon->num_P_E_L++;
			free(pEv); // ó���� �̺�Ʈ�� �����ȴ�. (���� �迭�� ����Ǿ������Ƿ� ������)
			pParam->pCS_thrd_mon->unlock();
		}
		Sleep(100 + rand() % 200); // ���� ��(������ �ð� ���߱�)
	}
}