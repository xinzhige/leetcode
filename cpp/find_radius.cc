class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i = 0;
        int result = 0;
        for (auto house : houses) {
            for (; i < heaters.size() - 1 && 
                   abs(heaters[i+1] - house) <= abs(heaters[i] - house); ++i); 
            result = max(result, abs(heaters[i] - house));
        }
        return result;
    }
};
