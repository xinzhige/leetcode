class Solution {
public:
  int bulbSwitch(int n) {
    int i = 1;
    for (; i * i <= n; ++i);
    return i - 1;
  }
};


// By the built-in function sqrt
class Solution {
public:
  int bulbSwitch(int n) {
    return sqrt(n);
  }
};
