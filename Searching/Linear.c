/* Linear Search : Works on sorted and unsorted array elements. Travels whole array and compare element to array element
   till does not get found.  Time complexity : O(N) */

#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr, int iSize, int element)
{
	int iCnt = 0, iNo = 0;
	for (iCnt = 0; iCnt < iSize; iCnt++)
	{
		if (arr[iCnt] == element)
		{
			iNo = iCnt;
			break;
		}
	}
	if (iCnt == iSize)
	{
		return -1;
	}
	else
	{
		return iNo;
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

	printf("enter the elements\n");

	for (i = 0; i <iLen; i++)
	{
		scanf("%d", &ptr[i]);
	}
	printf("Enter element you want to search\n");
	scanf("%d", &iNo);
	iRet = linearSearch(ptr, iLen, iNo);

	printf("Index of %d is %d\n", iNo, iRet);
	return 0;
}
