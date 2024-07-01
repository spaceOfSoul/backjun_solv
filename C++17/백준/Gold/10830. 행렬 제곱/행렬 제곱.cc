#include <iostream>
using namespace std;

int n;
long long b;
long long arr[5][5];
long long result[5][5];

void matrixMulti(long long a[5][5], long long b[5][5]){
  long long tmp[5][5];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      tmp[i][j] = 0;
      for(int k=0; k<n; k++)
        tmp[i][j] += (a[i][k] * b[k][j]);
      tmp[i][j] %= 1000;
    }
  }

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      a[i][j] = tmp[i][j];
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> b;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      cin >> arr[i][j];
    result[i][i] = 1;
  }
  while(b > 0){
    if(b%2 == 1)
      matrixMulti(result, arr);
    matrixMulti(arr, arr);
    b /= 2;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      cout << result[i][j] << " ";
    cout << "\n";
  }
} 