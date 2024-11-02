#include <iostream>
#include <queue>
using namespace std;

int r, c;

queue<pair<int, int>> hedge;
queue<pair<int, int>> water;
int gx,gy;

char arr[50][50];
int visited[50][50];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void waterBfs(int ls){
  while(ls--){
    int x= water.front().first;
    int y = water.front().second;
    water.pop();

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(0<=nx && nx<r && 0<= ny && ny < c){
        if(arr[nx][ny] == '.'){
          arr[nx][ny] = '*';
          water.push({nx,ny});
        }
      }
    }
  }
}

int bfs(){
  while(!hedge.empty()){
    waterBfs(water.size());
    int hedgePos = hedge.size();
    while(hedgePos--){
      int x = hedge.front().first;
      int y = hedge.front().second;
      hedge.pop();

      if(x == gx && y == gy)
        return visited[x][y];

      for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y + dy[i];

        if(!visited[nx][ny] && 0<= nx && nx< r && 0<= ny &&   ny < c){
          if(arr[nx][ny] == '*' || arr[nx][ny] == 'X')
            continue;
          visited[nx][ny] = visited[x][y] +1;
          hedge.push({nx,ny});
        }
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> r >> c;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin >> arr[i][j];
      if(arr[i][j] == '*')
        water.push({i,j});
      else if(arr[i][j] == 'S')
        hedge.push({i,j});
      else if(arr[i][j] == 'D'){
        gx = i;
        gy= j;
      }
    }
  }
  int result = bfs();
  if(result == -1)
    cout << "KAKTUS";
  else
    cout << result;
} 