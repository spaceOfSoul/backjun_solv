#include <iostream>
#include <algorithm>
using namespace std;

int n;
int result;

int main() {
  int now, a;
  cin >> n;
  cin >> now;
  while(n--){
    cin >> a;
    result += min(min(abs(a-360)+now, abs(now-360)+a),abs(now-a));
    now=a;
  }
  cout << result;
} 