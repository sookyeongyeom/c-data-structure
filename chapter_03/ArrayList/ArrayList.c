#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;		// �ƹ� ��ġ�� ����Ű�� ����
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)		// ���� ���� �ʰ�
	{
		puts("���� ������ �ʰ��߽��ϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)		// ����� �����Ͱ� ���ٸ�
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)		// �� �̻� ������ �����Ͱ� ���ٸ�
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;			// ������ �������� �ε����� ����
	int num = plist->numOfData;
	LData rdata = plist->arr[rpos];			// ������ �����͸� �ӽ÷� �����ص�

	for (int i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;		// �����ͼ� ����
	(plist->curPosition)--;		// ������ġ�� �ϳ� �ǵ���
	return rdata;		// ������ ������ ��ȯ (�����Ҵ��� �޸� ������ å���� ����)
}

int LCount(List* plist)
{
	return plist->numOfData;
}