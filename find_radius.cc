class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i = 0;
        int result = 0;
        for (auto house : houses) {
            for (; i < heaters.size() - 1 && 
                   heaters[i] + heaters[i + 1] <= 2 * house; ++i); 
            result = max(result, abs(heaters[i] - house));
        }
        return result;
    }
};
