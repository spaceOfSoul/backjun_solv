#include <stdio.h>

int n, m;

int arr[100000];
int tree[400000];
int lazy[400000];

void propagation(int s, int e, int node) {
  if (lazy[node]) {
    if (s != e) {
      tree[node] = (e - s + 1) - tree[node];

      lazy[node * 2] = lazy[node * 2] ? 0 : 1;
      lazy[node * 2 + 1] = lazy[node * 2 + 1] ? 0 : 1;
    } else {
      tree[node] = !tree[node];
    }
    lazy[node] = 0;
  }
}

void update(int s, int e, int l, int r, int node) {
  propagation(s, e, node);

  if (e < l || r < s)
    return;
  if (l <= s && e <= r) {
    if (s != e) {
      tree[node] = (e - s + 1) - tree[node];
      lazy[node * 2] = lazy[node * 2] ? 0 : 1;
      lazy[node * 2 + 1] = lazy[node * 2 + 1] ? 0 : 1;
    } else {
      tree[node] = !tree[node];
    }
    return;
  }

  int mid = (s + e) / 2;
  update(s, mid, l, r, node * 2);
  update(mid + 1, e, l, r, node * 2 + 1);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int s, int e, int l, int r, int node) {
  propagation(s, e, node);

  if (l <= s && e <= r)
    return tree[node];

  if (e < l || r < s)
    return 0;

  int mid = (s + e) / 2;
  return query(s, mid, l, r, node * 2) + query(mid + 1, e, l, r, node * 2 + 1);
}

int main(void) {
  scanf("%d %d", &n, &m);

  int a, b, c;

  int o, s, t;
  while (m--) {
    scanf("%d %d %d", &o, &s, &t);
    s--;
    t--;
    if (o) { // o==1
      printf("%d\n", query(0, n - 1, s, t, 1));
    } else {
      update(0, n - 1, s, t, 1);
      // printf("%d\n", query(0, n - 1, s, t, 1));
    }
  }

  // printf("tree\n");
  // for (int i = 0; i < 4 * n; i++) {
  //   printf("%d\n", tree[i]);
  // }
  return 0;
}