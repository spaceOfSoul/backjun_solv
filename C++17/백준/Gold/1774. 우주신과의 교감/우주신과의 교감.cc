#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
  int x, y;
} Node;
typedef struct edge {
  double dist;
  int a, b;
} Edge;

int n, m;
vector<Node> nodes;
vector<Edge> edges;
int parents[1000];

int find_parent(int x) {
  if (parents[x] != x)
    return parents[x] = find_parent(parents[x]);
  return parents[x];
}

void unionParents(int a, int b) {
  a = find_parent(a);
  b = find_parent(b);

  if (a < b) {
    parents[b] = a;
  } else {
    parents[a] = b;
  }
}

double distance(Node a, Node b) {
  float xd = abs(a.x - b.x);
  float yd = abs(a.y - b.y);

  return (double)sqrt(pow(xd, 2) + pow(yd, 2));
}

bool compare(Edge a, Edge b) { return a.dist < b.dist; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    nodes.push_back({a, b});
    parents[i] = i;
  }

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;

    unionParents(a, b);
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (find_parent(i) == find_parent(j))
        continue;

      double dist = distance(nodes[i], nodes[j]);
      edges.push_back({dist, i, j});
    }
  }

  sort(edges.begin(), edges.end(), compare);

  // for (Edge i : edges) {
  //   cout << i.a << " : " << i.b << " : " << i.dist << "\n";
  // }

  double result = 0;
  for (Edge i : edges) {
    if (find_parent(i.a) == find_parent(i.b))
      continue;
    unionParents(i.a, i.b);
    result += i.dist;
  }

  cout << fixed;
  cout.precision(2);
  cout << result;

  return 0;
}
