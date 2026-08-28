class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sn = 0
        for i in range(len(nums)):
            sn ^= nums[i]
        return sn