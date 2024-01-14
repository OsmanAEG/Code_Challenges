#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution{
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
    std::vector<std::vector<std::string>> group_anagrams;
    std::unordered_map<std::string, std::vector<int>> anagram_map;

    for(int i = 0; i < strs.size(); ++i){
      std::string tmp_str = strs[i];
      std::sort(tmp_str.begin(), tmp_str.end());
      anagram_map[tmp_str].push_back(i);
    }

    for(auto& group : anagram_map){
      std::vector<std::string> grouped_anagrams;
      for(auto& idx : anagram_map[group.first]){
        grouped_anagrams.push_back(strs[idx]);
      }
      std::sort(grouped_anagrams.begin(), grouped_anagrams.end());
      group_anagrams.push_back(grouped_anagrams);
    }

    return group_anagrams;
  }
};

int main(){
  std::vector<std::string> input = {"eat","tea","tan","ate","nat","bat"};
  auto result = Solution().groupAnagrams(input);

  for(int i = 0; i < result.size(); ++i){
    for(int j = 0; j < result[i].size(); ++j){
      std::cout << result[i][j] << std::endl;
    }
  }

  return 0;
}