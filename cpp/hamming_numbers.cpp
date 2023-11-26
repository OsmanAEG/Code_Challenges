#include <cstdint>
#include <iostream>

bool check_hamber(int num){
  if(num == 1) return true;

  if     (num % 2 == 0) return check_hamber(num / 2);
  else if(num % 3 == 0) return check_hamber(num / 3);
  else if(num % 5 == 0) return check_hamber(num / 5);

  return false;
}

uint64_t hamber(int n){
  if(n == 1) return 1;

  int nth = 2;
  int num = 2;

  while(nth <= n){
    if(check_hamber(num)) nth++;
    num++;
  }

  num--;

  return num;
}

int main(int argc, char* argv[]){
  int n = std::atoi(argv[1]);
  std::cout << hamber(n) << std::endl;

  return 0;
}