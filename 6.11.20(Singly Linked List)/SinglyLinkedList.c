#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node *head = NULL;


int length() {
	struct node*temp = head;
	int cnt = 0;

	while(temp->next!=NULL) {
		cnt++;
		temp = temp->next;
	}
	return cnt+1;
}
void insert_at_end() {
	struct node *newnode, *temp;
	int item;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d",&item);

	newnode->data = item;
	if(head == NULL) {
		newnode->next = NULL;
		head = newnode;
		printf("Node Created\n");
	}
	else{
		temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = NULL;
		printf("Node Created at the end.\n");
	}
}

void insert_at_first() {
	if(head == NULL) {
		insert_at_end();
		return;
	}
	struct node *newnode;
	int ele;
	printf("Enter the element to be inserted at first position : ");
	scanf("%d",&ele);
	newnode = (struct node*)malloc(sizeof(struct node));

	newnode->data = ele;
	newnode->next = head;
	head = newnode;
	printf("Element inserted at the first position of the list.\n");
}

void insert_at_anypos(int pos) {
	if(head==NULL) {
		insert_at_first();
		return;
	}

	if(pos>length()) {
		insert_at_end();
		return;
	}

	struct node *newnode ,*temp;
	temp = head;
	int ele;
	printf("Enter the element to be inserted : ");
	scanf("%d",&ele);
	int jump = 1;
	while(jump<pos-1) {
		temp = temp->next;
		jump++;
	}
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = ele;
	newnode->next = temp->next;
	temp->next = newnode;
	printf("Element inserted at position %d\n",pos);
}

void display() {
	struct node* ptr = NULL;
	ptr = head;
	if(ptr == NULL)
		printf("No data to print\n");
	else{
		printf("List Contents : \n");
		while(ptr!=NULL) {
			printf("%d ",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

int main() {
	int choice;
	int pos;
	printf("SINGLY LINKED LIST\n");
	printf("1.Insert at back\t2.Insert at front\t3.Insert at any position\t4.Display\t5.Exit\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);

	while(choice!=5) {
		switch(choice) {
			case 1: insert_at_end();
					break;
			case 2: insert_at_first();
					break;

			case 3:
					printf("Enter the postion you want to insert the new element at : ");
					scanf("%d",&pos);
					if(pos==1) {
						insert_at_first();
						break;
					}
					insert_at_anypos(pos);
					break;
			case 4: display();
					break;
		}
		printf("1.Insert at back\t2.Insert at front\t3.Insert at any position\t4.Display\t5.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
	}


	return 0;

}
