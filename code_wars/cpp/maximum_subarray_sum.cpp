#include <vector>
#include <iostream>

int maxSequence(const std::vector<int>& arr){
  int max = 0;
  int i_start = 0;

  while(i_start < arr.size()){
    int running_sum = 0;
    for(int i = i_start; i < arr.size(); ++i){
      running_sum += arr[i];

      if(running_sum > max) max = running_sum;
    }

    ++i_start;
  }

  return max;
}

int main(){
  std::vector<int> test = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  auto result = maxSequence(test);

  std::cout << result << std::endl;
}