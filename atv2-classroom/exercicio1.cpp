#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include<fstream>

#define LIMITE 10

using namespace std;

void troca(char nomes[LIMITE][100], int a, int b){
    char aux[100];
	strcpy(aux, nomes[a]);
	strcpy(nomes[a], nomes[b]);
	strcpy(nomes[b], aux);
}

//complexidade de espaço: O(1) (constante)
//complexidade de tempo: O(n²) (exponencial)
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

//complexidade de espaço: O(1) (constante)
//complexidade de tempo: O(n²) (exponencial)
void selectionSort(char nomes[LIMITE][100], int n){
	for(int i=0; i < n-1; i++){
		for(int j=i+1; j < n; j++){
			if(strcmp(nomes[i],nomes[j])>0){
				troca(nomes, i, j);
			}
		}
	}
}

////complexidade de espaço: O(1) (constante)
////complexidade de tempo: O(n²) (exponencial)
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

// Complexidade de tempo e espaço = O(n)
void merge(char nomes[LIMITE][100], int ini, int meio, int fim) {
    char tmp[(fim-ini) + 1][100];
    int i=ini;
	int j=meio + 1;
	int k=0;
    
    //meio e fim são os limites dos vetores divididos
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

//complexidade de espaço: O(n) (linear)
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

int main(){
	int escolha=0;
	
	while(escolha!=5){
		int n=LIMITE;
	    char nomes[LIMITE][100];
	    string linha;
	
		//ifstream – abre o arquivo apenas para leitura
		ifstream arq ("nomes2.txt");
		
		if (arq.is_open()) {
			//eof() - retorna true ao atingir o fim do arquivo
			int i=0;
			while( !arq.eof() ){
				if(i>LIMITE) break;
				
				getline(arq, linha);

				char nome[100]; 
			    strcpy(nomes[i], linha.c_str());

				i++;
			}
			
			arq.close();
		}else{
			cout<<"ERRO: arquivo nao foi aberto ou nao existe"<<endl;
		}
		
		cout<<"ANTES:"<<endl;
		for(int i=0; i<n; i++){
			cout<<"Linha "<<i<<": "<<nomes[i]<<endl;
		}
		cout<<"\n";
	    
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
			cout<<"\n";
			
			continue;
		}
		
		cout<<"DEPOIS:"<<endl;
		for(int i=0; i<n; i++){
			cout<<"Linha "<<i<<": "<<nomes[i]<<endl;
		}
		
		system("pause");
		system("cls");
		fflush(stdin);
	}
    
	return 0;
}

