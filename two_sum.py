class Solution(object):
    def twoSum(self, nums, target):
        for  idx1, num1 in enumerate(nums):
            for idx2, num2 in enumerate(nums[idx1 + 1:], start=idx1 + 1):
                if num1 + num2 == target:
                    return [idx1, idx2]

solution = Solution()
print(solution.twoSum([2,7,11,15], 9))