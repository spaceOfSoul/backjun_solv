#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

pair<int, char> count_alpha[26];
int alphabet_number[26];
string words[10];
int result;

int word2num(string str){
  int val = 0;
  int len = str.length();
  int multiplier = (int)pow(10,len - 1);
  
  for(int i=0; i<len; i++){
    val += alphabet_number[str[i] - 'A'] * multiplier;
    multiplier /= 10;
  }
  return val;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for(int i=0; i<26; i++)
    count_alpha[i].second = 'A'+i;

  for(int i=0; i<n; i++){
    cin >> words[i];
    
    int len = words[i].length();
    for(int j = 0; j<len; j++){
      count_alpha[words[i][j] - 'A'].first += (int)pow(10, len-j);
    }
  }

  sort(count_alpha, count_alpha+26, greater<pair<int,int>>());

  for(int i=0; i<10; i++){
    // cout << "alphabet : " << count_alpha[i].second << " weight : " << count_alpha[i].first << "\n";

    alphabet_number[count_alpha[i].second - 'A'] = 9-i;
  }

  for(int i=0; i<n; i++){
    result += word2num(words[i]);
  }
  cout << result;
}