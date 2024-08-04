#include <iostream>
using namespace std;

int t;
int k, n;
int arr[15][15];
// int maxn = -1;

// int max(int a, int b) {
//   if (a > b)
//     return a;
//   return b;
// }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 1; i <= 14; i++)
    arr[0][i] = i;

  for (int i = 1; i <= 14; i++) {
    for (int j = 1; j <= 14; j++) {
      arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    }
  }

  cin >> t;
  while (t--) {
    cin >> k;
    cin >> n;

    cout << arr[k][n] << "\n";
  }
}