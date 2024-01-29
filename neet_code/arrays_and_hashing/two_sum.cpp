#include <vector>
#include <iostream>
#include <unordered_map>

class Solution1{
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> result = {0, 0};

    int current = 0;

    while(current < nums.size()){
      for(int i = current + 1; i < nums.size(); ++i){
        if(nums[current] + nums[i] == target){
          result[0] = current;
          result[1] = i;
          return result;
        }
      }

      ++current;
    }
    return result;
  }
};

class Solution2{
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> result = {0, 0};
    std::unordered_map<int, int> num_idx_map;

    for(int i = 0; i < nums.size(); ++i) num_idx_map[nums[i]] = i;
    for(int i = 0; i < nums.size(); ++i){
      const int diff = target - nums[i];

      if(num_idx_map.count(diff) > 0 && i != num_idx_map[diff]){
        result[0] = i;
        result[1] = num_idx_map[diff];
        return result;
      }
    }

    return result;
  }
};

class Solution3{
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> result = {0, 0};
    std::unordered_map<int, int> num_idx_map;

    for(int i = 0; i < nums.size(); ++i){
      int diff = target - nums[i];

      if(num_idx_map.count(diff) > 0){
        result[0] = num_idx_map[diff];
        result[1] = i;
        return result;
      }

      num_idx_map[nums[i]] = i;
    }

    return result;
  }
};

int main(){
  std::vector<int> nums = {3, 2, 4};
  int target = 6;
  auto result = Solution3().twoSum(nums, target);
  std::cout << "{" << result[0] << ", " << result[1] << "}" << std::endl;
}