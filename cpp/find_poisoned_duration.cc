class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result = 0;
        int n = timeSeries.size();
        for (int i = 0; i < n; ++i) {
            int gap = timeSeries[i + 1] - timeSeries[i];
            if (i == n - 1 || duration < gap) {
                result += duration; 
            } else {
                result += gap; 
            } 
        }
        return result;
    }
};
