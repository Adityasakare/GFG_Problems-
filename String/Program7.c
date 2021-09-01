// Accept string and return frequency of 'small character 
#include <stdio.h>

int FreqSmall(char str[])
{
	int iCnt = 0;
	if (str == NULL)
	{
		return 0;
	}
	while (*str != '\0')
	{
		if ( (*str >= 'a') && (*str <= 'z') )
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

	iRet = FreqSmall(arr);

	printf("frequency of CAPTIAL letter is %d\n", iRet);

	return 0;
}