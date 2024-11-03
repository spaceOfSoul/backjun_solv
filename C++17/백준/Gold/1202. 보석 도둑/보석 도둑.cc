#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
vector<pair<int, int>> juel;
vector<int> bagpacks;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  int m, v;
  for (int i = 0; i < n; i++) {
    cin >> m >> v;
    juel.push_back({m, v}); // price, weight
  }

  int w;
  for (int i = 0; i < k; i++) {
    cin >> w;
    bagpacks.push_back(w);
  }

  sort(bagpacks.begin(), bagpacks.end());
  sort(juel.begin(), juel.end());

  int j = 0;

  long long result = 0;
  priority_queue<int> steals;

  for (int i : bagpacks) {
    while (j < n && juel[j].first <= i) {
      steals.push(juel[j].second);
      j++;
    }

    if (!steals.empty()) {
      result += steals.top();
      steals.pop();
    }
  }
  cout << result;
}