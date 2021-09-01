 // Copy string to Another string in Reverse form

#include <stdio.h>

void StrcpyX(char src[], char dest[])
{
	int iCnt = 0;
	if (src == NULL || dest == NULL)
	{
		return;
	}
	while (*src != '\0')
	{
		iCnt++;
		src++;
	}
	src--;
	while (iCnt > 0)
	{
		*dest = *src;
		src--;
		dest++;
		iCnt--;
	}
	*dest = '\0';
}

int main()
{
	char arr[20];
	char brr[20];

	printf("Enter the string \n");
	scanf("%[^'\n']s", arr);

	StrcpyX(arr, brr);

	printf("After copy string is %s\n", brr);
	return 0;
}
