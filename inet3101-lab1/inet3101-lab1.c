/*
Khalid Mohamed
Parts Inventory Manager
Inet 3101 Lab 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTS 100 //max number of parts

// funciton to print all records currently in the database
void printRecords(int partnumber[], char partname[][50], float partsize[], char partsizemet[][20], float partcost[], int count) {
    printf("\n\nPrint out list of parts in database: \n\n");
    for (int i = 0; i < count; i++) {
        printf("Part Number: %d\n", partnumber[i]);
        printf("Part Name: %s\n", partname[i]);
        printf("Part Size: %.2f\n", partsize[i]);
        printf("Part Metric: %s\n", partsizemet[i]);
        printf("Part Cost: %.2f\n", partcost[i]);
        printf("\n\n");
    }
}

// function to add a new record 
void addRecord(int partnumber[], char partname[][50], float partsize[], char partsizemet[][20], float partcost[], int *count) {
    if (*count >= MAX_PARTS) {
        printf("Database is full!\n");
        return;
    }

    printf("Adding Part Record\n\n");
    int partNum;
    char partName[50];
    float partSize;
    char partSizeMetric[20];
    float partCost;

//getting user input
    printf("Please Enter the Part Number: ");
    scanf("%d", &partNum);
    printf("Please Enter the Part Name: ");
    scanf(" %49[^\n]", partName);
    printf("Please Enter the Part Size: ");
    scanf("%f", &partSize);
    printf("Please Enter Part Size Metric (pounds, kilograms, feet, etc.): ");
    scanf(" %19s", partSizeMetric);
    printf("Please Enter the Part Cost: ");
    scanf("%f", &partCost);

//copying the inpput and storing as arrays
    partnumber[*count] = partNum;
    strcpy(partname[*count], partName);
    partsize[*count] = partSize;
    strcpy(partsizemet[*count], partSizeMetric);
    partcost[*count] = partCost;

//incrementing count
    (*count)++;

    printf("You entered:\n");
    printf("\tPart number = %d\n", partNum);
    printf("\tPart name = \"%s\"\n", partName);
    printf("\tPart size = %.2f\n", partSize);
    printf("\tPart size metric = \"%s\"\n", partSizeMetric);
    printf("\tPart cost = $%.2f\n", partCost);
}

// funciton to delete the last inputted record
void deleteRecord(int *count) {
    if (*count > 0) {
        (*count)--;
        printf("Last record deleted.\n");
    } else {
        printf("No records to delete.\n");
    }
}

// function to print the current total number of records
void printNumRecords(int count) {
    printf("\n\nNumber of parts records is: %d\n", count);
}

//function to get databse size
void printDatabaseSize() {
    printf("\n\nYou have entered the Print database size function\n");
}

//function to the returns total number of changes to the databse ie addition, deletion
void printNumChanges(int *changes, int increment) {
    if (increment) {
        (*changes)++;
    } else {
        printf("\n\nYou have modified the database %d times\n", *changes);
    }
}
// main functiion that gets controls the parts manger 
int main() {
    // storing part details as arrays
    int partnumber[MAX_PARTS];
    char partname[MAX_PARTS][50];
    float partsize[MAX_PARTS];
    char partsizemet[MAX_PARTS][20];
    float partcost[MAX_PARTS];
    //declaring variables
    int count = 0;
    int changes = 0;
    int selection;
    int looper = 6; // control value for while loop

    // saample value 
    partnumber[count] = 101;
    strcpy(partname[count], "windshield");
    partsize[count] = 1.5;
    strcpy(partsizemet[count], "meters");
    partcost[count] = 250.75;
    count++;
    changes++;
    // main menu screen loop 
    while (looper <= 6) {
        printf("\n\nParts Inventory Manager\n\n");
        printf("1. Print all records\n");
        printf("2. Add record\n");
        printf("3. Delete the last record\n");
        printf("4. Print number of records\n");
        printf("5. Print database size\n");
        printf("6. Print number of changes\n");
        printf("7. Exit\n\n");
        printf("Please enter your selection: ");
        scanf("%d", &selection);
        // calls functions associated with user input
        switch (selection) {
            case 1:
                printRecords(partnumber, partname, partsize, partsizemet, partcost, count);
                break;
            case 2:
                addRecord(partnumber, partname, partsize, partsizemet, partcost, &count);
                printNumChanges(&changes, 1);
                break;
            case 3:
                deleteRecord(&count);
                printNumChanges(&changes, 1);
                break;
            case 4:
                printNumRecords(count);
                break;
            case 5:
                printDatabaseSize();
                break;
            case 6:
                printNumChanges(&changes, 0);
                break;
            case 7:
                printf("\n\nThank you for using the Parts Inventory Manager\n");
                looper = selection;
                break;
            default:
                printf("Invalid selection. Please enter a number between 1 and 7.\n");
        }
    }

    return 0;
}
