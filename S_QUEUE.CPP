//Assignment No:
//Practical No:Implementation of linear simple Queue.
//Name:Kajal Govind Chopade
//Roll No:14
//___________________________________________________________________
#include<iostream.h>
#include<conio.h>
class QUEUE
{
	private:
		int *Q;
		int size,front,rear;
	public:
		QUEUE(int qu);
		void MENU();
		void INSERT(int);
		int DELETE();
		void LIST_ALL();
};
QUEUE::QUEUE(int qu)
{
		size=qu;
		Q=new int[size];
		front=rear=0;
}
void QUEUE::MENU()
{
	int opt,ele;
	do
	{
		cout<<"\n------------------------------";
		cout<<"\n 1. Insert element @ into Queue";
		cout<<"\n 2. Delete element @ from Queue";
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
	if(rear==size)
	{
		cout<<"Queue is full\n";
	}
	if(front==0)
	{
		front=front+1;
	}
	rear=rear+1;
	Q[rear]=ele;
}
int QUEUE::DELETE()
{
	int ele;
	if(front==0)
	{
		cout<<"\nQueue is Empty";
		return NULL;
	}
	ele=Q[front];
	if(front==rear)
	{
		front=rear=0;
	}
	else
	{
		front=front+1;
	}
	return(ele);
 }
void QUEUE::LIST_ALL()
{
	if(front==0)
	{
		cout<<"\n Queue is Empty";
	}
	for(int i=front; i<=rear; i++)
	{

		cout<<Q[i]<<"\t";
	}
}
void main()
{
	clrscr();
	int S;
	cout<<"\nEnter the size of the elements:";
	cin>>S;
	QUEUE q1(S);
	q1.MENU();
	getch();
}
