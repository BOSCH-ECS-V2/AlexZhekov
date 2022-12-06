#include<stdio.h>
#include <stdlib.h>
#include "flipFuncs.h"

// Dynamically assigned array initialization function
void enterArray(int** array, size_t n, size_t m) {
    for(size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < m; ++j) {
            printf("Enter value for array[%zu][%zu]:", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}

// Dynamically assigned array printing function
void printArray(int** array, size_t n, size_t m) {
    printf("Two Dimensional array elements:\n");
    for(size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < m; ++j) {
            printf("%d ", array[i][j]);
            if(j==2){
                printf("\n");
            }
        }
    }
}

/* Menu function to simplify
   the application of operations 
   to a dynamically allocated array */
void menu(int** array, size_t n, size_t m) {
    int choice = 1;

    printf("1. Diagonal flip\n");
    printf("2. Row flip\n");
    printf("3. Column flip\n");
    printf("4. Center row flip\n");
    printf("5. Center column flip\n");
    printf("6. Print matrix\n");
    printf("0. Exit\n");

    while(choice > 0) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: diagFlip(array, n, m); break;
            case 2: rowFlip(array, n, m); break;
            case 3: colFlip(array, n, m); break;
            case 4: centerRowFlip(array, n, m); break;
            case 5: centerColFlip(array, n, m); break;
            case 6: printArray(array, n, m); break;
            case 0: break;
            default: continue;
        }
    }
}

int main() {
    int** array = 0;
    size_t n = 0;
    size_t m = 0;

    printf("Enter size of array:\n");
    printf("n = ");
    scanf("%zu", &n);
    printf("m = ");
    scanf("%zu", &m);

    array = (int**)malloc(sizeof(int*) * n);
    for(size_t i = 0; i < n; ++i)
        array[i] = (int*)malloc(sizeof(int) * m);

    // Initializing array and passing it to menu func
    enterArray(array, n, m);
    menu(array, n, m);

    // Deallocating heap memory
    for(size_t i = 0; i < n; ++i) {
        free(array[i]);
    }
    free(array);
    return 0;
}