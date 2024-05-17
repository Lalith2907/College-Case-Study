#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Function to read data from CSV file
void readCSV(Student *students, int n) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        students[i].name = malloc(50 * sizeof(char));
        if (students[i].name == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        fscanf(file, "%[^,],%d,%d,%lld,", students[i].name, &students[i].rollno, &students[i].sem, &students[i].contact);
        for (int j = 0; j < 3; j++) {
            fscanf(file, "%[^,],", students[i].sub[j]);
        }
        for (int j = 0; j < 3; j++) {
            fscanf(file, "%d,", &students[i].credit[j]);
        }
        for (int j = 0; j < 3; j++) {
            fscanf(file, "%d,", &students[i].isa1[j]);
        }
        for (int j = 0; j < 3; j++) {
            fscanf(file, "%d,", &students[i].isa2[j]);
        }
        for (int j = 0; j < 3; j++) {
            fscanf(file, "%d,", &students[i].esa[j]);
        }
        for (int j = 0; j < 3; j++) {
            fscanf(file, "%f,", &students[i].marks[j]);
        }
        fscanf(file, "%f\n", &students[i].sgpa);
    }
    fclose(file);
}

// Function to search student by name
void searchStudent(Student *students, int n) {
    char name[50];
    printf("Enter the name of the student: ");
    scanf("%s", name);
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("\n");
            printf("====================================================================\n");
            printf("\t\t\t    GRADE CARD\n");
            printf("Name: %-45s\n", students[i].name);
            printf("Semester: %-10d\t\t\t\t\tSGPA: %.2f\n", students[i].sem, students[i].sgpa);
            printf("Roll No.: %-10d\t\t\t\t\t\n", students[i].rollno);
            printf("Contact No.: %-15lld\n", students[i].contact);
            printf("--------------------------------------------------------------------\n");
            printf("Subject\t\tISA1\tISA2\tESA\tMarks\n");
            printf("--------------------------------------------------------------------\n");
            for (int j = 0; j < 3; j++) {
                printf("%-10s\t%d\t%d\t%d\t%.2f\n", students[i].sub[j], students[i].isa1[j], students[i].isa2[j], students[i].esa[j], students[i].marks[j]);
            }
            printf("====================================================================\n");
            return;
        }
    }
    printf("Student not found.\n");
}