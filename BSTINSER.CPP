#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
		int data;
		NODE *left;
		NODE *rt;
};
class BST
{
	NODE *root;
	public:
		BST();
		void MENU();
		void INSERT(int);
		void PREORDER_R(NODE *);
		int SEARCH(int);
		void DELETE_A(NODE*,NODE*);
		void DELETE_B(NODE*,NODE*);
		void DELETE_AB(NODE*,NODE*);
};
void BST::MENU()
{
	NODE *ptr,*par;
	int opt,ele;
	do
	{
		cout<<"\n----------------------------------------\n";
		cout<<"\n1.Insert the element in the Binary Tree:";
		cout<<"\n2.Search the element in the list:";
		cout<<"\n3.The Preorder BST in Recursive:";
		cout<<"\n4.The Delete the one node form the tree:";
		cout<<"\n5.The Delete the two node from the tree:";
		cout<<"\n6.The Delete the node from the tree:";
		cout<<"\n7.Exit";
		cout<<"\n----------------------------------------\n";
		cout<<"\nchoose any option:";
		cin>>opt;
		switch(opt)
		{
			case 1: cout<<"\nInsert the element is:";
				cin>>ele;
				INSERT(ele);
				break;
			case 2: cout<<"\nEnter the elements to be search:";
				cin>>ele;
				SEARCH(ele);
				break;
			case 3: cout<<"\nThe inorder Traversal in Recursive is:";
				PREORDER_R(root);
				break;
			case 4: cout<<"\nEnter the element to be deleted:";
				cin>>ele;
				DELETE_A(ptr,par);
				if(ele)
				{
					cout<<ele<<"is deleted\n";
				}
				break;
			case 5:DELETE_B(ptr,par);
				if(ele)
				{
					cout<<ele<<"is deleted\n";
				}
				break;
			case 6:DELETE_AB(ptr,par);
				if(ele)
				{
					cout<<ele<<"is deleted\n";
				}
				break;
			case 7:  return;
			default: cout<<"\nInvalid option";
				break;

		}
	}while(1);
}

BST::BST()
{
	root=NULL;
}
void BST::INSERT(int ele)
{
	NODE *NEW=new NODE();
	NEW->data=ele;
	NEW->left=NULL;
	NEW->rt=NULL;
	if(root==NULL)
		root=NEW;
	else
	{
		NODE*ptr,*par;
		ptr=root;par=NULL;
		while(ptr!=NULL)
		{
			par=ptr;
			if(ele<ptr->data)
				ptr=ptr->left;
			else
				ptr=ptr->rt;
		}
		if(ele<par->data)
			par->left=NEW;
		else
			par->rt=NEW;
	}
}
int  BST::SEARCH(int ele)
{
	if(root==NULL)
	{
		cout<<"\nTree is empty";
		return NULL;
	}
	else
	{
		NODE *ptr=root;
		while(ptr!=NULL)
		{
			if(ptr->data==ele)
			{
				return ele;
			}
			else
			{
				if(ele<ptr->data)
				{
					ptr=ptr->left;
				}
				else
				{
					ptr=ptr->rt;
				}
			}
		}
	}
	return 0;
}
void BST::PREORDER_R(NODE *T)
{
	if(T!=NULL)
	{
		cout<<(T->data)<<"  ";
		PREORDER_R(T->left);
		PREORDER_R(T->rt);
	}
}
void BST::DELETE_A(NODE *ptr,NODE *par)
{
	NODE *child;
	if(ptr->left==NULL && ptr->rt==NULL)
	{
		child=NULL;
	}
	else
	{
		if(ptr->left!=NULL)
		{
			child=ptr->left;
		}
		else
		{
			child=ptr->rt;
		}
	}
	if(par!=NULL)
	{
		if(ptr==par->left)
		{
			par->left=child;
		}
		else
		{
			par->rt=child;
		}
	}
	else
	{
		root=child;
	}
}
void BST::DELETE_B(NODE *ptr,NODE *par)
{/*
	NODE *loc;
	NODE *suc=loc->rt;
	par->suc=loc;
	while(suc->left!=NULL)
	{
		par->suc=suc;
		suc=suc->left;
	}
	DELTETE_A();
	if(par!=NULL)
	{
		if(loc=par->left)
		{
			par->left=suc;
		}
		else
		{
			par->rt=suc;
		}
	}
	else
	{
		root=suc;
	}
	suc->left=loc->left;
	suc->rt=loc->rt;*/
}
void BST::DELETE_AB(NODE *ptr,NODE *par)
{
	int ele;
	SEARCH(ele);
	if(ptr==NULL)
	{
		cout<<"\nElement is not found";
	}
	else
	{
		if(ptr->rt!=NULL && ptr->left!=NULL)
		{
			DELETE_B(ptr,par);
		}
		else
		{
			DELETE_A(ptr,par);
		}
	}
}
void main()
{

	clrscr();
	BST b1;
	b1.MENU();
	getch();
}
