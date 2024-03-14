#include <iostream>

int main(){
  int n = 4e6;
  int sum = 2;

  int fib_n_min_2 = 1;
  int fib_n_min_1 = 2;

  while(fib_n_min_1 < n){
    int fib_n = fib_n_min_1 + fib_n_min_2;
    if (fib_n % 2 == 0){
      sum += fib_n;
    }
    fib_n_min_2 = fib_n_min_1;
    fib_n_min_1 = fib_n;
  }

  std::cout << sum << std::endl;
}