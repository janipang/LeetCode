amount = int(input())
num = []
min = 100
max = -100

for i in range(amount):
    num.append(int(input()))
    if num[-1] < min:
        min = num[-1]
    if num[-1] > max:
        max = num[-1]

print(min)
print(max)
