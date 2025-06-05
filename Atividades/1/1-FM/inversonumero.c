
#include <stdio.h>

int inverterNumero(int num) {
    int invertido = 0;

    while (num != 0) {
        int digito = num % 10;   
        invertido = invertido * 10 + digito;  
        num = num / 10;  
    }

    return invertido;
}

int main() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);

    int numeroInvertido = inverterNumero(numero);

    printf("O número invertido é: %d\n", numeroInvertido);
    return 0;
}
