#include <iostream>
#include <string>
#include <algorithm>

auto add_binary(int a, int b){
  auto sum = a + b;
  std::string binary_string = "";

  if(sum == 0){
    binary_string = "0";
    return binary_string;
  }

  while(sum > 0){
    auto remainder = sum % 2;
    sum /= 2;
    std::string new_entry = std::to_string(remainder);
    binary_string.append(new_entry);
  }

  std::reverse(binary_string.begin(), binary_string.end());

  return binary_string;
}

int main(){
  auto result = add_binary(2, 0);
  std::cout << result << std::endl;
  return 0;
}

