#include<iostream.h>
#include<conio.h>
class GRAPH
{
	int A[10][10];
	int n;
	public:
		GRAPH(int);
		void READ_GRAPH();
		void BFS(int);
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
void GRAPH::BFS(int v)
{
	int VISITED[10],Q[10],rear,front;
	for(int i=1; i<=n; i++)
		VISITED[i]=0;
	rear=0; front=0;
	VISITED[v]=1;
	int u=v;
	do
	{
		cout<<u<<" ";
		for(int w=1; w<=n; w++)
		{
			if(A[u][w]==1 && VISITED[w]==0)
			{
				if(front==0)
					front++;
				rear=rear+1; Q[rear]=w;
				VISITED[w]=1;
			}
		}
		if(front==0)
			break;
f		else
		{
			u=Q[front];
			if(front==rear)
				front=0;
			else
				front=front+1;
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
	cout<<"\n The Bsf is:";
	obj.BFS(1);
//	obj.SHOW_GRAPH();
	getch();
}