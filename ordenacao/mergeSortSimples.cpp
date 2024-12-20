#include<iostream>
#include<stdio.h>

// Complexidade de tempo e espa?o = O(n)
void merge(int v[], int ini, int meio, int fim) {
    int tmp[(fim-ini) + 1];
    int i=ini;
	int j=meio + 1;
	int k=0;
    
    //meio e fim s?o os limites dos vetores divididos
    while (i<=meio && j<=fim) {
        tmp[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
        
        //OU
		/*
        if(v[i] < v[j]){
        	temp[k] = v[i];
        	i++;
		}else{
			tmp[k] = v[j];
			j++;
		}
		k++;*/
    }
    
    //restos
    while (i<=meio) {
        tmp[k++] = v[i++];
    }
    while (j<=fim) {
        tmp[k++] = v[j++];
    }
    
    //transferindo pra original
    for (i=ini, k=0; i<=fim; i++, k++) {
        v[i] = tmp[k];
    }
}

// Complexidade de tempo O(n log n) e espa?o O(n)
void mergeSortSimples(int v[], int ini, int fim) {
    if (ini < fim) {
        int meio = (ini+fim) / 2;
        
        //printf("%d %d %d\n", s, m, e);
        mergeSortSimples(v, ini, meio);
        mergeSortSimples(v, meio+1, fim);
        
        merge(v, ini, meio, fim);
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
	mergeSortSimples(v, 0, 9);
	imprimirVetor(v, 10);
}
