#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> listSize;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    if(listSize.empty() || listSize.back() < a){
      listSize.push_back(a);
    }else{
      int ptr = lower_bound(listSize.begin(), listSize.end(), a) - listSize.begin();
      listSize[ptr] = a;
    }
  }
  cout << n-listSize.size();
} 