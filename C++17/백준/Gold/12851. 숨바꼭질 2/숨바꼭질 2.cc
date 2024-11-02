#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n,k;
bool step[100001];
int result;
int minDist;

void bfs(){
  queue<pair<int, int>> que;
  que.push({n,0});

  while(!que.empty()){
    int pos = que.front().first;
    int dist = que.front().second;
    que.pop();
    step[pos] = true;

    if(result && pos == k && dist == minDist)
      result++;

    if(!result && pos == k){
      minDist = dist;
      result++;
    }

    for(int i :{pos+1,pos-1, pos*2}){
      if(0 <= i && i<= 100000 && !step[i]){
        que.push({i,dist + 1});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> k;
  
  bfs();
  cout << minDist << "\n";
  cout << result;
}