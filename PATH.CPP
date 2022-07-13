#include<iostream.h>
#include<conio.h>
//int COST[10][10]={{0,5,6},{8,0,3},{4,7,0}};
//int COST[10][10]={{0,2,4,7},{16,0,3,8},{14,10,0,4},{8,9,13,0}};
class PATH
{
	int A[10][10],n;
	int COST[10][10];
	public:
		PATH(int);
		void READ_GRAPH();
		void ALL_PATH();
		void SHOW_GRAPH();
		friend int MIN(int,int);
};
PATH::PATH(int par)
{
	n=par;
}
void PATH::READ_GRAPH()
{
	cout<<"\nEnter the adj matrix:";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>COST[i][j];
		}
	}
}
void PATH::ALL_PATH()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			A[i][j]=COST[i][j];
		}
	}
	for(int k=0; k<n; k++)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				A[i][j]=MIN(A[i][j],A[i][k]+A[k][j]);
			}
		}
	}
}
int MIN(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
void PATH::SHOW_GRAPH()
{
	cout<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<A[i][j]<<"  ";
		}
		cout<<endl;
	}
}
void main()
{
	clrscr();
	int no;
	cout<<"\nEnter the size of the nodes:";
	cin>>no;
	PATH p(no);
	p.READ_GRAPH();
	p.ALL_PATH();
	p.SHOW_GRAPH();
	getch();

}