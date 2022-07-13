#include<iostream.h>
#include<conio.h>
class GCD
{
		public:
				int GCD_NR(int,int);
};
int GCD::GCD_NR(int a,int b)
{
		int top=-1,addr,STK[30];
	L111:if(b==0)
		{
			STK[++top]=a;
		}
		else
		{
			STK[++top]=a;
			STK[++top]=b;
			STK[++top]=222;
			int temp=b;
			b=a%b;
			a=temp;
			goto L111;
		}
	L222:a=STK[top--];
		addr=STK[top--];
		top=top-1;
		top=top-1;
		if(top<0)
			return a;
		else
		{
			STK[++top]=a;
			goto L222;
		}
}
void main()
{
	clrscr();
        int n1,n2,c;
        GCD g1;
        cout<<"\nEnter the two values:";
        cin>>n1>>n2;
        c=g1.GCD_NR(n1,n2);
        cout<<"\nThe Greatest Common Devisor is: "<<c;
        getch();
}
