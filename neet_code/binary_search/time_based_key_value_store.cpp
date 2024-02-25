#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

class TimeMap{
public:
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> key_map;
  TimeMap(){}

  int search(std::vector<std::pair<int, std::string>>& vec, int target){
    if(vec.size() == 0) return -1;

    if(vec.size() == 1){
      if(vec[0].first <= target) return 0;
      else return -1;
    }

    int idx_min = 0;
    int idx_max = vec.size() - 1;

    while(idx_min <= idx_max){
      auto idx_mid = (idx_min + idx_max)/2;

      if(vec[idx_mid].first == target) return idx_mid;

      if(vec[idx_mid].first > target) idx_max = idx_mid - 1;
      else if(vec[idx_mid].first < target) idx_min = idx_mid + 1;
    }

    return idx_max;
  }

  void set(std::string key, std::string value, int timestamp){
    std::pair<int, std::string> pair = std::make_pair(timestamp, value);
    key_map[key].push_back(pair);
  }

  std::string get(std::string key, int timestamp){
    if(key_map[key].size() == 0) return "";
    const auto idx = search(key_map[key], timestamp);
    if(idx == -1) return "";
    return key_map[key][idx].second;
  }
};

int main(){
  TimeMap timeMap = TimeMap();
  std::cout << "null" << std::endl;

  timeMap.set("foo", "bar", 1);
  std::cout << "null" << std::endl;

  std::cout << timeMap.get("foo", 1) << std::endl;
  std::cout << timeMap.get("foo", 3) << std::endl;

  timeMap.set("foo", "bar2", 4);
  std::cout << "null" << std::endl;

  std::cout << timeMap.get("foo", 4) << std::endl;
  std::cout << timeMap.get("foo", 5) << std::endl;

  return 0;
}