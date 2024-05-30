#include <iostream>
using namespace std;

int n,x;
int dist[10][10];
int result = 999999999;
bool visited[10];

void dfs(int a, int cnt, int cost){
  if(cnt == n){
    if(result>cost)
      result = cost;
    return;
  }
  for(int i=0; i<n; i++){
    if(!visited[i]){
      visited[i] = true;
      dfs(i, cnt+1, cost+dist[a][i]);
      visited[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> x;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      cin >> dist[i][j];
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      for(int k=0; k<n; k++)
        if(dist[j][k]> dist[j][i]+dist[i][k])
          dist[j][k] = dist[j][i] + dist[i][k];
  }
  visited[x] = true;
  dfs(x, 1, 0);
  cout << result;
} 