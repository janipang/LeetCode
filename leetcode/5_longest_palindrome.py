class Solution:
    def isPalindrome(self, str1):
        return str1 == str1[::-1]
    
    def longestPalindrome(self, string: str) -> str:
        # count = 0
        length = len(string)
        if length == 1:
            return string[0]
        elif length == 0:
            return ""
        for s_long in range(length, 1, -1):
            for s_round in range(length + 1 - s_long):
                # count += 1
                # print(f"{count}: {string[s_round: s_round + s_long]}")
                if self.isPalindrome(string[s_round: s_round + s_long]):
                    return string[s_round: s_round + s_long]
        return string[0]
        
        
ans = Solution()
print(ans.longestPalindrome("babad"))