class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> nums(n, -1); 
        for (int i = 0; i < edges.size(); ++i) {
            int x = find(nums, edges[i].first);
            int y = find(nums, edges[i].second);
            if (x == y) {
                return false; 
            }
            nums[x] = y;
        }
        return edges.size() == n - 1;
    }

private:
    int find(vector<int>& nums, int i) {
        if (nums[i] == -1) {
            return i; 
        } else {
            return find(nums, nums[i]); 
        } 
    }
};
