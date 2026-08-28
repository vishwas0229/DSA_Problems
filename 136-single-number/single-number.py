class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        singleOne = 0
        for value in nums:
            singleOne ^= value
        return singleOne