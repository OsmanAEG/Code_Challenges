#include <iostream>
#include <vector>
#include <map>

int score(const std::vector<int>& dice){
  std::map<int, int> count;

  for(int i = 0; i < dice.size(); ++i){
    count[dice[i]]++;
  }

  int points = 0;

  if(count[1] < 3 && count[1] >= 0) points += count[1]*100;
  else                              points += 1000 + (count[1]-3)*100;

  if(count[5] < 3 && count[5] >= 0) points += count[5]*50;
  else                              points += 500 + (count[5]-3)*50;

  std::vector<int> commons = {2, 3, 4, 6};

  for(int i = 0; i < commons.size(); ++i){
    if(count[commons[i]] >= 3) points += 100*commons[i];
  }

  return points;
}

int main(){
  std::vector<int> rolls = {2, 4, 4, 5, 4};
  auto result = score(rolls);
  std::cout << result << std::endl;
}