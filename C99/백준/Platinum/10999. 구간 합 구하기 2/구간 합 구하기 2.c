#include <stdio.h>
#define ll long long

int n,m,k;
ll arr[1000000];
ll tree[4000000];
ll lazy[4000000];

ll init(int s, int e, int node){
  if(s==e)
    return tree[node] = arr[s];
  int mid = (s+e)/2;
  return tree[node]=init(s,mid,node*2) + init(mid+1,e,node*2+1);
}

void update(int s, int e, int left, int right, int node, ll dif){
  if(lazy[node]){
    tree[node] += lazy[node]*(e-s+1);
    if(s!=e){
      lazy[node*2] += lazy[node];
      lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
  }
  
  if(e<left || right<s)
    return;
  
  if(left<=s&&e<=right){
    tree[node]+=(dif*(e-s+1));
    if(s!= e){
      lazy[node*2]+=dif;
      lazy[node*2+1]+=dif;
    }
    return;
  }

  int mid = (s+e)/2;
  update(s, mid, left, right, node*2, dif);
  update(mid+1, e, left, right, node*2+1, dif);
  tree[node] = tree[node*2]+tree[node*2+1];
  return;
}

ll query(int s, int e, int left, int right, int node){  
  if(lazy[node]){
    tree[node] += (e-s+1)*lazy[node];
    if(s!=e){
      lazy[node*2] += lazy[node];
      lazy[node*2+1] += lazy[node];
    }
    lazy[node]=0;
  }
  
  if(e<left || right < s)
    return 0;
  if(left <= s && e<=right)
    return tree[node];
  
  int mid = (s+e)/2;
  return query(s,mid,left,right,node*2) + query(mid+1, e, left, right, node*2+1);
}

int main(void) {
  scanf("%d %d %d",&n,&m,&k);
  for(int i=0; i<n; i++){
    scanf("%lld",arr+i);
  }
  init(0,n-1,1);
  
  int t = m+k, a;
  ll b,c,d;
  while(t--){
    scanf("%d %lld %lld",&a,&b,&c);
    if(a==1){
      scanf("%lld",&d);
      update(0,n-1, b-1, c-1, 1, d);
    }else{
      printf("%lld\n", query(0,n-1,b-1,c-1,1));
    }
  }
  return 0;
}