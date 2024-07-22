#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
  int n,q;
  cin >> n >> q;

  cin >> str;

  int command, l, r;

  while(q--){
    cin >> command >> l >> r;
    l--;
    r--;
    if(command == 1 ){
      int count = 0;
      char tmp = ' ';
      for(int i=l; i<=r; i++){
        if(tmp != str[i]){
          count++;
          tmp = str[i];
        }
      }
      cout << count << "\n";
    }else{
      for(int i=l; i<=r; i++){
        str[i]++;
        if(str[i] > 'Z')
          str[i] = 'A';
      }
    }
  }
}