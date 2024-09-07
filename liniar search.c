#include <stdio.h>
#include <conio.h> 

void main()
{
    int a[10], i, key, n, flag = 0;
    
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
    
    // Get the key element to be searched
    printf("\nEnter key element to be searched: ");
    scanf("%d", &key);
    
    // Search for the key in the array
    for (i = 0; i < n; i++) {
        if (key == a[i]) {
            flag = 1;
            break;
        }
    }
    
    // Print the result of the search
    if (flag == 1) {
        printf("\nElement is found.");
    } else {
        printf("\nElement is not found.");
    }
    
    getch(); // This is non-standard. Consider removing or replacing it with getchar() if needed.
}

