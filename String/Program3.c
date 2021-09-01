// Accept string and return length of string
#include <stdio.h>

int StrlenX(char str[])
{
	int iCnt = 0;

	while (*str != '\0')
	{
		printf("%d : %c: %d\n",iCnt, *str, *str);
		iCnt++;
		str++;
	}
	return iCnt;
}

int main()
{
	char arr[40];
	int iRet = 0;

	printf("Enter your name\n");
	scanf("%[^'\n]s", arr);
	//fgets(arr, 40, stdin);

	iRet = StrlenX(arr);

	printf("length of String is %d\n", iRet);

	return 0;
}