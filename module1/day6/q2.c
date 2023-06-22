#include <stdio.h>
#include <ctype.h>
#include <string.h>

void convertToUpper(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

void convertToLower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void convertToSentenceCase(char *str) {
    int len = strlen(str);
    if (len > 0) {
        *str = toupper(*str);
        for (int i = 1; i < len; i++) {
            if (*(str + i - 1) == ' ')
                (str + i) = toupper((str + i));
            else
                (str + i) = tolower((str + i));
        }
    }
}

void copyFile(FILE *sourceFile, FILE *destinationFile, char *option) {
    char ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        if (strcmp(option, "-u") == 0) {
            ch = toupper(ch);
        } else if (strcmp(option, "-I") == 0) {
            ch = tolower(ch);
        } else if (strcmp(option, "-s") == 0) {
            static int shouldCapitalize = 1;
            if (shouldCapitalize && isalpha(ch)) {
                ch = toupper(ch);
                shouldCapitalize = 0;
            } else if (ch == '.' || ch == '!' || ch == '?') {
                shouldCapitalize = 1;
            } else {
                ch = tolower(ch);
            }
        }
        fputc(ch, destinationFile);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4 || argc > 5) {
        printf("Invalid number of arguments.\n");
        printf("Usage: ./cp [option] source_file destination_file\n");
        printf("Options:\n");
        printf("    -u    Convert file content to upper case\n");
        printf("    -I    Convert file content to lower case\n");
        printf("    -s    Convert file content to sentence case\n");
        return 1;
    }

    char *option = "";
    char *sourceFileName = "";
    char *destinationFileName = "";

    if (argc == 4) {
        option = "";
        sourceFileName = argv[1];
        destinationFileName = argv[2];
    } else if (argc == 5) {
        option = argv[1];
        sourceFileName = argv[2];
        destinationFileName = argv[3];
    }

    FILE *sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    FILE *destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    if (strcmp(option, "-u") == 0 || strcmp(option, "-I") == 0 || strcmp(option, "-s") == 0) {
        copyFile(sourceFile, destinationFile, option);
    } else {
        char ch;
        while ((ch = fgetc(sourceFile)) != EOF) {
            fputc(ch, destinationFile);
        }
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return