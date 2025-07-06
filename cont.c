#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    time_t now;
    time(&now);

    int num1, num2;
    double dr;
    int choice;

    while (1)
    {
        printf("\n------ Calculator Menu ------\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. History\n");
        printf("6. Exit\n");
        printf("Choose an operation (1-5): ");
        scanf("%d", &choice);
        if (choice == 5) // history ekne
        {
            system("cls");
            char str[100];
            FILE *his = fopen("history.txt", "r");
            if (his == 0)
            {
                printf("No history found\n\n");
                continue;
            }
            printf("\n  '''''''''''History''''''''''  \n\n");
            while (fscanf(his, "%[^\n]\n", str) == 1)
            {
                printf("%s\n", str);
            }
            fclose(his);
            int hi;
            printf("\n\n\n\nPress 1 to clear history\n\n");
            printf("Press 2 to Menu\n\n");
            scanf("%d", &hi);
            if (hi == 1)    // history clear er jnno
            {
                FILE *his = fopen("history.txt", "w");
                system("cls");
                printf("History Cleared!!!!!!!!!!\n");
                continue;
            }
            if (hi == 2)    // main menu
            {
                continue;
            }
            else
            {
                printf("Wrong type\n");
                continue;
            }
            
        }
        else if (choice == 6) // exit
        {
            printf("Exiting...... Please wait\n");
            break;
        }
        else if (choice == 1) // jog
        {
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
            dr = num1 + num2;
            system("cls");

            printf("\n\n\n******************************\n\n");
            printf("Result: %d + %d = %.0lf\n", num1, num2, dr);
            printf("\n******************************\n");
            FILE *his = fopen("history.txt", "a");
            fprintf(his, "%d + %d = %.0lf\n", num1, num2, dr);
            fprintf(his, "%s",ctime(&now));
            fclose(his);
        }
        else if (choice == 2) // biyog
        {
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
            dr = num1 - num2;
            system("cls");

            printf("\n\n\n******************************\n\n");
            printf("Result: %d - %d = %.0lf\n", num1, num2, dr);
            printf("\n******************************\n");
            FILE *his = fopen("history.txt", "a");
            fprintf(his, "%d - %d = %.0lf\n", num1, num2, dr);
            fprintf(his, "%s",ctime(&now));
            fclose(his);
        }
        else if (choice == 3) // gun
        {
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
            dr = num1 * num2;
            system("cls");

            printf("\n\n\n******************************\n\n");
            printf("Result: %d * %d = %.0lf\n", num1, num2, dr);
            printf("\n******************************\n");
            FILE *his = fopen("history.txt", "a");
            fprintf(his, "%d * %d = %.0lf\n", num1, num2, dr);
            fprintf(his, "%s",ctime(&now));
            fclose(his);
        }
        else if (choice == 4) // vaag
        {
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
            system("cls");
            if (num2 != 0)
            {
                dr = (double)num1 / num2;
                printf("\n\n\n******************************\n\n");
                printf("Result: %d / %d = %.1lf\n", num1, num2, dr);
                printf("\n******************************\n");
                FILE *his = fopen("history.txt", "a");
                fprintf(his, "%d / %d = %.0lf\n", num1, num2, dr);
                fprintf(his, "%s",ctime(&now));
                fclose(his);
            }
            else
            {
                printf("Error: Division by zero is not allowed!\n");
            }
        }

        else
        {
            printf("Please select between 1 and 6.\n");
        }
    }
    return 0;
}
