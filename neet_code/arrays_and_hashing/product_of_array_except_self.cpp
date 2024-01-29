#include <vector>
#include <iostream>

class Solution{
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    const int N = nums.size();
    std::vector<int> prods(N, 0);

    int trailing_prod_for = 1;
    int trailing_prod_rev = 1;

    for(int i = 0; i < N; ++i){
      prods[i] = trailing_prod_for;
      trailing_prod_for *= nums[i];
    }

    for(int i = N-1; i >= 0; --i){
      prods[i] *= trailing_prod_rev;
      trailing_prod_rev *= nums[i];
    }

    return prods;
  }
};

int main(){
  std::vector<int> nums = {1, 2, 3, 4};
  auto result = Solution().productExceptSelf(nums);
  for(int i = 0; i < result.size(); ++i){
    std::cout << result[i] << std::endl;
  }
}