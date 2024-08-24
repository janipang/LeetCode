rows, cols = map(int, input().split())
num1 = []
num2 = []
result = []

for i in range(rows):
    num1.append(list(map(int, input().split())))

for i in range(rows):
    num2.append(list(map(int, input().split())))

for i in range(rows):
    data = []
    for j in range(cols):
        data.append(num1[i][j] + num2[i][j])
    result.append(data)

for row_data in result:
    print('%s' % ' '.join(map(str, row_data)))