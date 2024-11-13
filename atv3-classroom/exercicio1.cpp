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
};

// comp. tempo O(n)
bool buscaSequencial(int v[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (v[i] == x) return true;
    }
    return false;
}

// comp. tempo O(n)
bool buscarSubstring(char nome[], char busca[]) {
	if (strstr(nome,busca)!=NULL){
		//cout<<"encontrado!"<<endl;
		return true;
	}else{
		//cout<<"nao encontrado!"<<endl;
		return false;
	}
}

// comp. tempo O(log n)
// comp. espaco O(1)
bool buscaBinaria(int v[], int n, int x) {
    int ini=0, fim=n-1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (v[m] == x) {
            return true;
        } else if (v[m] > x) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return false;
}

void converterMaiusculo(char str[]){
	int i=0;
	while (str[i]){
		str[i] = toupper(str[i]);
		i++;
	}
}

int main(){
	Lista arqnomes;
    string linha;
    char busca[100];

	//ifstream – abre o arquivo apenas para leitura
	ifstream arq ("nomes.txt");
	
	//eof() - retorna true ao atingir o fim do arquivo
	if( arq.is_open() ){
		while( !arq.eof() ){
			char nome[100];
			
			getline(arq, linha);
		    strcpy(nome, linha.c_str());
		    
		    converterMaiusculo(nome);
			arqnomes.inserirFinal(nome);
		}
		arqnomes.removerFinal();
		
		arq.close();
	}else{
		cout<<"ERRO: arquivo nao foi aberto ou nao existe"<<endl;
	}
    
    //PARA TESTES
	//arqnomes.imprimir();
	//cout<<"qtd: "<<arqnomes.n<<endl;
	
	cout<<"Digite a sua substring (Busca): ";
	cin>>busca;
	converterMaiusculo(busca);
	
	buscaSequencialChar("ADELIA ROSMANINHO",busca);
	
	return 0;
}

