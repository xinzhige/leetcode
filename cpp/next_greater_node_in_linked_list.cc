class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<int> s;
        for (auto l = head; l != nullptr; l = l->next) {
            res.push_back(l->val);
        }
        int n = res.size();
        for (int i = n - 1; i >= 0; i--) {
            int val = res[i];
            while (!s.empty() && s.top() <= val) {
                s.pop();
            }
            res[i] = s.empty() ? 0 : s.top();
            s.push(val);
        }
        return res;
    }
};