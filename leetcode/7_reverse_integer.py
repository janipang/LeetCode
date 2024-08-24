
class Solution:
    def reverse(self, x: int) -> int:
        neg = 1
        result = 0
        if x < 0:
            neg = -1
            x = -1 * x
        while (x > 0):
            result = result * 10 + (x % 10)
            x = x // 10
        result = result * neg
        
        if result < -1 * pow(2, 31) or result > pow(2, 31) - 1:
            return 0
        
        return result
        
ans = Solution()
print(ans.reverse(-3210))