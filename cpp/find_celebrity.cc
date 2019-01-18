// Idea: first, select a candidate in the first round;
// second, try to determine if there is no such celebrity.
bool knows(int a, int b);

class Solution {
public:
  int findCelebrity(int n) {
    int candidate = 0;
    for (int i = 1; i < n; ++i) {
      if(knows(candidate, i)) {
        candidate = i;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i != candidate &&
          (knows(candidate, i) || !knows(i, candidate))) {
        return -1;
      }
    }
    return candidate;
  }
};
