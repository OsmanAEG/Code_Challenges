#include <iostream>
#include <vector>
#include <cmath>

class Solution1{
public:
  std::vector<int> plusOne(std::vector<int>& digits){
    const int N = digits.size();
    const int max = pow(10, N);

    long long int value = digits[0];

    for(int i = 1; i < N; ++i){
      value *= 10;
      value += digits[i];
    }

    value += 1;

    const int N_new = (max - value == 0) ? N + 1 : N;
    std::vector<int> new_digits(N_new, 0);

    for(int i = N_new - 1; i >= 0; --i){
      new_digits[i] = value % 10;
      value /= 10;
    }

    return new_digits;
  }
};

class Solution2{
public:
  std::vector<int> plusOne(std::vector<int>& digits){
    const int N = digits.size();

    bool last_9 = (digits[N-1] == 9) ? true : false;

    for(int i = N - 1; i >= 0; --i){
      if(!last_9){
        digits[i] += 1;
        return digits;
      }else if(last_9 && digits[i] != 9){
        digits[i] += 1;
        return digits;
      }else{
        digits[i] = 0;
      }
    }

    digits.push_back(0);
    digits[0] = 1;

    return digits;
  }
};

int main(){
  std::vector<int> digits = {9};
  const auto result = Solution2().plusOne(digits);

  std::cout << "[";
  for(int i = 0; i < result.size(); ++i){
    std::cout << result[i] << ", ";
  }
  std::cout << "]" << std::endl;

  return 0;
}