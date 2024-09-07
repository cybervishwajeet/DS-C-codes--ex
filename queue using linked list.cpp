#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct node {
    int data;
    struct node *next;
};

// Define front and rear pointers
struct node *front = NULL, *rear = NULL;

// Function to insert element in queue
void enqueue() {
    int item;
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &item);

    // Allocate memory for new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = item;
    new_node->next = NULL;

    // Insert the node into the queue
    if (rear == NULL) {
        // Queue is empty
        front = rear = new_node;
    } else {
        // Queue is not empty
        rear->next = new_node;
        rear = new_node;
    }
}

// Function to delete element from queue
void dequeue() {
    if (front == NULL) {
        printf("\nQueue is empty.\n");
        return;
    }

    // Remove the node from the front of the queue
    struct node *temp_node = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL; // Queue is now empty
    }
    printf("\nDeleted element is %d\n", temp_node->data);
    free(temp_node);
}

// Function to display elements of queue
void display() {
    if (front == NULL) {
        printf("\nQueue is empty.\n");
        return;
    }

    // Display the elements of the queue
    struct node *temp_node = front;
    printf("\nElements in the queue are: ");
    while (temp_node != NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while(1) {
        printf("\nQueue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}

