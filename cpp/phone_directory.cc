class PhoneDirectory {
public:
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
  PhoneDirectory(int maxNumbers) {
    idx = 0;
    numbers.resize(maxNumbers);
    used.resize(maxNumbers);
    iota(numbers.begin(), numbers.end(), 0);
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (idx == numbers.size()) {
      return -1;
    }
    int number = numbers[idx];
    idx += 1;
    used[number] = true;
    return number;
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    if (number < 0 || number >= numbers.size()) {
      return false;
    }
    return !used[number];
  }

  /** Recycle or release a number. */
  void release(int number) {
    if (number < 0 || number >= numbers.size() || !used[number]) {
      return;
    }
    used[number] = false;
    idx -= 1;
    numbers[idx] = number;
  }

private:
  int idx;
  vector<int> numbers;
  vector<bool> used;
};
/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
