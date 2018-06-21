#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
  // sliding window
  int lengthOfLongestSubstring(string s) {
    int longest = 0;
    std::unordered_map <char, int> map{};

    for (int i = 0, j = 0; j < s.size(); j++) {
      if (map.count(s[j]) != 0) {
	int index = map[s[j]];
	i = max(i, index);
      }
      longest = max(longest, j - i + 1);
      map[s[j]] = j + 1; 
    }
    
    return longest;
  }
};

int main(int argc, char *argv[])
{
  Solution s;
  cout << s.lengthOfLongestSubstring("pwwkew");
  return 0;
}

