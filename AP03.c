#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Merge Sort implementation in C  
This code includes the merge function and the merge_sort function
The merge function merges two halves of an array
The merge_sort function recursively divides the array into halves and sorts them */

void merge(int array[], int left, int middle, int right) {
    int left_size = middle - left + 1;
    int right_size = right - middle; 

    // Create temp arrays with space for sentinels
    int* left_array = (int*)malloc((left_size + 1) * sizeof(int));
    int* right_array = (int*)malloc((right_size + 1) * sizeof(int));

    // Copy data to temp arrays left_array[] and right_array[]
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

/* Quick Sort implementation in C
This code includes the partition function, the quick_sort function, and the swap function
The partition function selects a pivot and places elements smaller than the pivot to its left
The quick_sort function recursively divides the array and sorts them */

int partition(int array[], int left, int right) {
    int pivot, tam;

    tam = right - left + 1; // Calculate the size of the array
    
    // Calculate the pivot manually 
    if (tam >= 3) {
        int temp, a, b, c;
        
        a = array[left];
        b = array[left + 1];
        c = array[left + 2];
    
        if (a > b) { temp = a; a = b; b = temp; }
        if (a > c) { temp = a; a = c; c = temp; }
        if (b > c) { temp = b; b = c; c = temp; }
    
        pivot = b; // Mediana dos três
    } else {
        pivot = array[right]; // fallback
    }

    int i = left - 1;  

    for (int j = left; j < right; j++) {
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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    
    
    return 0;
}
