#include <stdio.h>
#define ll long long

ll arr[1000000];
ll tree[4000000];

int n,q;

void update(int s, int e, int node, int index, int dif){
  if(index <= e && index >= s){
    tree[node] += dif;
    if(s==e){
      return;
    }

    int mid = (s+e)/2;
    update(s,mid,node*2,index,dif);
    update(mid+1, e,node*2+1, index,dif);
  }
}

ll query(int s,int e,int node, int left, int right){
  if(left>e || right<s)
    return 0;
  if(left<=s && right >=e)
    return tree[node];

  int mid = (s+e)/2;
  return query(s,mid,node*2,left,right) + query(mid+1, e, node*2+1, left, right);
}

int main(void) {
  scanf("%d %d", &n, &q);
  int i,j,k;
  while(q--){
    scanf("%d %d %d",&i,&j,&k);
    if(i==1){
      update(0,n-1,1,j-1,k);
    }else{
      printf("%lld\n", query(0,n-1,1,j-1,k-1));
    }
  }
  return 0;
}