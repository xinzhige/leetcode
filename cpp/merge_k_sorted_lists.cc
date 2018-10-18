class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) {
      return nullptr;
    }
    int k = 0;
    for (int n = lists.size(); n > 1; n = k) {
      k = (n + 1) / 2;
      for (int i = 0; i < n / 2; ++i) {
        lists[i] = mergeTwoLists(lists[i], lists[i+k]);
      }
    }
    return lists[0];
  }

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode *head = &dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        head->next = l1;
        l1 = l1->next;
      } else {
        head->next = l2;
        l2 = l2->next;
      }
      head = head->next;
    }
    if (l1 == nullptr) {
      head->next = l2;
    } else {
      head->next = l1;
    }
    return dummy.next;
  }
};


// If the input is arrays
class Solution {
public:
  vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
    vector<int> result;
    if (arrays.empty()) {
      return result;
    }
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

  class mycomparison {
  public:
    bool operator() (const Node & a, const Node &b) {
      return a.val > b.val;
    }
  };
};
