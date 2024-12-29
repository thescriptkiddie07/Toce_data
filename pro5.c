PROGRAM 5A:
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int i, top = -1, op1, op2, res, s[20];
char postfix[90], symb;

void push(int item) { s[++top] = item; }
int pop() { return s[top--]; }

int main() {
printf("\nEnter a valid postfix expression:\n");
scanf("%s", postfix);
for(i = 0; postfix[i] != '\0'; i++) {
symb = postfix[i];
if(isdigit(symb)) push(symb - '0');
else {
op2 = pop();
op1 = pop();
switch(symb) {
case '+': push(op1 + op2); break;
case '-': push(op1 - op2); break;
case '*': push(op1 * op2); break;
case '/': push(op1 / op2); break;
case '%': push(op1 % op2); break;
case '^': push(pow(op1, op2)); break;
default: printf("Invalid operator: %c\n", symb); break;
}
}
}
res = pop();
printf("\nResult = %d\n", res);
return 0;
}

PROGRAM 5B:
#include<stdio.h>
int count = 0, n;
void tower(int n, char s, char t, char d) {
if(n == 1) {
printf("\nMove disc 1 from %c to %c", s, d);
count++;
return;
}
tower(n - 1, s, d, t);
printf("\nMove disc %d from %c to %c", n, s, d);
count++;
tower(n - 1, t, s, d);
}
int main() {
printf("\nEnter the number of discs: ");
scanf("%d", &n);
tower(n, 'A', 'B', 'C');
printf("\nThe total number of disc moves is: %d\n", count);
return 0;
}