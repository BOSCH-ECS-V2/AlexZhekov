#ifndef __FLIP_FUNCS
#define __FLIP_FUNCS
 
void swap(int* valA, int* valB) {
    *valA += *valB;
    *valB = *valA - *valB;
    *valA -= *valB;
}

void diagFlip(int** array, size_t n, size_t m) {
    if(n == m) {
        for(size_t i = 0; i < n; ++i)
            for(size_t j = 0; j < m; ++j)
                if(i < j)
                    swap(&array[i][j], &array[j][i]);
    }
    else {
        printf("Cannot diagonally flip non square matrix!\n");
    }
}

void rowFlip(int** array, size_t n, size_t m) {
    for(size_t i = 0; i < m; ++i) {
        for(size_t j = 0; j < n/2; ++j) {
            swap(&array[i][j], &array[i][n-j-1]);
        }
    }
}

void colFlip(int** array, size_t n, size_t m) {
    for(size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < m/2; ++j) {
            swap(&array[j][i], &array[m-j-1][i]);
        }
    }
}

void centerRowFlip(int** array, int n, int m) {
    if(n % 2) {
        colFlip(array, n, m);
    }
    else {
        printf("A matrix with an even number of rows cannot be center flipped!\n");
    }
}

void centerColFlip(int** array, int n, int m) {
    if(m % 2) {
        rowFlip(array, n, m);
    }
}   else {
        printf("A matrix with an even number of columns cannot be center flipped!\n");
    }

#endif