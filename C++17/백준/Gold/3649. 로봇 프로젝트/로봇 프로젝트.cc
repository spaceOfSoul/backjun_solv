#include <iostream>
#include <algorithm>
using namespace std;

int x,n;
int arr[1000000];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  while(cin >> x){
    cin >> n;
    for(int i=0; i<n; i++)
      cin >> arr[i];
    sort(arr, arr+n);
    
    int start = 0;
    int end = n-1;
    int find = x*10000000;

    int first, second;
    bool danger = true;
    while(start < end){
      int sum = arr[start] + arr[end];
      int stan = abs(sum-find);

      if(stan ==0){
        first = arr[start];
        second = arr[end];
        danger = false;
        break;
      }
      
      if(sum < find){
        start++;
      }else{
        end--;        
      }
    }
    
    if(danger){
      cout << "danger\n";
    }else{
      cout << "yes " << first << " " << second << "\n";
    }
  }
} 