#include<iostream>

struct successive_add{
  int a;
  successive_add(int a_in): a(a_in){}
  successive_add operator()(int b){return successive_add(a + b);}

  operator int() const{return a;}
};

successive_add add(int n){return{n};}

int main(){
  auto result = add(1)(2)(3);
  std::cout << result << std::endl;
}