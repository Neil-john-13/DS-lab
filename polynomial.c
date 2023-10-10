
// polynomial additiona nd multiplication using linked list


#include<stdio.h>
#include<stdlib.h>
struct node
{
	float coef;
	int expo;
	struct node* link;
};
void print(struct node* head)
{
	if(head==NULL)
	{
		printf("no Polynomial");
	}
	else
	{
		struct node* temp=head;
		while(temp!=NULL)
		{
			printf("(%.lfx^%d)",temp->coef,temp->expo);
			temp=temp->link;
			if(temp!=NULL)
			{
				printf("+");
			}
			else
			{
				printf("\n");
			}
		}	
	}
	
}
struct node* insert(struct node*head,float co,int ex)
{
	struct node* temp=NULL;
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	ptr->coef=co;
	ptr->expo=ex;
	ptr->link=NULL;
	int flag=0;
	if(head==NULL||(ex > head->expo))
	{
		ptr->link=head;
		head=ptr;
	}
	else
	{
		temp=head;
		if(temp->expo==ptr->expo)
		{
			temp->coef=temp->coef+ptr->coef;
			flag=1;
		}
		while(temp->link != NULL && temp->link->expo >=ex)
		{
			
			temp=temp->link;
			if(temp->expo==ptr->expo)
			{
				temp->coef=temp->coef+ptr->coef;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			ptr->link=temp->link;
			temp->link=ptr;
		}
	}
	return head;
}
struct node* create(struct node* head)
{
	int i,m,ex;
	float co;
	printf("enter Number of terms in the polynomial : ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("enter coefficent of the term %d: ",i+1);
		scanf("%f",&co);
		printf("enter exponent of the term %d: ",i+1);
		scanf("%d",&ex);
		head=insert(head,co,ex);
	}
	print(head);
	return head;
}
void add(struct node* head1,struct node* head2)
{
	struct node* ptr1=head1;
	struct node* ptr2=head2;
	struct node* head3=NULL;
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->expo==ptr2->expo)
		{
			head3=insert(head3,ptr1->coef+ptr2->coef,ptr1->expo);
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		else if(ptr1->expo>ptr2->expo)
		{
			head3=insert(head3,ptr1->coef,ptr1->expo);
			ptr1=ptr1->link;
		}
		else if(ptr1->expo<ptr2->expo)
		{
			head3=insert(head3,ptr2->coef,ptr2->expo);
			ptr2=ptr2->link;
		}
	}
	while(ptr1!=NULL)
	{
		head3=insert(head3,ptr1->coef,ptr1->expo);
		ptr1=ptr1->link;	
	}
	while(ptr2!=NULL)
	{
		head3=insert(head3,ptr2->coef,ptr2->expo);
		ptr2=ptr2->link;
	}
	print(head3);
}
void multiply(struct node* start1,struct node* start2)
{
	struct node* ptr1=start1;
	struct node* ptr2=start2;
	struct node* head3=NULL;
	while(ptr1!=NULL)
	{
		while(ptr2!=NULL)
		{
			head3=insert(head3,ptr1->coef * ptr2->coef,ptr1->expo+ptr2->expo);
			ptr2=ptr2->link;
		}
		ptr1=ptr1->link;
		ptr2=start2;
	}
	print(head3);
}
void main ()
{
	int n,p=1;
	while(p)
	{
		struct node* head1 = NULL;
		struct node* head2 = NULL;
		struct node* start1=NULL;
		struct node* start2=NULL;
		printf("\n1. Addition\n2. multiplication\n3. Exit\nEnetr your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\nfirst polynomial\n");
				head1=create(head1);
				printf("\nSecond polynomial\n");
				head2=create(head2);
				add(head1,head2);
				break;
			case 2:
				printf("\nfirst polynomial\n");
				start1=create(start1);
				printf("\nSecond polynomial\n");
			 	start2=create(start2);
			 	printf("\n");
				multiply(start1,start2);
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("invalid Choice !");
		}
	}
			
}

/*_______________OUTPUT________________

1. Addition
2. multiplication
3. Exit
Enetr your choice : 1

first polynomial
enter Number of terms in the polynomial : 3
enter coefficent of the term 1: 3
enter exponent of the term 1: 2
enter coefficent of the term 2: 5
enter exponent of the term 2: 1
enter coefficent of the term 3: 6
enter exponent of the term 3: 0
(3x^2)+(5x^1)+(6x^0)

Second polynomial
enter Number of terms in the polynomial : 5
enter coefficent of the term 1: 4
enter exponent of the term 1: 2
enter coefficent of the term 2: 1
enter exponent of the term 2: 1
enter coefficent of the term 3: 4
enter exponent of the term 3: 0
enter coefficent of the term 4: 0
enter exponent of the term 4: 0
enter coefficent of the term 5: 0
enter exponent of the term 5: 0
(4x^2)+(1x^1)+(4x^0)
(7x^2)+(6x^1)+(10x^0)

1. Addition
2. multiplication
3. Exit
Enetr your choice : 2

first polynomial
enter Number of terms in the polynomial : 3
enter coefficent of the term 1: 3
enter exponent of the term 1: 2
enter coefficent of the term 2: 5
enter exponent of the term 2: 1
enter coefficent of the term 3: 6
enter exponent of the term 3: 0
(3x^2)+(5x^1)+(6x^0)

Second polynomial
enter Number of terms in the polynomial : 2
enter coefficent of the term 1: 6
enter exponent of the term 1: 2
enter coefficent of the term 2: 3
enter exponent of the term 2: 0
(6x^2)+(3x^0)

(18x^4)+(30x^3)+(45x^2)+(15x^1)+(18x^0)

1. Addition
2. multiplication
3. Exit
Enetr your choice : 3

*/





