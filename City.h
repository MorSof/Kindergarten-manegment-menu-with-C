#ifndef __CITY__
#define __CITY__

#include "Kindergarten.h"
#include "LinkedList.h"

#define BIN_FILE "DataFile.bin"
#define DATA_FILE "DataFile.txt"

typedef struct
{
	Garden** pGardenList;
	int count;
}City;


void readCity(City* pCity, int parameter);
void	showCityGardens(City* pCity);
void	showSpecificGardenInCity(City* pCity);
void saveCity(City* pCity, int parameter);
void	cityAddGarden(City* pCity);
void	addChildToSpecificGardenInCity(City* pCity);
void	birthdayToChild(City* pCity);
int		countChova(City* pCity);
void	releaseCity(City* pCity);


LinkedList* createLinkedListForKindergartenType(City* pCity, GardenType type);
void displayKindergartensFromList(LinkedList* pList);
void kindergartensLinkedList(City* pCity, GardenType type);

#endif
