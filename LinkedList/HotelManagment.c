/* Hotel Management System
Create a menu-driven C program to replicate a hotel management system utilizing appropriate data structures (like Linked Lists or Queues).
Core Functionalities:
Check-in: Insert a new guest record into the active system.
Check-out: Delete a guest from the active checked-in records and move them to a checked-out record.
Admin Controls: Hotel admin should be able to create a new guest record and manually delete any record from the system.
Record Tracking:
Maintain a separate record pointing to the latest check-in and the latest check-out of a guest.
Display Options:
Display all currently checked-in guests.
Display all checked-out guests.
Display a master list of all guests that have visited the hotel (both past and present).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Guest
{
    int id;
    char name[30];
    int room;
    struct Guest *next;
};

/* Three separate lists */
struct Guest *active = NULL;
struct Guest *checkedOut = NULL;
struct Guest *master = NULL;

/* Latest records */
struct Guest *latestCheckIn = NULL;
struct Guest *latestCheckOut = NULL;


/* Create a new guest node */
struct Guest* createGuest(int id, char name[], int room)
{
    struct Guest *newGuest;

    newGuest = (struct Guest*)malloc(sizeof(struct Guest));

    newGuest->id = id;
    strcpy(newGuest->name, name);
    newGuest->room = room;
    newGuest->next = NULL;

    return newGuest;
}


/* Check-in a guest */
void checkIn()
{
    int id, room;
    char name[30];

    printf("Enter Guest ID: ");
    scanf("%d", &id);

    printf("Enter Guest Name: ");
    scanf("%s", name);

    printf("Enter Room Number: ");
    scanf("%d", &room);

    struct Guest *newGuest = createGuest(id, name, room);

    /* Insert into active list */
    newGuest->next = active;
    active = newGuest;

    /*
       Create a separate copy for master list.
       This is important because the active node may
       later be removed during check-out.
    */
    struct Guest *masterGuest = createGuest(id, name, room);

    masterGuest->next = master;
    master = masterGuest;

    latestCheckIn = masterGuest;

    printf("Guest checked in successfully.\n");
}


/* Check-out a guest */
void checkOut()
{
    int id;

    printf("Enter Guest ID to check-out: ");
    scanf("%d", &id);

    struct Guest *temp = active;
    struct Guest *prev = NULL;

    /* Search for guest */
    while(temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Guest not found in active records.\n");
        return;
    }

    /* Delete from active list */
    if(prev == NULL)
    {
        active = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    /* Move guest to checked-out list */
    temp->next = checkedOut;
    checkedOut = temp;

    latestCheckOut = temp;

    printf("Guest checked out successfully.\n");
}


/* Admin: manually create a guest record */
void adminCreate()
{
    int id, room;
    char name[30];

    printf("Enter Guest ID: ");
    scanf("%d", &id);

    printf("Enter Guest Name: ");
    scanf("%s", name);

    printf("Enter Room Number: ");
    scanf("%d", &room);

    struct Guest *newGuest = createGuest(id, name, room);

    /* Add to active list */
    newGuest->next = active;
    active = newGuest;

    /* Add separate copy to master list */
    struct Guest *masterGuest = createGuest(id, name, room);

    masterGuest->next = master;
    master = masterGuest;

    latestCheckIn = masterGuest;

    printf("Guest record created successfully.\n");
}


/* Admin: manually delete any active record */
void adminDelete()
{
    int id;

    printf("Enter Guest ID to delete: ");
    scanf("%d", &id);

    struct Guest *temp = active;
    struct Guest *prev = NULL;

    while(temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Guest not found.\n");
        return;
    }

    if(prev == NULL)
    {
        active = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);

    printf("Guest record deleted successfully.\n");
}


/* Display currently checked-in guests */
void displayActive()
{
    struct Guest *temp = active;

    if(temp == NULL)
    {
        printf("No guests are currently checked in.\n");
        return;
    }

    printf("\n===== CURRENTLY CHECKED-IN GUESTS =====\n");

    while(temp != NULL)
    {
        printf("ID: %d  Name: %s  Room: %d\n",
               temp->id, temp->name, temp->room);

        temp = temp->next;
    }
}


/* Display checked-out guests */
void displayCheckedOut()
{
    struct Guest *temp = checkedOut;

    if(temp == NULL)
    {
        printf("No guests have checked out.\n");
        return;
    }

    printf("\n===== CHECKED-OUT GUESTS =====\n");

    while(temp != NULL)
    {
        printf("ID: %d  Name: %s  Room: %d\n",
               temp->id, temp->name, temp->room);

        temp = temp->next;
    }
}


/* Display all guests */
void displayMaster()
{
    struct Guest *temp = master;

    if(temp == NULL)
    {
        printf("No guest records available.\n");
        return;
    }

    printf("\n===== MASTER GUEST LIST =====\n");

    while(temp != NULL)
    {
        printf("ID: %d  Name: %s  Room: %d\n",
               temp->id, temp->name, temp->room);

        temp = temp->next;
    }
}


/* Display latest check-in */
void displayLatestCheckIn()
{
    if(latestCheckIn == NULL)
    {
        printf("No check-in record available.\n");
        return;
    }

    printf("\n===== LATEST CHECK-IN =====\n");
    printf("ID: %d\n", latestCheckIn->id);
    printf("Name: %s\n", latestCheckIn->name);
    printf("Room: %d\n", latestCheckIn->room);
}


/* Display latest check-out */
void displayLatestCheckOut()
{
    if(latestCheckOut == NULL)
    {
        printf("No check-out record available.\n");
        return;
    }

    printf("\n===== LATEST CHECK-OUT =====\n");
    printf("ID: %d\n", latestCheckOut->id);
    printf("Name: %s\n", latestCheckOut->name);
    printf("Room: %d\n", latestCheckOut->room);
}


int main()
{
    int choice;

    do
    {
        printf("\n========== HOTEL MANAGEMENT SYSTEM ==========\n");
        printf("1. Check-in\n");
        printf("2. Check-out\n");
        printf("3. Admin - Create Guest Record\n");
        printf("4. Admin - Delete Guest Record\n");
        printf("5. Display Checked-in Guests\n");
        printf("6. Display Checked-out Guests\n");
        printf("7. Display Master Guest List\n");
        printf("8. Display Latest Check-in\n");
        printf("9. Display Latest Check-out\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                checkIn();
                break;

            case 2:
                checkOut();
                break;

            case 3:
                adminCreate();
                break;

            case 4:
                adminDelete();
                break;

            case 5:
                displayActive();
                break;

            case 6:
                displayCheckedOut();
                break;

            case 7:
                displayMaster();
                break;

            case 8:
                displayLatestCheckIn();
                break;

            case 9:
                displayLatestCheckOut();
                break;

            case 10:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 10);

    return 0;
}

