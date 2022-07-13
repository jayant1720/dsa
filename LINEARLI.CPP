#include<iostream.h>
#include<conio.h>
class LIST
{
	private:
		int *A;
		int size,n;
	public:
		LIST(int ln);
		void MENU();
		void INSERT_LAST(int);
		void INSERT_FIRST(int);
		void INSERT_POS(int,int);
		int  DELETE_LAST();
		int  DELETE_FIRST();
		int  DELETE_POS(int);
		int  DELETE_VALUE(int);
		void BUBBLE_SORT();
		int LINEAR_SEARCH(int);
		int BINERY_SEARCH(int);
		void ORDER_LIST(int);
		void LIST_ALL();
};
LIST::LIST(int ln)
{
		size=ln;
		A=new int[size];
		n=0;
}
void LIST::MENU()
{
	int opt,ele,pos,low,high;
	do
	{
		cout<<"\n------------------------------";
		cout<<"\n 1.Insert @ First position:";
		cout<<"\n 2.Insert @ Last position:";
		cout<<"\n 3.Insert @ given position:";
		cout<<"\n 4.Delete @ Last position:";
		cout<<"\n 5.Delete @ First position:";
		cout<<"\n 6.Delete @ given position:";
		cout<<"\n 7.Delete @ given value:";
		cout<<"\n 8.sort @ given elements:";
		cout<<"\n 9.Linear search @ given element:";
		cout<<"\n 10.Binery search @ given elements:";
		cout<<"\n 11.Order list @ given element:";
		cout<<"\n 12.Exit";
		cout<<"\n------------------------------";
		cout<<"\nChoose any option:";
		cin>>opt;
		switch(opt)
		{
			case 1: cout<<"\nEnter element to insert:";
				cin>>ele;
				INSERT_FIRST(ele);
				LIST_ALL();
				break;
			case 2: cout<<"\nEnter element to insert:";
				cin>>ele;
				INSERT_LAST(ele);
				LIST_ALL();
				break;
			case 3: cout<<"\nEnter element to insert:";
				cin>>ele;
				cout<<"\nEnter the position of the element:";
				cin>>pos;
				INSERT_POS(ele,pos);
				LIST_ALL();
				break;
			case 4: ele=DELETE_LAST();
				if(ele!=NULL)
					cout<<ele<<"is deleted";
				LIST_ALL();
				break;
			case 5: ele=DELETE_FIRST();
				if(ele!=NULL)
					cout<<ele<<"is deleted";
				LIST_ALL();
				break;
			case 6: cout<<"\nEnter the position of the element to deleted:";
				cin>>pos;
				ele=DELETE_POS(pos);
				if(ele!=NULL)
					cout<<ele<<"is deleted";
				LIST_ALL();
				break;
			case 7: cout<<"\nEnter the element to deleted:";
				cin>>ele;
				pos=DELETE_VALUE(ele);
				if(pos==0)
					cout<<ele<<"is not found in the list";
				else
					cout<<ele<<"is deleted from pos  "<<pos;
				LIST_ALL();
				break;
			case 8: cout<<"\nSorted elements are:";
				BUBBLE_SORT();
				LIST_ALL();
				break;
			case 9: cout<<"\nEnter the element to be search by the linear search:";
				cin>>ele;
				pos=LINEAR_SEARCH(ele);
				if(pos!=NULL)
					cout<<ele<<"is found at position "<<pos;

				else
					cout<<ele<<"is not found";

				LIST_ALL();
				break;
			case 10:cout<<"\n Enter the element to be search by the bineary search:";
				cin>>ele;
				pos=BINERY_SEARCH(ele);
				if(pos==NULL)
					cout<<ele<<"is not found";
				else
					cout<<"element is found at  "<<pos<<"  position";
				LIST_ALL();
				break;
			case 11:cout<<"\nEnter the element to order list:";
				cin>>ele;
				ORDER_LIST(ele);
				LIST_ALL();
				break;
			case 12: return;
			default:cout<<"\nInvalid option:";
				break;
		}
	}while(1);
}
void LIST::INSERT_LAST(int ele)
{
	if(n<size)
	{
		A[n+1]=ele;
		n=n+1;
	}
	else
	{
		cout<<"\n List is Full,There is no space";
	}
}
void LIST::INSERT_FIRST(int ele)
{
	if(n<size)
	{
		for(int i=n; i>=1; i--)
		{
			A[i+1]=A[i];
		}
		A[1]=ele;
		n=n+1;
	}
	else
	{
		cout<<"\nList is full,No Space...";
	}
}
void LIST::INSERT_POS(int ele,int pos)
{
	 if(n<size)
	{
		for(int i=n; i>=pos; i--)
		{
			A[i+1]=A[i];
		}
		A[pos]=ele;
		n=n+1;
	}
	else
	{
		cout<<"\nList is full,No Space...";
	}
}
int LIST::DELETE_LAST()
{
	if(n==0)
	{
		cout<<"\n List is empty:";

	}
	int ele=A[n];
	n=n-1;
	return(ele);
}
int LIST::DELETE_FIRST()
{
	if(n==0)
	{
		cout<<"\nList is empty";
		return NULL;
	}
	int ele=A[1];
	for(int i=1; i<=n-1; i++)
		A[i]=A[i+1];
	n=n-1;
	return (ele);
}
int LIST::DELETE_POS(int pos)
{
	if(n==0)
	{
		cout<<"\nList is empty";
	}
	int ele=A[pos];
	for(int i=pos; i<=n-1; i++)
		A[i]=A[i+1];
	n=n-1;
	return (ele);
}
int LIST::DELETE_VALUE(int ele)
{
	int pos=0;
	if(n==0)
	{
		cout<<"\nlist is empty";
		return NULL;
	}
	for(int i=1; i<=n;i++)
	{
		if(A[i]==ele)
		{
			pos=i;
			break;
		}
	}
	if(pos!=0)
	{
		for(i=pos; i<=n-1; i++)
			A[i]=A[i+1];
		n=n-1;
		return pos;
	}
	else
		return NULL;
}
void LIST::BUBBLE_SORT()
{
	if(n==0)
	{
		cout<<"\nList is Empty:";
	}
	for(int i=1; i<=n-1; i++)
	{
		for(int j=1; j<=n-i; j++)
		{
			if(A[j]>A[j+1])
			{
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}
int LIST::LINEAR_SEARCH(int ele)
{
	int pos=0;
	if(n==0)
	{
		cout<<"\nList is Empty:";
		return NULL;
	}
	for(int i=1;i<=n; i++)
	{
		if(A[i]==ele)
		{
			pos=i;
			break;
		}
	}
	return pos;
}
int LIST::BINERY_SEARCH(int ele)
{
	int low=0,high=n;
	if(n==0)
	{
		cout<<"\nList is Empty:";
		return NULL;
	}
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(A[mid]==ele)
		{
			return mid;
		}
		else
		{
			if(ele<A[mid])
				high=mid-1;
			else
				low=mid+1;

		}
	}
	return 0;
}
void LIST::ORDER_LIST(int ele)
{
	if(n==size)
	{
		cout<<"\n List is  full";
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
void LIST::LIST_ALL()
{
	cout<<endl;
	for(int i=1; i<=n; i++)
		cout<<A[i]<<"   ";
	cout<<endl;
}
void main()
{
	clrscr();
	int S;
	cout<<"\nEnter the size of the elements:";
	cin>>S;
	LIST L1(S);
	L1.MENU();
	getch();
}