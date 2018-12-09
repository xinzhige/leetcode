// Idea: use priority queue to store the character and its frequency.
// Each time pop two element in the queue and insert them into the result.
class Solution {
public:
  string reorganizeString(string S) {
    unordered_map<char, int> freq;
    for (const auto &c : S) {
      freq[c] += 1;
    }
    priority_queue<pair<int, char>> pq;
    for (const auto &f : freq) {
      if (f.second > (S.size() + 1) / 2) {
        return "";
      }
      pq.emplace(f.second, f.first);
    }
    string result("");
    while (pq.size() >= 2) {
      auto t1 = pq.top();
      pq.pop();
      auto t2 = pq.top();
      pq.pop();
      result.push_back(t1.second);
      result.push_back(t2.second);
      t1.first -= 1;
      t2.first -= 1;
      if (t1.first > 0) {
        pq.emplace(t1);
      }
      if (t2.first > 0) {
        pq.emplace(t2);
      }
    }
    if (pq.size() > 0) {
      result.push_back(pq.top().second);
    }
    return result;
  }
};


// Idea: use an integer to store each char and its frequency.
// For example, 'b' appears 9 times, its value is 100*9+('b'-'a').
// It is also easy to decode.
// Note: the first index to insert is 1 because 0 is reserver for the
// most frequent character.
class Solution {
public:
  string reorganizeString(string S) {
    int n = S.size();
    int index = 1;
    vector<int> count(26, 0);
    for (const auto &c : S) {
      count[c - 'a'] += 100;
    }
    for (int i = 0; i < 26; ++i) {
      count[i] += i;
    }
    sort(count.begin(), count.end());
    for (const auto &num : count) {
      int t = num / 100;
      char ch = 'a' + (num % 100);
      if (t > (n + 1) / 2) {
        return "";
      }
      for (int i = 0; i < t; ++i) {
        if (index >= n) {
          index = 0;
        }
        S[index] = ch;
        index += 2;
      }
    }
    return S;
  }
};
