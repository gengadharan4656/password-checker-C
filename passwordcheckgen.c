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

    printf("\n Generated Strong Password: %s\n", password);
}

int main() {
    char password[50];
    int length, num, special;
    char choice;

    printf("===== PASSWORD STRENGTH CHECKER =====\n");
    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);
    num = hasNumber(password);
    special = hasSpecialChar(password);

    printf("\nPassword Analysis:\n");
    printf("Length: %d\n", length);
    printf("Contains Number: %s\n", num ? "Yes" : "No");
    printf("Contains Special Character: %s\n", special ? "Yes" : "No");

    if (length < 6) {
        printf("\nPassword Strength: WEAK \n");
    } 
    else if (length >= 6 && num && !special) {
        printf("\nPassword Strength: MEDIUM \n");
    } 
    else if (length >= 8 && num && special) {
        printf("\nPassword Strength: STRONG \n");
    } 
    else {
        printf("\nPassword Strength: WEAK \n");
    }

    if (length < 6 || !num || !special) {
        printf("\nDo you want me to generate a strong password for you? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            generatePassword();
        } else {
            printf("\nOkay! Please consider improving your password.\n");
        }
    }

    printf("\nThank you for using Password Strength Checker!\n");
    return 0;
}
