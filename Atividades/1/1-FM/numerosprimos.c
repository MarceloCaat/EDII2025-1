#include <stdio.h>
#include <stdbool.h>

// Função que verifica se um número é primo
bool primo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Função que imprime todos os primos até um número dado pelo usuario
void imprime() {
    int fim;

    printf("Digite um numero: ");
    scanf("%d", &fim);

    printf("Numeros primos ate %d:\n", fim);
    if(fim >= 2) {
    for (int i = 2; i <= fim; i++) {
        if (primo(i)) {
            printf("%d\n", i);
        }
    }
}
else {
    printf("Nenhum numero primo encontrado.\n");
    }
}

int main() {
    imprime();
    return 0;
}