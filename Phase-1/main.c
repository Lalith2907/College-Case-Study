#include <stdio.h>
#include "functions.h" // Include user-defined functions header file

// Arrays to store student information
const int n = 10;    
char name[10][50], sub[3][50];   
long long int contact[10];   
int rollno[10], sem[10], credit[3], isa1[10][3], isa2[10][3], esa[10][3];  
float marks[10][3], sgpa[10];   

int main()
{
    int input;

    // Function calls to get input data
    studentinfo(name, rollno, sem, contact, n);
    Subjects(sub);
    Credits(credit);
    ISA1(isa1, n);
    ISA2(isa2, n);
    ESA(esa, n);
    Marks_Data(marks, isa1, isa2, esa, n);
    SGPA(marks, credit, n, sgpa);
    do
    {
        // Menu to select options
        printf("Select an option: \n");
        printf("1. Gradecard of student\n2. Exit\n");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
            {
                // Display gradecard for a student
                gradecard(name, rollno, sem, contact, sub, isa1, isa2, esa, marks, sgpa, n);
                break;
            }
            case 2:
            {
                // Exit the program
                break;
            }
        }
    } while(input != 2);
    return 0;
}