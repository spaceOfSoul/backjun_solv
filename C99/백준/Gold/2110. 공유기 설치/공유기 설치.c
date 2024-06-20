#include <stdio.h>

int n, c;
int houses[200000];
int result;

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

int main() {
  scanf("%d %d", &n, &c);

  for (int i = 0; i < n; i++) {
    scanf("%d", houses + i);
  }
  sort(houses, 0, n - 1);

  int start = 1;
  int end = houses[n - 1] - houses[0];
  int mid;
  int point;
  int count;
  while (start <= end) {
    mid = (start + end) / 2;
    point = houses[0];
    count = 1;

    for (int i = 1; i < n; i++) {
      if (houses[i] >= mid + point) {
        point = houses[i];
        count++;
      }
    }

    if (count >= c) {
      start = mid + 1;
      result = mid;
    } else
      end = mid - 1;
  }
  printf("%d", result);
}