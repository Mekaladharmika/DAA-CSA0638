#include <stdio.h>

// Function to print the reverse of a string recursively
void reverseString(char str[]) {
    // Base case: if the string is empty, return
    if (str[0] == '\0')
        return;
    
    // Recursive call to print the rest of the string in reverse
    reverseString(str + 1);
    
    // Print the first character of the string
    printf("%c", str[0]);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Reverse of the string: ");
    reverseString(str);

    return 0;
}
