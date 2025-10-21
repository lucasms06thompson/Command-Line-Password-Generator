// File: passgen.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>    // For seeding the random number generator
#include <stdbool.h> // For boolean type

// Character sets
const char *LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz";
const char *UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *NUMBER_CHARS = "0123456789";
const char *SYMBOL_CHARS = "!@#$%^&*()-_=+[]{}|;";

/**
 * @brief Prints the usage instructions for the program.
 */
void show_usage() {
    printf("Usage: passgen <length> [options]\n\n");
    printf("Generates a random password of a specified length.\n\n");
    printf("Arguments:\n");
    printf("  <length>      The desired length of the password (e.g., 16).\n\n");
    printf("Options:\n");
    printf("  --no-upper    Exclude uppercase letters.\n");
    printf("  --no-lower    Exclude lowercase letters.\n");
    printf("  --no-numbers  Exclude numbers.\n");
    printf("  --no-symbols  Exclude symbols.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        show_usage();
        return 1;
    }

    int length = atoi(argv[1]);
    if (length <= 0) {
        printf("Error: Password length must be a positive number.\n");
        return 1;
    }

    // --- Argument Parsing for Character Sets ---
    bool use_lower = true;
    bool use_upper = true;
    bool use_numbers = true;
    bool use_symbols = true;

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "--no-lower") == 0) use_lower = false;
        else if (strcmp(argv[i], "--no-upper") == 0) use_upper = false;
        else if (strcmp(argv[i], "--no-numbers") == 0) use_numbers = false;
        else if (strcmp(argv[i], "--no-symbols") == 0) use_symbols = false;
    }

    // --- Build the Master Character Set ---
    char charset[128] = ""; // Buffer to hold all allowed characters
    if (use_lower) strcat(charset, LOWERCASE_CHARS);
    if (use_upper) strcat(charset, UPPERCASE_CHARS);
    if (use_numbers) strcat(charset, NUMBER_CHARS);
    if (use_symbols) strcat(charset, SYMBOL_CHARS);
    
    if (strlen(charset) == 0) {
        printf("Error: All character sets are excluded. Cannot generate password.\n");
        return 1;
    }

    // --- Seed the Random Number Generator ---
    srand((unsigned int)time(NULL));

    // --- Generate the Password ---
    char password[length + 1];
    int charset_size = strlen(charset);

    for (int i = 0; i < length; i++) {
        int random_index = rand() % charset_size;
        password[i] = charset[random_index];
    }
    password[length] = '\0'; // Null-terminate the string

    printf("Generated Password: %s\n", password);

    return 0;
}
