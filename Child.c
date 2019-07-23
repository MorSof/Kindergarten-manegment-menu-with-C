
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Child.h"
#include "General.h"


/**************************************************/
/*             Read a Child from a file           */
/**************************************************/
void readChild(FILE* fp, Child* pChild)
{
	//Child ID
	fscanf(fp, "%d", &pChild->id);
	//Child Age
	fscanf(fp, "%d", &pChild->age);
}

void readChildFromBFile(FILE* fp, Child* pChild)
{
	unsigned char eightBitId, fiveIdThreeAge;
	
	fread(&eightBitId, sizeof(char), 1, fp);
	fread(&fiveIdThreeAge, sizeof(char), 1, fp);

	pChild->id = (int) ( eightBitId | ( (fiveIdThreeAge & createMask(4, 0)) << 8) );
	pChild->age = (int) ( fiveIdThreeAge & createMask(7,5) ) >> 5;

}


/**************************************************/
/*            show a Child				           */
/**************************************************/
void showChild(const Child* pChild)
{
	printf("\nID:%d  ", pChild->id);
	printf("Age:%d  ", pChild->age);
}


void getChildFromUser(Child* pChild, int id)

{
	pChild->id = id;
	
	puts("\nAge:\t");
	scanf("%d", &pChild->age);
}


/**************************************************/
/*Write a Child to the open file				*/
/**************************************************/
void writeChild(FILE* fp,const Child* pChild)
{
	fprintf(fp,"%d %d\n",pChild->id, pChild->age);
}

void writeChildToBFile(FILE* fp, const Child* pChild)
{

	unsigned char eightBitId, fiveIdThreeAge;

	eightBitId = (char)pChild->id;
	fiveIdThreeAge = (char) ( (pChild->id >> 8) | (pChild->age << 5) );
	fwrite(&eightBitId, sizeof(char), 1, fp);
	fwrite(&fiveIdThreeAge, sizeof(char), 1, fp);

}


//linear search
int	findChildById(Child** pChildList, int count, int id)
{
	Child** pFound;
	Child temp;
	Child* pTemp = &temp;
	temp.id = id;
	qsort(pChildList, count, sizeof(Child*), compareChildByID);
	pFound = (Child**)bsearch(&pTemp, pChildList, count, sizeof(Child*), compareChildByID);
	if (!pFound)
		return -1;
	else
		return pFound - pChildList;
}

void birthday(Child* pChild)
{
	pChild->age++;
}

int compareChildByID(const void* child1, const void* child2)
{
	const Child* pChild1 = *(const Child**)child1;
	const Child* pChild2 = *(const Child**)child2;
	return pChild1->id - pChild2->id;
}
