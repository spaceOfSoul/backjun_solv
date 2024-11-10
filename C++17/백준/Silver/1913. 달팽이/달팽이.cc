#include <iostream>
using namespace std;

int n, find_num;
int arr[999][999];

int r, c;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin >> find_num;

  int x, y, nn;
  r = c = x = y = n / 2;
  arr[x][y] = 1;
  nn = n * n;
  int count = 1;
  int i = 0;   // direction
  int nub = 1; // nuby
  int change_nub = 0;
  while (n < nn - count) {
    for (int j = 0; j < nub; j++) {
      count++;

      x += dx[i];
      y += dy[i];

      if (find_num == count) {
        r = x;
        c = y;
      }
      arr[x][y] = count;
    }

    i++;
    if (i == 4)
      i = 0;
    change_nub++;
    if (change_nub == 2) {
      change_nub = 0;
      nub++;
    }
  }
  nub--;
  for (int k = 0; k < nub; k++) {
    count++;
    x += dx[i];
    y += dy[i];

    if (find_num == count) {
      r = x;
      c = y;
    }
    arr[x][y] = count;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
  cout << r + 1 << " " << c + 1;
}