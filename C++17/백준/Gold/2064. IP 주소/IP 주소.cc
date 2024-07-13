#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define _BV(num) (1<<num)
using namespace std;

int n;

vector<vector<uint8_t>> addresses;

vector<uint8_t> split(string str){
  istringstream ss(str);
  string buffer;

  vector<uint8_t> result;

  while(getline(ss, buffer, '.')){
    result.push_back((uint8_t)stoi(buffer));
  }

  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  string tmp;
  for(int i=0; i<n; i++){
    cin >> tmp;
    addresses.push_back(split(tmp));
  }

  uint8_t network_address[4] = {0,0,0,0};
  uint8_t network_mask[4] = {0,0,0,0};

  int flag = 32;

  for(int i=0; i<32; i++){
    int byte_idx = i/8;
    int bit_idx = 7 - i%8; // big endian (인덱스 반전 필요.)

    for(auto address : addresses){
      if((addresses[0][byte_idx] & _BV(bit_idx)) !=  (address[byte_idx] & _BV(bit_idx))){
        flag = i;
        break;
      }
    }

    if(flag < 32)
      break;
  }
  

  for(int i=0; i<flag; i++){
    int byte_idx = i/8;
    int bit_idx = 7 - i%8;

    network_mask[byte_idx] |= _BV(bit_idx);
  }

  for(auto address : addresses){
    for(int i=0; i<4; i++){
      network_address[i] = network_mask[i] & address[i];
    }
  }

  for(int i=0; i<3; i++){
    cout << (int)network_address[i] << ".";
  }
  cout << (int)network_address[3] << "\n";

  for(int i=0; i<3; i++){
    cout << (int)network_mask[i] << ".";
  }
  cout << (int)network_mask[3];
}