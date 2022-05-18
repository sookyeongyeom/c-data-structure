#include <stdio.h>
#include "NameCard.h"
#include "ArrayList.h"

int main()
{
	NameCard* pcard;
	List list;
	ListInit(&list);
	
	NameCard* nc1 = MakeNameCard("Choco", "010-5461-0645");
	NameCard* nc2 = MakeNameCard("Gom", "010-7561-0645");
	NameCard* nc3 = MakeNameCard("Ponyo", "010-4983-7173");

	LInsert(&list, nc1);
	LInsert(&list, nc2);
	LInsert(&list, nc3);

	puts("포뇨 찾기!");
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "Ponyo"))
			ShowNameCardInfo(pcard);
		else
			while (LNext(&list, &pcard))
				if (!NameCompare(pcard, "Ponyo"))
				{
					ShowNameCardInfo(pcard);
					break;
				}
	}
	puts("");

	puts("곰 번호 바꾸기!");
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "Gom"))
			ChangePhoneNum(pcard, "010-2020-1102");
		else
			while (LNext(&list, &pcard))
				if (!NameCompare(pcard, "Gom"))
				{
					ChangePhoneNum(pcard, "010-2020-1102");
					break;
				}
	}
	puts("");

	puts("초코 가출!");
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "Choco"))
			LRemove(&list);
		else
			while (LNext(&list, &pcard))
				if (!NameCompare(pcard, "Choco"))
				{
					LRemove(&list);
					break;
				}
	}
	puts("");

	puts("전체 보기!");
	if (LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);

		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}

	return 0;
}