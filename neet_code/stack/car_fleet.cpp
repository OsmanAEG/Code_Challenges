#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

class Solution {
public:
  int carFleet(int target, std::vector<int>& position, std::vector<int>& speed){
    const auto N = position.size();
    std::map<int, int> old_fleets;

    int fleet_count = 0;

    for(int i = 0; i < N; ++i){old_fleets[position[i]] = speed[i];}

    while(!old_fleets.empty()){
      std::map<int, int> new_fleets;

      for(auto i = old_fleets.begin(); i != old_fleets.end(); ++i){
        const auto new_pos = i->first + i->second;
        new_fleets[new_pos] = i->second;
      }

      std::cout << std::distance(new_fleets.upper_bound(target), new_fleets.end()) << std::endl;
      fleet_count += std::distance(new_fleets.upper_bound(target), new_fleets.end());
      new_fleets.erase(new_fleets.lower_bound(target), new_fleets.end());

      old_fleets = new_fleets;
    }

    return fleet_count;
  }
};

int main(){
  int target = 12;
  std::vector<int> position = {10, 8, 0, 5, 3};
  std::vector<int> speed = {2, 4, 1, 1, 3};

  auto result = Solution().carFleet(target, position, speed);
  std::cout << result << std::endl;
  return 0;
}