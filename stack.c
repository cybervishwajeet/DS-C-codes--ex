#include <stdio.h>
#define MAX 10

int data[MAX], top;

void initialize();
int empty();
int full();
void push();
void pop();
void print();

int main() {
    int ch;
    initialize();
    do {
        printf("\n ***STACK OPERATIONS");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. Print");
        printf("\n 4. EXIT");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if (full() == 0) {
                    push();
                } else {
                    printf("\nStack is Full!!!");
                }
                break;
            case 2:
                if (empty() == 0) {
                    pop();
                } else {
                    printf("\nStack is Empty!!!");
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

    return 0;
}

void initialize() {
    top = -1;
}

int full() {
    return (top == MAX - 1);
}

int empty() {
    return (top == -1);
}

void push() {
    int x;
    printf("Enter data to be inserted: ");
    scanf("%d", &x);
    top = top + 1;
    data[top] = x;
}

void pop() {
    int x;
    x = data[top];
    top = top - 1;
    printf("\nData popped = %d", x);
}

void print() {
    int i;
    if (empty()) {
        printf("\nStack is Empty!!!");
    } else {
        printf("\nStack data: ");
        for (i = top; i >= 0; i--) {
            printf("%d\t", data[i]);
        }
        printf("\n"); // Added newline for better formatting
    }
}

