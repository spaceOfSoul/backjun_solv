#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> stk;
string foland;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  cin >> foland;

  for(int i = 0; i< size(foland);i++){
    if(foland[i] >= 'A' && foland[i] <= 'Z')
      cout << foland[i];
    else {
      if(foland[i] == '('){
        stk.push(foland[i]);
      }else if(foland[i] == ')'){
        while(stk.top() != '('){
          cout << stk.top();
          stk.pop();
        }
        stk.pop();
      }else if(foland[i] == '*' || foland[i] == '/'){
        if(!stk.empty() && (stk.top() == '*' || stk.top() == '/')){ 
          cout << stk.top();
          stk.pop();
        }
        stk.push(foland[i]);
      }else{//+-
        while(!stk.empty() && stk.top() != '('){
          cout << stk.top();
          stk.pop();
        }
        stk.push(foland[i]);
      }
    }
  }
  while(!stk.empty()){
    cout<<stk.top();
    stk.pop();
  }
}