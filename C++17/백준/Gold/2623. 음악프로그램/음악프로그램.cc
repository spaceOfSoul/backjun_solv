#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<int> graph[1001];
int indegree[1001];
int result[1000];

bool tSort(){
  queue<int> que;
  for(int i=1; i<=n; i++){
    if(!indegree[i])
      que.push(i);
  }
  for(int k=0; k<n; k++){
    if(que.empty())
      return false;

    int now = que.front();
    que.pop();

    result[k] = now;
    
    for(int i:graph[now]){
      indegree[i]--;
      if(!indegree[i])
        que.push(i);
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a; cin >> a;
    int prev = 0;
    for(int j=0; j<a; j++){
      int b; cin >> b;
      if(!prev)
        prev = b;
      else{
        indegree[b]++;
        graph[prev].push_back(b);
        prev = b;
      }
    }
  }
  if(!tSort()){
    cout << 0;
  }else{
    for(int i=0; i<n; i++){
      cout << result[i] << "\n";
    }
  }
  
} 