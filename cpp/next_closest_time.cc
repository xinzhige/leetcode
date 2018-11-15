class Solution {
public:
  string nextClosestTime(string time) {
    string result("0000");
    vector<int> range{600, 60, 10, 1};
    int minutes = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
    for (int i = 1; i <= 1440; ++i) {
      int next = (minutes + i) % 1440;
      int d = 0;
      for (; d < 4; ++d) {
        result[d] = '0' + next / range[d];
        next %= range[d];
        if (time.find(result[d]) == string::npos) {
          break;
        }
      }
      if (d >= 4) {
        break;
      }
    }
    return result.substr(0, 2) + ":" + result.substr(2);
  }
};
