PROGRAM 1A:
#include <stdio.h>
#include <stdlib.h>
struct CalendarDay {
char *dayName;
int date;
char *activity;
};
int main() {
struct CalendarDay calendar[7];
for (int i = 0; i < 7; i++) {
calendar[i].dayName = malloc(20);
calendar[i].activity = malloc(100);
sprintf(calendar[i].dayName, "Day %d", i + 1);
calendar[i].date = i + 1;
sprintf(calendar[i].activity, "Activity for Day %d", i + 1);
printf("Day Name: %s\nDate: %d\nActivity: %s\n\n", calendar[i].dayName, calendar[i].date, calendar[i].activity);
free(calendar[i].dayName);
free(calendar[i].activity);
}
return 0;
}

PROGRAM 1B:
#include <stdio.h>
#include <stdlib.h>
struct CalendarDay {
char *dayName;
int date;
char *activity;
};
void create(struct CalendarDay calendar[]) {
for (int i = 0; i < 7; i++) {
calendar[i].dayName = malloc(20);
calendar[i].activity = malloc(100);
}
}
void read(struct CalendarDay calendar[]) {
for (int i = 0; i < 7; i++) {
printf("Enter day name for Day %d: ", i + 1);
scanf("%s", calendar[i].dayName);
printf("Enter date for Day %d: ", i + 1);
scanf("%d", &calendar[i].date);
printf("Enter activity for Day %d: ", i + 1);
scanf(" %[^\n]", calendar[i].activity);
}
}
void display(struct CalendarDay calendar[]) {
printf("\nActivity Details for the Week:\n");
for (int i = 0; i < 7; i++) {
printf("Day Name: %s\nDate: %d\nActivity: %s\n\n", calendar[i].dayName, calendar[i].date, calendar[i].activity);
}
}
int main() {
struct CalendarDay calendar[7];
create(calendar);
read(calendar);
display(calendar);
for (int i = 0; i < 7; i++) {
free(calendar[i].dayName);
free(calendar[i].activity);
}
return 0;
}