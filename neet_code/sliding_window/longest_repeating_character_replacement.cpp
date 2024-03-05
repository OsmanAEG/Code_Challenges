#include<iostream>
#include<string>

class Solution{
public:
  int characterReplacement(std::string s, int k){
    int longest = 0;

    for(int first = 0; first < s.size(); ++first){
      int second = first;
      int rem = k;

      while(second < s.size()){
        if(s[second] != s[first]){
          if(rem > 0) --rem;
          else break;
        }

        ++second;
      }

      if(rem >= 0) longest = std::max(longest, second - first);
      else longest = std::max(longest, second - first + 1);
    }

    return longest;
  }
};

int main(){
  std::string s = "AAAA";
  const int k = 0;

  const auto result = Solution().characterReplacement(s, k);
  std::cout << result << std::endl;

  return 0;
}