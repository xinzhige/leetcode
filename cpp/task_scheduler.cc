class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> count(26, 0);
    for (const auto &c : tasks) {
      count[c - 'A'] += 1;
    }
    sort(count.begin(), count.end());
    int time = 0;
    while (count[25] > 0) {
      int i = 0;
      while (i <= n) {
        if (count[25] == 0) {
          break;
        }
        if (i < 26 && count[25 - i] > 0) {
          count[25 - i] -= 1;
        }
        time += 1;
        ++i;
      }
      sort(count.begin(), count.end());
    }
    return time;
  }
};


// Count idle slots
class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> count(26, 0);
    for (const auto &c : tasks) {
      count[c - 'A'] += 1;
    }
    sort(count.begin(), count.end());
    int max_val = count[25] - 1;
    int idle_slots = max_val * n;
    for (int i = 24; i >= 0; --i) {
      if (count[i] > 0) {
        idle_slots -= min(max_val, count[i]);
      }
    }
    if (idle_slots > 0) {
      return idle_slots + tasks.size();
    } else {
      return tasks.size();
    }
  }
};
