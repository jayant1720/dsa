#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
class LIST
{
      int *A;
      int n;
      public:
	LIST(int);
	void SET_ELE();
	void BUBBLE_SORT();
	void INSERTION_SORT();
	void SELECTION_SORT();
	void QUICK_SORT(int,int);
	void PARTITION(int,int&);
	void MERGE_SORT(int,int);
	void MERGE(int,int,int);
	void RADIX_SORT();
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
void LIST::BUBBLE_SORT()
{
       for(int i=1; i<n-1; i++)
		for(int j=1; j<n-i; j++)
			if(A[j]>A[j+1])
			{
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
}
void LIST::INSERTION_SORT()
{
	int j,ele;
	for(int i=2; i<=n; i++)
	{
		ele=A[i];
		j=i-1;
		while(j>=1 && ele<A[j])
		{
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=ele;
	}
}
void LIST::SELECTION_SORT()
{
	for(int i=1; i<=n-1; i++)
	{
		int min=A[i];
		int k=i;
		for(int j=i+1; j<=n; j++)
		{
			if(A[j]<min)
			{
				min=A[j];
				k=j;
			}
		}
		A[k]=A[i];
		A[i]=min;
	}
}
void LIST::QUICK_SORT(int p,int q)
{
	if(p<q)
	{
		int j=q+1;
		PARTITION(p,j);
		QUICK_SORT(p,j-1);
		QUICK_SORT(j+1,q);
	}
}
void LIST::PARTITION(int m,int &p)
{
	int v=A[m];
	int i=m;
	do
	{
		do
		{
			i=i+1;
		}while(A[i] < v);
		do
		{
			p=p-1;
		}while(A[p] > v);
		if(i<p)
		{
			int temp=A[i];
			A[i]=A[p];
			A[p]=temp;
		}
		else
			break;
	}while(1);
	A[m]=A[p];
	A[p]=v;
}
void LIST::MERGE_SORT(int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		MERGE_SORT(low,mid);
		MERGE_SORT(mid+1,high);
		MERGE(low,mid,high);
	}
}
void LIST::MERGE(int low,int mid,int high)
{
	int h=low,i=low,j=mid+1;
	int *B=new int[n];
	while(h<=mid &&j<=high)
	{
		if(A[h]<A[j])
		{
			B[i]=A[h];
			h=h+1;
		}
		else
		{
			B[i]=A[j];
			j=j+1;
		}
		i=i+1;
	}
	if(h>mid)
	{
		for(int k=j; k<=high; k++)
		{
			B[i]=A[k];
			i=i+1;
		}
	}
	else
	{
		for(int k=h; k<=mid; k++)
		{
			B[i]=A[k];
			i=i+1;
		}
	}
	for(int k=low; k<=high; k++)
	{
			A[k]=B[k];
	}
	delete B;
}
void LIST::RADIX_SORT()
{
	int Q[10][100];
	int rear[10];
	for(int d=1; d<=5; d++)
	{
		for(int i=0; i<10; i++)
		{
			rear[i]=0;
		}
		for(i=1; i<=n; i++)
		{
			int radix=int(A[i]/pow(10,d-1))%10;
			rear[radix]=rear[radix]+1;
			Q[radix][rear[radix]]=A[i];
		}
		int k=0;
		for(int r=0; r<10; r++)
		{
			if(rear[r]>0)
			{
				for(int j=1; j<=rear[r]; j++)
				{
					k=k+1;
					A[k]=Q[r][j];
				}
			}
		}
	}
}
void LIST::VIEW_ALL()
{
	for(int i=1; i<=n; i++)
	{
		cout<<A[i]<<" ";
	}
}
void main()
{
	clrscr();
	int size;
	cout<<"\nEnter the Size of the List:";
	cin>>size;
	LIST l1(size);
	l1.SET_ELE();
	cout<<"\nBefore Sorting the elements:";
	l1.VIEW_ALL();
	l1.BUBBLE_SORT();
	//l1.INSERTION_SORT();
	//l1.SELECTION_SORT();
	//l1.QUICK_SORT(1,size);
	//l1.MERGE_SORT(1,size);
	l1.RADIX_SORT();
	cout<<"\n\nAfter sorting the elements:";
	l1.VIEW_ALL();
	getch();


}