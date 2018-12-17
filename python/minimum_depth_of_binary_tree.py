class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        left_depth = self.minDepth(root.left)
        right_detph = self.minDepth(root.right)
        if root.left is None:
            return 1 + right_detph
        if root.right is None:
            return 1 + left_depth
        return 1 + min(left_depth, right_detph)
