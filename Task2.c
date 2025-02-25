/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;              // Data part of the node
    struct Node* next;     // Pointer to the next node
};

// Function to create a new node with the given value
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for a new node
    if (!newNode) { // Check if memory allocation was successful
        printf("Memory allocation failed!\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = value; // Assign the data
    newNode->next = NULL;  // Initialize the next pointer to NULL
    return newNode;        // Return the newly created node
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value); // Create a new node with the given value
    newNode->next = *head; // Point the new node's next to the current head
    *head = newNode;       // Update the head to the new node
    printf("Node inserted at the beginning.\n");
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value); // Create a new node with the given value
    if (*head == NULL) { // Check if the list is empty
        *head = newNode; // If empty, make the new node the head
    } else {
        struct Node* temp = *head; // Start at the head
        while (temp->next != NULL) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Link the last node to the new node
    }
    printf("Node inserted at the end.\n");
}

// Function to delete a node by value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) { // Check if the list is empty
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head; // Temporary pointer to traverse the list
    struct Node* prev = NULL;  // Pointer to keep track of the previous node

    // If the node to be deleted is the head
    if (temp != NULL && temp->data == value) {
        *head = temp->next; // Update head to the next node
        free(temp);         // Free the memory of the deleted node
        printf("Node with value %d deleted.\n", value);
        return;
    }

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->data != value) {
        prev = temp; // Update the previous node
        temp = temp->next; // Move to the next node
    }

    // If the value was not found in the list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Unlink the node and free its memory
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

// Function to traverse and display the linked list
void traverseList(struct Node* head) {
    if (head == NULL) { // Check if the list is empty
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head; // Temporary pointer to traverse the list
    printf("Linked list: ");
    while (temp != NULL) { // Traverse until the end of the list
        printf("%d -> ", temp->data); // Print the data of each node
        temp = temp->next; // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}

// Main function to provide a menu for linked list operations
int main() {
    struct Node* head = NULL; // Initialize the head of the list as NULL
    int choice, value;

    do {
        // Display the menu
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete by Value\n");
        printf("4. Traverse List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read the user's choice

        switch (choice) {
            case 1: // Insert a node at the beginning
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2: // Insert a node at the end
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3: // Delete a node by value
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4: // Traverse and display the list
                traverseList(head);
                break;
            case 5: // Exit the program
                printf("Exiting program...\n");
                break;
            default: // Handle invalid choices
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5); // Repeat until the user chooses to exit

    return 0; // Indicate successful program termination
}
