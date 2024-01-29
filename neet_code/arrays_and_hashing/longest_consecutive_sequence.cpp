#include <vector>
#include <iostream>
#include <map>

class Solution1{
public:
  int longestConsecutive(std::vector<int>& nums) {
    std::map<int, int> consecutive_vals;

    if(nums.size() == 0) return 0;

    for(int i = 0; i < nums.size(); ++i) consecutive_vals[nums[i]] += 1;

    int in_order = 0;
    int max = 1;
    int prev = consecutive_vals[nums[0]]-1;
    for(auto i = consecutive_vals.begin(); i != consecutive_vals.end(); ++i){
      if(i->first == prev + 1) in_order += 1;
      else in_order = 1;

      prev = i->first;
      max = std::max(in_order, max);
    }

    return max;
  }
};

int main(){
  std::vector<int> nums = {100, 4, 200, 1, 3, 2};
  auto result = Solution1().longestConsecutive(nums);
  std::cout << result << std::endl;
}