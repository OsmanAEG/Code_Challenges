#include <iostream>
#include <cmath>
#include <vector>

// find primes
template<typename Int_type>
auto sieve_of_erastosthenes(Int_type N){
  std::vector<bool> is_prime(N, true);

  is_prime[0] = false;

  if(is_prime.size() <= 1) return is_prime;

  is_prime[1] = false;

  for(Int_type i = 2; i < N; ++i){
    if(is_prime[i]){
      for(Int_type j = i*i; j < N; j += i){
        is_prime[j] = false;
      }
    }
  }
  return is_prime;
}

template<typename Int_type>
auto prime_sum(Int_type N){
  Int_type sum = 0;
  auto is_prime = sieve_of_erastosthenes(N);
  for(Int_type i = 2; i < N; ++i){
    if(is_prime[i]){
      sum += i;
    }
  }

  return sum;
}

int main(){
  long long int N = 2E6;
  auto sum = prime_sum(N);
  std::cout << sum << std::endl;
}