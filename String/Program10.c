// Accept string and convert lower to UPPER character: strlwr()
#include <stdio.h>

void StruprX(char str[])
{
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str = *str - 32;
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

	StruprX(arr);

	printf("Updates String is %s\n", arr);

	return 0;
}