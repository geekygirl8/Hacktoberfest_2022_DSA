//Operations performed on stack--PUSH,POP,Traverse
#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10
int stack[MAXSIZE];
int top=-1;
void push()
{
	int item;
	if(top==MAXSIZE-1)
	{
		printf("The stack is full!! \n");
		exit(0);
	}
	else{
		printf("Enter the element to be inserted \n");
		scanf("%d",&item);
		top=top+1;
		stack[top]=item;
	}
}
int pop()
{
	int item;
	if(top==-1)
	{
		printf("The stack is empty \n");
		exit(0);
	}
	else{
		item=stack[top];
		top=top-1;
	}
	return item;
}
void traverse()
{
	int i;
	if(top==-1)
	{
		printf("The stack is empty");
		exit(0);
	}
	else{
		printf("Traverse the element: \n");
		for(i=top;i>=0;i--)
		{
			printf("%d \n",stack[i]);
		}
	}
}
void main()
{
	int choice;
	char ch;
	do{
		printf("1.PUSH \n");
		printf("2.POP\n");
		printf("3.Traverse \n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();
			break;
			case 2:printf("The deleted element is %d \n",pop());
			break;
			case 3:traverse();
			break;
			default:printf("You Entered Wrong Choice\n");
		}
		printf("\n Do you Wish to continue..(Y/N)");
		fflush(stdin);
		scanf("%c",&ch);
	}
	while(ch=='Y'||ch=='y');
}


