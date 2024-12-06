#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindromeString(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    // Compare characters from both ends
    while (start < end) {
        // Skip non-alphanumeric characters (for cases like punctuation)
        if (!isalnum(str[start])) {
            start++;
        } else if (!isalnum(str[end])) {
            end--;
        } else {
            // Convert both characters to lowercase for case-insensitive comparison
            if (tolower(str[start]) != tolower(str[end])) {
                return 0;  // Not a palindrome
            }
            start++;
            end--;
        }
    }
    return 1;  // It's a palindrome
}

int main() {
    char str[100];

    // Take input from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Check if the string is a palindrome
    if (isPalindromeString(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
