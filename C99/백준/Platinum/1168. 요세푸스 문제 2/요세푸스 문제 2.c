#include <stdio.h>

int n, k;
int tree[4000000];

int init(int s, int e, int node) {
  if (s == e)
    return tree[node] = 1;
  int mid = (s + e) / 2;
  return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

int pop(int s, int e, int index, int node) {
  tree[node]--;
  if (s == e)
    return s;
  int mid = (s + e) / 2;
  if (tree[node * 2] >= index)
    return pop(s, mid, index, node * 2);
  else
    return pop(mid + 1, e, index - tree[node * 2], node * 2 + 1);
}

int main(void) {
  scanf("%d %d", &n, &k);
  init(1, n, 1);

  printf("<");
  int query = k;
  int count = 0;
  int size = n;
  while (count < n) {
    count++;

    // printf("%d %d\n", query, size);
    printf("%d", pop(1, n, query, 1));
    size--;
    if (size)
      printf(", ");
    query += (k - 1);
    if (size)
      query %= size;
    if (!query)
      query = size;
  }
  printf(">");
  return 0;
}