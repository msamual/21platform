#include <stdio.h>
#include <stdlib.h>

void output(int *a, int n);
int input(int **a);
void swap(int *a, int *b);
void sort(int *a, int size);
int puterror();

int main() {
    int *arr;
    int size = 0;
    if ((size = input(&arr)) < 1) {
        return puterror();
    }
    sort(arr, size);
    output(arr, size);
    free(arr);
}

int puterror() {
    printf("n/a\n");
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) printf(" ");
    }
    printf("\n");
}

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            swap(arr + j, arr + j - 1);
        }
    }
}

int input(int **a) {
    int size;
    if(scanf("%d", &size) != 1)
    {
        size = 0;
    }
    else
    {
        *a = (int *)malloc(size * sizeof(int));
        for (int *p = *a; p - *a < size; p++) {
            if (scanf("%d", p) != 1)
            {
                size = 0;
                break;
            } 
        }
    }
    return size;
}
