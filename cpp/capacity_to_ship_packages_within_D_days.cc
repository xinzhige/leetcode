class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (can_finish(weights, D, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int can_finish(vector<int>& weights, int D, int cap) {
        int i = 0;
        for (int day = 0; day < D; day++) {
            for (int maxCap = cap - weights[i]; maxCap >= 0; maxCap -= weights[i]) {
                i++;
                if (i == weights.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};