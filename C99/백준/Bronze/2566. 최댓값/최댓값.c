#include <stdio.h>

int main(void) {
  int tmp, i, j;
  int max = -1;
  int max_i, max_j;
  for(i = 1; i<=9; i++){
    for(j = 1; j<=9; j++){
      scanf("%d", &tmp);
      if(tmp > max){
        max = tmp;
        max_i = i;
        max_j = j;
      }
    }
  }

  printf("%d\n",max);
  printf("%d %d", max_i, max_j);
  return 0;
}