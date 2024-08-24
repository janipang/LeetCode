class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        num = nums1 + nums2
        num.sort()
        length = len(num)
        if length % 2 == 0:
            return (num[(length // 2) - 1] + num[length // 2]) / 2
        else:
            return num[length // 2]
        

ans = Solution()
print(ans.findMedianSortedArrays([3,4,6], [5,3,2]))