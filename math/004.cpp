#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

// return largest number for the given amount of digits
auto largest_digit_number(int num_digits){
  auto num = 0;

  for(int i = 0; i < num_digits; ++i){
    num *= 10;
    num += 9;
  }

  return num;
}

// reverse an input string
auto reverse_string(std::string entry){
  std::reverse(entry.begin(), entry.end());
  return entry;
}

// check if the input values are equal
template<typename Input_T>
auto is_equal(Input_T first, Input_T second){
  if(first == second) return true;
  else return false;
}

// check if the input integer is palindromic
auto is_palindrome(int entry){
  auto entry_string = std::to_string(entry);
  auto entry_string_reversed = reverse_string(entry_string);
  return is_equal(entry_string, entry_string_reversed);
}

// finds the largest palindrome for the multiplication of
//    two numbers of a given digit size
auto find_largest_palindrome(int num_digits){
  auto max = largest_digit_number(num_digits);
  auto min = pow(10, num_digits-1);

  auto largest_palindrome = 0;

  for(int i = max; i >= min; i--){
    for(int j = i; j >= min; j--){
      auto check = i*j;
      if(check <= largest_palindrome) break;
      if(is_palindrome(check)) largest_palindrome = check;
    }
  }

  return largest_palindrome;
}

int main(){
  int num_digits = 3;
  auto largest_palindrome = find_largest_palindrome(num_digits);
  std::cout << largest_palindrome << std::endl;
}