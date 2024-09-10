#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int v;
vector<pair<int, int>> tree[100000];
int maxLenth;
int stan;
bool visited[100000];

void dfs(int start, int nowDist){
  if(visited[start])
    return;
  visited[start] = true;
  if(nowDist>maxLenth){
    maxLenth = nowDist;
    stan = start;
  }
  for(pair<int, int> i:tree[start]){
    dfs(i.first, i.second+nowDist);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> v;

  for(int i = 0; i<v; i++){
    int vertex;
    cin >> vertex;
    while(true){
      int a,dist;
      cin >> a;
      if(a == -1)
        break;
      cin >> dist;
      tree[vertex-1].push_back({a-1, dist});
      tree[a-1].push_back({vertex-1, dist});
    }
  }
  dfs(0,0);
  maxLenth = 0;
  memset(visited, false, sizeof(visited));
  dfs(stan,0);
  cout << maxLenth;
} 