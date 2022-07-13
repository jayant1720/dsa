#include<iostream.h>
#include<conio.h>
class GRAPH
{
	int A[10][10];
	int n;
	public:
		GRAPH(int);
		void READ_GRAPH();
		void DFS(int);
		void SHOW_GRAPH();
};
GRAPH::GRAPH(int par)
{
	n=par;
}
void GRAPH::READ_GRAPH()
{
	cout<<"\nEnter the cost adj matrix:";
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin>>A[i][j];
		}
	}
}
void GRAPH::DFS(int v)
{
	int VISITED[10],STK[10],top;
	for(int i=1; i<=n; i++)
		VISITED[i]=0;
	top=0;
	VISITED[v]=1;
	int u=v;
	do
	{
		l1:cout<<u<<" ";
		for(int w=1; w<=n; w++)
		{
			if(A[u][w]==1 && VISITED[w]==0)
			{
				top=top+1;
				STK[top]=w;
				VISITED[w]=1;
			}
		}
		if(top==0)
			return;
		else
		{
			u=STK[top];
			top=top-1;
			goto l1;
		}
	}while(1);
}
void GRAPH::SHOW_GRAPH()
{
	cout<<endl;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
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
	GRAPH obj(no);
	obj.READ_GRAPH();
	cout<<"\n The Dsf is:";
	obj.DFS(1);
//	obj.SHOW_GRAPH();
	getch();
}