#include <iostream>
#include <algorithm>
using namespace std;

int n, x, y;
pair<int, int> arr[1000000];
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i].first >> arr[i].second;

  sort(arr, arr+n);

  int left = arr[0].first;
  int right = arr[0].second;

  for(int i=1; i<n; i++){
    x = arr[i].first;
    y = arr[i].second;
    if(right < x){
      result += right-left;
      right = y;
      left = x;
    }else{
      right = max(right, y);
    }
  }
  result += right-left;
  cout << result;
} 