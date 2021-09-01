// Accept string and Display reverse
#include <stdio.h>

void Display(char str[])
{
	int i, iCnt = 0;

	while (*str != '\0')
	{
		iCnt++;
		str++;
	}
	str--;
	for (i = iCnt; i > 0; i--)
	{
		printf("%c\n", *str);
		str--;
	}
}

int main()
{
	char arr[40];
	int iRet = 0;

	printf("Enter string\n");
	scanf("%[^'\n]s", arr);

	Display(arr);

	printf("Normal String is %s\n", arr);

	return 0;
}