#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

uint8_t num[6];
uint8_t visited[6];
int max_digit = 0;
int result=9999999;
int x;

void min_max(int depth, int val){
  if(depth == max_digit){
    if(val > x && val < result)
      result = val;
    return;
  }

  // cout << "called \n";

  for(int i=0; i<max_digit; i++){
    if(visited[i])
      continue;

    visited[i] = 1;
    min_max(depth + 1, val*10 + num[i]);
    visited[i] = 0;
  }
}

int main() {
  cin >> x;
  
  int tmp = x;
  int idx = 0;
  while(tmp >0){
    num[idx++] = tmp%10;
    tmp/=10;
  }
  max_digit = idx;

  sort(num, num+max_digit);
  
  min_max(0, 0);

  if(result == 9999999)
    result = 0;
  cout << result;
}