#include <stdio.h>

int main() {
  char str[1001];
  int index;
  scanf("%s", str);
  scanf("%d", &index);
  printf("%c", str[index - 1]);
}