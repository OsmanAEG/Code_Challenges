#include <iostream>
#include <string>
#include <algorithm>

template<typename Int_type>
auto convert_to_binary(Int_type entry){
  std::string binary_string = "";

  if(entry == 0){
    binary_string = "0";
    return binary_string;
  }

  while(entry > 0){
    auto remainder = entry % 2;
    entry /= 2;
    std::string new_entry = std::to_string(remainder);
    binary_string.append(new_entry);
  }

  std::reverse(binary_string.begin(), binary_string.end());
  return binary_string;
}

unsigned int countBits(unsigned long long n){
  unsigned int ones = 0;
  auto binary_n = convert_to_binary(n);

  for(char c : binary_n){
    if(c == '1') ones++;
  }

  return ones;
}

int main(){
  int n = 77231418;
  auto result = countBits(n);
  std::cout << result << std::endl;
}