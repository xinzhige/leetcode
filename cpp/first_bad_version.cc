// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 1;
        int end = n;
        int mid = 0;
        while (begin < end) {
            mid = begin + (end - begin) / 2;
            if (isBadVersion(mid)) {
                end = mid; 
            } else {
                begin = mid + 1; 
            }
        }
        return end;
    }
};
