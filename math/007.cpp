#include <iostream>

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
auto nth_prime(Int_type n){
  if(n == 1) return static_cast<Int_type>(2);
  else if(n == 2) return static_cast<Int_type>(3);
  else{
    bool found_nth_prime = false;
    Int_type count = 2;
    Int_type num = 3;
    while(!found_nth_prime){
      num += 1;
      if(check_prime(num)) count += 1;
      if(count == n) found_nth_prime = true;
    }

    return num;
  }
}

int main(){
  long long int n = 10001;
  auto prime = nth_prime(n);
  std::cout << prime << std::endl;
}