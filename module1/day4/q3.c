#include <stdio.h>

// Structure to represent a time period
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct Time difference(struct Time t1, struct Time t2) {
    struct Time diff;

    // Convert everything to seconds
    int time1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int time2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    int timeDiff = time2 - time1;

    // Calculate hours, minutes, and seconds from the time difference
    diff.hours = timeDiff / 3600;
    timeDiff %= 3600;
    diff.minutes = timeDiff / 60;
    diff.seconds = timeDiff % 60;

    return diff;
}

int main() {
    struct Time t1, t2, diff;

    // Input the first time period
    printf("Enter the first time period (hh:mm:ss): ");
    scanf("%d:%d:%d", &t1.hours, &t1.minutes, &t1.seconds);

    // Input the second time period
    printf("Enter the second time period (hh:mm:ss): ");
    scanf("%d:%d:%d", &t2.hours, &t2.minutes, &t2.seconds);

    // Calculate the difference between the two time periods
    diff = difference(t1, t2);

    // Output the difference
    printf("The difference is: %d hours, %d minutes, %d seconds\n",
           diff.hours, diff.minutes, diff.seconds);

    return 0;
}