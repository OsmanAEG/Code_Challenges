#include <iostream>
#include <vector>

class Solution{
public:
  int minCostClimbingStairs(std::vector<int>& cost){
    const int n = cost.size();

    if(n == 0) return 0;
    if(n == 1) return cost[0];
    if(n == 2) return std::min(cost[0], cost[1]);

    std::vector<int> variation_costs(n, 0);

    variation_costs[0] = cost[0];
    variation_costs[1] = cost[1];

    for(int i = 2; i < n; ++i){
      const auto local_variation_cost1 = cost[i] + variation_costs[i-1];
      const auto local_variation_cost2 = cost[i] + variation_costs[i-2];

      variation_costs[i] = std::min(local_variation_cost1, local_variation_cost2);
    }

    return std::min(variation_costs[n - 1], variation_costs[n - 2]);
  }
};

int main(){
  std::vector<int> costs = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  const auto result = Solution().minCostClimbingStairs(costs);

  std::cout << result << std::endl;

  return 0;
}