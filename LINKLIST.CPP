#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
	int data;
	NODE *next;
};
class LINKLIST
{
	private:
		NODE *start;
	public:
		LINKLIST();
		void INSERT_FIRST(int);
		void INSERT_LAST(int);
		void INSERT_POS(int,int);
		int DELETE_FIRST();
		int DELETE_LAST();
		int DELETE_POS(int);
		int DELETE_VALUE(int);
		void LIST_ALL();
		void MENU();
};
LINKLIST::LINKLIST()
{
	start=NULL;
}
void LINKLIST::MENU()
{
	int opt,ele,pos,data;
	do
	{
		cout<<"\n----------------------------------------\n";
		cout<<"\n1.Insert the element at First position:";
		cout<<"\n2.Insert the element at Last position:";
		cout<<"\n3.Insert the element at a given position:";
		cout<<"\n4.Delete the element at First position:";
		cout<<"\n5.Delete the element at Last position:";
		cout<<"\n6.Delete the element at given position:";
		cout<<"\n7.Delete the element at given value:";
		cout<<"\n8.Exit";
		cout<<"\n----------------------------------------\n";
		cout<<"\nchoose any option:";
		cin>>opt;
		switch(opt)
		{
			case 1: cout<<"\nEnter element to insert at:";
				cin>>ele;
				INSERT_FIRST(ele);
				LIST_ALL();
				break;
			case 2: cout<<"\nEnter element to insert:";
				cin>>ele;
				INSERT_LAST(ele);
				LIST_ALL();
				break;
		       case 3:  cout<<"\nEnter element to insert:";
				cin>>ele;
				cout<<"\nEnter the position of the element:";
				cin>>pos;
				INSERT_POS(ele,pos);
				LIST_ALL();
				break;
		       case 4:  ele=DELETE_FIRST();
				if(ele)
					cout<<ele<<"is deleted\n";
				LIST_ALL();
				break;
		       case 5:  ele=DELETE_LAST();
				if(ele)
					cout<<ele<<"is deleted\n";
				LIST_ALL();
				break;
		       case 6: 	cout<<"\nEnter the position of the element to insert:";
				cin>>pos;
				ele=DELETE_POS(pos);
				if(ele)
					cout<<ele<<"is deleted\n";
				LIST_ALL();
				break;
		       case 7:  cout<<"\nEnter the value to delete:";
				cin>>ele;
				ele=DELETE_VALUE(ele);
				if(ele)
					cout<<ele<<"is deleted\n";
				LIST_ALL();
				break;
		       case 8:  return;
		      default:cout<<"\nInvalid option";
				break;

		}
	}while(1);
}
void LINKLIST::INSERT_FIRST(int ele)
{
	NODE *N=new NODE();
	if(N==NULL)
	{
		cout<<"\nList is full:";
	}
	N->data=ele;
	N->next=NULL;
	N->next=start;
	start=N;
}
void LINKLIST::INSERT_LAST(int ele)
{
	NODE *N=new NODE();
	NODE *ptr=new NODE();
	if(N==NULL)
	{
		cout<<"\nlist is full:";
	}
	N->data=ele;
	N->next=NULL;
	if(start==NULL)
		start=N;
	else
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=N;
}
void LINKLIST::INSERT_POS(int ele,int pos)
{
	NODE *N=new NODE();
	NODE *ptr=new NODE();
	if(N==NULL)
	{
		cout<<"\nlist is full:";
	}
	N->data=ele;
	N->next=NULL;
	if(pos==1)
	{
		N->next=start;
		start=N;
	}
	else
	{
		int i=1;
		ptr=start;
		while(i<pos-1)
		{
			ptr=ptr->next;
			i=i+1;
		}
		N->next=ptr->next;
		ptr->next=N;
	}
}
int LINKLIST::DELETE_FIRST()
{
	int ele;
	if(start==NULL)
	{
		cout<<"\nList is empty";
		return NULL;
	}
	ele=start->data;
	start=start->next;
	return ele;

}
int LINKLIST::DELETE_LAST()
{
	NODE *ptr=new NODE();
	NODE *prev=new NODE();
	if(start==NULL)
	{
		cout<<"\nList is empty";
		return NULL;
	}
	ptr=start;
	prev=NULL;
	while(ptr->next!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;
	}
	int ele=ptr->data;
	if(prev==NULL)
	{
		start=NULL;
	}
	else
	{
		prev->next=NULL;
	}
	return ele;

}
int LINKLIST::DELETE_POS(int pos)
{
	int ele;
	NODE *ptr=new NODE();
	NODE *prev=new NODE();
	if(start==NULL)
	{
		cout<<"\nList is empty";
		return NULL;
	}
	if(pos==1)
	{
		ele=start->data;
		start=start->next;
	}
	else
	{
		int i=1;
		ptr=start;
		prev=NULL;
		while(i<pos)
		{
			prev=ptr;
			ptr=ptr->next;
			i=i+1;
		}
		ele=ptr->data;
		prev->next=ptr->next;
	}
       return ele;
}
int LINKLIST::DELETE_VALUE(int ele)
{
	NODE *ptr=new NODE();
	NODE *prev=new NODE();
	if(start==NULL)
	{
		cout<<"\nList is empty";
		return NULL;
	}
	ptr=start;
	prev=NULL;
	if(ptr->data==ele)
	{
		start=ptr->next;
		return(ele);
	}
	else
	{
		prev=ptr;
		ptr=ptr->next;
		while(ptr->data!=ele)
		{
		      prev=ptr;
		      ptr=ptr->next;
		}
		if(ptr!=NULL)
		{
			prev->next=ptr->next;
			return(ele);
		}
		return 0;
	}
}

void LINKLIST::LIST_ALL()
{
	NODE *N=new NODE();
	if(N==NULL)
	{
		cout<<"\nlist is full:";
	}
	NODE *ptr=new NODE();
	ptr=start;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"  |  ";
		ptr=ptr->next;
	}
}
void main()
{
	clrscr();
	LINKLIST l1;
	l1.MENU();
	getch();
}