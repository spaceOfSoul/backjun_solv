#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int n,k;
int step[100001];

void bfs(){
  deque<int> que;
  que.push_back(n);
  step[n] = 1;

  while(!que.empty()){
    int pos = que.front();
    que.pop_front();
    if( pos == k){
      return;
    }

    for(int i :{pos*2,pos-1,pos+1}){
      if(0 <= i && i<= 100000 && !step[i]){
        if(i == pos*2){
          que.push_front(i);
          step[i] = step[pos];
        }
        else{
          que.push_back(i);
          step[i] = step[pos] + 1;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> k;

  bfs();
  cout << step[k]-1 << "\n";
}