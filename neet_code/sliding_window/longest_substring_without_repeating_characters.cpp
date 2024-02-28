#include <iostream>
#include <unordered_map>
#include <set>

class Solution1{
public:
  int lengthOfLongestSubstring(std::string s) {
    int longest = 0;
    int counter = 0;
    std::unordered_map<char, int> tracker;

    int i = 0;

    while(i < s.size()){
      auto it = tracker.find(s[i]);
      if(it != tracker.end()){
        counter = 1;
        i = tracker[s[i]] + 1;
        tracker.clear();
      }else{
        ++counter;
      }

      tracker[s[i]] = i;
      longest = std::max(longest, counter);

      ++i;
    }

    return longest;
  }
};

class Solution2{
public:
  int lengthOfLongestSubstring(std::string s) {
    int longest = 0;
    int first = 0;

    std::set<char> tracker;

    for(int last = 0; last < s.size(); ++last){
      while(tracker.find(s[last]) != tracker.end()){
        tracker.erase(s[first]);
        first += 1;
      }

      tracker.insert(s[last]);
      longest = std::max(longest, last - first + 1);
    }

    return longest;
  }
};

int main(){
  std::string s = "pwwkew";
  const auto result = Solution2().lengthOfLongestSubstring(s);
  std::cout << result << std::endl;

  return 0;
}