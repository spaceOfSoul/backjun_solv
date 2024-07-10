#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  pair<int, int>point[4];
  int distances[6];

  cin >> t;

  while(t--){
    for(int i=0; i<4; i++)
      cin >> point[i].first >> point[i].second;

    int distance_idx = 0;
    for(int i=0; i<4; i++){
      for(int j=i+1; j<4; j++){
        distances[distance_idx++] = (int)pow(point[i].first - point[j].first, 2) + (int)pow(point[i].second - point[j].second, 2);
      }
    }

    sort(distances, distances+6);

    cout << (int)((distances[0] == distances[1] && distances[0] == distances[2] && distances[0] == distances[3] && distances[0] < distances[4])
      &&
      (distances[4] == distances[5])) << "\n";
  }
}