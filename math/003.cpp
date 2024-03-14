#include <iostream>
#include <cmath>

template<typename Scalar_type>
auto sqrt(Scalar_type entry){
  return static_cast<Scalar_type>(std::sqrt(entry));
}

template<typename Int_type>
auto check_prime(Int_type entry){
  if(entry   == 1) return false;
  if(entry   == 2) return true;
  if(entry%2 == 0) return false;

  for(Int_type i = 3; i < entry; i += 2){
    if(entry%i == 0) return false;
  }

  return true;
}

template<typename Int_type>
auto largest_prime_factor(Int_type entry){
  auto check_factor = sqrt(entry);
  bool largest_prime = false;

  for(int i = check_factor; i >= 2; i--){
    if(entry%i == 0){
      if(check_prime(i)) return i;
    }
  }

  return 1;
}

int main(){
  long int num = 600851475143;
  auto result = largest_prime_factor(num);

  std::cout << result << std::endl;
}