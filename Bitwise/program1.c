// Accept one number and convert into binary
#include <stdio.h>

void DisplayBinary(unsigned int iNo)
{
	unsigned int iDigit = 0;

	while (iNo > 0)
	{
		iDigit = iNo % 2;
		printf("%u", iDigit);
		iNo = iNo / 2;
	}
}

int main()
{
	unsigned int iValue = 0;

	printf("Enter one number: \n");

	scanf("%u", &iValue);
	DisplayBinary(iValue);
	return 0;
}
