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
		
		//if(imprimirArquivo()==-1) return 0;
		//cout<<endl;
		
		cout<<"Escolha um dos algoritmos de ordenacao abaixo:"<<endl;
		cout<<"5 - Sair"<<endl;
		cin>>escolha;
		cout<<endl;
		
		//system("pause");
	}
    
	return 0;
}

