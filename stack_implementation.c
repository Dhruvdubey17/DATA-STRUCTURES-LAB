#include<stdio.h>
#include<stdbool.h>

#define MAX 5
int top = -1;
int stack[MAX];

void push(int ele) {
	if(top == MAX -1) {
		printf("Stack overflow\n");
	}
	else {
		top++;
		stack[top] = ele;
		printf("%d is pushed into the stack \n",ele);
	}
}

bool empty() {
	if(top==-1) {
		return true;
	}
	return false;
}

void pop(int *stack) {
	if(!empty()) {
		printf("%d popped out\n",stack[top]);
		top--;
	}

	else 
		printf("Stack Underflow\n");
	
}

void display(int *stack) {
	int i;
	if(top==-1) {
		printf("Stack is empty.\n");
	}
	else {
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
	

int main() {
	int element;
	printf("Select from the choices available: \n");
	printf("1.Push\t2.Pop\t3.Display\t4.Exit\n"); 
	int option;
	printf("Enter your choice : ");
	scanf("%d",&option);
	while(option!=4) {
		switch(option) {
			case 1: printf("Enter element to be pushed: ");
					scanf("%d",&element);
					push(element);
					break;
			case 2: pop(stack);
					break;

			case 3: display(stack);
					break;
		}
		printf("Enter your next choice : ");
		scanf("%d",&option);
	}
	return 0;
}
