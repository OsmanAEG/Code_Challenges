#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

unsigned long long solution1(const std::vector<unsigned long long>& arr){
  auto min = *std::min_element(arr.begin(), arr.end());

  for(int i = 0; i < arr.size(); ++i){
    auto arr_i = arr[i];
    while(arr_i > min) arr_i -= min;
    min = std::min(arr_i, min);
  }

  return min*arr.size();
}

unsigned long long solution2(const std::vector<unsigned long long>& arr){
  std::map<unsigned long long, int> arr_map;
  for(size_t i = 0; i < arr.size(); ++i) arr_map[arr[i]];

  auto min = arr_map.begin()->first;

  while(arr_map.size() > 1){
    auto max = (--arr_map.end())->first;
    arr_map.erase(max);

    while(max > min){
      max -= min;
      arr_map.erase(max);
    }

    min = std::min(max, min);
  }

  return min*arr.size();
}

unsigned long long solution3(const std::vector<unsigned long long>& arr){
  std::map<unsigned long long, int> arr_map;
  for(size_t i = 0; i < arr.size(); ++i) arr_map[arr[i]];

  auto max = (arr_map.rbegin())->first;
  arr_map.erase(max);

  while(arr_map.size() > 0){
    auto next = (arr_map.rbegin())->first;

    while(max > next){
      max -= next;
      arr_map.erase(max);
    }

    arr_map[max];
    max = next;
    arr_map.erase(next);
  }

  return max*arr.size();
}


int main(){
  std::vector<unsigned long long> X = {60,12,96,48,60,24,72,36,72,72,48};
  auto sum = solution3(X);
  std::cout << sum << std::endl;

  return 0;
}