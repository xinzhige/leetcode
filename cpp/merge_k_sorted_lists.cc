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
    priority_queue<Node, vector<Node>, Comparison> pq;
    for(int i = 0; i < arrays.size(); i++) {
      if(!arrays[i].empty()) {
        pq.emplace(i, 0, arrays[i][0]);
      }
    }
    vector<int> result;
    while(!pq.empty()) {
      Node node = pq.top();
      result.push_back(node.val);
      pq.pop();
      // Note it determines if there is a "next" element.
      if(node.col < arrays[node.row].size() - 1)
        pq.emplace(node.row, node.col + 1,
                   arrays[node.row][node.col+1]);
    }
    return result;
  }

  struct Node {
    Node (int r, int c, int v) : row(r), col(c), val(v) {};
    int row;
    int col;
    int val;
  };

  struct Comparison {
    bool operator() (const Node & a, const Node &b) {
      return a.val > b.val;
    }
  };
};
