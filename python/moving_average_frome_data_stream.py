class MovingAverage(object):

    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self.q = collections.deque(maxlen=size)


    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        q = self.q
        q.append(val)
        return float(sum(q)) / len(q)
