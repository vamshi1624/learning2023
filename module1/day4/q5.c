#include <stdio.h>

// Structure to represent a point
struct Point {
    int x;
    int y;
};

// Function to swap the fields of two points
void swapPoints(struct Point *p1, struct Point *p2) {
    int tempX, tempY;

    // Swap the x coordinates
    tempX = p1->x;
    p1->x = p2->x;
    p2->x = tempX;

    // Swap the y coordinates
    tempY = p1->y;
    p1->y = p2->y;
    p2->y = tempY;
}

int main() {
    struct Point point1, point2;

    // Input the coordinates for the first point
    printf("Enter the coordinates for point 1 (x y): ");
    scanf("%d %d", &point1.x, &point1.y);

    // Input the coordinates for the second point
    printf("Enter the coordinates for point 2 (x y): ");
    scanf("%d %d", &point2.x, &point2.y);

    // Display the original points
    printf("\nOriginal Points:\n");
    printf("Point 1: (%d, %d)\n", point1.x, point1.y);
    printf("Point 2: (%d, %d)\n", point2.x, point2.y);

    // Swap the fields of the points
    swapPoints(&point1, &point2);

    // Display the swapped points
    printf("\nSwapped Points:\n");
    printf("Point 1: (%d, %d)\n", point1.x, point1.y);
    printf("Point 2: (%d, %d)\n", point2.x, point2.y);

    return 0;
}