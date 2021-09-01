// Accept string and Display in seprate lines 

#include <stdio.h>

void Display(char *str)
{
	printf("Charachers from string are :\n");

	while(*str != '\0')
	{
		printf("%c\n", *str);
		str++;
	}
}

int main()
{
	char str[10];

	printf("Enter your name\n");
	fgets(str, 10, stdin);

	Display(str);

	return 0;
}