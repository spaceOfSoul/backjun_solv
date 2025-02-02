#include <iostream>
#include <deque>
#include <string>
using namespace std;

int n;
deque<int> que;
string commend;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  while(n--){
    cin >> commend;
    if(commend=="push"){
      int x; cin >> x;
      que.push_back(x);
    }else if(commend=="pop"){
      if(!que.empty()){
        cout << que.front() << "\n";
        que.pop_front();
      }else
        cout << "-1\n";
    }else if(commend=="size"){
      cout << que.size() << "\n";
    }else if(commend=="empty"){
      if(que.empty())
       cout << "1\n";
      else
        cout << "0\n";
    }else if(commend=="front"){
      if(!que.empty())
        cout << que.front() << "\n";
      else
        cout << "-1\n";
    }else if(commend=="back"){
      if(!que.empty())
        cout << que.back() << "\n";
      else
        cout << "-1\n";
    }
  }
}