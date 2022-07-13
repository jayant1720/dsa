#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
	int data;
	NODE *next;
};
class STACK
{
	private:
		NODE *Top;
	public:
		STACK();
		void MENU();
		void PUSH(int);
		int POP();
		void LIST_ALL();
};
STACK::STACK()
{
	Top=NULL;
}
void STACK::MENU()
{
	int opt,ele;
	do
	{
		cout<<"\n------------------------------";
		cout<<"\n 1. Insert the element into stack";
		cout<<"\n 2. Delete the element from Stack";
		cout<<"\n 3.Exit";
		cout<<"\n------------------------------";
		cout<<"\nChoose any option:";
		cin>>opt;
		switch(opt)
		{
			case 1: cout<<"\nEnter element to insert:";
				cin>>ele;
				PUSH(ele);
				LIST_ALL();
				break;
			case 2: ele=POP();
				if(ele)
				{
					cout<<ele<<"is Deleted\n";
				}
				LIST_ALL();
				break;
			case 3: return;
			default:cout<<"\nInvalid option:";
				break;
		}
	}while(1);
}
void STACK::PUSH(int ele)
{
	NODE *New=new NODE();
	if(New==NULL)
	{
		cout<<"\nStack is full";
	}
	else
	{
		New->data=ele;
		New->next=NULL;
		New->next=Top;
		Top=New;
	}
}
int STACK::POP()
{
	if(Top==NULL)
	{
		cout<<"\nStack is Empty";
	}
	else
	{
		cout<<"deleted element"<<Top->data<<"\n";
		Top=Top->next;
	}
	return NULL;
}
void STACK::LIST_ALL()
{
	NODE *ptr=new NODE();
	ptr=Top;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" | ";
		ptr=ptr->next;
	}

}
void main()
{
	clrscr();
	STACK stk;
	stk.MENU();
	getch();
}