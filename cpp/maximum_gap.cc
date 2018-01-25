class Solution {
	public:
		int maximumGap(vector<int> &num) { 
			if (num.empty() || num.size() < 2) {
				return 0;
			}
			int Max = *max_element(num.begin(), num.end());
			int Min = *min_element(num.begin(), num.end());
			int gap = (int)ceil((double)(Max - Min)/(num.size() - 1));
			int bucket_num = (int)ceil((double)(Max - Min) / gap);
			vector<int> buckets_min(bucket_num, INT_MAX);	
			vector<int> buckets_max(bucket_num, INT_MIN);
			for (int i = 0; i < num.size(); i++) {
				if (num[i] != Max && num[i] != Min) {
    				int idx = (num[i] - Min) / gap;
    				buckets_min[idx] = min(buckets_min[idx], num[i]);
    				buckets_max[idx] = max(buckets_max[idx], num[i]);
				}
			}
			int ans = INT_MIN;
			int previous = Min;
			for (int i = 0; i < bucket_num; i++) {
				if (buckets_min[i] != INT_MAX && buckets_max[i] != INT_MIN) {
    				ans = max(ans, buckets_min[i] - previous);
    				previous = buckets_max[i];
				}
			}
			ans = max(ans, Max - previous);
			return ans;
		}
};
