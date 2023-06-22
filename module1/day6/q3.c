#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    int sensorNo;
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
} LogEntry;

LogEntry logEntries[MAX_ENTRIES];
int numEntries = 0;

void readDataFromFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Unable to open the file: %s\n", fileName);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        LogEntry entry;

        sscanf(line, "%d,%d,%f,%d,%d,%[^,\n]", &entry.entryNo, &entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.timestamp);

        logEntries[numEntries] = entry;
        numEntries++;

        if (numEntries >= MAX_ENTRIES) {
            printf("Maximum number of entries reached. Exiting...\n");
            break;
        }
    }

    fclose(file);
}
void displayLogEntries() {
    printf("EntryNo | SensorNo | Temperature | Humidity | Light | Timestamp\n");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        LogEntry entry = logEntries[i];
        printf("%7d | %8d | %11.2f | %8d | %5d | %s\n",
               entry.entryNo, entry.sensorNo, entry.temperature, entry.humidity, entry.light, entry.timestamp);
    }
}

int main() {
    readDataFromFile("data.csv");
    displayLogEntries();

    return 0;
}