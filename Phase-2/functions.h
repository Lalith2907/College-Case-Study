#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
    char *name;
    int rollno;
    int sem;
    long long int contact;
    int *isa1;
    int *isa2;
    int *esa;
    float *marks;
    float sgpa;
    char sub[3][50];
    int credit[3];
} Student;

extern void studentinfo(Student *students, int n);
extern void Subjects(Student *students);
extern void Credits(Student *students);
extern void ISA1(Student *students, int n);
extern void ISA2(Student *students, int n);
extern void ESA(Student *students, int n);
extern void Marks_Data(Student *students, int n);
extern void SGPA(Student *students, int n);
extern void gradecard(Student *students, int n);

#endif