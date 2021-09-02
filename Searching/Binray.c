/* Binary Search : Works on sorted array elements. Divide Array size and search Time complexity : O(1) */

#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int *arr, int iSize, int element)
{
	int low = 0;
	int high = iSize - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == element)
		{
			break;
		}

		if (arr[mid] < element)
		{
			low = mid + 1;
		}
		else
		{
			high = mid + 1;
		}
	}
	if (low >= high)
	{
		return -1;
	}
	else
	{
		return mid;
	}
}

int main()
{
	int *ptr = NULL;
	int iLen = 0, i = 0, iRet = 0, iNo = 0;
	printf("Enter the size\n");
	scanf("%d", &iLen);

	ptr = (int*)malloc(iLen * sizeof(int));

	if (ptr == NULL)
	{
		puts("Unable to allocate the memory");
	} 

	printf("enter the sorted elements\n");

	for (i = 0; i <iLen; i++)
	{
		scanf("%d", &ptr[i]);
	}
	printf("Enter element you want to search\n");
	scanf("%d", &iNo);
	iRet = BinarySearch(ptr, iLen, iNo);

	printf("Index of %d is %d\n", iNo, iRet);
	return 0;
}
