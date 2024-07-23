#include <stdio.h>
#define ll long long

ll arr[100000];
ll tree[400000];
int n,m;

void init(int start, int end, int node){
  if(start == end){
    tree[node] = arr[start];
    return;
  }

  int mid = (start+end)/2;
  init(start,mid,node*2);
  init(mid+1,end, node*2+1);
}

void update(int start, int end, int node, int left, int right, int dif){
  if(left>end || right < start)
    return;//out of range
  if(left<=start && end<=right){
    tree[node] += dif; 
    return;
  }
  int mid = (start+end)/2;

  update(start, mid, node*2, left, right, dif);
  update(mid+1,end,node*2+1, left, right, dif);
}

ll getVal(int start, int end, int node, int index, ll val){
  if(start<= index && index<=end){
    val+=tree[node];
    if(start == end)
      return val;
    int mid = (start+end)/2;
    return getVal(start,mid,node*2,index,val)
      +getVal(mid+1, end, node*2+1,index, val);
  }
  return 0;
}

int main(void) {
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%lld", arr+i);
  }
  
  init(0,n-1,1);
  
  scanf("%d", &m);
  int q,i,j,k;
  while(m--){
    scanf("%d", &q);
    if(q == 1){
      scanf("%d %d %d", &i, &j, &k);
      update(0,n-1,1,i-1,j-1,k);
    }else{
      scanf("%d", &i);
      printf("%lld\n", getVal(0,n-1,1,i-1,0));
    }
  }
  return 0;
}