#include <iostream>
#define namor 1000000007;
using namespace std;

int n,m,k;
long long arr[1000000];
long long tree[4000000];

long long init(int start,int end, int node){
  if(start == end)
    return tree[node] = arr[start];
  int mid = (start+end)/2;
  return tree[node] = (init(start, mid, node*2) * init(mid + 1, end, node*2+1)) % namor;
}

long long multi(int start, int end, int left, int right, int node){
  if(end < left || start > right)
    return 1;
  if(start >= left && end <= right)
    return tree[node];
  
  int mid = (start+end)/2;

  return (multi(start,mid,left,right,node*2) * multi(mid+1,end,left,right,node*2+1))% namor;
}

long long update(int start, int end, int index, int node, int num){
  if(index > end || index < start)
    return tree[node];
  if(start == end)
    return tree[node] = num;

  int mid = (start+end)/2;
  return  tree[node] = (update(start,mid,index,node*2,num) * update(mid+1,end,index, node*2+1,num))%namor;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m >> k;
  for(int i=0; i<n; i++)
    cin >> arr[i];

  init(0,n-1,1);
  
  int a,b;
  long long c;
  for(int i=0; i<m+k; i++){
    cin >> a >> b >> c;
    b--;
    if(a == 1){
      arr[b]=c;
      update(0,n-1,b,1,c);
    }else{
      c--;
      cout << multi(0,n-1,b,c,1) << "\n";
    }
  }
} 