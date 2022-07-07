/*
*���ϸ� : "HW11-2_21912193_�Ŵ�ȫ"
*���α׷��� ���� �� �⺻ ���:
*      - �켱���� ť�� �����ϰ�, �̺�Ʈ�� �߰�, ������ �ϸ� ������� �޸𸮰� �����Ǵ��� Ȯ���غ��� ���α׷�
*
*���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 5�� 20��)
*���� Update : Version 1.0.0, 2022�� 5�� 20��(�Ŵ�ȫ)
*============================================================================
*���α׷� ����/���� �̷�
*============================================================================
*������			������			����			����/���ϳ���
*----------------------------------------------------------------------------
*�Ŵ�ȫ		 2022/05/20			v1.0.0		�����ۼ�
*============================================================================
*/

#ifndef PRIQ_E_H
#define PRIQ_E_H

#include "Event.h"
#include <string.h>

#define POS_ROOT 1								// �ֿ켱 ���
#define MAX_NAME_LEN 80

// �̺�Ʈ1���� ��� ����ü
typedef struct CBTN_Event {
	int priority;
	Event* pEv;
} CBTN_Event;

// �켱���� ť ����ü
typedef struct PriorityQueue {
	char PriQ_Name[MAX_NAME_LEN];
	int priQ_capacity;
	int priQ_size;
	int pos_last;
	CBTN_Event* pCBT_Ev;
} PriQ; 

bool hasLeftChild(int pos, PriQ* pPriQ_Ev);				// �θ��尡 ���� �ڽĳ�带 ������ �ִ°�?
bool hasRightChild(int pos, PriQ* pPriQ_Ev);			// �θ��尡 ������ �ڽĳ�带 ������ �ִ°�?
PriQ* initPriQ_Ev(PriQ* pPriQ_Ev, char* name, int capacity); //PriQ �ʱⰪ ����
void delPriQ_Ev(PriQ* pPriQ_Ev);						//�����Ҵ� ���� �Լ� 
void enPriQ(PriQ* pPriQ_Ev, Event* pEv);				// ��� �߰� �Լ�
Event* dePriQ(PriQ* pPriQ_Ev);							// �ֻ��� ��� ���� �Լ�
void fprintPriQ(FILE* fout, PriQ* pPriQ_Ev);			// ���� ��� �Լ�

#endif // !PRIQ_E_H