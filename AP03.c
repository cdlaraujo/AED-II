#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Global counters for comparisons
int merge_sort_comparisons = 0;
int quick_sort_comparisons = 0;
int quick_insertion_comparisons = 0;

/*Helper functions*/

// Swap function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to copy arrays
void copy_arrays(int array[], int copy[], int size) {
    for (int i = 0; i < size; i++) {
        copy[i] = array[i];
    }
}

/* Merge Sort implementation in C */
void merge(int array[], int left, int middle, int right) {
    int left_size = middle - left + 1;
    int right_size = right - middle; 

    // Create temp arrays with space for sentinels
    int* left_array = (int*)malloc((left_size + 1) * sizeof(int));
    int* right_array = (int*)malloc((right_size + 1) * sizeof(int));

    // Copy data to temp arrays
    for (int i = 0; i < left_size; i++)
        left_array[i] = array[left + i];
    for (int j = 0; j < right_size; j++)
        right_array[j] = array[middle + 1 + j];

    // Set sentinel values
    left_array[left_size] = INT_MAX;  
    right_array[right_size] = INT_MAX;  

    int left_index = 0; 
    int right_index = 0;  

    // The merging process
    for (int k = left; k <= right; k++) { 
        merge_sort_comparisons++; // Count comparison
        if (left_array[left_index] <= right_array[right_index]) {
            array[k] = left_array[left_index];  
            left_index++;
        } else {
            array[k] = right_array[right_index]; 
            right_index++;
        }
    }
    
    // Free the allocated memory
    free(left_array);
    free(right_array);
}

void merge_sort(int array[], int left, int right) {
    if (right > left) {
        int middle = left + (right - left) / 2;
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}

/* Quick Sort implementation in C */
int partition(int array[], int left, int right) {
    int pivot, tam;

    tam = right - left + 1; // Calculate the size of the array
    
    // Calculate the pivot manually 
    if (tam >= 2) {
        int temp, a, b, c;
        
        a = array[left];
        b = array[left + (right - left) / 2];
        c = array[right - 2];
    
        // Compare for median-of-three
        quick_sort_comparisons++; // a vs b
        if (a > b) { temp = a; a = b; b = temp; }
        quick_sort_comparisons++; // a vs c
        if (a > c) { temp = a; a = c; c = temp; }
        quick_sort_comparisons++; // b vs c
        if (b > c) { temp = b; b = c; c = temp; }

        pivot = b; // Median of three
        
        // Move the pivot to the rightmost position
        // Find where the pivot value is and swap it with array[right]
        if (array[left] == pivot) {
            swap(&array[left], &array[right]);
        } else if (array[left + (right - left) / 2] == pivot) {
            swap(&array[left + (right - left) / 2], &array[right]);
        } else {
            swap(&array[right], &array[right]);
        }
    } else {
        pivot = array[right]; // fallback
    }

    int i = left - 1;  

    for (int j = left; j < right; j++) { // The second condition is equal to < right
        quick_sort_comparisons++; // Count comparison
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[right]);
    return i + 1;
}

void quick_sort(int array[], int left, int right) {
    if (left < right) {
        int pivot_index = partition(array, left, right);

        quick_sort(array, left, pivot_index - 1);
        quick_sort(array, pivot_index + 1, right);
    }
}

/* Quick Sort with Insertion Sort */
void insertion_sort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        quick_insertion_comparisons++; // Count initial comparison
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
            if (j >= 0) { // Only count if we're going to compare again
                quick_insertion_comparisons++;
            }
        }
        
        array[j + 1] = key;
    }
}

void quick_sort_with_insertion(int array[], int left, int right) {
    if (right - left < 6) { // Threshold of 5 as in the original code
        insertion_sort(array + left, right - left + 1);
    } else {
        if (left < right) {
            // We use the same partition function as quick_sort
            int pivot_index = partition(array, left, right);
            // The comparisons in partition are already counted in quick_sort_comparisons
            // We need to manually move those counts to quick_insertion_comparisons
            quick_insertion_comparisons += quick_sort_comparisons;
            quick_sort_comparisons = 0;
            
            quick_sort_with_insertion(array, left, pivot_index - 1);
            quick_sort_with_insertion(array, pivot_index + 1, right);
        }
    }
}

// Function to print array
void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    // Read the number of elements
    scanf("%d", &n);
    
    // Allocate memory for arrays
    int* original_array = (int*)malloc(n * sizeof(int));
    int* working_array = (int*)malloc(n * sizeof(int));
    
    // Read the elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &original_array[i]);
    }
    
    // Reset all counters to ensure accurate counting
    merge_sort_comparisons = 0;
    quick_sort_comparisons = 0;
    quick_insertion_comparisons = 0;
    
    // Merge Sort
    copy_arrays(original_array, working_array, n);
    merge_sort(working_array, 0, n - 1);
    print_array(working_array, n);
    printf("%d\n", merge_sort_comparisons);
    
    // Quick Sort
    copy_arrays(original_array, working_array, n);
    quick_sort_comparisons = 0; // Reset counter
    quick_sort(working_array, 0, n - 1);
    print_array(working_array, n);
    printf("%d\n", quick_sort_comparisons);
    
    // Quick Sort with Insertion Sort
    copy_arrays(original_array, working_array, n);
    quick_insertion_comparisons = 0; // Reset counter
    quick_sort_comparisons = 0; // Reset this too as it's used in partition
    quick_sort_with_insertion(working_array, 0, n - 1);
    print_array(working_array, n);
    printf("%d\n", quick_insertion_comparisons);
    
    // Free allocated memory
    free(original_array);
    free(working_array);
    
    return 0;
}
