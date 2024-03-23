#include <stdio.h>

// Function to copy one string to another recursively
void copyString(char source[], char destination[], int index) {
    if (source[index] == '\0') {
        destination[index] = '\0'; // Null-terminate the destination string
        return;
    }
    destination[index] = source[index]; // Copy character from source to destination
    copyString(source, destination, index + 1); // Recur for the next character
}

int main() {
    char source[100], destination[100];

    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);

    copyString(source, destination, 0);

    printf("Source string: %s", source);
    printf("Destination string: %s", destination);

    return 0;
}
