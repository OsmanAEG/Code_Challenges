#include <iostream>
#include <vector>

double going(int n){
  std::vector<double> sums(n);
  double sum = 0.0;

  sums[0] = 1.0;

  for(int i = 1; i < n; ++i) sums[i] = sums[i-1]/(n-i+1.0);
  for(int i = 0; i < n; ++i) sum += sums[i];

  return sum;
}

int main(){
  int n = 5;
  auto sum = going(n);
  std::cout << sum << std::endl;
}