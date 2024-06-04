#include <iostream>
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    
  }
};

int main() {
  std::vector<int> nums1 = {1, 3};
  std::vector<int> nums2 = {2};

  const auto result = Solution().findMedianSortedArrays(nums1, nums2);

  std::cout << "Result: " << result << std::endl;

  return 0;
}