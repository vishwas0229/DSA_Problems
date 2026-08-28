class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        singleOne = 0
        for i in range(len(nums)):
            singleOne ^= nums[i]
        return singleOne