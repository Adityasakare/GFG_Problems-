 // Contact the two string
//	src: Demo
//  dest: Hello
//	dest: HelloDemo
#include <stdio.h>

void StrcatX(char src[], char dest[])
{
	while (*dest != '\0')
	{
		dest++;
	}
	*dest = ' ';   //Space
	dest++;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}
int main()
{
	char arr[20];
	char brr[20];

	printf("Enter first string \n");
	scanf("%[^'\n']s", arr);			//Demo

	printf("Enter second string \n");
	scanf(" %[^'\n']s", brr);			//Hello

	StrcatX(arr, brr);

	printf("After Concat string is %s\n", brr);	//HelloDemo
	return 0;
}
