#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[17];
int dp[17];

int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=1; i<=n; i++)
    cin >> arr[i].first >> arr[i].second;

  for(int i=1; i<=n+1; i++){
    for(int j=1; j<=i;j++){
      dp[i] = max(dp[i], dp[j]);
      if(j+arr[j].first <= i){
        dp[i] = max(dp[i], arr[j].second+dp[j]);
      }
    }
    result = max(dp[i],result);
  }
  cout << result;
} 