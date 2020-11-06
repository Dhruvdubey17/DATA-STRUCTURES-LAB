#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data) {
	if((front == 0 && rear == MAX-1) || front == rear+1) {
		printf("Queue is full\n");
	}
	else if (front == -1 && rear == -1)
	{
		front++;
		rear++;
		queue[rear] = data;
	}
	else {
		rear = (rear+1)%MAX;
		queue[rear] = data;
	}
}

int dequeue() {
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
	if(front==-1 && rear == -1) {
		printf("Queue is empty\n");
	}
	else {
		printf("Contents of the queue : \n");
		if(front<=rear) {
			for(int i=front;i<=rear;i++) {
				printf("%d ",queue[i]);
			}
			printf("\n");

		}
		else {
			for (int i = front; i <= MAX-1; i++) {
				printf("%d ", queue[i]);
			}
			for (int i = 0; i <= rear; i++) {
				printf("%d ", queue[i]);
			}
			printf("\n");
		}
	}
}
int main() {
	int choice;
	int item;
	printf("1.Insert\t2.Delete\t3.Display\t4.Exit\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	while(choice!=4) {
		switch(choice) {
			case 1: printf("Enter item to be enqueued : ");
					scanf("%d",&item);
					enqueue(item);
					break;

			case 2: item = dequeue();
					if(item == -999) {
						printf("Queue underflow\n");
					}
					else
						printf("%d has been dequeued.\n",item);
					break;

			case 3: display();
					break;
		}
		printf("1.Insert\t2.Delete\t3.Display\t4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
	}

}
