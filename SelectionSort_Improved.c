#include <stdio.h>

void selection_sort(int* arr, int len) {
    int min_idx, comp = 0, troca = 0;
    int already_sorted = 1;
    
    for (int i = 0; i < len - 1; i++) {
        // Verificar se o array já está ordenado
        already_sorted = 1;
        for (int j = i; j < len - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                already_sorted = 0;
                break;
            }
        }
        
        if (already_sorted) {
            break;
        }
        
        // Continua com o selection sort normal
        min_idx = i;
        for (int j = i + 1; j < len; j++) {
            comp++;
            if (arr[j] < arr[min_idx]) 
                min_idx = j;
        }
        
        if (min_idx != i) {
            troca++;
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
    
    printf("Comparações: %d, Trocas: %d\n", comp, troca);
}

// Exemplo de uso
int main() {
    int array[] = {64, 25, 12, 22, 11};
    int len = sizeof(array) / sizeof(array[0]);
    
    printf("Array original: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    selection_sort(array, len);
    
    printf("Array ordenado: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Teste com array já ordenado
    printf("\nTestando com array já ordenado:\n");
    int sorted_array[] = {10, 20, 30, 40, 50};
    int sorted_len = sizeof(sorted_array) / sizeof(sorted_array[0]);
    
    printf("Array original: ");
    for (int i = 0; i < sorted_len; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");
    
    selection_sort(sorted_array, sorted_len);
    
    return 0;
}
