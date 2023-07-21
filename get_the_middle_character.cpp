#include <iostream>
#include <string>

std::string middle_character(std::string input){
  auto size = input.size();
  std::string result = "";
  if(size % 2 == 0){
    result += input[size/2-1];
    result += input[size/2];
    return result;
  }
  else{
    result += input[size/2];
    return result;
  }
}

int main(){
  auto x = middle_character("test");
  std::cout << x << std::endl;
}