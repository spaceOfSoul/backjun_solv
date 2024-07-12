#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int n,m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  string input_str, sort_str;

  map<string, string> dict;
  
  while(n--){
    cin >> input_str;
    
    sort_str = input_str;

    if(input_str.length()>3)
      sort(sort_str.begin()+1, sort_str.end()-1);
    
    dict.insert({sort_str, input_str});
  }

  cin >> m;
  // cout << "m : " << m << "\n";
  while(m--){
    // cout << "m\n";
    cin >> input_str;
    sort_str = input_str;

    if(input_str.length()>3)
      sort(sort_str.begin()+1, sort_str.end()-1);
    
    if(dict.find(sort_str) != dict.end())
      cout << dict[sort_str] << " ";
    else
      cout << input_str << " ";
  }
}