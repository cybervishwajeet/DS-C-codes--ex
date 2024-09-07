#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>  

typedef struct node
{
    int data;
    struct node *next;
} node;

// Function prototypes
node* create(int n);
void print(node *p);
void count(node *p);
void search(node *p);
node* insert_at_Begin(node *head);
node* insert_at_Middle(node *head);
node* insert_at_End(node *head);
node* delete_at_Begin(node *head);
node* delete_at_Middle(node *head);
node* delete_at_End(node *head);

int main()
{
    node *Head = NULL;
    int no, op;
    
    clrscr(); // This is non-standard. Use system("cls") for Windows or a similar function for other OS.

    do
    {
        printf("\n************SLL OPERATIONS*************");
        printf("\n1. Create\n2. Print\n3. Count\n4. Search");
        printf("\n5. Insert at Begin\n6. Insert at Middle\n7. Insert at End");
        printf("\n8. Delete from Begin\n9. Delete from Middle\n10. Delete from End\n11. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                printf("\nEnter size of linked list: ");
                scanf("%d", &no);
                Head = create(no);
                break;
            case 2:
                print(Head);
                break;
            case 3:
                count(Head);
                break;
            case 4:
                search(Head);
                break;
            case 5:
                Head = insert_at_Begin(Head);
                break;
            case 6:
                Head = insert_at_Middle(Head);
                break;
            case 7:
                Head = insert_at_End(Head);
                break;
            case 8:
                Head = delete_at_Begin(Head);
                break;
            case 9:
                Head = delete_at_Middle(Head);
                break;
            case 10:
                Head = delete_at_End(Head);
                break;
            case 11:
                printf("\nGood Bye.. Thanks for using our Application!!!");
                break;
            default:
                printf("\nPlease select a valid option!!!");
        }

        // Using getchar() to wait for user input if getch() is not available
        //getchar(); // Uncomment if needed to pause before clearing screen
        //clrscr(); // Uncomment if needed to clear screen after each operation

    } while(op != 11);

    return 0;
}

node* create(int n)
{
    node *head = NULL, *p = NULL;
    int i, x;

    if (n <= 0) {
        printf("\nInvalid size for linked list.");
        return NULL;
    }

    printf("\nEnter data: ");
    scanf("%d", &x);
    
    head = (node*)malloc(sizeof(node));
    head->data = x;
    head->next = NULL;
    p = head;

    for(i = 2; i <= n; i++)
    {
        printf("\nEnter data: ");
        scanf("%d", &x);
        
        p->next = (node*)malloc(sizeof(node));
        p = p->next;
        p->data = x;
        p->next = NULL;
    }

    printf("\nLinked list created successfully:");
    return head;
}

void print(node *p)
{
    if (p == NULL) {
        printf("\nLinked list is empty.");
        return;
    }

    printf("\nSLL Nodes: ");
    while(p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void count(node *p)
{
    int count = 0;
    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    printf("\nNumber of Nodes: %d", count);
}

void search(node *p)
{
    int key, found = 0;
    printf("\nEnter key element to be searched: ");
    scanf("%d", &key);

    while(p != NULL)
    {
        if(key == p->data)
        {
            found = 1;
            break;
        }
        p = p->next;
    }

    if(found)
        printf("\nElement is found!!!");
    else
        printf("\nElement is not found!!!");
}

node* insert_at_Begin(node *head)
{
    node *q;
    int x;
    printf("\nEnter data: ");
    scanf("%d", &x);

    q = (node*)malloc(sizeof(node));
    q->data = x;
    q->next = head;

    printf("\nNode inserted at Begin successfully!!!");
    return q;
}

node* insert_at_End(node *head)
{
    node *q, *p;
    int x;
    printf("\nEnter data: ");
    scanf("%d", &x);

    q = (node*)malloc(sizeof(node));
    q->data = x;
    q->next = NULL;

    if (head == NULL) {
        printf("\nNode inserted at end successfully!!!");
        return q;
    }

    p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;

    printf("\nNode inserted at end successfully!!!");
    return head;
}

node* insert_at_Middle(node *head)
{
    node *q, *p;
    int x, loc, i;

    if (head == NULL) {
        printf("\nLinked list is empty!!! You cannot insert node at middle!!!");
        return NULL;
    }

    printf("\nEnter data: ");
    scanf("%d", &x);
    printf("\nEnter location for insertion: ");
    scanf("%d", &loc);

    if (loc <= 1) {
        return insert_at_Begin(head);
    }

    q = (node*)malloc(sizeof(node));
    q->data = x;
    q->next = NULL;

    p = head;
    for(i = 1; i < loc - 1; i++)
    {
        if (p == NULL) {
            printf("\nLocation out of bounds.");
            free(q);
            return head;
        }
        p = p->next;
    }

    q->next = p->next;
    p->next = q;

    printf("\nNode inserted at middle successfully!!!");
    return head;
}

node* delete_at_Begin(node *head)
{
    node *q;

    if (head == NULL) {
        printf("\nLinked list is already empty!!! You cannot delete node.");
        return NULL;
    }

    q = head;
    head = head->next;
    free(q);

    printf("\nNode deleted from Begin successfully!!!");
    return head;
}

node* delete_at_End(node *head)
{
    node *q, *p;

    if (head == NULL) {
        printf("\nLinked list is already empty!!! You cannot delete node.");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    p = head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    q = p->next;
    p->next = NULL;
    free(q);

    printf("\nNode deleted from End successfully!!!");
    return head;
}

node* delete_at_Middle(node *head)
{
    node *q, *p;
    int loc, i;

    if (head == NULL) {
        printf("\nLinked list is already empty!!! You cannot delete node.");
        return NULL;
    }

    printf("\nEnter location of node for deletion: ");
    scanf("%d", &loc);

    if (loc <= 1) {
        return delete_at_Begin(head);
    }

    p = head;
    for(i = 1; i < loc - 1; i++)
    {
        if (p == NULL || p->next == NULL) {
            printf("\nLocation out of bounds.");
            return head;
        }
        p = p->next;
    }

    q = p->next;
    p->next = q->next;
    free(q);

    printf("\nNode deleted from Middle successfully!!!");
    return head;
}

