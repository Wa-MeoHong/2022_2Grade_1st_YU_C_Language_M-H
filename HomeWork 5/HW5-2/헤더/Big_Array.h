/*
  ���ϸ� : "HW5-2_21912193_�Ŵ�ȫ"

  ���α׷��� ���� �� �⺻ ���:
	- ��ó����, ��������� ���� main�Լ��� ��� ����, ������ �ۼ��ؼ� ���Ͽ� �Է��ϴ� ���α׷�

  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 4�� 1��)
  ���� Update : Version 1.1.0, 2022�� 7�� 6��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������		   ������		 ����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
   �Ŵ�ȫ		 2022/04/01		v1.0.0		  �����ۼ�
   �Ŵ�ȫ		 2022/07/06		v1.1.0		  ���������� �ڵ� ����ȭ
===========================================================================================================
*/

#ifndef BIG_ARRAY_H
#define BIG_ARRAY_H
#pragma warning(disable: 4996)								// scanf���� �ȶ߰� �ϴ� pragma���� 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>											// �ð� ���� ���� �õ带 ���� �������
#include <windows.h>

#define RANDOMIZE() srand((unsigned int)time(NULL))			// �ð� ���� ��ũ��
#define LINE_SIZE 10										// ���ٴ� ����ϴ� ������ ����
#define NUM_OF_LINES 3										// ���� ���� ����� ��, ó�� X��, ������ X�ٸ� ���
#define OUT_DATA "output.txt"								// ��¿� ���� �̸� output.txt

void genBigRandArray(int* array, int SIZE);						// ���� ���� �Լ�
void suffleBigArray(int* array, int SIZE);						// ������ ���� �迭�� �����ִ� �Լ�
void printBigarraySample(int* array, int SIZE, int line_size, int num_sample_lines);	// ������ ���� �迭�� ����ϴ� �Լ�
void fprintBigarraySample(FILE* fout, int* array, int SIZE, int line_size, int num_sample_lines);	// ���� ����Լ�

#endif // !BIG_ARRAY_H
