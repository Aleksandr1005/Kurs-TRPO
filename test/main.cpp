#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;
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
    cout << "Infinitive: ";
    while ((ch = fgetc(pr)) != EOF) {
        if (ch == ' ')
            word++;
        if (word == 0)
            cout << ch;
    }
    cout << endl;
    fclose(pr);
}

void output_sim_word()
{
    char ch;
    int word = 0;
    FILE* pr;
    pr = fopen("werbs.txt", "r");
    cout << "Infinitive: ";
    while ((ch = fgetc(pr)) != EOF) {
        if (ch == ' ')
            word++;
        if (word == 1)
            cout << ch;
    }
    cout << endl;
    fclose(pr);
}

void output_part_word()
{
    char ch;
    int word = 0;
    FILE* pr;
    pr = fopen("werbs.txt", "r");
    cout << "Infinitive: ";
    while ((ch = fgetc(pr)) != EOF) {
        if (ch == ' ')
            word++;
        if (word == 2)
            cout << ch;
    }
    cout << endl;
    fclose(pr);
}

int input_simple_word()
{
    char ch, sl1[100];
    int word = 0, i = 0, c = 0, t = 0;
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
    char simple_word[100];
    cout << "Past Simple: ";
    cin >> simple_word;
    for (t = 0; t < i; t++) {
        if (sl1[t] == simple_word[t])
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
    char participle_word[100];
    cout << "Past Participle: ";
    cin >> participle_word;
    for (t = 0; t < i; t++) {
        if (sl[t] == participle_word[t])
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
    cout << endl << "===========================" << endl;
    cout << "Past Simple: ";
    if (simple == 1) {
        cout << "correct" << endl;
    } else {
        cout << "uncorrect" << endl;
    }
    cout << "Past Participle: ";
    if (participle == 1) {
        cout << "correct" << endl;
    } else {
        cout << "uncorrect" << endl;
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
        cout << "End? y/n " << endl;
        cin >> ch;
    } while (ch != 'y');
}

int main()
{
    menu();
    return 0;
}
