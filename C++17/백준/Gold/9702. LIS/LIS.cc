#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> t;

  int arr[500];
  
  for(int k = 1;k<=t;k++){
    cin >> n;
    for(int i=0; i<n; i++)
      cin >> arr[i];

    int total = 0;
    for(int i=0; i<n; i++ ){
      vector<int> lis;
      for(int j=i; j<n; j++){
        if(lis.empty() || lis.back() < arr[j])
          lis.push_back(arr[j]);
        else{
          int ptr = lower_bound(lis.begin(), lis.end(), arr[j]) - lis.begin();
          lis[ptr] = arr[j];
        }
        total += lis.size();
      }
    }

    cout << "Case #"<< k << ": " << total << "\n";
  }
}