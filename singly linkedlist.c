#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

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

int main() {
    node *Head = NULL;
    int no, op;

    do {
        printf("\n************SLL OPERATIONS*************");
        printf("\n1.Create\n2.Print\n3.Count\n4.Search");
        printf("\n5.Insert at Begin\n6.Insert at Middle\n7.Insert at End");
        printf("\n8.Delete from Begin\n9.Delete from Middle\n10.Delete from End\n11.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &op);

        switch(op) {
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
                printf("\nGood Bye..Thanks for using our Application!!!\n");
                break;
            default:
                printf("\nPlease select a valid option!!!\n");
        }
    } while(op != 11);

    return 0;
}

node* create(int n) {
    node *head = NULL, *p = NULL, *temp = NULL;
    int i, x;

    if (n <= 0) {
        printf("\nInvalid size!\n");
        return NULL;
    }

    printf("\nEnter data: ");
    scanf("%d", &x);

    head = (node*)malloc(sizeof(node));
    if (head == NULL) {
        printf("\nMemory allocation failed!\n");
        return NULL;
    }
    head->data = x;
    head->next = NULL;
    p = head;

    for (i = 2; i <= n; i++) {
        printf("\nEnter data: ");
        scanf("%d", &x);

        temp = (node*)malloc(sizeof(node));
        if (temp == NULL) {
            printf("\nMemory allocation failed!\n");
            return head; // Return the partially created list
        }
        temp->data = x;
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }

    printf("\nLinked list created successfully:\n");
    return head;
}

void print(node *p) {
    if (p == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    printf("\nSLL Nodes:\n");
    while(p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void count(node *p) {
    int count = 0;
    while(p != NULL) {
        count++;
        p = p->next;
    }
    printf("\nNumber of Nodes: %d\n", count);
}

void search(node *p) {
    int key, flag = 0;
    printf("\nEnter key element to be searched: ");
    scanf("%d", &key);
    while(p != NULL) {
        if (key == p->data) {
            flag = 1;
            break;
        }
        p = p->next;
    }
    if (flag)
        printf("\nElement is found!!!\n");
    else
        printf("\nElement is not found!!!\n");
}

node* insert_at_Begin(node *head) {
    node *q;
    int x;
    printf("\nEnter data: ");
    scanf("%d", &x);

    q = (node*)malloc(sizeof(node));
    if (q == NULL) {
        printf("\nMemory allocation failed!\n");
        return head;
    }
    q->data = x;
    q->next = head;
    head = q;

    printf("\nNode inserted at Begin successfully!!!\n");
    return head;
}

node* insert_at_End(node *head) {
    node *q, *p;
    int x;
    printf("\nEnter data: ");
    scanf("%d", &x);

    q = (node*)malloc(sizeof(node));
    if (q == NULL) {
        printf("\nMemory allocation failed!\n");
        return head;
    }
    q->data = x;
    q->next = NULL;

    if (head == NULL) {
        head = q;
    } else {
        p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = q;
    }

    printf("\nNode inserted at end successfully!!!\n");
    return head;
}

node* insert_at_Middle(node *head) {
    node *q, *p;
    int x, loc, i;

    if (head == NULL) {
        printf("\nLinked list is empty!!! You cannot insert a node in the middle!!!\n");
        return NULL;
    }

    printf("\nEnter data: ");
    scanf("%d", &x);

    q = (node*)malloc(sizeof(node));
    if (q == NULL) {
        printf("\nMemory allocation failed!\n");
        return head;
    }
    q->data = x;
    q->next = NULL;

    printf("\nEnter location for insertion: ");
    scanf("%d", &loc);

    if (loc <= 0) {
        printf("\nInvalid location!\n");
        free(q);
        return head;
    }

    p = head;
    for (i = 1; i < loc - 1; i++) {
        if (p == NULL) {
            printf("\nLocation out of bounds!\n");
            free(q);
            return head;
        }
        p = p->next;
    }

    q->next = p->next;
    p->next = q;

    printf("\nNode inserted at middle successfully!!!\n");
    return head;
}

node* delete_at_Begin(node *head) {
    node *q;

    if (head == NULL) {
        printf("\nLinked list is empty!!! You cannot delete a node!!!\n");
        return NULL;
    }

    q = head;
    head = head->next;
    free(q);

    printf("\nNode deleted from Begin successfully!!!\n");
    return head;
}

node* delete_at_End(node *head) {
    node *q, *p;

    if (head == NULL) {
        printf("\nLinked list is empty!!! You cannot delete a node!!!\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    p = head;
    while(p->next->next != NULL) {
        p = p->next;
    }

    q = p->next;
    p->next = NULL;
    free(q);

    printf("\nNode deleted from End successfully!!!\n");
    return head;
}

node* delete_at_Middle(node *head) {
    node *q, *p;
    int loc, i;

    if (head == NULL) {
        printf("\nLinked list is empty!!! You cannot delete a node!!!\n");
        return NULL;
    }

    printf("\nEnter location of node for deletion: ");
    scanf("%d", &loc);

    if (loc <= 0) {
        printf("\nInvalid location!\n");
        return head;
    }

    if (loc == 1) {
        return delete_at_Begin(head);
    }

    p = head;
    for (i = 1; i < loc - 1; i++) {
        if (p == NULL || p->next == NULL) {
            printf("\nLocation out of bounds!\n");
            return head;
        }
        p = p->next;
    }

    q = p->next;
    if (q == NULL) {
        printf("\nLocation out of bounds!\n");
        return head;
    }
    p->next = q->next;
     free(q);
     printf("\n node delete succesfully !!!");
     return(head);
 }
 
