#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;		// 아무 위치도 가리키지 않음
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)		// 저장 공간 초과
	{
		puts("저장 공간을 초과했습니다.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)		// 저장된 데이터가 없다면
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)		// 더 이상 참조할 데이터가 없다면
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;			// 삭제할 데이터의 인덱스값 참조
	int num = plist->numOfData;
	LData rdata = plist->arr[rpos];			// 삭제할 데이터를 임시로 저장해둠

	for (int i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;		// 데이터수 감소
	(plist->curPosition)--;		// 참조위치를 하나 되돌림
	return rdata;		// 삭제된 데이터 반환 (동적할당한 메모리 해제의 책임을 전가)
}

int LCount(List* plist)
{
	return plist->numOfData;
}