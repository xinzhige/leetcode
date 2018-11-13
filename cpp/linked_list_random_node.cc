// Time: O(1), space: O(n)
class Solution {
public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head) {
    for (; head != nullptr; head = head->next) {
      nums.push_back(head->val);
    }
  }

  /** Returns a random node's value. */
  int getRandom() {
    int r = rand() % nums.size();
    return nums[r];
  }
private:
  vector<int> nums;
};


// Time: O(n), space: O(1)
class Solution {
public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head) : node(head) {}

  /** Returns a random node's value. */
  int getRandom() {
    assert(node != nullptr);
    int result = node->val;
    int i = 2;
    for (auto curr = node->next; curr != nullptr; curr = curr->next) {
      int j = rand() % i;
      if (j == 0) {
        result = curr->val;
      }
      ++i;
    }
    return result;
  }

private:
  ListNode *node;
};
