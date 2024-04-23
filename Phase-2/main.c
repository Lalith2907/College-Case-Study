#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    int input;

    // Get student count
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for students
    Student *students = malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Function calls to get input data
    studentinfo(students, n);
    Subjects(students);
    Credits(students);
    ISA1(students, n);
    ISA2(students, n);
    ESA(students, n);
    Marks_Data(students, n);
    SGPA(students, n);

    do {
        // Menu to select options
        printf("Select an option: \n");
        printf("1. Gradecard of student\n2. Exit\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                // Display gradecard for a student
                gradecard(students, n);
                break;
            case 2:
                // Exit the program
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (input != 2);

    // Free dynamically allocated memory
    free(students);

    return 0;
}