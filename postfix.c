// infix to postfix and postfix evaluation

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char stack[20],postfix[20];
int stack1[20];
int top=-1,size=20;
void push(char item)
{
	if(top==size-1)
	{
		printf("\nstack Overflow\n");
	}
	top++;
	stack[top]=item;
}
char pop()
{
	char c;
	if(top==-1)
	{
		printf("invalid expression ");
		exit(0);
	}
	c=stack[top];
	top--;
	return c;
}
void push_evl(int item)
{
	if(top==size-1)
	{
		printf("\nstack Overflow\n");
	}
	top++;
	stack1[top]=item;
}
int pop_evl()
{
	int c;
	if(top==-1)
	{
		printf("invalid expression ");
	}
	c=stack1[top];
	top--;
	return c;
}
int precedence(char symbol)
{
	switch(symbol)
	{
		case '^':
			return 3;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
		case '-':
			return 1;
			break;
		case '+':
			return 1;
			break;
		default :
			return 0;
	}		
}
void main()
{
	char next,symbol;
	char infix [20];
	int j=0,i;
	printf("Enter the infix expression : ");
	scanf("%s",infix);
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		
		if(symbol != ' ' && symbol !='\t')
		{
			switch(symbol)
			{
				case '(' :
					printf("%c",symbol);
					push(symbol);
					break;
				case ')' :
					printf("%c",symbol);
					while((next=pop())!='(')
					{
					 	postfix[j++]=next;
					}
					break;
				case '+' :
				case '-' :
				case '/' :
				case '*' :
					printf("%c",symbol);
					while(top!=-1 && precedence(stack[top])>=precedence(symbol))
					{
						postfix[j++]=pop();
					}
					push(symbol);
					break;
				case '^' :
					printf("%c",symbol);
					while(top!=-1 && precedence(stack[top])>precedence(symbol))
					{
						postfix[j++]=pop();
					}
					push(symbol);
					break;
				default:
					printf("%c",symbol);
					postfix[j++]=symbol;
			}
		}
	}
	while(top!=-1)
	{
		postfix[j++]=pop();
	}
	postfix[j]='\0';
	printf("\nthe equivalent postfix expression : %s ",postfix);
	int a,b;
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]>='0'&& postfix[i]<='9')
		{
			push_evl(postfix[i]-'0');
		}
		else
		{
			a= pop_evl();
			b= pop_evl();
			switch(postfix[i])
			{
				

				
				case '+' :
					push_evl(b+a);
					break;
				case '-' :
					push_evl(b-a);
					break;
				case '/' :
					push_evl(b/a);
					break;
				case '*' :
					push_evl(b*a);
					break;
				case '^' :
					push_evl(pow(b,a));
					break;
			}
		}
		
	}
	printf("\npostfix evaluated : %d",pop_evl());
}



/*_______________OUTPUT________________

Enter the infix expression : 4+5*(5+6)^2^1       
4+5*(5+6)^2^1
the equivalent postfix expression : 4556+21^^*+ 
postfix evaluated : 609

*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
