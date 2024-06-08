#include <iostream>
#include <vector>
#include <queue>
#define inf 999999999
using namespace std;

int n,e,s;
vector<pair<int, int>> graph[20000];
int dist[20000];

void djs(){
  priority_queue<pair<int, int>> que;//distance,vertex
  que.push({0,s});
  dist[s] = 0;

  while(!que.empty()){
    pair<int, int> now = que.top();//distance,vertex
    que.pop();

    if(dist[now.second] < -now.first)
        continue;

    for(pair<int, int> i : graph[now.second]){//i is graph(v,w)
      int cost = -now.first+i.second;//will be distance
      if(cost < dist[i.first]){
        dist[i.first] = cost;
        que.push({-cost, i.first});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> e;
  cin >> s;
  s--;
  for(int i=0; i<n; i++)
    dist[i] = inf;
  
  int u,v,w;
  for(int i=0;i<e;i++){
    cin >> u >> v >> w;
    u--;v--;
    graph[u].push_back({v,w});
  }
  djs();
  for(int i=0;i<n; i++){
    if(i==s){
      cout << 0;
    }else if(dist[i] == inf){
      cout << "INF";
    }else{
      cout << dist[i];
    }
    cout << "\n";
  }
}