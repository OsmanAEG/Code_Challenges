#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
public:
  int search(std::vector<int>& piles, int target, int max){
    if(piles.size() == 1) return div_up(piles[0], target);

    int idx_min = 1;
    int idx_max = max;

    while(idx_min < idx_max){
      auto idx_mid = idx_min + (idx_max - idx_min)/2;

      if(time_taken(piles, idx_mid) <= target) idx_max = idx_mid;
      else idx_min = idx_mid + 1;
    }

    return idx_min;
  }

  int div_up(int n, int d){
    return (n + d - 1)/d;
  }

  int time_taken(std::vector<int>& piles, int speed){
    int sum = 0;

    for(int i = 0; i < piles.size(); ++i){
      sum += div_up(piles[i], speed);
    }

    return sum;
  }

  int minEatingSpeed(std::vector<int>& piles, int h){
    const int max = *std::max_element(piles.begin(), piles.end());

    int idx = search(piles, h, max);

    return idx;
  }
};

int main(){
  std::vector<int> piles = {1, 1, 1, 999999999};

  const int h = 10;

  const auto result = Solution().minEatingSpeed(piles, h);
  std::cout << result << std::endl;

  return 0;
}