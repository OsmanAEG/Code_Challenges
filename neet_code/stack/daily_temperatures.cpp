#include <iostream>
#include <vector>
#include <stack>

class Solution{
public:
  std::vector<int> dailyTemperatures(std::vector<int>& temperatures){
    const int N = temperatures.size();

    std::vector<int> days_until_higher(N, 0);
    std::stack<std::vector<int>> smaller_temps;

    smaller_temps.push({temperatures[N-1], N-1});

    for(int i = N - 2; i >= 0; --i){
      if(smaller_temps.top()[0] > temperatures[i]){
        smaller_temps.push({temperatures[i], i});
        days_until_higher[i] = 1;
      }else{
        while(!smaller_temps.empty()){
          if(smaller_temps.top()[0] > temperatures[i]){
            days_until_higher[i] = smaller_temps.top()[1] - i;
            smaller_temps.push({temperatures[i], i});
            break;
          }
          smaller_temps.pop();
        }

        smaller_temps.push({temperatures[i], i});
      }
    }

    return days_until_higher;
  }
};

int main(){
  std::vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
  auto result = Solution().dailyTemperatures(input);

  std::cout << "[";
  for(auto& num : result){
    std::cout << num << ", ";
  }
  std::cout << "]" << std::endl;
}