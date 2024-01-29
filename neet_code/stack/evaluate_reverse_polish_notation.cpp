#include <iostream>
#include <vector>
#include <string>
#include <stack>

class Solution {
public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> expressions;

    for(auto& s : tokens){
      if(s == "+" || s == "-" || s == "/" || s == "*"){
        int result = 0;
        int a = expressions.top();
        expressions.pop();
        int b = expressions.top();
        expressions.pop();
        if(s == "+") result = b + a;
        if(s == "-") result = b - a;
        if(s == "/") result = b / a;
        if(s == "*") result = b * a;

        expressions.push(result);
      }else{
        expressions.push(std::stoi(s));
      }
    }

    return expressions.top();
  }
};

int main(){
  std::vector<std::string> tokens = {"4", "13", "5", "/", "+"};
  auto result = Solution().evalRPN(tokens);
  std::cout << result << std::endl;
}