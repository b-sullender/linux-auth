
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

#define USER_ENTRY_FILE "/etc/shadow"

// Function to check if two hashed passwords match
int passwordsMatch(const char* storedHashedPassword, const char* inputPassword) {
    return strcmp(storedHashedPassword, crypt(inputPassword, storedHashedPassword)) == 0;
}

// Function to authenticate a user
int authenticateUser(const char* username, const char* password)
{
    FILE* file = fopen(USER_ENTRY_FILE, "r");
    if (file == NULL) {
        perror("Error opening shadow file");
        return -1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        char *token = strtok(line, ":");
        if (token != NULL && strcmp(token, username) == 0)
        {
            token = strtok(NULL, ":"); // Get the stored hashed password

            if (token != NULL && passwordsMatch(token, password)) {
                fclose(file);
                return 1; // Authentication successful
            } else {
                fclose(file);
                return 0; // Authentication failed (wrong password)
            }
        }
    }

    fclose(file);

    return 0; // Authentication failed (user not found)
}

int main()
{
    char username[100];
    char password[100];

    printf("Enter username: ");
    if (scanf("%99s", username) != 1) {
        fprintf(stderr, "Error reading username\n");
        return 1;
    }

    printf("Enter password: ");
    if (scanf("%99s", password) != 1) {
        fprintf(stderr, "Error reading password\n");
        return 1;
    }

    int result = authenticateUser(username, password);
    if (result == 1) {
        printf("Authentication successful!\n");
    } else if (result == 0) {
        printf("Authentication failed: Incorrect username or password.\n");
    } else {
        printf("Error authenticating user.\n");
    }

    return 0;
}

