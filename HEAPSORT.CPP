#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class LIST
{
      int *A;
      int n;
      public:
	LIST(int);
	void SET_ELE();
	void HEAPIFY();
	void ADJUST(int,int);
	void HEAP_SORT();
	void VIEW_ALL();
};
LIST::LIST(int par)
{
	n=par;
	A=new int[n+1];
}
void LIST::SET_ELE()
{
	for(int i=1; i<=n; i++)
		A[i]=random(1000);
}
void LIST::HEAPIFY()
{
	for(int i=n/2; i>=1; i--)
	{
		ADJUST(i,n);
	}
}
void LIST::ADJUST(int i,int n)
{
	int j=2*i;
	int item=A[i];
	while(j<=n)
	{
		if(j<n && A[j]<A[j+1])
		{
			j=j+1;
		}
		if(item>=A[j])
		{
			break;
		}
		else
		{
			A[j/2]=A[j];
		}
		j=2*j;
	}
	A[j/2]=item;
}
void LIST::HEAP_SORT()
{
	HEAPIFY();
	for(int i=n; i>=2; i--)
	{
		int temp=A[i];
		A[i]=A[1];
		A[1]=temp;
		ADJUST(1,i-1);
	}
}
void LIST::VIEW_ALL()
{	cout<<endl;
	for(int i=1; i<=n; i++)
	{	cout<<A[i]<<" ";
	}
}
void main()
{	clrscr();
	int size;
	cout<<"\nEnter the Size of the List:";
	cin>>size;
	LIST l1(size);
	l1.SET_ELE();
	cout<<"\nBefore Sorting the elements:";
	l1.VIEW_ALL();
	l1.HEAP_SORT();
	cout<<"\n\nAfter sorting the elements:";
	l1.VIEW_ALL();
	getch();
}
