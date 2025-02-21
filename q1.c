#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 256

// Helper function to sanitize filename
void sanitize_filename(const char* input, char* output, size_t outsize) {
    size_t i;
    for (i = 0; input[i] && i < outsize - 1; i++) {
        // Only allow alphanumeric chars, dots, underscores, and hyphens
        if (isalnum(input[i]) || input[i] == '.' || input[i] == '_' || input[i] == '-') {
            output[i] = input[i];
        } else {
            output[i] = '_';  // Replace unsafe chars with underscore
        }
    }
    output[i] = '\0';  // Ensure null termination
}

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char cmd[BUFSIZE] = "wc -c < ";
    char safe_filename[BUFSIZE];
    sanitize_filename(argv[1], safe_filename, BUFSIZE);
    char cmd2[BUFSIZE] = {0};
    snprintf(cmd2, cmd, safe_filename);
    system(cmd2);
}