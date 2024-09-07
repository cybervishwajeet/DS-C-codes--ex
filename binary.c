#include <stdio.h>
#include <conio.h> 

void main()
{
    int a[10], i, j, n, mid, key, temp;
    
    clrscr(); // This is non-standard. Use system("cls") for Windows or a similar function for other OS.
    
    // Get the size of the array from the user
    printf("\nEnter size of array (up to 10): ");
    scanf("%d", &n);
    
    // Ensure the size does not exceed the array limit
    if (n > 10 || n <= 0) {
        printf("\nInvalid size. Please enter a number between 1 and 10.");
        return;
    }
    
    // Get the array elements from the user
    printf("\nEnter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Bubble sort to sort the array in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
    // Get the key element to be searched
    printf("\nEnter key element to be searched: ");
    scanf("%d", &key);
    
    // Binary search algorithm
    int left = 0;
    int right = n - 1;
    int found = 0;
    
    while (left <= right) {
        mid = (left + right) / 2;
        
        if (key == a[mid]) {
            found = 1;
            break;
        }
        else if (key > a[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    if (found) {
        printf("\nElement is found!!!");
    } else {
        printf("\nElement is not found!!!");
    }
    
    getch(); // This is non-standard. Consider removing or replacing it with getchar() if needed.
}

