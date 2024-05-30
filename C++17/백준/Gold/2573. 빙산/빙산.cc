#include <iostream>
#include <queue>
using namespace std;

int n,m;
int arr[300][300];
bool visited[300][300];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(int r, int c){
  queue<pair<int,int>> que;
  visited[r][c] = true;
  que.push({r,c});

  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(0<=nx&&nx<n&& 0<=ny&& ny<m){
        if(visited[nx][ny] || !arr[nx][ny])
          continue;
        visited[nx][ny] = true;
        que.push({nx,ny});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
    }
  }
  int count = 0;
  while(1){
    count++;
    queue<pair<int,int>> melt;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(!arr[i][j])
          continue;
        for(int k=0; k<4; k++){
          int meltX = i+dx[k];
          int meltY = j+dy[k];

          if(0<=meltX && meltX<n&&0<=meltY&& meltY<m){
            if(!arr[meltX][meltY])
              melt.push({i,j}); 
          }
        }
      }
    }
    while(!melt.empty()){
      if(arr[melt.front().first][melt.front().second])
        arr[melt.front().first][melt.front().second]--;
      melt.pop();
    }
    
    bool one = false;
    bool part = false;
    int z = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(arr[i][j] && !visited[i][j]){
          if(one){
            part = true;
            break;
            }
          one = true;
          bfs(i,j);
        }
        if(!arr[i][j])
          z++;
      }
      if(part)
        break;
    }
    if(part){
      cout << count;
      return 0;
    }else if(z==n*m){
      cout << 0;
      return 0;
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        visited[i][j] = false;
      }
    }
  }
} 