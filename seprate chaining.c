#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *link;
};
struct node *H[5];
int size =5;
void init()
{
    int i;
    for(i = 0; i < size; i++)
        H[i] = NULL;
}
void insert(int x)
{
    int hkey;
    struct node * temp=(struct node *)malloc(sizeof(struct node ));
    temp->key=x;
    temp->link=NULL;
    hkey=x%size;
    struct node*ptr;
    if(H[hkey]==NULL)
    {
        H[hkey]=temp;
        return;
    }
    else
    {
        ptr=H[hkey];
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
}
void display()
{
    for(int i=0;i<size;i++)
    {
        printf("chain[%d]  ->  ",i);
        struct node*ptr=H[i];
        while(ptr)
        {
            printf("%d  ",ptr->key);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
void main()
{
    int x,n;
    init();
    while(1)
    {
        printf("\n1.insert \n2.search \n3.display \n4.exit \nenter the choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("enter the element to insert :");
                scanf("%d",&x);
                insert(x);
                break;
            case 2:
                //search();
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