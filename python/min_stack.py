class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.q = []


    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        curr_min = self.getMin()
        if curr_min is None or curr_min > x:
            curr_min = x
        self.q.append((x, curr_min))

    def pop(self):
        """
        :rtype: void
        """
        self.q.pop()

    def top(self):
        """
        :rtype: int
        """
        if len(self.q) == 0:
            return None
        else:
            return self.q[len(self.q) - 1][0]

    def getMin(self):
        """
        :rtype: int
        """
        if len(self.q) == 0:
            return None
        else:
            return self.q[len(self.q) - 1][1]
