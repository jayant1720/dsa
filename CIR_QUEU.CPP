#include<iostream.h>
#include<conio.h>
class C_QUEUE
{
	private:
		int *Q;
		int size,front,rear;
	public:
		C_QUEUE(int cq);
		void MENU();
		void INSERT(int);
		int DELETE();
		void LIST_ALL();
};
C_QUEUE::C_QUEUE(int cq)
{
		size=cq;
		Q=new int[size];
		front=rear=0;
}
void C_QUEUE::MENU()
{
	int opt,ele;
	do
	{
		cout<<"\n------------------------------";
		cout<<"\n 1. Insert element @into circular Queue";
		cout<<"\n 2. Delete element @ from circular Queue";
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
				if(ele!=0)
				{
					cout<<ele<<"is Deleted";
				}
				LIST_ALL();
				break;
			case 3: return;
			default:cout<<"\nInvalid option:";
				break;
		}
	}while(1);
}
void C_QUEUE::INSERT(int ele)
{
	if(front==1 && rear==size) //||front=rear+1)
	{
		cout<<"\nQueue is full";
	}
	else
	{
		if(front==0)
		{
			front=front+1;
		}
		if(rear==size)
		{
			rear=0;
		}
		rear=rear+1;
		Q[rear]=ele;
	}
}
int C_QUEUE::DELETE()
{
	int ele;
	if(front==0)
	{
		cout<<"\nQueue is Empty";
		return NULL;
	}
	else
	{
		ele=Q[front];
		if(front==size)
		{
			front=0;
		}
		if(front==rear)
		{
			front=rear=0;
		}
		else
		{
			front=front+1;
		}
		return ele;
	}

}
void C_QUEUE::LIST_ALL()
{
	if(front==0)
	{
		cout<<"\n Queue is Empty";
	}
	else
	{
		if(front<=rear)
		{
			for(int i=front; i<=rear; i++)
			{
				cout<<" "<<Q[i];
			}

		}
		else
		{
			for(int i=front; i<=size; i++)
			{
				cout<<"\n"<<Q[i];
			}
			for(i=1;i<=rear; i++)
			{
				cout<<"\n"<<Q[i];
			}
		}
	}
}
void main()
{
	clrscr();
	int S;
	cout<<"\nEnter the size of the elements:";
	cin>>S;
	C_QUEUE c1(S);
	c1.MENU();
	getch();
}