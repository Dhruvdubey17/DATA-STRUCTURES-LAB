#include<stdio.h>
#define Max 100
char stack[Max];
int top = -1;

void push(char ch)
{
	if(top==Max-1) {
		printf("Stack Full!\n");
	}
	else
	{
		top++;
		stack[top] = ch;
	}
}


char pop() 
{
	char item;
	if(top==-1)
		printf("Empty Stack!\n");
	else 
	{
		item = stack[top];
		top--;
		return item;
	}
}

int stackempty()
{
	if(top==-1)
		return 1;
	return 0;
}

char stacktop()
{
	if(top==-1) {
		printf("Empty stack\n");
	}
	else
		return stack[top];
}

int priority(char ch)
{
	switch(ch) {
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
		default:  return 0;
	}
}


int main() 
{
	char infix[100];
	int i,item;
	printf("Enter the infix expression: ");
	scanf("%s",infix);
	printf("Infix Expression: %s\n",infix);
	printf("Postfix Expression: ");
	i=0;
	while(infix[i] != '\0') {
		switch(infix[i]) {
			case '(' : push(infix[i]);
					   break;
			case ')' : while((item = pop())!='(') {
						   printf("%c",item);
					   
					  	}
					  	break;

			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
					   while(!stackempty() &&priority(infix[i])<=priority(stacktop()))
					   {
					   	item = pop();
					   	printf("%c",item);
					   }
					   push(infix[i]);
					   break;

			default: printf("%c",infix[i]);
					 break;
		}
		i++;
	}
	while(!stackempty()) {
		printf("%c",pop());
	}

	return 0;
}
