#include <iostream>
#include <vector>

class Solution{
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target){
    int idx_1 = 0;
    int idx_2 = numbers.size() - 1;

    while(numbers[idx_1] + numbers[idx_2] != target){
      if(numbers[idx_1] + numbers[idx_2] > target) --idx_2;
      if(numbers[idx_1] + numbers[idx_2] < target) ++idx_1;
    }

    return {idx_1 + 1, idx_2 + 1};
  }
};

int main(){
  std::vector<int> nums = {5, 25, 75};
  int target = 100;
  auto result = Solution().twoSum(nums, target);

  std::cout << "{" << result[0] << ", " << result[1] << "}" << std::endl;
}