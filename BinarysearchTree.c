// Binary search Tree using linked representation

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node * left,* right;
};
struct node* newnode(int item)
{
	struct node * temp=(struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}
void inorder(struct node * root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->key);
		inorder(root->right);
	}
}
void preorder(struct node * root)
{
	if(root!=NULL)
	{
		printf("%d ",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node * root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->key);
	}
}
struct node* insert (struct node * root,int key)
{
	if(root==NULL)
	{
		return newnode(key);
	}
	else if(key<root->key)
	{
		root->left=insert(root->left,key);
		return root;
	}
	else
	{	
		root->right=insert(root->right,key);
		return root;
	}
}
struct node *minValueNode (struct node * Node)
{
	struct node* current= Node;
	while(current && current->left!=NULL)
	{
		 current= current->left;
	}
	return current;
}
struct node *delete (struct node * root,int key)
{
	if (root==NULL)
	{
		return root;
	}
	else if(key<root->key)
	{
		root->left=delete(root->left,key);
	}
	else if(key>root->key)
	{
		root->right=delete(root->right,key);
	}
	else
	{
		if(root->left ==NULL)
		{
			struct node * temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right ==NULL)
		{
			struct node * temp=root->left;
			free(root);
			return temp;
		}
		struct node * temp=minValueNode(root->right);
		root->key=temp->key;
		root->right=delete(root->right,temp->key);
	}
	return root;
}
void main()
{
	int n,c,x,y=1;
	struct node * root=NULL;
	while(y==1)
	{
		printf("\n1. Insert a Node \n2. Delete a node \n3. display Traversal \n4. Exit\nenter the choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("enter the node element : ");
				scanf("%d",&x);
				root=insert(root,x);
				break;
			case 2:
				printf("enter the node element  to delete: ");
				scanf("%d",&x);
				root=delete(root,x);
				break;
			case 3:
				printf("\nThe Inorder traversal   : ");
				inorder(root);
				printf("\nThe preorder traversal  : ");
				preorder(root);
				printf("\nThe postorder traversal : ");
				postorder(root);
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid choice !");	
		}
	}
}
/*_______________OUTPUT________________

1. Insert a Node 
2. Delete a node 
3. display Traversal 
4. Exit
enter the choice : 1
enter the node element : 15

1. Insert a Node 
2. Delete a node 
3. display Traversal 
4. Exit
enter the choice : 1
enter the node element : 10

1. Insert a Node 
2. Delete a node 
3. display Traversal 
4. Exit
enter the choice : 1
enter the node element : 9

1. Insert a Node 
2. Delete a node 
3. display Traversal 
4. Exit
enter the choice : 1
enter the node element : 11

1. Insert a Node 
2. Delete a node 
3. display Traversal 
4. Exit
enter the choice : 1
enter the node element : 34

1. Insert a Node 
2. Delete a node 
3. display Traversal 
4. Exit
enter the choice : 1
enter the node element : 23

1. Insert a Node 
2. Delete a node 
3. display Traversal 
4. Exit
enter the choice : 1
enter the node element : 78

1. Insert a Node 
2. Delete a node 
3. display Traversal 
4. Exit
enter the choice : 3

The Inorder traversal   : 9 10 11 15 23 34 78 
The preorder traversal  : 15 10 9 11 34 23 78 
The postorder traversal : 9 11 10 23 78 34 15 
1. Insert a Node 
2. Delete a node 
3. display Traversal 
4. Exit
enter the choice : 2 
enter the node element  to delete: 11

1. Insert a Node 
2. Delete a node 
3. display Traversal 
4. Exit
enter the choice : 3

The Inorder traversal   : 9 10 15 23 34 78 
The preorder traversal  : 15 10 9 34 23 78 
The postorder traversal : 9 10 23 78 34 15 
1. Insert a Node 
2. Delete a node 
3. display Traversal 
4. Exit
enter the choice : 4

*/
