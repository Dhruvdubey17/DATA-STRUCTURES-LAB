#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node* head;

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

void delete_at_first() {
	if(head==NULL) {
		printf("No elements present to delete\n");
		return;
	}

	struct node*temp = head;
	head = head->next;

	free(temp);
	printf("Element at first node deleted\n");
}

void delete_at_end() {
	if(head == NULL) {
		printf("No elements present to delete\n");
		return;
	}

	if(head->next == NULL) {
		delete_at_first();
		return;
	}
	struct node*temp = head;
	while(temp->next->next!=NULL) {
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
	printf("Element at last deleted\n");
}

void delete_at_anypos(int pos) {
	if(head == NULL) {
		printf("No elements present to delete\n");
		return;
	}
	if(pos == 1) {
		delete_at_first();
		return;
	}

	if(pos > length()) {
		delete_at_end();
		return;
	}
	struct node*prev = head;
	int jump = 1;
	while(jump<pos-1) {
		prev = prev->next;
		jump++;
	}
	struct node*temp = prev->next;
	prev->next = temp->next;
	free(temp);
	printf("Element at %d deleted\n",pos);
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
	int choice,pos;
	printf("1.Insert at back\n2.Delete at front\n3.Delete at end\n4.Delete at any position\n5.Display\n6.Exit\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	while(choice!=6) {
		if(choice == 1) {
			insert_at_end();
		}
		else if(choice == 2) {
			delete_at_first();
		}
		else if(choice == 3) {
			delete_at_end();
		}
		else if(choice == 4) {
			printf("Enter postion of the element you want to delete : ");
			scanf("%d",&pos);
			delete_at_anypos(pos);
		}
		else if(choice == 5) {
			display();
		}
		else {
			break;
		}
		printf("Enter your next choice : ");
		scanf("%d",&choice);

	}
	return 0;
}
