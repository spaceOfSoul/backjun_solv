#include <iostream>
using namespace std;

int t,n;
bool visited[100001];
int hopes[100001];
bool turnOut[100001];
int gotTeam;

void dfs(int a){
  visited[a] = true;
  int next = hopes[a];
  if(!visited[next]){
    dfs(next);
  }else{
    if(!turnOut[next]){
      for(int i=next; i!=a; i=hopes[i])
        gotTeam++;
      gotTeam++;
    }
  }
  turnOut[a] = true;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> t;
  while(t--){
    cin >> n;
    for(int i=1; i<=n; i++){
      cin >> hopes[i];
      turnOut[i] = false;
      visited[i] = false;
    }

    for(int i=1; i<=n; i++){
      if(!visited[i])
        dfs(i);
    }
    cout << n-gotTeam << "\n";
    gotTeam = 0;
  }
} 