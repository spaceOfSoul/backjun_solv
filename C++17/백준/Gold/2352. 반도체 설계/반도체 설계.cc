#include <iostream> 
#include <vector>
using namespace std;

int n;
vector<int> connect;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  int a;
  for(int i=0; i<n; i++){
    cin >> a;
    if(connect.empty() || connect.back() < a){
      connect.push_back(a);
    }else{
      int ptr = lower_bound(connect.begin(), connect.end(), a) - connect.begin();
      connect[ptr] = a;
    }
  }
  cout << connect.size();
} 