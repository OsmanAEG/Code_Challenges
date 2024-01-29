#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

class Solution{
public:
  template<typename Map_T>
  int happy_calculator(Map_T& sums, int n){
    std::string n_str = std::to_string(n);

    int n_new = 0;
    sums[n];

    for(auto& c : n_str){
      const int c_int = c - '0';
      n_new += c_int*c_int;
    }

    if(n_new == 1) return 1;
    else if(sums.find(n_new) != sums.end()) return 0;
    else n = happy_calculator(sums, n_new);

    return n;
  }

  bool isHappy(int n){
    std::unordered_map<int, int> sums;
    const auto result = happy_calculator(sums, n);

    if(result == 1) return true;
    return false;
  }
};

int main(){
  const int n = 2;
  const auto result = Solution().isHappy(n);

  std::cout << result << std::endl;

  return 0;
}