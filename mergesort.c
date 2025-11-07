#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int cp = 0;

int partition_mid(int arr[], int low, int high) {
    int pivot = arr[(low + high) / 2];
    if (cp == 0) {
        printf("Pivot element (middle)= %d\n", pivot);
        cp++;
    }
    int i = low;
    int j = high;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

int partition_end(int arr[], int low, int high) {
    int pivot = arr[high];
    if (cp == 0) {
        printf("Pivot element (last)= %d\n", pivot);
        cp++;
    }
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int partition_start(int arr[], int low, int high) {
    int pivot = arr[low];
    if (cp == 0) {
        printf("Pivot element (first) = %d\n", pivot);
        cp++;
    }
    int i = high + 1;

    for (int j = high; j > low; j--) {
        if (arr[j] > pivot) {
            i--;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[i - 1]);
    return i - 1;
}

void quickSort_mid(int arr[], int low, int high) {
    if (low < high) {
        int p = partition_mid(arr, low, high);
        quickSort_mid(arr, low, p - 1);
        quickSort_mid(arr, p, high);
    }
}

void quickSort_end(int arr[], int low, int high) {
    if (low < high) {
        int p = partition_end(arr, low, high);
        quickSort_end(arr, low, p - 1);
        quickSort_end(arr, p + 1, high);
    }
}

void quickSort_start(int arr[], int low, int high) {
    if (low < high) {
        int p = partition_start(arr, low, high);
        quickSort_start(arr, low, p - 1);
        quickSort_start(arr, p + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int choice, sort;
    char chh;
    int arr[100]; 
    int n = 0;  
    int size;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    do {
        n = 0; 
        printf("Enter elements: (Type a letter to stop)\n");

        while (1) {
            if (scanf("%d", &arr[n]) != 1) {
                while (getchar() != '\n');
                break; 
            }
            n++;
        }

        printf("Enter sorting method:\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("Enter choice: ");
        scanf("%d", &sort);

        switch (sort) {
            case 1:
                mergesort(arr, 0, n - 1);
                break;

            case 2:
                cp = 0;
                printf("\nChoose pivot:\n");
                printf("1. Pivot = Middle element\n");
                printf("2. Pivot = Last element\n");
                printf("3. Pivot = First element\n");
                printf("Enter choice: ");
                scanf("%d", &choice);

                printf("Original array: ");
                printArray(arr, n);

                switch (choice) {
                    case 1: quickSort_mid(arr, 0, n - 1); break;
                    case 2: quickSort_end(arr, 0, n - 1); break;
                    case 3: quickSort_start(arr, 0, n - 1); break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;

            default:
                printf("Invalid sorting method!\n");
                return 1;
        }

        printf("Sorted array: ");
        printArray(arr, n);

        printf("Continue? (Y/N): ");
        scanf(" %c", &chh);

    } while (chh == 'Y' || chh == 'y');

    return 0;
}
