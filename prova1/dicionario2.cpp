#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<ctype.h>

using namespace std;

struct No {
    char nome[100];
    No* prox;

    No() {
        prox = NULL;
    }
    
    No(char _valor[]) {
        strcpy(nome, _valor);
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

    void inserirFinal(char nome[100]) {
    	
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
    
    void removerFinal() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
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
    
    bool buscarSubstring(char nome[], char busca[]) {
		if (strstr(nome,busca)!=NULL){
			//cout<<"encontrado!"<<endl;
			return true;
		}else{
			//cout<<"nao encontrado!"<<endl;
			return false;
		}
	}
    
    void buscar(char palavra[]){
    	No* aux = inicio;
        
        while (aux != NULL) {
            if(strcmp(aux->nome, palavra)==0){
            	inserirFinal(aux->nome);
			}
            aux = aux->prox;
        }
	}
};

int main(){
	int n=0, m=0, cont=0;
	char palavra[100];
    Lista dicionario, palavras;
    
    cin>>n;
	for(int i=0; i<n; i++){
		cin>>palavra;
		dicionario.inserirFinal(palavra);
	}
	
	cin>>m;
	for(int i=0; i<m; i++){
		cin>>palavra;
		palavras.inserirFinal(palavra);
	}
	
	//buscaSequencialChar("ADELIA ROSMANINHO",busca);
	
	resultado.buscar(busca);
	
	return 0;
}
