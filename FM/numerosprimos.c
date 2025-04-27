#include<stdio.h>
#include <stdbool.h>

bool primo(int n) {
if(n < 2 ) return false;
for(int i = 2 ; i * i <= n ; i++){
    if(n % i == 0)
        return false;
}
        return true;

}
    

int main() {
    int cont = 0;
    printf("digite dois numeros\n");
    int inicio, fim;
    printf("digite o primeiro numero\n");
    scanf("%d", &inicio);
    printf("digite o segundo numero\n");
    scanf("%d", &fim);
   if(inicio<=fim){ 
    for (int i=inicio; i<=fim; i++){ 
        if (primo(i)){
            printf("%d\n",i);
            cont = 1;
        }    
    }
    if(cont != 1){
        printf("entre os numeros %d e %d \n",inicio, fim);
        printf("nao existem numeros primos\n");
    }
}
    else{
        printf("o primeiro numero deve ser menor que o segundo\n");
    }
}