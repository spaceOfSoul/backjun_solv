#include <iostream>
#include <algorithm>
using namespace std;

int bag[100001];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n,k;
  cin >> n >> k;
  
  int v[100]; 
  int w[100];

  for(int i = 0; i <n; i++){
    cin >> w[i] >> v[i];
  }

  for(int i =0; i<n; i++){
    for(int j = k; j>=1; j--){
      if(w[i] <= j)
        bag[j] = max( bag[j], bag[j - w[i] ] + v[i]);
    }
  }
  cout << bag[k];
}