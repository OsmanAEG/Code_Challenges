#include <iostream>
#include <vector>

class Solution{
public:
  int search(std::vector<int>& nums, int target){
    if(nums.size() == 0) return -1;

    if(nums.size() == 1){
      if(nums[0] == target) return 0;
      else return -1;
    }

    int idx_min = 0;
    int idx_max = nums.size() - 1;

    while(idx_min <= idx_max){
      auto idx_mid = (idx_min + idx_max)/2;

      if(nums[idx_mid] == target) return idx_mid;

      if(nums[idx_mid] > target) idx_max = idx_mid - 1;
      else if(nums[idx_mid] < target) idx_min = idx_mid + 1;
    }

    return -1;
  }
};

int main(){
  std::vector<int> nums = {2,5};
  const int target = 0;

  const auto result = Solution().search(nums, target);
  std::cout << result << std::endl;

  return 0;
}