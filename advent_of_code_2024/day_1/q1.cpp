#include<algorithm>
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

int main() {
  std::ifstream codes("q1_input.txt");

  std::vector<int> first_codes;
  std::vector<int> second_codes;

  std::string code;
  std::string first_code;
  std::string second_code;

  while(std::getline(codes, code)) {
    std::istringstream code_stream(code);

    code_stream >> first_code >> second_code;

    first_codes.push_back(std::stoi(first_code));
    second_codes.push_back(std::stoi(second_code));
  }

  std::sort(first_codes.begin(), first_codes.end());
  std::sort(second_codes.begin(), second_codes.end());

  int sum = 0;

  for(int i = 0; i < first_codes.size(); ++i) {
    sum += std::abs(first_codes[i] - second_codes[i]);
  }

  std::cout << sum << std::endl;
}