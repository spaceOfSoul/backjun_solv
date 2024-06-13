#include <iostream>
#include <queue>
using namespace std;

int arr[1000][1000];
int m,n;
int result = -1;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<pair<int, int>> que;
void bfs(){
  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(0<=nx && nx < n && 0<=ny && ny <m && arr[nx][ny] == 0){
        arr[nx][ny] = arr[x][y] +1;
        que.push({nx,ny});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> m >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
      if(arr[i][j]==1)
        que.push({i,j});
    }
  }
  bfs();
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j] == 0){
        cout << -1;
        return 0;
      }
      if(arr[i][j] > result)
        result = arr[i][j];
    }
  }
  cout << result-1;
}