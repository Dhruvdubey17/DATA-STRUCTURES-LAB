#include<stdio.h>
#define Max 5
//intializing front and rear
int front = 0;
int rear = -1;
//intializing queue
int queue[Max];

//Func to push into queue
void push(int d) {
	if(rear == Max - 1) 
		printf("Queue is full\n");

	else
    {
      rear++;
      queue[rear]=d;
                    
    }
}

//Func to delete from queue
int pop()
{
    int item;
    if(front == -1)
        return -1;
    else 
    {
        item=queue[front];
        front++;
        if(front>rear)
        {
            front=-1;
            rear=-1;
        }
        return item;
    }
    
}

//Func to display
void display() {
	if(front==-1) {
		printf("No elements present in the queue to display!\n");
		return;
	}

	else {
		for(int i=front;i<=rear;i++) {
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
}

int main() {
	int choice;
	int ele;
	printf("1.Insert in Queue\n 2.Delete from Queue\n 3.Display Queue\n 4.Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);


	while(choice!=4) {
		switch(choice) {
			case 1:
				printf("Enter the element: ");
				scanf("%d",&ele);
				push(ele);
				break;

			case 2:
				ele = pop();
				if(ele==-1) {
					printf("Queue is empty!\n");
					break;
				}
				printf("%d is popped out from queue\n",ele);
				break;

			case 3:
				display();
				break;
		}
		printf("Enter your choice: ");
		scanf("%d",&choice);
	}
	printf("Exit \n");
	return 0;
}
