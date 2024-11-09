#include <iostream>
#include <algorithm>
using namespace std;

int n,s;
int arr[100000];
int result = 999999999;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> s;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  int sum = arr[0];
  int i=0;
  int j=0;
  while(i<=j && j<n){
    if(sum >= s){
      result = min(result, j-i+1);
      sum -= arr[i];
      i++;
    }else{
      sum += arr[++j];
    }
  }
  if(result == 999999999)
    cout << 0;
  else
    cout << result;
} 