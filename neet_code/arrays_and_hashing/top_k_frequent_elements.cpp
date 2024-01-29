#include <vector>
#include <iostream>
#include <unordered_map>

int partition(std::vector<int>& vec, int low, int high, std::unordered_map<int, int>& num_count) {
  int pivot = num_count[vec[high]];
  int i = low - 1;

  for(int j = low; j <= high; ++j) {
    if(num_count[vec[j]] < pivot) {
      ++i;
      std::swap(vec[i], vec[j]);
    }
  }

  std::swap(vec[i+1], vec[high]);
  return i+1;
}

void quick_sort(std::vector<int>& vec, int low, int high, std::unordered_map<int, int>& num_count) {
  if(low < high) {
    int pi = partition(vec, low, high, num_count);
    quick_sort(vec, low, pi - 1, num_count);
    quick_sort(vec, pi + 1, high, num_count);
  }
}

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> num_count;
    std::vector<int> max_values(k);
    std::vector<int> unique_nums;

    for(int i = 0; i < nums.size(); ++i) num_count[nums[i]] += 1;
    for(auto i = num_count.begin(); i != num_count.end(); ++i) unique_nums.push_back(i->first);

    quick_sort(unique_nums, 0, unique_nums.size() - 1, num_count);
    for(int i = 0; i < k; ++i) max_values[i] = unique_nums[unique_nums.size() - 1 - i];

    return max_values;
  }
};

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    auto result = Solution().topKFrequent(nums, k);
    for(int i = 0; i < k; ++i) {
      std::cout << result[i] << std::endl;
    }
}