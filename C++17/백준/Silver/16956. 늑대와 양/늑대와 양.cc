#include <iostream>
#include <vector>
using namespace std;

int r,c;
char arr[500][500];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

vector<pair<int, int>> ship;
int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> r >> c;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 'S')
        ship.push_back({i,j});
    }
  }

  int result = 1;
  for(auto i:ship){
    int x = i.first;
    int y = i.second;

    for(int j=0; j<4; j++){
      int nx = x+dx[j];
      int ny = y+dy[j];
      if(0<=nx&&nx<r&&0<=ny&&ny<c){
        if(arr[nx][ny] == 'W'){
          result = 0;
          break;
        }
      }
    }
    if(!result)
      break;
  }
  cout << result << "\n";
  if(result){
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        if(arr[i][j] == '.')
          cout << 'D';
        else{
          cout << arr[i][j];
        }
      }
      cout << "\n";
    }
  }
}