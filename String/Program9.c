// Accept string and convert CAPITAL to lower character: strlwr()
#include <stdio.h>

void StrlwrX(char str[])
{
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str = *str + 32;
		}
		str++;
	}
}

int main()
{
	char arr[40];
	int iRet = 0;

	printf("Enter your name\n");
	scanf("%[^'\n]s", arr);

	StrlwrX(arr);

	printf("Updates String is %s\n", arr);

	return 0;
}