#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, d, c;
int dist[10001];
int visited, cSum;
vector<pair<int, int>> graph[10001];

void djs(int start){
  dist[start] = 0;
  priority_queue<pair<int, int>> que;
  que.push({0,start});

  while(!que.empty()){
    int now = que.top().second;
    int distant = -que.top().first;
    que.pop();

    if(dist[now] < distant)
      continue;
    visited++;
    for(auto i: graph[now]){
      int next = i.first;
      int nxtCost = i.second;
      if(dist[next] > nxtCost+distant){
        dist[next] = nxtCost+distant;
        que.push({-dist[next], next});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> t;
  while(t--){
    cSum = 0; visited =0;
    cin >> n >> d >> c;
    for(int i=1; i<=n; i++){
      dist[i] = 999999999;
    }
    for(int i=0; i<d; i++){
      int a,b,time;
      cin >> a >> b >> time;
      graph[b].push_back({a,time});
    }
    djs(c);
    for(int i=1; i<=n; i++){
      if(dist[i] != 999999999){
        if(cSum < dist[i])
          cSum = dist[i];
      }
    }
    cout << visited<< " " << cSum << "\n";
    for(int i=1; i<=n; i++){
      graph[i].clear();
    }
  }
} 