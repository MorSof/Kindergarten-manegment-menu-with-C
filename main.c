
#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Kindergarten.h"
#include "Child.h"
#include "City.h"


int main(int argc, char* argv[])
{
	City utz = { NULL,0 };
	Garden* keyGarden;
	GardenType type;
	int uReq, parameter;

	if(argc != 2 )
		return -1;

	sscanf(argv[1], "%d", &parameter);

	//first time read
	readCity(&utz, parameter);

	do
	{
		uReq = menu();
		switch (uReq)
		{
		case  READ_CITY:
			readCity(&utz, parameter);
			break;

		case  SHOW_CITY:
			showCityGardens(&utz);
			break;

		case  SHOW_GARDEN:
			showSpecificGardenInCity(&utz);
			break;

		case  WRITE_CITY:
			saveCity(&utz,parameter);
			break;

		case  ADD_GARDEN:
			cityAddGarden(&utz);
			break;

		case  ADD_CHILD:
			addChildToSpecificGardenInCity(&utz);
			break;

		case  CHILD_BIRTHDAY:
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE:
			printf("There are %d children going to school next year\n", countChova(&utz));
			break;

		case SORT_NAME:
			insertionSort(utz.pGardenList, utz.count, sizeof(Garden*), compareGardenByName);
			break;
		case SORT_TYPE_CHILD_NUN:
			insertionSort(utz.pGardenList, utz.count, sizeof(Garden*), compareGardenByTypeAndNumOfChild);
			break;

		case SORT_ID:
			if (!(keyGarden = getGardenAskForName(utz.pGardenList, utz.count)))
			{
				printf("No such Kindergarten\n");
				break;
			}
			insertionSort(keyGarden->childPtrArr, keyGarden->childCount, sizeof(Child*), compareChildByID);
			break;

		case LINKED_LIST:
			type = getTypeOption();
			kindergartensLinkedList(&utz, type);
			break;

		}
	} while (uReq != EXIT);

	releaseCity(&utz);//free all allocations

	return EXIT_SUCCESS;
}

