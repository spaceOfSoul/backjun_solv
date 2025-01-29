#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool pelrin[10000001];

int a,b;

bool isPelrindrom(int num){
  string snum = to_string(num);
  int sSize = snum.length();
  for(int i=0; i<sSize/2; i++){
    if(snum[i] != snum[sSize - 1 - i])
      return true;
  }
  return false;
}

bool isprime(int num){
  for(int i=2; i<= sqrt(num); i++){
    if(num % i ==0)
      return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> a >> b;

  if(b>10000000)
    b=10000000;
  
  for(int i=2; i<=b; i++){
    pelrin[i] = isPelrindrom(i);
  }
  
  for(int i=a; i<=b; i++){
    if(!pelrin[i]){
      if(isprime(i))
        cout << i << "\n";
    }
  }
  cout << -1;
} 