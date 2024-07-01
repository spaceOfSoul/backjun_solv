#include <iostream>
#include <queue>
using namespace std;

int r, c;
int count = 0;
char arr[1500][1500];
bool visited[2][1500][1500];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<int, int>> waterQue;
queue<pair<int, int>> baekjoQue;

void melt(){
  queue<pair<int, int>> nxtQue;
  while(!waterQue.empty()){
    int x = waterQue.front().first;
    int y = waterQue.front().second;
    waterQue.pop();
    visited[0][x][y] = true;

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(0<=nx && nx < r && 0 <= ny && ny < c){
        if(visited[0][nx][ny])
          continue;

        visited[0][nx][ny] = true;
        if(arr[nx][ny] == 'X'){
          arr[nx][ny] = '.';
          nxtQue.push({nx,ny});
        }else
          waterQue.push({nx, ny});
      }
    }
  }
  while(!nxtQue.empty()){
    waterQue.push(nxtQue.front());
    nxtQue.pop();
  }
}

bool columBfs(int sx, int sy){
  queue<pair<int, int>> nxtQue;
  while(!baekjoQue.empty()){
    int x = baekjoQue.front().first;
    int y = baekjoQue.front().second;
    baekjoQue.pop();

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(0<=nx && nx < r && 0 <= ny && ny < c){
        if(visited[1][nx][ny])
          continue;

        visited[1][nx][ny] = true;
        if(arr[nx][ny] == 'L')
          return true;
        else if(arr[nx][ny] == 'X')
          nxtQue.push({nx,ny});
        else
          baekjoQue.push({nx, ny});
      }
    }
  }
  while(!nxtQue.empty()){
    baekjoQue.push(nxtQue.front());
    nxtQue.pop();
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int cx,cy;
  cin >> r >> c;
  for(int i=0; i<r;i++){
    for(int j=0; j<c; j++){
      cin >> arr[i][j];
      if(arr[i][j] == '.')
        waterQue.push({i,j});
      else if(arr[i][j] == 'L'){
        waterQue.push({i,j});
        cx = i;
        cy = j;
      }
    }
  }
  baekjoQue.push({cx,cy});
  visited[1][cx][cy] = true;
  
  while(true){
    if(columBfs(cx, cy)){
      cout << count;
      break;
    }
    count++;

    melt();
  }
} 