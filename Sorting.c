#include <stdio.h>
#include <stdbool.h>

void printArr(int *arr, int n, int pass) {
    printf("Pass %d: ", pass);
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    int pass = 1;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printArr(arr, n, pass++);
    }
}

void insertionSort(int arr[], int n){
    for(int i=1; i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j<=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    }

void insertionSortptr(int arr[], int n) {
    int pass = 1;
    for (int i = 1; i < n; i++) {
        int key = *(arr + i);
        int j = i - 1;
        while (j >= 0 && *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
        printArr(arr, n, pass++);
    }
}

void selectionSort(int arr[], int n) {
    int pass = 1;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        printArr(arr, n, pass++);
    }
}


void selectionSortptr(int arr[], int n) {
    int pass = 1;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (*(arr + j) < *(arr + min))
                min = j;
        if (min != i) {
            int temp = *(arr + i);
            *(arr + i) = *(arr + min);
            *(arr + min) = temp;
        }
        printArr(arr, n, pass++);
    }
}



void bubbleSort(int arr[], int n) {
    bool swapped;
    int pass = 1;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        printArr(arr, n, pass++);
    } while (swapped);
}


void bubbleSortptr(int *arr, int n) {
    bool swapped;
    int pass = 1;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (*(arr + i) > *(arr + i + 1)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;
                swapped = true;
            }
        }
        printArr(arr, n, pass++);
    } while (swapped);
}

void insertionSOrt(int arr[],int n){

}

int main() {
    int n, ch;
    printf("Sorting Algorithms Implementation\n");
    char chh;
    do {
        printf("\nChoose sorting algorithm:\n");
        printf("1. Bubble Sort\n2. Bubble Sort (pointers)\n");
        printf("3. Selection Sort\n4. Selection Sort (pointers)\n");
        printf("5. Insertion Sort\n6. Insertion Sort (pointers)\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        printf("Enter number of elements: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter elements:\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        switch (ch) {
            case 1: bubbleSort(arr, n); break;
            case 2: bubbleSortptr(arr, n); break;
            case 3: selectionSort(arr, n); break;
            case 4: selectionSortptr(arr, n); break;
            case 5: insertionSort(arr, n); break;
            case 6: insertionSortptr(arr, n); break;
            default: printf("Invalid choice\n"); break;
        }

        printf("Continue? (Y/N): ");
        scanf(" %c", &chh);
    } while (chh == 'Y' || chh == 'y');

    return 0;
}
