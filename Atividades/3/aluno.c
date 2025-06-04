#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

Aluno* criarAluno(char* nome, int matricula, float nota) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->matricula = matricula;
        novo->nota = nota;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}
Aluno* inserirAluno(Aluno* raiz, char* nome, int matricula, float nota) {
    if (raiz == NULL) {
        return criarAluno(nome, matricula, nota);
    }

    if (matricula < raiz->matricula) {
        raiz->esquerdo = inserirAluno(raiz->esquerdo, nome, matricula, nota);
    } else if (matricula > raiz->matricula) {
        raiz->direito = inserirAluno(raiz->direito, nome, matricula, nota);
    } else {
        printf("Já existe um aluno com essa matrícula!\n");
    }

    return raiz;
}
#include <string.h> // necessário para strcmp

Aluno* buscarPorNome(Aluno* raiz, char* nome) {
    if (raiz == NULL)
        return NULL;

    // Verifica se o nome do nó atual é igual ao nome procurado
    if (strcmp(raiz->nome, nome) == 0) {
        return raiz;
    }

    // Busca na subárvore esquerda
    Aluno* encontrado = buscarPorNome(raiz->esquerdo, nome);
    if (encontrado != NULL)
        return encontrado;

    // Se não achou na esquerda, busca na direita
    return buscarPorNome(raiz->direito, nome);
}
// Função auxiliar para somar as notas e contar os alunos
void somarNotas(Aluno* raiz, float* soma, int* total) {
    if (raiz == NULL) return;

    *soma += raiz->nota;
    (*total)++;

    somarNotas(raiz->esquerdo, soma, total);
    somarNotas(raiz->direito, soma, total);
}

// Função principal que retorna a média
float calcularMedia(Aluno* raiz) {
    float soma = 0;
    int total = 0;

    somarNotas(raiz, &soma, &total);

    if (total == 0) return 0; // evita divisão por zero
    return soma / total;
}

int main() {
    Aluno* raiz = NULL;

    raiz = inserirAluno(raiz, "Ana", 101, 7.5);
    raiz = inserirAluno(raiz, "Bruno", 102, 8.0);
    raiz = inserirAluno(raiz, "Carla", 100, 6.8);

    Aluno* resultado = buscarPorNome(raiz, "Bruno");
    if (resultado != NULL) {
        printf("Aluno encontrado: %s, Matricula: %d, Nota: %.2f\n",
                resultado->nome, resultado->matricula, resultado->nota);
    } else {
        printf("Aluno não encontrado.\n");
    }
    float media = calcularMedia(raiz);
    printf("Média das notas dos alunos: %.2f\n", media);
    return 0;
}



