#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore binária
typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;

// Cria um novo nó
Node* criarNo(int valor){
    Node* novo = malloc(sizeof(Node));
    if(novo){
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->valor = valor;
    }
    return novo;
}

// Insere um valor na árvore
Node* inserir(Node* raiz, int valor){
    if(raiz == NULL){
        return criarNo(valor);
    }
    if(valor < raiz->valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

// Busca um valor na árvore
Node* buscar(Node* raiz, int dado){
    if(raiz == NULL || raiz->valor == dado){
        return raiz;
    }
    if(dado < raiz->valor){
        return buscar(raiz->esquerda, dado);
    } else {
        return buscar(raiz->direita, dado);
    }
}

// Impressão em pré-ordem (raiz, esquerda, direita)
void preOrdem(Node* raiz){
    if(raiz != NULL){
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Impressão em pós-ordem (esquerda, direita, raiz)
void posOrdem(Node* raiz){
    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}
void emOrdem(Node* raiz){
    if(raiz != NULL){
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}


// Remove um nó da árvore
Node* remover(Node* raiz, int valor) {
    if (raiz == NULL) return NULL;

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        // Nó com 0 ou 1 filho
        if (raiz->esquerda == NULL) {
            Node* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            Node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Nó com 2 filhos: encontrar o menor da subárvore direita
        Node* atual = raiz->direita;
        while (atual->esquerda != NULL) {
            atual = atual->esquerda;
        }

        raiz->valor = atual->valor;
        raiz->direita = remover(raiz->direita, atual->valor);
    }

    return raiz;
}

//função para calcular a altura da arvore
int altura(Node* raiz) {
    if (raiz == NULL){
        return -1; // Retorna -1 para considerar a altura de uma árvore vazia como -1
    }
    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);
     int maiorvalor;
     if (alturaEsquerda > alturaDireita) {
        maiorvalor = alturaEsquerda;
}
else {
    maiorvalor = alturaDireita;

}
int resultado = maiorvalor +1;
    return resultado;
}
int soma(Node* raiz) {
    if (raiz == NULL) {
        return 0; 
    }
    int somaesquerda = soma(raiz->esquerda);
    int somadireita = soma(raiz->direita);
     int resultado = raiz->valor + somaesquerda + somadireita;
    return resultado;
}
int contarNos(Node* raiz) {
    if (raiz == NULL) {
        return 0; 
    }
int nosesquerda = contarNos(raiz->esquerda);
int nosdireita = contarNos(raiz->direita);
int resultado = 1 + nosesquerda + nosdireita; 
    return resultado;
}
int nivel(Node* raiz, int valor, int nivelAtual) {
    if(raiz == NULL) {
        return -1;
    }
    if(raiz->valor == valor) {
        return nivelAtual; // Retorna o nível do nó encontrado
    }
int resultado;
    if(valor < raiz->valor) {
        resultado = nivel(raiz->esquerda, valor, nivelAtual + 1);
    } else {
        resultado = nivel(raiz->direita, valor, nivelAtual + 1);
    }
    return resultado; 
}
int profundidade(Node* raiz, int valor) {
    return nivel(raiz, valor, 0);
}


int main() {
    Node* raiz = NULL;

    // Inserindo valores na árvore
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);

    // Removendo um valor
    raiz = remover(raiz, 30);

    // Buscando um valor
    Node* encontrado = buscar(raiz, 70);
    if (encontrado != NULL)
        printf("Valor %d encontrado!\n", encontrado->valor);
    else
        printf("Valor nao encontrado.\n");

    // Mostrando a árvore
    printf("Pre-Ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Pos-Ordem: ");
    posOrdem(raiz);
    printf("\n");
altura(raiz);
    printf("Altura da árvore: %d\n", altura(raiz));
    soma(raiz);
    printf("Soma dos valores da árvore: %d\n", soma(raiz));
    contarNos(raiz);
    printf("Número de nós na árvore: %d\n", contarNos(raiz));   
    nivel(raiz, 40, 0);
    printf("Nível do nó com valor 20: %d\n", nivel(raiz, 40, 0));
    profundidade(raiz, 40);
    printf("Profundidade do nó com valor 20: %d\n", profundidade(raiz, 40));
    return 0;
}
