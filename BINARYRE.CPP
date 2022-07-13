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
		void INORDER_R(NODE *);
		void POSTORDER_R(NODE *);
		void PREORDER_NR();
		void INORDER_NR();
		void POSTORDER_NR();
};
void BST::MENU()
{
	int opt,ele;
	do
	{
		cout<<"\n----------------------------------------\n";
		cout<<"\n1.Insert the element in the Binary Tree:";
		cout<<"\n2.The Preorder BST in Recursive :";
		cout<<"\n3.The Inorder BST in Recursive:";
		cout<<"\n4.The Postorder BST in Recursive:";
		cout<<"\n5.The Preorder BST in Non-Recursive :";
		cout<<"\n6.The Inorder BST in Non-Recursive:";
		cout<<"\n7.The Postorder BST in Non-Recursive:";
		cout<<"\n8.Exit";
		cout<<"\n----------------------------------------\n";
		cout<<"\nchoose any option:";
		cin>>opt;
		switch(opt)
		{
			case 1: cout<<"\nInsert the element is:";
				cin>>ele;
				INSERT(ele);
				break;
			case 2: cout<<"\nThe Preorder Traversal in Recursive is:";
				PREORDER_R(root);
				break;
			case 3: cout<<"\nThe inorder Traversal in Recursive is:";
				INORDER_R(root);
				break;
			case 4: cout<<"\nThe Postoder Traversal in Recursive is:";
				POSTORDER_R(root);
				break;
			case 5: cout<<"\nThe Preorder Traversal in Recursive is:";
				PREORDER_NR();
				break;
			case 6: cout<<"\nThe inorder Traversal in Recursive is:";
				INORDER_NR();
				break;
			case 7: cout<<"\nThe Postoder Traversal in Recursive is:";
				POSTORDER_NR();
				break;
			case 8:  return;
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
void BST::PREORDER_R(NODE *T)
{
	if(T!=NULL)
	{
		cout<<(T->data)<<"  ";
		PREORDER_R(T->left);
		PREORDER_R(T->rt);
	}
}
void BST::INORDER_R(NODE *T)
{
	if(T!=NULL)
	{
		INORDER_R(T->left);
		cout<<(T->data)<<"  ";
		INORDER_R(T->rt);
	}
}
void BST::POSTORDER_R(NODE *T)
{
	if(T!=NULL)
	{
		POSTORDER_R(T->left);
		POSTORDER_R(T->rt);
		cout<<(T->data)<<"  ";
	}
}
void BST::PREORDER_NR()
{
	int Top=1;
	NODE *STACK[10];
	STACK[1]=NULL;
	NODE *ptr=new NODE();
	ptr=root;
	while(ptr!=NULL)
	{
		cout<<(ptr->data)<<"  ";
		if(ptr->rt!=NULL)
		{
			Top=Top+1;
			STACK[Top]=ptr->rt;
		}
		if(ptr->left!=NULL)
		{
			ptr=ptr->left;
		}
		else
		{
			ptr=STACK[Top];
			Top=Top-1;
		}

	}
}
void BST::INORDER_NR()
{
	int Top=1;
	NODE *STACK[10];
	STACK[1]=NULL;
	NODE *ptr;//=new NODE();
	ptr=root;
    L2: while(ptr!=NULL)
	{
		Top=Top+1;
		STACK[Top]=ptr;
		ptr=ptr->left;
	}
	ptr=STACK[Top];
	Top=Top-1;
	while(ptr!=NULL)
	{
		cout<<(ptr->data)<<"  ";
		if(ptr->rt!=NULL)
		{
			ptr=ptr->rt;
			goto L2;
		}
		ptr=STACK[Top];
		Top=Top-1;
	}
}
void BST::POSTORDER_NR()
{
	int Top=1;
	NODE *STACK[10];
	int FLAG[10];
	int flag;
	STACK[1]=NULL;
	NODE *ptr=root;
	l2:while(ptr!=NULL)
	{
		Top=Top+1;
		STACK[Top]=ptr;
		FLAG[Top]=0;
		if(ptr->rt!=NULL)
		{
			Top=Top+1;
			STACK[Top]=ptr->rt;
			FLAG[Top]=1;
		}
		ptr=ptr->left;
	}
	ptr=STACK[Top];
	flag=FLAG[Top];
	Top=Top-1;
	while(flag==0)
	{
		cout<<(ptr->data)<<"  ";
		ptr=STACK[Top];
		flag=FLAG[Top];
		Top=Top-1;
	}
	if(flag==1)
		goto l2;
}
void main()
{
	clrscr();
	BST b1;
	b1.MENU();
	getch();
}
