#include <iostream>
#include <vector>
#include <unordered_map>

class Solution1{
public:
  int singleNumber(std::vector<int>& nums){
    std::unordered_map<int, int> duplicates;

    for(int i = 0; i < nums.size(); ++i){
      duplicates[nums[i]] += 1;
    }

    for(int i = 0; i < nums.size(); ++i){
      if(duplicates[nums[i]] < 2) return nums[i];
    }

    return 0;
  }
};

class Solution2{
public:
  int singleNumber(std::vector<int>& nums){
    int unique = 0;
    for(auto& num : nums){ unique ^= num; }
    return unique;
  }
};

int main(){
  std::vector<int> nums = {2, 2, 1};
  const auto result = Solution1().singleNumber(nums);
  std::cout << result << std::endl;

  return 0;
}