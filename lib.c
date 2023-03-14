#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Book
{
    /* data */

    int stdNo;
    int ISBN_no;
    char title[20];
    struct Book *next;
};

// login function, return true if successfully logged in
bool logIn()
{
    char A[50], password[] = "Admin123";
    bool flag;
    int n;

    printf("LOGIN\n========");
    while (n <= 2)
    {
        printf("\nEnter Password to login: ");
        scanf("%s", A);
        if (strcmp(password, A) == 0)
        {
            flag = true;
            break;
        }
        else
        {
            n++;
            printf("incorrect password");
        }
    }
    if (n == 3)
    {
        printf("\nOops!! you have exhausted number of login attempts\n");
        flag = false;
        exit(0);
    }
    return flag;
}

// function to add a book
int Book_Borrowed(struct Book **Start)
{
    int stdNo;
    int ISBN_no;
    int n;

    // use dynamic memory allocation
    struct Book *temp, *t;

    temp = malloc(n * sizeof(struct Book));
    printf("Enter student number: ");
    scanf("%d", &stdNo);
    temp->stdNo = stdNo;
    printf("Enter Book Title: ");
    scanf("%s", temp->title);
    printf("Enter ISBN number: ");
    scanf("%d", &ISBN_no);
    temp->ISBN_no = ISBN_no;

    temp->next = NULL;
    if (*Start == NULL)
        *Start = temp;
    else
    {
        t = *Start;
        while (t->next != NULL)
            t = t->next;
        t->next = temp;
    }
}

// function to view borrowed books
void View_books(struct Book *Start)
{
    int i = 1;

    if (Start == NULL)
        printf("No book borrowed");
    else
    {

        while (Start)
        {
            /* code */
            printf("\nBook %d\n", i);
            printf("Registration number: %d\n", Start->stdNo);
            printf("ISBN number: %d\n", Start->ISBN_no);
            printf("Book title: ");
            puts(Start->title);
            Start = Start->next;
            i++;
        }
    }
}

void Return_book(struct Book **Start, int ISBN_no2)
{
    struct Book *temp, *t;

    int i = 0;
    if (*Start == NULL)
    {
        printf("There is no Book in record");
    }
    else if ((*Start)->ISBN_no == ISBN_no2)
    {
        temp = *Start;
        *Start = (*Start)->next;
        free(temp);
        printf("Book removed successfully");
    }
    else
    {
        temp = *Start;
        while (temp->next != NULL)
        {
            if (temp->ISBN_no == ISBN_no2)
            {
                i = 1;
                break;
            }
            t = temp;
            temp = temp->next;
        }
        if (i != 1)
            printf("Book with that ISBN not found");
        else
        {
            t->next = temp->next;
            free(temp);
            printf("Book removed successfully");
        }
    }
}

int menu(void)
{
    int choice;
    printf("\n*****************************\nDkut Library Management System\n*****************************\n");
    printf("\n1: Borrow a book");
    printf("\n2: View a book");
    printf("\n3: Return a Book");
    printf("\n4: Quit!!");
    printf("\n\nEnter your choice: \n");
    scanf("%d", &choice);
    return (choice);
}

int main()
{
    int data;
    struct Book *Start = NULL;
    char option[1];

    // while the password is correct
    while (logIn())
    {
        /* code */
        while (1)
        {
            // system("cls");
            switch (menu())
            {
            case 1:
                Book_Borrowed(&Start);
                printf("Do you want to continue issue another book [Y/N]: ");
                scanf("%s", option);
                if (option == "N" || option == "n")
                {
                    exit(0);
                }
                else if (option == "Y" || option == "Y")
                {
                    break;
                }
                break;
            case 2:
                View_books(Start);
                break;
            case 3:
                printf("Enter the ISBN number of the book returned: ");
                scanf("%d", &data);
                Return_book(&Start, data);
                break;
            case 4:
                exit(0);
            }
            getchar();
        }
    }
}