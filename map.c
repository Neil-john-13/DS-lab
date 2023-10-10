
#include<stdio.h>
#include<stdlib.h>
int size =5;
int h[5];
void insert()
{
	int i,hkey,hkey2,key,index;
	printf("enter the elemnet  : ");
	scanf("%d",&key);
	hkey=key%size;
	if(h[hkey]==0)
	{
		h[hkey]=key;
		return;
	}
	hkey2=key%(size-2);
	for(i=0;i<size;i++)
	{
		index=(hkey2+i)%size;
		if(h[index]==0)
		{
			h[index]=key;
			break;
		}
	}
	if(i==size)
	{
		printf("enter the element cannot be inserted "); 
	}
}
void display()
{
	for(int i=0;i<size;i++)
	{
		printf("\nindex :%d          element : %d",i,h[i]);
	}
}
void search()
{
	int i,hkey,hkey2,key,index;
	printf("enter the elemnet to search  : ");
	scanf("%d",&key);
	hkey=key%size;
	hkey2=key%(size-2);
	if(h[hkey]==key)
	{
		printf("element %d found at index %d ",key,hkey);
		return;
	}

	for(i=0;i<size;i++)
	{
		index=(hkey2+i)%size;
		if(h[index]==key)
		{
			printf("element %d found at index %d ",key,index);
			break;
		}
	}
	if(i==size)
	{
		printf("enter the element not found "); 
	}
}
void main()
{
	int n;
	while(1)
	{
		printf("\n1.insert \n2.search \n3.display \n4.exit \nenter the choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				insert();
				break;
			case 2:
				search();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("invalid choice");
		}
	}	
}	

/*_______________OUTPUT________________
1.insert 
2.search
3.display
4.exit
enter the choice : 1
enter the elemnet  : 10

1.insert
2.search
3.display
4.exit
enter the choice : 1
enter the elemnet  : 5

1.insert
2.search
3.display
4.exit
enter the choice : 1
enter the elemnet  : 20

1.insert
2.search
3.display
4.exit
enter the choice : 1
enter the elemnet  : 30

1.insert
2.search
3.display
4.exit
enter the choice : 1
enter the elemnet  : 45

1.insert
2.search
3.display
4.exit
enter the choice : 1
enter the elemnet  : 60
enter the element cannot be inserted
1.insert
2.search
3.display
4.exit
enter the choice : 3

index :0          element : 10
index :1          element : 5
index :2          element : 20
index :3          element : 30
index :4          element : 45
1.insert
2.search
3.display
4.exit
enter the choice : 2
enter the elemnet to search  : 20
element 20 found at index 2
1.insert
2.search
3.display
4.exit
enter the choice : 4
*/	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

