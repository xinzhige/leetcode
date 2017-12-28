class TwoSum {
public:
  /** Initialize your data structure here. */
  TwoSum() {

  }
  /** Add the number to an internal data structure.. */
  void add(int number) {
    nums[number] += 1;
  }

  /** Find if there exists any pair of numbers which sum is equal to the value. */
  bool find(int value) {
    for (const auto &curr : nums) {
      int diff = value - curr.first;
      if (nums.count(diff) > 0 &&
          (curr.first != diff || curr.second > 1)) {
        return true;
      }
    }
    return false;
  }

private:
  unordered_map<int, int> nums;
};


// By unordered_multiset
class TwoSum {
public:
  /** Initialize your data structure here. */
  TwoSum() {

  }
  /** Add the number to an internal data structure.. */
  void add(int number) {
    nums.insert(number);
  }

  /** Find if there exists any pair of numbers which sum is equal to the value. */
  bool find(int value) {
    for (const auto &curr : nums) {
      int diff = value - curr;
      int cnt = (curr == diff ? 1 : 0);
      if (nums.count(diff) > cnt) {
        return true;
      }
    }
    return false;
  }

private:
  unordered_multiset<int> nums;
};
