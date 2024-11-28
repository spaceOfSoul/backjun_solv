#include <iostream>
using namespace std;

int n;
int arr[16][16];

int count;
int dx[3] = {0,1,1};
int dy[3] = {1,0,1};

void dfs(int x, int y, int before){
  if(x == n-1 && y== n-1){
    count++;
    return;
  }

  for(int i=0; i<3; i++){
    if((i==0&&before==1)||(i==1&&before==0))
      continue;
    int nx = x + dx[i];
    int ny = y+dy[i];
    if(0<= nx && nx < n && 0<= ny && ny <n && !arr[nx][ny]){
      if(i == 2 && (arr[x][y+1]||arr[x+1][y]))
        continue;
      dfs(nx,ny,i);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
    }
  }
  dfs(0,1,0);
  cout << count;
} 