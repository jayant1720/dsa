#include<iostream.h>
#include<conio.h>
class ORLIST
{
	int *A,n,size;
	public:
		ORLIST(int);
		void MENU();
		void INSERT(int);
		int DELETE(int);
		void LIST_ALL();
};
ORLIST::ORLIST(int par)
{
	size=par;
	A=new int[size];
	n=0;
}
void ORLIST::MENU()
{
	int opt,ele,pos;
	do
	{
		cout<<"\n__________________________";
		cout<<"\n1.Insert the element in the ordered list:";
		cout<<"\n2.Delete the element from the ordered list:";
		cout<<"\n3.EXIT";
		cout<<"\nEnter any option:";
		cin>>opt;
		switch(opt)
		{
			case 1:cout<<"\nEnter the element to insert:";
				cin>>ele;
				INSERT(ele);
				LIST_ALL();
				break;
			case 2:cout<<"\nEnter the element to be deleted:";
				cin>>ele;
				pos=DELETE(ele);
				if(pos!=0)
				{
					cout<<ele<<"is found at "<<pos<<"position\n";
				}
				else
				{
					cout<<"\nElement is not found\n";
				}
				LIST_ALL();
				break;

			case 3:return;
			default:cout<<"\ninvalid option:";
				break;
		}
	}while(1);
}
void ORLIST::INSERT(int ele)
{
	if(n>=size)
	{
		cout<<"\nList is full\n";
	}
	else
	{
		int i=n;
		while(i>=1 && ele<A[i])
		{
			A[i+1]=A[i];
			i=i-1;
		}
		A[i+1]=ele;
		n=n+1;
	}
}
int ORLIST::DELETE(int ele)
{
	if(n==0)
	{
		cout<<"List is empty\n";
	}
	else
	{
		int pos=0;
		for(int i=1; i<=n; i++)
		{
			if(A[i]==ele)
			{
				pos=i;
				break;
			}
		}
		for(i=pos; i<=n-1; i++)
		{
			A[i]=A[i+1];
		}
		n=n-1;
		return(pos);
	}
	return 0;
}
void ORLIST::LIST_ALL()
{
	if(n==0)
	{
		cout<<"list is empty";
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			cout<<A[i]<<" | ";
		}
	}
}
void main()
{
	clrscr();
	int size;
	cout<<"\nEnter the size of the element:";
	cin>>size;
	ORLIST l1(size);
	l1.MENU();
	getch();
}