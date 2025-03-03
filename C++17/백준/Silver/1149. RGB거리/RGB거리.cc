#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001][3];
int cach[1001][3];

int main() {
  ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }

  for(int i=1; i<=n; i++){
    cach[i][0] = arr[i][0] + min(cach[i-1][1], cach[i-1][2]);
    cach[i][1] = arr[i][1] + min(cach[i-1][0], cach[i-1][2]);
    cach[i][2] = arr[i][2] + min(cach[i-1][1], cach[i-1][0]);
  }
  cout << min(cach[n][0],min(cach[n][1], cach[n][2]));
} 