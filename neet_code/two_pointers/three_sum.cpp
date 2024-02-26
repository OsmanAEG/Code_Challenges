#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums){
    std::set<std::vector<int>> triplets;

    std::sort(nums.begin(), nums.end());

    for(int idx = 1; idx < nums.size() - 1; ++idx){
      int idx_min = 0;
      int idx_max = nums.size() - 1;

      while(idx_min < idx && idx < idx_max){
        if(nums[idx_min] + nums[idx] + nums[idx_max] > 0) --idx_max;
        else if(nums[idx_min] + nums[idx] + nums[idx_max] < 0) ++idx_min;
        else{
          triplets.insert({nums[idx_min], nums[idx], nums[idx_max]});
          --idx_max;
          ++idx_min;
        }
      }
    }

    return std::vector<std::vector<int>>(triplets.begin(), triplets.end());
  }
};

int main(){
  std::vector<int> nums = {3, 0, -2, -1, 1, 2};
  auto result = Solution().threeSum(nums);

  for(const auto& triplet : result){
    std::cout << "{" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "}" << std::endl;
  }
}