#include <iostream>
#include <queue>
#include <algorithm>
#define _BV(n) 1<<n
using namespace std;

int n,m,p;
int S[9];
int result[9];
char arr[1000][1000];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

queue<pair<int, int>> que[9];

void bfs(){
  uint16_t flag = 0;
  uint16_t goal = 0;

  for(int i=0; i<p; i++)
    goal |= _BV(i);
    
  while(flag != goal){
    for(int i=0; i<p; i++){

      for(int k=0; k<S[i]; k++){
        int size = que[i].size();

        if(!size){
          flag |= _BV(i);
          break;
        }
        while(size--){
          int x,y,nx,ny;
          result[i]++;
          x = que[i].front().first;
          y = que[i].front().second;

          que[i].pop();

          for(int j=0; j<4; j++){
            nx = x+dx[j];
            ny = y+dy[j];

            if(nx<0 || nx>=n || ny<0 || ny>=m 
              || arr[nx][ny] != '.')
              continue;

            arr[nx][ny] = arr[x][y];
            que[i].push({nx,ny});
          }
        }
      }
      
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  cin >> n >> m >> p;

  for(int i=0; i<p; i++){
    cin >> S[i];
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
      if('1' <= arr[i][j] && arr[i][j] <= '9')
        que[arr[i][j] - '1'].push({i,j});
    }
  }

  bfs();
  
  for(int i=0; i<p; i++){
    cout << result[i] << " ";
  }
}