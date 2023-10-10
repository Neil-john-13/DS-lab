// stack and queue using Linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *top= NULL;
struct node *front= NULL;
struct node *rear= NULL;
void push(int item)
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=item;
	ptr->link=NULL;
	if (top== NULL)
	{
		top=ptr;
	}
	else
	{
		ptr->link=top;
		top=ptr;
	}
}
void pop()
{
	if (top== NULL)
	{
		printf("list is empty ");
	}
	else
	{
		struct node *q;
		q=(struct node*)malloc(sizeof(struct node));
		q=top;
		printf("The deleted element : %d",top->data);
		top=top->link;
		free(q);
	}
}
void display_stack()
{
	if (top== NULL)
	{
		printf("list is empty ");
	}
	else
	{
		struct node *p;
		p=top;
		while(p)
		{
			printf("%d ",p->data);
			p=p->link;
		}
	}
}
void enque(int item)
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=item;
	if (front== NULL)
	{
		rear=ptr;
		front=ptr;
		front->link=NULL;
		rear->link=NULL;
	}
	else
	{
		
		rear->link=ptr;
		rear=ptr;
		ptr->link=NULL;
	}
}
void deque()
{
	if (front== NULL)
	{
		printf("list is empty ");
	}
	else
	{
		struct node *q;
		q=(struct node*)malloc(sizeof(struct node));
		q=front;
		printf("The deleted element : %d",front->data);
		front=front->link;
		free(q);
	}
}
void display_que()
{
	if (front== NULL)
	{
		printf("list is empty ");
	}
	else
	{
		struct node *p;
		p=front;
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->link;
			
		}
	}
}
void main()
{
	int p=1,n,n1,n2,item;
	while(p)
	{
		printf("\n\n1. Stack\n2. Queue\n3. exit\nEnter your choice : ");
		scanf("%d",&n);
		p=1;
		switch(n)
		{

			case 1:
			while(p==1)
			{
			printf("\n1. Push\n2.Pop\n3. Display\n4 exit \nEnter your choice : ");
			scanf("%d",&n1);
			switch(n1)
			{
				case 1:
				printf("Enter the element to push :");
				scanf("%d",&item);
				push(item);
				break;
				case 2:
				pop();
				break;
				case 3:
				display_stack();
				break;
				case 4:
				p=2;
				break;
				default:
				printf("Invalid choice !");
			}
			}
			break;
			case 2:
			while(p==1)
			{
			printf("\n1. Enqueue\n2.Dequeue\n3. Display\n4 exit \nEnter your choice : ");
			scanf("%d",&n1);
			switch(n1)
			{
				case 1:
				printf("Enter the element to enqueue:");
				scanf("%d",&item);
				enque(item);
				break;
				case 2:
				deque();
				break;
				case 3:
				display_que();
				break;
				case 4:
				p=2;
				break;
				default:
				printf("Invalid choice !");
			}
			}
			break;
			case 3:
			exit(0);
			default:
			printf("Invalid choice !");
		}
	}
}

/*_______________OUTPUT________________
1. Stack
2. Queue
3. exit
Enter your choice : 1

1. Push
2.Pop
3. Display
4 exit 
Enter your choice : 1
Enter the element to push :23

1. Push
2.Pop
3. Display
4 exit 
Enter your choice : 1
Enter the element to push :2 

1. Push
2.Pop
3. Display
4 exit 
Enter your choice : 3
2 23 
1. Push
2.Pop
3. Display
4 exit 
Enter your choice : 2
The deleted element : 2
1. Push
2.Pop
3. Display
4 exit 
Enter your choice : 4


1. Stack
2. Queue
3. exit
Enter your choice : 2

1. Enqueue
2.Dequeue
3. Display
4 exit 
Enter your choice : 1
Enter the element to enqueue:234

1. Enqueue
2.Dequeue
3. Display
4 exit 
Enter your choice : 2
The deleted element : 234
1. Enqueue
2.Dequeue
3. Display
4 exit 
Enter your choice : 34
Invalid choice !
1. Enqueue
2.Dequeue
3. Display
4 exit 
Enter your choice : 3
list is empty 
1. Enqueue
2.Dequeue
3. Display
4 exit 
Enter your choice : 4


1. Stack
2. Queue
3. exit
Enter your choice : 3

*/

