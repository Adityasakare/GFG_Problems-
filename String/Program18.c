 // Accept Character from user and check whether it is alphabet or not.
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef int BOOL;
BOOL ChkAlpha(char str)
{
	int iFlag = 0;
	if (str == NULL)
	{
		return FALSE;
	}
		if (str >= 'A' && str <= 'z')
		{
			iFlag = 1;
		}
		else
		{
			iFlag = 0;
		}
	
	if (iFlag == 1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int main()
{
	char cValue = '\0';
	BOOL bRet = FALSE;

	printf("Enter string \n");
	scanf("%c", &cValue);			

	bRet = ChkAlpha(cValue);
	if (bRet == TRUE)
	{
		printf("It is a Alphabet\n");
	}
	else
	{
		printf("It is not a Alphabet\n");
	}
	
	return 0;
}
