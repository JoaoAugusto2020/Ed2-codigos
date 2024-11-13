#include<iostream>
#include<bits/stdc++.h>
#include<string.h>

#define LIMITE 1000

using namespace std;

void troca(char nomes[LIMITE][100], int a, int b){
    char aux[100];
	strcpy(aux, nomes[a]);
	strcpy(nomes[a], nomes[b]);
	strcpy(nomes[b], aux);
}

//complexidade de espa?o: O(1) (constante)
//complexidade de tempo: O(n?) (exponencial)
void bubbleSortOtimizado(char palavra[], int n){
    for(int i=0; i < n-1; i++){
    	bool houveTroca = false;
    	
        for(int j=0; j < (n-1) - i; j++){
			if(strcmp(&palavra[j], &palavra[j+1])>0){
                troca(palavra, j, j+1);
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
//void merge(char palavra[], int ini, int meio, int fim) {
//    char tmp[(fim-ini) + 1];
//    int i=ini;
//	int j=meio + 1;
//	int k=0;
//    
//    //meio e fim s?o os limites dos vetores divididos
//    while (i<=meio && j<=fim) {
//        if(strcmp(palavra[i], palavra[j])<0){
//			strcpy(tmp[k], palavra[i]);
//        	i++;
//		}else{
//			strcpy(tmp[k], palavra[j]);
//			j++;
//		}
//		k++;
//    }
//    
//    //restos
//    while (i<=meio) {
//        strcpy(tmp[k++], nomes[i++]);
//    }
//    while (j<=fim) {
//        strcpy(tmp[k++], nomes[j++]);
//    }
//    
//    //transferindo pra original
//    for (i=ini, k=0; i<=fim; i++, k++) {
//        strcpy(nomes[i], tmp[k]);
//    }
//}

//complexidade de espa?o: O(n) (linear)
//complexidade de tempo: O(n log n)
//void mergeSort(char palavra[], int ini, int fim) {
//    if (ini < fim) {
//        int meio = (ini + fim) / 2;
//        //printf("%d %d %d\n", ini, meio, fim);
//        mergeSort(palavra, ini, meio);
//        mergeSort(palavra, meio + 1, fim);
//        merge(palavra, ini, meio, fim);
//    }
//}


int main(){
    char str1[LIMITE], str2[LIMITE];
	
	cin>>str1;
	fflush(stdin);
	cin>>str2;
	
	bubbleSortOtimizado(str1, 0);
	bubbleSortOtimizado(str2, 0);
    
	return 0;
}

