#include <iostream>
using namespace std;

int n;
int arr[1000];
int dp[2][1000];
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  for(int i=0; i<n; i++){
    dp[0][i] = 1;
    for(int j=0; j<i; j++){
      if(arr[j] < arr[i] && dp[0][i] < dp[0][j] +1)
        dp[0][i] = dp[0][j] +1;
    }
  }

  for(int i=n-1; i>=0; i--){
    dp[1][i] = 1;
    for(int j = n-1; j>=i; j--){
      if(arr[j] < arr[i] && dp[1][i] < dp[1][j] +1)
        dp[1][i] = dp[1][j] +1;
    }
  }
  for(int i=0; i<n; i++){
    if(result < dp[0][i] + dp[1][i] - 1)
      result = dp[0][i] + dp[1][i] - 1;
  }
  cout << result;
} 