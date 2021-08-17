#include <stdio.h>
#include <stdlib.h>

#pragma pack (1)
struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE Head, int No)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = No;
	newn -> next = NULL;

	if (*Head == NULL)					// Linked List is empty
	{
		*Head = newn;
	}
	else								// Linked List contains atleast one node
	{
		newn -> next = *Head;
		*Head = newn;
	}
}

void InsertLast(PPNODE Head, int No)
{
	PNODE newn = NULL;
	PNODE temp = *Head;

	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = No;
	newn ->next = NULL;

	if (*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
	}
}

void DeleteFirst(PPNODE Head)
{
	PNODE temp = *Head;
	if (*Head == NULL)					// if Linked List empty
	{
		return;
	}
	else if ((*Head) -> next == NULL)		// if Linked List contains ONLY 1 node
	{
		free(*Head);						// Delete the first node
		*Head = NULL;						// set First pointer to NULL
	}
	else									//else Linked List contains more than 1 node
	{
		(*Head) = (*Head) -> next;
		free(temp);
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;
	if (*Head == NULL)			// if Linked List empty
	{
		return;
	}
	else if ((*Head) -> next == NULL)	// if Linked List contains ONLY 1 node
	{
		free(*Head);					// Delete the First Node
		*Head = NULL;					// set NULL into first pointer
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

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("|%d|->", Head -> data);
		Head = Head -> next;
	}
	printf("|NULL|\n");
}

int Count(PNODE Head)
{
	int iCnt = 0;

	while(Head != NULL)
	{
		iCnt++;
		Head = Head -> next;
	}
	return iCnt;
	printf("Count of nodes are %d\n", iCnt);
}

int main()
{
	PNODE First = NULL;					//struct node* First = NULL;
	int iRet = 0;
	//printf("%d\n", sizeof(NODE));
	//printf("%d\n", sizeof(PNODE));
	//printf("%d\n", sizeof(PPNODE));

	InsertFirst(&First, 51);
	InsertFirst(&First, 21);
	InsertFirst(&First, 11);
	InsertLast(&First, 101);
	InsertLast(&First, 111);
	printf("************************InsertFirst************************\n");
	Display(First);
	DeleteFirst(&First);
	Display(First);
	iRet = Count(First);
	printf("Count of nodes after DeleteFirst are %d\n", iRet);
	DeleteLast(&First);
	Display(First);
	iRet = Count(First);
	printf("Count of nodes after DeleteLast are %d\n", iRet);


	return 0;
}
