string1 = input()
string2 = input()
list1 = []
list2 = []
result = []
carry = 0
for i in range(max(len(string1), len(string2))):
    if i % 2 == 0:
        continue
    list1.append(int(string1[i]) if i < len(string1) else 0)
    list2.append(int(string2[i] if i < len(string2) else 0))
    # calculate
    sum_digit = list1[-1] + list2[-1] + carry
    result.append(sum_digit % 10)
    carry = sum_digit // 10
if carry != 0:
    result.append(carry)
print(result)