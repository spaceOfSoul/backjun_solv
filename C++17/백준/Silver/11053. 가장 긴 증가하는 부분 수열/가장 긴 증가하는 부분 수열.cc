#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int,int> arr[1000];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i].first;
    arr[i].second = 1;
  }
  int result = 1;
  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
      if(arr[j].first < arr[i].first){
        arr[i].second = max(arr[j].second+1, arr[i].second);
      }
    }
    result = max(result, arr[i].second);
  }
  cout << result;
} 