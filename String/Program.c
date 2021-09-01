// Display Name with differnt input string method 

#include <stdio.h>

int main()
{
	char arr[40];

	printf("Enter your name\n");
	//scanf("%s", arr);
	//gets(arr);
	//fgets(arr, 40, stdin); 
	scanf("%[^\n]s",arr);
	printf("Your name is %s\n", arr);

	return 0;
}