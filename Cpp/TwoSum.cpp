#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      map.insert({nums[i], i});
    }
    for (int i = 0; i < nums.size(); i++) {
      auto v = nums[i];
      auto itr = map.find(target - v);
      if (itr != map.end() && itr->second != i)
	return vector<int> {i, itr->second};
    }
    return vector<int> {};
  }
};
