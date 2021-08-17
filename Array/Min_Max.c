/*
	Find the minimum and maximum number in the array.
*/

#include <stdio.h>
#include <stdlib.h>

void PrintValue(int *arr, int iSize)
{
	int i = 0;
	printf("\n");
	for (i = 0; i < iSize; i++)
	{
		printf("%d\t\n", arr[i]);
	}
}

void MinMax (int *arr, int iSize, int *ipMin, int *ipMax)
{
	int i = 0;
	*ipMax = arr[0];
	*ipMin = arr[0];

	for (i = 0; i < iSize; i++)
	{
		if (arr[i] > *ipMax)
		{
			*ipMax = arr[i];
		}
		else if (arr[i] < *ipMin)
		{
			*ipMin = arr[i];
		}
	}
}

int main()
{
	int *ptr = NULL;
	int i = 0, iLength = 0;
	int Min = 0, Max = 0;

	printf("Enter the Size of array\n");
	scanf("%d", &iLength);

	ptr = (int *)malloc(iLength * sizeof(int));
	if (ptr == NULL)
		printf("ERROR : Unable to allocate the memeory\n");

	printf("Enter the elements of array\n");

	for (i = 0; i < iLength; i++)
		scanf("%d", &ptr[i]);

	MinMax(ptr, iLength, &Min, &Max);
	//PrintValue(ptr, iLength);
	printf("Minimum number is %d\n", Min);
	printf("Maximum number is %d\n", Max);

	free(ptr);

	return 0;
}
