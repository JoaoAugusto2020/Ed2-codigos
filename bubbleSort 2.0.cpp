#include<iostream>
#include<stdio.h>
#include<stdlib.h>
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

void imprimirVetor(int v[], int n){
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

//[Inicial]
//melhor caso (já está ordenado): cTime  = O(n²)
//caso médio (estástiticamente, 50/50): cTime = O(n²)
//pior caso (está ordenado inversamente): cTime == O(n²)

//[Com checagem de houveTroca]
//melhor caso (já está ordenado): complexTime = O(n) [constante]

//[Com (n-1) - i]
//melhor caso (já está ordenado): complexTime = O(n) [constante]

//complexidade de espaço: O(1) [constante]
//complexidade de tempo: O(n²) [exponencial]
void bubbleSortOtimizado(int v[], int n){
    for(int i=0; i < n-1; i++){
    	bool houveTroca = false;
        for(int j=0; j < (n-1) - i; j++){
            if(v[j] > v[j+1]){
                troca(v, j, j+1);
                houveTroca = true;
            }
        }
        if(!houveTroca) return;
    }
}

int main(){
    srand(time(NULL));
    int n = 100;
    int v[n];

    geraVetor(v, n);
    imprimirVetor(v, n);
    bubbleSortOtimizado(v, n);
    imprimirVetor(v, n);

    return 0;
}
