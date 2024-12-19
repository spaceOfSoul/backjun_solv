#include <stdio.h>
#include <string.h>

int main(void) {
  int t, n, m;
  scanf("%d", &t);
  while(t--){
    int coin[20];
    int memory[10001];
    memset(memory, 0, sizeof(memory));
    
    scanf("%d", &n);
    for(int i=0; i<n; i++)
      scanf("%d", coin+i);

    scanf("%d", &m);
    memory[0]=1;
    for(int i=0; i<n; i++){
      for(int j=coin[i]; j<=m; j++){
        memory[j] += memory[j-coin[i]];
      }
    }
    printf("%d\n", memory[m]);
  }
  return 0;
}