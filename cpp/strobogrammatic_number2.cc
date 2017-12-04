// recursive
class Solution {
public:
  vector<string> findStrobogrammatic(int n) {
    return helper(n, n);
  }

  vector<string> helper(int n, int m) {
    if (n == 0) {
      return vector<string>{""};
    }
    if (n == 1) {
      return vector<string>{"0", "1", "8"};
    }
    vector<string> list = helper(n-2, m);
    vector<string> result;
    for (auto &s : list) {
      if (n != m) {
        result.emplace_back("0" + s + "0");
      }
      result.emplace_back("1" + s + "1");
      result.emplace_back("6" + s + "9");
      result.emplace_back("8" + s + "8");
      result.emplace_back("9" + s + "6");
    }
    return result;
  }
};


// iterative
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
      for (auto &s : result) {
        if (i != n) {
          tmp.emplace_back("0" + s + "0");
        }
        tmp.emplace_back("1" + s + "1");
        tmp.emplace_back("6" + s + "9");
        tmp.emplace_back("8" + s + "8");
        tmp.emplace_back("9" + s + "6");
      }
      result = tmp;
    }
    return result;
  }
};
