// Idea: function a running time=b.start-a.start+a.end-z.end, where
// b is next function called and z is the last function called.
// Use stack to store all start time.
class Solution {
public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> result(n, 0);
    stack<int> st;
    int pre_time = 0;
    for (const auto &log : logs) {
      int found1 = log.find(":");
      int found2 = log.find_last_of(":");
      int idx = stoi(log.substr(0, found1));
      string type = log.substr(found1 + 1, found2 - found1 - 1);
      int time = stoi(log.substr(found2 + 1));
      if (!st.empty()) {
        result[st.top()] += time - pre_time;
      }
      pre_time = time;
      if (type == "start") {
        st.push(idx);
      } else {
        auto t = st.top();
        st.pop();
        result[t] += 1;
        pre_time += 1;
      }
    }
    return result;
  }
};
