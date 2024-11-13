#include<iostream>
#include<bits/stdc++.h>
#include<string.h>

#define LIMITE 500

using namespace std;

void troca(char nomes[LIMITE][100], int a, int b){
    char aux[100];
	strcpy(aux, nomes[a]);
	strcpy(nomes[a], nomes[b]);
	strcpy(nomes[b], aux);
}

//complexidade de espa?o: O(1) (constante)
//complexidade de tempo: O(n?) (exponencial)
void bubbleSortOtimizado(char nomes[LIMITE][100], int n){
    for(int i=0; i < n-1; i++){
    	bool houveTroca = false;
    	
        for(int j=0; j < (n-1) - i; j++){
			if(strcmp(nomes[j],nomes[j+1])>0){
                troca(nomes, j, j+1);
                houveTroca = true;
            }
        }
        
        if(houveTroca==false) return;
    }
}

//complexidade de espa?o: O(1) (constante)
//complexidade de tempo: O(n?) (exponencial)
void selectionSort(char nomes[LIMITE][100], int n){
	for(int i=0; i < n-1; i++){
		for(int j=i+1; j < n; j++){
			if(strcmp(nomes[i],nomes[j])>0){
				troca(nomes, i, j);
			}
		}
	}
}

////complexidade de espa?o: O(1) (constante)
////complexidade de tempo: O(n?) (exponencial)
void insertionSort(char nomes[LIMITE][100], int n){
	for(int i=1; i<n; i++){
		char aux[100];
		strcpy(aux, nomes[i]);
		int j = i-1;
		
		while(j>=0 && strcmp(aux, nomes[j])<0){
			strcpy(nomes[j+1], nomes[j]);
			j--;
		}
		
		strcpy(nomes[j+1], aux);
	}
}

// Complexidade de tempo e espa?o = O(n)
void merge(char nomes[LIMITE][100], int ini, int meio, int fim) {
    char tmp[(fim-ini) + 1][100];
    int i=ini;
	int j=meio + 1;
	int k=0;
    
    //meio e fim s?o os limites dos vetores divididos
    while (i<=meio && j<=fim) {
        if(strcmp(nomes[i], nomes[j])<0){
			strcpy(tmp[k], nomes[i]);
        	i++;
		}else{
			strcpy(tmp[k], nomes[j]);
			j++;
		}
		k++;
    }
    
    //restos
    while (i<=meio) {
        strcpy(tmp[k++], nomes[i++]);
    }
    while (j<=fim) {
        strcpy(tmp[k++], nomes[j++]);
    }
    
    //transferindo pra original
    for (i=ini, k=0; i<=fim; i++, k++) {
        strcpy(nomes[i], tmp[k]);
    }
}

//complexidade de espa?o: O(n) (linear)
//complexidade de tempo: O(n log n)
void mergeSort(char nomes[LIMITE][100], int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        //printf("%d %d %d\n", ini, meio, fim);
        mergeSort(nomes, ini, meio);
        mergeSort(nomes, meio + 1, fim);
        merge(nomes, ini, meio, fim);
    }
}

// comp. tempo O(log n)
// comp. espaco O(1)
bool buscaBinaria(char v[LIMITE][100], int n, char x[]) {
    int ini=0, fim=n-1;
    
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
//        cout<<"meio = "<<v[meio]<<endl;
//        cout<<"busc = "<<x<<endl;
        if (strcmp(v[meio], x) == 0) {
            return true;
        } else if (strcmp(v[meio], x)==1) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return false;
}


int main(){
	int n=0, m=0, cont=0;
    char dicionario[500][100];
    char palavras[50][100];
	
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>dicionario[i];
	}
	
	cin>>m;
	for(int i=0; i<m; i++){
		cin>>palavras[i];
	}
	
	mergeSort(dicionario, 0, n-1);
//	for(int i=0; i<n; i++){
//		cout<<"Linha "<<i<<": "<<dicionario[i]<<endl;
//	}
	
	for(int i=0; i<m; i++){
		if(buscaBinaria(dicionario, n, palavras[i]) == true){
			cont++;
		}
	}
	
	cout<<cont<<endl;
	
    
	return 0;
}

