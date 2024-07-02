#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<int> graph[1000];
int indegree[1000];
int result[1000];

void tSort(){
    queue<int> que;
    for(int i=0; i<n; i++){
        if(!indegree[i])
            que.push(i);
    }
    for(int k=0; k<n; k++){
        if(que.empty())
            break;

        int now = que.front();
        que.pop();

        if(!result[now])
          result[now] = 1;

        for(int i:graph[now]){
            indegree[i]--;
            if(!indegree[i]) {
                que.push(i);
                result[i] = result[now] + 1;
            }
        }
    }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;

  int a,b;

  for(int i=0; i<m; i++){
    cin >> a >> b;
    graph[a-1].push_back(b-1);
    indegree[b - 1]++;
  }

  tSort();

  for (int i = 0; i < n; i++) {
      cout << result[i] << " ";
  }
}