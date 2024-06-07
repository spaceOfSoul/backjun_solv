#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000];
int result = 2000000222;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  sort(arr, arr+n);

  int i=0;
  int j=n-1;
  int first, second;

  while(i < j){
    int sum = arr[i]+arr[j];
    int stan = abs(sum);

    if(result>stan){
      result = stan;
      first = arr[i];
      second = arr[j];
    }
    if(sum <=0){
      i++;
    }else{
      j--;
    }
  }
  cout << first << " " << second;
} 