#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int hasNumber(char pwd[]) {
    for (int i = 0; pwd[i] != '\0'; i++) {
        if (pwd[i] >= '0' && pwd[i] <= '9')
            return 1;
    }
    return 0;
}

int hasSpecialChar(char pwd[]) {
    char special[] = "!@#$%^&*";
    for (int i = 0; pwd[i] != '\0'; i++) {
        for (int j = 0; special[j] != '\0'; j++) {
            if (pwd[i] == special[j])
                return 1;
        }
    }
    return 0;
}

void generatePassword() {
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    char password[12];

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[10] = '\0';

    printf("\nGenerated Strong Password: %s\n", password);
}

int main() {
    char password[50];
    int length, num, special;
    int choice;

    while (1) {
        printf("\n===== PASSWORD UTILITY =====\n");
        printf("1. Check Password Strength\n");
        printf("2. Generate Strong Password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("\nEnter your password: ");
            scanf("%s", password);

            length = strlen(password);
            num = hasNumber(password);
            special = hasSpecialChar(password);

            printf("\nPassword Analysis:\n");
            printf("Length: %d\n", length);
            printf("Contains Number: %s\n", num ? "Yes" : "No");
            printf("Contains Special Character: %s\n", special ? "Yes" : "No");

            if (length < 6) {
                printf("Password Strength: WEAK\n");
            } 
            else if (length >= 6 && num && !special) {
                printf("Password Strength: MEDIUM\n");
            } 
            else if (length >= 8 && num && special) {
                printf("Password Strength: STRONG\n");
            } 
            else {
                printf("Password Strength: WEAK\n");
            }
            break;

        case 2:
            generatePassword();
            break;

        case 3:
            printf("\nThank you for using Password Utility!\n");
            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }
}