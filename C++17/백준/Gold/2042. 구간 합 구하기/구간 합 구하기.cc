#include <iostream>
#include <vector>
using namespace std;

int n,m,k;
long long arr[1000000];
long long tree[4000000];

long long init(int start, int end, int node){
  if(start==end) return tree[node] = arr[start];//끝임
  int mid = (start + end) / 2;
  return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}
//start, end 체크범위
//left, right 구간합 구할 범위 asdf
long long sum(int start, int end, int left, int right, int node){
  if(left > end || right < start)
    return 0;
  if(left <= start && right >= end)
    return tree[node];
    
  int mid = (start+end)/2;
  return sum(start, mid, left, right,node*2) + sum(mid+1, end, left, right, node*2+1);
}

void update(int start, int end, int node, int index, long long dif){
  if(index <= end && index >= start){
    tree[node] += dif;
    if(start==end){
      
      return; 
    }
    int mid = (start+end)/2;
    update(start, mid, node*2, index, dif);
    update(mid+1, end, node*2+1, index, dif);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >>n >> m >>k;
  for(int i=0; i<n; i++)
    cin >> arr[i];
  
  init(0,n-1,1);
  
  int a,b;
  long long c;
  for(int i=0; i<m+k; i++){
    cin >> a >> b >> c;
    b--;
    if(a == 1){
      long long dif = c-arr[b];
      arr[b] = c;
      update(0,n-1,1, b, dif);
    }else{
      cout << sum(0,n-1,b,c-1,1) << "\n";
    }
  }
} 