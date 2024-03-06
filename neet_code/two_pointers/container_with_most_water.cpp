#include <iostream>
#include <vector>

class Solution{
public:
  int calc_area(int height, int width){
    return height*width;
  }

  int maxArea(std::vector<int>& height){
    int idx1 = 0;
    int idx2 = 1;

    int max_area = calc_area(std::max(height[idx1], height[idx2]), idx2 - idx1);

    for(int i = 1; i < height.size(); ++i){
      
    }

    return 0;
  }
};

int main(){
  std::vector<int> height = {1,8,6,2,5,4,8,3,7};
  const auto result = Solution().maxArea(height);

  std::cout << result << std::endl;
  return 0;
}