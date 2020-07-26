class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1;
        int right = get_max(piles); 
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (!can_finish(piles, mid, H)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    bool can_finish(vector<int>& piles, int speed, int H) {
        int count = 0;
        for (int n : piles) {
            count += time_count(n, speed);
        }
        return count <= H;
    }

    int time_count(int n, int speed) {
        if (n % speed == 0) {
            return n / speed;
        }
        return (n / speed) + 1;
    }

    int get_max(vector<int>& piles) {
        int res = 0;
        for (int n : piles) {
            res = max(res, n);
        }
        return res;
    }
};