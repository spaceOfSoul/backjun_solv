#include <iostream>
#include <vector>

using namespace std;

int parents[10000];
bool visited[10000];

int go_to_root(int a) {
    int parent = parents[a];
    visited[a] = true;

    while (parent != a)
    {
        if (visited[parent])
            break;
        visited[parent] = true;
        parent = parents[parent];
    }

    return parent;
}

void clear_graph(int n) {
    for (int i = 0; i < n; i++) {
        parents[i] = i;
        visited[i] = false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    int N;
    int a, b;

    cin >> T;

    while (T--) {
      cin >> N;
      clear_graph(N);

      int i;
      for (i = 0; i < N-1; i++) {
        cin >> a >> b;
        parents[b - 1] = a - 1;
      }

      cin >> a >> b;
      go_to_root(a-1);
      cout << go_to_root(b-1) + 1 << "\n";
    }
}