#include<stdio.h>
 void frequencia(int num[10]) {
int i, j, cont;
    
    // Leitura dos números
    printf("Digite 10 números:\n");
  for (i = 0; i < 10; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &num[i]);
    }
for (i = 0; i < 10; i++)
{
    cont =1;
    int contado = 0;
    for(j = 0; j < i; j++) {
        if(num[i] == num[j]) {
            contado = 1;
            break;
        }
    }
if (contado == 0) {
    int cont = 1;
    for (j = i + 1; j < 10; j++) {
        if (num[i] == num[j]) {
            cont++;
        }
    }
    printf("O número %d aparece %d vez(es).\n", num[i], cont);
}

}
 }
int main() {
    int num[10];
   frequencia(num);


    return 0;
}