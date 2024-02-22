#include <iostream>
#include <vector>

class Solution{
public:
  int findMin(std::vector<int>& nums){
    if(nums.size() == 0) return -1;
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return (nums[0] > nums[1]) ? nums[1] : nums[0];

    int idx_min = 0;
    int idx_max = nums.size() - 1;

    while(idx_min < idx_max){
      auto idx_mid = (idx_min + idx_max)/2;

      bool larger_than_min = nums[idx_mid] > nums[idx_min];
      bool larger_than_max = nums[idx_mid] > nums[idx_max];

      if(larger_than_min && !larger_than_max) return nums[idx_min];

      if(larger_than_min) idx_min = idx_mid;
      else idx_max = idx_mid;
    }

    return nums[idx_min + 1];
  }
};

int main(){
  std::vector<int> nums = {11,13,15,17};

  const auto result = Solution().findMin(nums);
  std::cout << result << std::endl;
}