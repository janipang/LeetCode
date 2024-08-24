class Solution:
    def state(self, index: int, rows: int) -> int:
        if rows == 1:
            return 0
        virtual_index = index % ((rows * 2) - 2)
        return min(virtual_index, ((2 * (rows - 1)) - virtual_index))
            
        
    def convert(self, string: str, rows: int) -> str:
        split_s = [""] * rows
        for i in range(len(string)):
            split_s[self.state(i, rows)] += string[i]
        new_s = "".join(split_s)
        return new_s
        
        
        
ans = Solution()
print(ans.convert("human", 2))