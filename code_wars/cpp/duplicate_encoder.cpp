#include <string>
#include <iostream>
#include <unordered_map>

auto duplicate_encoder(const std::string& word){
  auto lower_case = [](const std::string& word){
    std::string lower_word = "";
    for(auto& character : word){
      lower_word += std::tolower(character);
    }
    return lower_word;
  };

  auto is_letter_recurring = [](const std::string& word){
    std::unordered_map<char, bool> letter_count;
    for(auto& character : word){
      if(letter_count.find(character) == letter_count.end()){
        letter_count[character] = true;
      }
      else{
        letter_count[character] = false;
      }
    }

    return letter_count;
  };

  std::string result = "";
  auto lower_word = lower_case(word);
  auto recurring_letters = is_letter_recurring(lower_word);
  for(auto& character : lower_word){
    if(recurring_letters[character]){
      result += "(";
    }
    else{
      result += ")";
    }
  }

  return result;
}

int main(){
  std::string word = "recede";
  auto result = duplicate_encoder(word);
  std::cout << result << std::endl;
}