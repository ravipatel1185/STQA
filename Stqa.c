#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>
#include<ctype.h>
#include<time.h>
#include<assert.h>

struct user
{
    char name[50];
    int age;
    char gender[10];
    char phone[15];
    char pnr[6];
    char source[50];
    char destination[50];
    char seat_type[10];
    long long cost;
    bool is_booked;
    struct user *next;
};

struct user *head = NULL;
struct user *tail = NULL;
int pnr_counter = 82725;

void book_ticket();
void view_ticket();
void cancel_ticket();
void display_all_tickets();
void menu();

void cancel_ticket()
{
    printf("\nCancel Ticket functionality is not yet implemented.\n");
}

void display_all_tickets()
{
    printf("\nDisplay All Tickets functionality is not yet implemented.\n");
}

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

void menu()
{
    int choice;
    while(1)
    {
        printf("\n\n********** Railway Management System **********\n");
        printf("1. Book Ticket\n");
        printf("2. View Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Display All Tickets\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                book_ticket();
                break;
            case 2:
                view_ticket();
                break;
            case 3:
                cancel_ticket();
                break;
            case 4:
                display_all_tickets();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void book_ticket()
{
    struct user *new_user = (struct user*)malloc(sizeof(struct user));
    if (new_user == NULL) {
        printf("Memory allocation failed!\n");
        return;

    }
    printf("Enter Name: ");
    scanf("%s", new_user->name);
    printf("Enter Age: ");
    scanf("%d", &new_user->age);
    printf("Enter Gender: ");
    scanf("%s", new_user->gender);
    printf("Enter Phone Number: ");
    scanf("%s", new_user->phone);
    printf("Enter Source: ");
    scanf("%s", new_user->source);
    printf("Enter Destination: ");
    scanf("%s", new_user->destination);
    printf("Enter Seat Type (sleeper/ac/non-ac): ");
    scanf("%s", new_user->seat_type);

    if(strcmp(new_user->seat_type, "sleeper") == 0)
    {
        new_user->cost = 500;
    }
    else if(strcmp(new_user->seat_type, "ac") == 0)
    {
        new_user->cost = 1000;
    }
    else if(strcmp(new_user->seat_type, "non-ac") == 0)
    {
        new_user->cost = 700;
    }
    
    else
    {
        printf("Invalid seat type! Booking failed.\n");
        free(new_user);
        return;
    }

    sprintf(new_user->pnr, "%d", pnr_counter);
    pnr_counter++; 

    new_user->is_booked = true;
    new_user->next = NULL;

    if(head == NULL)
    {
        head = new_user;
        tail = new_user;
    }
    else
    {
        tail->next = new_user;
        tail = new_user;
    }
    printf("Ticket booked successfully! Your PNR number is %s\n", new_user->pnr);
}

void view_ticket()
{
    char pnr[10];
    printf("Enter PNR number: ");
    scanf("%s", pnr);
    struct user *temp = head;

    while(temp != NULL)
    {
        if(strcmp(temp->pnr, pnr) == 0 && temp->is_booked)
        {
            printf("\n********** Ticket Details **********\n");
            printf("PNR Number: %s\n", temp->pnr);
            printf("Name: %s\n", temp->name);
            printf("Age: %d\n", temp->age);
            printf("Gender: %s\n", temp->gender);
            printf("Phone Number: %s\n", temp->phone);
            printf("Source: %s\n", temp->source);
            printf("Destination: %s\n", temp->destination);
            printf("Seat Type: %s\n", temp->seat_type);
            printf("Cost: %lld\n", temp->cost);
            return;
        }
        temp = temp->next;
    }
    printf("Ticket not found or already cancelled!\n");
}