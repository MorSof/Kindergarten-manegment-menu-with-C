
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"


const char* optionStr[NofOptions] =
{
	"Exit","Read City information from file",
	"Show all Kindergartens","Show a specific Kindergarten",
	"Save City information to file","Add a Kindergarten",
	"Add a Child","Birthday to a Child",
	"Count Hova childres", "Sort Kindergatens By Name", "Sort Kindergatens By Type And Children Number",
	"Sort Children In Kindergarten","Kindergarten In Linked list"
};


/**************************************************/
int menu()
/**************************************************/
/**************************************************/
{
	int option, i;

	printf("\n==========================");
	printf("\nSelect:\n");
	for (i = 0; i < NofOptions; i++)
		printf("\n\t%d. %s.", i, optionStr[i]);
	printf("\n");
	scanf("%d", &option);
	return option;
}

char* getStrExactLength(char* inpStr)
{
	char* theStr = NULL;
	size_t len;

	len = strlen(inpStr) + 1;
	//allocate a place for the string in the right location in the array 
	theStr = (char*)malloc(len * sizeof(char));
	//Copy the string to the right location in the array 
	if (theStr != NULL)
		strcpy(theStr, inpStr);

	return theStr;
}

int checkAllocation(const void* p)
{
	if (!p)
	{
		printf("ERROR! Not enough memory!");
		return 0;
	}
	return 1;
}

// create a Mask
unsigned char createMask(int high, int low)
{
	return ((1 << (high + 1)) - (1 << low));
}

void insertionSort(void* arr, int size, int typeSize, int(*compare)(const void* first, const void* second))
{
	int i, j;
	char* key = (char*)malloc(typeSize);
	for (i = 1; i < size; i++)
	{
		memcpy(key, (char*)arr + i * typeSize, typeSize);
		for (j = i - 1; j >= 0 && compare((char*)arr + j * typeSize, key) > 0/*(arr[j] > key)*/; j--)
			memcpy((char*)arr + (j + 1) * typeSize, (char*)arr + j * typeSize, typeSize);//arr[j + 1] = arr[j];

		memcpy((char*)arr + (j + 1) * typeSize, key, typeSize);//arr[j + 1] = key;
	}
	free(key);
}



