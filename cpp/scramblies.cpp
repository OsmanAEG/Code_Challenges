#include <iostream>
#include <string>
#include <map>

bool scramble(const std::string& s1, const std::string& s2){
  std::map<char, int> s2_map;
  std::map<char, int> s1_map;

  bool scrambleable = true;
  for(char c : s1) s1_map[c] += 1;
  for(char c : s2) s2_map[c] += 1;

  for(char c : s2){
    if(s1_map[c] < s2_map[c]){
      scrambleable = false;
      break;
    }
  }

  return scrambleable;
}

int main(){
  auto result = scramble("rkqodlw", "world");
  std::cout << result << std::endl;
}