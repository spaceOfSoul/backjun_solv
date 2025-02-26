#include <iostream>
#include <vector>
#include <queue>
using namespace  std;

int n, k, goal;

int buildTime[1000];//each other original
int indegree[1000];
long long int totalTime[1000];//total

int sortGraph(vector<int> graph[]){
  queue<int> que;
  for(int i = 0; i<n; i++){
    if(indegree[i] == 0){
      que.push(i);
      totalTime[i] = buildTime[i];
    }
  }

  while(!que.empty()){
    int now = que.front();
    que.pop();

    for(int nxt:graph[now]){
      indegree[nxt]--;
      if(totalTime[nxt] < totalTime[now]+buildTime[nxt])
        totalTime[nxt] = totalTime[now] + buildTime[nxt];
      if(indegree[nxt] == 0)
        que.push(nxt);
        
    }
  }
  return totalTime[goal];
}

int main() {
ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  
  cin >> t;
  while(t--){
    cin >> n >> k;
    vector<int> graph[1000];
    for(int i=0; i<n; i++){
      cin >> buildTime[i];
      indegree[i] = 0;
      totalTime[i] = 0;
    }
    for(int i=0; i<k; i++){
      int a,b;
      
      cin >> a >> b;
      graph[a-1].push_back(b-1);
      indegree[b-1]++;
    }
    cin >> goal;
    goal--;

    cout << sortGraph(graph) << "\n";
  }
}