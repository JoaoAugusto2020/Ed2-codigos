#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void geraVetor(int v[], int n){
    for(int i=0; i<n; i++){
        v[i] = rand() % n;
    }
}

void imprimirVetor(int v[], int n){
    for(int i=0; i<n; i++){
        if(v[i]!=-1) printf("%d\n", v[i]);
    }
}

void imprimirVetorR(int v[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if(v[i]!=-1) printf("%d\n", v[i]);
    }
}

void imprimirVetorPares(int v[], int n){
    for(int i=0; i<n; i++){
        if(v[i]%2==0) cout<<v[i]<<endl;
    }
}

void imprimirVetorImpares(int v[], int n){
    for(int i=n-1; i>=0; i--){
        if(v[i]%2!=0) cout<<v[i]<<endl;
    }
}

void troca(int v[], int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

//complexidade de espaço: O(1) (constante)
//complexidade de tempo: O(n²) (exponencial)
int bubbleSort(int v[], int n) {
    int trocas = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
                trocas++;
            }
        }
    }
    return trocas;
}
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

// Complexidade de tempo e espaço = O(n)
void merge(int v[], int ini, int meio, int fim) {
    int tmp[(fim-ini) + 1];
    int i=ini;
	int j=meio + 1;
	int k=0;

    //meio e fim são os limites dos vetores divididos
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

//complexidade de espaço: O(n) (linear)
//complexidade de tempo: O(n log n)
void mergeSort(int v[], int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        //printf("%d %d %d\n", ini, meio, fim);
        mergeSort(v, ini, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, ini, meio, fim);
    }
}

int main(){
	int n;
    while(scanf("%d",&n) != EOF){
        int largada[n], chegada[n], p1[n + 1], p2[n + 1];

        for(int i=0; i<n; i++) {
            cin>>largada[i];
            p1[largada[i]] = i;
        }

        for(int i=0; i<n; i++) {
            cin>>chegada[i];
            p2[i + 1] = p1[chegada[i]];
        }

        cout<<bubbleSort(p2, n + 1)<<endl;
    }
    return 0;
}
