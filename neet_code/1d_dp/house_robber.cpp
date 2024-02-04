#include <iostream>
#include <algorithm>
#include <vector>

class Solution{
public:
  int rob(std::vector<int>& nums){
    if(nums.size() <= 2) return *std::max_element(nums.begin(), nums.end());

    int L2 = nums[0];
    int L1 = std::max(nums[0], nums[1]);

    for(int i = 2; i < nums.size(); ++i){
      const auto max = std::max(nums[i] + L2, L1);
      L2 = L1;
      L1 = max;
    }

    return L1;
  }
};

int main(){
  std::vector<int> nums = {2, 1, 1, 2};
  auto result = Solution().rob(nums);

  std::cout << result << std::endl;

  return 0;
}