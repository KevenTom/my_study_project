#include"ArrayList.h"

int main()
{
	List list;
	LData data;
	NameCard *namecard;
	ListInit(&list);

	namecard = MakeNameCard("Keven", "010");
	LInsert(&list, namecard);

	namecard = MakeNameCard("JACKJACK", "020");
	LInsert(&list, namecard);

	namecard = MakeNameCard("Thin Chill", "030");
	LInsert(&list, namecard);


	if (LFirst(&list, &data))
	{
		if (NameCompare(data, "Keven") == 0)
			ShowNameCardInfo(data);

		while (LNext(&list, &data))
		{
			if (NameCompare(data, "Keven") == 0)
				ShowNameCardInfo(data);
		}

	}

	if (LFirst(&list, &data))
	{
		if (NameCompare(data, "Keven") == 0)
			ChangePhoneNum(data, "1111");

		while (LNext(&list, &data))
		{
			if (NameCompare(data, "Keven") == 0)
				ChangePhoneNum(data, "1111");
		}

	}

	if (LFirst(&list, &data))
	{
		if (NameCompare(data, "Keven") == 0)
			delete LRemove(&list);

		while (LNext(&list, &data))
		{
			if (NameCompare(data, "Thin Chill") == 0)
			delete LRemove(&list);
		}

	}


	if (LFirst(&list, &data))
	{
			ShowNameCardInfo(data);

		while (LNext(&list, &data))
				ShowNameCardInfo(data);
	}

	return 0;
}