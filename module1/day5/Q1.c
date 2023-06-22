#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseInputString(const char* input, struct Student* students, int size) {
    int count = 0;
    const char* delimiter = " ";
    char* token = strtok(input, delimiter);

    while (token != NULL && count < size) {
        students[count].rollno = atoi(token);
        token = strtok(NULL, delimiter);

        if (token != NULL) {
            strncpy(students[count].name, token, 19);
            token = strtok(NULL, delimiter);
        }

        if (token != NULL) {
            students[count].marks = atof(token);
            token = strtok(NULL, delimiter);
        }

        count++;
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    // Consume the newline character
    getchar();

    struct Student* students = malloc(size * sizeof(struct Student));

    char input[100];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove the newline character from the input

    parseInputString(input, students, size);

    // Display the initialized array of structures
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }

    free(students);

    return 0;
}