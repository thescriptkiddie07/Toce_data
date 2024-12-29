#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Term {
int coeff, x, y, z;
struct Term* next;
} Term;
Term* createTerm(int coeff, int x, int y, int z) {
Term* t = malloc(sizeof(Term));
t->coeff = coeff; t->x = x; t->y = y; t->z = z;
t->next = t;
return t;
}
void insertTerm(Term** poly, int coeff, int x, int y, int z) {
Term* t = createTerm(coeff, x, y, z);
if (!*poly) *poly = createTerm(0, 0, 0, 0);
Term* temp = (*poly)->next;
while (temp->next != *poly) temp = temp->next;
temp->next = t; t->next = *poly;
}
int evaluatePoly(Term* poly, int x, int y, int z) {
int result = 0;
Term* t = poly->next;
while (t != poly) {
result += t->coeff * pow(x, t->x) * pow(y, t->y) * pow(z, t->z);
t = t->next;
}
return result;
}
void addPolynomials(Term* poly1, Term* poly2, Term** sum) {
Term *t1 = poly1->next, *t2;
while (t1 != poly1) insertTerm(sum, t1->coeff, t1->x, t1->y, t1->z), t1 = t1->next;
t2 = poly2->next;
while (t2 != poly2) {
Term* temp = (*sum)->next;
int found = 0;
while (temp != *sum) {
if (temp->x == t2->x && temp->y == t2->y && temp->z == t2->z) {
temp->coeff += t2->coeff; found = 1; break;
}
temp = temp->next;
}
if (!found) insertTerm(sum, t2->coeff, t2->x, t2->y, t2->z);
t2 = t2->next;
}
}
void displayPoly(Term* poly) {
Term* t = poly->next;
while (t != poly) {
printf("%+dx^%dy^%dz^%d ", t->coeff, t->x, t->y, t->z);
t = t->next;
}
printf("\n");
}
int main() {
Term *poly1 = NULL, *poly2 = NULL, *polySum = NULL;
insertTerm(&poly1, 6, 2, 2, 1); insertTerm(&poly1, -4, 0, 1, 5);
insertTerm(&poly1, 3, 3, 1, 1); insertTerm(&poly1, 2, 1, 5, 1); insertTerm(&poly1, -2, 1, 1, 3);
insertTerm(&poly2, 5, 2, 2, 1); insertTerm(&poly2, 7, 0, 1, 5);
insertTerm(&poly2, -2, 3, 1, 1); insertTerm(&poly2, 1, 1, 5, 1); insertTerm(&poly2, 3, 1, 1, 3);
printf("POLY1: "); displayPoly(poly1);
printf("POLY2: "); displayPoly(poly2);
addPolynomials(poly1, poly2, &polySum);
printf("POLYSUM: "); displayPoly(polySum);
printf("POLY1(1,1,1): %d\n", evaluatePoly(poly1, 1, 1, 1));
return 0;
}