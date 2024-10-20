#include <stdio.h>
#include <stdlib.h>

typedef struct sanke {
  int dx;
  int dy;
  int x;
  int y;
} snake;

typedef struct instruct {
  int timing;
  char rotate;
} instruct;

typedef struct pair {
  int x;
  int y;
} pair;

typedef struct node {
  pair var;
  struct node *pre;
  struct node *next;
} node;

typedef struct deque {
  node *left;
  node *right;
  int size;
} deque;

void init(deque *dq) {
  dq->right = NULL;
  dq->left = NULL;
  dq->size = 0;
}

int is_empty(deque *dq) { return (dq->size == 0); }

void push_r(deque *dq, pair var) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->var = var;

  if (is_empty(dq)) {
    dq->right = new_node;
    dq->left = new_node;
    new_node->pre = NULL;
    new_node->next = NULL;
  } else {
    node *tmp = dq->right;
    dq->right = new_node;
    new_node->pre = tmp;
    tmp->next = new_node;
    new_node->next = NULL;
  }
  dq->size += 1;
}

void push_l(deque *dq, pair var) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->var = var;

  if (is_empty(dq)) {
    dq->left = new_node;
    dq->right = new_node;
    new_node->pre = NULL;
    new_node->next = NULL;
  } else {
    node *tmp = dq->left;
    dq->left = new_node;
    new_node->next = tmp;
    tmp->pre = new_node;
    new_node->pre = NULL;
  }
  dq->size += 1;
}

void pop_l(deque *dq) {
  node *tmp = dq->left;
  dq->left = tmp->next;
  dq->size -= 1;
  free(tmp);
}

void pop_r(deque *dq) {
  node *tmp = dq->right;
  dq->right = tmp->pre;
  dq->size -= 1;
  free(tmp);
}

void pop_all(deque *dq) {
  while (!is_empty(dq)) {
    pop_l(dq);
  }
}

node left(deque *dq) { return *(dq->left); }

node right(deque *dq) { return *(dq->right); }

pair make_pair(int x, int y) {
  pair tmp = {x, y};
  return tmp;
}

int arr[100][100];
instruct command[101];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
  int n, k, l;
  scanf("%d", &n);
  scanf("%d", &k);

  int a, b;
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &a, &b);
    arr[a - 1][b - 1] = 1;
  }
  scanf("%d", &l);

  int x;
  char rotate;
  int cur = 0;
  for (int i = 0; i < l; i++) {
    scanf("%d %c", &x, &rotate);
    command[i].timing = x;
    command[i].rotate = rotate;
  }

  int time = 0;
  snake head = {0, 1, 0, 0};
  arr[0][0] = 2;

  deque snk;
  init(&snk);
  push_r(&snk, make_pair(0, 0));

  char dir = 0;

  while (1) {
    time++;
    int nx = head.x + head.dx;
    int ny = head.y + head.dy;

    if (0 <= nx && nx < n && 0 <= ny && ny < n) {
      if (arr[nx][ny] == 2) {
        break;
      } else if (arr[nx][ny] == 0) {
        arr[left(&snk).var.x][left(&snk).var.y] = 0;
        pop_l(&snk);
      }
      head.x = nx;
      head.y = ny;
      push_r(&snk, make_pair(head.x, head.y));
      arr[nx][ny] = 2;
    } else
      break;

    if (command[cur].timing == time) {
      if (command[cur].rotate == 'L') {
        dir -= 1;
        if (dir == -1)
          dir = 3;
      } else {
        dir += 1;
        if (dir == 4)
          dir = 0;
      }
      head.dx = dx[dir];
      head.dy = dy[dir];
      cur++;
    }
  }
  printf("%d", time);
  return 0;
}