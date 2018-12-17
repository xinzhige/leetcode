class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []


    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        curr_min = self.getMin()
        if curr_min is None or curr_min > x:
            curr_min = x
        self.stack.append((x, curr_min))

    def pop(self):
        """
        :rtype: void
        """
        self.stack.pop()

    def top(self):
        """
        :rtype: int
        """
        if len(self.stack) == 0:
            return None
        else:
            return self.stack[len(self.stack) - 1][0]

    def getMin(self):
        """
        :rtype: int
        """
        if len(self.stack) == 0:
            return None
        else:
            return self.stack[len(self.stack) - 1][1]
