#include <iostream>
using namespace std;

int n,m,r,c,sd;
int result = 1;

int arr[50][50];
bool visited[50][50];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int d;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;
  cin >> r >> c >> d;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
    }
  }

  int turning = 0;
  visited[r][c] = true;
  while(true){
    
    d--;
    if(d == -1)
      d = 3;

    int nx, ny;
    nx = r+dx[d];
    ny = c+dy[d];

    if(arr[nx][ny] || visited[nx][ny]){
      turning++;
    }else{
      r = nx;
      c = ny;
      result++;
      turning = 0;
      visited[r][c] = true;
    }

    if(turning == 4){
      nx = r-dx[d];
      ny = c-dy[d];
      if(!arr[nx][ny]){
        r = nx;
        c=ny;
        turning = 0;
      }else
        break;
    }
  }
  cout << result;
} 