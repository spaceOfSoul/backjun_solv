#include <iostream>
#include <vector>
using namespace std;

int n,a;
int arr[100001];
int index[100001];
vector<int> result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> a;
    index[a] = i;
  }
  for(int i=1; i<=n; i++){
    cin >> a;
    arr[i] = index[a];
  }
  for(int i=1; i<= n; i++){
    a=arr[i];
    if(result.empty() || result.back() < a){
      result.push_back(a);
    }else{
      int ptr = lower_bound(result.begin(), result.end(), a) - result.begin();
      result[ptr] = a;
    }
  }
  cout << result.size();
} 