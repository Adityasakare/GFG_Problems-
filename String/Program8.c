// Accept string and return frequency of white space
#include <stdio.h>

int WhiteSpace(char str[])
{
	int iCnt = 0;
	if (str == NULL)
	{
		return 0;
	}
	while (*str != '\0')
	{
		if ( *str == ' ' )
		{
			iCnt++;
		}
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

	iRet = WhiteSpace(arr);

	printf("frequency of white space is %d\n", iRet);

	return 0;
}