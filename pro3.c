#include <stdio.h>
#include <stdlib.h>
int *stack, top = -1, size;
void push() {
int num;
if(top == size - 1) printf("Stack Overflow\n");
else {
printf("Enter the number to be pushed\n");
scanf("%d", &num);
stack[++top] = num;
}
}
void pop() {
if(top == -1) printf("Stack Underflow\n");
else printf("Popped element is %d\n", stack[top--]);
}
void display() {
if(top == -1) printf("Stack is Empty\n");
else {
printf("Stack Contents....\n");
for(int i = top; i >= 0; i--) printf("%d\n", stack[i]);
}
}
int pali() {
for(int i = 0; i <= top / 2; i++) {
if(stack[i] != stack[top - i]) return 0;
}
return 1;
}
int main() {
int choice;
printf("Enter the size for stack\n");
scanf("%d", &size);
stack = (int *)malloc(size * sizeof(int));
if(stack == NULL) {
printf("Memory allocation failed!\n");
return 1;
}
printf("1.Push\n2.Pop\n3.Display\n4.Check for Palindrome\n5.Exit\n");
while(1) {
printf("Enter the choice\n");
scanf("%d", &choice);
if(choice == 1) push();
else if(choice == 2) pop();
else if(choice == 3) display();
else if(choice == 4) {
if(pali()) printf("It's Palindrome\n");
else printf("It's not a Palindrome\n");
}
else if(choice == 5) break;
else printf("Wrong choice...\n");
}
free(stack);
return 0;
}