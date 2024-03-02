#include <iostream>

class Solution1{
public:
  double myPow(double x, int n){
    double ans = 1.0;

    if(n >= 0) for(int i = 0; i < n; ++i) ans *= x;
    else for(int i = 0; i < -n; ++i) ans /= x;

    return ans;
  }
};

class Solution2{
public:
  double myPow(double x, int n){
    if(n == 0) return 1.0;

    auto num_it = std::abs(n);
    double multiplier = 1.0;

    while(num_it > 1){
      const double num = x;
      if(num_it%2 != 0) multiplier *= num;
      x *= x;
      num_it /= 2;
    }

    x *= multiplier;
    if(n < 0) x = 1.0/x;

    return x;
  }
};

int main(){
  double x = 2.10000;
  int n = 3;
  const auto result = Solution2().myPow(x, n);
  std::cout << result << std::endl;

  return 0;
}

