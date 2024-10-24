#include <algorithm>
#include <iostream>
#include <queue>

typedef struct problem {
  int deadline;
  int count;
} problem;

bool compare(problem a, problem b) {
  if (a.deadline < b.deadline)
    return true;
  else if (a.deadline == b.deadline) {
    if (a.count > b.count)
      return true;
    else
      return false;
  }
  return false;
}

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  problem arr[200001];
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> arr[i].deadline >> arr[i].count;
  sort(arr, arr + n, compare);

  priority_queue<int, vector<int>, greater<int>> rewards;

  int result = 0;
  int tasks = 0;
  for (int t = 0; t < n; t++) {
    if (tasks < arr[t].deadline) {
      rewards.push(arr[t].count);
      tasks++;
    } else {
      if (arr[t].count > rewards.top()) {
        rewards.pop();
        rewards.push(arr[t].count);
      }
    }
  }
  while (!rewards.empty()) {
    result += rewards.top();
    rewards.pop();
  }
  cout << result;
}