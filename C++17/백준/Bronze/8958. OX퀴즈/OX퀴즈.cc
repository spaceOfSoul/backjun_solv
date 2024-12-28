#include <iostream>
#include <string>
using namespace std;

int testcase;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> testcase;
  for(int t=0; t<testcase; t++){
    int score = 0;
    string result;
    cin >> result;

    bool iscombo = false;
    int combo = 1;
    for(int i =0; i<result.size(); i++){
      if(result[i] == 'O'){
        if(!combo)
          combo = true;
        else{
          score += combo++;
        }
      }else
        combo = 1;
    }
    cout << score << "\n";
  }
}