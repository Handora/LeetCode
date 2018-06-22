#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    if (re(x)) return true;
    return false;
  }

  bool re(int x) {
    int origin = x;
    int rev = 0;
    while (x) {
      int i = x % 10;
      if (rev > INT_MAX / 10 || ((rev == INT_MAX / 10) && i  > 7)) {
	return false;
      }
      rev = rev * 10 + i;
      x /= 10;
      
    }
    // cout << rev << " " << x << endl;
    return rev == origin;
  }
};

int main(int argc, char *argv[])
{
  Solution s;
  s.isPalindrome(121);
  return 0;
}

