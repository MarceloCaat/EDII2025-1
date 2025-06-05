#include <stdio.h>

void imprimirElementosComuns(int v1[], int tamanho1, int v2[], int tamanho2) {
    printf("Elementos comuns:\n");

    for (int i = 0; i < tamanho1; i++) {
        int repetido = 0;

        // Verifica se já imprimiu esse número antes
        for (int k = 0; k < i; k++) {
            if (v1[k] == v1[i]) {
                repetido = 1;
                break;
            }
        }

        if (repetido)
            continue;

        // Verifica se número está no vetor 2
        for (int j = 0; j < tamanho2; j++) {
            if (v1[i] == v2[j]) {
                printf("%d ", v1[i]);
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int t1, t2;
    printf("tamaho do vetor 1: \n");
    scanf("%d", &t1);
    printf("tamaho do vetor 2: \n");
    scanf("%d", &t2);
    int v1[t1];
    int v2[t2];
    for (int i = 0; i < t1; i++)
    {
         printf("Digite os elementos do vetor 1:\n");
    scanf("%d", &v1[i]); 
    }
    for (int i = 0; i < t2; i++)
    {
    printf("Digite os elementos do vetor 2:\n");
    scanf("%d", &v2[i]);
}


    imprimirElementosComuns(v1, t1, v2, t2);

    return 0;
}
