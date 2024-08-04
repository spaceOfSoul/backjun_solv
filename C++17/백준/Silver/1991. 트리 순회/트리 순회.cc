#include <iostream>
using namespace std;

int n;
pair<char, char> node[27];

void jeonY(char a){
  if(a == '.') return;
  cout << a;
  jeonY(node[a-'A'].first);
  jeonY(node[a-'A'].second);
}

void joomgY(char a){
  if(a == '.') return;
  joomgY(node[a-'A'].first);
  cout << a;
  joomgY(node[a-'A'].second);
}

void after(char a){
  if(a=='.') return;
  after(node[a-'A'].first);
  after(node[a-'A'].second);
  cout << a;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i = 0; i < n; i++){
    char a,b,c;
    cin >> a >> b >> c;
    node[a - 'A'] = {b,c};
  }
  jeonY('A');
  cout << "\n";
  joomgY('A');
  cout << "\n";
  after('A');
}