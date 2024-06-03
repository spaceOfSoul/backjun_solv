#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];
int tree[400000];
int n,m;

int init(int start, int end, int node){
  if(start == end)
    return tree[node] = start;
  int mid = (start + end)/2;
  int li = init(start, mid, node*2);
  int ri = init(mid+1, end, node*2+1);
  if(arr[li] > arr[ri])
    return tree[node] = ri;
  else
    return tree[node]= li;
  
}

int update(int s, int e, int index, int node){
  if(index < s || index > e)
    return tree[node];
  if(s == e)
    return tree[node] = e;
  int mid = (s+e)/2;
  int li = update(s, mid, index, node*2);
  int ri = update(mid+1, e, index, node*2+1);

  if(arr[ri] < arr[li]){
    return tree[node] = ri;
  }else{
    return tree[node] = li;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  init(0,n-1,1);
  cin >> m;
  int a,b,c;
  while(m--){
    cin >> a;
    if(a==1){
      cin >> b >> c;
      b--;
      arr[b] = c;
      update(0,n-1,b,1);
    }else{
      cout << tree[1]+1 << "\n";
    }
  }
} 