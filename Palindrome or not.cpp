#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alphanumeric
bool isAlphanumeric(char ch) {
    return isalnum(ch) != 0;
}

// Function to convert character to lowercase
char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');
    }
    return ch;
}

// Function to check if a string is a palindrome recursively
bool isPalindrome(char str[], int start, int end) {
    // Base case: if start is greater than or equal to end, return true
    if (start >= end)
        return true;
    
    // Ignore non-alphanumeric characters
    while (!isAlphanumeric(str[start]) && start < end)
        start++;
    while (!isAlphanumeric(str[end]) && start < end)
        end--;
    
    // Compare characters ignoring case
    if (toLower(str[start]) != toLower(str[end]))
        return false;
    
    // Recur for substring
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    
    if (isPalindrome(str, 0, strlen(str) - 1))
        printf("The string \"%s\" is a palindrome.\n", str);
    else
        printf("The string \"%s\" is not a palindrome.\n", str);
    
    return 0;
}

