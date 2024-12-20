#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<ctype.h>

using namespace std;

struct Node {
    int value;
    Node *left, *right;

    Node() {
        left = NULL;
        right = NULL;
    }

    Node(int _value) {
        value = _value;
        left = NULL;
        right = NULL;
    }

    //função para saber quantos filhos tem
    int g() {
        int g = 0;
        if (left != NULL) g++;
        if (right != NULL) g++;
        return g;
    }
};

struct Tree {
    Node *root;
    int tamanho, cont;

    Tree() {
        root = NULL;
        tamanho = 0;
        cont =0;
    }

    bool empty() {
        return root == NULL;
    }

    void insert(int value) {
        if (empty()) {
            root = new Node(value);
            tamanho++;
            return;
        }
        insert(root, value);
    }
    void insert(Node *aux, int value) {
        if (value <= aux->value) {
            if (aux->left == NULL) {
                aux->left = new Node(value);
                tamanho++;
                return;
            }
            insert(aux->left, value);
        } else if (value > aux->value) {
            if (aux->right == NULL) {
                aux->right = new Node(value);
                tamanho++;
                return;
            }
            insert(aux->right, value);
        }
    }

    bool search(int value) {
        Node *aux = root;

        while (aux != NULL) {
            if (value == aux->value) {
                return true;
            } else if (value < aux->value) {
                aux = aux->left;
            } else if (value > aux->value) {
                aux = aux->right;
            }
        }

        return false;
    }

    void inOrder() {
        cont=0;
        inOrder(root);
        printf("\n");
    }
    void inOrder(Node *aux) {
        if (aux == NULL) return;

        inOrder(aux->left);
        printf("%d\n", aux->value);
        inOrder(aux->right);
    }

    void preOrder() {
        cont=0;
        preOrder(root);
        printf("\n");
    }
    void preOrder(Node *aux) {
        if (aux == NULL) return;

        cont++;
        if(cont == tamanho){
            printf("%d", aux->value);
        }else{
            printf("%d ", aux->value);
        }
        preOrder(aux->left);
        preOrder(aux->right);
    }

    void postOrder() {
        cont=0;
        postOrder(root);
        printf("\n");
    }
    void postOrder(Node *aux) {
        if (aux == NULL) return;

        postOrder(aux->left);
        postOrder(aux->right);
        cont++;
        if(cont == tamanho){
            printf("%d", aux->value);
        }else{
            printf("%d ", aux->value);
        }
    }

    void imprimirNivel() {
        cont=0;
        queue<Node*> q;
        //o primeiro é a raiz
        q.push(root);

        //enquanto a pilha não ficar vazia
        while (!q.empty()) {
            Node* aux = q.front();

            //remova o primeiro da fila (q)
            q.pop();
            if (aux == NULL) continue;

            //imprime o primeiro da fila (aux)
            cont++;
            if(cont == tamanho){
                printf("%d", aux->value);
            }else{
                printf("%d ", aux->value);
            }

            //coloca os filhos na fila
            q.push(aux->left);
            q.push(aux->right);
        }
        printf("\n");
    }

    void remove(int value) {
        if (!empty() && root->value == value) {
        	//se não está vazio e o toDel é a raiz
            tamanho--;

            if (root->g() == 0) {
            	//Se a raiz não tiver filhos
            	//exclui a própria raiz
                delete(root);
                root = NULL;
            } else if (root->g() == 1) {
            	//se a raiz tiver 1 filho
            	//o filho vira a raiz
                Node *toDel = root;

                if (root->left != NULL) {
                    root = root->left;
                } else {
                    root = root->right;
                }

                delete(toDel);
            } else {
            	//se a raiz tiver 2 filhos
            	//
                Node *toDel = root;
                Node* aux3 = root;
                Node* aux2 = root->left;

                //enquanto a direita do aux2 tiver alguém
                while (aux2->right != NULL) {
                	//avança o aux3 e o aux2 para a direita
                    aux3 = aux2;
                    aux2 = aux2->right;
                }

                //aux2 é o maior valor
                //o maior entra onde eu quero remover
                root->value = aux2->value;

                if (aux3 != toDel) {
                	//se o meu item anterior é menor que a raiz
                    aux3->right = aux2->left; //a direita do item anterior recebe o menor do aux2 (que pode ser null)
                } else {
                	//se o meu item anterior já é a raiz
                    aux3->left = aux2->left; //a esquerda da raiz recebe o menor do aux2
                }

                delete(aux2);
            }

            return;
        }

        Node* aux = root;
        Node* toDel = root;

		//Enquanto não achar
        while (toDel != NULL) {

            if (toDel->value == value) {
            	//quando achar o valor
            	tamanho--;

                if (toDel->g() == 0) {
                	//se não tiver filhos

                	//anterior tira a ponteiro do valor (toDel) substituindo por NULL
                    if (value > aux->value) {
                        aux->right = NULL;
                    } else {
                        aux->left = NULL;
                    }

                    delete(toDel);
                } else if (toDel->g() == 1) {
                	//se tiver 1 filho
                    Node* toMove;

                    //qual lado está o filho?
                    if (toDel->left != NULL) {
                        toMove = toDel->left; //novo node aponta para o filho da esuquerda
                    } else {
						toMove = toDel->right; //novo node aponta para o filho da direita
                    }

					//anterior tira a ponteiro do valor (toDel) substituindo pelo filho
                    if (value > aux->value) {
                        aux->right = toMove;
                    } else {
                        aux->left = toMove;
                    }

                    delete(toDel);
                } else {
                	//se tiver 2 filhos
                    Node* aux2 = toDel->left;
                    Node* aux3 = toDel;

					//enquanto a direita do aux tiver alguém
                    while (aux2->right != NULL) {
                    	//avança o aux3 e o aux2 para a direita
                        aux3 = aux2;
                        aux2 = aux2->right;
                    }

					//toDel recebe o maior valor a esquerda dele
                    toDel->value = aux2->value;

					if (aux3 != toDel) {
						//se o meu item anterior é menor que o toDel
                        aux3->right = aux2->left; //a direita do anterior recebe o menor do que movi
                    } else {
                    	//se o meu item anterior é o proprio toDel
                        aux3->left = aux2->left; //a esquerda do anterior recebe o menor do que movi
                    }

                    delete(aux2);
                }

                return;

            } else if (value < toDel->value) {
            	//se for menor, vá para a esquerda
                aux = toDel;
                toDel = toDel->left;
            } else {
            	//se não, vá para a direita
                aux = toDel;
                toDel = toDel->right;
            }
        }
    }

    void limpaTree() {
        limpaTree(root);
        root = NULL;
        tamanho = 0;
        cont=0;
    }

    void limpaTree(Node* aux) {
        if (aux == NULL) return;

        limpaTree(aux->left);
        limpaTree(aux->right);

        delete aux;
        aux = NULL;
    }

};

int main() {
    Tree t;
    int n=0, valor=0;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>valor;
        t.insert(valor);
    }

    t.inOrder();
    return 0;
}
