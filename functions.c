#include <stdio.h>

// Function to input student information
void studentinfo(char name[][50], int roll[], int sem[], long int contact[], int x) {
    for (int i = 0; i < x; i++) {
        printf("===============    Data of Student %d    ===============\n", i + 1);
        printf("Enter name: ");
        scanf("%s", name[i]);
        printf("Enter roll number: ");
        scanf("%d", &roll[i]);
        printf("Enter semester: ");
        scanf("%d", &sem[i]);
        printf("Enter contact number: ");
        scanf("%ld", &contact[i]);
    }
    printf("-----------------------------------------------------------\n");
}

// Function to input subject names
void Subjects(char sub[3][50]) {
    for (int i = 0; i < 3; i++) {
        printf("Enter subject %d: ", i + 1);
        scanf("%s", sub[i]);
    }
}

// Function to input subject credits
void Credits(int credit[3]) {
    for (int i = 0; i < 3; i++) {
        printf("Enter credits of subject %d: ", i + 1);
        scanf("%d", &credit[i]);
    }
    printf("-----------------------------------------------------------\n");
}

// Function to input ISA1 marks
void ISA1(int isa1[][3], int x) {
    for (int i = 0; i < x; i++) {
        printf("Enter marks of subjects of student %d for ISA1: ", i + 1);
        scanf("%d %d %d", &isa1[i][0], &isa1[i][1], &isa1[i][2]);
    }
    printf("-----------------------------------------------------------\n");
}

// Function to input ISA2 marks
void ISA2(int isa2[][3], int x) {
    for (int i = 0; i < x; i++) {
        printf("Enter marks of subjects of student %d for ISA2: ", i + 1);
        scanf("%d %d %d", &isa2[i][0], &isa2[i][1], &isa2[i][2]);
    }
    printf("-----------------------------------------------------------\n");
}

// Function to input ESA marks
void ESA(int esa[][3], int x) {
    for (int i = 0; i < x; i++) {
        printf("Enter marks of subjects of student %d for ESA: ", i + 1);
        scanf("%d %d %d", &esa[i][0], &esa[i][1], &esa[i][2]);
    }
    printf("-----------------------------------------------------------\n");
}

// Function to calculate total marks
void Marks_Data(float marks[][3], int isa1[][3], int isa2[][3], int esa[][3], int x)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            marks[i][j] = ((isa1[i][j] * 0.5) + (isa2[i][j] * 0.5) + (esa[i][j] * 0.5) + 10);
        }
    }
}

// Function to calculate SGPA
void SGPA(float marks[][3], int credits[3], int x, float sgpa[])
{
    int total = 0;
    for(int i = 0; i < 3; i++)
    {
        total += credits[i];
    }
    for(int i = 0; i < x; i++) 
    {
        sgpa[i] = 0;
        for(int j = 0; j < 3; j++)
        {
            if (marks[i][j] > 90) 
            {
                sgpa[i] += 10 * credits[j]; 
            } 
            else if (marks[i][j] > 80 && marks[i][j] <= 90) 
            {
                sgpa[i] += 9 * credits[j]; 
            } 
            else if (marks[i][j] > 70 && marks[i][j] <= 80) 
            {
                sgpa[i] += 8 * credits[j]; 
            } 
            else if (marks[i][j] > 60 && marks[i][j] <= 70) 
            {
                sgpa[i] += 7 * credits[j]; 
            } 
            else if (marks[i][j] > 50 && marks[i][j] <= 60) 
            {
                sgpa[i] += 6 * credits[j]; 
            } 
            else if (marks[i][j] > 40 && marks[i][j] <= 50) 
            {
                sgpa[i] += 5 * credits[j]; 
            }
            else
            {
                sgpa[i] += 4 * credits[j];
            }
        }
        sgpa[i] /= total; 
    }
}

// Function to print gradecard
void gradecard(char name[][50], int roll[], int sem[], long int contact[], char sub[3][50], int isa1[][3], int isa2[][3], int esa[][3], float marks[][3], float sgpa[], int x) {
    int input;
    printf("Choose whose grade card you want to be printed (1 to %d):\n", x);
    for (int i = 0; i < x; i++) 
    {
        printf("%d. %s\n", i + 1, name[i]);
    }
    scanf("%d", &input);
    if (input >= 1 && input <= x) 
    {
        input--;
        printf("\n");
        printf("====================================================================\n");
        printf("\t\t\t    GRADE CARD\n");
        printf("Name: %-45s\n", name[input]);
        printf("Semester: %-10d\t\t\t\t\tSGPA: %.2f\n", sem[input], sgpa[input]);
        printf("Roll No.: %-10d\t\t\t\t\t\n", roll[input]);
        printf("Contact No.: %-15lld\n", contact[input]);
        printf("--------------------------------------------------------------------\n");
        printf("Subject\t\tISA1\tISA2\tESA\tMarks\n");
        printf("--------------------------------------------------------------------\n");
        for (int i = 0; i < 3; i++) {
            printf("%-10s\t%d\t%d\t%d\t%.2f\n", sub[i], isa1[input][i], isa2[input][i], esa[input][i], marks[input][i]);
        }
        printf("====================================================================\n");
    } 
    else 
    {
        printf("Invalid input! Please choose a number between 1 and %d.\n", x);
    }
}