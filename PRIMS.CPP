#include<iostream.h>
#include<conio.h>
/*int COST[10][10]={{9999,9999,9999,9999,9999,9999,9999},
{9999,0,10,9999,30,45,9999},
{9999,10,0,50,9999,40,25},
{9999,9999,50,0,9999,35,15},
{9999,30,9999,9999,0,9999,20},
{9999,45,40,35,9999,0,5},
{9999,9999,25,15,20,5,0}}; */
class GRAPH
{
	int n;
	int COST[10][10];
	int NEAR[10],T[10][2],mincost;
	public:
		GRAPH(int);
		void READ_GRAPH();
		void PRIMS();
		void SHOW_GRAPH();
		void SHOW_TREE();
};
GRAPH::GRAPH(int par)
{
	n=par;
}
void GRAPH::READ_GRAPH()
{
	cout<<"\nEnter the cost adjacent matrix of the graph:";
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin>>COST[i][j];
		}
	}
}
void GRAPH::PRIMS()
{
	int k,l,j,i;
	int min=9999;
	for(i=1;i<=n; i++)
	{
		for(j=i+1; j<=n; j++)
		{
			if(COST[i][j]<min)
			{
				min=COST[i][j];
				 k=i,l=j;
			}
		}
	}
	T[1][1]=k;
	T[1][2]=l;
	mincost=COST[k][l];
	for(i=1; i<=n; i++)
	{
		if(COST[i][l]<COST[i][k])
		{
			NEAR[i]=l;
		}
		else
		{
			NEAR[i]=k;
		}
	}
	NEAR[k]=0;NEAR[l]=0;
	for(i=2; i<=n-1; i++)
	{
		int min=9999;
		for(int w=1;w<=n; w++)
		{
			if(NEAR[w]!=0 && COST[w][NEAR[w]]<min)
			{
				min=COST[w][NEAR[w]];
				j=w;
			}
		}
		T[i][1]=j;
		T[i][2]=NEAR[j];
		mincost=mincost+COST[j][NEAR[j]];
		NEAR[j]=0;
		for(k=1;k<=n;k++)
		{
			if(NEAR[k]!=0 && COST[k][NEAR[k]]>COST[k][j])
			{
				NEAR[k]=j;
			}
		 }
		 if(mincost>9999)
		 {
			cout<<"\nNO Spanning tree is possible";
		 }
	}
}
void GRAPH::SHOW_GRAPH()
{
	cout<<endl;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cout<<COST[i][j]<<"  ";
		}
		cout<<endl;
	}
}
void GRAPH::SHOW_TREE()
{
	cout<<"\nTree edges with cost:";
	for(int i=1;i<=n-1;i++)
	{
		cout<<endl;
		cout<<T[i][1]<<" "<<T[i][2]<<" "<<COST[T[i][1]][T[i][2]];
	}
	cout<<"\nThe Min cost the spanning tree is:"<<mincost;
}
void main()
{
	clrscr();
	int no;
	cout<<"\nEnter the size of the nodes:";
	cin>>no;
	GRAPH obj(no);
	obj.READ_GRAPH();
	obj.PRIMS();
	obj.SHOW_GRAPH();
	obj.SHOW_TREE();
	getch();
}