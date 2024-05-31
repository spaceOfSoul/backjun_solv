#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int tc;
vector<pair<pair<int, int>, int>> edges;
int dist[501];

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> tc;
  while(tc--){
    int n,m,w;
    edges.clear();
    cin >> n >> m >> w;
    for(int i =0; i< m; i++){
      int s,e,t;
      cin >> s >> e >> t;
      edges.push_back({{s,e},t});
      edges.push_back({{e,s},t});
    }
    for(int i=0; i<w; i++){
      int s,e,t;
      cin >> s >> e >> t;
      edges.push_back({{s,e},-t});
    }
    memset(dist, 999999999,sizeof(dist));

    dist[1] = 0;
    bool isCycle = false;
    for(int i=0; i<n; i++){
      for(pair<pair<int, int>, int> j: edges){
        int now = j.first.first;
        int nxt = j.first.second;
        int cost = j.second;
          if(dist[nxt]> dist[now] + cost){
            dist[nxt] = dist[now] + cost;
            if(i==n-1)
              isCycle = true;
          }
      }
    }
    for(pair<pair<int, int>, int> i:edges){
      int now = i.first.first;
      int nxt = i.first.second;
      int cost = i.second;
      if(dist[nxt] > dist[now]+cost){
        isCycle = true;
        break;
      }
    }
    if(isCycle)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }

} 