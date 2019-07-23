#ifndef __PROTOTYPE__
#define __PROTOTYPE__

typedef enum
{
	EXIT,
	READ_CITY,
	SHOW_CITY,
	SHOW_GARDEN,
	WRITE_CITY,
	ADD_GARDEN,
	ADD_CHILD,
	CHILD_BIRTHDAY,
	COUNT_GRADUATE,
	SORT_NAME,
	SORT_TYPE_CHILD_NUN,
	SORT_ID,
	LINKED_LIST,
	NofOptions
} MenuOptions;


int		menu();
char*	getStrExactLength(char* inpStr);
int		checkAllocation(const void* p);
unsigned char createMask(int high, int low);
void insertionSort(void* arr, int size, int typeSize, int(*compare)(const void* first, const void* second));

#endif
