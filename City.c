
#include <stdio.h>
#include <stdlib.h>
#include "City.h"
#include "Kindergarten.h"
#include "LinkedList.h"

void readCity(City* pCity, int parameter)
{
	if (pCity->pGardenList != NULL) {
		releaseCity(pCity);
		pCity->count = 0;
	}
	if(parameter)
		pCity->pGardenList = readAllGardensFromFile(BIN_FILE, &pCity->count, parameter);
	else
		pCity->pGardenList = readAllGardensFromFile(DATA_FILE, &pCity->count, parameter);

	if (pCity->pGardenList == NULL)
		printf("Error reading city information\n");
}

void	showCityGardens(City* pCity)
{
	showAllGardens(pCity->pGardenList, pCity->count);
	if (pCity->count > 3)
		printKindergartensInfo(
			pCity->pGardenList[0]->name, pCity->pGardenList[0]->childCount,
			pCity->pGardenList[1]->name, pCity->pGardenList[1]->childCount,
			pCity->pGardenList[2]->name, pCity->pGardenList[2]->childCount,
			NULL
		);
}

void	showSpecificGardenInCity(City* pCity)
{
	showGardenMenu(pCity->pGardenList, pCity->count);
}

void saveCity(City* pCity, int parameter)
{
	if(parameter)
		writeGardensToFile(pCity->pGardenList, pCity->count, BIN_FILE, parameter);
	else
		writeGardensToFile(pCity->pGardenList, pCity->count, DATA_FILE, parameter);
}

void cityAddGarden(City* pCity)
{
	pCity->pGardenList = addGarden(pCity->pGardenList, &pCity->count);
	if (pCity->pGardenList == NULL)//Allocation error
		printf("Error adding kindergarten\n");
}

void	addChildToSpecificGardenInCity(City* pCity)
{
	addChildToGarden(pCity->pGardenList, pCity->count);
}

void	birthdayToChild(City* pCity)
{
	handleBirthdayToChild(pCity->pGardenList, pCity->count);
}

int	countChova(City* pCity)
{
	int i;
	int count = 0;
	for (i = 0; i < pCity->count; i++)
	{
		if (pCity->pGardenList[i]->type == Chova)
			count += pCity->pGardenList[i]->childCount;
	}
	return count;
}

void	releaseCity(City* pCity)
{
	release(pCity->pGardenList, pCity->count);
}

LinkedList* createLinkedListForKindergartenType(City* pCity, GardenType type)
{
	LinkedList list;
	LinkedList* pList = &list;
	pList = (LinkedList*)malloc(sizeof(LinkedList));
	if(!pList)
		return NULL;//
	NODE* pNode;
	int i;
	if (L_init(pList) == False)
		return NULL;
	pNode = &pList->head;
	for (i = 0; i < pCity->count; i++)
	{
		if (type == pCity->pGardenList[i]->type)
			pNode = L_insert(pNode, pCity->pGardenList[i]);
	}
	return pList;
}

void displayKindergartensFromList(LinkedList* pList)
{
	printf("\nKindergarten List: \n");
	L_print(pList, showGarden);
}

void kindergartensLinkedList(City* pCity, GardenType type)
{
	LinkedList* pList = createLinkedListForKindergartenType(pCity, type);
	displayKindergartensFromList(pList);
	L_free(pList);
}
