// use unordered_map time: O(max(m, n)), space O(max(m, n)) 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mymap;
        vector<int> result;
        for (int i = 0; i < nums1.size(); ++i) {
            mymap[nums1[i]] += 1; 
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (mymap.find(nums2[i]) != mymap.end() &&
                mymap[nums2[i]] >= 1) {
                result.emplace_back(nums2[i]);     
                mymap[nums2[i]] -= 1;
            } 
        }
        return result;
    }
};


// sort arrays time O(nlgn) space O(1)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> result;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                result.emplace_back(nums1[i]); 
                i += 1;
                j += 1;
            } else if (nums1[i] < nums2[j]) {
                i += 1; 
            } else {
                j += 1; 
            } 
        }
        return result;
    }
};
