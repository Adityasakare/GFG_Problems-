// Accept string and reverse string physically
#include <stdio.h>

void Reverse(char str[])
{
	char *start = str;
	char *end = str;
	char *temp;

	while (*end != '\0')
	{
		end++;
	}
	end--;

	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

int main()
{
	char arr[40];
	int iRet = 0;

	printf("Enter string\n");
	scanf("%[^'\n]s", arr);

	Reverse(arr);

	printf("Reverse String is %s\n", arr);

	return 0;
}

