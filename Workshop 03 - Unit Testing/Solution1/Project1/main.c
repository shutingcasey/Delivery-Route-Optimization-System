#define _CRT_SECURE_NO_WARNINGS

#include "mathfuncs.h"

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

struct Customer {
    char firstName[50];
    char lastName[50];
    char address[100];
    char city[50];
    char province[50];
    char postalCode[10];
};

    struct Customer enterCustomerInfo() {

        struct Customer customer;
        int again = 0;


        // Prompt the user to enter first name
        do {
            printf("Enter your first name: ");
            scanf("%[^\n]", customer.firstName);

            if (customer.firstName == "") {
                printf("Invalid Entry: ");
                again = 1;
            }

        } while (again = 1);

        again = 0;

        printf("\n");


        // Prompt the user to enter last name
        do {
            printf("Enter your last name: ");
            scanf("%[^\n]", customer.lastName);

            if (customer.lastName == "") {
                printf("Invalid Entry: ");
                again = 1;
            }

        } while (again = 1);

        again = 0;

        printf("\n");


        // Prompt the user to enter street address
        do {
            printf("Enter your street address: ");
            scanf("%[^\n]", customer.address);

            if (customer.address == "") {
                printf("Invalid Entry: ");
                again = 1;
            }

        } while (again = 1);

        again = 0;

        printf("\n");


        // Prompt the user to enter city
        do {
            printf("Enter your city: ");
            scanf("%[^\n]", customer.city);

            if (customer.city == "") {
                printf("Invalid Entry: ");
                again = 1;
            }

        } while (again = 1);

        again = 0;

        printf("\n");


        // Prompt the user to enter province:
        do {
            printf("Enter your province:: ");
            scanf("%[^\n]", customer.province);

            if (customer.province == "") {
                printf("Invalid Entry: ");
                again = 1;
            }

        } while (again = 1);

        again = 0;

        printf("\n");


        // Prompt the user to enter postal code:

        int length;

        do {
            printf("Enter your postal code:: ");
            scanf("%[^\n]", customer.postalCode);

            length = strlen(customer.postalCode);

            if (length != 7) {
                printf("Invalid Entry: ");
                again = 1;
            }

        } while (again = 1);

        again = 0;
        printf("\n");


        return customer;

    }


    int main() {
        struct Customer customerInfo;

        printf("Customer Information Entry\n");
        customerInfo = enterCustomerInfo();

        printf("\nCustomer Information:\n");
        printf("First Name: %s\n", customerInfo.firstName);
        printf("Last Name: %s\n", customerInfo.lastName);
        printf("Address: %s\n", customerInfo.address);
        printf("City: %s\n", customerInfo.city);
        printf("Province: %s\n", customerInfo.province);
        printf("Postal Code: %s\n", customerInfo.postalCode);

        return 0;
    }







 /*   do {
        printf("Enter your postal code (e.g., A1B 2C3): ");
        scanf("%s", customer.postalCode);
    } while (!isValidPostalCode(customer.postalCode));

    return customer;*/


//bool isValidPostalCode(char postalCode[]) {
//    int length = strlen(postalCode);
//    if (length != 7) // Example: A1B 2C3
//        return false;
//
//    for (int i = 0; i < length; i++) {
//        if (i == 0 || i == 2 || i == 5) {
//            if (!isalpha(postalCode[i]) || !isupper(postalCode[i]))
//                return false;
//        }
//        else if (i == 1 || i == 4) {
//            if (!isdigit(postalCode[i]))
//                return false;
//        }
//        else if (i == 3) {
//            if (postalCode[i] != ' ')
//                return false;
//        }
//    }
//
//    // Transfer to upper case
//    for (int i = 0; i < length; i++) {
//        postalCode[i] = toupper(postalCode[i]);
//    }
//
//    return true;
//}


//struct Customer enterCustomerInfo() {




//}

//int main() {
//    struct Customer customerInfo;
//
//    printf("Customer Information Entry\n");
//    customerInfo = enterCustomerInfo();
//
//    printf("\nCustomer Information:\n");
//    printf("First Name: %s\n", customerInfo.firstName);
//    printf("Last Name: %s\n", customerInfo.lastName);
//    printf("Address: %s\n", customerInfo.address);
//    printf("City: %s\n", customerInfo.city);
//    printf("Province: %s\n", customerInfo.province);
//    printf("Postal Code: %s\n", customerInfo.postalCode);
//
//
//    // Class note
//    printf("the square of 3 is %lf\n", square(3));
//    printf("the cube of 5 is %lf\n", cube(5));
//
//    return 0;
//}
