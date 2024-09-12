#include <iostream>
#include <vector>

using namespace std;
vector<int> primes;
int n;

void eratosPrime(){
  bool arr[4000001];
  for(int i=2; i<= n; i++)
    arr[i]=true;

  for(int i = 2; i<= n; i++){
    if(!arr[i])continue;
    for(int j = 2*i; j<= n; j+=i){
      arr[j] = false;
    }
  }

  for(int i=2;i<=n; i++){
    if(arr[i]) primes.push_back(i);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;

  eratosPrime();

  int sum = 0;
  int result = 0;
  for(int i=0; i<primes.size(); i++){
    for (int j=i;j<primes.size(); j++){
      sum += primes[j];
      if(sum > n){
        sum =0;
        break;
      }
      if(sum == n){
        sum = 0;
        result++;
        break;
      }
    }
    sum =0;
  }
  cout << result;
}