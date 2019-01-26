// Idea: like merge sort, merge two neighbors and double the gap.
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }
    int n = lists.size();
    for (int k = 1; k < n; k *= 2) {
      for (int i = 0; i < n - k; i += 2*k) {
        lists[i] = merge2Lists(lists[i], lists[i+k]);
      }
    }
    return lists[0];
  }

  ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *l = dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        l->next = l1;
        l1 = l1->next;
      } else {
        l->next = l2;
        l2 = l2->next;
      }
      l = l->next;
    }
    l->next = (l1 == nullptr ? l2 : l1);
    return dummy->next;
  }
};


// The input is arrays.
class Solution {
public:
  vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
    if (arrays.empty()) {
      return {};
    }
    vector<int> result;
    priority_queue<Node, vector<Node>, mycomparison> pq;
    for(int i = 0; i < arrays.size(); i++) {
      if(!arrays[i].empty()) {
        pq.emplace(i, 0, arrays[i][0]);
      }
    }
    while(!pq.empty()) {
      Node curr = pq.top();
      result.emplace_back(curr.val);
      pq.pop();
      if(curr.col < arrays[curr.row].size() - 1)
        pq.emplace(curr.row, curr.col + 1,
                   arrays[curr.row][curr.col+1]);
    }
    return result;
  }

  class Node {
  public:
    Node (int r, int c, int v) : row(r), col(c), val(v) {};
    int row;
    int col;
    int val;
  };

  struct mycomparison {
    bool operator() (const Node & a, const Node &b) {
      return a.val > b.val;
    }
  };
};
