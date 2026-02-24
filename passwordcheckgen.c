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

/* Fully random password */
void generateRandomPassword() {
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    char password[12];

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[10] = '\0';

    printf("\nGenerated Random Password: %s\n", password);
}

/* Customized password using user keyword */
void generateCustomPassword() {
    char keyword[30];
    char special[] = "!@#$%^&*";
    int num1, num2;

    srand(time(NULL));

    printf("\nEnter a keyword (name or word): ");
    scanf("%s", keyword);

    num1 = rand() % 10;
    num2 = rand() % 10;
    char sp = special[rand() % strlen(special)];

    printf("\nGenerated Custom Password: %s%c%d%d\n",
           keyword, sp, num1, num2);
}

int main() {
    char password[50];
    int length, num, special;
    int choice, subChoice;

    while (1) {
        printf("\n===== PASSWORD UTILITY =====\n");
        printf("1. Check Password Strength\n");
        printf("2. Generate Password\n");
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
            printf("\nPassword Generation Mode:\n");
            printf("1. Fully Random Password\n");
            printf("2. Custom Password (Keyword Based)\n");
            printf("Enter your choice: ");
            scanf("%d", &subChoice);

            if (subChoice == 1) {
                generateRandomPassword();
            } 
            else if (subChoice == 2) {
                generateCustomPassword();
            } 
            else {
                printf("\nInvalid option!\n");
            }
            break;

        case 3:
            printf("\nThank you for using Password Utility!\n");
            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }
}}
