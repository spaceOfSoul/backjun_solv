#include <stdio.h>

int tree[2000000];
int arr[500000];

int n, m;

void init(int s, int e, int node) {
  if (s == e) {
    tree[node] = arr[s];
    return;
  }

  int mid = (s + e) / 2;
  init(s, mid, node * 2);
  init(mid + 1, e, node * 2 + 1);
}

void update(int s, int e, int node, int l, int r, int val) {
  if (e < l || r < s)
    return;
  if (l <= s && e <= r) {
    tree[node] ^= val;
    return;
  }

  int mid = (s + e) / 2;
  update(s, mid, node * 2, l, r, val);
  update(mid + 1, e, node * 2 + 1, l, r, val);
}

int query(int s, int e, int node, int index, int pv) {
  if (s <= index && index <= e) {
    pv ^= tree[node];
    if (s == e)
      return pv;
    int mid = (s + e) / 2;
    return query(s, mid, node * 2, index, pv) ^
           query(mid + 1, e, node * 2 + 1, index, pv);
  }
  return 0;
}

int main(void) {
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d", arr + i);

  init(0, n - 1, 1);

  scanf("%d", &m);

  int q, l, r, k;
  while (m--) {
    scanf("%d", &q);
    if (q == 2) {
      scanf("%d", &l);
      printf("%d\n", query(0, n - 1, 1, l, 0));
    } else {
      scanf("%d %d %d", &l, &r, &k);

      if (l > r) {
        int tmp = l;
        l = r;
        r = tmp;
      }

      update(0, n - 1, 1, l, r, k);
    }
  }
  return 0;
}