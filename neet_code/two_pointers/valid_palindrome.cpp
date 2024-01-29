#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution{
public:
  bool isPalindrome(std::string s){
    auto is_not_alpha = [](char c){return !std::isalnum(c);};
    s.erase(std::remove_if(s.begin(), s.end(), is_not_alpha), s.end());

    for(int i = 0; i < s.size() / 2; ++i){
      if(std::tolower(s[i]) != std::tolower(s[s.size()-i-1])) return false;
    }

    return true;
  }
};

int main(){
  std::string input = "A man, a plan, a canal: Panama";
  auto result = Solution().isPalindrome(input);
  std::cout << result << std::endl;
}