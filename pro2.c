PROGRAM 2:
#include <stdio.h>
#include <string.h>
void findAndReplace(char *mainString, const char *pattern, const char *replace) {
int mainLen = strlen(mainString), patternLen = strlen(pattern), replaceLen = strlen(replace);
for (int i = 0; i <= mainLen - patternLen;) {
int j;
for (j = 0; j < patternLen; j++) if (mainString[i + j] != pattern[j]) break;
if (j == patternLen) {
char temp[1000];
strcpy(temp, mainString + i + patternLen);
strcpy(mainString + i, replace);
strcat(mainString, temp);
mainLen = strlen(mainString);
i += replaceLen;
} else i++;
}
}
int main() {
char mainString[1000], pattern[100], replace[100];
printf("Enter the main string: ");
scanf(" %[^\n]", mainString);
printf("Enter the pattern string: ");
scanf("%s", pattern);
printf("Enter the replace string: ");
scanf("%s", replace);
findAndReplace(mainString, pattern, replace);
printf("The Result of String: %s\n", mainString);
return 0;
}
