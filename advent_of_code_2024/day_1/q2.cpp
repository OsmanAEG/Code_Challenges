#include<algorithm>
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<unordered_map>
#include<vector>

int main() {
  std::ifstream codes("q1_input.txt");

  std::vector<int> first_codes;
  std::vector<int> second_codes;

  std::unordered_map<int, int> times_second;

  std::string code;
  std::string first_code;
  std::string second_code;

  while(std::getline(codes, code)) {
    std::istringstream code_stream(code);

    code_stream >> first_code >> second_code;

    first_codes.push_back(std::stoi(first_code));
    second_codes.push_back(std::stoi(second_code));
  }

  int sum = 0;

  for(int i = 0; i < second_codes.size(); ++i) {
    times_second[second_codes[i]] += 1;
  }

  for(int i = 0; i < first_codes.size(); ++i) {
    sum += first_codes[i]*times_second[first_codes[i]];
  }

  std::cout << sum << std::endl;
}