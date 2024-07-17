#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[50];

int result;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for(int i=0; i<n; i++)
    cin >> arr[i];

  sort(arr, arr+n, greater<int>());

  vector<int> minus;
  vector<int> plus;
  int zeros = 0;
  
  int i;
  for( i=0; i<n; i++){
    if(arr[i] <0){
      minus.push_back(arr[i]);
    }else if(arr[i] > 0){
      plus.push_back(arr[i]);
    }else
      zeros++;
  }
  
  vector<int> bindings;
  // 양수 처리
  int tmp_plus = 0;
  for(int num : plus){
    if(!tmp_plus){
        tmp_plus = num;
      continue;
    }
    if(tmp_plus*num > tmp_plus+num){
      bindings.push_back(tmp_plus*num);
      tmp_plus = 0;
    }else{ // 곱한게 더 작으면 손해임. 따로 넣는게 이득
      bindings.push_back(tmp_plus);
      bindings.push_back(num);
      tmp_plus = 0;
    }
  }

  sort(minus.begin(), minus.end());
  // 음수 처리
  int tmp_minus = 0;
  for(int num : minus){
    if(!tmp_minus){
        tmp_minus = num;
      continue;
    }
    bindings.push_back(tmp_minus*num);
      tmp_minus = 0;
  }

  // 음수랑 0 남으면
  if(tmp_minus && zeros)
    bindings.push_back(0);
  else // 아니면 그대로 넣어야 함.
    bindings.push_back(tmp_minus);
  
  if(tmp_plus)
    bindings.push_back(tmp_plus);

  for(int num : bindings){
    result += num;
  }

  cout << result;
}