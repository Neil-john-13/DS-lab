// stack and que using array 


#include<stdio.h>
#include<stdlib.h>
int stack[5],size=5,que[5],top=-1,rear=-1,front=-1;
void push(int item)
{
	if(top==size-1)
	{
		printf("\nstack Overflow\n");
	}
	else
	{
		top++;
		stack[top]=item;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("stack underflow");
		
	}
	else
	{
		printf("\nThe popped element : %d",stack[top]);
		top--;
	}
}
void display_stack()
{
	if(top>=0)
	{
		for(int i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
	else
	{
		printf("stack is empty ");
	}
}
void enque(int item)
{
	if(rear==size-1)
	{
		printf("queue Overflow\n");
	}
	else
	{
		if(front==-1)
		{
			front++;
		}
		rear++;
		que[rear]=item;
	}
}
void deque()
{
	if(front==-1)
	{
		printf("queue is empty \n");
	}
	else
	{
		printf("deleted element : %d\n",que[front]);
		front++;
	}
	if(front > rear)
	{
		front=rear=-1;
	}
}
void display_que()
{
	if(front<=rear)
	{
		for(int i=front;i<=rear;i++)
		{
			printf("%d ",que[i]);
		}
	}
	else
	{
		printf("Queue is empty \n");
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
Enter the element to push :2

1. Push
2.Pop
3. Display
4 exit 
Enter your choice : 1
Enter the element to push :3

1. Push
2.Pop
3. Display
4 exit 
Enter your choice : 3
3
2

1. Push
2.Pop
3. Display
4 exit 
Enter your choice : 2

The popped element : 3
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
Enter the element to enqueue:34

1. Enqueue
2.Dequeue
3. Display
4 exit 
Enter your choice : 1
Enter the element to enqueue:35

1. Enqueue
2.Dequeue
3. Display
4 exit 
Enter your choice : 2
deleted element : 34

1. Enqueue
2.Dequeue
3. Display
4 exit 
Enter your choice : 3
35 
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
	
		
