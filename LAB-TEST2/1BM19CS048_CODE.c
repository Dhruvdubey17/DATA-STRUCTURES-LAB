#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	char name[20],usn[20];
	struct Node*prev;
	struct Node*next;
}node;

void insert(node**head,char na[20],char u[20]) {
	if(*head == NULL) {
		*head = (node*)malloc(sizeof(node));
		(*head)->prev = NULL;
		strcpy((*head)->name,na);
		strcpy((*head)->usn,u);
		(*head)->next = NULL;
		return;
	}
	node*temp = *head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	node*n = (node*)malloc(sizeof(node));
	strcpy(n->name,na);
	strcpy(n->usn,u);
	n->next = NULL;
	n->prev = temp;
	temp->next = n;
}

void delete(node**head,char u[20]) {
	node*temp = *head;
	while(temp!=NULL) {
		if(strcmp(temp->usn,u) == 0) {
			if(temp == *head) {
				*head = (*head)->next;
				(*head)->prev = NULL;
				printf("Deleted USN %s\n",temp->usn);
			}
			else {
				if(temp->next == NULL) {
					temp->prev->next = NULL;
				}
				else {
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
				}
				printf("Deleted USN %s",temp->usn);
				free(temp);
			}
			return;
		}
		temp = temp->next;
	}
}

void display(node*head) {
	int cnt = 0;
	while(head!=NULL) {
		printf("Student %d\n",cnt);
		printf("USN : %s",head->usn);
		printf("Name : %s\n",head->name);
		head = head->next;
		cnt++;
	}
}

int main() {
	char name[20],usn[20];
	int n;
	node*head = NULL;
	printf("Enter number of students you want to enter: ");
	scanf("%d",&n);
	getchar();
	printf("Enter the details of the students: \n");
	for(int i=0;i<n;i++) {
		printf("Student %d:\n",i);
		printf("USN : ");
		fgets(usn,20,stdin);
		printf("Name : ");
		fgets(name,20,stdin);
		insert(&head,name,usn);
	}
	printf("\nPerform delete operation\n");
	printf("1.Delete student\n2.Display\n3.Exit\n");
	int opt;
	printf("Enter your choice : ");
	scanf("%d",&opt);
	getchar();
	while(opt!=3) {
		if(opt == 1) {
			printf("Enter the USN to be deleted : ");
			char key[20];
			fgets(key,20,stdin);
			delete(&head,key);
		}
		if(opt == 2) {
			printf("Student List\n");
			display(head);
		}
		printf("1.Delete student\n2.Display\n3.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&opt);
		getchar();
	}
	return 0;
}








