// Idea: sort the array by comparing two numbers in the ordering of them,
// for example, 9 and 51, comparing 9+51*10=519 > 51+9*100=951.
class Solution {
public:
  string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), mycomparison);
    string result;
    for(const int &num : nums){
      result += to_string(num);
    }
    return result.front() == '0' ? "0" : result;
  }
  struct Comparison {
    bool operator() (const int &a, const int &b){
      long long sizea = 10;
      long long m = a;
      for (; sizea <= m; sizea *= 10);
      long long n = b;
      long long sizeb = 10;
      for (; sizeb <= n; sizeb *= 10);
      return (m + sizea * n) < (n + sizeb * m);
    }
  }mycomparison;
  struct Comparison2 {
    bool operator() (const int &a, const int &b){
      string sa = to_string(a);
      string sb = to_string(b);
      string order1 = sa + sb;
      string order2 = sb + sa;
      return order1 > order2;
    }
  }mycomparison2;
};
