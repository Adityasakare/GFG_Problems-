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
	PNODE newn = (PNODE)malloc(sizeof(NODE));
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
	PNODE temp = *Head;
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = no;
	newn -> next = NULL;

	if (*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while (temp -> next != NULL)
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
	else if ( (*Head)-> next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		*Head = (*Head) -> next;
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
	else if ( (*Head)-> next == NULL)
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
		free(temp -> next);
		temp -> next = NULL;
	}
}

void InsertAtPosition(PPNODE Head, int no, int iPos)
{
	int iSize = 0, i = 0;
	PNODE temp = *Head;
	iSize = Count(*Head);

	PNODE newn = NULL;

	if (iPos < 0 || iPos > iSize + 1)	//Invalid position
	{
		return;
	}

	if (iPos == 1)						// First Position
	{	
		InsertFirst(Head, no);
	}
	else if (iPos == iSize + 1)			// Last Position
	{
		InsertLast(Head, no);
	}
	else								// Inbetween First and last Position
	{
		newn = (PNODE)malloc(sizeof(NODE));
		newn -> data = no;
		newn -> next = NULL;

		for (i = 1; i < iPos - 1; i++)
		{
			temp = temp -> next;
		}
		newn -> next = temp -> next;
		temp -> next = newn;
	}
}

void DeleteAtPosition(PPNODE Head, int iPos)
{
	int iSize = 0, i = 0;
	iSize = Count(*Head);
	PNODE temp = *Head;
	PNODE target = NULL;
	

	if (iPos < 0 || iPos > iSize)	//Invalid position
	{
		return;
	}

	if (iPos == 1)						// First Position
	{	
		DeleteFirst(Head);
	}
	else if (iPos == iSize)			// Last Position
	{
		DeleteLast(Head);
	}
	else								// Inbetween First and last Position
	{
		for (i = 1; i < iPos - 1; i++)
		{
			temp = temp -> next;
		}
		target = temp -> next;
		temp -> next = target -> next;
		free(target);
	}
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

int main()
{
	PNODE First = NULL;
	int iRet = 0, iOption = 1, iValue = 0, iPos = 0;
	
	
	while(iOption != 0)
	{
		printf("\n___________________________________________________\n");
		printf("Enter your action on Linked List\n");
		printf("1: Insert node at first position\n");
		printf("2: Insert node at last position\n");
		printf("3: Insert node at given position\n");
		printf("4: Delete first node\n");
		printf("5: Delete last node\n");			
		printf("6: Delete node at given position\n");
		printf("7: Display the contents of linked list\n");
		printf("8: Count number of nodes of linked list\n");
		printf("0: Exit the application\n");

		scanf("%d", &iOption);
		printf("\n__________________________\n");
				  	
	switch(iOption)
	{
		case 1:
			printf("ENter data to insert: \n");
			scanf("%d", &iValue);
			InsertFirst(&First, iValue);
			break;
			
		case 2:
			printf("ENter data to insert: \n");
			scanf("%d", &iValue);
			InsertLast(&First, iValue);
			break;
			
		case 3:
			printf("ENter data to insert: \n");
			scanf("%d", &iValue);
			printf("ENter position: \n");
			scanf("%d", &iPos);
			InsertAtPosition(&First, iValue, iPos);
			break;
			
		case 4:
			DeleteFirst(&First);
			break;
			
		case 5:
			DeleteLast(&First);
			break;
			
		case 6:
			printf("Enter the position");
			scanf("%d", &iPos);
			DeleteAtPosition(&First, iPos);
			break;			
	
		case 7:
			printf("Nodes of LInked List: \n");
			Display(First);
			break;	
			
		case 8:
			iRet = Count(First);
			printf("Number of nodes in linked list : %d", iRet);
			break;
			
		case 0:
			printf("Thank you for using Marvellous Linked List Application: \n");
			break;
			
		default:
			printf("Please enter Valid Option");
	}// End of switch
	}//end of while
	return 0;
}
