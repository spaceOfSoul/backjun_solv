#include <iostream>
#define INF 999999999;
using namespace std;

int n,m;
int dist[201][201];
int navi[201][201];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++){
      if(i==j)
        dist[i][j] = 0;
      else
        dist[i][j] = INF;
    }
  
  int a,b,c;
  for(int i=0; i<m; i++){
    cin >> a >> b >> c;
    dist[a][b] = c;
    dist[b][a] = c;
    navi[a][b] = b;
    navi[b][a] = a;
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      for(int k=1; k<=n; k++){
        if(dist[j][k] > dist[j][i] + dist[i][k]){
          dist[j][k] = dist[j][i] + dist[i][k];
          navi[j][k] = navi[j][i];
        }
      }
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(navi[i][j] == 0)
        cout << '-';
      else cout << navi[i][j];
      cout << " ";
    }
    cout << "\n";
  }
} 