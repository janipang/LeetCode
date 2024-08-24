class Solution:
    def lengthOfLongestSubstring(self, string: str) -> int:
        if len(string) <= 1:
            return len(string)
        
        accepted_char = ""
        for char in string:
            if char in accepted_char:
                break
            accepted_char += char
        this_length = len(accepted_char)
        sub_lenght = self.lengthOfLongestSubstring(string[1:])
        if this_length >= len(string[1:]):
            return this_length
        if this_length > sub_lenght:
            return this_length
        else:
            return sub_lenght

ans = Solution()
print(ans.lengthOfLongestSubstring("pwwkew"))