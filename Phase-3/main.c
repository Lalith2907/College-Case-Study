#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    int input;
    int n = 10; // Number of students

    // Allocate memory for students
    Student *students = malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read data from CSV file
    readCSV(students, n);

    do {
        // Menu to select options
        printf("Select an option: \n");
        printf("1. Search student by name\n");
        printf("2. Exit\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                // Search student by name
                searchStudent(students, n);
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