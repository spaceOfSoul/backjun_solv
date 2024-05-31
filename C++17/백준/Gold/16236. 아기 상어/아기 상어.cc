#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[20][20];
bool visited[20][20];

int Size = 2;
int feed;
int r,c;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

int result;

bool bfs(){
  queue<pair<int,int>> que;
  que.push({r,c});
  visited[r][c] = true;
  int step = 0;

  priority_queue<pair<int, int>> fish;

  while(!que.empty()){
    int qus= que.size();
    if(!fish.empty()){
      r = -fish.top().first;
      c = -fish.top().second;
      arr[r][c] = 0;
      feed++;
      if(feed == Size){
        feed = 0;
        Size++;
      }
      result += step;
      return true;
    }
    step++;
    //cout << "step!\n";
    while(qus--){
      int x = que.front().first;
      int y = que.front().second;
      que.pop();

      for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(0<=nx&&nx<n&&0<=ny&&ny<n&&!visited[nx][ny]){
          //cout << arr[nx][ny] << "\n";
          if(arr[nx][ny] > Size)
            continue;
          if(arr[nx][ny] < Size && arr[nx][ny]!=0){
            fish.push({-nx,-ny});
          }
          //cout << nx << " " << ny << "\n";
          que.push({nx,ny});
          visited[nx][ny] = true;
        }
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 9){
        r=i;c=j;
        arr[i][j] = 0;
      }
    }
  }
  // cout << r << " " << c << "\n";

  while(bfs()){
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        visited[i][j] = false;
  }
    cout << result;
}