#include<stdio.h>
typedef struct {
    int matricula;
    float nota;
    char nome[50];
} aluno;
void adicionaraluno(aluno aluno[], int n){
for(int i = 0; i < n; i++) {
    printf("Digite a matricula do aluno %d: ", i + 1);
    scanf("%d", &aluno[i].matricula);
    printf("Digite a nota do aluno %d: ", i + 1);
    scanf("%f", &aluno[i].nota);
    printf("Digite o nome do aluno %d: ", i + 1);
    scanf(" %[^\n]", aluno[i].nome); // Lê até o final da linha
  }

}
void exibiraluno(aluno aluno[], int n){
for(int i = 0; i < n; i++) {
    printf("Matricula: %d\n", aluno[i].matricula);
    printf("Nota: %.2f\n", aluno[i].nota);
    printf("Nome: %s\n", aluno[i].nome);
    if(aluno[i].nota >= 7.0) {
        printf(" aluno %s aprovado\n", aluno[i].nome);
    }
    else {
        printf(" aluno %s reprovado\n", aluno[i].nome);
  }
}
}
int main() {
   aluno alunos[100];
   int n;
   printf("Digite o numero de alunos: ");
   scanf("%d", &n);
   adicionaraluno(alunos, n);
   exibiraluno(alunos, n);
   return 0;
}