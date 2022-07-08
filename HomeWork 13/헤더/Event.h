#ifndef EVENT_H
#define EVENT_H
#pragma warning(disable: 4996) // scanf���� �ȶ߰� �ϴ� pragma���� 

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "SimParam.h"
#include "ConsoleDisplay.h"

typedef struct Event // �̺�Ʈ ����ü
{
	// �̺�Ʈ�� ������
	int seq_no;
	int ev_gen_addr;
	int ev_han_addr;
	int ev_pri;
	LARGE_INTEGER t_gen; // �̺�Ʈ�� ������ �ð� ������
	LARGE_INTEGER t_proc; // �̺�Ʈ�� ó���� �ð� ������
	double elapsed; // ���� - ó���Ǳ���� �ð� ����
} Event;

void printEvent(Event* pEv);	// �̺�Ʈ ���
void printEvent_withTime(Event* pEvt);		// �̺�Ʈ ��� (�ð� ����)
void calc_elapsed_time(Event* pEv, LARGE_INTEGER freq); // �̺�Ʈ ���� - ó������ �ɸ� �ð�
void fprintEvent(FILE* fout, Event* pEv); // �̺�Ʈ ��� �Լ�

#endif // !EVENT_H