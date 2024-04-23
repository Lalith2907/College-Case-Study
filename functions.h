#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern const int n;
extern char name[][50];
extern char sub[3][50];
extern long long int contact[];
extern int rollno[];
extern int sem[];
extern int credit[3];
extern int isa1[][3];
extern int isa2[][3];
extern int esa[][3];
extern float marks[][3];
extern float sgpa[];

void studentinfo(char name[][50], int roll[], int sem[], long long int contact[], int x);
void Subjects(char sub[3][50]);
void Credits(int credit[3]);
void ISA1(int isa1[][3], int x);
void ISA2(int isa2[][3], int x);
void ESA(int esa[][3], int x);
void Marks_Data(float marks[][3], int isa1[][3], int isa2[][3], int esa[][3], int x);
void SGPA(float marks[][3], int credits[3], int x, float sgpa[]);
void gradecard(char name[][50], int roll[], int sem[], long long int contact[], char sub[3][50], int isa1[][3], int isa2[][3], int esa[][3], float marks[][3], float sgpa[], int x);

#endif