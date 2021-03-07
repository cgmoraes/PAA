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
