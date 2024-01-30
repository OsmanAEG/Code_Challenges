#include <iostream>
#include <string>
#include <vector>

class Solution{
public:
  std::string encode(std::vector<std::string>& strs){
    std::string encoded = "";

    for(auto& str : strs){
      for(auto& c : str){
        encoded += c;
      }
      encoded += '|';
    }

    return encoded;
  }

  std::vector<std::string> decode(std::string s){
    std::vector<std::string> decoded = {};
    std::string word = "";

    for(auto& c : s){
      if(c == '|'){
        decoded.push_back(word);
        word = "";
      }else{
        word += c;
      }
    }

    return decoded;
  }
};

int main(){
  std::vector<std::string> input = {"cpp", "code", "love", "you"};
  const auto encoded_msg = Solution().encode(input);
  const auto decoded_msg = Solution().decode(encoded_msg);

  std::cout << "[";
  for(auto& word : decoded_msg){std::cout << word << ", ";}
  std::cout << "]" << std::endl;

  return 0;
}
