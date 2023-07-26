#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
  std::vector<T> unique_list;

  if(iterable.size() == 0){
    return unique_list;
  }

  unique_list.push_back(iterable[0]);

  for(auto& el : iterable){
    if(el != unique_list.back()){
      unique_list.push_back(el);
    }
  }

  return unique_list;
}

std::vector<char> uniqueInOrder(const std::string& iterable){
  std::vector<char> unique_list;

  if(iterable.size() == 0){
    return unique_list;
  }

  unique_list.push_back(iterable[0]);

  for(auto& el : iterable){
    if(el != unique_list.back()){
      unique_list.push_back(el);
    }
  }

  return unique_list;
}

int main(){
  auto result = uniqueInOrder("AAAABBBCCDAABBB");
  for(int i = 0; i < result.size(); ++i){
    std::cout << result[i] << std::endl;
  }
}