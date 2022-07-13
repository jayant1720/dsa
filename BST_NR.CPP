#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
		int data;
		NODE *left;
		NODE *rt;
};
class BST_NR
{
	NODE *root;
	public:
		BST_NR();
		void MENU();
		void INSERT(int);
		void PREORDER(NODE *);
		void INORDER(NODE *);
		void POSTORDER(NODE *);
		int DELETE(int);
};
void BST_NR::MENU()
{
	int opt,ele;
	do
	{
		cout<<"\n----------------------------------------\n";
		cout<<"\n1.Insert the element in the Binary Tree:";
		cout<<"\n2.The Preorder Binary Tree Traversal:";
		cout<<"\n3.The Inorder Binary Tree Traversal:";
		cout<<"\n4.The Postorder Binary Tree Traversal:";
		cout<<"\n5.The Delete the element from Binary Tree:";
		cout<<"\n6.Exit";
		cout<<"\n----------------------------------------\n";
		cout<<"\nchoose any option:";
		cin>>opt;
		switch(opt)
		{
			case 1: cout<<"\nInsert the element is:";
				cin>>ele;
				INSERT(ele);
				break;
			case 2: cout<<"\nThe Preorder Traversal is:";
				PREORDER(root);
				break;
			case 3: cout<<"\nThe inorder Traversal is:";
				INORDER(root);
				break;
			case 4: cout<<"\nThe Postoder Traversal is:";
				POSTORDER(root);
				break;
			case 5: cout<<"\nEnter the element to be deleted:";
				cin>>ele;
				if(DELETE(ele))
					cout<<ele<<"deleted successfully\n";
				else
					cout<<ele<<"is not found\n";
				break;
			case 6:  return;
			default: cout<<"\nInvalid option";
				break;

		}
	}while(1);
}

BST_NR::BST_NR()
{
	root=NULL;
}
void BST_NR::INSERT(int ele)
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
int BST_NR::DELETE(int)
{

return 0;
}

void BST_NR::PREORDER(NODE *T)
{

}
void BST_NR::INORDER(NODE *T)
{

}
void BST_NR::POSTORDER(NODE *T)
{

}
void main()
{
	clrscr();
	BST_NR b1;
	b1.MENU();
	getch();
}
