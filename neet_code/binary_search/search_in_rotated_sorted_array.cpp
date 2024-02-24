#include <iostream>
#include <vector>

class Solution{
public:
  int find_arr_start(std::vector<int>& nums){
    int idx_min = 0;
    int idx_max = nums.size() - 1;

    while(idx_min < idx_max){
      auto idx_mid = (idx_min + idx_max)/2;

      bool larger_than_min = nums[idx_mid] > nums[idx_min];
      bool larger_than_max = nums[idx_mid] > nums[idx_max];

      if(larger_than_min && !larger_than_max) return idx_min;

      if(larger_than_min) idx_min = idx_mid;
      else idx_max = idx_mid;
    }

    return idx_min + 1;
  }

  int search(std::vector<int>& nums, int target){
    int idx_min = 0;
    int idx_max = nums.size() - 1;

    if(nums.size() == 0) return -1;
    if(nums.size() == 1) return (nums[0] == target) ? 0 : -1;
    if(nums.size() == 2) return (nums[0] == target) ? 0 : (nums[1] == target) ? 1 : -1;

    const auto idx_start = find_arr_start(nums);

    if(target >= nums[idx_start] && target <= nums[nums.size() - 1]) idx_min = idx_start;
    else idx_max = idx_start - 1;

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
  std::vector<int> nums = {1, 3, 5};
  const int target = 5;

  const auto result = Solution().search(nums, target);
  std::cout << result << std::endl;
}