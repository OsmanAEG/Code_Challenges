#include <vector>
#include <unordered_map>
#include <iostream>

class Solution{
public:
  bool containsDuplicate(std::vector<int>& nums){
    std::unordered_map<int, int> num_count;

    for(auto& num : nums){
      num_count[num] += 1;
      if(num_count[num] > 1) return true;
    }

    return false;
  }
};

int main(){
  std::vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
  auto sol = Solution();
  bool result = sol.containsDuplicate(nums);
  std::cout << result << std::endl;
}