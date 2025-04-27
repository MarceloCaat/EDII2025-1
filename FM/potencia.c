#include<stdio.h>

int potencia(int base, int expoente, int resultado ) {

    for ( int i = 0; i < expoente; i++)
    {
        resultado = resultado * base;

    }
    return resultado;
}
int main() {
    int resultado = 1;
    printf("digite a base\n");
    int base;
    scanf("%d", &base);
    printf("digite o expoente\n");
    int expoente;
    scanf("%d", &expoente);
    resultado = potencia(base, expoente, resultado); 
    printf("%d elevado a %d é %d\n", base, expoente, resultado);
    return 0;
}