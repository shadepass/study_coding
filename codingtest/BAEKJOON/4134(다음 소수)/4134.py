import math
import sys

input = sys.stdin.readline
max_value = int(math.sqrt(4 * math.pow(10, 9))) + 1

test_num = int(input())
test_list = []
answer = []
for _ in range(test_num):
    test_list.append(int(input()))

decimal_check_list = [1] * max_value
decimal_list = []

for i in range(2, max_value):
    if decimal_check_list[i] == 1:
        decimal_list.append(i)
        for j in range(i*i, max_value, i):
            decimal_check_list[j] = 0


for test in test_list:
    if test == 0 or test == 1:
        answer.append(2)
        continue
    temp = test
    while True:
        check = 0
        for test_value in decimal_list:
            if test_value >= temp:
                break
            if temp % test_value == 0:
                check = 1
                break
        if check == 0:
            answer.append(temp)
            break
        else:
            temp += 1

for i in range(test_num):
    print(answer[i])