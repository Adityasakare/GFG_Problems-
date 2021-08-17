/*
	A program to reverse an array ans stroe into another empty array.
*/
#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int iSize)
{
	int i = 0;
	for (i = 0; i < iSize; i++)
	{
		printf("%d\t", arr[i]);
	}
}
void ReverseArray(int *arr, int iSize)
{
	int brr [iSize];
	int temp = 0;
	int *ptr1 = arr;
	int *ptr2 = &(arr[iSize - 1]);
	int *ptr3 = brr, *ptr4 = &(brr[iSize - 1]);

	while (ptr1 != ptr2)
	{	
		// Reverse in 1st array			
		temp = *ptr1;	
		*ptr1 = *ptr2;
		*ptr2 = temp;

		// put reversed value in 2nd array
		*ptr3 = *ptr1;
		*ptr4 = *ptr2;

		//travel to next
		ptr1++;
		if (ptr1 == ptr2)
		{
			break;
		}
		ptr2--;
		ptr3++;
		ptr4--;
	}
		// Odd size condition	
		if (ptr3 == ptr4)
		{
			*ptr3 = *ptr1;
			*ptr4 = *ptr2;
		}
	
	print(brr, iSize);

}

int main()
{
	int *ptr = NULL;
	int iLength = 0, i = 0;

	printf("Enter the size of array\n");
	scanf("%d", &iLength);

	ptr = (int *)malloc(iLength * sizeof(int));

	printf("Enter the elements of array\n");

	for (i = 0; i <iLength; i++)
	{
		scanf("%d", &ptr[i]);
	}

	ReverseArray(ptr, iLength);
	

	free(ptr);

	return 0;
}
