// O(n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for (const auto & c: citations) {
            if (c >= n)  {
                count[n] += 1;
            } else {
                count[c] += 1;
            }
        }
        int total = 0;
        for (int i = n; i >= 0; i--) {
            total += count[i];
            if (total >= i) {
                return i;
            }
        }
        return 0;
    }
};

// O(nlgn)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        for (int i = 0; i < n; i++) {
          if (i >= citations[i]) {
    	    return i;
          }
        }
        return n;  
    }
};
