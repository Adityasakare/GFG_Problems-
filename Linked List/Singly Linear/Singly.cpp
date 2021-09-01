// Singly Linear Linked List

#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE;

/*
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;
*/

class SinglyLL
{
private:
	PNODE Head;
	int iSize;
	
public:
	SinglyLL()
	{
		Head = NULL;
		iSize = 0;
	}
	
	int Count()
	{
		return iSize;
	}

void InsertFirst(int iValue)
{
	PNODE newn = NULL;
	newn = new NODE;
	
	newn -> data = iValue;
	newn -> next = NULL;
	
	if (Head == NULL)	//LL is empty
	{
		Head = newn;
	}
	else			//LL contains atleast one node
	{
		newn -> next = Head;
		Head = newn;
	}
	iSize++;
}

void InsertLast(int iValue)
{
	PNODE newn = NULL;
	newn = new NODE;
	PNODE temp = Head;
	
	newn -> data = iValue;
	newn -> next = NULL;
	
	if (Head == NULL)	//LL is empty
	{
		Head = newn;
	}
	else			//LL contains atleast one node
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
	}
	iSize++;
}

void Display()
{
	PNODE temp = Head;
	
	while (temp != NULL)
	{
		cout<<temp->data<<"\t";
		temp = temp -> next;
	}
	cout<<"\n";
}

void DeleteLast()
{
	if (Head == NULL)
	{
		return;
	}
	else if (Head -> next = NULL)
	{
		delete Head;
		Head = NULL;
		iSize--;
	}	
	else
	{
		PNODE temp = Head;
		while(temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
		delete (temp -> next);
		temp -> next = NULL;
		iSize--;
		
	}
}

void DeleteFirst()
{
	if (Head != NULL)
	{
		return;
	}
	else
	{
		PNODE temp = Head;
		Head = Head -> next;
		delete temp;
		iSize--;
	}	
}

void DeleteAtPos(int iPos)
{
	if (iPos < 1 || iPos > iSize)
	{
		return;
	}
	if (iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DeleteLast();
	}
	else
	{
		PNODE temp = Head;
		PNODE target = NULL;
		for (int i = 1; i < iPos - 1; i++)
		{
			temp = temp -> next;
		}		
		target = temp -> next;
		temp -> next = temp -> next -> next;
		delete target;
		iSize--;
	}	
}
void InsertAtPos(int iValue,int iPos)
	{
		if (iPos < 1 || iPos > iSize + 1)
		{
			return;
		}
		if (iPos == 1)
		{
			InsertFirst(iValue);
		}
		else if (iPos == iSize)
		{
			InsertLast(iValue);
		}
		else
		{
			PNODE temp = Head;
			PNODE newn = new NODE;
			newn -> data = iValue;
			newn -> next = NULL;

			for (int i = 1; i < iPos - 1; i++)
			{
				temp = temp -> next;
			}
			newn -> next = temp -> next;
			temp -> next = newn;
			iSize++;
		}
	}
};

int main()
{
	int iChoice = 1, iNo = 0, iPos = 0;
	
	SinglyLL obj1;
	
	while(iChoice != 0)
	{
		cout<<"ENter your choice: "<<"\n";
		cout<<"1: Insert at first position "<<"\n";
		cout<<"2: Insert at last position"<<"\n";
		cout<<"3: Insert at given position"<<"\n";
		cout<<"4: Delete at first position"<<"\n";
		cout<<"5: Delete at last position"<<"\n";
		cout<<"6: Delete at given position"<<"\n";
		cout<<"7: Display the nodes of Singly LL"<<"\n";
		cout<<"8: Count the number of nodes of Singly LL"<<"\n";
		cout<<"0: Exit the Application"<<"\n";
		cin>>iChoice;
		
		
		switch(iChoice)
		{
			case 1:
				cout<<"Enter number\n";
				cin>>iNo;
				obj1.InsertFirst(iNo);
				break;
				
			case 2:
				cout<<"Enter number\n";
				cin>>iNo;
				obj1.InsertLast(iNo);
				break;
				
			case 3:
				cout << "Enter number\n";
				cin >> iNo;
				cout << "Enter position\n";
				cin >> iPos;
				obj1.InsertAtPos(iNo, iPos);
				break;
				
			case 4:
				obj1.DeleteFirst();
				break;
				
			case 5:
				obj1.DeleteLast();
				break;
				
			case 6:
				cout << "Enter the position\n";
				cin >> iNo;
				obj1.DeleteAtPos(iNo);
				break;
				
			case 7:
				obj1.Display();
				break;
				
			case 8:
				iNo = obj1.Count();
				cout<<"Number of elemets are "<<iNo<<"\n";
				break;
				
			case 0:
				cout<<"Thank you for using the application \n";
				break;
				
			default:
				cout<<"Please enter proper option \n";
				break;	
		}
	}
	return 0;
}
