#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
char usn[20], name[50], programme[50], phNo[15];
int sem;
struct Student *next;
};
typedef struct Student Student;
Student* createNode() {
Student *newNode = (Student*)malloc(sizeof(Student));
if(!newNode) {
printf("Memory allocation failed!\n");
return NULL;
}
printf("Enter USN: ");
scanf("%s", newNode->usn);
printf("Enter Name: ");
scanf("%s", newNode->name);
printf("Enter Programme: ");
scanf("%s", newNode->programme);
printf("Enter Semester: ");
scanf("%d", &newNode->sem);
printf("Enter Phone Number: ");
scanf("%s", newNode->phNo);
newNode->next = NULL;
return newNode;
}
Student* insertFront(Student *head) {
Student *newNode = createNode();
if(!newNode) return head;
newNode->next = head;
return newNode;
}
void display(Student *head) {
if(!head) {
printf("The list is empty!\n");
return;
}
Student *temp = head;
int count = 0;
printf("\nStudent Data in Linked List:\n");
while(temp) {
printf("USN: %s, Name: %s, Programme: %s, Semester: %d, Phone: %s\n",
temp->usn, temp->name, temp->programme, temp->sem, temp->phNo);
temp = temp->next;
count++;
}
printf("Total number of students: %d\n", count);
}
Student* insertEnd(Student *head) {
Student *newNode = createNode();
if(!newNode) return head;
if(!head) return newNode;
Student *temp = head;
while(temp->next) temp = temp->next;
temp->next = newNode;
return head;
}
Student* deleteFront(Student *head) {
if(!head) {
printf("List is empty, nothing to delete!\n");
return NULL;
}
Student *temp = head;
head = head->next;
printf("Deleted student with USN: %s\n", temp->usn);
free(temp);
return head;
}
Student* deleteEnd(Student *head) {
if(!head) {
printf("List is empty, nothing to delete!\n");
return NULL;
}
if(!head->next) {
printf("Deleted student with USN: %s\n", head->usn);
free(head);
return NULL;
}
Student *temp = head, *prev = NULL;
while(temp->next) {
prev = temp;
temp = temp->next;
}
prev->next = NULL;
printf("Deleted student with USN: %s\n", temp->usn);
free(temp);
return head;
}
int main() {
Student *head = NULL;
int choice;
while(1) {
printf("\nMenu:\n");
printf("1. Create SLL using front insertion\n");
printf("2. Display the SLL and count nodes\n");
printf("3. Insert at end\n");
printf("4. Delete from end\n");
printf("5. Insert at front (stack demonstration)\n");
printf("6. Delete from front (stack demonstration)\n");
printf("7. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice) {
case 1: head = insertFront(head); break;
case 2: display(head); break;
case 3: head = insertEnd(head); break;
case 4: head = deleteEnd(head); break;
case 5: head = insertFront(head); break;
case 6: head = deleteFront(head); break;
case 7: printf("Exiting the program.\n"); return 0;
default: printf("Invalid choice! Please try again.\n");
}
}
return 0;
}