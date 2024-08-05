#include <iostream>
#include <queue>
using namespace std;

int n,m,k, result;
bool visited[100][100];
bool garbage[100][100];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int a, int b){
  queue<pair<int, int>> que;
  visited[a][b] = true;
  que.push({a,b});
  int size = 0;

  while(!que.empty()){
    size++;
    int x = que.front().first;
    int y = que.front().second;
    que.pop();
    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(0<=nx&&nx<n&&0<=ny&& ny<m && !visited[nx][ny]){
        if(!garbage[nx][ny])
          continue;
        visited[nx][ny] = true;
        que.push({nx,ny});
      }
    }
  }
  if(size>result)
    result = size;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m >> k;
  int a,b;
  while(k--){
    cin >> a >> b;
    garbage[a-1][b-1] = true;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(garbage[i][j] && !visited[i][j]){
        bfs(i,j);
      }
    }
  }
  cout << result;
}