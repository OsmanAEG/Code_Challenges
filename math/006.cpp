#include <iostream>

// return the sum squared difference
template<typename Int_type>
auto sum_square_diff(Int_type N){
  Int_type sum = 0;
  for(Int_type i = 1; i <= N; ++i){
    sum -= i*i;
    for(Int_type j = 1; j <= N; ++j){
      sum += i*j;
    }
  }

  return sum;
}

int main(){
  long long int N = 100;
  auto ssd = sum_square_diff(N);
  std::cout << ssd << std::endl;
}

