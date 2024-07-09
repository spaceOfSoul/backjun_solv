#include <stdio.h>

int t, r, c;
char arr[400][400];

int result;

int main(void) {
  scanf("%d", &t);

  while(t--){
    result = 0;
    
    scanf("%d %d", &r, &c);

    for(int i=0; i<r; i++){
      scanf("%s", arr[i]);
    }

    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        
        if(arr[i][j] == 'o'){
          // printf("rc : %d %d \n", i, j);
          int nx_1, nx_2, ny_1, ny_2;
          nx_1 = i + 1;
          nx_2 = i - 1;
          ny_1 = j + 1;
          ny_2 = j - 1;

          if(nx_1 < r && nx_2 >= 0){
            if(arr[nx_1][j] == '^' && arr[nx_2][j] == 'v')
              result++;
          }
          
          if(ny_1 < c && ny_2 >= 0){
            if(arr[i][ny_1] == '<' && arr[i][ny_2] == '>')
              result++;
          }
        }
        
      }
    }

    printf("%d\n", result);
  }
  return 0;
}