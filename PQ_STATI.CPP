#include<iostream.h>
#include<conio.h>
class QUEUE
{
	private:
		int front,rear;
		int *Q;
		int *P;
		int n;
	public:
		QUEUE(int);
		void QINS(int,int);
		int QDEL();
		void MENU();
		void LIST_ALL();

};
void QUEUE::MENU()
{
	int opt,ele,pri;
	do
	{
		cout<<"\n-------------------------------";
		cout<<"\n1.Insert at ele";
		cout<<"\n2.Delete at ele";
		cout<<"\n3.EXIT";
		cout<<"\n choose option";
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"\n enter the ele";
				cin>>ele;
				cout<<"\nEnter the the proi to add";
				cin>>pri;
				QINS(ele,pri);
				LIST_ALL();
				break;
			case 2:
				ele=QDEL();
				if(ele)
				{
					cout<<ele<<"is delete";
				}
				LIST_ALL();
				break;
			case 3:return;
			default: cout<<"\nInvalid option:";
					break;
		}
	}while(1);
}
QUEUE::QUEUE(int par)
{
	n=par;
	Q=new int[n];
	P=new int[n];
	front=0;
	rear=0;
}
void QUEUE::QINS(int ele,int pri)
{
	int i;
	if(rear==n)
	{
		cout<<"\n queue is full";
	}
	else
	{
		if(front==0)
			front=1;
		int i=rear;
		while(i>=front && P[i]<pri)
		{
			Q[i+1]=Q[i];
			P[i+1]=P[i];
			i=i-1;
		}
		Q[i+1]=ele;
		P[i+1]=pri;
		rear=rear+1;
	}
}
int QUEUE::QDEL()
{
	if(front==0)
	{
		cout<<"\n QUEUE is empty";
	}
	else
	{
		int ele=Q[front];
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
	return 0;
}
void QUEUE::LIST_ALL()
{
	if(front==0)
	{
		cout<<"\n QUEUE is empty";
	}
	else
	{
		cout<<endl;
		for(int i=front;i<=rear;i++)
		{
			cout<<Q[i]<<" | "<<P[i]<<endl;
		}
	}
}
void main()
{
	clrscr();
	int size;
	cout<<"\nEnter the size of the list:";
	cin>>size;
	QUEUE obj(size);
	obj.MENU();
	getch();
}
