//invertexto.com/rzak36
#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore binária
typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;


Node* criarNo(int valor){
    Node* novo = malloc(sizeof(Node));
    if(novo){
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->valor = valor;
    }
    return novo;
}

Node* inserir(Node* raiz, int valor){
    if(raiz == NULL){
        return criarNo(valor);
    }
    if(valor < raiz->valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }else{
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}
Node* buscar(Node* raiz, int dado){
    if(raiz == NULL || raiz->valor == dado){
        return raiz;
    }
    if(dado < raiz-> valor){ //se o dado que voce quer achar for menos que o valor do no atual ele procura no no da esquerda//
        return buscar(raiz->esquerda, dado);
    }
    else {
        return buscar(raiz->direita, dado);
    }
}
void preOrdem(Node* raiz){
    if(raiz != NULL){
        printf("%d\n", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}
void posOrdem(Node* raiz){
    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

int main() {
    Node* raiz = NULL;

    // Inserindo valores
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);

    // Testando busca
    Node* encontrado = buscar(raiz, 3);
    if (encontrado != NULL)
        printf("Valor %d encontrado!\n", encontrado->valor);
    else
        printf("Valor nao encontrado.\n");

    return 0;
}