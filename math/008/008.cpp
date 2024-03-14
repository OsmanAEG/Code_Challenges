#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>

auto read_ints(std::string filename){
  std::ifstream read_digits(filename);
  std::vector<int> digits;

  std::string row_digits;

  while(std::getline(read_digits, row_digits)){
    for(char digit : row_digits){
      if(isdigit(digit)){
        int digit_in = digit - '0';
        digits.push_back(digit_in);
      }
    }
  }

  read_digits.close();
  return digits;
}

template<typename Vector_type, typename Int_type>
auto largest_product(Vector_type arr, Int_type N){
  long long int max = 0;

  for(int i = 0; i < arr.size()-N; ++i){
    long long int tmp = 1;
    for(int j = i; j < i + N; ++j){
      tmp *= arr[j];
    }

    max = std::max(max, tmp);
  }

  return max;
}

int main(){
  auto digits = read_ints("008.txt");
  auto max = largest_product(digits, 13);
  std::cout << max << std::endl;
}
