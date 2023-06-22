#include <stdio.h>
#include <stdlib.h>

// Structure to represent a student
struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    int n, i;
    struct Student *students;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array of students
    students = (struct Student *)malloc(n * sizeof(struct Student));

    // Input data for each student
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Display the data for each student
    printf("\nStudent Details:\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}