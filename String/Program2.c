// Accept string and Display in seprate lines with Array  (Without Pointer)

#include <stdio.h>

void Display(char str[])
{
	int iCnt = 0;
	printf("Charachers from string are :\n");

	while(str[iCnt] != '\0')
	{
		printf("%c\n", str[iCnt]);
		iCnt++;
	}
}

int main()
{
	char str[40];

	printf("Enter your name\n");
	fgets(str, 40, stdin);

	Display(str);

	return 0;
}