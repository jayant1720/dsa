#include<iostream.h>
#include<conio.h>
#include<string.h>
class EXPR
{
	char *infix,*postfix;
	public:
		EXPR(char *);
		void INFIX_POSTFIX();
		void EVAL_POSTFIX();
		int ISOPERAND(char c);
		int PREF(char);

};
EXPR::EXPR(char *str)
{

	int len=strlen(str);
	infix=new char[len];
	postfix=new char[len];
	strcpy(infix,str);
}
int EXPR::ISOPERAND(char c)
{
	if(c>='0'&& c<='9')
		return 3;
	if(c>='a'&& c<='z')
		return 2;
	if(c>='A'&&c<='Z')
		return 1;

	return 0;
}
int EXPR::PREF(char ch)
{
	if(ch=='*'||ch=='/')
		return 2;
	if(ch=='+'||ch=='-')
		return 1;
	return 0;

}
void EXPR::INFIX_POSTFIX()
{
	char  STK[20];
	int top=-1;
	strcat(infix,")");
	STK[++top]='(';
	int i=0,j=-1;
	while(infix[i]!='\0')
	{
		if(ISOPERAND(infix[i]))
		{
			postfix[++j]=infix[i];
		}
		else
		{
			if(infix[i]==')')
			{
				while(STK[top]!='(')
				{
					postfix[++j]=STK[top];
					top=top-1;
				}
				top=top-1;
			}
			else
			{
				if(infix[i]=='(')
					STK[++top]=infix[i];
				else
				{
					while(PREF(STK[top])>=PREF(infix[i]))
					{
						postfix[++j]=STK[top];
						top=top-1;
					}
					STK[++top]=infix[i];
				}
			}
		}
		i=i+1;
	}
	postfix[++j]='\0';
	cout<<"The postfix Expression is:"<<postfix;
}
void EXPR::EVAL_POSTFIX()
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
	char *infix;
	cout<<"Enter Infix Expression:";
	cin>>infix;
	EXPR obj(infix);
	obj.INFIX_POSTFIX();
	obj.EVAL_POSTFIX();
	getch();
}