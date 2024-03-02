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

    double ans = 1.0;
    auto num_it = std::abs(n);

    while(num_it > 0){
      ans *= x;
      num_it /= 2;
    }

    if(n%2 != 0) ans *= x;
    if(n < 0) ans = 1.0/ans;

    return ans;
  }
};

int main(){
  double x = 2.0;
  int n = 10;
  const auto result = Solution2().myPow(x, n);
  std::cout << result << std::endl;

  return 0;
}

