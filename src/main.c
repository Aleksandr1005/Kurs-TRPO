#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void genering_word()
{
int word = 0;
char ch;
int k = 1;
srand(time(NULL));
FILE *tf, *pr;
tf = fopen("Infinitive.txt", "r");
pr = fopen("werbs.txt", "w");
int num_word = rand() % 118;
while ((ch = fgetc(tf)) != EOF) {
if (ch == ' ') {
word++;
}
if (k == num_word) {
if (word == 0) {
fputc(ch, pr);
}
if (word == 1) {
fputc(ch, pr);
}
if (word == 2) {
fputc(ch, pr);
}
}
if (ch == '\n') {
k++;
word = 0;
}
}
fclose(tf);
fclose(pr);
}

void output_inf_word()
{
char ch;
int word = 0;
FILE* pr;
pr = fopen("werbs.txt", "r");
printf("Infinitive: ");
while ((ch = fgetc(pr)) != EOF) {
if (ch == ' ')
word++;
if (word == 0)
printf("%c",ch);
}
printf("\n");
fclose(pr);
}

void output_sim_word()
{
char ch;
int word = 0;
FILE* pr;
pr = fopen("werbs.txt", "r");
printf("Infinitive: ");
while ((ch = fgetc(pr)) != EOF) {
if (ch == ' ')
word++;
if (word == 1)
printf("%c",ch);
}
printf("\n");
fclose(pr);
}

void output_part_word()
{
char ch;
int word = 0;
FILE* pr;
pr = fopen("werbs.txt", "r");
printf("Infinitive: ");
while ((ch = fgetc(pr)) != EOF) {
if (ch == ' ')
word++;
if (word == 2)
printf("%s",&ch);
}
printf("\n");
fclose(pr);
}

int input_simple_word()
{
char ch, sl1[100];
int word = 0, correct_simple, i = 0, c = 0, t = 0;
FILE* pr;
pr = fopen("werbs.txt", "r");
while ((ch = getc(pr)) != EOF) {
if (ch == ' ')
word++;
if (word == 1 && ch != ' ') {
sl1[i] = ch;
i++;
}
}
char simple_word;
printf("Past Simple: ");
scanf("%s", &simple_word);
char* simp = &simple_word;
for (t = 0; t < i; t++) {
if (sl1[t] == simp[t])
c++;
}
if (c == i) {
return 1;
} else {
return 0;
}
fclose(pr);
}

int input_participle_word()
{
char ch, sl[100];
int word = 0, i = 0, c = 0, t = 0;
FILE* pr;
pr = fopen("werbs.txt", "r");
while ((ch = getc(pr)) != EOF) {
if (ch == ' ')
word++;
if (word == 2 && ch != ' ' && ch != '\n') {
sl[i] = ch;
i++;
}
}
char participle_word;
printf("Past Participle: ");
scanf("%s", &participle_word);
char* part = &participle_word;
for (t = 0; t < i; t++) {
if (sl[t] == part[t])
c++;
}
if (c == i) {
return 1;
} else {
return 0;
}
fclose(pr);
}

void correct()
{
int simple = input_simple_word();
int participle = input_participle_word();
printf("\n =========================== \n");
printf("Past Simple: ");
if (simple == 1) {
printf("correct \n");
} else {
printf("uncorrect \n");
}
printf("Past Participle: ");
if (participle == 1) {
printf("correct \n");
} else {
printf("uncorrect");
}
}

void menu()
{
char ch;
do {
system("cls");
genering_word();
output_inf_word();
correct();
printf("\n End? y/n \n");
scanf("%s", &ch);
} while (ch != 'y');
}

int main()
{
menu();
return 0;
}
