#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int to_num(char n){
  if('A' <= n && n <= 'Z')
    return n-'A'+10;
  return n-'0';
}

int main() {
  string n;
  int b;
  
  cin >> n >> b;

  int len = n.length();

  int result = 0;
  for(int i=1; i<=len; i++){
    result += to_num(n[i-1])*(int)pow(b, len-i);
  }

  cout << result;
}