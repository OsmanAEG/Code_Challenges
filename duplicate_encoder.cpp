#include <string>
#include <iostream>

auto duplicate_encoder(const std::string& word){
  auto lower_case = [](const std::string& word){
    std::string lower_word = "";
    for(auto& character : word){
      lower_word += std::tolower(character);
    }
    return lower_word;
  };

  std::string result = "";
  auto lower_word = lower_case(word);
  for(auto& character : lower_word){
    int num_recurrences = 0;

    for(auto& character_check : lower_word){
      if(character == character_check){
        num_recurrences++;
      }
    }

    if(num_recurrences > 1){
      result += ')';
    }
    else{
      result += '(';
    }
  }

  return result;
}

int main(){
  std::string word = "recede";
  auto result = duplicate_encoder(word);
  std::cout << result << std::endl;
}