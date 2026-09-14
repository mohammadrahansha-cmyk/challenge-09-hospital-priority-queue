#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    char name[50];
    int priority;
};

struct Patient queue[MAX];
int count = 0;


// Function to add patient
void addPatient(char name[], int priority) {

    int pos = count;

    while (pos > 0 &&
           queue[pos - 1].priority > priority) {

        queue[pos] = queue[pos - 1];
        pos--;
    }

    strcpy(queue[pos].name, name);
    queue[pos].priority = priority;

    count++;

    printf("\nPatient Added Successfully!\n");
}


// Function to treat next patient
void treatNext() {

    if (count == 0) {

        printf("\nNo patients waiting!\n");
        return;
    }

    printf("\n---------------------------\n");

    printf("Treating Patient: %s\n",
           queue[0].name);

    printf("Priority: %d\n",
           queue[0].priority);

    printf("---------------------------\n");


    // Remove patient after treatment

    for (int i = 0;
         i < count - 1;
         i++) {

        queue[i] = queue[i + 1];
    }

    count--;
}


// Function to display patients

void displayPatients() {

    if (count == 0) {

        printf("\nNo patients waiting!\n");

        return;
    }

    printf("\n--- WAITING PATIENTS ---\n");


    for (int i = 0;
         i < count;
         i++) {

        printf("%d. %s - Priority %d\n",

               i + 1,

               queue[i].name,

               queue[i].priority);
    }
}


// Main Function

int main() {

    int choice;

    int priority;

    char name[50];


    while (1) {

        printf("\n");

        printf("==============================\n");

        printf(" HOSPITAL PRIORITY QUEUE\n");

        printf("==============================\n");


        printf("1. Add Patient\n");

        printf("2. Treat Next Patient\n");

        printf("3. Display Patients\n");

        printf("4. Exit\n");


        printf("\nEnter your choice: ");

        scanf("%d", &choice);


        switch (choice) {


        case 1:

            printf("\nEnter Patient Name: ");

            scanf("%s", name);


            printf("\nPriority:\n");

            printf("1 = Emergency\n");

            printf("2 = Urgent\n");

            printf("3 = Routine\n");


            printf("\nEnter Priority: ");

            scanf("%d", &priority);


            if (priority < 1 || priority > 3) {

                printf("\nInvalid Priority!\n");

            }

            else {

                addPatient(name, priority);

            }

            break;


        case 2:

            treatNext();

            break;


        case 3:

            displayPatients();

            break;


        case 4:

            printf("\nProgram Closed Successfully!\n");

            return 0;


        default:

            printf("\nInvalid Choice!\n");

        }
    }


    return 0;
}
