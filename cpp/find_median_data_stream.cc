class MedianFinder {
public:
  /** initialize your data structure here. */
  MedianFinder(): () {

  }

  // Throw (push the num to the big heap)
  // Float (get the top of the big heap)
  // Throw (push it to the small heap)
  void addNum(int num) {
    big.push(num);
    small.push(big.top());
    big.pop();
    if (big.size() < small.size()) {
      big.push(small.top());
      small.pop();
    }
  }

  double findMedian() {
    if (big.size() > small.size()) {
      return (double)big.top();
    } else {
      return (big.top() + small.top()) * 0.5;
    }
  }

private:
  priority_queue<int> big;
  priority_queue<int, vector<int>, greater<int>> small;
};
