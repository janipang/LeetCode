class Solution:
    def myAtoi(self, string: str) -> int:
        neg = 1
        value = 0
        started = False
        for char in string:
            if char == ' ':
                if not started:
                    continue
                else:
                    break
            elif char >= '0' and char <= '9':
                value = value * 10 + int(char)
                started = True
            elif char == '-' and not started:
                neg = -1
                started = True
            elif char == '+' and not started:
                neg = 1
                started = True
            elif char < '0' or char > '9':
                break
        value *= neg
        if value < (-1 * pow(2,31)):
            return -1 * pow(2,31)
        elif value > pow(2, 31) - 1:
            return pow(2, 31) - 1
        else:
            return value
                
        
ans=Solution()
print(ans.myAtoi('   +0 123'))