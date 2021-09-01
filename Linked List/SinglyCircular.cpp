// Singly CIrcular

#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}NODE, *PNODE;

class SinglyCircular
{
	private :
		int iSize;
		PNODE Head;
		PNODE Tail;

	public :
		SinglyCircular()
		{
			iSize = 0;
			Head = NULL;
			Tail = NULL;
		}

	void InsertFirst(int iNo)
	{
		PNODE newn = new NODE;
		newn -> next = NULL;
		newn -> data = iNo;

		if ( (Head == NULL) && (Tail == NULL ))	// LL is empty
		{
			Head = newn;
			Tail = newn;
			iSize++;
			Tail -> next = Head;
		}
		else 							      // LL contains 1 node
		{
			newn -> next = Head;
			Head = newn;
			iSize++;
			Tail -> next = Head;
		}
	}

	void InsertLast(int iNo)
	{
		PNODE newn = new NODE;
		newn -> next = NULL;
		newn -> data = iNo;

		if ( (Head == NULL) && (Tail == NULL ))	// LL is empty
		{
			Head = newn;
			Tail = newn;
			iSize++;
			Tail -> next = Head;
		}
		else 							      // LL contains 1 node
		{
			Tail -> next = newn;
			Tail = Tail -> next;
			iSize++;
			Tail -> next = Head;		
		}
	}

	void DeleteFirst()
	{
		if (iSize == 0)	//LL empty
		{
			return;
		}
		else if(iSize == 1)	//if(Head == Tail)//SIngle node
		{
			delete Head;
			Head = NULL;
			Tail = NULL;
			iSize--;
		}
		else				// more than 1 node
		{
			Head = Head -> next;
			delete (Tail -> next);
			iSize--;
			Tail -> next = Head;
		}
	}

	void DeleteLast()
	{
		if (iSize == 0)	//LL empty
		{
			return;
		}
		else if(iSize == 1)	//if(Head == Tail)//SIngle node
		{
			delete Head;
			Head = NULL;
			Tail = NULL;
			iSize--;
		}
		else				// more than 1 node
		{
			PNODE temp = Head;
			for (int i = 1; i < iSize - 1; i++)
			{
				temp = temp -> next;
			}
			delete Tail;
			Tail = temp;
			iSize--;
			Tail -> next = Head;
		}
	}

	int Count()
	{
		return iSize;
	}

	void Display()
	{
		PNODE temp = Head;
		for (int i = 1; i <= iSize; i++)
		{
			cout << temp -> data << "->";
			temp = temp -> next;
		}
		cout << endl;
	}

};

int main()
{
	SinglyCircular obj;
	int iChoice = 1, iRet = 0, iPos = 0, iValue = 0;
	
	while (iChoice != 0)
	{
		cout<<"ENter your choice\n";
		cout<<"1. Insert First\n";
		cout<<"2. Insert Last\n";
		cout<<"3. Insert at position \n";
		cout<<"4. Delete First\n";
		cout<<"5. Delete Last\n";
		cout<<"6. Delete at position\n";
		cout<<"7. Insert DIspaly the nodes \n";
		cout<<"8. count the nodes \n";
		cout<<"0. Exit the application \n";
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1:
				cout<<"Insert number\n";
				cin>>iValue;
				obj.InsertFirst(iValue);
				break;
				
			case 2:
				cout<<"Insert number\n";
				cin>>iValue;
				obj.InsertLast(iValue);
				break;
				
			case 3:
				cout<<"Enter the position\n";
				cin>>iPos;
				cout<<"Insert number\n";
				cin>>iValue;
				//obj.InsertAtPos(iValue, iPos);
				break;
				
			case 4:
				obj.DeleteFirst();
				break;
				
			case 5:
				obj.DeleteLast();
				break;
				
			case 6:
				cout<<"Enter the position\n";
				cin>>iPos;
				//obj.DeleteAtPos(iPos);
				break;
				
			case 7:
				obj.Display();
				break;
				
			case 8:
				iRet = obj.Count();
				cout<<"Number of nodes are"<<iRet<<"\n";
				break;
				
			case 0:
				cout<<"Thank you for using Aditya's SIngly Circular Linked List \n";
				break;
				
			default:
				cout<<"Enter appropriate option \n";		
		}// ENd of switch	
	}// ENd of while
	

	return 0;
}// ENd of main

