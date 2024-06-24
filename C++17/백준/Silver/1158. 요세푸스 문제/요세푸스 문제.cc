#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n,k;
  vector<int> arr;
  
  cin >> n >> k;

  for(int i=1; i<=n; i++)
    arr.push_back(i);

  int query = 0;
  cout << "<";
  while (n) {
    query = (query+k-1) % n;
    cout << arr[query];
    arr.erase(arr.begin() + query);
    n--;
    if(n)
      cout << ", ";
  }
  cout << ">";
}