#include <cmath>
#include <iostream>

using namespace std;

typedef struct {
  int a, b, c;
} Equation;

pair<double, double> intersection(Equation e1, Equation e2) {
  float x, y;
  x = (e1.b * e2.c - e2.b * e1.c) / float(e1.a * e2.b - e2.a * e1.b);
  y = (e1.c * e2.a - e2.c * e1.a) / float(e1.a * e2.b - e2.a * e1.b);
  return make_pair(x, y);
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;

  Equation eq[3];

  pair<double, double> intersections[3];

  bool isTriangle = true;

  while (T--) {
    isTriangle = true;
    for (int i = 0; i < 3; i++) {
      cin >> eq[i].a >> eq[i].b >> eq[i].c;
    }

    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == k)
          continue;
        if (eq[j].a * eq[k].b == eq[k].a * eq[j].b) {
          isTriangle = false;
          break;
        }
      }
      if (!isTriangle)
        break;
    }

    if (!isTriangle) {
      cout << "0.0000\n";
    } else {
      intersections[0] = intersection(eq[0], eq[1]);
      intersections[1] = intersection(eq[0], eq[2]);
      intersections[2] = intersection(eq[1], eq[2]);

      double area;
      area = intersections[0].first *
                 (intersections[1].second - intersections[2].second) +
             intersections[1].first *
                 (intersections[2].second - intersections[0].second) +
             intersections[2].first *
                 (intersections[0].second - intersections[1].second);
      area = 0.5 * abs(area);
      area = round(area * 100000) / 100000;

      cout.precision(4);
      cout << fixed << area << "\n";
    }
  }
}