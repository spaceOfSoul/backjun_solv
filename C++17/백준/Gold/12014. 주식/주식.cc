#include <iostream>
#include <vector>
using namespace std;

int t,n,k,a;
vector<int> lis;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> t;
  for(int j=1; j<=t; j++){
    cin >> n >> k;
    for(int i=0; i<n; i++){
      cin >> a;
      if(lis.empty()||lis.back() < a){
        lis.push_back(a); 
      }else{
        int ptr = lower_bound(lis.begin(), lis.end(), a) - lis.begin();
        lis[ptr] = a;
      }
    }

    cout << "Case #" << j << "\n";
    if(lis.size()>=k){
      cout << 1 << "\n";
    }else{
      cout << 0 << "\n";
    }
    lis.clear();
  }
} 