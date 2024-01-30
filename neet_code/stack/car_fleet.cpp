#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
  int carFleet(int target, std::vector<int>& position, std::vector<int>& speed){
    const auto N = position.size();
    int num_fleets = 1;

    std::vector<std::vector<double>> cars;

    // pairing the position and speed
    for(int i = 0; i < N; ++i){
      const std::vector<double> car = {(double)position[i], (double)speed[i]};
      cars.push_back(car);
    }

    std::sort(cars.begin(), cars.end());

    // checking number of fleets
    for(int i = N - 1; i >= 1; --i){
      const auto car_pos_1 = cars[i][0];
      const auto car_spd_1 = cars[i][1];

      const auto car_pos_2 = cars[i-1][0];
      const auto car_spd_2 = cars[i-1][1];

      const auto steps_1 = (target - car_pos_1)/car_spd_1;
      const auto steps_2 = (target - car_pos_2)/car_spd_2;

      if(steps_2 > steps_1) num_fleets += 1;
      else cars[i-1] = cars[i];
    }

    return num_fleets;
  }
};

int main(){
  int target = 10;
  std::vector<int> position = {0,4,2};
  std::vector<int> speed = {2,1,3};

  auto result = Solution().carFleet(target, position, speed);
  std::cout << result << std::endl;
  return 0;
}