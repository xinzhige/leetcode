// Recursive
class Solution {
public:
  vector<string> findStrobogrammatic(int n) {
    return strobogrammaticNumber(n, n);
  }

  vector<string> strobogrammaticNumber(int n, int m) {
    if (n == 0) {
      return {""};
    }
    if (n == 1) {
      return {"0", "1", "8"};
    }
    vector<string> rest = strobogrammaticNumber(n - 2, m);
    vector<string> result;
    for (const auto &s : rest) {
      if (n != m) {
        result.push_back("0" + s + "0");
      }
      result.push_back("1" + s + "1");
      result.push_back("6" + s + "9");
      result.push_back("8" + s + "8");
      result.push_back("9" + s + "6");
    }
    return result;
  }
};


// Iterative
class Solution {
public:
  vector<string> findStrobogrammatic(int n) {
    vector<string> first{""};
    vector<string> second{"0", "1", "8"};
    vector<string> result = first;
    if ((n % 2) == 1) {
      result = second;
    }
    for (int i = (n % 2) + 2; i <= n; i += 2) {
      vector<string> tmp;
      for (const auto &s : result) {
        if (i != n) {
          tmp.push_back("0" + s + "0");
        }
        tmp.push_back("1" + s + "1");
        tmp.push_back("6" + s + "9");
        tmp.push_back("8" + s + "8");
        tmp.push_back("9" + s + "6");
      }
      result = tmp;
    }
    return result;
  }
};
