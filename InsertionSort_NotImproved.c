#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int i, key, j;
    
    // Percorre o array a partir do segundo elemento (índice 1)
    for (i = 1; i < n; i++) {
        key = arr[i];  // Elemento atual a ser inserido na posição correta
        j = i - 1;     // Índice do elemento anterior
        
        // Move os elementos do arr[0..i-1] que são maiores que key
        // uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // Insere o elemento na posição correta
        arr[j + 1] = key;
    }
}

// Exemplo de uso
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    printf("Array original: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    insertion_sort(arr, n);
    
    printf("Array ordenado: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
