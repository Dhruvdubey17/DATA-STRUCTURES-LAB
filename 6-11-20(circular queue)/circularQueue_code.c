#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void push(int data) {
	if((front == 0 && rear == MAX-1) || front == rear+1) {
		printf("Queue is full\n");
	}
	else {
		rear = (rear+1)%MAX;
		queue[rear] = data;
		if(front == -1) {
			front =0;
		}
	}
}

int pop() {
	int item;
	if(front==-1 && rear ==-1) {
		return -999;
	}

	else {
		item = queue[front];
		if(front==rear){
			front = -1;
			rear = -1;
		}
		else
			front = (front+1)%MAX;
		return item;
	}
}

void display() {
	if((front==-1 && rear == -1)||front == rear) {
		printf("Queue is empty\n");
	}
	else {
		printf("Contents of the queue : \n");
		for(int i=front;i<=rear;i++) {
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
}
int main() {
	int choice;
	int item;
	printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	while(choice!=4) {
		switch(choice) {
			case 1: printf("Enter item to be enqueued : ");
					scanf("%d",&item);
					push(item);
					break;

			case 2: item = pop();
					if(item == -999) {
						printf("Queue underflow\n");
					}
					else
						printf("%d has been dequeued.\n",item);
					break;

			case 3: display();
					break;
		}
		printf("Enter your choice : ");
		scanf("%d",&choice);
	}

}
