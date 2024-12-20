#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<ctype.h>

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

void imprimirVetorC(int v[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", v[i]);
    }
}

//complexidade de tempo: O(n²) (exponencial)
//complexidade de espaço: O(1) (constante)
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

//complexidade de tempo: O(n²) (exponencial)
//complexidade de espaço: O(1) (constante)
void selectionSort(int v[], int n){
	for(int i=0; i < n-1; i++){
		for(int j=i+1; j < n; j++){
			if(v[i] > v[j]){
				troca(v, i, j);
			}
		}
	}
}

//complexidade de tempo: O(n²) (exponencial)
//complexidade de espaço: O(1) (constante)
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

//complexidade de tempo: O(n) (linear)
//complexidade de espaço: O(n) (linear)
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

//complexidade de tempo: O(n log n)
//complexidade de espaço: O(n) (linear)
void mergeSortSimples(int v[], int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        //printf("%d %d %d\n", ini, meio, fim);
        mergeSortSimples(v, ini, meio);
        mergeSortSimples(v, meio + 1, fim);
        
        merge(v, ini, meio, fim);
    }
}

//complexidade de tempo: O(max(n, m)) onde m é o maior elemento do vetor
//complexidade de espaço: O(m)
void countingSort(int v[], int n, int m) {
	//m = maior elemento do vetor
	
	//vetor temporario = 0
    int tmp[m + 1];
    for (int i=0; i<m+1; i++) tmp[i] = 0;
    
    //percorrendo o vetor normal
    for (int i=0; i<n; i++) {
    	//no vetor contador, some 1 onde a posicao eh = o valor do vetor
        tmp[ v[i] ]++;
    }
    
    //percorrendo vetor temporário e "esvaziando" ele
    for (int i=0,j=0; i<m+1; i++) {
    	//enquanto houver elementos a serem contados
        while(tmp[i] > 0) {
        	//ordenando vetor normal
            v[j++] = i;
            //quantas vezes cada número tiver no tmp
            tmp[i]--;
        }
    }
}

int main(){
    int n;
	cout<<"Digite o tamanho do vetor"<<endl;
	cin>>n;
	cout<<endl;
	
    int v[n];
	
	srand(time(NULL));
    geraVetor(v, n);
	
	int escolha=0;
	while(escolha<1 || escolha>5){
		cout<<"Escolha um dos algoritmos de ordenacao abaixo:"<<endl;
		cout<<"1 - BubbleSort"<<endl;
		cout<<"2 - SelectionSort"<<endl;
		cout<<"3 - InsertionSort"<<endl;
		cout<<"4 - MergeSort"<<endl;
		cout<<"5 - CountingSort"<<endl;
		cin>>escolha;
		
		if(escolha==1){
			bubbleSortOtimizado(v, n);
		}else if(escolha==2){
			selectionSort(v, n);
		}else if(escolha==3){
			insertionSort(v , n);
		}else if(escolha==4){
			mergeSortSimples(v, 0, n-1);
		}else if(escolha==5){
			countingSort(v, n, n);
		}else{
			cout<<"Opcao invalida! Escolha novamente!"<<endl;
			cout<<endl;
			continue;
		}
		cout<<endl;
		
	    imprimirVetor(v, n);
	}
    
	return 0;
}

