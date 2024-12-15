#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n,k;
int step[100001][2];

void bfs(){
  queue<int> que;
  que.push(n);

  while(!que.empty()){
    int pos = que.front();
    que.pop();

    if(pos == k){
      return;
    }

    for(int i :{pos+1,pos-1, pos*2}){
      if(0 <= i && i<= 100000 && !step[i][0]){
        step[i][0] = step[pos][0] +1;
        step[i][1] = pos;
        que.push(i);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> k;
  
  bfs();
  cout << step[k][0] << "\n";
  stack<int> stk;
  stk.push(k);
  for(int i = k; i != n; ){
    stk.push(step[i][1]);
    i = step[i][1];
  }
  while(!stk.empty()){
    cout << stk.top() << " ";
    stk.pop();
  }
} 