#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int arr[50][50];
int visited[50][50];
vector<pair<int,int>> site;
bool choosed[10];
int result = 999999999;
int goal;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(){
  queue<pair<int, int>> que;
  int time=0;
  int spreadArea = 0;
  for(int i=0; i<site.size(); i++){
    if(choosed[i]){
      que.push({site[i].first, site[i].second});
      visited[site[i].first][site[i].second] = 1;
    }
  }
  
  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(0<=nx && nx<n && 0<=ny && ny <n){
        if(arr[nx][ny] ==1 || visited[nx][ny])
          continue;
        que.push({nx,ny});
        visited[nx][ny] = visited[x][y] +1;
        if(arr[nx][ny] == 0){
          spreadArea++;
          time = visited[nx][ny]-1;
        }
      }
    }
  }
  if(spreadArea == goal)
    result = min(result, time);
}

void choise(int now, int count){
  if(count == m){
    bfs();
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++)
        visited[i][j] = 0;
    }
    return;
  }
  for(int i=now; i<site.size(); i++){
    if(choosed[i])
      continue;
    choosed[i] = true;
    choise(i,count+1);
    choosed[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 2)
        site.push_back({i,j});
      else if(arr[i][j] == 0)
        goal++;
    }
  }
  choise(0,0);
  if(result == 999999999){
    result = -1;
  }
  cout << result;
} 