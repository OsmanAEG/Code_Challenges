#include <iostream>
#include <vector>

class Solution {
public:
  int findDuplicate(std::vector<int>& nums) {
    int slow = 0;
    int fast = 1;

    while(true){
      if(slow != fast && nums[slow] == nums[fast]){
        return nums[slow];
      }else{
        if(slow >= nums.size() - 1) slow = 0;
        else slow += 1;

        if(fast >= nums.size() - 2) fast = 0;
        else fast += 2;
      }
    }
  }
};

int main(){
  std::vector<int> nums = {1, 3, 4, 2, 2};
  const auto result = Solution().findDuplicate(nums);

  std::cout << result << std::endl;
  return 0;
}