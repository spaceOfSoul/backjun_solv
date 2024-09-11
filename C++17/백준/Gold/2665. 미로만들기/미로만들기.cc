#include <iostream>
#include <queue>
using namespace std;

int n;
char arr[50][50];
int visited[50][50];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(){
  queue<pair<pair<int, int>,int>> que;
  que.push({{0,0},0});
  visited[0][0] = 0;

  while(!que.empty()){
    int x = que.front().first.first;
    int y = que.front().first.second;
    int count = que.front().second;
    que.pop();
    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      int cnt = count;

      if(0<= nx && nx < n && 0<= ny && ny < n){
        if(arr[nx][ny] == '0')
          cnt++;
        if(visited[nx][ny] == -1){
          visited[nx][ny] = cnt;
          que.push({{nx,ny},cnt});
        }else{
          if(visited[nx][ny] > cnt){
            visited[nx][ny] = cnt;
            que.push({{nx,ny},cnt});
          }
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
      visited[i][j] = -1;
    }
  }
  bfs();
  cout << visited[n-1][n-1];
} 