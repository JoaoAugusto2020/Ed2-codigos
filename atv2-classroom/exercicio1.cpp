#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include<fstream>

#define LIMITE 1000

using namespace std;

struct No {
    char nome[100];
    No* prox;

    No() {
        prox = NULL;
    }

};

struct Lista {
    No* inicio;
    No* fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void inserirFinal(char nome[]) {
    	
        No* novo = new No();
        strcpy(novo->nome, nome);
		if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
        
		//cout<<n<<": "<<novo->nome<<endl;
    }
	
	void imprimir() {
        No* aux = inicio;
        
        //printf("%d %d\n", aux, aux->valor);
        while (aux != NULL) {
            cout<<aux->nome<<endl;
            //printf("%d %d\n", aux->prox, aux->nome);
            aux = aux->prox;
        }
    }
};


void troca(Lista nomes, int a, int b){
    Lista aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

//complexidade de espaço: O(1) (constante)
//complexidade de tempo: O(n²) (exponencial)
void bubbleSortOtimizado(Lista nomes, int n){
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
void selectionSort(Lista nomes, int n){
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
void insertionSort(Lista nomes, int n){
	for(int i=1; i < n; i++){
		vector<string> aux = v[i];
		int j = i-1;
		
		while(j>=0 && aux<v[j]){
			v[j + 1] = v[j];
			j--;
		}
		
		v[j+1] = aux;
	}
}

// Complexidade de tempo e espaço = O(n)
void merge(Lista nomes, int ini, int meio, int fim) {
    vector<string> tmp[(fim-ini) + 1];
    int i=ini;
	int j=meio + 1;
	int k=0;
    
    //meio e fim são os limites dos vetores divididos
    while (i<=meio && j<=fim) {
        tmp[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
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
void mergeSort(Lista nomes, int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        //printf("%d %d %d\n", ini, meio, fim);
        mergeSort(v, ini, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, ini, meio, fim);
    }
}

int main(){
	int escolha=0;
	
	while(escolha!=5){
	    Lista nomes;
	    string linha;
	
		//ifstream – abre o arquivo apenas para leitura
		ifstream arq ("nomes2.txt");
		
		if (arq.is_open()) {
			//eof() - retorna true ao atingir o fim do arquivo
			int i=1;
			while( !arq.eof() ){
				if(i>LIMITE) break;
				
				getline(arq, linha);
			    char nome[100]; 
			    strcpy(nome, linha.c_str());
				nomes.inserirFinal(nome);
				i++;
			}
			
			arq.close();
		}else{
			cout<<"ERRO: arquivo nao foi aberto ou nao existe"<<endl;
		}
	    
		nomes.imprimir();
		cout<<nomes.n<<endl;
		
		cout<<"Escolha um dos algoritmos de ordenacao abaixo:"<<endl;
		cout<<"1 - BubbleSort"<<endl;
		cout<<"2 - SelectionSort"<<endl;
		cout<<"3 - InsertionSort"<<endl;
		cout<<"4 - MergeSort"<<endl;
		cout<<"5 - Sair"<<endl;
		cin>>escolha;
		cout<<endl;
		
		if(escolha==1){
			bubbleSortOtimizado(nomes, n);
		}else if(escolha==2){
			selectionSort(nomes, n);
		}else if(escolha==3){
			insertionSort(nomes, n);
		}else if(escolha==4){
			mergeSort(nomes, 0, n-1);
		}else if(escolha==5){
			return 0;
		}else{
			cout<<"Opcao invalida! Escolha novamente!"<<endl;
			cout<<endl;
			
			system("pause");
			continue;
		}
		
		system("pause");
	}
    
	return 0;
}

