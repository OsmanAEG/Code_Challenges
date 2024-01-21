#include <iostream>
#include <algorithm>
#include <vector>

class Solution{
public:
  void get_valid_variants(std::vector<std::string>& variants, std::string variant,
                          int num_open, int num_closed, int n){
    if(variant.size() == 2*n){
      variants.push_back(variant);
    }else if(num_open == n && num_closed < n + 1){
      auto new_var = variant;
      new_var.push_back(')');
      get_valid_variants(variants, new_var, num_open, num_closed + 1, n);
    }else if(num_open > num_closed && num_open < n + 1){
      auto new_var1 = variant;
      auto new_var2 = variant;
      new_var1.push_back('(');
      new_var2.push_back(')');
      get_valid_variants(variants, new_var1, num_open + 1, num_closed, n);
      get_valid_variants(variants, new_var2, num_open, num_closed + 1, n);
    }else{
      auto new_var = variant;
      new_var.push_back('(');
      get_valid_variants(variants, new_var, num_open + 1, num_closed, n);
    }
  }

  std::vector<std::string> generateParenthesis(int n){
    std::vector<std::string> variants;
    get_valid_variants(variants, "(", 1, 0, n);
    return variants;
  }
};

int main() {
  const int n = 4;
  auto result = Solution().generateParenthesis(n);

  for(auto& s : result){
    std::cout << s << std::endl;
  }
}

