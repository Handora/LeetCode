#include <string>
#include <climits>


using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    int i = skipSpaces(str, 0);
    if (i == str.size()) return 0;
    
    if (isdigit(str[i])) {
      return consume(str, i, true);
    } else if (isOp(str, i) == 1 && i + 1 != str.size()) {
      return consume(str, i + 1, true);
    } else if (isOp(str, i) == -1 && i + 1 != str.size()) {
      return consume(str, i + 1, false);
    } else {
      return 0;
    }
  }

  int consume(const string &str, int i, bool isPlus) {
    long sum = 0;
    while (i < str.size() && isdigit(str[i])) {
      sum = sum * 10 +  str[i] - '0';
      i ++;
      if (sum > INT_MAX && isPlus) {
	return INT_MAX;
      }
      if (sum > INT_MAX + (long)1 && !isPlus) {
	return INT_MIN;
      }
    }
    if (isPlus) return sum;
    return -1 * sum;
  }

  int isOp(const string &str, int i) {
    if (str[i] == '+') return 1;
    if (str[i] == '-') return -1;
    return 0;
  }

  int skipSpaces(const string &str, int i) {
    for (int i = 0; i < str.size(); i++) {
      if (str[i] != ' ') {
	return i;
      }
    }
    return str.size();
  }
};
