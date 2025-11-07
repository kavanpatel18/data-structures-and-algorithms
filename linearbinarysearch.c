#include <stdio.h>

// Function for Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Element found
        }
    }
    return -1; // Element not found
}

// Function for Binary Search (Requires sorted array)
int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Element found
        } else if (arr[mid] < key) {
            low = mid + 1; // Search right half
        } else {
            high = mid - 1; // Search left half
        }
    }
    return -1; // Element not found
}

int main() {
    int n, i, index, key, ch;

    // Input size of the array
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements for the array: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the number to search
    printf("Enter number to search: ");
    scanf("%d", &key);

    // Menu for search method
    printf("\nEnter your choice:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Only if the elements are sorted)\n");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            index = linearSearch(arr, n, key);
            if (index == -1) {
                printf("The number does not exist in the array.\n");
            } else {
                printf("The number is at index %d of the array.\n", index);
            }
            break;

        case 2:
            index = binarySearch(arr, n, key);
            if (index == -1) {
                printf("The number does not exist in the array.\n");
            } else {
                printf("The number is at index %d of the array.\n", index);
            }
            break;

        default:
            printf("Invalid choice. Please select 1 or 2.\n");
    }

    return 0;
}
