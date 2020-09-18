#include<stdio.h>
#include<string.h>
struct details {
	char name[10];
	int age;
	int marks;
};

int main() {
	struct details d[100];
	int n;
	printf("Enter the number of students applying for addmission :");
	scanf("%d",&n);

	printf("Enter the asked details of students: \n");

	for(int i=0;i<n;i++) {
		printf("Enter the name,age and marks of the student %d : \n",i+1);
		scanf("%s %d %d",&d[i].name,&d[i].age,&d[i].marks);
	}

	for(int i=0;i<n;i++) {
		printf("Admission list\n");
		printf("S no. \tName \tAge \tMarks \tResult\n");
		if(d[i].marks>65 && d[i].marks<100 && d[i].age<20) {
			printf("%d \t%s \t%d \t%d \tADMITTED\n",i,d[i].name,d[i].age,d[i].marks);
		}
		else
			printf("%d \t%s \t%d \t%d \tNOT ADMITTED\n",i,d[i].name,d[i].age,d[i].marks);
	}
	printf("---------End of List---------");
	return 0;
}
