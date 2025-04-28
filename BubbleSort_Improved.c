#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, comp = 0, troca = 0;
    int swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // flag para otimização
        
        // A cada passagem, os últimos i elementos já estão ordenados
        for (j = 0; j < n - i - 1; j++) {
            // Compara elementos adjacentes
            if (arr[j] > arr[j + 1]) {
                // Troca se estiverem na ordem errada
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                comp++;
                troca++;
                swapped = 1;
            }
        }
        
        // Se não houve trocas nessa passagem, o array já está ordenado
        if (swapped == 0)
            break;
    }
}

// Exemplo de uso
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    printf("Array original: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    bubble_sort(arr, n);
    
    printf("Array ordenado: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
