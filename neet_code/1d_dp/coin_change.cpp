#include <algorithm>
#include <iostream>
#include <vector>

class Solution{
public:
  int coinChange(std::vector<int>& coins, int amount){
    std::vector<int> num_coins(amount + 1, 1e6);
    num_coins[0] = 0;

    std::sort(coins.begin(), coins.end());

    for(int i = 1; i <= amount; ++i){
      for(auto& coin : coins){
        if(i - coin >= 0){
          num_coins[i] = std::min(num_coins[i], 1 + num_coins[i - coin]);
        }
      }
    }

    if(num_coins[amount] != 1e6) return num_coins[amount];

    return -1;
  }
};

int main(){
  std::vector<int> coins{186, 419, 83, 408};
  const int amount = 6249;

  const auto result = Solution().coinChange(coins, amount);
  std::cout << result << std::endl;
}