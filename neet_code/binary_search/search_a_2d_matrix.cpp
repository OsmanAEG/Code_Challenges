#include <iostream>
#include <vector>

class Solution{
public:
  bool search(std::vector<int>& nums, int target){
    if(nums.size() == 0) return false;

    if(nums.size() == 1){
      if(nums[0] == target) return true;
      else return false;
    }

    int idx_min = 0;
    int idx_max = nums.size() - 1;

    while(idx_min <= idx_max){
      auto idx_mid = (idx_min + idx_max)/2;

      if(nums[idx_mid] == target) return true;

      if(nums[idx_mid] > target) idx_max = idx_mid - 1;
      else if(nums[idx_mid] < target) idx_min = idx_mid + 1;
    }

    return false;
  }

  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target){
    for(auto& nums : matrix){
      if(search(nums, target)) return true;
    }

    return false;
  }
};

int main(){
  std::vector<std::vector<int>> matrix = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
  const int target = 3;

  const auto result = Solution().searchMatrix(matrix, target);
  std::cout << result << std::endl;

  return 0;
}