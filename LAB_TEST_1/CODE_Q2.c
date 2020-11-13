#include<stdio.h>
#include<stdbool.h>
#define MAX 100

struct stack{
	int arr[MAX];
	int top;
};
//initialize the stack
void init(struct stack *s){
	s->top = -1;
}

void push(struct stack *s,int d){
	if(s->top == MAX-1){
		printf("Stack Overflow\n");
		return;
	}
	s->top++;
	s->arr[s->top]=d;
	printf("%d plate added to pile\n",d);
}

void pop(struct stack *s){
	if(s->top==-1){
		printf("Stack Underflow\n");
		return;
	}
	int d;
	printf("%d was popped\n",s->arr[s->top]);
	s->top--;
}

void display(struct stack s){
	if(s.top==-1){
		printf("No items in stack\n");
		return;
	}
	for(int i=s.top;i>=0;i--){
		printf("( %d )\n",s.arr[i]);
	}
}

bool empty(struct stack s) {
    return s.top==-1;
}



int main(){
	struct stack s1,s2,s3;
	int data;
	init(&s1);
	init(&s2);
	init(&s3);

	printf("1.Put more plates on stack 1\n2.No more plates\n");
	int opt;
	printf("Your Choice : ");
	scanf("%d",&opt);
	while(opt!=2) {
		if(opt == 1) {
			printf("Enter the plate number you putting on the pile: ");
			scanf("%d",&data);
			push(&s1,data);		
		}
		printf("1.Put more plates on stack 1\n2.No more plates\n");
		printf("Your choice : ");
		scanf("%d",&opt);
	}
	printf("Contents in the pile of stack\n");
	display(s1);
	printf("\n");

	while(!empty(s1)) {
		if(s1.arr[s1.top]%2 == 0) {
			push(&s2,s1.arr[s1.top]);
			pop(&s1);
		}
		else {
			push(&s3,s1.arr[s1.top]);
			pop(&s1);
		}

	}


	printf("\nContents of the first table\n");
	display(s2);

	printf("\nContents of the second table\n");
	display(s3); 
}
