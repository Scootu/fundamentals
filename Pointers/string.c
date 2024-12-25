#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to get a substring from index 0 to x
char* substring(char* c, int x) {
    char* s = malloc(x + 2); // Allocate memory for substring (x + 1 chars + null terminator)
    if (s == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i <= x; i++) {
        s[i] = c[i];
    }
    s[x + 1] = '\0'; // Null-terminate the string
    return s;
}

// Function to check if a string contains a given substring
bool isSubstring(char* s, char* sub) {
    int len = strlen(s);
    int sub_len = strlen(sub);

    for (int i = 0; i <= len - sub_len; i++) {
        char* temp = substring(s + i, sub_len - 1); // Extract substring of the same length as `sub`
        if (strcmp(temp, sub) == 0) { // Compare strings
            free(temp);
            return true;
        }
        free(temp); // Free dynamically allocated memory
    }
    return false;
}

int main() {
    char s[100]; // Use a character array to hold the string
    char sub[100];

    printf("Enter your string: ");
    scanf("%99s", s); // Limit input size to prevent overflow

    printf("Enter the substring to search for: ");
    scanf("%99s", sub); // Input for the substring

    if (isSubstring(s, sub)) {
        printf("'%s' is a substring of '%s'.\n", sub, s);
    } else {
        printf("'%s' is not a substring of '%s'.\n", sub, s);
    }

    return EXIT_SUCCESS;
}
