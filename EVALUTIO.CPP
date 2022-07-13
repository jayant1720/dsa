#include<iostream.h>
#include<conio.h>
#include<string.h>
class EVAL
{
	char *postfix;
	public:
		EVAL(char *);
		int EVAL_POSTFIX();
		int ISOPERAND(char c);

};
EVAL::EVAL(char *str)
{

	int len=strlen(str);
	postfix=new char[len];
	strcpy(postfix,str);
}
int EVAL::ISOPERAND(char c)
{
	if(c>='0'&& c<='9')
		return 3;
	if(c>='a'&& c<='z')
		return 2;
	if(c>='A'&&c<='Z')
		return 1;

	return 0;
}
int EVAL::EVAL_POSTFIX()
{
	int STK[20],top=-1,i=0,temp;
	while(postfix[i]!='\0')
	{
		if(ISOPERAND(postfix[i]))
		{
			cout<<"\nEnter the value of"<<postfix[i]<<":";
			cin>>temp;
			STK[++top]=temp;
		}
		else
		{
			int right=STK[top--];
			int left=STK[top--];
			switch(postfix[i])
			{
				case'+':STK[++top]=left+right;
					break;
				case'-':STK[++top]=left-right;
					break;
				case'*':STK[++top]=left*right;
					break;
				case'/':STK[++top]=left/right;
					break;
				default:cout<<"other operator:";
			}
		}
		i=i+1;
	}
	cout<<"The Evalution of postfix is:"<<STK[top--];
}
void main()
{
	clrscr();
	char *postfix;
	cout<<"Enter postfix Expression:";
	cin>>postfix;
	EVAL obj(postfix);
	obj.EVAL_POSTFIX();
	getch();
}