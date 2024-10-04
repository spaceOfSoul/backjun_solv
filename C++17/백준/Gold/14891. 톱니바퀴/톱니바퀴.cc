#include <iostream>
#include <deque>
#include <cmath>
#include <string>
using namespace std;

deque<int> topni[4];
int k;
int result;

void rotate(int a, int b){
  int tmp;
  if(b == -1){
      tmp = topni[a].front();
      topni[a].pop_front();
      topni[a].push_back(tmp);
    }else{
      tmp = topni[a].back();
      topni[a].pop_back();
      topni[a].push_front(tmp);
    }
}

void leftCheck(int left, int right, int rd){
  if(left == -1)
    return;
  if(topni[left][2] != topni[right][6]){
    leftCheck(left-1, left, -rd);
    rotate(left,-rd);
  }
}

void rightCheck(int left, int right, int rd){
  if(right == 4)
    return;
  if(topni[left][2] != topni[right][6]){
    rightCheck(right, right+1, -rd);
    rotate(right,-rd);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  for(int i=0; i<4; i++){
    for(int j=0; j<8; j++){
      char a;cin >> a;
      topni[i].push_back(a-'0');
    }
  }

  cin >> k;
  
  while(k--){
    int a,b;
    cin >> a >> b;
    leftCheck(a-2,a-1,b);
    rightCheck(a-1,a,b);
    rotate(a-1,b);
  }

  for(int i=0; i<4; i++){
    result += topni[i][0] * (int)pow(2,i);
  }
  
  cout << result;
} 