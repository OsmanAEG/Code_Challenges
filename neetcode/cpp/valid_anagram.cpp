#include <string>
#include <iostream>
#include <unordered_map>

class Solution{
public:
  bool isAnagram(std::string s, std::string t){
    std::unordered_map<char, int> s_count;
    std::unordered_map<char, int> t_count;

    if(s.size() != t.size()) return false;

    for(auto& c : s) s_count[c] += 1;
    for(auto& c : t) t_count[c] += 1;
    for(auto& c : s) if(s_count[c] != t_count[c]) return false;

    return true;
  }
};

int main(){
  std::string s = "anagram";
  std::string t = "nagaram";

  bool result = Solution().isAnagram(s, t);
  std::cout << result << std::endl;
}