/*Cristiano, um aluno curioso de matemática, notou que para todo número inteiro par maior que 2 que ele testou
manualmente existe alguma forma de expressá-lo como a soma de dois números primos. Como Cristiano não
sabe provar que a propriedade é válida para todo número maior que 2 e também não sabe programar, ele pediu a
sua ajuda para escrever um programa para contar o número de pares de números primos cuja soma é igual a um
número N (N<1.000.000).
Um número natural P, maior que 1, é um número primo se é divisível apenas por dois números positivos: 1 e P.
Por exemplo, os 6 menores números primos são: 2, 3, 5, 7, 11 e 13. Desta forma, para N=16, podemos expressar
através de duas somas de primos: 3+13 e 5+11.
Entrada
A entrada consiste de um número inteiro N (3 < N < 1.000.000) par.
Saída
Você deve imprimir o número de pares de primos que somados resultam em N. Note que 3+5=8 e 5+3=8 são o
mesmo par. Você deve contar o número de pares distintos.*/

#include <math.h>
#include <stdio.h>
 
int main()
{
  int i, j, k = 0, n, cont = 0; 
  static int v[1000000];
  scanf("%d", &n);
 
  for (i = 2; i <= n; i++)
    v[i] = i;
 
  for (i = 2; i <= sqrt(n); i++) {
    if (v[i] == i) {
      for (j = 2 * i; j <= n; j += i)
        v[j] = 0;
    }
  }
 
  for (i = 2; i <= n/2; i++){
    if(v[i] != 0 && v[n-i] != 0)
      cont++;
  }
        
  printf("%d\n", cont);
 
  return 0;
}
