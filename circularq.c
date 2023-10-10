// circular Queue 

#include<stdio.h>
#include<stdlib.h>
int que[20],size,rear=-1,front =-1;
void enque()
{
	int item;
	if(front==0 && rear==size-1)
	{
		printf("\nQue overflow\n");
	}
	else
	{
		printf("Enter the element to enqueue:");
		scanf("%d",&item);
		if(front ==-1)
		{
			front=0;
		}
		rear=(rear+1)%size;
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
		if(front == rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=(front+1)%size;
		}
	}
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("Queue is empty \n");
	}
	else
	{
		for(i=front;i!=rear;i=(i+1)%size)
		{
			printf("%d ",que[i]);
		}
		printf("%d ",que[i]);
	}
}
void main()
{
	int p=1,item,n;
	printf("enter the size of the queue :");
	scanf("%d",&size);
	while(p)
	{
		printf("\n1. Enqueue\n2.Dequeue\n3. Display\n4 exit \nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			enque();
			break;
			case 2:
			deque();
			break;
			case 3:
			display();
			break;
			case 4:
			exit(0);
			break;
			default:
			printf("Invalid choice !");
		}
	}
}


/*_______________OUTPUT________________
1. Enqueue
2.Dequeue
3. Display
4 exit 
Enter your choice : 1
Enter the element to enqueue:23

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
Enter your choice : 2
deleted element : 23

1. Enqueue
2.Dequeue
3. Display
4 exit 
Enter your choice : 3
34 
1. Enqueue
2.Dequeue
3. Display
4 exit 
Enter your choice : 4

*/

