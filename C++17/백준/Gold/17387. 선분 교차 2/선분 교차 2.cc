#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll x1,x2,x3,x4,y1,y2,y3,y4;

int ccw(ll a1, ll b1, ll a2, ll b2, ll a3, ll b3){
  ll tmp = a1*b2 + a2*b3 + a3*b1;
  tmp-=(a2*b1 + a3*b2 + a1*b3);

  if(tmp>0) return 1;
  else if(tmp<0) return -1;
  else return 0;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

  int ccw1 = ccw(x1,y1,x2,y2,x3,y3);
  int ccw2 = ccw(x1,y1,x2,y2,x4,y4);
  int ccw3 = ccw(x3,y3,x4,y4,x1,y1);
  int ccw4 = ccw(x3,y3,x4,y4,x2,y2);

  if(ccw1*ccw2<=0 && ccw3*ccw4<=0){
    if(ccw1*ccw2==0 && ccw3*ccw4==0){
      pair<int, int> a = {x1,y1};
      pair<int, int> b = {x2,y2};
      pair<int, int> c = {x3,y3};
      pair<int, int> d = {x4,y4};

      if(a>b)
        swap(a,b);
      if(c>d)
        swap(c,d);
      if(c<=b && a<=d)
        cout << 1;
      else{
        cout << 0;
      }
    }else
      cout << 1;
  }else
    cout << 0;
} 