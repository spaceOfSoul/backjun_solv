#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp {
    bool operator()(const int& a, const int& b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, cmp> pq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }

    return 0;
}
