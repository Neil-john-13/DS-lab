//Quick sort and merge sort


#include<stdio.h>
#include<stdlib.h>

int partition(int a[20],int low,int high)
{
	int i,j,pivot,temp;
	i=low-1;
	pivot=a[high];
	for(j=low;j<high;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[high];
	a[high]=temp;
	return i+1;
}
void Qsort(int a[20],int low,int high)
{
	int pi;
	if(low<high)
	{
		pi=partition(a,low,high);
		Qsort(a,low,pi-1);
		Qsort(a,pi+1,high);
	}
}
void merge(int a[20],int l,int m,int u)
{
	int i,j,k,n1,n2;
	int b[20],c[20];
	n1=m-l+1;
	n2=u-m;
	for( i=0;i<n1;i++)
	{
		b[i]=a[l+i];
	}
	for( j=0;j<n2;j++)
	{
		c[j]=a[m+1+j];
	}
	k=l;
	i=j=0;
	while(i<n1 && j<n2)
	{
		if(b[i]<=c[j])
		{
			a[k]=b[i];
			i++;
		}
		else
		{
			a[k]=c[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=b[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=c[j];
		j++;
		k++;
	}
	
}
void Msort(int a[20],int l,int u)
{
	int m;
	if(l<u)
	{
		m=(l+u)/2;
		Msort(a,l,m);
		Msort(a,m+1,u);
		merge(a,l,m,u);
	}
}
void main()
{
	int n,c=1,a[20];
	while(c>0)
	{
		printf("\n1.Quick sort \n2. Merge Sort \n3. Exit \nenter the choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("enter the number of element : ");
				scanf("%d",&n);
				for(int i=0;i<n;i++)
				{
					printf("enter the element : ");
					scanf("%d",&a[i]);
				}
				Qsort(a,0,n-1);
				printf("the sorted array :");
				for(int i=0;i<n;i++)
				{
					printf("%d\t",a[i]);
				}
				break;
			case 2:
				printf("enter the number of element : ");
				scanf("%d",&n);
				for(int i=0;i<n;i++)
				{
					printf("enter the element : ");
					scanf("%d",&a[i]);
				}
				Msort(a,0,n-1);
				printf("the sorted array :");
				for(int i=0;i<n;i++)
				{
					printf("%d\t",a[i]);
				}
				break;
			case 3:
				exit(0);
				break;
			default :
				printf("invalid choice !" );
		}
	}
}

/*_______________OUTPUT________________
1.Quick sort 
2. Merge Sort
3. Exit
enter the choice : 1
enter the number of element : 5
enter the element : 46
enter the element : 34
enter the element : 22
enter the element : 90
enter the element : 6
the sorted array :6     22      34      46      90
1.Quick sort
2. Merge Sort
3. Exit
enter the choice : 2
enter the number of element : 6
enter the element : 43
enter the element : 89
enter the element : 32
enter the element : 77
enter the element : 6
enter the element : 34
the sorted array :6     32      34      43      77      89
1.Quick sort
2. Merge Sort
3. Exit
enter the choice : 3
*/
