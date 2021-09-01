#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node* next;
	struct node* prev;	//+
};

typedef struct node NODE;
typedef struct node* PNODE; 
typedef struct node** PPNODE;

int Count(PNODE Head)
{
	int iCnt = 0;
	while (Head != NULL)
	{
		iCnt++;
		Head  = Head -> next;
	}
	return iCnt;
}

void InsertFirst(PPNODE Head, int no)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = no;
	newn -> prev = NULL;
	newn -> next = NULL;

	if (*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn -> next = *Head;
		(*Head) -> prev = newn;	//+	
		*Head = newn;
	}
}

void InsertLast(PPNODE Head, int no)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = no;
	newn -> prev = NULL;
	newn -> next = NULL;
	PNODE temp = *Head;

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
		newn -> prev = temp;
	}
}

void DeleteFirst(PPNODE Head)
{
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
		*Head = (*Head) -> next;
		free((*Head) -> prev);
		(*Head) -> prev = NULL;
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
		free(temp -> next);
		temp -> next = NULL;
	}
}

void InsertAtPos(PPNODE Head, int no, int iPos)
{
	int iSize = 0, i = 0;
	PNODE newn = NULL;
	PNODE temp = *Head;
	iSize = Count(*Head);
	
	if((iPos < 1) || (iPos > iSize + 1))
	{
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(Head, no);
	}
	
	else if(iPos == iSize + 1)
	{
		InsertLast(Head, no);
	}
	
	else
	{
		newn = (PNODE) malloc(sizeof(NODE));
		newn -> data = no;
		newn -> next = NULL;
		
		for(i = 1; i < iPos - 1; i++)
		{
			temp = temp -> next;
		}
		newn -> next = temp -> next;
		temp -> next -> prev = newn;
		temp -> next = newn;
		newn -> prev = temp;
	}
	
}

void Display(PNODE Head)
{
	while (Head != NULL)
	{
		printf("|%d|<->", Head -> data);
		Head  = Head -> next;
	}
	printf("NULL\n");
}

void DeleteAtPos(PPNODE Head, int iPos)
{
	int iSize = Count(*Head);

	if (iPos < 1 || iPos > iSize)
	{
		return;
	}
	if (iPos == 1)
	{
		DeleteFirst(Head);
	}
	else if (iPos == iSize)
	{
		DeleteLast(Head);
	}
	else
	{
		PNODE temp = *Head;

		for (int i = 1; i < iPos - 1; i++)
		{
			temp = temp -> next;
		}
		temp -> next = temp -> next -> next;
		free(temp -> next -> prev);
		temp -> next -> prev = temp;
	}
}



int main()
{
	PNODE First = NULL;
	int iOption = 1, iValue = 0, iRet = 0, iPos = 0;
	
	while(iOption != 0)
	{
		printf("\n*************************************************************\n");
		printf("Please select the option\n");
		printf("1: Insert the node at first position \n");
		printf("2: Insert the node at last position \n");
		printf("3: Insert the node at given position \n");
		printf("4: Delete the first node \n");
		printf("5: Delete the last node \n");
		printf("6: Delete the node at given position \n");
		printf("7: Display the contents of Doubly Linear Linked List \n");
		printf("8: Count the nodes of Doubly Linear Linked list \n");
		printf("0: Exit from the application \n");
		printf("\n*************************************************************\n");
		scanf("%d", &iOption);
		
		switch(iOption)
		{
			case 1:
				printf("Enter data to insert \n");
				scanf("%d", &iValue);
				InsertFirst(&First, iValue);
				break;
				
			case 2:
				printf("Enter data to insert \n");
				scanf("%d", &iValue);
				InsertLast(&First, iValue);
				break;
				
			case 3:
				printf("Enter postion to be intert \n");
				scanf("%d", &iPos);
				printf("enter data to be insert \n");
				scanf("%d", &iValue);
				InsertAtPos(&First, iValue, iPos);
				break;
				
			case 4:
				DeleteFirst(&First);
				break;
				
			case 5:
				DeleteLast(&First);
				break;
				
			case 6:
				printf("Enter postion to be intert \n");
				scanf("%d", &iPos);
				DeleteAtPos(&First, iPos);
				break;
				
			case 7:
				printf("Contents of Doubly Linear Linked List are: \n");
				Display(First);
				break;
				
			case 8:
				iRet = Count(First);
				printf("Number of nodes are: %d\n", iRet);
				break;
				
			case 0:
				printf("Thank you for using Marvellous Doubly Linear Linked List Application \n");
				break;
		
			default:
				printf("Please Enter valid option \n");
				break;
		}	
	}
	
	return 0;
}//End of main
