#include <stdio.h>
#include <conio.h> // This header is non-standard. Use standard headers instead.

// Define the maximum size of the queue
#define MAX 10

// Declare the queue, front and rear variables
int data[MAX], rear, front;

// Function prototypes
void initialize();
int empty();
int full();
void insertion();
void deletion();
void print();

int main()
{
    int ch;
    clrscr(); // This is non-standard. Use system("cls") for Windows or a similar function for other OS.
    initialize();
    do
    {
        printf("\n ***QUEUE OPERATIONS");
        printf("\n 1. Insertion");
        printf("\n 2. Deletion");
        printf("\n 3. Print");
        printf("\n 4. EXIT");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (!full())
            {
                insertion();
            }
            else
            {
                printf("\nQueue is Full!!!");
            }
            break;
        case 2:
            if (!empty())
            {
                deletion();
            }
            else
            {
                printf("\nQueue is Empty!!!");
            }
            break;
        case 3:
            print();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice");
        }
    } while (ch != 4);

    // getch(); // This is non-standard. It is often used in older compilers. Not required in most cases.
    return 0;
}

void initialize()
{
    rear = front = -1;
}

int full()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

int empty()
{
    if (front == -1 || front > rear) // Adjust condition to handle the case when queue is reset
        return 1;
    else
        return 0;
}

void insertion()
{
    int x;
    printf("Enter data to be inserted: ");
    scanf("%d", &x);

    if (empty()) // Handle the case when the queue is initially empty
    {
        front = rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    data[rear] = x;
}

void deletion()
{
    int x;
    if (!empty())
    {
        x = data[front];
        if (front == rear)
        {
            rear = front = -1; // Reset queue when it's empty after deletion
        }
        else
        {
            front = front + 1;
        }
        printf("\nDeleted data = %d", x);
    }
    else
    {
        printf("\nQueue is Empty!!!");
    }
}

void print()
{
    int i;
    if (empty())
    {
        printf("\nQueue is Empty!!!");
    }
    else
    {
        printf("\nQueue data: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", data[i]);
        }
    }
}

