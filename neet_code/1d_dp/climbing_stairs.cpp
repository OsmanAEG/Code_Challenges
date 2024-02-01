#include <iostream>
#include <vector>

class Solution1{
public:
  void stair_count(int n, int steps_taken, int& step_variations){
    if(steps_taken == n - 1){
      stair_count(n, steps_taken + 1, step_variations);
    }else if(steps_taken < n){
      stair_count(n, steps_taken + 1, step_variations);
      stair_count(n, steps_taken + 2, step_variations);
    }else{
      step_variations += 1;
    }
  }

  int climbStairs(int n){
    int step_variations = 0;

    stair_count(n, 0, step_variations);

    return step_variations;
  }
};

class Solution2{
public:
  int climbStairs(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;

    std::vector<int> variations(n, 0);

    variations[0] = 1;
    variations[1] = 2;

    for(int i = 2; i < n; ++i){
      variations[i] += variations[i-1] + variations[i-2];
    }

    return variations[n-1];
  }
};

int main(){
  int n = 3;

  const auto result = Solution2().climbStairs(n);
  std::cout << result << std::endl;

  return 0;
}