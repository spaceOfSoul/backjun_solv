#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,p;
int d[400];
int capacity[400][400];
int flow[400][400];
vector<int> graph[400];
int result;

void maxflow(){
  while(true){
    fill(d,d+n,-1);
    queue<int> que;
    que.push(0);

    while(!que.empty()){
      int x = que.front();
      que.pop();

      for(int i:graph[x]){
        if(capacity[x][i] - flow[x][i] > 0 && d[i] == -1){
          que.push(i);
          d[i] = x;
          if(i==1)
            break;
        }
      }
    }
    if(d[1] == -1)
      break;
    for(int i=1; i!=0; i=d[i]){
      flow[d[i]][i]++;
      flow[i][d[i]]--;
    }
    result++;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> p;
  int a,b;
  while(p--){
    cin >> a >> b;
    a--;b--;
    capacity[a][b] = 1;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  maxflow();
  cout << result;
} 