#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void troca(int v[], int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

//complexidade de espaço: O(1) (constante)
//complexidade de tempo: O(n²) (exponencial)
int bubbleSort(int v[], int n){
	int trocas=0;

    for(int i=0; i < n-1; i++){
        for(int j=0; j < n-1; j++){
            if(v[j] > v[j+1]){
                troca(v, j, j+1);
                trocas++;
            }
        }
    }
    return trocas;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		int l;
		cin>>l;

		int v[l];
		for(int i=0; i<l; i++){
			cin>>v[i];
		}

		cout<<"Optimal train swapping takes "<<bubbleSort(v, l)<<" swaps."<<endl;
	}

    return 0;
}
