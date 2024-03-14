#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>

auto read_ints(std::string filename){
  std::ifstream read_digits(filename);
  std::vector<std::vector<int>> digits_2D;

  std::string row_digits;

  while(std::getline(read_digits, row_digits)){
    std::vector<int> digits_1D;
    for(char digit : row_digits){
      int digit_in = digit - '0';
      digits_1D.push_back(digit_in);
    }
    digits_2D.push_back(digits_1D);
  }

  read_digits.close();
  return digits_2D;
}