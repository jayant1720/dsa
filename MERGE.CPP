#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
	int data;
	NODE *next;
};
class MERGE_L
{
	NODE *start1,*start2;
	public:
		MERGE_L();
		void MENU();
		void INSERT(int);
		void MERGE();
		void SHOW();
};
MERGE_L::MERGE_L()
{
	start1=start2=NULL;
}
void SPLIT_L::MENU()
{
	int opt,ele;
	do
	{
		cout<<"\n________________";
		cout<<"\n1.INSERT:";
		cout<<"\n2.MERGE:";
		cout<<"\n3.EXIT";
		cout<<"\nEnter any option:";
		cin>>opt;
		switch(opt)
		{
			case 1:cout<<"\nEnter any element:";
				cin>>ele;
				INSERT(ele);
				SHOW();
				break;
			case 2:MERGE();
				SHOW();
				break;
			case 3:return;
			default:cout<<"\nInvalid option";
				break;
		}
	}while(1);
}
void MERGE_L::INSERT(int ele)
{
	NODE *New=new NODE();
	NODE *ptr=new NODE();
	if(New==NULL)
	{
		cout<<"\nlist is full";
	}
	else
	{
		New->data=ele;
		New->next=NULL;
		if(start==NULL)
		{
			start=New;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=New;
		}
	}
}
void MERGE_L::MERGE()
{
	int *even,*odd;
	int j=0,k=0;
	if(start==NULL)
	{
		cout<<"\nlist is empty";
	}
	else
	{
		NODE *ptr=start;
		while(ptr!=NULL)
		{
			if(ptr->data%2==0)
			{
				even[++j]=ptr->data;
			}
			else
			{
				odd[++k]=ptr->data;
			}
			ptr=ptr->next;
		}
		cout<<"even list is:";
		for(int e=1;e<=j; e++)
		{
			cout<<even[e]<<" | ";
		}
		cout<<"\n\n";
		cout<<"odd list is:";
		for(int o=1;o<=k; o++)
		{
			cout<<odd[o]<<" | ";
		}
		if(j==0)
		{
			cout<<"\nThere is no even list";
		}
		if(k==0)
		{
			cout<<"\nThere is no odd list";
		}
	}

}
void MERGE_L::SHOW()
{
	if(start==NULL)
	{
		 cout<<"\nList is empty";
	}
	else
	{
		NODE *ptr=start;
		while(ptr!=NULL)
		{
			cout<<ptr->data<<" | ";
			ptr=ptr->next;
		}
	}
}
void main()
{
	clrscr();
	MERGE_L obj;
	obj.MENU();
	getch();
}