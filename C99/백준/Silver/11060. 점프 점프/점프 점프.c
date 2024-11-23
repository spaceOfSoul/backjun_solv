#include <stdio.h>
int n;
int arr[1000];
int visited[1000];
int result;

typedef struct queue{
  int front, rear;
  int queueArr[1001];
} queue;
//---------
void queInit(queue *q){
  q->front = 0;
  q->rear = 0;
}

void push(queue *q, int val){
  q->queueArr[q->rear++]= val;
}
void pop(queue *q){
  q->front++;
}

int queEmpty(queue *q){
  if(q->front == q->rear){
    return 1;
  }
  return 0;
}

int queFront(queue *q){
  return q->queueArr[q->front];
}

//--------
void bfs(){
  queue que;
  queInit(&que);
  push(&que,0);
  visited[0] = 1;

  while(!queEmpty(&que)){
    int now = queFront(&que);
    pop(&que);

    if(now == n-1){
      result = visited[now]-1;
      return;
    }

    for(int i=1; i<=arr[now]; i++){
      if(now+i<n && !visited[now+i]){
        visited[now+i] = visited[now]+1;
        push(&que, now+i);
      }
    }
  }
  result = -1;
  return;
}

int main(void) {
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  bfs();
  printf("%d", result);
  return 0;
}