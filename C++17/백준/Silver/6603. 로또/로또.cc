#include <iostream>

using namespace std;

int k;
int arr[13];
bool checks[13];

void dfs(int depth, int index){
  if(depth == 6){
    // cout << "depth : " << depth << "\n";
    for(int i=0; i<k; i++){
      if(checks[i])
        cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i=index; i<k; i++){
    checks[i] = true;
    dfs(depth+1, i+1);
    checks[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(1){
    cin >> k;
    if(!k)
      break;
    
    for(int i=0; i<k; i++)
      cin >> arr[i];
    dfs(0,0);
    cout << "\n";
  }
}