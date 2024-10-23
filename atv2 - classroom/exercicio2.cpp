#include <bits/stdc++.h>
using namespace std;

struct Time{
    string nome;
    int pont, vit, emp, der, saldoGols, golsP, golsC;

    Time(){
        pont = vit = emp = der = saldoGols = golsP = golsC = 0;
    }
};

struct Jogo{
    string t1, t2, res;
};

struct No{
    Time valor;
    No* prox;

    No(){
        prox = NULL;
    }
    No(Time _valor){
        valor = _valor;
        prox = NULL;
    }
};

struct Lista{
    No* inicio;
    No* fim;
    int tam;

    Lista(){
        inicio = NULL;
        fim = NULL;
        tam = 0;
    }

    void inserirFinal(Time valor){
        No* aux = inicio;
        while(aux != NULL){
            if(aux->valor.nome == valor.nome) {
                aux->valor.vit += valor.vit;
                aux->valor.der += valor.der;
                aux->valor.emp += valor.emp;
                aux->valor.pont += valor.pont;
                aux->valor.golsP += valor.golsP;
                aux->valor.golsC += valor.golsC;
                return;
            }
            aux = aux->prox;
        }

        No* novo = new No(valor);
        if(tam == 0){
            inicio = novo;
            fim = novo;
        } else{
            fim->prox = novo;
            fim = novo;
        }
        tam++;
    }

    void imprimir(){
        cout << "TABELA DE RESULTADOS\n\n";
        cout << "Time" << setw(14) <<"Pontos" << setw(14) << "Vitorias" << setw(14) 
            << "Empates" << setw(14) << "Derrotas" << setw(14) << "Saldo Gols" << setw(14)
                << "Gols Pro" << setw(14) << "Gols Contra";
        cout << "\n";
        No* aux = inicio;
        while(aux != NULL){
            cout << aux->valor.nome << setw(14) <<
                aux->valor.pont << setw(14) << aux->valor.vit << setw(14)
                    << aux->valor.emp << setw(14) << aux->valor.der << setw(14) << aux->valor.saldoGols
                        << setw(14) << aux->valor.golsP << setw(14) << aux->valor.golsC << "\n";

            aux = aux->prox;
        }
    }

    void saldoDeGols(){
        No* aux = inicio;
        while(aux != NULL){
            aux->valor.saldoGols = aux->valor.golsP - aux->valor.golsC;
            aux = aux->prox;
        }
    }

    void listaParaVetor(Time v[]){
        No* aux = inicio;
        int i=0;
        while(aux != NULL){
            v[i] = aux->valor;
            i++;
            aux = aux->prox;
        }
    }

    void vetorParaLista(Time v[]){
        No* aux = inicio;
        int i=0;
        while(aux != NULL){
            aux->valor = v[i];
            i++;
            aux = aux->prox;
        }
    }
};


//funções para ordenação
bool troca(Time v[], int i, int j){
    if(v[i].pont < v[j].pont){
        return true;
    } 
    else if(v[i].pont == v[j].pont){
        if(v[i].vit < v[j].vit){
            return true;
        } 
        else if(v[i].vit == v[j].vit){
            if(v[i].saldoGols < v[j].saldoGols){
                return true;
            } 
            else if(v[i].saldoGols == v[j].saldoGols){
                if(v[i].golsP < v[j].golsP){
                    return true;
                }
            }
        }
    }
    return false;
}

void bubbleSort(Time v[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<(n-1)-i; j++){
            if(troca(v, j, j+1)){
                swap(v[j], v[j+1]);
            }
        }
    }
}

void selectionSort(Time v[], int n){
    for(int i=0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if(troca(v, i, j)){
                swap(v[i], v[j]);
            }
        }
    }
}

bool trocaInsertion(Time v[], Time aux, int j){
    if(aux.pont > v[j].pont){
        return true;
    } 
    else if(aux.pont == v[j].pont){
        if(aux.vit > v[j].vit){
            return true;
        } 
        else if(aux.vit == v[j].vit){
            if(aux.saldoGols > v[j].saldoGols){
                return true;
            } 
            else if(aux.saldoGols == v[j].saldoGols){
                if(aux.golsP > v[j].golsP){
                    return true;
                }
            }
        }
    }
    return false;
}

void insertionSort(Time v[], int n){
    for(int i=1; i<n; i++){
        Time aux = v[i];
        int j = i-1;
        while(j>=0 && trocaInsertion(v, aux, j)){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
}

void merge(Time v[], int inicio, int m, int f){
    Time tmp[(f-inicio)+1];
    int i=inicio, j=m+1, k=0;
    while(i <= m && j<=f){
        if(troca(v, i, j)) tmp[k++] = v[j++]; 
        else tmp[k++] = v[i++]; 
    }

    while(i <= m){
        tmp[k++] = v[i++];
    }
    while(j <= f){
        tmp[k++] = v[j++];
    }
    for(i = inicio, k=0; i<=f; i++, k++){
        v[i] = tmp[k];
    }
}

void mergeSort(Time v[], int i, int f){
    if(i < f){
        int m = (i+f)/2;
        mergeSort(v, i, m);
        mergeSort(v, m+1, f);
        merge(v, i, m, f);
    }
}

int main(){
    ifstream infile;
    infile.open("dados.txt");

    vector <Jogo> jogos;
    string t1, res, t2;

    while(infile >> t1 >> res >> t2){
        Jogo j;
        j.t1 = t1, j.t2 = t2, j.res = res;
        jogos.push_back(j);
    }
    Lista l;
    for(int i=0; i<(int)jogos.size(); i++){
        int pont1 = jogos[i].res[0] - '0';
        int pont2 = jogos[i].res[2] - '0';

        Time t1, t2;
        t1.nome = jogos[i].t1, t2.nome = jogos[i].t2;
        if(pont1 > pont2){
            t1.pont = 3, t1.vit = 1, t1.golsP = pont1, t1.golsC = pont2;
            t2.der = 1, t2.golsP = pont2, t2.golsC = pont1;
        } else if(pont2 > pont1){
            t2.pont = 3, t2.vit = 1, t2.golsP = pont2, t2.golsC = pont1;
            t1.der = 1, t1.golsP = pont1, t1.golsC = pont2;
        } else{
            t1.pont = 1, t1.emp = 1, t1.golsP = pont1, t1.golsC = pont2;
            t2.pont = 1, t2.emp = 1, t2.golsP = pont2, t2.golsC = pont1;
        }

        l.inserirFinal(t1);
        l.inserirFinal(t2);
    }
    l.saldoDeGols();

    Time vetTimes[l.tam + 1];
    l.listaParaVetor(vetTimes);

    int op;
    cout << "Qual metodo de ordenacao deseja utilizar?\n";
    cout << "1 - Bubble Sort\n2 - Selection Sort\n3 - Insertion Sort\n4 - Merge Sort\n";
    cin >> op;

    switch(op){
        case 1:
            bubbleSort(vetTimes, l.tam+1);
            break;
        case 2:
            selectionSort(vetTimes, l.tam+1);
            break;
        case 3:
            insertionSort(vetTimes, l.tam+1);
            break;
        case 4:
            mergeSort(vetTimes, 0, l.tam);
            break;
    
    }
    l.vetorParaLista(vetTimes);
    l.imprimir();
}