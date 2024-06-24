#include <iostream>
#include <queue>
using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n,k;
  queue<int> que;
  
  cin >> n >> k;

  for(int i=1; i<=n; i++)
    que.push(i);

  int tmp;
  cout << "<";
  while(n-- != 1){
    for(int j=0; j<k-1; j++){
      tmp = que.front();
      que.pop();
      que.push(tmp);
    }

    cout << que.front() << ", ";
    que.pop();
  }
  cout << que.front() << ">";
}