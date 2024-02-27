#include <iostream>
#include <vector>

class Solution1{
public:
  int maxProfit(std::vector<int>& prices){
    int max_profit = 0;

    for(int i = 0; i < prices.size(); ++i){
      for(int j = i + 1; j < prices.size(); ++j){
        max_profit = std::max(prices[j] - prices[i], max_profit);
      }
    }

    return max_profit;
  }
};

class Solution2{
public:
  int maxProfit(std::vector<int>& prices){
    int min_start = prices[0];
    int max_profit = 0;

    for(int i = 1; i < prices.size(); ++i){
      max_profit = std::max(prices[i] - min_start, max_profit);
      min_start  = std::min(prices[i], min_start);
    }

    return max_profit;
  }
};

int main(){
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  auto result = Solution2().maxProfit(prices);

  std::cout << result << std::endl;

  return 0;
}