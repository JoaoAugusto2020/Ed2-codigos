#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void troca(int v[], int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void imprimirVetor(int v[], int n){
    for(int i=0; i<n; i++){
        cout<<v[i]<<endl;
    }
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

//complexidade de espaço: O(1) (constante)
//complexidade de tempo: O(n²) (exponencial)
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

//complexidade de espaço: O(1) (constante)
//complexidade de tempo: O(n²) (exponencial)
void selectionSort(int v[], int n){
	for(int i=0; i < n-1; i++){
		for(int j=i+1; j < n; j++){
			if(v[i] > v[j]){
				troca(v, i, j);
			}
		}
	}
}

//complexidade de espaço: O(1) (constante)
//complexidade de tempo: O(n²) (exponencial)
void insertionSort(int v[], int n){
	for(int i=1; i < n; i++){
		int aux = v[i];
		int j = i-1;

		while(j>=0 && aux<v[j]){
			v[j + 1] = v[j];
			j--;
		}

		v[j+1] = aux;
	}
}

int main(){
    int v[3], o[3];

    for(int i=0; i<3; i++){
    	cin>>v[i];
    	o[i] = v[i];
	}

    bubbleSortOtimizado(v, 3);
    imprimirVetor(v, 3);
    cout<<endl;
    imprimirVetor(o, 3);

    return 0;
}
