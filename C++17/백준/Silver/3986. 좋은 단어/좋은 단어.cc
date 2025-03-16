#include <iostream>
#include <stack>
#include <string>
using namespace std;
int n, result;

string word;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  while(n--){
    cin >> word;
    
    stack<char> stk;
    int size = word.size();
    for(int i=0; i<size; i++){
      char tmp = word[i];
      if(stk.empty()){
        stk.push(tmp);
        continue;
      } 

      if(stk.top() == tmp)stk.pop();
      else if(stk.top() != tmp) stk.push(tmp);
    }

    if(stk.empty()) result++;
  }
  cout << result;
}
