#include<stdio.h>
void somarmatriz(int a[3][3], int b[3][3]){
// somar as matrizes a e b
for (int i = 0; i<3; i++) {
    for (int j = 0; j<3; j++) {
        printf("%d ", a[i][j] + b[i][j]);
    }
    printf("\n");
  }
}
int main() {
   int a[3][3] = {
    {1, 2, 3},
    {4, 5, 6}, 
    {7, 8, 9}};
    int b[3][3] = {
    {9, 8, 7},
    {6, 5, 4}, 
    {3, 2, 1}};
    somarmatriz(a,b);
    return 0;
}