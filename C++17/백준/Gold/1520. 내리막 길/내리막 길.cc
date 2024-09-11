#include <iostream>
using namespace std;

int m,n;
int arr[500][500];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int visited[500][500];

int dfs(int x, int y){
  if(x == m-1 && y== n-1)
    return 1;
  
  if(visited[x][y] != -1)
    return visited[x][y];
  
  visited[x][y] = 0;

  for(int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if(0<=nx && nx<m && 0<= ny && ny<n){
      if(arr[nx][ny] < arr[x][y])
        visited[x][y] += dfs(nx,ny);
    }
  }
  return visited[x][y];
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> m >> n;
  for(int i=0; i<m; i++)
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
      visited[i][j] = -1;
    }
  
  cout << dfs(0,0);
} 