#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Employee {
int SSN;
char name[50], dept[50], designation[50];
float salary;
long int phone;
struct Employee *prev, *next;
} Employee;
Employee* head = NULL;
Employee* createEmployee(int SSN, char* name, char* dept, char* designation, float salary, long int phone) {
Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
newEmployee->SSN = SSN;
strcpy(newEmployee->name, name);
strcpy(newEmployee->dept, dept);
strcpy(newEmployee->designation, designation);
newEmployee->salary = salary;
newEmployee->phone = phone;
newEmployee->prev = newEmployee->next = NULL;
return newEmployee;
}
void insertEnd(int SSN, char* name, char* dept, char* designation, float salary, long int phone) {
Employee* newEmployee = createEmployee(SSN, name, dept, designation, salary, phone);
if (!head) head = newEmployee;
else {
Employee* temp = head;
while (temp->next) temp = temp->next;
temp->next = newEmployee;
newEmployee->prev = temp;
}
}
void displayDLL() {
Employee* temp = head;
int count = 0;
if (!temp) {
printf("Doubly Linked List is empty.\n");
return;
}
while (temp) {
printf("SSN: %d, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, Phone: %ld\n",
temp->SSN, temp->name, temp->dept, temp->designation, temp->salary, temp->phone);
temp = temp->next;
count++;
}
printf("Total employees: %d\n", count);
}
void insertAtEnd() {
int SSN;
char name[50], dept[50], designation[50];
float salary;
long int phone;
printf("Enter SSN: ");
scanf("%d", &SSN);
printf("Enter Name: ");
scanf("%s", name);
printf("Enter Department: ");
scanf("%s", dept);
printf("Enter Designation: ");
scanf("%s", designation);
printf("Enter Salary: ");
scanf("%f", &salary);
printf("Enter Phone: ");
scanf("%ld", &phone);
insertEnd(SSN, name, dept, designation, salary, phone);
}
void deleteEnd() {
if (!head) {
printf("List is empty.\n");
return;
}
Employee* temp = head;
if (!head->next) {
free(head);
head = NULL;
} else {
while (temp->next) temp = temp->next;
temp->prev->next = NULL;
free(temp);
}
}
void insertFront(int SSN, char* name, char* dept, char* designation, float salary, long int phone) {
Employee* newEmployee = createEmployee(SSN, name, dept, designation, salary, phone);
if (head) head->prev = newEmployee;
newEmployee->next = head;
head = newEmployee;
}
void deleteFront() {
if (!head) {
printf("List is empty.\n");
return;
}
Employee* temp = head;
if (head->next) {
head = head->next;
head->prev = NULL;
} else {
head = NULL;
}
free(temp);
}
int main() {
int choice;
do {
printf("\n1. Insert at end\n2. Display\n3. Insert at front\n4. Delete from end\n5. Delete from front\n6. Exit\nChoice: ");
scanf("%d", &choice);
switch (choice) {
case 1: insertAtEnd(); break;
case 2: displayDLL(); break;
case 3: {
int SSN;
char name[50], dept[50], designation[50];
float salary;
long int phone;
printf("Enter SSN, Name, Dept, Designation, Salary, Phone: ");
scanf("%d %s %s %s %f %ld", &SSN, name, dept, designation, &salary, &phone);
insertFront(SSN, name, dept, designation, salary, phone);
break;
}
case 4: deleteEnd(); break;
case 5: deleteFront(); break;
case 6: printf("Exiting...\n"); break;
default: printf("Invalid choice\n");
}
} while (choice != 6);
return 0;
}