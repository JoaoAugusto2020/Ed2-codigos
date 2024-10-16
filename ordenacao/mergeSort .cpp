#include<iostream>
#include<stdio.h>

// Complexidade de tempo e espaço = O(n)
void merge(int v[], int s, int m, int e) {
    int tmp[(e - s) + 1];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        tmp[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
    }
    while (i <= m) {
        tmp[k++] = v[i++];
    }
    while (j <= e) {
        tmp[k++] = v[j++];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        v[i] = tmp[k];
    }
}

// Complexidade de tempo O(n log n) e espaço O(n)
void mergeSort(int v[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        //printf("%d %d %d\n", s, m, e);
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
    }
}

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}

void imprimirVetorC(int v[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", v[i]);
    }
}

int main(){
	int v[] = {10, 1, 5, 2, 4, 7, 5, 8, 3, 9};
	mergeSort(v, 0, 9);
	imprimirVetor(v, 10);
	
}
