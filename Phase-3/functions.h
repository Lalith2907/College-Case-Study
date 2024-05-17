#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
    char *name;
    int rollno;
    int sem;
    long long int contact;
    int isa1[3];
    int isa2[3];
    int esa[3];
    float marks[3];
    float sgpa;
    char sub[3][50];
    int credit[3];
} Student;

extern void readCSV(Student *students, int n);
extern void searchStudent(Student *students, int n);

#endif