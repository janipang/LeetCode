class Solution:
    
    def __init__(self):
        pass
    
    def calculate_mix_max_position(self, current_position, min_position, max_position):
        if (min_position == -1 and max_position == -1):
            min_position = current_position
            max_position = current_position
        else:
            min_position = min(min_position, current_position)
            max_position = max(max_position, current_position)
        return min_position, max_position
        
    
    def maxArea(self, height):
        indexed_height = [(val, i) for i, val in enumerate(height)]
        sorted_height = sorted(indexed_height, key=lambda x: (-x[0], x[1]))
        min_position = -1
        max_position = -1
        len_height = len(sorted_height)
        current_index = 0
        max_area = 0
        
        print(f"sorted_height: {sorted_height}")
        
        while current_index < len_height:
            (current_height, current_position) = sorted_height[current_index]
            may_be_max = current_height * len_height > max_area
            if (may_be_max):
                min_position, max_position = self.calculate_mix_max_position(current_position, min_position, max_position)
                current_area_left = current_height * abs(current_position - min_position)
                current_area_right = current_height * abs(current_position - max_position)
                current_area = max(current_area_left, current_area_right)
                if (current_area > max_area): 
                    max_area = current_area
            # print(f"HEAD {current_index}:  h-{current_height}  nh-{next_height}  p-{current_position}  np-{next_position}  minp-{min_position}  maxp-{max_position}  result-{max_area}")
            current_index += 1
        return max_area

def main():
    # array = [0,14,6,2,10,9,4,1,10,3] # -> 70
    # array = [1,0,0,0,0,0,0,2,2] # -> 8
    # array = [1,8,6,2,5,4,8,3,7] # -> 49
    array = [1,1] # -> 1
    solution = Solution()
    print(f"test1: {solution.maxArea(array)}\n")
    
if __name__=="__main__":
    main()