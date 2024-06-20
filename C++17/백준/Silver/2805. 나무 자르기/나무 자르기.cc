#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> trees;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  int a;
  for(int i=0; i<n; i++){
    cin >> a;
    trees.push_back(a);
  }
  sort(trees.begin(), trees.end());

  unsigned int left = 0;
  unsigned int right = trees[n-1];
  unsigned int mid;
  unsigned int result = 0;
  unsigned int woods;
  while(left <= right){
    woods = 0;
    mid = (left+right)/2;
    for(int i=0; i<n; i++){
      if(trees[i] > mid)
        woods += (trees[i]-mid);
      if(woods >= m) break;
    }
    if(woods < m){
      right = mid-1;
    }else{
      left  = mid +1;
      result = max(result, mid);
    }
  }
  cout << result;
}