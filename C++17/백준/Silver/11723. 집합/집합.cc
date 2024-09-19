#include <iostream>
#include <sstream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  bool s[20] = {false,};
  int n;
  cin >> n;

  int count = 0;
  string commend;
  int number;
  for (int i = 0;i < n; i++){
    cin >> commend;
    if(commend == "add"){
      cin >> number;
      s[number - 1] = true;
    }else if(commend == "remove"){
      cin >> number;
      s[number - 1] = false;
    }else if(commend == "check"){
      cin >> number;
      if(s[number - 1]){
        cout << 1 << "\n";
      }else
        cout << 0 << "\n";
    }else if(commend == "toggle"){
      cin >> number;
      if(s[number-1]){
        s[number-1] = false;
      }else
        s[number-1] = true;
    }else if(commend == "all"){
      fill_n(s,20,true);
    }else if(commend == "empty"){
      fill_n(s,20,false);
    }
  }
}