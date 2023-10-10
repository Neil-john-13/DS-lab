// binary tree traversal


#include<stdio.h>
char tree[32];
int size=32;
int getRightChild (int index)
{
	if((2*index+1)<=size)
	{
		return (2*index)+1;
	}
	return -1;
}
int getLeftChild (int index)
{
	if((2*index)<=size)
	{
		
		return (2*index);
	}
	return -1;
}
void preorder(int index)
{
	if(index>0 && tree[index]!='\0')
	{
		printf("%c ",tree[index]);
		preorder(getLeftChild ( index));
		preorder(getRightChild ( index));
	}
}
void postorder(int index)
{
	if(index>0 && tree[index]!='\0')
	{
		postorder(getLeftChild ( index));
		postorder(getRightChild ( index));
		printf("%c ",tree[index]);
	}
	
}
void inorder(int index)
{
	if(index>0 && tree[index]!='\0')
	{
		inorder(getLeftChild ( index));
		printf("%c ",tree[index]);
		inorder(getRightChild ( index));
	}
}
void Tree(int index)
{
	char c;
	printf("enter the element (enter $ to exit):,");
	scanf("%c",&c);
	getchar();
	if(c=='$')
	{
		return;
	}
	tree[index]=c;
	printf("\nenter the left subtree of %c\n",tree[index]);
	Tree(2*index);
	printf("\nenter the right subtree of %c\n",tree[index]);
	Tree(2*index+1);
}
void main()
{
	for(int i=0;i<size;i++)
	{
		tree[i]=='\0';
	}
	Tree(1);
	printf("The Preorder traversal  : ");
	preorder(1);
	printf("\n");
	printf("The Postorder traversal : ");
	postorder(1);
	printf("\n");
	printf("The Inorder traversal   : ");
	inorder(1);
	printf("\n");
}

/*_______________OUTPUT________________
enter the element (enter $ to exit):,A

enter the left subtree of A
enter the element (enter $ to exit):,B

enter the left subtree of B
enter the element (enter $ to exit):,D

enter the left subtree of D
enter the element (enter $ to exit):,$

enter the right subtree of D
enter the element (enter $ to exit):,$

enter the right subtree of B
enter the element (enter $ to exit):,G

enter the left subtree of G
enter the element (enter $ to exit):,$

enter the right subtree of G
enter the element (enter $ to exit):,$

enter the right subtree of A
enter the element (enter $ to exit):,C

enter the left subtree of C
enter the element (enter $ to exit):,E

enter the left subtree of E
enter the element (enter $ to exit):,$

enter the right subtree of E
enter the element (enter $ to exit):,$

enter the right subtree of C
enter the element (enter $ to exit):,F

enter the left subtree of F
enter the element (enter $ to exit):,$

enter the right subtree of F
enter the element (enter $ to exit):,$
The Preorder traversal  : A B D G C E F 
The Postorder traversal : D G B E F C A 
The Inorder traversal   : D B G A E C F 
*/
