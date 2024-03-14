#include <iostream>
#include <cmath>

auto is_condition_satisfied(int a, int b, int N){
  auto c = N - a - b;
  if(a*a + b*b == c*c) return true;
  else return false;
}

auto binary_search_pyth_b(int a, int N){
  int b_low  = 1;
  int b_high = N;

  while(b_low <= b_high){
    int b = b_low + (b_high - b_low)/2;
    int c = N - a - b;
    if(is_condition_satisfied(a, b, N)) return b;
    else if(a*a + b*b < c*c) b_low = b + 1;
    else b_high = b - 1;
  }

  return 0;
}

auto special_pythagoerean_triplet(int N){
  for(int a = 1; a < N; ++a){
    auto b = binary_search_pyth_b(a, N);
    if(b) return a*b*(N-a-b);
  }

  return 0;
}

int main(){
  int N = 1000;
  auto result = special_pythagoerean_triplet(N);
  std::cout << result << std::endl;
}