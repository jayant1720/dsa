#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
		int data;
		NODE *next;
		NODE *prev;
};
class D_LINK
{
	NODE *start;
	public:
		D_LINK();
		void MENU();
		void INSERT_FIRST(int);
		void INSERT_LAST(int);
		void INSERT_POS(int,int);
		int DELETE_FIRST();
		int DELETE_LAST();
		int DELETE_POS(int);
		void LIST_ALL();
};
D_LINK::D_LINK()
{
	start=NULL;
}
void D_LINK::MENU()
{
	int opt,ele,pos;
	do
	{
		cout<<"\n_________________________________________";
		cout<<"\n 1.Insert the element at First position:";
		cout<<"\n 2.Insert the element at Last position:";
		cout<<"\n 3.Insert the element at Given position:";
		cout<<"\n 4.DELETE the element at first position:";
		cout<<"\n 5.DELETE the element at Last position:";
		cout<<"\n 6.DELETE the element at Given position:";
		cout<<"\n 7.EXIT";
		cout<<"\n_________________________________________";
		cout<<"\nchoose the option:";
		cin>>opt;
		switch(opt)
		{
			case 1: cout<<"\n Enter the Element to insert:";
				cin>>ele;
				INSERT_FIRST(ele);
				LIST_ALL();
				break;
			case 2: cout<<"\n Enter the Element to insert:";
				cin>>ele;
				INSERT_LAST(ele);
				LIST_ALL();
				break;
			case 3: cout<<"\n Enter the Element to insert:";
				cin>>ele;
				cout<<"\n Enter the position of the element:";
				cin>>pos;
				INSERT_POS(ele,pos);
				LIST_ALL();
				break;
			case 4:	ele=DELETE_FIRST();
				if(ele)
				{
					cout<<ele<<"is deleted\n";
				}
				LIST_ALL();
				break;
			case 5:	ele=DELETE_LAST();
				if(ele)
				{
					cout<<ele<<"is deleted\n";
				}
				LIST_ALL();
				break;
			case 6: cout<<"\nEnter the position to deleted:";
				cin>>pos;
				ele=DELETE_POS(pos);
				if(ele)
				{
					cout<<ele<<"is deleted\n";
				}
				LIST_ALL();
				break;
			case 7: return;
			default: cout<<"\nInvalid Option";
				 break;


		}

	}while(1);
}
void D_LINK::INSERT_FIRST(int ele)
{
	NODE *New=new NODE();
	if(New==NULL)
	{
		cout<<"\nList is full";
	}
	else
	{
		New->data=ele;
		New->next=start;
		start->prev=New;
		start=New;
	}
}
void D_LINK::INSERT_LAST(int ele)
{
	NODE *New=new NODE();
	NODE *ptr=new NODE();
	if(New==NULL)
	{
		cout<<"\nList is full";
	}
	else
	{
		New->data=ele;
		New->next=NULL;
		New->prev=NULL;
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
			New->prev=ptr;
		}
	}
}
void D_LINK::INSERT_POS(int ele,int pos)
{
	NODE *New=new NODE();
	NODE *ptr=new NODE();
	if(New==NULL)
	{
		cout<<"\nList is full";
	}
	else
	{       New->data=ele;
		New->next=NULL;
		if(pos==1)
		{
			New->next=start;
			if(start!=NULL)
			{
				start->prev=New;
			}
			start=New;
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
			New->next=ptr->next;
			New->prev=ptr;
			if(ptr->next!=NULL)
			{
				ptr->next->prev=New;
			}
			ptr->next=New;
		}
	}
}
int D_LINK::DELETE_FIRST()
{
	if(start==NULL)
	{
		cout<<"\nList is Empty";
		return NULL;
	}
	int ele=start->data;
	start=start->next;
	start->prev=NULL;
	return(ele);
}
int D_LINK::DELETE_LAST()
{
	NODE *ptr=new NODE();
	if(start==NULL)
	{
		cout<<"\nList is Empty";
		return NULL;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		int ele=ptr->data;
		if(ptr==start)
		{
			start=NULL;
		}
		else
		{
			ptr->prev->next=NULL;
		}
		return ele;
	}
}
int D_LINK::DELETE_POS(int pos)
{
	int ele;
	NODE *ptr=new NODE();
	if(start==NULL)
	{
		cout<<"\nList is Empty";
		return NULL;
	}
	else
	{
		if(pos==1)
		{
			ele=start->data;
			start=start->next;
			start->prev=NULL;
		}
		else
		{
			int i=1;
			ptr=start;
			while(i<pos)
			{
				ptr=ptr->next;
				i=i+1;
			}
			ele=ptr->data;
			ptr->prev->next=ptr->next;
			if(ptr!=NULL)
			{
				ptr->next->prev=ptr->prev;
			}
		}
		return ele;
	}
}
void D_LINK::LIST_ALL()
{
 //	NODE *New=new NODE();
	NODE *ptr=new NODE();
	if(start==NULL)
	{
		cout<<"\nList is empty";
	}
	else
	{
		ptr=start;
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
	D_LINK D1;
	D1.MENU();
	getch();
}