#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  bool isValid(std::string s){
    std::stack<char> opened_brackets;

    if(s.size() == 1) return false;

    for(auto& c : s){
      if(c == '(' || c == '[' || c == '{'){
        opened_brackets.push(c);
      }else if(opened_brackets.size() > 0){
        if(c == ')' && opened_brackets.top() == '(') opened_brackets.pop();
        else if(c == ']' && opened_brackets.top() == '[') opened_brackets.pop();
        else if(c == '}' && opened_brackets.top() == '{') opened_brackets.pop();
        else return false;
      }else{
        return false;
      }
    }

    if(opened_brackets.size() != 0) return false;
    return true;
  }
};

int main(){
  std::string s = ")(){}";
  auto result = Solution().isValid(s);
  std::cout << result << std::endl;
}