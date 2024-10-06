#include<iostream>
#include<climits>

class MinStack {
public:
    int* idx, min;
    MinStack() {
    }

    void push(int val) {
    }

    void pop() {
    }

    int top() {
    }

    int getMin() {
    }
};

int main(){
  MinStack minstack;
  minstack.push(2);
  minstack.push(0);
  minstack.push(3);
  minstack.push(0);
  std::cout << minstack.getMin() << std::endl;
  minstack.pop();
  std::cout << minstack.getMin() << std::endl;
  minstack.pop();
  std::cout << minstack.getMin() << std::endl;
  minstack.pop();
  std::cout << minstack.getMin() << std::endl;
}