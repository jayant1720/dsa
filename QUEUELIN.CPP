#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
		int data;
		NODE *next;
};
class QUEUE
{
	private:
		NODE *front,*rear;

	public:
		QUEUE();
		void MENU();
		void INSERT(int);
		int DELETE();
		void LIST_ALL();
};
QUEUE::QUEUE()
{
	front=rear=NULL;
}
void QUEUE::MENU()
{
	int opt,ele;
	do
	{
		cout<<"\n------------------------------";
		cout<<"\n 1. Insert node @ into Queue";
		cout<<"\n 2. Delete node @ from Queue";
		cout<<"\n 3.Exit";
		cout<<"\n------------------------------";
		cout<<"\nChoose any option:";
		cin>>opt;
		switch(opt)
		{
			case 1: cout<<"\nEnter element to insert:";
				cin>>ele;
				INSERT(ele);
				LIST_ALL();
				break;
			case 2: ele=DELETE();
				if(ele)
					cout<<ele<<"is Deleted\n";
				LIST_ALL();
				break;
			case 3: return;
			default:cout<<"\nInvalid option:\n";
					break;
		}
	}while(1);
}
void QUEUE::INSERT(int ele)
{
	NODE *N=new NODE();
	if(N==NULL)
	{
		cout<<"\nQueue is full";
	}
	else
	{
		N->data=ele;
		N->next=NULL;
		if(front==NULL)
			front=N;
		else
		{
			rear->next=N;
		}
		rear=N;
	}
}
int QUEUE::DELETE()
{
	if(front==NULL)
	{
		cout<<"\nQueue is empty";
		return NULL;
	}
	else
	{
		int ele=front->data;
		if(front==rear)
			front=rear=NULL;
		else
		{
			NODE *ptr;
			ptr=front;
			front=front->next;
			delete ptr;
		}
		return ele;
	}
}
void QUEUE::LIST_ALL()
{
	if(front==NULL)
	{
		cout<<"\nQueue is empty";
	}
	else
	{
		NODE *ptr;
		ptr=front;
		while(ptr!=NULL)
		{
			cout<<ptr->data<<"  ";
			ptr=ptr->next;
		}
	}
}
void main()
{
	clrscr();
	QUEUE q1;
	q1.MENU();
	getch();
}

