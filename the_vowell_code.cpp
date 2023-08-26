#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

std::string encode(const std::string &str){
  auto new_str = str;
  std::vector<char> old_chars = {'a', 'e', 'i', 'o', 'u'};

  for(int i = 1; i <= old_chars.size(); ++i){
    std::replace(new_str.begin(), new_str.end(), old_chars[i-1], static_cast<char>(i + '0'));
  }

  return new_str;
}

std::string decode(const std::string &str){
  auto new_str = str;
  char char_conv[2][5] = {{'1', '2', '3', '4', '5'},
                          {'a', 'e', 'i', 'o', 'u'}};

  for(int i = 0; i < sizeof(char_conv[0]); ++i){
    std::replace(new_str.begin(), new_str.end(), char_conv[0][i], char_conv[1][i]);
  }

  return new_str;
}

int main(){
  const auto test = "H4w 1r2 y45 t4d1y?";
  const auto new_str = decode(test);
  std::cout << new_str << std::endl;
}