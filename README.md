# Inet3101-Lab1
Inventory Parts Manager Code

## Khalid Mohamed
Parts Inventory Storage Manager
Inet 3101 Lab 1

---

## Parts Inventory Storage Manager

No group members, just:
- Khalid Mohamed

Simple Program that stores details of parts and puts them in a database. I mainly used character arrays to store the database. The max amount of parts it can hold is 100.

### Menu
When the program is run, you'll see the following menu:
1. Print all records
2. Add record
3. Delete the last record
4. Print number of records
5. Print database size
6. Print number of changes
7. Exit the Program

### Steps
1. Choose a choice.
2. Return to the menu.
3. Choose another choice or exit.

### Function Definitions

#### 1. Print all records
- Loops through the database arrays and prints the details of each part.

#### 2. Add record
- Prompts the user for part details:
  - Number
  - Name
  - Size
  - Size metric
  - Cost
- Stores the input in the respective arrays.
- Increments the count of records.

#### 3. Delete the last record
- Decrements the count of records if possible.
- Prints a confirmation message.

#### 4. Print number of records
- Prints the current count of records.

#### 5. Print database size  *(not implemented for this lab)*
- Displays the current database size.
- Prints a placeholder message indicating the function is called.
  - Will probably be used in lab 2.

#### 6. Print number of changes
- Uses a static variable to track and print the number of changes to the database.

`main.c` - Contains the main function and all other function implementations.

---

Those are the design ideas behind the functions in the Parts Inventory Manager.
