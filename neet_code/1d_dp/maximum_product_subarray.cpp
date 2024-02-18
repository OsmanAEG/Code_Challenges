#include<iostream>
#include<vector>

class Solution1{
public:
  int maxProduct(std::vector<int>& nums){
    int max = -1.0e6;
    int i_start = 0;

    while(i_start < nums.size()){
      int running_prod = 1;
      for(int i = i_start; i < nums.size(); ++i){
        running_prod *= nums[i];

        if(running_prod > max) max = running_prod;
      }

      ++i_start;
    }

    return max;
  }
};

class Solution2{
public:
  int maxProduct(std::vector<int>& nums){
    int max = -1.0e6;
    int running_prod = 1;

    for(int i = 0; i < nums.size(); ++i){
      running_prod *= nums[i];
      std::cout << running_prod << std::endl;
    }

    return max;
  }
};

int main(){
  std::vector<int> nums = {2, 3, -2, 4};
  auto result = Solution2().maxProduct(nums);
  std::cout << result << std::endl;
  return 0;
}