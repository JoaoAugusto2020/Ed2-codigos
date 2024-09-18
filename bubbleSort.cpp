#include<stdio.h>
#include<iostream>
#include<time.h>

using namespace std;

void geraVetor(int v[], int n){
    for(int i=0; i<n; i++){
        v[i] = rand() % n;
    }
}

void troca(int v[], int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

//complexidade de espaço: O(1) (constante)
//complexidade de tempo: O(n²) (exponencial)
void bubbleSort(int v[], int n){
    for(int i=0; i < n-1; i++){
        for(int j=0; j < n-1; j++){
            if(v[j] > v[j+1]){
                troca(v, j, j+1);
            }
        }
    }
}

void imprimirVetor(int v[], int n){
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    srand(time(NULL));
    int n = 100;
    int v[n];

    geraVetor(v, n);
    imprimirVetor(v, n);
    bubbleSort(v, n);
    imprimirVetor(v, n);

    return 0;
}
