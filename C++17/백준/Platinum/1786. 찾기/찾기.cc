#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

string t, p;
int n, m;
vector<int> result;
int count;

vector<int> table(){
  int pp = 0;
  int pt;
  vector<int> petern(m,0);
  
  for(pt=1;pt<m; pt++){
    while(pp>0 && p[pt] != p[pp])
      pp = petern[pp-1];
    if(p[pt] == p[pp])
      petern[pt] = ++pp;
  }
  return petern;
}

void kmp(){
  int pp=0;
  vector<int> piTable= table();
  for(int pt=0; pt< n; pt++){
    while(pp > 0 && t[pt] != p[pp])
      pp = piTable[pp-1];
    
    if(t[pt] == p[pp]){
      if(pp == m-1){
        result.push_back(pt-m+2);
        pp = piTable[pp];
        count++;
      }else
        pp++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  getline(cin, t);
  getline(cin, p);
  n = t.length();
  m = p.length();
  kmp();
  cout << count << "\n";
  for(int i:result){
    cout << i << " ";
  }
} 