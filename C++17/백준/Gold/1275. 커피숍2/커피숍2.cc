#include <iostream>
using namespace std;

int n,q;
long long arr[100000];
long long tree[400000];

long long init(int s, int end, int node){
  if(s==end)return tree[node] = arr[s];
  int mid = (s+end)/2;
  return tree[node] = init(s, mid, node*2)+ init(mid+1, end, node*2+1);
}

long long sum(int s, int end, int left,int right, int node){
  if(end<left || s>right)
    return 0;
  if(left <= s && right >= end)
    return tree[node];
  int mid = (s+end)/2;
  return sum(s,mid,left,right, node*2) + sum(mid+1,end,left,right,node*2+1);
}

void update(int s, int e, int node, int index, long long diff){
  if(index <= e && index >= s){
    tree[node] += diff;
    if(s == e)
      return;
    int mid = (s+e)/2;
    update(s,mid,node*2, index, diff);
    update(mid+1, e, node*2+1, index, diff);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> q;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  init(0, n-1,1);

  int x,y,a,b;
  for(int i=0; i<q; i++){
    cin >> x >> y >> a >> b;
    a--;
    if(x>y)
      cout << sum(0,n-1,y-1,x-1,1);
    else
      cout << sum(0,n-1,x-1,y-1,1);
    cout << "\n";
    long long dif = b-arr[a];
    arr[a] = b;
    update(0, n-1, 1, a, dif);
  }
} 