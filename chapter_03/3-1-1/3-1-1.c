#include <stdio.h>
#include "ArrayList.h"

int main()
{
	int sum = 0, data;
	List list;
	ListInit(&list);

	for (int i = 1; i < 10; i++)
		LInsert(&list, i);

	if (LFirst(&list, &data))
	{
		sum += data;

		while (LNext(&list, &data))
			sum += data;
	}
	printf("sum = %d\n", sum);

	if (LFirst(&list, &data))
	{
		if (!(data % 2) || !(data % 3))
			LRemove(&list);

		while (LNext(&list, &data))
			if (!(data % 2) || !(data % 3))
				LRemove(&list);
	}

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}

	return 0;
}