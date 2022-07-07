#include "Cmplx.h"

int main(void)
{
	Cmplx clxs[CmplxNUM];											//���Ҽ� �迭 

	clxs[0] = InputCmplx();											// �Է�
	clxs[1] = InputCmplx();

	printf("\nclxs[0] = "); printCmplxNum(clxs[0]); printf("\n");
	printf("clxs[1] = "); printCmplxNum(clxs[1]); printf("\n");		//���Ҽ� �Է°� ���

	clxs[2] = cmplxAdd(clxs[0], clxs[1]);							// ���Ҽ� ����
	printf("clxs[2] = clxs[0] + clxs[1] = \n");
	printCplxresult(clxs[0], clxs[1], clxs[2], ADD);

	clxs[3] = cmplxSub(clxs[0], clxs[1]);							// ���Ҽ� ����
	printf("clxs[3] = clxs[0] - clxs[1] = \n");
	printCplxresult(clxs[0], clxs[1], clxs[3], SUB);

	clxs[4] = cmplxMul(clxs[0], clxs[1]);							// ���Ҽ� ����
	printf("clxs[4] = clxs[0] * clxs[1] = \n");
	printCplxresult(clxs[0], clxs[1], clxs[4], MUL);

	clxs[5] = cmplxDiv(clxs[0], clxs[1]);							// ���Ҽ� ������
	printf("clxs[5] = clxs[0] / clxs[1] = \n");
	printCplxresult(clxs[0], clxs[1], clxs[5], DIV);

	clxs[6] = cmplxMul(clxs[1], clxs[5]);							// ���Ҽ� ����(clxs[1]*clxs[5])
	printf("clxs[6] = clxs[1] * clxs[5] = \n");
	printCplxresult(clxs[1], clxs[5], clxs[6], MUL);

	printf("\nBefore sorting complexs : \n");						// ������ �� ���
	printCmplxs(clxs, CmplxNUM);

	quickSortCmplx(clxs, CmplxNUM);									// ������
	printf("After sorting complexs : \n");							// ������ �� ���
	printCmplxs(clxs, CmplxNUM);

	return 0;
}