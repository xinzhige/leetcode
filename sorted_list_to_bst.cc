// top-down
class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    int node_num = 0;
    ListNode *node = head;
    while (node) {
      ++node_num;
      node = node->next;
    }
    return sortedList2BST(head, node_num);
  }
  
  TreeNode *sortedList2BST(ListNode *head, int node_num) {
    if (node_num == 0) {
      return NULL;
    }
    int left_num = node_num/2;
    int right_num = node_num - left_num - 1;
    ListNode *mid_node = head;
    for (int i=0; i < left_num; ++i) {
      mid_node = mid_node->next;
    }
    TreeNode *root = new TreeNode(mid_node->val);
    root->left = sortedList2BST(head,left_num);
    root->right = sortedList2BST(mid_node->next, right_num);
  }
};

// bottom-up
class Solution {
public:
  TreeNode *sortedListToBST(ListNode *&head, int begin, int end) {
    if (begin > end) {
      return NULL;
    }
    int mid = begin + (end - begin)/2;
    TreeNode* left_child = sortedListToBST(head, begin, mid-1);
    TreeNode* parent = new TreeNode(head->val);
    parent->left = left_child;
    head = head->next;
    TreeNode* right_child = sortedListToBST(head, mid+1, end);
    parent->right = right_child;
    return parent;
  }
  TreeNode *sortedListToBST(ListNode *head) {
    int num_nodes = 0;
    ListNode *node = head;
    while (node != NULL) {
      ++num_nodes;
      node = node->next;
    }
    return sortedListToBST(head, 0, num_nodes-1);
  }
};
