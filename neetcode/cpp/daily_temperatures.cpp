#include <iostream>
#include <vector>
#include <stack>

class Solution{
public:
  std::vector<int> dailyTemperatures(std::vector<int>& temperatures){
    const auto N = temperatures.size();
    int running_days = 1;

    std::vector<int> days_to_higher(N, 0);
    std::stack<int> temp_stack;

    temp_stack.push(temperatures[N-1]);
    int num_removed = 0;

    for(int i = N - 2; i >= 0; --i){
      if(temp_stack.top() > temperatures[i]){
        temp_stack.push(temperatures[i]);
        days_to_higher[i] = 1;
      }else{
        while(!temp_stack.empty()){
          days_to_higher[i] += 1;

          if(temp_stack.top() > temperatures[i]){
            num_removed = 0;
            break;
          }

          temp_stack.pop();
          num_removed += 1;
        }

        if(temp_stack.empty()) days_to_higher[i] = 0;
        else days_to_higher[i] += num_removed;

        temp_stack.push(temperatures[i]);
      }
    }

    return days_to_higher;
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