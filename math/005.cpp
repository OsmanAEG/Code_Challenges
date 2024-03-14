#include <iostream>
#include <vector>

// greatest common divisor (gcd)
template<typename Int_type>
auto eucliden_algo(Int_type first, Int_type second){
  while(first != second){
    if(first > second) first -= second;
    else second -= first;
  }

  return first;
}

// least common multiple (lcm)
template<typename Int_type>
auto smallest_common_multiple(Int_type first, Int_type second){
  return first*second/eucliden_algo(first, second);
}

// finds the smallest evenly divisible number
template<typename Int_type>
auto divisible_up_to(Int_type N){
  Int_type min = 1;

  for(Int_type i = 2; i <= N; ++i){
    min = smallest_common_multiple(min, i);
  }

  return min;
}

int main(){
  long long int num = 20;
  auto min = divisible_up_to(num);
  std::cout << min << std::endl;
}