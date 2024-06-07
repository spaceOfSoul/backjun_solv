#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str, result, c4;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> str;
  cin >> c4;
  int strSize = str.length();
  int c4Size = c4.length();
  for(int i=0; i<strSize; i++){
    result += str[i];

    if(result.length() < c4Size)
      continue;
    if(result[result.length()-1] == c4[c4Size-1]){
      bool deleteCheck = true;
      for(int j=1; j<c4Size; j++){
        if(result[result.length()-j-1] != c4[c4Size-j-1]){
          deleteCheck = false;
          break;
        } 
      }
      
      if(deleteCheck){
        for(int k=0; k<c4Size; k++){
          result.pop_back();
        }
      }
    }
  }
  if(result.length())
    cout << result;
  else
    cout << "FRULA";
} 