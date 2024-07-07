#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

int t;
int n;
int arr[1000];

int main() {
  cin >> t;

  cout << t << "\n\n";
  while(t--){
    cin >> n;
    for(int i=0; i<n; i++)
      cin >> arr[i];

    sort(arr, arr + n);
    swap(arr[0], arr[1]);

    cout << n << "\n";
    for(int i=0; i<n; i++)
      cout << arr[i] << " ";
    
    cout << "\n";
  }
}