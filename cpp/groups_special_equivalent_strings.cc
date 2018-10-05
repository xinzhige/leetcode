class Solution {
public:
  int numSpecialEquivGroups(vector<string>& A) {
    unordered_set<string> seen;
    for (const auto &a : A) {
      string odd;
      string even;
      for (int i = 0; i < a.size(); ++i) {
        if ((i % 2) == 1) {
          odd += a[i];
        } else {
          even += a[i];
        }
      }
      sort(begin(odd), end(odd));
      sort(begin(even), end(even));
      seen.insert(odd + even);
    }
    return seen.size();
  }
};
