//Binary search and linear search

#include<stdio.h>
void main()
{
	int n,l,a[100],x,flag=0,i,temp,high,low,mid,y=1;
	printf("1. Linear search\n2. Binary Search\n3. Exit");
	while(y==1)
	{
		printf("\nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\nEnter the size of array : ");
				scanf("%d",&l);
				printf("\nEnter the elements : ");
				for (int i=0;i<l;i++)
				{
					scanf("%d",&a[i]);
				}
				printf("\nEnter the element to search : ");
				scanf("%d",&x);
				for (i=0;i<l;i++)
				{	
					if(a[i]==x)
					{
						flag=1;
						break;
					}	
				}
				if(flag==1)
				{	
					printf("element %d found at position %d",x,i+1);
				}
				else
				{
					printf("element not found ");
				}
				break;
			case 2:
				printf("\nEnter the size of array : ");
				scanf("%d",&l);
				printf("\nEnter the elements : ");
				for (int i=0;i<l;i++)
				{
					scanf("%d",&a[i]);
				}
				for (i=0;i<l-1;i++)
				{
					for (int j=0;j<l-i-1;j++)
					{
						if(a[j]>a[j+1])
						{
							temp=a[j];
							a[j]=a[j+1];
							a[j+1]=temp;
						}
					}
				}
				printf("\nEnter the element to search : ");
				scanf("%d",&x);
				high=l-1;
				low=0;
				while(low<=high)
				{
					mid=(high+low)/2;
					if(x==a[mid])
					{
						printf("\nElement found");
						flag=1;
						break;
					}
					else if(x>a[mid])
					{
						low=mid+1;
					}
					else 
					{
						high=mid-1;
					
					}
				}
				if(flag==0)	
				{
					printf("\nElement not found ");
				}
				break;
			case 3:
				y=0;
				break;
			default:
				printf("\nInvalid choice");
		}
	}
}
/*_______________OUTPUT________________

1. Linear search
2. Binary Search
3. Exit
Enter your choice : 1

Enter the size of array : 5

Enter the elements : 6 
7
8
54
6

Enter the element to search : 8
element 8 found at position 3
Enter your choice : 2

Enter the size of array : 5

Enter the elements : 6
2
7
4
9

Enter the element to search : 4

Element found
Enter your choice : 3

*/
	
