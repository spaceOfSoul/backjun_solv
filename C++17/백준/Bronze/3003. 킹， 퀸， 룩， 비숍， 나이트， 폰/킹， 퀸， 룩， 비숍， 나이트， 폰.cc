#include <iostream>
using namespace std;
int stan[6] = {1,1,2,2,2,8};
int arr[6];
int main() {
  for(int i=0; i<6; i++)
    cin >> arr[i];
  for(int i=0; i<6; i++)
    cout << stan[i]-arr[i] << " ";
} 