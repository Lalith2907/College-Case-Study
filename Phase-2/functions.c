#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// Function to input student information
void studentinfo(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        students[i].name = malloc(50 * sizeof(char));
        if (students[i].name == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        printf("===============    Data of Student %d    ===============\n", i + 1);
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter roll number: ");
        scanf("%d", &students[i].rollno);
        printf("Enter semester: ");
        scanf("%d", &students[i].sem);
        printf("Enter contact number: ");
        scanf("%lld", &students[i].contact);
    }
    printf("-----------------------------------------------------------\n");
}

// Function to input subject names
void Subjects(Student *students) {
    for (int i = 0; i < 3; i++) {
        printf("Enter subject %d: ", i + 1);
        scanf("%s", students->sub[i]);
    }
    printf("-----------------------------------------------------------\n");
}

// Function to input subject credits
void Credits(Student *students) {
    for (int i = 0; i < 3; i++) {
        printf("Enter credits of subject %d: ", i + 1);
        scanf("%d", &students->credit[i]);
    }
    printf("-----------------------------------------------------------\n");
}

// Function to input ISA1 marks
void ISA1(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        students[i].isa1 = malloc(3 * sizeof(int));
        printf("Enter marks of subjects of student %d for ISA1: ", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &students[i].isa1[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}

// Function to input ISA2 marks
void ISA2(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        students[i].isa2 = malloc(3 * sizeof(int));
        printf("Enter marks of subjects of student %d for ISA2: ", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &students[i].isa2[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}

// Function to input ESA marks
void ESA(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        students[i].esa = malloc(3 * sizeof(int));
        printf("Enter marks of subjects of student %d for ESA: ", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &students[i].esa[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}

// Function to calculate total marks
void Marks_Data(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        students[i].marks = malloc(3 * sizeof(float));
        for (int j = 0; j < 3; j++) {
            students[i].marks[j] = ((students[i].isa1[j] * 0.5) + (students[i].isa2[j] * 0.5) + (students[i].esa[j] * 0.5) + 10);
        }
    }
}

// Function to calculate SGPA
void SGPA(Student *students, int n) {
    int total_credits = 0;
    for (int i = 0; i < 3; i++) {
        total_credits += students->credit[i];
    }
    for (int i = 0; i < n; i++) {
        students[i].sgpa = 0;
        for (int j = 0; j < 3; j++) {
            if (students[i].marks[j] > 90) {
                students[i].sgpa += 10 * students->credit[j];
            } else if (students[i].marks[j] > 80 && students[i].marks[j] <= 90) {
                students[i].sgpa += 9 * students->credit[j];
            } else if (students[i].marks[j] > 70 && students[i].marks[j] <= 80) {
                students[i].sgpa += 8 * students->credit[j];
            } else if (students[i].marks[j] > 60 && students[i].marks[j] <= 70) {
                students[i].sgpa += 7 * students->credit[j];
            } else if (students[i].marks[j] > 50 && students[i].marks[j] <= 60) {
                students[i].sgpa += 6 * students->credit[j];
            } else if (students[i].marks[j] > 40 && students[i].marks[j] <= 50) {
                students[i].sgpa += 5 * students->credit[j];
            } else {
                students[i].sgpa += 4 * students->credit[j];
            }
        }
        students[i].sgpa /= total_credits;
    }
}

// Function to print gradecard
void gradecard(Student *students, int n) {
    int input;
    printf("Choose whose grade card you want to be printed (1 to %d):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, students[i].name);
    }
    scanf("%d", &input);
    if (input >= 1 && input <= n) {
        input--;
        printf("\n");
        printf("====================================================================\n");
        printf("\t\t\t    GRADE CARD\n");
        printf("Name: %-45s\n", students[input].name);
        printf("Semester: %-10d\t\t\t\t\tSGPA: %.2f\n", students[input].sem, students[input].sgpa);
        printf("Roll No.: %-10d\t\t\t\t\t\n", students[input].rollno);
        printf("Contact No.: %-15lld\n", students[input].contact);
        printf("--------------------------------------------------------------------\n");
        printf("Subject\t\tISA1\tISA2\tESA\tMarks\n");
        printf("--------------------------------------------------------------------\n");
        for (int i = 0; i < 3; i++) {
            printf("%-10s\t%d\t%d\t%d\t%.2f\n", students[0].sub[i], students[input].isa1[i], students[input].isa2[i], students[input].esa[i], students[input].marks[i]);
        }
        printf("====================================================================\n");
    } else {
        printf("Invalid input! Please choose a number between 1 and %d.\n", n);
    }
}