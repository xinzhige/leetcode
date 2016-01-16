// time: O(n), space: O(n)
class Solution {
public:
    TreeNode* helper(vector<int>& postorder, int poL, int poR,
                     vector<int>& inorder, int inL, int inR, 
                     unordered_map<int, int>& map) {
        if (poL > poR || inL > inR) {
            return nullptr;
        }
        //everytime we insert the post order of sub tree's last element as root
        TreeNode* root = new TreeNode(postorder[poR]);
        int index = map[root->val];
        //index - inL means the length of the left subtree,
        //we calculate the indices of the begin and end of the subtree in post/in order
        root->left = helper(postorder, poL, poL + index - inL - 1, 
                            inorder, inL, index - 1, map);
        root->right = helper(postorder, poL + index - inL, poR - 1, 
                             inorder, index + 1, inR, map);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int, int> map;
        //faster to get the indices and length of subtree
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return helper(postorder, 0, postorder.size() - 1, 
                      inorder, 0, inorder.size() - 1, map);
    }
};

// time: O(n^2), space: O(1)
class Solution {
public:
    typedef vector<int>::iterator Iter;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeHelper(inorder.begin(), inorder.end(), 
                              postorder.begin(), postorder.end());
    }
    TreeNode *buildTreeHelper(Iter istart, Iter iend, Iter pstart, Iter pend) {
        if(istart == iend) {
            return nullptr;
        }
        int rootval = *(pend - 1);
        TreeNode *res = new TreeNode(rootval);
        Iter iterroot = find(istart, iend, rootval);
        res->left = buildTreeHelper(istart, iterroot, pstart, pstart + (iterroot - istart);
        res->right = buildTreeHelper(iterroot + 1, iend, pstart + (iterroot - istart), pend - 1);
        return res;
    }
};