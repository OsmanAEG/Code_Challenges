#include<iostream>
#include<climits>

class MinStack{
public:
  int* idx;
  int* min;

  MinStack(){
    idx = new int[50];
    min = new int[51];
    min[0] = INT_MAX;
  }

  void push(int val){
    const auto last_min = min[0];
    idx += sizeof(int);
    min += sizeof(int);
    min[0] = std::min(last_min, val);
    idx[0] = val;
  }

  void pop(){
    idx -= sizeof(int);
    min -= sizeof(int);
  }

  int top(){return idx[0];}
  int getMin(){return min[0];}
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