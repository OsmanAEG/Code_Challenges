#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums){
    std::vector<std::vector<int>> triplets;
    std::map<int, std::vector<int>> num_idx_map;

    for(int i = 0; i < nums.size(); ++i) num_idx_map[nums[i]].push_back(i);

    for(auto i = num_idx_map.begin(); i != num_idx_map.end(); ++i){
      int num_low  = num
      int num_high =
      std::cout << i->first << std::endl;
    }

    return triplets;
  }
};

int main(){
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  auto result = Solution().threeSum(nums);

  // for(const auto& triplet : result){
  //   std::cout << "{" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "}" << std::endl;
  //   std::cout << nums[triplet[0]] + nums[triplet[1]] + nums[triplet[2]] << std::endl;
  // }
}