class Solution:
    def isPalindrome(self, num: int) -> bool:
        string = list(str(num))
        if string == string[::-1]:
            return True
        return False
     
                
        
ans=Solution()
print(ans.isPalindrome(1000021))