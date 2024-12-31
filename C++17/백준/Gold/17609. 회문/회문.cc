#include <iostream>
#include <string>
using namespace std;

int n;
string str;

int ispel(int a,int b, bool erase){
  while(a<=b){
    if(str[a] != str[b]){
      if(erase)
        return 2;
      else{
        if(!ispel(a+1,b,true)||!ispel(a,b-1,true))
          return 1;
        
        return 2;
        }
      }
    a++;b--;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  while(n--){
    cin >> str;
    
    cout << ispel(0,str.size()-1,false)<<"\n";
  }
}