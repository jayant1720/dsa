#include<iostream.h>
#include<conio.h>
class STACK
{
	private:
		int *A;
		int size,top;
	public:
		STACK(int);
		void MENU();
		void PUSH(int);
		int POP();
		void LIST_ALL();
		void VIEW_TOP();
};
STACK::STACK(int sk)
{
		size=sk;
		A=new int[size];
		top=0;
}
void STACK::MENU()
{
	int opt,ele;
	do
	{
		cout<<"\n------------------------------";
		cout<<"\n 1. Insert element @ into stack";
		cout<<"\n 2. Delete element @ from Stack";
		cout<<"\n 3. View the Top of the Element";
		cout<<"\n 4.Exit";
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
					cout<<ele<<"is Deleted\n";
				LIST_ALL();
				break;
			case 3: VIEW_TOP();
				break;
			case 4: return;
			default:cout<<"\nInvalid option:";
				break;
		}
	}while(1);
}
void STACK::PUSH(int ele)
{
	if(top==size)
	{
		cout<<"Stack is full\n";
	}
	else
	{
		top=top+1;
		A[top]=ele;
	}
}
int STACK::POP()
{
	int ele;
	if(top==-1)
	{
		cout<<"\nStack is Empty";
		return NULL;
	}
	else
	{
		ele=A[top];
		top=top-1;
		return ele;
	}
}
void STACK::LIST_ALL()
{
	if(top==0)
	{
		cout<<"\nStack is Empty";
	}
	for(int i=top; i>=1; i--)
	{
		cout<<A[i]<<"  |  ";
	}
}
void  STACK::VIEW_TOP()
{
	cout<<"\nTop element is: "<<A[top];
}
void main()
{
	clrscr();
	int S;
	cout<<"\nEnter the size of the elements:";
	cin>>S;
	STACK stk(S);
	stk.MENU();
	getch();
}