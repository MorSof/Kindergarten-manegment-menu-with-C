#ifndef __KINDERGARTEN__
#define __KINDERGARTEN__

#include "Child.h"

typedef enum
{
	Chova,
	TromChova,
	TromTromChova,
	NofTypes
} GardenType;

const char* GardenTypeName[NofTypes];

typedef struct
{
	char* name;
	GardenType  type;
	Child** childPtrArr;
	int		childCount;
}Garden;


Garden**	readAllGardensFromFile(char* fileName, int* pGardenCount, int parameter);
void	readGarden(FILE* fp, Garden* pGarden);

//Garden** readAllGardensFromBinaryFile(char* fileName, int* pGardenCount);
int readGardenFromBFile(FILE* fp, Garden* pGarden);

void	writeGardenToBFile(FILE* fp, const Garden* pGarden);
//void	writeGardensToBinaryFile(Garden** pGardenList, int gardenCount, char* fileName);

GardenType	getTypeOption();

void	showAllGardens(Garden** pGardenList, int count);
void	showGarden(const void* pG);

void	writeGardensToFile(Garden** pGardenList, int gardenCount, char* fileName, int parameter);
void	writeGarden(FILE* fp,const Garden* pGarden);


void	addChildToGarden(Garden** pGardenList, int gardenCount);
Garden**	addGarden(Garden** pGardenList, int* pGardenCount);

void	showGardenMenu(Garden** pGardenList, int count);
Garden*	getGardenAskForName(Garden** pGardenList, int count);

Garden*	findGardenByName(Garden** pGardenList, int count,const char* name);

Child*	getChildAskForId(Garden* pGarden);

void	getGardenFromUser(Garden* pGarden, Garden** pGardenList, int count);
void	getChildCheckIdFromUser(Child* pChild,const Garden* pGarden);

void	handleBirthdayToChild(Garden** pGardenList, int count);

void	release(Garden** pGardenList, int count);

int compareGardenByName(const void* garden1, const void* garden2);
int compareGardenByTypeAndNumOfChild(const void* garden1, const void* garden2);

void printKindergartensInfo(char* string, int num, ...);





#endif
