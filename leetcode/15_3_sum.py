def threeSum(nums):
    result = []
    for i, num1 in enumerate(nums):
        for j, num2 in enumerate(nums[i+1:]):
            for k, num3 in enumerate(nums[i+2:]):
                if (num1 + num2 + num3 == 0):
                    temp = [num1, num2, num3]
                    temp.sort()
                    if not any(item == temp for item in result):
                        result.append(temp)
                if ((id(num1) == id(nums[-3])) and (id(num2) == id(nums[-2])) and (id(num3) == id(nums[-1]))):
                    return result
    return result
                
    
    
print(threeSum([3, -2, 1, 0]))