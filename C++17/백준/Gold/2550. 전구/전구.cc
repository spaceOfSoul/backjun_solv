#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n,a;
int arr[10001];
int index[10001];
int connect[10001];
vector<int> result;

vector<pair<int, int>> trace;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a;
    index[a] = i;
    arr[i] = a;
  }
  for(int i=0; i<n; i++){
    cin >> a;
    connect[i] = index[a];
  }

  for(int i=0; i<n; i++){
    a = connect[i];
    if(result.empty() || result.back()<a){
      result.push_back(a);
      trace.push_back({result.size(), a});
    }else{
      int ptr = lower_bound(result.begin(), result.end(), a) - result.begin();
      result[ptr] = a;
      trace.push_back({ptr+1,a});
    }
  }
  int size = result.size();
  cout << size << "\n";

  vector<int> answer;

  for(int i = trace.size() - 1; i>=0; i--){
    if(trace[i].first == size){
      answer.push_back(arr[trace[i].second]);
      size--;
    }
  }
  sort(answer.begin(), answer.end());
  for(int i:answer){
    cout << i << " ";
  }
} 