// Accept string and toggle the string
#include <stdio.h>

void StrToggle(char str[])
{
	if (str == NULL)
	{
		return;
	}
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str = *str + ('a' - 'A');    //*str = *str + 32;	
		}
		else if (*str >= 'a' && *str <= 'z')
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

	StrToggle(arr);

	printf("Updated String is %s\n", arr);

	return 0;
}