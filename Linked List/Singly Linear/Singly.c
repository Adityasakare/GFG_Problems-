#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE Head, int no)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn -> data = no;
	newn -> next = NULL;

	if (*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn -> next = *Head;
		*Head = newn;
	}

}

void InsertLast(PPNODE Head, int no)
{
	PNODE newn = NULL;
	PNODE temp = *Head;
	newn = (PNODE)malloc(sizeof(NODE));

	newn -> data = no;
	newn -> next = NULL;

	if (*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
	}

}

void DeleteFirst(PPNODE Head)
{
	PNODE temp = *Head;
	if (*Head == NULL)
	{
		return;
	}
	else if ((*Head) -> next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		(*Head) = (*Head) -> next;
		free(temp);
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;
	if (*Head == NULL)
	{
		return;
	}
	else if ((*Head) -> next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		while (temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
		free(temp -> next -> next);
		temp -> next = NULL;
	}
}

int SearchFirstOccurance(PNODE Head, int no)
{
	PNODE temp = Head;
	int iCnt = 1;
	while (temp -> data != no)
	{
		temp = temp -> next;
		iCnt++;
	}
	return iCnt;
}

int SearchLastOccurance(PNODE Head, int no)
{
	int iCnt = 1;
	int last = 0;

	while (Head != NULL)
	{
		if (Head -> data == no)
		{
			last = iCnt;
		}
		iCnt++;
		Head = Head -> next;
	}
	return last;
}

int AdditionOfElements(PNODE Head)
{
	int iSum = 0;

	while (Head != NULL)
	{
		iSum = iSum + Head -> data;
		Head = Head -> next;
	}
	return iSum;
}

void Display(PNODE Head)
{
	while (Head != NULL)
	{
		printf("|%d|->", Head -> data);
		Head = Head -> next;
	}
	printf("NULL\n");
}

void ReverseElement(PNODE Head, int iCount)
{
	int iDigit = 0, iNo = 0;
	int i = 0, iValue = 0;
	for (i = 0; i < iCount; i++)
	{	
		iNo = Head -> data;
		Head = Head -> next;
		while(iNo != 0)
		{
			iDigit = iNo % 10;
			iValue = iValue * 10 + iDigit; 
			iNo = iNo / 10;
		}
		printf("|%d|->", iValue);
		iValue = 0;
	}
	printf("NULL\n");
	
}

int Count(PNODE Head)
{
	int iCnt = 0;

	while (Head != NULL)
	{
		iCnt++;
		Head = Head -> next;
	}
	return iCnt;
}

// Entry point funtion
int main(void)
{
	PNODE First = 0;
	int iRet = 0;

	printf("\n*******************Insert First()*******************\n");
	InsertFirst(&First, 51);
	InsertFirst(&First, 21);
	InsertFirst(&First, 11);
	Display(First);
	iRet = Count(First);
	printf("Count of nodes are %d\n", iRet);

	printf("\n*******************Insert Last()*******************\n");
	InsertLast(&First, 101);
	InsertLast(&First, 111);
	InsertLast(&First, 51);
	InsertLast(&First, 121);
	Display(First);
	iRet = Count(First);
	printf("Count of nodes are %d\n", iRet);

	printf("\n*******************Reverse Elements()*******************\n");
	iRet = Count(First);
	ReverseElement(First, iRet);
	//Display(First);
	//printf("First Occurance of 101 is %d\n", iRet);

	printf("\n*******************Search First Occurance()*******************\n");
	iRet = SearchFirstOccurance(First, 101);
	Display(First);
	printf("First Occurance of 101 is %d\n", iRet);

	printf("\n*******************Search Last Occurance()*******************\n");
	iRet = SearchLastOccurance(First, 51);
	Display(First);
	printf("Last Occurance of 51 is %d\n", iRet);

	printf("\n*******************Addition of Elements()*******************\n");
	iRet = AdditionOfElements(First);
	Display(First);
	printf("Addition of Elements are %d\n", iRet);

	printf("\n*******************Delete First()*******************\n");
	DeleteFirst(&First);
	Display(First);
	iRet = Count(First);
	printf("Count of nodes are %d\n", iRet);

	printf("\n*******************Delete Last()*******************\n");
	DeleteLast(&First);
	Display(First);
	iRet = Count(First);
	printf("Count of nodes are %d\n", iRet);
	

	return 0;
}
