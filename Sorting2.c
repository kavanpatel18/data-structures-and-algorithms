#include <stdio.h>

// Swap function to interchange two elements using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Global variable used to print pivot only once during quick sort
int cp = 0;

// ======================= QUICK SORT (MID PIVOT) ========================= //
// Partition function where pivot is chosen as the middle element
int partition_mid(int arr[], int low, int high) {
    int pivot = arr[(low + high) / 2];  // Middle element as pivot

    // Print pivot only for the first partition
    if (cp == 0) {
        printf("Pivot element = %d\n", pivot);
        cp++;
    }

    int i = low;
    int j = high;

    // Hoare partition scheme
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    return i;  // Return partition index
}

// Recursive quicksort function using middle pivot
void quickSort_mid(int arr[], int low, int high) {
    if (low < high) {
        int p = partition_mid(arr, low, high);
        quickSort_mid(arr, low, p - 1);
        quickSort_mid(arr, p, high);
    }
}

// ======================= QUICK SORT (END PIVOT) ========================= //
// Partition function where pivot is chosen as the last element
int partition_end(int arr[], int low, int high) {
    int pivot = arr[high];  // Last element as pivot

    // Print pivot only once
    if (cp == 0) {
        printf("Pivot element = %d\n", pivot);
        cp++;
    }

    int i = low - 1;

    // Lomuto partition scheme
    for (int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

// Recursive quicksort function using last element as pivot
void quickSort_end(int arr[], int low, int high) {
    if (low < high) {
        int p = partition_end(arr, low, high);
        quickSort_end(arr, low, p - 1);
        quickSort_end(arr, p + 1, high);
    }
}

// ======================= QUICK SORT (START PIVOT) ======================= //
// Partition function where pivot is chosen as the first element
int partition_start(int arr[], int low, int high) {
    int pivot = arr[low];  // First element as pivot

    // Print pivot only once
    if (cp == 0) {
        printf("Pivot element = %d\n", pivot);
        cp++;
    }

    int i = high + 1;

    // Partition loop (reverse direction)
    for (int j = high; j > low; j--) {
        if (arr[j] > pivot) {
            i--;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[i - 1]);  // Place pivot in correct position
    return i - 1;
}

// Recursive quicksort function using first element as pivot
void quickSort_start(int arr[], int low, int high) {
    if (low < high) {
        int p = partition_start(arr, low, high);
        quickSort_start(arr, low, p - 1);
        quickSort_start(arr, p + 1, high);
    }
}

// ============================ MERGE SORT ================================= //
// Helper function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int i ,j,k;
    int n1 = mid-left+1;
    int n2= right-mid;
    int L[n1],R[n2];
    
    for(i=0;i<n1;i++) L[i]=arr[left+i];
    for(i=0;i<n2;i++) R[j]=arr[mid+1+j];

    int i=0, j=0, k=left;
    while(i<n1 && j<n2){
        if (L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        } else {
            arr[k]=R[j];
        }
        k++;
        
    }

    while (i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while (j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}


void merge(int arr[], int right, int left, int mid){
    int i, j ,k;
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1], R[n2];

    for(i=0;i<n1;i++) L[i]=arr[left+i];
    for(j=0;j<n2;j++) R[j]=arr[mid+1+j];

    i=0, j=0, k=left;
    while (i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i]; i++;
        }
        else{
            arr[k]=R[j]; j++;
        }
        k++
    }

    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right){
    if (left<right){
        int mid = left+(right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
// Recursive Merge Sort function
void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort both halves
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        // Merge the two halves
        merge(arr, left, mid, right);
    }
}

// ============================ UTILITY FUNCTION =========================== //
// Prints the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}

// ================================ MAIN ================================== //
int main() {
    int n, choice, sort;
    char chh;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    do {
        int arr[n];  // Declare array of size n
        printf("Enter elements:\n");
        for (int i = 0; i < n; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr[i]);
        }

        // Ask user which sorting method to use
        printf("Enter sorting method:\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("Enter choice: ");
        scanf("%d", &sort);

        switch (sort) {
            case 1:
                // Call merge sort
                mergesort(arr, 0, n - 1);
                break;

            case 2:
                cp = 0;  // Reset pivot print counter
                printf("\nChoose pivot:\n");
                printf("1. Pivot = Middle element\n");
                printf("2. Pivot = Last element\n");
                printf("3. Pivot = First element\n");
                printf("Enter choice: ");
                scanf("%d", &choice);

                // Print original array before sorting
                printf("Original array: ");
                printArray(arr, n);

                // Choose pivot strategy
                switch (choice) {
                    case 1:
                        quickSort_mid(arr, 0, n - 1);
                        break;
                    case 2:
                        quickSort_end(arr, 0, n - 1);
                        break;
                    case 3:
                        quickSort_start(arr, 0, n - 1);
                        break;
                    default:
                        printf("Invalid choice!\n");
                        return 1;
                }
                break;

            default:
                printf("Invalid sorting method!\n");
                return 1;
        }

        // Display sorted array
        printf("Sorted array: ");
        printArray(arr, n);

        // Ask if user wants to continue
        printf("Continue? (Y/N): ");
        scanf(" %c", &chh);

    } while (chh == 'Y' || chh == 'y');

    return 0;
}
