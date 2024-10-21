#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int edge_size;
  int edge[25001];
} Node;

typedef struct queue {
  int arr[501];
  int size;
  int ptr;
} Queue;

void init(Queue *que) {
  que->size = 0;
  que->ptr = 0;
}

void push(Queue *que, int var) { que->arr[que->size++] = var; }
int front(Queue *que) { return que->arr[que->ptr]; }
void pop(Queue *que) { que->ptr++; }
int is_empty(Queue *que) {
  if (que->size - que->ptr)
    return 0;
  return 1;
}

void tsort_print(Node *graph, int *indegree, int n) {
  Queue que;
  init(&que);

  int result[500];

  for (int i = 1; i <= n; i++) {
    if (!indegree[i])
      push(&que, i);
  }

  int possible = 1;
  for (int i = 0; i < n; i++) {
    if (is_empty(&que)) {
      possible = 0;
      break;
    }

    int now = front(&que);
    pop(&que);
    result[i] = now;

    for (int j = 0; j < graph[now].edge_size; j++) {
      int dest = graph[now].edge[j];
      if (dest == -1)
        continue;
      indegree[dest]--;
      if (!indegree[dest])
        push(&que, dest);
    }
  }

  if (!possible)
    printf("IMPOSSIBLE\n");
  else {
    for (int i = 0; i < n; i++)
      printf("%d ", result[i]);
    printf("\n");
  }
}

int main(void) {
  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    int change;
    int a, b;
    int before_rank[501];
    int indegree[501];
    Node rank_graph[501];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", before_rank + i);

      int index = before_rank[i]; //순위가 순서대로 저장
      indegree[index] = i - 1; //진입차수(본인에게 들어오는 간선)
      rank_graph[index].edge_size = n - i; //간선 수(총 노드 수 - 본인의 등수)
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 0, k = n; j < rank_graph[i].edge_size + i; j++, k--) {
        rank_graph[i].edge[j] = before_rank[k];
      }
    }

    scanf("%d", &change);

    while (change--) {
      scanf("%d %d", &a, &b);

      int flag = 0;

      for (int i = 0; i < rank_graph[a].edge_size; i++) {
        if (rank_graph[a].edge[i] == b) {
          rank_graph[a].edge[i] = -1; // a간선 삭제

          // b간선 추가
          rank_graph[b].edge[rank_graph[b].edge_size++] = a;
          indegree[b]--;
          indegree[a]++;
          flag = 1;
          break;
        }
      }
      if (!flag) {
        for (int i = 0; i < rank_graph[b].edge_size; i++) {
          if (rank_graph[b].edge[i] == a) {
            rank_graph[b].edge[i] = -1;

            rank_graph[a].edge[rank_graph[a].edge_size++] = b;
            indegree[b]++;
            indegree[a]--;
            break;
          }
        }
      }
    }
    tsort_print(rank_graph, indegree, n);
  }
  return 0;
}