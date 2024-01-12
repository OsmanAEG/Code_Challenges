#include <vector>
#include <iostream>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map){
  const int n = snail_map.size();
  std::vector<int> snaily_boy(n*n);

  for(int i = 0; i < n; ++i){
    snaily_boy[i] = snail_map[0][n]
  }

  return {};
}

int main(){
  std::vector<std::vector<int>> array = {{1, 2, 3},
                                         {4, 5, 6},
                                         {7, 8, 9}};

  auto result = snail(array);
}