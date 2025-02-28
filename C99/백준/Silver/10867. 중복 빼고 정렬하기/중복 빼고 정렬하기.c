#include <stdio.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(int *arr, int left, int right) {
  int pl = left;
  int pr = right;

  int mid = arr[(left + right) / 2];

  while (pl <= pr) {
    while (arr[pl] < mid)
      pl++;
    while (arr[pr] > mid)
      pr--;

    if (pl <= pr) {
      swap(arr + pl, arr + pr);
      pl++;
      pr--;
    }
  }
  if (left < pr)
    sort(arr, left, pr);
  if (pl < right)
    sort(arr, pl, right);
}

int main(void) {
  int n;
  int arr[100000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", arr + i);
  sort(arr, 0, n - 1);

  int tmp = -1;
  for (int i = 0; i < n; i++) {
    if (tmp != arr[i]) {
      printf("%d ", arr[i]);
      tmp = arr[i];
    }
  }
  return 0;
}