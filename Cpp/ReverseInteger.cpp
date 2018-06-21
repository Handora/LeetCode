#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
      int res = 0;
      while (x) {
	int y = x % 10;
	//cout << y << std::endl;
	if ((y >= 0 && res > (INT_MAX - y) / 10) || (y < 0 && res < (INT_MIN - y) / 10)) {
	   return 0;
	}
	res = res * 10 + y;
	x /= 10;
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  std::cout << s.reverse(-123);
  return 0;
}
