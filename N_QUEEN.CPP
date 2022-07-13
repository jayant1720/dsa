#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
class CHESSBOARD
{
	int X[20],n;
	public:
		CHESSBOARD(int);
		void NQUEEN();
		int PLACE(int);
		void PRINT();
		void SHOW();
};
CHESSBOARD::CHESSBOARD(int size)
{
	n=size;
}
void CHESSBOARD::NQUEEN()
{
	int k=1;int count=1;
	X[1]=0;
	while(k>0)
	{
		X[k]=X[k]+1;
		while(X[k]<=n && !PLACE(k))
		{
			X[k]=X[k]+1;
		}
		if(X[k]<=n)
		{
			if(k==n)
			{
				cout<<"\nSolution-"<<count<<" is : ";
				PRINT();
				count++;
			}
			else
			{
				k=k+1;
				X[k]=0;
			}
		}
		else
		{
			k=k-1;
		}
	}
}
int CHESSBOARD::PLACE(int k)
{
	for(int i=1;i<k;i++)
	{
		if(X[i]==X[k] || (abs(X[i]-X[k])==abs(i-k)))
		{
			return(0);
		}
	}
	return(1);
}
void CHESSBOARD::PRINT()
{
	for(int i=1;i<=n;i++)
	{
		cout<<X[i]<<" ";
	}
	SHOW();
}
void CHESSBOARD::SHOW()
{
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<endl<<"|---------------|\n";
		for(int j=1;j<=n;j++)
		{
			if(X[i]==j)
			{
				cout<<"| Q"<<i;
			}
			else
			{
				cout<<"| * ";
			}
		}
                cout<<"|";
	}
        cout<<endl<<"|---------------|";
}
void main()
{
	clrscr();
	int size;
	cout<<"\n Enter the size of chess board :";
	cin>>size;
	CHESSBOARD obj(size);
	obj.NQUEEN();
	getch();
}