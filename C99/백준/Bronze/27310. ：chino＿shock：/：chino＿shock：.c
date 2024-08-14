#include <stdio.h>
#include <string.h>

int main(void) {
  char str[50];
  int level = 0;
  int _ = 0;

  scanf("%s", str);
  level = strlen(str) + 2;

  char *ptr = strchr(str, '_');

  while (ptr != NULL) {
    _++;
    ptr = strchr(ptr + 1, '_');
  }
  level += _ * 5;
  printf("%d", level);
  return 0;
}